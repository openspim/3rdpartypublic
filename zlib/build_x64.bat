set path=C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\bin\amd64;%path%

rem   pushd "\Program Files (x86)\Microsoft Visual Studio 9.0"\vc
rem   vcvarsall amd64
rem   popd


nmake -f win32/Makefile.msc OBJA="inffast.obj"
