#!/bin/sh

# Gbemisola Akerele 216167041


# $1: the path
inp="command: "
l="list"
q="quit"
listOfComm=`echo "l or list: lists found courses
ci: gives the name of all courses plus number of credits
sl: gives a unique list of all students registered in all courses
sc: gives the total number of unique students registered in all courses
cc: gives the total numbers of found course files.
h or help: prints the current message.
q or quit: exits from the script"`

# checks if the path $1 has a .rec file
#has_rec() {
    if test ! -e "$1" ; then
        printf "There is no *.rec file that exists in the specified path or its subdirectories \n"
        exit 1
    fi
#}
#has_rec

file=`find "$1" -type f  -name "*.rec" -perm /444`
if [ "X${file} = "X"" ] ; then
    #checks if the file is readable in user, group and other
    printf "$inp"
    read command #prints command; saves the input to variable $inp

    while true; do
        case $command in
            list | l) printf "Here is the list of found class files: \n"
            find "$1" -type f -name "*.rec";;

            ci) printf "Found courses are: \n`cut -f3-4 -d\  *.rec | head -1` has `cut -f3-4 -d\  *.rec | head -2 | grep [0-9]` credits. \n"
            printf "`cut -f3-4 -d\  *.rec | tail -4 | head -1` has `cut -f3-4 -d\  *.rec | tail -3 | grep [0-9]` credits. \n" ;;

            sl) printf "Here is the unique list of student numbers in all courses: \n"
            grep -oh "[0-9]\{6\}" *.rec | sort | uniq ;;

            sc) printf "There are `grep -oh "[0-9]\{6\}" *.rec | sort | uniq | wc -l ` registered students in all courses.\n" ;;

            cc) printf "There are `find "$1" -type f  -name "*.rec" | wc -l` course files. \n" ;;

            help | h)  printf "$listOfComm \n";;

            quit | q)  printf "goodbye \n"
            exit 0;;

            *) printf "Unrecognized command! \n";;
        esac
            #the code above executes and ends and loops/prints again the command; saves the input to a variable $inp
            printf "$inp"
            read command
    done
# if the path $1 does not have a .rec file, exit
    else
        printf "There is no readable *.rec file that exists in the specified path or its subdirectories \n"
        exit 1
fi




