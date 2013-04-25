
@set toolset=msvc-9.0
@if "%1"=="vc10" set toolset=msvc-10.0

cd boost
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_x64 --build-dir=build_x64 link=static toolset=%toolset% architecture=x86 address-model=64
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_x64 --build-dir=build_x64 link=static runtime-link=static toolset=%toolset% architecture=x86 address-model=64
