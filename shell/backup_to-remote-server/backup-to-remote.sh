#!/bin/bash

# 
# backup-to-remote.sh
# 
# A simple backup script to manually backup everything in the current directory to a remote server.
# 
# Leon Hostetler, June 9, 2018
#
# USAGE: sh backup-to-remote.sh
#

# Get the current date and time
today=`date +%Y-%m-%d_%H-%M-%S`

# Tar and compress the current directory
# If you want to backup something other than the current directory, replace the final '.' with the directory to backup
echo '\nTarring backup directory'
tar -zcvf 'backup_'$today.tgz .

# Upload it to remote server (replace with your password, username, remote server address, and backup directory)
echo "Uploading to remote server..."
sshpass -p 'password' scp 'backup_'$today.tgz user@remoteserveraddress:~/backupdirectory

# Clean up
rm -r 'backup_'$today.tgz
echo "All done"
