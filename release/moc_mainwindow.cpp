/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_btnSelectFile_clicked",
    "",
    "on_btnExecute_clicked",
    "on_btnCheckStatus_clicked",
    "on_cmbUpxVersion_currentIndexChanged",
    "index",
    "on_rdoCompress_toggled",
    "checked",
    "on_rdoDecompress_toggled",
    "on_actionOpenFile_triggered",
    "on_actionExit_triggered",
    "on_actionUPXWebsite_triggered",
    "on_actionUpdateWebsite_triggered",
    "on_actionFeedback_triggered",
    "on_actionAbout_triggered",
    "on_actionCheckUpdate_triggered",
    "on_cmbPreset_currentIndexChanged",
    "on_chkLzma_toggled",
    "on_chkNoCompressExports_toggled",
    "on_chkStripRelocs_toggled",
    "on_chkOverlayCopy_toggled",
    "on_chkBrute_toggled",
    "on_chkUltraBrute_toggled",
    "on_chkNrv2c_toggled",
    "processFinished",
    "exitCode",
    "QProcess::ExitStatus",
    "exitStatus",
    "processReadyReadStandardOutput",
    "processReadyReadStandardError",
    "onUpdateCheckFinished",
    "QNetworkReply*",
    "reply",
    "onUpdateCheckError",
    "QNetworkReply::NetworkError",
    "error",
    "onAutoUpdateCheck"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[76];
    char stringdata0[11];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[26];
    char stringdata5[37];
    char stringdata6[6];
    char stringdata7[23];
    char stringdata8[8];
    char stringdata9[25];
    char stringdata10[28];
    char stringdata11[24];
    char stringdata12[30];
    char stringdata13[33];
    char stringdata14[28];
    char stringdata15[25];
    char stringdata16[31];
    char stringdata17[33];
    char stringdata18[19];
    char stringdata19[32];
    char stringdata20[26];
    char stringdata21[26];
    char stringdata22[20];
    char stringdata23[25];
    char stringdata24[20];
    char stringdata25[16];
    char stringdata26[9];
    char stringdata27[21];
    char stringdata28[11];
    char stringdata29[31];
    char stringdata30[30];
    char stringdata31[22];
    char stringdata32[15];
    char stringdata33[6];
    char stringdata34[19];
    char stringdata35[28];
    char stringdata36[6];
    char stringdata37[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 24),  // "on_btnSelectFile_clicked"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 21),  // "on_btnExecute_clicked"
        QT_MOC_LITERAL(59, 25),  // "on_btnCheckStatus_clicked"
        QT_MOC_LITERAL(85, 36),  // "on_cmbUpxVersion_currentIndex..."
        QT_MOC_LITERAL(122, 5),  // "index"
        QT_MOC_LITERAL(128, 22),  // "on_rdoCompress_toggled"
        QT_MOC_LITERAL(151, 7),  // "checked"
        QT_MOC_LITERAL(159, 24),  // "on_rdoDecompress_toggled"
        QT_MOC_LITERAL(184, 27),  // "on_actionOpenFile_triggered"
        QT_MOC_LITERAL(212, 23),  // "on_actionExit_triggered"
        QT_MOC_LITERAL(236, 29),  // "on_actionUPXWebsite_triggered"
        QT_MOC_LITERAL(266, 32),  // "on_actionUpdateWebsite_triggered"
        QT_MOC_LITERAL(299, 27),  // "on_actionFeedback_triggered"
        QT_MOC_LITERAL(327, 24),  // "on_actionAbout_triggered"
        QT_MOC_LITERAL(352, 30),  // "on_actionCheckUpdate_triggered"
        QT_MOC_LITERAL(383, 32),  // "on_cmbPreset_currentIndexChanged"
        QT_MOC_LITERAL(416, 18),  // "on_chkLzma_toggled"
        QT_MOC_LITERAL(435, 31),  // "on_chkNoCompressExports_toggled"
        QT_MOC_LITERAL(467, 25),  // "on_chkStripRelocs_toggled"
        QT_MOC_LITERAL(493, 25),  // "on_chkOverlayCopy_toggled"
        QT_MOC_LITERAL(519, 19),  // "on_chkBrute_toggled"
        QT_MOC_LITERAL(539, 24),  // "on_chkUltraBrute_toggled"
        QT_MOC_LITERAL(564, 19),  // "on_chkNrv2c_toggled"
        QT_MOC_LITERAL(584, 15),  // "processFinished"
        QT_MOC_LITERAL(600, 8),  // "exitCode"
        QT_MOC_LITERAL(609, 20),  // "QProcess::ExitStatus"
        QT_MOC_LITERAL(630, 10),  // "exitStatus"
        QT_MOC_LITERAL(641, 30),  // "processReadyReadStandardOutput"
        QT_MOC_LITERAL(672, 29),  // "processReadyReadStandardError"
        QT_MOC_LITERAL(702, 21),  // "onUpdateCheckFinished"
        QT_MOC_LITERAL(724, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(739, 5),  // "reply"
        QT_MOC_LITERAL(745, 18),  // "onUpdateCheckError"
        QT_MOC_LITERAL(764, 27),  // "QNetworkReply::NetworkError"
        QT_MOC_LITERAL(792, 5),  // "error"
        QT_MOC_LITERAL(798, 17)   // "onAutoUpdateCheck"
    },
    "MainWindow",
    "on_btnSelectFile_clicked",
    "",
    "on_btnExecute_clicked",
    "on_btnCheckStatus_clicked",
    "on_cmbUpxVersion_currentIndexChanged",
    "index",
    "on_rdoCompress_toggled",
    "checked",
    "on_rdoDecompress_toggled",
    "on_actionOpenFile_triggered",
    "on_actionExit_triggered",
    "on_actionUPXWebsite_triggered",
    "on_actionUpdateWebsite_triggered",
    "on_actionFeedback_triggered",
    "on_actionAbout_triggered",
    "on_actionCheckUpdate_triggered",
    "on_cmbPreset_currentIndexChanged",
    "on_chkLzma_toggled",
    "on_chkNoCompressExports_toggled",
    "on_chkStripRelocs_toggled",
    "on_chkOverlayCopy_toggled",
    "on_chkBrute_toggled",
    "on_chkUltraBrute_toggled",
    "on_chkNrv2c_toggled",
    "processFinished",
    "exitCode",
    "QProcess::ExitStatus",
    "exitStatus",
    "processReadyReadStandardOutput",
    "processReadyReadStandardError",
    "onUpdateCheckFinished",
    "QNetworkReply*",
    "reply",
    "onUpdateCheckError",
    "QNetworkReply::NetworkError",
    "error",
    "onAutoUpdateCheck"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  176,    2, 0x08,    1 /* Private */,
       3,    0,  177,    2, 0x08,    2 /* Private */,
       4,    0,  178,    2, 0x08,    3 /* Private */,
       5,    1,  179,    2, 0x08,    4 /* Private */,
       7,    1,  182,    2, 0x08,    6 /* Private */,
       9,    1,  185,    2, 0x08,    8 /* Private */,
      10,    0,  188,    2, 0x08,   10 /* Private */,
      11,    0,  189,    2, 0x08,   11 /* Private */,
      12,    0,  190,    2, 0x08,   12 /* Private */,
      13,    0,  191,    2, 0x08,   13 /* Private */,
      14,    0,  192,    2, 0x08,   14 /* Private */,
      15,    0,  193,    2, 0x08,   15 /* Private */,
      16,    0,  194,    2, 0x08,   16 /* Private */,
      17,    1,  195,    2, 0x08,   17 /* Private */,
      18,    1,  198,    2, 0x08,   19 /* Private */,
      19,    1,  201,    2, 0x08,   21 /* Private */,
      20,    1,  204,    2, 0x08,   23 /* Private */,
      21,    1,  207,    2, 0x08,   25 /* Private */,
      22,    1,  210,    2, 0x08,   27 /* Private */,
      23,    1,  213,    2, 0x08,   29 /* Private */,
      24,    1,  216,    2, 0x08,   31 /* Private */,
      25,    2,  219,    2, 0x08,   33 /* Private */,
      29,    0,  224,    2, 0x08,   36 /* Private */,
      30,    0,  225,    2, 0x08,   37 /* Private */,
      31,    1,  226,    2, 0x08,   38 /* Private */,
      34,    1,  229,    2, 0x08,   40 /* Private */,
      37,    0,  232,    2, 0x08,   42 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 27,   26,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_btnSelectFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnExecute_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnCheckStatus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cmbUpxVersion_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_rdoCompress_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_rdoDecompress_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_actionOpenFile_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionUPXWebsite_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionUpdateWebsite_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFeedback_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAbout_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCheckUpdate_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cmbPreset_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_chkLzma_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkNoCompressExports_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkStripRelocs_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkOverlayCopy_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkBrute_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkUltraBrute_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkNrv2c_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'processFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QProcess::ExitStatus, std::false_type>,
        // method 'processReadyReadStandardOutput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processReadyReadStandardError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUpdateCheckFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'onUpdateCheckError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply::NetworkError, std::false_type>,
        // method 'onAutoUpdateCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnSelectFile_clicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnCheckStatus_clicked(); break;
        case 3: _t->on_cmbUpxVersion_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_rdoCompress_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_rdoDecompress_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_actionOpenFile_triggered(); break;
        case 7: _t->on_actionExit_triggered(); break;
        case 8: _t->on_actionUPXWebsite_triggered(); break;
        case 9: _t->on_actionUpdateWebsite_triggered(); break;
        case 10: _t->on_actionFeedback_triggered(); break;
        case 11: _t->on_actionAbout_triggered(); break;
        case 12: _t->on_actionCheckUpdate_triggered(); break;
        case 13: _t->on_cmbPreset_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_chkLzma_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->on_chkNoCompressExports_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_chkStripRelocs_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_chkOverlayCopy_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->on_chkBrute_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_chkUltraBrute_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_chkNrv2c_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->processFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 22: _t->processReadyReadStandardOutput(); break;
        case 23: _t->processReadyReadStandardError(); break;
        case 24: _t->onUpdateCheckFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 25: _t->onUpdateCheckError((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        case 26: _t->onAutoUpdateCheck(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_WARNING_POP
