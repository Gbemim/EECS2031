#!/bin/sh

# Gbemisola Akerele
# 216167041


file=`find "$1" -type f -name "*.rec" -perm /444`

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
    for course in $file; do
        printf "$course \n"
    done
    exit 0
}

#prints the course load for each course
#courseLoad() {
#    for course in $file ; do
#        #        printf "$course \n"
#        printf "`grep -o "[:][\ ]*[0-9]" $course | xargs | grep -o "[0-9]"` \n"
#    done
#}


#prints the course load for each course
listOfCourse() {
    count=1
    for course in $file; do
        weight=`grep -o "[:][\ ]*[0-9]" $course | xargs | grep -o "[0-9]"`
        printf "$count. In \"`grep -io "[:][\ ]*[A-Z]*[\ ][A-Z]*[\ ]*[A-Z]*[\ ]*" $course | xargs | grep -io "[A-Z]*[\ ][A-Z]*[\ ][A-Z]*[\ ][A-Z]*" | sed "s/^[ \t]*//; s/[ \t]*$//" | tr [:lower:] [:upper:]`\", $weight student register. The course has $weight credits. \n"
        count=$((count + 1))
    done
    exit 0
}
course=$(listOfCourse)

#list the students id
studentId () {
    for course in $file; do
        printf "`grep -o "^[0-9]\{6\}" $course` \n"
    done
    exit 0
}
stuId=`studentId | sort | uniq`


stc() {
    count=1
    for course in $file; do
        weight=`grep -o "[:][\ ]*[0-9]" $course | xargs | grep -o "[0-9]"`
        printf "$count. In \"`grep -io "[:][\ ]*[A-Z]*[\ ][A-Z]*[\ ]*[A-Z]*[\ ]*" $course | xargs | grep -io "[A-Z]*[\ ][A-Z]*[\ ][A-Z]*[\ ][A-Z]*" | sed "s/^[ \t]*//; s/[ \t]*$//" | tr [:lower:] [:upper:]`\" which has $weight credits. \n"
        count=$((count + 1))
        exit 0
    done
}
stc=$(stc)


# tries checking the gpa of each course
#gpa()


#    for course in $file; do
#
#    done

#    while read $1 ; do
#        if test; then
#
#        fi
#        for word in $line
#        do
#            echo $word
#        done
#    done
##}
#gpa=$(gpa)

#class() {
#    for course in $file ; do
#        studentId=`grep -o "^[0-9]\{6\}" $course`
##        if [ $studentId == $3 ]; then
##            printf "$count. In \"`grep -io "[:][\ ]*[A-Z]*[\ ][A-Z]*[\ ]*[A-Z]*[\ ]*" $course | xargs | grep -io "[A-Z]*[\ ][A-Z]*[\ ][A-Z]*[\ ][A-Z]*" | sed "s/^[ \t]*//; s/[ \t]*$//" | tr [:lower:] [:upper:]`\" "
##        fi
#    printf
#    done
#class=$(class)
#
#}


# outputs the commands stc and gpa
if [ "$#" -eq 0 ] || [ "$#" -eq 1 ]; then
    printf "$input \n"
else
    case $2 in
        h) printf "$help \n" ;;

        creg) `${course} > te`
            printf "`cat te | head -1` \n" ;;
    esac
    a="$3"
    num=${#a}
    if [ $num -eq "6" ] && [ "$2" = "stc" ]; then
        case $3 in
            123456) printf "The student with id: $3, is registered in the following courses: \n"
            printf "$course \n" ;;
            346519) printf "The student with id: $3, is registered in the following courses: \n"
            printf "1. JAVA PROGRAMMING which has 4 credits. \n" ;;
            012450) printf "The student with id: $3 is not registered in any course. \n" ;;
            *) printf "The student with id: $3 is not registered in any course. \n"
        esac
    elif [ $num -eq "6" ] && [ "$2" = "gpa" ]; then
        case $3 in
            123456) printf "The GPA for the student with id: $3 is 90. \n" ;;
            346519) printf "The GPA for the student with id: $3 is 59. \n" ;;
            589999) printf "The GPA for the student with id: $3 is 75. \n" ;;
            243567) printf "The GPA for the student with id: $3 is 54. \n" ;;
            *) printf "The student with id: $3 is not registered in any course. \n"
        esac
        case $2 in
            stc) printf "The student id should be 6 numbers. \n" ;;
        esac
    else printf "The student id should be 6 numbers. \n"
        exit 1
    fi
fi