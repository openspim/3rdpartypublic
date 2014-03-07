REM Building Boost as static libraries (VS 2010, Windows SDK 7.1) for
REM Micro-Manager
REM
REM The /MD and /MT library variants have different name, so they can go into
REM the same directory. The 32-bit and 64-bit versions need to go into separate
REM directories.
REM
REM Linking happens automatically via the headers, so the libraries simply need
REM to be on the library search path.
REM
REM When build is complete, copy the *.lib files in stage_* to appropriate
REM destination.
REM
REM (Note: Some libraries not (yet) in use by MM are included in the build
REM below.)


cd boost_1_55_0

bootstrap.bat


"C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\setenv.cmd" /x86 /Release

REM 32-bit /MD
b2 --with-system --with-atomic --with-thread --with-regex --with-chrono --with-date_time --with-timer --with-log --stagedir=stage_Win32 --build-dir=build_Win32 toolset=msvc-10.0 address-model=32 link=static runtime-link=shared

REM 32-bit /MT
b2 --with-system --with-atomic --with-thread --with-regex --with-chrono --with-date_time --with-timer --with-log --stagedir=stage_Win32 --build-dir=build_Win32 toolset=msvc-10.0 address-model=32 link=static runtime-link=static


"C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\setenv.cmd" /x64 /Release

REM 64-bit /MD
b2 --with-system --with-atomic --with-thread --with-regex --with-chrono --with-date_time --with-timer --with-log --stagedir=stage_x64 --build-dir=build_x64 toolset=msvc-10.0 address-model=64 link=static runtime-link=shared

REM 64-bit /MT
b2 --with-system --with-atomic --with-thread --with-regex --with-chrono --with-date_time --with-timer --with-log --stagedir=stage_x64 --build-dir=build_x64 toolset=msvc-10.0 address-model=64 link=static runtime-link=static
