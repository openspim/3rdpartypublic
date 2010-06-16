rem   pushd "\Program Files\Microsoft Visual Studio 9.0"\vc
rem   vcvarall
rem   popd


nmake -f win32/Makefile.msc AS=ml64 LOC="-DASMV -DASMINF"  OBJA="inffasx64.obj gvmat64.obj inffas8664.c" 

