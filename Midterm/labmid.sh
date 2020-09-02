#!/bin/sh

file=`find "$1" -type f  -name "*.rec" -perm /444`

input=`printf "You should enter the path name for course files and at least one command.
Use: lab3.sh path command [arg1 arg2 ...]
For the list of all commands use:
Example1: lab3.sh . h
For the list of number of registered students in each course use:
Example2: lab3.sh . creg"`

help=`printf "Here are defined commands:
creg: give the list of course names with the total number of students registered in each course.
stc ######: gives the name of all course names in which the student with ###### id registered in.
gpa ######: gives the GPA of the student defined with id ###### using the following formula: (course_1*credit_1 +   . . . + course_n*credit_n) / (credit_1+ . . . + credit_n)
h: prints the current message."`

#lists the courses
listFiles() {
    for course in $file ; do
        printf "$course \n"
    done
}

#prints the course load for each course
courseLoad() {
    for course in $file ; do
        #        printf "$course \n"
        printf "`grep -o "[:][\ ]*[0-9]" $course | xargs | grep -o "[0-9]"` \n"
    done
}

listOfCourse() {
    for course in $file; do
        weight=`grep -o "[:][\ ]*[0-9]" $course | xargs | grep -o "[0-9]"`
        printf "In \"`grep -io "[:][\ ]*[A-Z]*[\ ][A-Z]*[\ ]*[A-Z]*[\ ]*" $course | xargs | grep -io "[A-Z]*[\ ][A-Z]*[\ ][A-Z]*[\ ][A-Z]*" | sed "s/^[ \t]*//; s/[ \t]*$//" | tr [:lower:] [:upper:]`\" which has $weight register. \n"
    done
}
course=$(listOfCourse)


studentId () {
    for course in $file; do
        printf "`grep -o "^[0-9]\{6\}" $course` \n"
    done
}
stuId=`studentId | sort | uniq`






six=`$3 | wc -l`
sixNum () {
    if [ $six -ne "6" ]; then
        printf "The student id should be 6 numbers. \n"
    fi
}

#stc() {
#    if [ ! ${#2} = 6 ]; then
#        echo "Try af"
#    exit 1
#    fi
#}








if [ "$#" -eq 0 ] || [ "$#" -eq 1 ] ; then
   printf "$input \n"
#elif [ "X${file} = "X"" ] ; then
#    printf "There is no readable *.rec file in the specified path or its subdirectories. \n"
else
    case $2 in
        h ) printf "$help \n" ;;

        creg ) printf "$course \n"  ;;

        stc ) stc ;;
    esac

#    six=`printf $3 | wc -m`
    if [ ! ${#2} = 6 ]; then
        echo "Try af"
        exit 1

#    else
#        case $3 in
#            123456 ) printf ". \n"
#        esac

    fi

























fi
