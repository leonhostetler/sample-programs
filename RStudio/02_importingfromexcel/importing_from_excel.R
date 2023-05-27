
# See video:
# https://www.youtube.com/watch?v=q66Gk-DPBh4

# Excel data needs to be saved in CSV format

# Read data in using the read.csv() function
# Does not work to do it like the following even if the CSV file is in 
# the same directory as the R script
my_data = read.csv("sample_data.csv")
# Need to use the full path to the file instead like follows:
my_data = read.csv("/home/hostetler/Dropbox/misc/programs/github_sample-programs/RStudio/02_importingfromexcel/sample_data.csv")

# Can also use the 'sep' option to specify separators other than commas





