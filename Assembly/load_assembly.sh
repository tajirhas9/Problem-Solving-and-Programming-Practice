#!/bin/bash

file_name=$1
object_file_name="$1.o"

ld -s -o $file_name $object_file_name
