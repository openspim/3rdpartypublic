rem nmake needs the assembler ml64.exe
set path=C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\bin\amd64;%path%

pushd "\Program Files (x86)\Microsoft Visual Studio 9.0"\vc
rem this is how we setup the compiler to generate x64 code:
call vcvarsall amd64
popd

