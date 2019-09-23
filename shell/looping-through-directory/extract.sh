#!/bin/bash

# Run the Python program get_max.py on each file of the
# form outputs_*.txt in the current directory.
#
# Leon Hostetler, Sep. 22, 2019
#
# Usage: sh extract.sh

for file in outputs_*.txt; do
    [ -e "$file" ] || continue
    python get_max.py $file
done
