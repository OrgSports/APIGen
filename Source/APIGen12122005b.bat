rem ****************************************************************************
rem                   APIGen UNIX Shell Command File
rem
rem   This file is a batch file that contains command lines for Unix commands specified
rem   while running the AttachmateWRQ API Generator.  The format of the commands is
rem   taken from the MKS Toolkit and the file generated will be a .bat file intended
rem   to be run in a Windows command window.
rem
rem
rem   Generated:   Mon Dec 12 14:43:03 2005

rem
rem ****************************************************************************
rem
 
rem *** grep - search files w/basic regexp
grep  -n -f test.in *\*.cpp
grep  -n -f test.in *\*.h
