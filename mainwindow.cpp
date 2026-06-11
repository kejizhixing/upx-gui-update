#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QFileInfo>
#include <QDateTime>
#include <QRegularExpression>
#include <QStandardPaths>
#include <QApplication>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_process(new QProcess(this))
    , m_networkManager(new QNetworkAccessManager(this))
    , m_originalFileSize(0)
    , m_detectedUpxIndex(-1)
    , m_presetChanging(false)
    , m_pendingAction(None)
{
    ui->setupUi(this);
    
    // 启用拖放功能
    setAcceptDrops(true);
    
    connect(m_process, SIGNAL(finished(int, QProcess::ExitStatus)),
            this, SLOT(processFinished(int, QProcess::ExitStatus)));
    connect(m_process, SIGNAL(readyReadStandardOutput()),
            this, SLOT(processReadyReadStandardOutput()));
    connect(m_process, SIGNAL(readyReadStandardError()),
            this, SLOT(processReadyReadStandardError()));
    
    // 连接网络请求完成信号
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(onUpdateCheckFinished(QNetworkReply*)));
    
    initUpxVersions();
    initPresetOptions();
    checkUpxExists();

    ui->btnExecute->setEnabled(false);
    ui->btnCheckStatus->setEnabled(false);
    
    // 启动后3秒自动检查更新
    QTimer::singleShot(3000, this, SLOT(onAutoUpdateCheck()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUpxVersions()
{
    m_upxVersions.clear();
    m_upxPaths.clear();
    
    // 添加 UPX 版本
    m_upxVersions << "UPX 1.25 (Win32)";
    m_upxPaths << "upx-1.25-win32.exe";
    
    m_upxVersions << "UPX 2.3 (Win32)";
    m_upxPaths << "upx-2.03-win32.exe";
    
    m_upxVersions << "UPX 4.2.2 (Win32)";
    m_upxPaths << "upx-4.2.2-win32.exe";
    
    m_upxVersions << "UPX 4.2.2 (Win64)";
    m_upxPaths << "upx-4.2.2-win64.exe";
    
    m_upxVersions << "UPX 5.1.1 (Win32)";
    m_upxPaths << "upx-5.1.1-win32.exe";
    
    m_upxVersions << "UPX 5.1.1 (Win64)";
    m_upxPaths << "upx-5.1.1-win64.exe";
    
    m_upxVersions << "UPX 5.2.0 (Win32)";
    m_upxPaths << "upx-5.2.0-win32.exe";
    
    m_upxVersions << "UPX 5.2.0 (Win64)";
    m_upxPaths << "upx-5.2.0-win64.exe";
    
    ui->cmbUpxVersion->addItems(m_upxVersions);
}

void MainWindow::initPresetOptions()
{
    ui->cmbPreset->addItem("自定义参数", 0);
    ui->cmbPreset->addItem("1. 最稳推荐（日常使用）", 1);
    ui->cmbPreset->addItem("2. 体积更小低误报", 2);
    ui->cmbPreset->addItem("3. 强压缩尽量免报", 3);
    ui->cmbPreset->addItem("4. 不生成UPX特征区段", 4);
    ui->cmbPreset->addItem("5. 绝对不暴露UPX签名", 5);
    ui->cmbPreset->addItem("6. 最高压缩防误报", 6);
    
    // 默认选择自定义
    ui->cmbPreset->setCurrentIndex(0);
}

void MainWindow::applyPreset(int presetIndex)
{
    m_presetChanging = true;
    
    // 先清空所有复选框
    ui->chkLzma->setChecked(false);
    ui->chkNoCompressExports->setChecked(false);
    ui->chkStripRelocs->setChecked(false);
    ui->chkOverlayCopy->setChecked(false);
    ui->chkBrute->setChecked(false);
    ui->chkUltraBrute->setChecked(false);
    ui->chkNrv2c->setChecked(false);
    
    switch (presetIndex) {
        case 1: // 最稳推荐
            ui->chkLzma->setChecked(true);
            ui->chkNoCompressExports->setChecked(true);
            break;
        case 2: // 体积更小低误报
            ui->chkLzma->setChecked(true);
            ui->chkStripRelocs->setChecked(true);
            break;
        case 3: // 强压缩尽量免报
            ui->chkLzma->setChecked(true);
            ui->chkBrute->setChecked(true);
            break;
        case 4: // 不生成UPX特征区段
            ui->chkLzma->setChecked(true);
            ui->chkNoCompressExports->setChecked(true);
            ui->chkStripRelocs->setChecked(true);
            break;
        case 5: // 绝对不暴露UPX签名
            ui->chkLzma->setChecked(true);
            ui->chkNrv2c->setChecked(true);
            ui->chkOverlayCopy->setChecked(true);
            break;
        case 6: // 最高压缩防误报
            ui->chkLzma->setChecked(true);
            ui->chkNoCompressExports->setChecked(true);
            ui->chkBrute->setChecked(true);
            break;
        default: // 自定义
            break;
    }
    
    m_presetChanging = false;
}

void MainWindow::checkUpxExists()
{
    QString appDir = QCoreApplication::applicationDirPath();
    int availableIndex = -1;
    
    for (int i = 0; i < m_upxPaths.size(); ++i) {
        QString upxPath = appDir + "/" + m_upxPaths[i];
        if (QFile::exists(upxPath)) {
            if (availableIndex == -1) {
                availableIndex = i;
            }
        }
    }
    
    if (availableIndex != -1) {
        ui->cmbUpxVersion->setCurrentIndex(availableIndex);
    }
}

void MainWindow::updateStatusDisplay()
{
    if (m_currentFile.isEmpty()) {
        ui->lblFileInfo->setText("未选择文件");
        ui->btnExecute->setEnabled(false);
        ui->btnCheckStatus->setEnabled(false);
        ui->lblStatus->setText("状态：等待选择文件");
        clearCompressRatio();
        return;
    }
    
    QFileInfo fileInfo(m_currentFile);
    QString info = QString("文件: %1\n大小: %2 字节\n修改时间: %3")
        .arg(fileInfo.fileName())
        .arg(fileInfo.size())
        .arg(fileInfo.lastModified().toString("yyyy-MM-dd HH:mm:ss"));
    
    ui->lblFileInfo->setText(info);
    ui->btnExecute->setEnabled(true);
    ui->btnCheckStatus->setEnabled(true);
    ui->lblStatus->setText("状态：就绪");
    clearCompressRatio();
}

QStringList MainWindow::buildUpxArguments()
{
    QStringList args;
    
    // 始终添加 -f 参数
    args << "-f";
    
    // 添加选中的高级参数
    if (ui->chkLzma->isChecked()) {
        args << "--lzma";
    }
    if (ui->chkNoCompressExports->isChecked()) {
        args << "--no-compress-exports";
    }
    if (ui->chkStripRelocs->isChecked()) {
        args << "--strip-relocs";
    }
    if (ui->chkOverlayCopy->isChecked()) {
        args << "--overlay=copy";
    }
    if (ui->chkBrute->isChecked()) {
        args << "--brute";
    }
    if (ui->chkUltraBrute->isChecked()) {
        args << "--ultra-brute";
    }
    if (ui->chkNrv2c->isChecked()) {
        args << "--nrv2c";
    }
    
    return args;
}

void MainWindow::on_cmbPreset_currentIndexChanged(int index)
{
    if (m_presetChanging) return;
    
    int presetIndex = ui->cmbPreset->itemData(index).toInt();
    applyPreset(presetIndex);
}

void MainWindow::on_chkLzma_toggled(bool checked)
{
    Q_UNUSED(checked);
    if (!m_presetChanging) {
        ui->cmbPreset->setCurrentIndex(0);
    }
}

void MainWindow::on_chkNoCompressExports_toggled(bool checked)
{
    Q_UNUSED(checked);
    if (!m_presetChanging) {
        ui->cmbPreset->setCurrentIndex(0);
    }
}

void MainWindow::on_chkStripRelocs_toggled(bool checked)
{
    Q_UNUSED(checked);
    if (!m_presetChanging) {
        ui->cmbPreset->setCurrentIndex(0);
    }
}

void MainWindow::on_chkOverlayCopy_toggled(bool checked)
{
    Q_UNUSED(checked);
    if (!m_presetChanging) {
        ui->cmbPreset->setCurrentIndex(0);
    }
}

void MainWindow::on_chkBrute_toggled(bool checked)
{
    Q_UNUSED(checked);
    if (!m_presetChanging) {
        ui->cmbPreset->setCurrentIndex(0);
    }
}

void MainWindow::on_chkUltraBrute_toggled(bool checked)
{
    Q_UNUSED(checked);
    if (!m_presetChanging) {
        ui->cmbPreset->setCurrentIndex(0);
    }
}

void MainWindow::on_chkNrv2c_toggled(bool checked)
{
    Q_UNUSED(checked);
    if (!m_presetChanging) {
        ui->cmbPreset->setCurrentIndex(0);
    }
}

void MainWindow::on_btnSelectFile_clicked()
{
    QString filter = "可执行文件 (*.exe *.dll *.com *.sys *.scr *.ocx *.acm *.ax *.bpl *.dpl)";
    QString filePath = QFileDialog::getOpenFileName(this, "选择要处理的文件", "", filter);
    
    if (!filePath.isEmpty()) {
        if (containsSpecialCharacters(filePath)) {
            QMessageBox::warning(this, "警告", "文件路径中包含中文或特殊字符，可能导致 UPX 处理失败。\n建议将文件移动到纯英文路径下。");
        }
        
        m_currentFile = filePath;
        ui->txtFilePath->setText(filePath);
        updateStatusDisplay();
        ui->txtOutput->clear();
        m_detectedUpxIndex = -1;
        
        // 自动检测文件状态和 UPX 版本
        ui->lblStatus->setText("状态：正在自动检测 UPX 版本...");
        ui->btnExecute->setEnabled(false);
        ui->btnCheckStatus->setEnabled(false);
        autoDetectUpxVersion(filePath);
    }
}

void MainWindow::on_cmbUpxVersion_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    // 版本切换时重置预设选择
}

void MainWindow::on_rdoCompress_toggled(bool checked)
{
    if (checked) {
        // 切换到压缩模式时启用高级选项
    }
}

void MainWindow::on_rdoDecompress_toggled(bool checked)
{
    Q_UNUSED(checked);
    // 解压模式下禁用高级选项
}

void MainWindow::on_btnCheckStatus_clicked()
{
    if (m_currentFile.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要检测的文件。");
        return;
    }
    
    ui->txtOutput->clear();
    ui->lblStatus->setText("状态：正在检测文件状态...");
    ui->btnExecute->setEnabled(false);
    
    QString upxPath = getSelectedUpxPath();
    if (upxPath.isEmpty()) {
        QMessageBox::critical(this, "错误", "未找到 UPX 程序，请确保 UPX 可执行文件存在于程序目录中。");
        ui->lblStatus->setText("状态：错误 - 未找到 UPX 程序");
        ui->btnExecute->setEnabled(true);
        return;
    }
    
    QStringList args;
    args << "-t" << m_currentFile;
    
    ui->txtOutput->append("正在检测文件...\n");
    m_process->start(upxPath, args);
}

void MainWindow::on_btnExecute_clicked()
{
    if (m_currentFile.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要处理的文件。");
        return;
    }
    
    QString upxPath = getSelectedUpxPath();
    if (upxPath.isEmpty()) {
        QMessageBox::critical(this, "错误", "未找到 UPX 程序，请确保 UPX 可执行文件存在于程序目录中。");
        ui->lblStatus->setText("状态：错误 - 未找到 UPX 程序");
        return;
    }
    
    m_selectedUpxPath = upxPath;
    ui->txtOutput->clear();
    
    // 显示正在使用的参数
    QStringList args = buildUpxArguments();
    ui->txtOutput->append(QString("UPX 命令参数: %1\n").arg(args.join(" ")));
    ui->txtOutput->append(QString("目标文件: %1\n").arg(m_currentFile));
    ui->txtOutput->append("\n");
    
    if (ui->rdoDecompress->isChecked()) {
        // 解压操作
        ui->lblStatus->setText("状态：正在解压...");
        QStringList args;
        args << "-d" << m_currentFile;
        m_process->start(upxPath, args);
    } else {
        // 压缩操作 - 先检测文件是否已被压缩
        ui->txtOutput->append("正在检测文件是否已被 UPX 压缩...\n");
        m_pendingAction = CheckThenCompress;
        
        QStringList args;
        args << "-t" << m_currentFile;
        m_process->start(upxPath, args);
    }
}

void MainWindow::processFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    // 处理自动检测 UPX 版本
    if (m_pendingAction == AutoDetectVersion) {
        QString appDir = QCoreApplication::applicationDirPath();
        
        if (exitStatus == QProcess::NormalExit && exitCode == 0) {
            // 找到能识别该文件的 UPX 版本（从新到旧检测，第一个成功的就是最佳版本）
            ui->cmbUpxVersion->setCurrentIndex(m_detectedUpxIndex);
            
            ui->txtOutput->append(QString("\n检测结果：文件已被 UPX 压缩！\n"));
            ui->txtOutput->append(QString("识别的 UPX 版本：%1\n").arg(m_upxVersions[m_detectedUpxIndex]));
            ui->txtOutput->append(QString("压缩工具：%1\n").arg(m_upxPaths[m_detectedUpxIndex]));
            
            ui->lblStatus->setText("状态：文件已被 UPX 压缩，已自动选择正确的版本");
            ui->rdoDecompress->setChecked(true);
            ui->btnExecute->setEnabled(true);
            ui->btnCheckStatus->setEnabled(true);
            m_pendingAction = None;
            
            QMessageBox::information(this, "检测完成", 
                QString("文件已被 UPX 压缩！\n\n"
                        "识别的 UPX 版本：%1\n"
                        "已自动选择正确的版本进行解压。").arg(m_upxVersions[m_detectedUpxIndex]));
        } else {
            // 当前版本无法识别，尝试下一个更旧的版本
            m_detectedUpxIndex--;
            
            while (m_detectedUpxIndex >= 0) {
                QString upxPath = appDir + "/" + m_upxPaths[m_detectedUpxIndex];
                if (QFile::exists(upxPath)) {
                    ui->txtOutput->append(QString("尝试版本：%1\n").arg(m_upxVersions[m_detectedUpxIndex]));
                    
                    QStringList args;
                    args << "-t" << m_currentFile;
                    m_process->start(upxPath, args);
                    return;
                }
                m_detectedUpxIndex--;
            }
            
            // 所有版本都无法识别，说明文件未被压缩
            // 自动选择实际存在的最新版本进行压缩
            int latestIndex = m_upxPaths.size() - 1;
            while (latestIndex >= 0) {
                QString upxPath = appDir + "/" + m_upxPaths[latestIndex];
                if (QFile::exists(upxPath)) {
                    break;
                }
                latestIndex--;
            }
            
            ui->txtOutput->append("\n检测结果：文件未被 UPX 压缩。\n");
            ui->txtOutput->append(QString("已自动选择最新版本进行压缩：%1\n").arg(m_upxVersions[latestIndex]));
            ui->lblStatus->setText("状态：文件未被 UPX 压缩，已自动选择最新版本");
            
            ui->cmbUpxVersion->setCurrentIndex(latestIndex);
            ui->rdoCompress->setChecked(true);
            ui->btnExecute->setEnabled(true);
            ui->btnCheckStatus->setEnabled(true);
            m_pendingAction = None;
        }
        return;
    }
    
    // 处理压缩前的预检测结果
    if (m_pendingAction == CheckThenCompress) {
        if (exitStatus == QProcess::NormalExit && exitCode == 0) {
            ui->txtOutput->append("\n检测结果：文件已被 UPX 压缩，无法重复压缩！\n");
            ui->txtOutput->append("提示：如果需要重新压缩，请先选择\"解压\"模式。\n");
            ui->lblStatus->setText("状态：文件已被 UPX 压缩");
            ui->btnExecute->setEnabled(true);
            ui->btnCheckStatus->setEnabled(true);
            m_pendingAction = None;
            
            QMessageBox::warning(this, "提示", 
                "文件已被 UPX 压缩，无法重复压缩！\n\n"
                "如需重新压缩，请先选择\"解压\"模式解压文件。");
            return;
        }
        
        // 记录原始文件大小用于计算压缩率
        QFileInfo fileInfo(m_currentFile);
        m_originalFileSize = fileInfo.size();
        
        // 文件未被压缩，继续执行压缩
        ui->txtOutput->append("\n检测结果：文件未被 UPX 压缩，开始执行压缩...\n");
        ui->lblStatus->setText(QString("状态：正在%1...").arg(getCurrentAction()));
        m_pendingAction = ExecuteCompress;
        
        QStringList args = buildUpxArguments();
        args << m_currentFile;
        
        m_process->start(m_selectedUpxPath, args);
        return;
    }
    
    // 正常的执行结果处理
    QString statusText;
    QString resultText;
    
    if (exitStatus == QProcess::NormalExit) {
        if (exitCode == 0) {
            statusText = QString("状态：%1 成功").arg(getCurrentAction());
            resultText = "\n=== 操作成功完成 ===";
        } else {
            statusText = QString("状态：%1 失败 (错误码：%2)").arg(getCurrentAction()).arg(exitCode);
            resultText = "\n=== 操作失败 ===";
        }
    } else {
        statusText = "状态：进程异常终止";
        resultText = "\n=== 进程异常终止 ===";
    }
    
    ui->txtOutput->append(resultText);
    ui->lblStatus->setText(statusText);
    ui->btnExecute->setEnabled(true);
    ui->btnCheckStatus->setEnabled(true);
    
    if (exitCode == 0 && m_pendingAction == ExecuteCompress) {
        updateStatusDisplay();
        updateCompressRatio();
    }
    
    m_pendingAction = None;
}

