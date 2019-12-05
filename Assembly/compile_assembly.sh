#!/bin/bash

file_name=$1

nasm -f elf64 $file_name
