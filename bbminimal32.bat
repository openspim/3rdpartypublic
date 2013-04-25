REM you need to run Microsoft vcvarsall.bat to set the environment variables....

@set toolset=msvc-vc9.0
@if "%1"=="vc10" set toolset=msvc-vc10.0

cd boost
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_Win32 --build-dir=build_Win32 link=static toolset=%toolset% architecture=x86 address-model=32
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_Win32 --build-dir=build_Win32 link=static runtime-link=static toolset=%toolset% architecture=x86 address-model=32
