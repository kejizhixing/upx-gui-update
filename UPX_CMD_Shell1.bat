@echo off
:: ☆☆☆ 注意事项：不能在含 % 路径中安装右键菜单！☆☆☆
if /i "%UserName%" == "SYSTEM" (Goto GotAdmin) else (reg query "HKLM\SYSTEM\ControlSet001\Control\MiniNT" 1>nul 2>nul&&Goto GotAdmin)
:BatchGotAdmin
Set _Args=%*
if `%1` neq `` Set "_Args=%_Args:"=""%"
if exist %WinDir%\System32\fltMC.exe fltMC 1>nul 2>nul||mshta VBScript:CreateObject("Shell.Application").ShellExecute("cmd.exe","/c """"%~f0"" %_Args%""",,"runas",1)(Window.Close) 2>nul&&Exit /b

:GotAdmin
Pushd "%CD%"&cd /d "%~dp0"
REM 判断输入参数
Set hint=启用提示&Set Installed=
if /i `%1` == `` Goto Green
if /i `%1` == `install` Set hint=&Goto Install
if /i `%1` == `uninsta` Set hint=&Goto UnInsta
Set file=%1

:UPX
Title UPX_CMD_Shell
if not exist %file% (Mode 41,10 2>nul&Color 2f&Call :EchoX "cf.:文件不存在，按任意键退出。。。"&Call :Delay 5&Exit /b)
Set flag=　√
Set upx1_e=%flag:~0,1%&Set upx1=upx-1.25-win32.exe
Set upx2_e=%flag:~0,1%&Set upx2=upx-2.3-win32.exe
Set upx3_e=%flag:~0,1%&Set upx3=upx-4.2.2-win32.exe
Set upx4_e=%flag:~0,1%&Set upx4=upx-4.2.2-win64.exe
Set upx5_e=%flag:~0,1%&Set upx5=upx-5.2.0-win32.exe
Set upx6_e=%flag:~0,1%&Set upx6=upx-5.2.0-win64.exe
Set compr=
%upx1% -t %file% 1>nul 2>nul
if %ErrorLevel% == 0 Set upx1_e=%flag:~1,1%&Set compr=1
%upx2% -t %file% 1>nul 2>nul
if %ErrorLevel% == 0 Set upx2_e=%flag:~1,1%&Set compr=1
%upx3% -t %file% 1>nul 2>nul
if %ErrorLevel% == 0 Set upx3_e=%flag:~1,1%&Set compr=1
%upx4% -t %file% 1>nul 2>nul
if %ErrorLevel% == 0 Set upx4_e=%flag:~1,1%&Set compr=1
%upx5% -t %file% 1>nul 2>nul
if %ErrorLevel% == 0 Set upx5_e=%flag:~1,1%&Set compr=1
%upx6% -t %file% 1>nul 2>nul
if %ErrorLevel% == 0 Set upx6_e=%flag:~1,1%&Set compr=1
if defined compr (Set ☆=★&Set state=已被UPX压缩&Set action=解压) else (Set ☆=☆&Set state=未被UPX压缩&Set action=压缩)
Mode 44,21 2>nul&Color 2f
Set err=0

:Menu
Cls&Call :EchoX "9f::[ 处理文件 ] " "↓            %☆% " "2e::%state%" "xx.: %☆%"&echo %file%
echo.
echo     ------------------------------------
echo    ｜         软件版本         ｜ %action% ｜
echo     ------------------------------------
Call :EchoX "   ｜" "f2::[1]" "  %upx1%   ｜  " "2e::%upx1_e%" "xx.:  ｜"
Call :EchoX "xx.:   ｜                          ｜      ｜"
Call :EchoX "   ｜" "f2::[2]" "  %upx2%    ｜  " "2e::%upx2_e%" "xx.:  ｜"
Call :EchoX "xx.:   ｜                          ｜      ｜"
Call :EchoX "   ｜" "f2::[3]" "  %upx3%  ｜  " "2e::%upx3_e%" "xx.:  ｜"
Call :EchoX "xx.:   ｜                          ｜      ｜"
Call :EchoX "   ｜" "f2::[4]" "  %upx4%  ｜  " "2e::%upx4_e%" "xx.:  ｜"
Call :EchoX "xx.:   ｜                          ｜      ｜"
Call :EchoX "   ｜" "f2::[5]" "  %upx5%  ｜  " "2e::%upx5_e%" "xx.:  ｜"
Call :EchoX "xx.:   ｜                          ｜      ｜"
Call :EchoX "   ｜" "f2::[6]" "  %upx6%  ｜  " "2e::%upx6_e%" "xx.:  ｜"
echo     ------------------------------------
echo.
if %err% gtr 0 Call :EchoX "cf::输入无效请重新输入！" "cf.:(メ%err%)"
Set cho=&Set /p cho=选择: 
Set "cho=%cho:"=%"
if "%cho:~-1%" == "=" Goto Menu
:DelRSpac :: 删除尾部空格
if "%cho:~-1%" == " " (
Set "cho=%cho:~0,-1%"&Goto DelRSpac)
if not defined cho Goto Menu
if /i "%cho%" == "1" Cls&Set cstr=&Goto Decomp
if /i "%cho%" == "2" Cls&Set cstr=&Goto Decomp
if /i "%cho%" == "3" Cls&Set cstr=--ultra-brute&Goto Decomp
if /i "%cho%" == "4" Cls&Set cstr=--ultra-brute&Goto Decomp
if /i "%cho%" == "5" Cls&Set cstr=--ultra-brute&Goto Decomp
if /i "%cho%" == "6" Cls&Set cstr=--ultra-brute&Goto Decomp
if /i "%cho%" == "q" Popd&Exit
if exist "%cho%" Set file="%cho%"&Cls&Goto UPX
Set /a err+=1&Goto Menu

