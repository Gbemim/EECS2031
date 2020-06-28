#!/bin/sh
# Check if a file is executable.
# Better version!
if test -e $1 && test -x $1
then
   echo File $1 is executable.
elif test ! -e $1
then
   echo File $1 does not exist.
else
   echo File $1 is not executable.
fi
