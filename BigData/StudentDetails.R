#a. Create three different variables, one that is numeric type and other two are vector of characters. Use these to create data frame of student. (USN, Name, Marks)

#b. Add a new numeric data column to the existing data frame (Age). Provide summary of the data

#c.   Display the list of students whose Age is less than 20 and Marks greater than 25.

n <- as.integer(readline(prompt = "Enter no of students"))

USN <- vector(mode="character", length= n) 
Name <- vector(mode="character", length= n)
Marks <- vector(mode="numeric", length= n)

print("Enter USN")
for (i in 1:n)
  USN[i] <- as.character(readline())
print("Enter Name")
for (i in 1:n)
  Name [i] <- as.character(readline())
print("Enter Marks" )
for (i in 1:n)
  Marks[i] <- as.integer(readline())


student <- data.frame(USN,Name,Marks)
print("The Student detials are as follows") 
print(student)

print("Enter Age")
Age <- vector(mode="integer", length=n)
for (i in 1:n)
  Age [i] <- as.integer(readline())
student <- cbind(student,Age)
print(student)

for(i in 1:n)
  if (student[i,][3] > 25 )
    if (student[i,][4] > 20)
      print(student[i,])
