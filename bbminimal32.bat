cd boost
bjam --with-date_time --with-thread --stagedir=stage_Win32 --build-dir=build_Win32 link=static toolset=msvc-9.0 architecture=x86 address-model=32
bjam --with-date_time --with-thread --with-system --with-regex --stagedir=stage_Win32 --build-dir=build_Win32 link=static runtime-link=static toolset=msvc-9.0 architecture=x86 address-model=32
