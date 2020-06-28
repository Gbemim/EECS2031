#!/bin/sh

# Gbemisola Akerele 216167041


# $1: the path

inp="command: "
l="list"
q="quit"

# In accordance to the prof lecture notes, -e means if the file exist it should return true and my code
# clearly states if the files does not exist, return the appropriate output.
# checks if the path $1 has a .rec file
if test ! -e "$1" ; then
    printf "There is no *.rec file that exists in the specified path or its subdirectories \n"
    exit 1
fi


file=`find "$1" -type f -perm /444 -name "*.rec"`
if test -r "$file"; then
    #checks if the file is readable in user, group and other
    printf "$inp"
    read command #prints command; saves the input to variable $inp

    # while true, continue running this loop until q OR quit exit/end this loop
    while test true; do
        # prints out the list of files that ends with .rec and are readable by inputing the command l OR list
        if test "$command" = "$l" || test "$command" = "l"; then
            printf "Here is the list of found class files: \n"
            find "$1" -type f -name "*.rec"
        # exit when command is quit OR q
        elif test "$command" = "$q" || test "$command" = "q"; then
            exit 0
        else
        #if command is not either q OR quit OR l OR list, then print this out
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




