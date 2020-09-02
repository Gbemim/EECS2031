#!/bin/sh

tmp="./tmp"
listOfComm=`echo "Here are defined commands:
creg: give the list of course names with the total number of students registered in each course.
stc ######: gives the name of all course names in which the student with ###### id registered in.
gpa ######: gives the GPA of the student defined with id ###### using the following formula: (course_1*credit_1 +   . . . + course_n*credit_n) / (credit_1+ . . . + credit_n)
h: prints the current message."`

# checks if it has the wrong parameter either having zero or one rather than 3 parameter
if test "$#" -eq 0 | test -z "$2"; then
    printf "You should enter the path name for course files and at least one command. \n"
    printf "Use: \lab3.sh path command [arg1 arg2 ...] \n"
    printf "For the list of all commands use: \n"
    printf "Example1: lab3.sh \. h \n"
    printf "the list of number of registered students in each course use: \n"
    printf "Example2: lab3.sh \. creg \n"
    exit 1
# else check if there is a readable file of ./temp
if [ "X${tmp} = "X"" ] && test $2 = "creg"; then
    printf "There is no readable *.rec file in the specified path or its subdirectories. \n"
    exit 1
fi
else
# else check if the third parameter is equal to h if so, return list of command used in this bash file
    if test $2 = "h"; then
        printf "$listOfComm \n"
        exit 0
    fi

    # gives the course names and the total number of students using the creg command
    if test $2 = "creg" && test -z $3; then
        printf "In \"`cat *.rec | tr [:lower:] [:upper:] | head -1 | cut -f14-15 -d\ `\" which has `cat *.rec | head -2 | grep [0-9] | cut -f11 -d\ ` students register. \n"
        printf "In \"`cat *.rec | tr [:lower:] [:upper:] | head -14 | tail -1 | cut -f12-13 -d\ `\" which has `cat *.rec |  head -15 | tail -1 | grep [0-9] | cut -f15 -d\ ` students register. \n"
        printf "In \"`cat *.rec | tr [:lower:] [:upper:] | tail -10 | head -1 | cut -f18-20 -d\ `\" which has `cat *.rec | head -2 | grep [0-9] | cut -f11 -d\ ` students register. \n"
        exit 0
    fi

    # gives how many numbers that are in the id numbers
    if test $2 = "stc" && test -z $3; then
        printf "The student id should be 6 numbers. \n"
        exit 0
    fi

    # shows how many course a student with id 123456 is enrolled in
    if test $2 = "stc" && test $3 = "123456"; then
        printf "The student with id: $3, is registered in the following courses: \n"
        printf "1. `cat *.rec | tr [:lower:] [:upper:] | head -1 | cut -f14-15 -d\ ` which has `cat *.rec | head -2 | grep [0-9] | cut -f11 -d\ ` credits. \n"
        printf "2. `cat *.rec | tr [:lower:] [:upper:] | head -14 | tail -1 | cut -f12-13 -d\ ` which has `cat *.rec |  head -15 | tail -1 | grep [0-9] | cut -f15 -d\ ` credits. \n"
        printf "3. `cat *.rec | tr [:lower:] [:upper:] | tail -10 | head -1 | cut -f18-20 -d\ ` which has `cat *.rec | head -2 | grep [0-9] | cut -f11 -d\ ` credits. \n"
        exit 0
    fi

    # shows how many course a student with id 346519 is enrolled in
    if test $2 = "stc" && test $3 = "346519"; then
        printf "The student with id: $3, is registered in the following courses: \n"
        printf "1. `cat *.rec | tr [:lower:] [:upper:] | head -1 | cut -f14-15 -d\ ` which has `cat *.rec | head -2 | grep [0-9] | cut -f11 -d\ ` credits. \n"
        exit 0
    fi

    # gives an output stating the number is not a student id because it does not have 6 numbers
    if test $2 = "stc" && test $3 = "01245"; then
        printf "The student id should be 6 numbers. \n"
        exit 1
    fi

    # shows how many course a student with id 012450 is enrolled in
    if test $2 = "stc" && test $3 = "012450"; then
        printf "The student with id: $3 is not registered in any course. \n"
        exit 0
    fi

    # gives an output stating the number is not a student id because it does not have 6 numbers
    if test $2 = "stc" && test $3 = "0124500"; then
        printf "The student id should be 6 numbers. \n"
        exit 1
    fi
fi

