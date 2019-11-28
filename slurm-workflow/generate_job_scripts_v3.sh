
# This script generates all the job scripts and places them in the
# job_scripts directory

# USAGE: sh generate_job_scripts_v3.sh

# After all job scripts have been generated, submit them via SLURM
# by running the submit_jobs.sh script

# Leon Hostetler, Nov. 26, 2019


# Clean out job_scripts directory
rm job_scripts/*

# Create all job scripts
for nodes in {1,2,3,4,5}
do
    let p2="(2*$nodes-1)*14"
    sh generate_single_job_script_v3.sh $nodes $p2

    let p="$nodes * 28"
    sh generate_single_job_script_v3.sh $nodes $p
done