void MainWindow::processReadyReadStandardOutput()
{
    QString output = m_process->readAllStandardOutput();
    ui->txtOutput->append(output);
}

void MainWindow::processReadyReadStandardError()
{
    QString error = m_process->readAllStandardError();
    ui->txtOutput->append("错误：" + error);
}

void MainWindow::on_actionOpenFile_triggered()
{
    on_btnSelectFile_clicked();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionUPXWebsite_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/upx/upx"));
}

void MainWindow::on_actionUpdateWebsite_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/upx/upx/releases"));
}

void MainWindow::on_actionFeedback_triggered()
{
    QMessageBox::information(this, "留言反馈",
        "欢迎留言反馈！\n\n"
        "请访问 UPX 官方 GitHub 仓库提交问题或建议：\n"
        "https://github.com/upx/upx/issues\n\n"
        "或者加入我们的 QQ 群进行交流：\n"
        "科技之星 1 群：669812887\n"
        "科技之星总群：561116458\n"
        "新人报道群：1032931117");
}

void MainWindow::on_actionAbout_triggered()
{
    QString aboutText =
        "UPX GUI - 可视化压缩/解压工具\n\n"
        "版本：" APP_VERSION "\n"
        "基于 Qt 6.5.3 开发\n\n"
        "支持的 UPX 版本:\n"
        "  - UPX 1.25 (Win32)\n"
        "  - UPX 2.3 (Win32)\n"
        "  - UPX 4.2.2 (Win32/Win64)\n"
        "  - UPX 5.1.1 (Win32/Win64)\n"
        "  - UPX 5.2.0 (Win32/Win64)\n\n"
        "功能:\n"
        "  - 文件压缩/解压\n"
        "  - 防误报优化参数\n"
        "  - 多种预设方案\n"
        "  - 文件状态检测\n"
        "  - 自动在线升级检测\n\n"
        "官方网站：https://github.com/upx/upx\n\n"
        "========================================\n"
        "        软件许可与版权声明\n"
        "========================================\n"
        "版权归属：本软件著作权归开发者所有，受《中华人民共和国著作权法》及国际版权条约保护。\n"
        "禁止篡改：严禁逆向工程、反编译、篡改版权信息、修改程序逻辑并二次发布。\n"
        "合法使用：使用需遵守国家法律法规，违规使用产生的法律责任由用户自行承担。\n"
        "免责声明：软件按现状提供，无任何明示或默示担保，开发者不承担使用过程中产生的各类损失。\n\n"
        "🐟—— 请遵守法律法规，尊重知识产权 ——🐟";

    QMessageBox::about(this, "关于软件", aboutText);
}

