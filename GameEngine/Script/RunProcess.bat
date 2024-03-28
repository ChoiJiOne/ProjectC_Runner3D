@echo off

echo Start "RunProcess.bat" script...

SET mode=%1
SET name=%2
set currentPath=%~dp0
set rootPath=%~dp0..\..\
SET exePath=Solution\%mode%\%name%

pushd "%currentPath%"
pushd "%rootPath%"

start %exePath%

popd
popd