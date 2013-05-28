@echo off
setlocal ENABLEDELAYEDEXPANSION
rem Author: Mark Tsuchida
rem See contrib\vstudio\readme.txt.
rem
rem Change these two paths as needed:
set ZLIB_SRC_ROOT=..\..\zlib-1.2.8
set VC_DIR="C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC"


if "%1" == "/f" (
  call :do_build
  goto :EOF
)
if "%1" == "/F" (
  call :do_build
  goto :EOF
)
echo.
echo Before building, you should modify the project files to link to the DLL
echo version of the Microsoft C Runtime (/MD or /MDd) in the Win32
echo configuration. At least in zlib 1.2.8, the x64 configuration already
echo uses this setting.
echo.
echo If MinGW is available, this can be accomplished by running
echo   sed -i 's/RuntimeLibrary="0"/RuntimeLibrary="2"/' *.vcproj
echo   sed -i 's/RuntimeLibrary="1"/RuntimeLibrary="3"/' *.vcproj
echo in zlib/contrib/vstudio/vc9.
echo.
echo Rerun this batch file as '%0 /f' to bypass this message.
goto :EOF


:do_build
call :build_asm
call :build_libs
call :stage_libs
goto :EOF


:clear_env
set INCLUDE=
set LIBS=
set LIBPATH=
goto :EOF


:build_asm
call :clear_env
pushd %VC_DIR%
call vcvarsall.bat
popd
pushd %ZLIB_SRC_ROOT%\contrib\masmx86
call bld_ml32.bat
popd

call :clear_env
pushd %VC_DIR%
call bin\vcvars64.bat
popd
pushd %ZLIB_SRC_ROOT%\contrib\masmx64
call bld_ml64.bat
popd
goto :EOF


:build_libs
call :clear_env
pushd %VC_DIR%
call vcvarsall.bat
popd

pushd %ZLIB_SRC_ROOT%\contrib\vstudio\vc9
vcbuild /rebuild zlibvc.sln "Debug|Win32"
vcbuild /rebuild zlibvc.sln "Release|Win32"
vcbuild /rebuild zlibvc.sln "Debug|x64"
vcbuild /rebuild zlibvc.sln "Release|x64"
popd
goto :EOF


:stage_libs
for %%I in (Debug Release) do (
  set DEST_DIR=.\Win32\%%I
  if not exist !DEST_DIR! md !DEST_DIR!
  copy "%ZLIB_SRC_ROOT%\contrib\vstudio\vc9\x86\ZlibStat%%I\zlibstat.lib" !DEST_DIR!

  set DEST_DIR=.\x64\%%I
  if not exist !DEST_DIR! md !DEST_DIR!
  copy "%ZLIB_SRC_ROOT%\contrib\vstudio\vc9\x64\ZlibStat%%I\zlibstat.lib" !DEST_DIR!
)
goto :EOF
