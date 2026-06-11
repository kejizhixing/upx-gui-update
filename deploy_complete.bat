@echo off
chcp 65001 >nul
echo ========================================
echo UPX_GUI 完整部署脚本
echo ========================================
echo.

set QT_DIR=D:\Computer\Qt653\6.5.3\mingw_64\bin
set PROJECT_DIR=%~dp0
set DEPLOY_DIR=%PROJECT_DIR%deploy_complete

echo [1/5] 清理旧文件...
if exist "%DEPLOY_DIR%" rmdir /s /q "%DEPLOY_DIR%"
mkdir "%DEPLOY_DIR%"
mkdir "%DEPLOY_DIR%\platforms"
mkdir "%DEPLOY_DIR%\styles"

echo.
echo [2/5] 复制主程序和文件...
copy "%PROJECT_DIR%UPX_GUI.exe" "%DEPLOY_DIR%\" >nul
copy "%PROJECT_DIR%upx-*.exe" "%DEPLOY_DIR%\" >nul
copy "%PROJECT_DIR%UPX_GUI_Info.txt" "%DEPLOY_DIR%\" >nul
copy "%PROJECT_DIR%version.txt" "%DEPLOY_DIR%\" >nul 2>nul
copy "%PROJECT_DIR%UPX_CMD_Shell.bat" "%DEPLOY_DIR%\" >nul

echo.
echo [3/5] 复制 Qt DLL 文件...
copy "%QT_DIR%\Qt6Core.dll" "%DEPLOY_DIR%\" >nul
copy "%QT_DIR%\Qt6Gui.dll" "%DEPLOY_DIR%\" >nul
copy "%QT_DIR%\Qt6Network.dll" "%DEPLOY_DIR%\" >nul
copy "%QT_DIR%\Qt6Widgets.dll" "%DEPLOY_DIR%\" >nul
copy "%QT_DIR%\libgcc_s_seh-1.dll" "%DEPLOY_DIR%\" >nul
copy "%QT_DIR%\libstdc++-6.dll" "%DEPLOY_DIR%\" >nul
copy "%QT_DIR%\libwinpthread-1.dll" "%DEPLOY_DIR%\" >nul

echo.
echo [4/5] 复制 Qt 插件...
copy "%QT_DIR%\..\plugins\platforms\qwindows.dll" "%DEPLOY_DIR%\platforms\" >nul
copy "%QT_DIR%\..\plugins\styles\qwindowsvistastyle.dll" "%DEPLOY_DIR%\styles\" >nul

echo.
echo [5/5] 创建启动脚本...
echo @echo off > "%DEPLOY_DIR%\启动.bat"
echo start "" "UPX_GUI.exe" >> "%DEPLOY_DIR%\启动.bat"

echo.
echo ========================================
echo 部署完成！
echo 输出目录：%DEPLOY_DIR%
echo ========================================
echo.
echo 说明：
echo 1. deploy_complete 文件夹包含所有依赖
echo 2. 可直接复制到其他电脑使用
echo 3. 双击 UPX_GUI.exe 或 启动.bat 运行
echo ========================================
pause