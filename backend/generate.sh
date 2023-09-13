#!/bin/bash

usage() { echo "Usage: $0 [insert filename]"; exit 1; }

# Default flag value
singleton=false

while getopts "s" opt; do
  case $opt in
    s)
      # code to handle -f flag
      singleton=true
      ;;
    \?)
      echo "Usage: $0 [-s] <filename>"
      exit 1
      ;;
  esac
done

# Shift the options and arguments so that $1 refers to the filename
shift $((OPTIND-1))

if [[ "$1" == "" ]]; then
	usage
fi

# Get random uuid
RANDOM_UUID=$(cat /proc/sys/kernel/random/uuid)
# Replace dashes "-" in uuid to "_"
UUID=$(echo "$RANDOM_UUID" | tr - _)
# Get macro from input with underscore before capital letter
MACRO=$(echo $1 | sed 's/[A-Z]\+/_&/g')
# Caps the macro and append _H
ALLCAPSMACRO="_${MACRO^^}_H"
# Capitalize first letter of input
CLASS_NAME="${1^}"

# Create .h and .cpp file
touch $1.h
touch $1.cpp

# Print ifndef and define
printf "#ifndef ${ALLCAPSMACRO}_${UUID}_\n#define ${ALLCAPSMACRO}_${UUID}_\n\n" >> $1.h

if [ "$singleton" = false ]; then
	# Create class, constructor and destructor.
	printf "class $CLASS_NAME {\nprivate:\n\npublic:\n\t$CLASS_NAME();\n\tvirtual ~$CLASS_NAME();\n};\n\n" >> $1.h
else
	# Create singleton private constructors, destructor, and getInstance()
	printf "class $CLASS_NAME {\nprivate:\n" >> $1.h
	printf "\t$CLASS_NAME();\n" >> $1.h
	printf "\tvirtual ~$CLASS_NAME();\n\n" >> $1.h
	printf "\t$CLASS_NAME($CLASS_NAME const&) = delete; // private copy constructor\n" >> $1.h
	printf "\t$CLASS_NAME& operator=($CLASS_NAME const&) = delete; // private assignment operator\n\n" >> $1.h
	printf "public:\n\tstatic $CLASS_NAME& getInstance();\n};\n\n" >> $1.h
fi

# Print endif
printf "#endif\n" >> $1.h

# Include .h file
printf "#include \"$1.h\"\n\n" >> $1.cpp

#########
# Add any other includes of your liking
# printf "#include <iostream>\n" >> $1.cpp # Include iostream
printf "#include \"./src/utils/debugUtils.h\"\n" >> $1.cpp # Include funny.h
#########

# Newline
printf "\n" >> $1.cpp
# Add constructor and destructor empty definition
printf "$CLASS_NAME::$CLASS_NAME() {}\n\n$CLASS_NAME::~$CLASS_NAME() {}\n" >> $1.cpp

# Add getInstance() implementation for singleton
if [ "$singleton" = true ]; then
	printf "\n$CLASS_NAME& $CLASS_NAME::getInstance() {\n" >> $1.cpp
	printf "\tstatic $CLASS_NAME instance;\n\treturn instance;\n}\n" >> $1.cpp
fi