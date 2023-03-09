#!/bin/bash

usage() { echo "Usage: $0 [insert filename]"; exit 1; }

if [[ "$1" == "" ]]; then
	usage
fi

# Get random uuid
RANDOM_UUID=$(cat /proc/sys/kernel/random/uuid)
# Replace dashes "-" in uuid to "_"
UUID=$(echo "$RANDOM_UUID" | tr - _)
# Get macro from input
MACRO=$(echo $1 | sed 's/[A-Z]\+/_&/g')
# Caps the macro
ALLCAPSMACRO="${MACRO^^}_H"
# Capitalize first letter of input
CLASS_NAME="${1^}"

# Create .h and .cpp file
touch $1.h
touch $1.cpp

# Print ifndef and define
printf "#ifndef ${ALLCAPSMACRO}_${UUID}\n#define ${ALLCAPSMACRO}_${UUID}\n\n" >> $1.h
# Create class, constructor and destructor.
printf "class $CLASS_NAME {\n\tpublic:\n\t\t$CLASS_NAME();\n\t\tvirtual ~$CLASS_NAME();\n};\n\n" >> $1.h
# Print endif
printf "#endif\n" >> $1.h

# Include iostream
printf "#include <iostream>\n" >> $1.cpp
# Include .h file
printf "#include \"$1.h\"\n" >> $1.cpp
# Include funny.h
printf "#include \"utils/funny.h\"\n" >> $1.cpp
# Newline
printf "\n" >> $1.cpp
# Add constructor and destructor empty definition
printf "$CLASS_NAME::$CLASS_NAME() {}\n\n$CLASS_NAME::~$CLASS_NAME() {}\n" >> $1.cpp
