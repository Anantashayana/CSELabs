#Write a program to create the csv file for storing Employee data, containing the fields 

#(Emp ID, Emp Name, DOJ, Dept, Desig.)

#Read the suitable number of employee details from the user.
#Create a data frame of Employee.
#Store the data frame in the csv file.
#Read the data from csv and display the contents.
#Append a new row into the csv file.



n <- as.integer(readline(prompt = "Enter no of Employee"))
EmpId <- vector(mode="character", length= n)
EmpName <- vector(mode="character", length= n)
DOJ <- vector(mode="character", length= n)
EmpCode <- vector(mode="numeric",length = n)
Desig <- vector(mode="character",length = n)
Dept <- vector(mode="character",length = n)


print("Enter EmpId")
for (i in 1:n)
  EmpId[i] <- as.character(readline())
print("Enter EmployeeName")
for (i in 1:n)
  EmpName [i] <- readline()
print("Enter DOJ" )
for (i in 1:n)
  DOJ[i] <- (readline())
print("Enter EmployeeCode" )
for (i in 1:n)
  EmpCode[i] <- as.integer(readline())
print("Enter Designation" )
for (i in 1:n)
  Desig[i] <- (readline())
print("Enter Dept" )
for (i in 1:n)
  Dept[i] <- (readline())

Emp <- data.frame(EmpId,EmpName,EmpCode,Desig,Dept,DOJ)
print("The Employee detials are as follows")
print(Emp)


write.csv(Emp,"./Employee.csv")

readStudent=read.csv("./Employee.csv")

print("Enter a new row")
u<- readline(prompt = "EmpId")
n<- readline(prompt = "EmpName")
m<- readline(prompt = "EmpCode")
A<- readline(prompt = "Desig")
s<- readline(prompt = "Dept")
t<- readline(prompt = "DOJ")
x<- data.frame(u,n,m,A,s,t)



write.table(x,"./Employee.csv",col.names = FALSE, append = T,row.names= T, quote= FALSE, sep = ",")
readStudent=read.csv("./Employee.csv")
print(readStudent)

