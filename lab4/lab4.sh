#!/bin/sh

# $1: the path
inp="command: "
l="list"
q="quit"
listOfComm="l or list: lists found courses
ci: gives the name of all courses plus number of credits
sl: gives a unique list of all students registered in all courses
sc: gives the total number of unique students registered in all courses
cc: gives the total numbers of found course files.
h or help: prints the current message.
q or quit: exits from the script \n"

# checks if the path $1 has a .rec file
#has_rec() {
    if test ! -e "$1" ; then
        printf "There is no *.rec file that exists in the specified path or its subdirectories \n"
        exit 1
    fi
#}
#has_rec

file=`find "$1" -type f  -name "*.rec" -perm /444`
if [ "X${class_files} = "X"" ] ; then
    #checks if the file is readable in user, group and other
    printf "$inp"
    read command #prints command; saves the input to variable $inp




    # while true, continue running this loop until q OR quit exit/end this loop
    while test true; do
        # prints out the list of files that ends with .rec and are readable by inputing the command l OR list
        if test "$command" = "$l" || test "$command" = "l"; then
            printf "Here is the list of found class files: \n"
            find "$1" -type f  -name "*.rec"



        # prints out the name and the credits for each course
        elif test "$command" = "ci" ; then
           printf "Found courses are: \n`cut -f3-4 -d\  *.rec | head -1` has `cut -f3-4 -d\  *.rec | head -2 | grep [0-9]` credits. \n"
            printf "`cut -f3-4 -d\  *.rec | tail -4 | head -1` has `cut -f3-4 -d\  *.rec | tail -3 | grep [0-9]` credits. \n"




        # prints out the unique students numbers taking either 1 or both of the courses. Students taking both classes,
        # their student number will be printed out once
        elif test "$command" = "sl" ; then
            printf "Here is the unique list of student numbers in all courses: \n"
            grep -oh "[0-9]\{6\}" *.rec | sort | uniq




        # prints out the total number of students taking either 1 or both of the courses. Students taking both classes
        # will only be registered as 1 student
        elif test "$command" = "sc" ; then
            printf "There are `grep -oh "[0-9]\{6\}" *.rec | sort | uniq | wc -l ` registered students in all courses.\n"




        # prints out the total number of course files
        elif test "$command" = "cc" ; then
            printf "There are `find "$1" -type f  -name "*.rec" | wc -l` course files. \n"




        # prints out the list of commands that can be used and info about them
        elif test "$command" = "h" || test "$command" = "help" ; then
            printf "$listOfComm"




        # exit when command is quit OR q
        elif test "$command" = "$q" || test "$command" = "q"; then
            printf "goodbye \n"
            exit 0



        #if command is not either q OR quit OR l OR list, then print this out
        else
            printf "Unrecognized command! \n"
        fi
        #the code above executes and ends and loops/prints again the command; saves the input to a variable $inp
        printf "$inp"
        read command
    done




# if the path $1 does not have a .rec file, exit
else
    printf "There is no readable *.rec file that exists in the specified path or its subdirectories \n"
    exit 1
fi




