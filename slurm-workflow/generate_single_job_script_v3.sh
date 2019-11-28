
# This script generates three job scripts (each containing a batch of jobs)
# It takes the number of nodes and processes from the command line and outputs
# the job scripts to the directory job_scripts

# USAGE: This script is called by generate_job_scripts_v3.sh

# Leon Hostetler, Nov. 26, 2019

# Get number of nodes and processes from the command line
nodes=$1
nproc=$2

out_dir="job_scripts"

out_file1="job_v3_"$nodes"n_"$nproc"p_100M.sb"
out_file2="job_v3_"$nodes"n_"$nproc"p_500M.sb"
out_file3="job_v3_"$nodes"n_"$nproc"p_2B.sb"

echo "#!/bin/bash --login
########## SBATCH Lines for Resource Request ##########

#SBATCH --time=00:10:00
#SBATCH --constraint=lac
#SBATCH --nodes=$nodes
#SBATCH --ntasks=$nproc
#SBATCH --mem=20G

########## Command Lines to Run ##########

module purge
module load GCC/6.4.0-2.28 OpenMPI  ### load necessary modules, e.g.

cd \${PBS_O_WORKDIR}                 ### change to working directory

########## Run the scripts  ##############

out_dir=\"output_v3\"

for i in {1,2,3,4,5}
do
  srun -n $nproc ./bucket_sort_v3.x 100000000 > \$out_dir/\""$nodes"_"$nproc"_100M_\"\$i\"_.dat\"
done" >> $out_dir/$out_file1

###############################################

echo "#!/bin/bash --login
########## SBATCH Lines for Resource Request ##########

#SBATCH --time=00:15:00
#SBATCH --constraint=lac
#SBATCH --nodes=$nodes
#SBATCH --ntasks=$nproc
#SBATCH --mem=30G

########## Command Lines to Run ##########

module purge
module load GCC/6.4.0-2.28 OpenMPI  ### load necessary modules, e.g.

cd \${PBS_O_WORKDIR}                 ### change to working directory

########## Run the scripts  ##############

out_dir=\"output_v3\"

for i in {1,2,3,4,5}
do
  srun -n $nproc ./bucket_sort_v3.x 500000000 > \$out_dir/\""$nodes"_"$nproc"_500M_\"\$i\"_.dat\"
done" >> $out_dir/$out_file2

###############################################

echo "#!/bin/bash --login
########## SBATCH Lines for Resource Request ##########

#SBATCH --time=00:15:00
#SBATCH --constraint=lac
#SBATCH --nodes=$nodes
#SBATCH --ntasks=$nproc
#SBATCH --mem=120G

########## Command Lines to Run ##########

module purge
module load GCC/6.4.0-2.28 OpenMPI  ### load necessary modules, e.g.

cd \${PBS_O_WORKDIR}                 ### change to working directory

########## Run the scripts  ##############

out_dir=\"output_v3\"

for i in {1,2,3,4,5}
do
  srun -n $nproc ./bucket_sort_v3.x 2000000000 > \$out_dir/\""$nodes"_"$nproc"_2B_\"\$i\"_.dat\"
done" >> $out_dir/$out_file3

###############################################
