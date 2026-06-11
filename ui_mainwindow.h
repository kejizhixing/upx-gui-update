/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxFile;
    QHBoxLayout *horizontalLayoutFile;
    QLineEdit *txtFilePath;
    QPushButton *btnSelectFile;
    QGroupBox *groupBoxVersion;
    QHBoxLayout *horizontalLayoutVersion;
    QComboBox *cmbUpxVersion;
    QGroupBox *groupBoxAction;
    QHBoxLayout *horizontalLayoutAction;
    QRadioButton *rdoCompress;
    QRadioButton *rdoDecompress;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBoxAdvanced;
    QVBoxLayout *verticalLayoutAdvanced;
    QHBoxLayout *horizontalLayoutPreset;
    QLabel *lblPreset;
    QComboBox *cmbPreset;
    QSpacerItem *horizontalSpacerPreset;
    QGridLayout *gridLayoutParams;
    QCheckBox *chkLzma;
    QCheckBox *chkNoCompressExports;
    QCheckBox *chkStripRelocs;
    QCheckBox *chkOverlayCopy;
    QCheckBox *chkBrute;
    QCheckBox *chkUltraBrute;
    QCheckBox *chkNrv2c;
    QGroupBox *groupBoxInfo;
    QVBoxLayout *verticalLayoutInfo;
    QLabel *lblFileInfo;
    QGroupBox *groupBoxOutput;
    QVBoxLayout *verticalLayoutOutput;
    QTextEdit *txtOutput;
    QHBoxLayout *horizontalLayoutButtons;
    QLabel *lblStatus;
    QLabel *lblCompressRatio;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnCheckStatus;
    QPushButton *btnExecute;
    QMenuBar *menuBar;
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionUPXWebsite;
    QAction *actionUpdateWebsite;
    QAction *actionFeedback;
    QAction *actionCheckUpdate;
    QAction *actionAbout;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 750);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxFile = new QGroupBox(centralWidget);
        groupBoxFile->setObjectName("groupBoxFile");
        horizontalLayoutFile = new QHBoxLayout(groupBoxFile);
        horizontalLayoutFile->setSpacing(6);
        horizontalLayoutFile->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutFile->setObjectName("horizontalLayoutFile");
        txtFilePath = new QLineEdit(groupBoxFile);
        txtFilePath->setObjectName("txtFilePath");
        txtFilePath->setReadOnly(true);

        horizontalLayoutFile->addWidget(txtFilePath);

        btnSelectFile = new QPushButton(groupBoxFile);
        btnSelectFile->setObjectName("btnSelectFile");

        horizontalLayoutFile->addWidget(btnSelectFile);


        verticalLayout->addWidget(groupBoxFile);

        groupBoxVersion = new QGroupBox(centralWidget);
        groupBoxVersion->setObjectName("groupBoxVersion");
        horizontalLayoutVersion = new QHBoxLayout(groupBoxVersion);
        horizontalLayoutVersion->setSpacing(6);
        horizontalLayoutVersion->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutVersion->setObjectName("horizontalLayoutVersion");
        cmbUpxVersion = new QComboBox(groupBoxVersion);
        cmbUpxVersion->setObjectName("cmbUpxVersion");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbUpxVersion->sizePolicy().hasHeightForWidth());
        cmbUpxVersion->setSizePolicy(sizePolicy);

        horizontalLayoutVersion->addWidget(cmbUpxVersion);


        verticalLayout->addWidget(groupBoxVersion);

        groupBoxAction = new QGroupBox(centralWidget);
        groupBoxAction->setObjectName("groupBoxAction");
        horizontalLayoutAction = new QHBoxLayout(groupBoxAction);
        horizontalLayoutAction->setSpacing(6);
        horizontalLayoutAction->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutAction->setObjectName("horizontalLayoutAction");
        rdoCompress = new QRadioButton(groupBoxAction);
        rdoCompress->setObjectName("rdoCompress");
        rdoCompress->setChecked(true);

        horizontalLayoutAction->addWidget(rdoCompress);

        rdoDecompress = new QRadioButton(groupBoxAction);
        rdoDecompress->setObjectName("rdoDecompress");

        horizontalLayoutAction->addWidget(rdoDecompress);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutAction->addItem(horizontalSpacer);


        verticalLayout->addWidget(groupBoxAction);

        groupBoxAdvanced = new QGroupBox(centralWidget);
        groupBoxAdvanced->setObjectName("groupBoxAdvanced");
        verticalLayoutAdvanced = new QVBoxLayout(groupBoxAdvanced);
        verticalLayoutAdvanced->setSpacing(6);
        verticalLayoutAdvanced->setContentsMargins(11, 11, 11, 11);
        verticalLayoutAdvanced->setObjectName("verticalLayoutAdvanced");
        horizontalLayoutPreset = new QHBoxLayout();
        horizontalLayoutPreset->setSpacing(6);
        horizontalLayoutPreset->setObjectName("horizontalLayoutPreset");
        lblPreset = new QLabel(groupBoxAdvanced);
        lblPreset->setObjectName("lblPreset");

        horizontalLayoutPreset->addWidget(lblPreset);

        cmbPreset = new QComboBox(groupBoxAdvanced);
        cmbPreset->setObjectName("cmbPreset");
        sizePolicy.setHeightForWidth(cmbPreset->sizePolicy().hasHeightForWidth());
        cmbPreset->setSizePolicy(sizePolicy);

        horizontalLayoutPreset->addWidget(cmbPreset);

        horizontalSpacerPreset = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutPreset->addItem(horizontalSpacerPreset);


        verticalLayoutAdvanced->addLayout(horizontalLayoutPreset);

        gridLayoutParams = new QGridLayout();
        gridLayoutParams->setSpacing(6);
        gridLayoutParams->setObjectName("gridLayoutParams");
        chkLzma = new QCheckBox(groupBoxAdvanced);
        chkLzma->setObjectName("chkLzma");

        gridLayoutParams->addWidget(chkLzma, 0, 0, 1, 1);

        chkNoCompressExports = new QCheckBox(groupBoxAdvanced);
        chkNoCompressExports->setObjectName("chkNoCompressExports");

        gridLayoutParams->addWidget(chkNoCompressExports, 0, 1, 1, 1);

        chkStripRelocs = new QCheckBox(groupBoxAdvanced);
        chkStripRelocs->setObjectName("chkStripRelocs");

        gridLayoutParams->addWidget(chkStripRelocs, 1, 0, 1, 1);

        chkOverlayCopy = new QCheckBox(groupBoxAdvanced);
        chkOverlayCopy->setObjectName("chkOverlayCopy");

        gridLayoutParams->addWidget(chkOverlayCopy, 1, 1, 1, 1);

        chkBrute = new QCheckBox(groupBoxAdvanced);
        chkBrute->setObjectName("chkBrute");

        gridLayoutParams->addWidget(chkBrute, 2, 0, 1, 1);

        chkUltraBrute = new QCheckBox(groupBoxAdvanced);
        chkUltraBrute->setObjectName("chkUltraBrute");

        gridLayoutParams->addWidget(chkUltraBrute, 2, 1, 1, 1);

        chkNrv2c = new QCheckBox(groupBoxAdvanced);
        chkNrv2c->setObjectName("chkNrv2c");

        gridLayoutParams->addWidget(chkNrv2c, 3, 0, 1, 1);


        verticalLayoutAdvanced->addLayout(gridLayoutParams);


        verticalLayout->addWidget(groupBoxAdvanced);

        groupBoxInfo = new QGroupBox(centralWidget);
        groupBoxInfo->setObjectName("groupBoxInfo");
        verticalLayoutInfo = new QVBoxLayout(groupBoxInfo);
        verticalLayoutInfo->setSpacing(6);
        verticalLayoutInfo->setContentsMargins(11, 11, 11, 11);
        verticalLayoutInfo->setObjectName("verticalLayoutInfo");
        lblFileInfo = new QLabel(groupBoxInfo);
        lblFileInfo->setObjectName("lblFileInfo");
        lblFileInfo->setWordWrap(true);

        verticalLayoutInfo->addWidget(lblFileInfo);


        verticalLayout->addWidget(groupBoxInfo);

        groupBoxOutput = new QGroupBox(centralWidget);
        groupBoxOutput->setObjectName("groupBoxOutput");
        verticalLayoutOutput = new QVBoxLayout(groupBoxOutput);
        verticalLayoutOutput->setSpacing(6);
        verticalLayoutOutput->setContentsMargins(11, 11, 11, 11);
        verticalLayoutOutput->setObjectName("verticalLayoutOutput");
        txtOutput = new QTextEdit(groupBoxOutput);
        txtOutput->setObjectName("txtOutput");
        txtOutput->setReadOnly(true);

        verticalLayoutOutput->addWidget(txtOutput);


        verticalLayout->addWidget(groupBoxOutput);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setSpacing(6);
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        lblStatus = new QLabel(centralWidget);
        lblStatus->setObjectName("lblStatus");

        horizontalLayoutButtons->addWidget(lblStatus);

        lblCompressRatio = new QLabel(centralWidget);
        lblCompressRatio->setObjectName("lblCompressRatio");
        lblCompressRatio->setStyleSheet(QString::fromUtf8("color: #0066cc; font-weight: bold;"));

        horizontalLayoutButtons->addWidget(lblCompressRatio);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutButtons->addItem(horizontalSpacer_2);

        btnCheckStatus = new QPushButton(centralWidget);
        btnCheckStatus->setObjectName("btnCheckStatus");
        btnCheckStatus->setEnabled(false);

        horizontalLayoutButtons->addWidget(btnCheckStatus);

        btnExecute = new QPushButton(centralWidget);
        btnExecute->setObjectName("btnExecute");
        btnExecute->setEnabled(false);

        horizontalLayoutButtons->addWidget(btnExecute);


        verticalLayout->addLayout(horizontalLayoutButtons);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        actionOpenFile = new QAction(menuBar);
        actionOpenFile->setObjectName("actionOpenFile");
        actionExit = new QAction(menuBar);
        actionExit->setObjectName("actionExit");
        actionUPXWebsite = new QAction(menuBar);
        actionUPXWebsite->setObjectName("actionUPXWebsite");
        actionUpdateWebsite = new QAction(menuBar);
        actionUpdateWebsite->setObjectName("actionUpdateWebsite");
        actionFeedback = new QAction(menuBar);
        actionFeedback->setObjectName("actionFeedback");
        actionCheckUpdate = new QAction(menuBar);
        actionCheckUpdate->setObjectName("actionCheckUpdate");
        actionAbout = new QAction(menuBar);
        actionAbout->setObjectName("actionAbout");
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenFile);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionUPXWebsite);
        menuHelp->addAction(actionUpdateWebsite);
        menuHelp->addAction(actionFeedback);
        menuHelp->addAction(actionCheckUpdate);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UPX GUI - \345\216\213\347\274\251/\350\247\243\345\216\213\345\267\245\345\205\267 By\357\274\232 Journeyer", nullptr));
        groupBoxFile->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        btnSelectFile->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
        groupBoxVersion->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251UPX\347\211\210\346\234\254", nullptr));
        groupBoxAction->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\347\261\273\345\236\213", nullptr));
        rdoCompress->setText(QCoreApplication::translate("MainWindow", "\345\216\213\347\274\251", nullptr));
        rdoDecompress->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\216\213", nullptr));
        groupBoxAdvanced->setTitle(QCoreApplication::translate("MainWindow", "\351\253\230\347\272\247\351\200\211\351\241\271\357\274\210\351\230\262\350\257\257\346\212\245\344\274\230\345\214\226\357\274\211", nullptr));
        lblPreset->setText(QCoreApplication::translate("MainWindow", "\351\242\204\350\256\276\346\226\271\346\241\210\357\274\232", nullptr));
        chkLzma->setText(QCoreApplication::translate("MainWindow", "LZMA\347\256\227\346\263\225 (--lzma)", nullptr));
        chkNoCompressExports->setText(QCoreApplication::translate("MainWindow", "\344\270\215\345\216\213\347\274\251\345\257\274\345\207\272\350\241\250 (--no-compress-exports)", nullptr));
        chkStripRelocs->setText(QCoreApplication::translate("MainWindow", "\345\211\245\347\246\273\351\207\215\345\256\232\344\275\215\344\277\241\346\201\257 (--strip-relocs)", nullptr));
        chkOverlayCopy->setText(QCoreApplication::translate("MainWindow", "\344\277\235\347\225\231\351\231\204\345\212\240\346\225\260\346\215\256 (--overlay=copy)", nullptr));
        chkBrute->setText(QCoreApplication::translate("MainWindow", "\345\274\272\345\212\233\345\216\213\347\274\251 (--brute)", nullptr));
        chkUltraBrute->setText(QCoreApplication::translate("MainWindow", "\346\236\201\351\231\220\345\216\213\347\274\251 (--ultra-brute)", nullptr));
        chkNrv2c->setText(QCoreApplication::translate("MainWindow", "NRV2C\347\256\227\346\263\225 (--nrv2c)", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\344\277\241\346\201\257", nullptr));
        lblFileInfo->setText(QCoreApplication::translate("MainWindow", "\346\234\252\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        groupBoxOutput->setTitle(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227", nullptr));
        lblStatus->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201: \347\255\211\345\276\205\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        lblCompressRatio->setText(QCoreApplication::translate("MainWindow", "\345\216\213\347\274\251\347\216\207: --", nullptr));
        btnCheckStatus->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\347\212\266\346\200\201", nullptr));
        btnExecute->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionUPXWebsite->setText(QCoreApplication::translate("MainWindow", "UPX \345\256\230\347\275\221", nullptr));
        actionUpdateWebsite->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260\345\256\230\347\275\221", nullptr));
        actionFeedback->setText(QCoreApplication::translate("MainWindow", "\347\225\231\350\250\200\345\217\215\351\246\210", nullptr));
        actionCheckUpdate->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\237\245\346\233\264\346\226\260", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\350\275\257\344\273\266", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
