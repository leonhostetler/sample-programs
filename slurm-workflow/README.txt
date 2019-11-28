When working with a batch job scheduler such as SLURM, it is helpful to set up a workflow of shell scripts. Consider the following example (from a CMSE822 homework):

Suppose you have an MPI application "bucket_sort_v3.c" that you run with a command like
     srun -n <# processes> ./bucket_sort_v3.x <N>

The cluster architecture it runs on contains nodes each supporting up to 28 processes, and you want to test the runtime of the application using (14, 28, 42, 56, 70, 84, 98, 112, 126, 140) processes each at three different values of N (100 million, 500 million, 2 billion). Furthermore, you want each data point to be the average of 5 runs. This requires you to run your application a total of 10*3*5=150 times.

#############################################

With the included shell scripts, you can complete all 150 runs and gather the data into a table by issuing several shell commands, waiting the half hour or so it takes for all jobs to complete, and finishing with another shell command to gather the data.

    1) Create two directories: /output_v3/ and /job_scripts/ and compile your application and name the executable "bucket_sort_v3.x" (without the quotation marks).

    2) Create the batch scripts by running:
          sh generate_job_scripts_v3.sh

    3) Submit all batch scripts by running:
          sh submit_jobs.sh

    4) Wait until all submitted jobs have completed. Check via a command like
          squeue --user <username>
       or simply:
          sq
       Once the jobs start running, they will output log files with names like slurm-50584516.out. To check in on all of these log files at once, use a command like
          tail slurm*
       This command displays the last few lines in each log file. If none of the log files contain output, that is good. Occasionally, you will see messages that are no cause for worry. However, if you see segfaults, something is wrong with your program (or maybe you did not request sufficient memory). You can cancel running or pending jobs using the command:
          scancel <job_id>

    5) Gather all your data into a file "data_v3.txt" by running:
        sh gather_data_v3.sh
       WARNING: You will have to edit this script. See the description below.

    6) Analyze the data in data_v3.txt manually, or better yet, write a python script to import, clean, sort, manipulate, and output your final numbers.

#############################################

Descriptions:

    - generate_single_job_script_v3.sh: This script generates three job scripts (each containing a batch of 5 runs for one combination of processes and N) and puts them in the /job_scripts/ directory. Each run will output its data to /output_v3/. NOTE: Adjust the requested wall times and memory as needed for your application.

    - generate_job_scripts_v3.sh: This script generates 30 job scripts (each containing 5 srun runs) by repeatedly calling generate_single_job_script_v3.sh. 

    - submit_jobs.sh: Loops through every file in the directory /job_scripts/ and submits it as a batch job.

    - gather_data_v3.sh: This script grabs each output file in /output_v3/, extracts the interesting data, and puts it in a nice space delimited table in data_v3.txt. WARNING: This script will not work for you because it requires that your application bucket_sort_v3.x outputs its timing information in a very specific format. However, it should be fairly easy to edit for your needs. For example, the line "gen="$(awk '{if(NR==8) print $4}' $file)"" tells it to extract the 4th "word" from the 8th line in the file. In my application's output, the 4th word in the 8th line is the "generation time". 











