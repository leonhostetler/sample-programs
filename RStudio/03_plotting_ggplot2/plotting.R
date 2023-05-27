# See the video
# https://www.youtube.com/watch?v=HPJn1CMvtmI




# Import sample data
my_data = read.csv("/home/leon/Dropbox/misc/programs/github_sample-programs/RStudio/03_plotting_ggplot2/sample_data.csv")

library(ggplot2)

# Basic scatter plot
ggplot(data = my_data,
       mapping = aes(x = column1,
                     y = column2))+
  geom_point()


# Basic plot with connected lines
ggplot(data = my_data,
       mapping = aes(x = column1,
                     y = column2))+
  geom_point(size=2)+
  geom_line(color="red")

# Create a smooth line from the points
ggplot(my_data,aes(column1,column2))+
  geom_point(size=2)+
  geom_smooth()

# Linear fit
ggplot(my_data,aes(column1,column2))+
  geom_point(size=2)+
  geom_smooth(method=lm)

# Linear fit, no error band, with labels
ggplot(my_data,aes(column1,column2))+
  geom_point(size=2)+
  geom_smooth(method=lm, se=F)+
  xlab("x")+
  ylab("y")+ 
  labs(title="My Fancy Plot")

# Boxplot
ggplot(my_data,aes(column1,column2))+
  geom_boxplot()

# Boxplot + points
ggplot(my_data,aes(column1,column2))+
  geom_boxplot()+
  geom_point()
