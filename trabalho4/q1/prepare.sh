#!/bin/sh

# This script should be runned in current shell, to follow variables be avaliable.
# To this, use . or source:
# source ./prepare.sh /dev/sda7 /wener/workspaces/fso/trabalho4/q1/image_test.jpg


# Gives permission to run debugfs
chmod +x prog

# Use df -h to see what disk your current filesystem
# If your file is in home, so search your home disk.
export DIR_DISK=$1

# Should be used from the root of file system passed as the first parameter, example:
# You have passed /dev/sda2 that is your home
# Suppose, that inside your home, you have two users wener and zara
# If your file passed in program is in wener directory, pass
# /wener/workspaces/C/fso/trabalho4/q1/image_test.jpg
export FILE_DIR=$2

echo "Disk is "$DIR_DISK
echo "File directory is "$FILE_DIR