QString MainWindow::getSelectedUpxPath()
{
    int index = ui->cmbUpxVersion->currentIndex();
    if (index < 0 || index >= m_upxPaths.size()) {
        return "";
    }
    
    QString appDir = QCoreApplication::applicationDirPath();
    return appDir + "/" + m_upxPaths[index];
}

QString MainWindow::getCurrentAction()
{
    if (ui->rdoCompress->isChecked()) {
        return "压缩";
    } else {
        return "解压";
    }
}

bool MainWindow::containsSpecialCharacters(const QString &path)
{
    QRegularExpression chinesePattern("[\\u4e00-\\u9fa5]");
    QRegularExpression specialPattern("[~!@#$%^&*()+|{}';,<>`]");
    
    return chinesePattern.match(path).hasMatch() || specialPattern.match(path).hasMatch();
}

void MainWindow::updateCompressRatio()
{
    if (m_currentFile.isEmpty() || m_originalFileSize <= 0) {
        return;
    }
    
    QFileInfo fileInfo(m_currentFile);
    qint64 newSize = fileInfo.size();
    
    if (newSize > 0) {
        double ratio = (1.0 - (double)newSize / m_originalFileSize) * 100.0;
        ui->lblCompressRatio->setText(QString("压缩率：%1%").arg(ratio, 0, 'f', 1));
    }
}

