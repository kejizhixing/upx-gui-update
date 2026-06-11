#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QTimer>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QComboBox>
#include <QCheckBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define APP_VERSION "2.0.1"
#define UPDATE_URL "https://raw.githubusercontent.com/kejizhixing/upx-gui-update/refs/heads/main/version.txt"  // GitHub版本检测地址
#define DOWNLOAD_URL "https://github.com/kejizhixing/upx-gui-update/releases" // GitHub Releases下载地址

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private slots:
    void on_btnSelectFile_clicked();
    void on_btnExecute_clicked();
    void on_btnCheckStatus_clicked();
    void on_cmbUpxVersion_currentIndexChanged(int index);
    void on_rdoCompress_toggled(bool checked);
    void on_rdoDecompress_toggled(bool checked);
    void on_actionOpenFile_triggered();
    void on_actionExit_triggered();
    void on_actionUPXWebsite_triggered();
    void on_actionUpdateWebsite_triggered();
    void on_actionFeedback_triggered();
    void on_actionAbout_triggered();
    void on_actionCheckUpdate_triggered();
    void on_cmbPreset_currentIndexChanged(int index);
    void on_chkLzma_toggled(bool checked);
    void on_chkNoCompressExports_toggled(bool checked);
    void on_chkStripRelocs_toggled(bool checked);
    void on_chkOverlayCopy_toggled(bool checked);
    void on_chkBrute_toggled(bool checked);
    void on_chkUltraBrute_toggled(bool checked);
    void on_chkNrv2c_toggled(bool checked);
    
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void processReadyReadStandardOutput();
    void processReadyReadStandardError();
    void onUpdateCheckFinished(QNetworkReply *reply);
    void onUpdateCheckError(QNetworkReply::NetworkError error);
    void onAutoUpdateCheck();

private:
    Ui::MainWindow *ui;
    QProcess *m_process;
    QNetworkAccessManager *m_networkManager;
    QString m_currentFile;
    QStringList m_upxVersions;
    QStringList m_upxPaths;
    qint64 m_originalFileSize;
    int m_detectedUpxIndex;
    bool m_presetChanging;
    bool m_showNoUpdateMsg;
    
    enum PendingAction { None, CheckThenCompress, ExecuteCompress, ExecuteDecompress, AutoDetectVersion };
    PendingAction m_pendingAction;
    QString m_selectedUpxPath;
    
    void initUpxVersions();
    void initPresetOptions();
    void applyPreset(int presetIndex);
    void updateStatusDisplay();
    void checkUpxExists();
    void loadChangelogFromServer();
    void onChangelogLoadedFromServer(QNetworkReply *reply);
    QString getSelectedUpxPath();
    QString getCurrentAction();
    QStringList buildUpxArguments();
    bool containsSpecialCharacters(const QString &path);
    void updateCompressRatio();
    void clearCompressRatio();
    void autoDetectUpxVersion(const QString &filePath);
    void checkForUpdates(bool showNoUpdateMsg = true);
    int compareVersions(const QString &v1, const QString &v2);
};

#endif // MAINWINDOW_H
