rem   pushd "\Program Files\Microsoft Visual Studio 9.0"\vc
rem   vcvarall
rem   popd


nmake -f win32/Makefile.msc LOC="-DASMV -DASMINF" OBJA="inffas32.obj match686.obj"