:Decomp
Mode 80,23 2>nul&Color 2f
Setlocal EnableDelayedExpansion
Set upx_=!upx%cho%!&Set upx_e=!upx%cho%_e!
Title UPX_CMD_Shell              === [ !upx_! ] ===
if "!upx_e!" == "%flag:~0,1%" (
    REM --best 最佳压缩（大文件可能很慢）
    REM !upx_! -f --best %cstr% %file%
    !upx_! -f %cstr% %file%
    if !ErrorLevel! == 0 (echo.&Call :EchoX "9f.: 成功，压缩完成！！") else (echo.&Call :EchoX "cf.: 出错，压缩失败！！")
) else (
    !upx_! -d %file%
    if !ErrorLevel! == 0 (echo.&Call :EchoX "e0.: 成功，解压完成！！") else (echo.&Call :EchoX "cf.: 出错，解压失败！！")
)
Endlocal
Call :Delay 5 +&Cls&Goto UPX

:Green
Title UPX_CMD_Shell&Mode 41,10 2>nul&Color 2f
reg query "HKCR\exefile\Shell\UPX_CMD_Shell" 1>nul 2>nul&&Set Installed=1||Set Installed=0
if "%Installed%" == "1" Goto UnInsta

:Install
if defined hint Call :EchoX "e0.: 正在安装中，请稍候。。。"
REM 添加到右键菜单
Set "XD=%CD%"
Set "XD=%XD:&=^&%"
Call :RMenu acm add
Call :RMenu ax add
Call :RMenu bpl add
Call :RMenu com add
Call :RMenu dll add
Call :RMenu dpl add
Call :RMenu exe add
Call :RMenu ocx add
Call :RMenu scr add
Call :RMenu sys add
Goto End

:UnInsta
if defined hint Call :EchoX "e0.: 正在卸载中，请稍候。。。"
REM 从右键菜单删除
Call :RMenu acm del
Call :RMenu ax del
Call :RMenu bpl del
Call :RMenu com del
Call :RMenu dll del
Call :RMenu dpl del
Call :RMenu exe del
Call :RMenu ocx del
Call :RMenu scr del
Call :RMenu sys del
Goto End

:End
if defined hint (
    Cls&if "%Installed%" == "0" (Color 9f&echo [ 已添加到右键菜单 ]) else (Color cf&echo [ 已从右键菜单删除 ])
    Call :Delay 2 +
)
Set hint=&Set Installed=&Exit /b

:RMenu :: 关联操作 <%1=ext|扩展名> [%2=del|删除菜单]
if /i "%~2" == "del" (reg delete "HKCR\%~1file\Shell\UPX_CMD_Shell" /f 1>nul 2>nul&Goto :eof)
reg add "HKCR\.%~1" /f /ve /t REG_SZ /d "%~1file" 1>nul 2>nul
reg add "HKCR\%~1file\Shell\UPX_CMD_Shell" /f /ve /t REG_SZ /d "用 UPX [压缩/解压]" 1>nul 2>nul
reg add "HKCR\%~1file\Shell\UPX_CMD_Shell" /f /v "Icon" /t REG_SZ /d "%CD%\upx_Icon.ico,0" 1>nul 2>nul
reg add "HKCR\%~1file\Shell\UPX_CMD_Shell\Command" /f /ve /t REG_SZ /d "\"%XD%\%~n0%~x0\" \"%%1\"" 1>nul 2>nul
Goto :eof

:Delay :: 延迟操作 <%1=Sec|延迟秒数> [%2=+|显示倒计时]
if `%2` == `+` (Set n=2) else Set n=1
if exist %WinDir%\System32\timeout.exe (timeout /t %1 %n%>nul) else if exist %WinDir%\System32\choice.exe (choice /t %1 /d y /n >nul) else ping 127.1 -n %1 >nul
Goto :eof

:EchoX :: 显示彩色文字 (不支持半角字符 \ / : * ? " < >|. % ! ~)。
Setlocal EnableDelayedExpansion
Set echox=EchoX.exe&&!echox! 1>nul 2>nul||(Set echox=&mkdir "%TEMP%\EchoX" 2>nul&&attrib +s +h "%TEMP%\EchoX" 2>nul)
for %%a in (%*) do (
    Set "param=%%~a"&Set "color=!param:~0,2!"&(if not exist %WinDir%\System32\findstr.exe if not defined echox Set "color=xx")
    Set n=0&(if "!param:~2,2!" == "::" Set n=1)&(if "!param:~2,2!" == ".:" Set n=2)
    if !n! gtr 0 (
        if /i "!color!" == "xx" (Set /p="_!param:~4!"<nul) else (Set param=%%~nxa&if defined echox (!echox! -c !color! -n "!param:~4!") else (Pushd "%TEMP%\EchoX" 2>nul&>"!param:~4!",Set /p= <nul&findstr /a:!color! .* "!param:~4!*"&del "!param:~4!"&Popd))
        if !n! == 2 echo.
    ) else if defined param Set /p="_!param!"<nul
)
Endlocal&Goto :eof