void MainWindow::clearCompressRatio()
{
    ui->lblCompressRatio->setText("压缩率：--");
}

void MainWindow::autoDetectUpxVersion(const QString &filePath)
{
    m_pendingAction = AutoDetectVersion;
    
    QString appDir = QCoreApplication::applicationDirPath();
    
    // 从最新版本开始检测（倒序遍历）
    m_detectedUpxIndex = m_upxPaths.size() - 1;
    
    // 找到实际存在的最新版本作为起点
    while (m_detectedUpxIndex >= 0) {
        QString upxPath = appDir + "/" + m_upxPaths[m_detectedUpxIndex];
        if (QFile::exists(upxPath)) {
            break;
        }
        m_detectedUpxIndex--;
    }
    
    if (m_detectedUpxIndex < 0) {
        ui->txtOutput->append("错误：未找到任何可用的 UPX 程序！\n");
        ui->lblStatus->setText("状态：错误 - 未找到 UPX 程序");
        ui->btnExecute->setEnabled(false);
        ui->btnCheckStatus->setEnabled(false);
        m_pendingAction = None;
        return;
    }
    
    ui->txtOutput->append("正在自动检测 UPX 版本（从最新版本开始），请稍候...\n");
    ui->txtOutput->append(QString("尝试版本：%1\n").arg(m_upxVersions[m_detectedUpxIndex]));
    
    QString upxPath = appDir + "/" + m_upxPaths[m_detectedUpxIndex];
    QStringList args;
    args << "-t" << filePath;
    m_process->start(upxPath, args);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        
        if (!urlList.isEmpty()) {
            QString filePath = urlList.at(0).toLocalFile();
            
            QFileInfo fileInfo(filePath);
            
            if (fileInfo.exists() && fileInfo.isFile()) {
                QString suffix = fileInfo.suffix().toLower();
                QStringList validExtensions = {"exe", "dll", "com", "sys", "scr", "ocx", "acm", "ax", "bpl", "dpl"};
                
                if (validExtensions.contains(suffix) || suffix.isEmpty()) {
                    if (containsSpecialCharacters(filePath)) {
                        QMessageBox::warning(this, "警告", "文件路径中包含中文或特殊字符，可能导致 UPX 处理失败。\n建议将文件移动到纯英文路径下。");
                    }
                    
                    m_currentFile = filePath;
                    ui->txtFilePath->setText(filePath);
                    updateStatusDisplay();
                    ui->txtOutput->clear();
                    m_detectedUpxIndex = -1;
                    
                    ui->lblStatus->setText("状态：已拖放文件 " + fileInfo.fileName() + "，正在检测 UPX 版本...");
                    ui->btnExecute->setEnabled(false);
                    ui->btnCheckStatus->setEnabled(false);
                    
                    autoDetectUpxVersion(filePath);
                } else {
                    QMessageBox::warning(this, "警告", "不支持的文件类型: ." + suffix + "\n请选择可执行文件（exe、dll 等）。");
                }
            } else {
                QMessageBox::warning(this, "警告", "文件不存在或路径无效。");
            }
        }
    }
    
    event->acceptProposedAction();
}

