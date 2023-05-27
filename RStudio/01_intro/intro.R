
# Watch intro videos like:
# https://www.youtube.com/watch?v=FIrsOBy5k58
# https://www.youtube.com/watch?v=BvKETZ6kr9Q


# Use CTRL+ENTER to run a line of code


# Basic calculator stuff
1+2
3*5
abs(-5)
log(100)
log10(100)

# Assign variables...two different ways
a = 3
b <- 4

# R is case sensitive
A = 5

# R has three basic datatypes: numeric, character, and logical
my_numeric_value = 3.2
my_logical_value = F
my_char_value = "giggity giggity goo"

# Plus one special datatype: category/factor
my_factor_value = as.factor("Male")

# Can make vectors
vector1 = c(1,2,3)
vector2 = c(6,7,8)
vector3 = vector1 + vector2

# Accessing elements of vectors
vector1[1]
vector1[2]
vector1[2:3]

# Can specify a range of numbers
1:100

# Save the numbers 1 to 100 as a vector
x<-1:100

# Print x
print(x)

# Can make lists, which can store data of different types
mylist = list(1,2,3,"hello")

# Data frames are essentially a list of vectors of equal lengths
mydf = data.frame(vector1,vector2)

# Get the first column of the data frame
mydf[[1]]
mydf$vector1

# Get the second row of the data frame
mydf[2,]

# Defining a function
my_sum_function = function(value1, value2){
  result = value1 + value2
  return(result)
}

# Using the function
my_sum_function(10,20)

