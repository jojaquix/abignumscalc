echo off
cls
echo Setting variables before CMAKE call
set BOOST_ROOT=C:\src\boost_1_64_0
rem set BOOST_INCLUDEDIR=C:\src\boost_1_64_0
rem set BOOST_LIBRARYDIR=C:\src\boost_1_64_0\x86\lib
echo Configuring project...
cmake ../src
