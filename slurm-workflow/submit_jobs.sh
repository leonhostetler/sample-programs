#!/bin/bash

# This script submits all the job scripts in the directory job_scripts

# USAGE: sh submit_jobs.sh

# After all batch jobs have completed, gather the output into readable
# tables using the script gather_data.sh

# Leon Hostetler, Nov. 23, 2019

for job in job_scripts/*
do
    sbatch $job
done
