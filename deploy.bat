@echo off
chcp 65001 >nul
echo ========================================
echo UPX_GUI 依赖部署脚本
echo ========================================
echo.

set QT_DIR=D:\Computer\Qt653\6.5.3\mingw_64\bin
set PROJECT_DIR=%~dp0
set RELEASE_DIR=%PROJECT_DIR%release

echo [1/3] 清理旧文件...
if exist "%PROJECT_DIR%deploy" rmdir /s /q "%PROJECT_DIR%deploy"
mkdir "%PROJECT_DIR%deploy"

echo.
echo [2/3] 复制程序文件...
copy "%PROJECT_DIR%UPX_GUI.exe" "%PROJECT_DIR%deploy\" >nul
copy "%PROJECT_DIR%upx-*.exe" "%PROJECT_DIR%deploy\" >nul
copy "%PROJECT_DIR%UPX_GUI_Info.txt" "%PROJECT_DIR%deploy\" >nul
copy "%PROJECT_DIR%version.txt" "%PROJECT_DIR%deploy\" >nul 2>nul
copy "%PROJECT_DIR%UPX_CMD_Shell.bat" "%PROJECT_DIR%deploy\" >nul

echo.
echo [3/3] 部署 Qt 依赖...
"%QT_DIR%\windeployqt.exe" "%PROJECT_DIR%deploy\UPX_GUI.exe" --release --no-translations --no-system-d3d-compiler --no-webkit --no-opengl-sw

echo.
echo ========================================
echo 部署完成！
echo 输出目录：%PROJECT_DIR%deploy
echo ========================================
pause