void MainWindow::on_actionCheckUpdate_triggered()
{
    checkForUpdates(true);
}

void MainWindow::onAutoUpdateCheck()
{
    checkForUpdates(false);
}

void MainWindow::checkForUpdates(bool showNoUpdateMsg)
{
    m_showNoUpdateMsg = showNoUpdateMsg;
    ui->txtOutput->append("\n正在检查更新...\n");
    ui->lblStatus->setText("状态：正在检查更新...");
    
    QNetworkRequest request(QUrl(UPDATE_URL));
    request.setHeader(QNetworkRequest::UserAgentHeader, 
        "UPX_GUI/" APP_VERSION " (Windows)");
    
    QNetworkReply *reply = m_networkManager->get(request);
    
    // 设置超时时间（10秒）
    QTimer::singleShot(10000, reply, SLOT(abort()));
    
    // 连接超时信号
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(onUpdateCheckError(QNetworkReply::NetworkError)));
}

void MainWindow::onUpdateCheckError(QNetworkReply::NetworkError error)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;
    
    ui->txtOutput->append("更新检查失败：网络超时或连接错误\n");
    ui->lblStatus->setText("状态：就绪");
    
    reply->deleteLater();
}

void MainWindow::onUpdateCheckFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        ui->txtOutput->append("更新检查失败：网络连接错误\n");
        ui->lblStatus->setText("状态：更新检查失败");
        reply->deleteLater();
        return;
    }
    
    QString response = reply->readAll();
    reply->deleteLater();
    
    // 清理HTML标签（如果从网页获取）
    QString plainText = response;
    plainText.remove(QRegularExpression("<[^>]*>"));
    
    // 解析版本号
    QString latestVersion = "";
    QRegularExpression versionRegex(R"(version[\s\S]*?([\d]+\.[\d]+\.[\d]+))", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = versionRegex.match(plainText);
    if (match.hasMatch()) {
        latestVersion = match.captured(1);
    }
    
    // 解析更新日志
    QString updateLog = "";
    int logStart = plainText.indexOf("【更新日志】");
    if (logStart >= 0) {
        logStart += QString("【更新日志】").length();
        int logEnd = plainText.indexOf("【", logStart);
        if (logEnd < 0) logEnd = plainText.length();
        updateLog = plainText.mid(logStart, logEnd - logStart).trimmed();
    }
    
    // 如果从页面提取失败，使用默认的更新方式
    if (latestVersion.isEmpty()) {
        ui->txtOutput->append("提示：无法自动检测版本，请手动访问下载页面检查更新。\n");
        ui->lblStatus->setText("状态：就绪");
        
        if (QMessageBox::question(this, "检查更新", 
            "无法自动检测版本，是否跳转到下载页面手动检查？",
            QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            QDesktopServices::openUrl(QUrl(DOWNLOAD_URL));
        }
        return;
    }
    
    ui->txtOutput->append(QString("当前版本：%1\n").arg(APP_VERSION));
    ui->txtOutput->append(QString("最新版本：%1\n").arg(latestVersion));
    
    int compareResult = compareVersions(APP_VERSION, latestVersion);
    
    if (compareResult < 0) {
        // 有新版本
        ui->txtOutput->append("发现新版本！\n");
        if (!updateLog.isEmpty()) {
            ui->txtOutput->append("更新内容：\n" + updateLog + "\n");
        }
        
        QString msgText = QString("当前版本：%1\n最新版本：%2\n")
            .arg(APP_VERSION).arg(latestVersion);
        if (!updateLog.isEmpty()) {
            msgText += "\n【更新内容】\n" + updateLog;
        }
        msgText += "\n\n是否前往下载页面更新？";
        
        int ret = QMessageBox::question(this, "发现新版本", msgText,
            QMessageBox::Yes | QMessageBox::No);
        
        if (ret == QMessageBox::Yes) {
            QDesktopServices::openUrl(QUrl(DOWNLOAD_URL));
        }
    } else {
        // 当前已是最新版本
        ui->txtOutput->append("当前已是最新版本。\n");
        if (m_showNoUpdateMsg) {
            QMessageBox::information(this, "检查更新", 
                QString("当前已是最新版本：%1").arg(APP_VERSION));
        }
    }
    
    ui->lblStatus->setText("状态：就绪");
}

int MainWindow::compareVersions(const QString &v1, const QString &v2)
{
    QStringList parts1 = v1.split(".");
    QStringList parts2 = v2.split(".");
    
    int count = qMin(parts1.size(), parts2.size());
    
    for (int i = 0; i < count; ++i) {
        int num1 = parts1[i].toInt();
        int num2 = parts2[i].toInt();
        
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
    }
    
    // 如果前面部分相同，比较长度
    return parts1.size() - parts2.size();
}
