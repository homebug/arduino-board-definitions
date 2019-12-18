@echo off

cd %1%

FOR /F "tokens=* USEBACKQ" %%F IN (`git describe --tags --always --dirty`) DO (
SET var=%%F
)

echo #define GIT_VERSION "%var%" > %2%/sketch/git-version.h