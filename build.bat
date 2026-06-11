@echo off
setlocal enabledelayedexpansion

echo ===============================
echo UPX GUI - Qt6.5.3 构建脚本
echo ===============================
echo.

set QT_PATH=D:\Computer\Qt653\6.5.3\mingw_64\bin
set GCC_PATH=C:\TDM-GCC-64\bin
set QMAKE_PATH=%QT_PATH%\qmake.exe
set MAKE_PATH=%GCC_PATH%\mingw32-make.exe

echo 检查 Qt 环境...
if not exist "%QMAKE_PATH%" (
    echo 错误: 未找到 qmake.exe
    echo 路径: %QMAKE_PATH%
    pause
    exit /b 1
)

echo 检查 GCC 环境...
if not exist "%MAKE_PATH%" (
    echo 错误: 未找到 mingw32-make.exe
    echo 路径: %MAKE_PATH%
    pause
    exit /b 1
)

echo 设置环境变量...
set PATH=%GCC_PATH%;%QT_PATH%;%PATH%

echo 生成 Makefile...
"%QMAKE_PATH%" upx_gui.pro -spec win32-g++
if %errorlevel% neq 0 (
    echo 错误: qmake 执行失败
    pause
    exit /b 1
)

echo 编译项目...
"%MAKE_PATH%" -f Makefile.Release
if %errorlevel% neq 0 (
    echo 错误: 编译失败
    pause
    exit /b 1
)

echo.
echo ===============================
echo 构建成功！
echo 输出文件: UPX_GUI.exe
echo ===============================
pause
