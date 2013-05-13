REM Before building with Visual Studio 2010 + Windows SDK 7.1, you need to run
REM "C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\setenv.cmd" /x64
REM , or equivalent. Also add --with-chrono if using a more recent boost (e.g.
REM 1.53.0).

cd boost
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_x64 --build-dir=build_x64 link=static toolset=msvc-10.0 address-model=64
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_x64 --build-dir=build_x64 link=static runtime-link=static toolset=msvc-10.0 address-model=64
