#!/bin/bash

usage() { echo "Usage: $0 [insert filename]"; exit 1; }

if [[ "$1" == "" ]]; then
	usage
fi

UUID=$(cat /proc/sys/kernel/random/uuid)
MACRO=$(echo $1 | sed 's/[A-Z]\+/_&/g')
ALLCAPSMACRO="${MACRO^^}_H"


touch $1.h
touch $1.cpp

# printf "#pragma once\n\nClass $1 {\n\tpublic:\n\t\t$1();\n\t\tvirtual ~$1();\n}" >> $1.h

printf "#ifndef ${ALLCAPSMACRO}_${UUID}\n#define ${ALLCAPSMACRO}_${UUID}\n\n" >> $1.h
printf "Class $1 {\n\tpublic:\n\t\t$1();\n\t\tvirtual ~$1();\n}\n\n" >> $1.h
printf "#endif\n" >> $1.h

printf "#include <iostream>\n" >> $1.cpp
printf "#include "utils/funny.h"\n" >> $1.cpp
printf "#include \"$1.h\"\n\n$1::$1() {}\n\n$1::~$1() {}\n" >> $1.cpp
