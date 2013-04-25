rem build the whole boost x64 library 

@set toolset=msvc-9.0
@if "%1"=="vc10" set toolset=msvc-10.0

cd boost
bjam --stagedir=stage_x64 --build-dir=build_x64 --build-type=complete toolset=%toolset% architecture=x86 address-model=64
