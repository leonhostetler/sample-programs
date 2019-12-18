#!/bin/bash

# Try running this script with the command
#    sh bash-test.sh

# If it doesn't work, try running it with the command
#    bash bash-test.sh


echo $(bash --version)
echo


echo "Testing brace expansion. This should be followed by the numbers 1 to 10--one on each line:"
for i in {1..10}
do 
   echo $i
done

echo
echo "Testing string comparison:"
if [[ "Hello" == "Hello" ]];
then
    echo "Successful string comparison"
else
    echo "String comparison was not successful!"
fi







