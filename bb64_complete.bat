rem build the whole boost x64 library 
cd boost
bjam --stagedir=stage_x64 --build-dir=build_x64 --build-type=complete toolset=msvc-9.0 architecture=x86 address-model=64