#!/bin/bash

if [ $# -ne 2 ]
then
	echo "Error: Insert two arguments: file-directory and string"
	exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"

if echo "$writestr" > "$writefile";
then
	exit 0
else
	echo "Error: unable to create the file $writefile"
	exit 1
fi
