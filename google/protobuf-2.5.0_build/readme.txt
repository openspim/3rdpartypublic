Protobuf 2.5.0 for Windows

How this was built

Generally, follow the directions in vsprojects\readme.txt in the source
distribution.

To build with VS2010, open protobuf.sln and allow VS to perform autoconvert.
Then, select all projects, open Properties, select all configurations and all
platforms, and set Platform Toolset to WindowsSDK7.1.

To add an x64 build, create the x64 configuration (copy settings from Win32).
No further settings need to be changed (although the output will go to the same
directory as the Win32 by default, so perhaps add $(Platform) to the output
directory).

To build from the Visual Studio command line:
msbuild /p:Configuration=Debug /p:Platform=Win32 protobuf.sln
msbuild /p:Configuration=Release /p:Platform=Win32 protobuf.sln
msbuild /p:Configuration=Debug /p:Platform=x64 protobuf.sln
msbuild /p:Configuration=Release /p:Platform=x64 protobuf.sln

After the C++ build and running extract_includes.bat, copy
inlucde/* to $dest/include/*
protoc.exe (from Release|Win32 build) to $dest/bin
libprotobuf.lib, libprotobuf-lite.lib, and libprotoc.lib to the config-platform
directory under $dest/lib

(2013.07.30 Mark Tsuchida)
