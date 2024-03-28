@echo off

SET target=%1
SET block=%2

SET lua=%~dp0..\Bin\lua54.exe
SET script=%~dp0CompressAstc.lua

start %lua% %script% %target% %block%