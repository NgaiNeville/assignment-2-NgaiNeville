#!/bin/bash


if [ $# -ne 2 ];
then
	echo "Error: Insert two arguments: files-directory(/tmp/aesd/assignment1) and search-string(linux)"
	exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ] 
then
	echo "Error: $filesdir is not a valid file directory"
	exit 1
fi

x=$(find "$filesdir" -type f | wc -l)

y=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "we have found $x files and $y matching linese"
