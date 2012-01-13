cd boost
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_x64 --build-dir=build_x64 link=static toolset=msvc-9.0 architecture=x86 address-model=64
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_x64 --build-dir=build_x64 link=static runtime-link=static toolset=msvc-9.0 architecture=x86 address-model=64
