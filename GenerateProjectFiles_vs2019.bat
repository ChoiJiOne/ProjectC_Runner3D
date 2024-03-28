@echo off

SET visualstudio=vs2019
SET project=ProjectC
SET script=GameEngine\Script\GenerateProjectFiles.bat

%script% %visualstudio% %project% On