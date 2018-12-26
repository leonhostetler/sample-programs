#!/bin/bash

# 
# simple-backup.sh
# 
# A simple backup script to backup everything in the current directory.
#
# Leon Hostetler, June 9, 2018
#
# USAGE: sh simple-backup.sh
#

# Get the current date and time
today=`date +%Y-%m-%d_%H-%M-%S`

# Make a directory named with current date and time
echo '\nMaking directory /'$today
mkdir $today

# Copy files to the directory
echo '\nCopying files'
cp * $today/

# Tar and compress the backup directory
echo '\nTarring backup directory'
tar -zcvf backup_$today.tgz $today/

# Clean up and finish
rm -r $today/
echo "\nbackup.sh: All done"
