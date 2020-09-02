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
has_rec() {
    if test ! -e "$1" ; then
        printf "There is no *.rec file that exists in the specified path or its subdirectories \n"
        exit 1
    fi
}


readable_file () {
    if test -r "$file"; then
        #checks if the file is readable in user, group and other
        printf "$inp"
        read command #prints command; saves the input to variable $inp
    # if the path $1 does not have a .rec file, exit
    else
        printf "There is no readable *.rec file that exists in the specified path or its subdirectories \n"
        exit 1
    fi
}


other_comm () {

    has_rec



    file=`find "$1" -type f -perm /444 -name "*.rec"`
    # while true, continue running this loop until q OR quit exit/end this loop
    while test true; do
        # prints out the list of files that ends with .rec and are readable by inputing the command l OR list
        if test "$command" = "$l" || test "$command" = "l"; then
            printf "Here is the list of found class files: \n"
            find "$1" -type f -name "*.rec"
        elif test "$command" = "ci" ; then
            printf "Found courses are: \n `grep -o "[ ][A-Z][a-z]*[ ][A-Z][a-z]*" *.rec | grep -o "[A-Z][a-z]*[ ][A-Z][a-z]*"` has `grep CREDITS *.rec | grep -o "[0-9]*"` credits. \n"
        elif test "$command" = "sl" ; then
            grep -o "[0-9]\{6\}" *.rec
        elif test "$command" = "sc" ; then
            printf "There are `grep -oc "[0-9]\{6\}" *.rec` registered students in all courses.\n"
        elif test "$command" = "cc" ; then
            printf "There are `grep -oc COURSE *.rec` course files.\n"
        elif test "$command" = "h" || test "$command" = "help" ; then
            printf "$listOfComm"
        # exit when command is quit OR q
        elif test "$command" = "$q" || test "$command" = "q"; then
            printf "goodbye \n"
            exit 0
        else
            #if command is not either q OR quit OR l OR list, then print this out
            printf "Unrecognized command! \n"
        fi
        #the code above executes and ends and loops/prints again the command; saves the input to a variable $inp
        printf "$inp"
        read command
    done

}

readable_file

other_comm

