class student: #creating the class

    default_gradelevel = 9

    def __init__(self, first_name, last_name, student_ID): #method to create atributes
        self.first_name = first_name #first name
        self.last_name = last_name #last name
        self.student_ID = student_ID #student ID

    def display(self): #method to display the atributes
        print("First Name:", self.first_name) #first name
        print("Last Name:", self.last_name) #last name
        print("Student ID:", self.student_ID) #student ID
        print("Grade Level:", self.default_gradelevel) #grade level


student1 = student("John", "Doe", "1234") #creating student 1
student2 = student("Jane", "Smith", "6789") #creating student 2

student1.display() #displaying student 1's information
student2.display() #displaying student 2's information

student1.default_gradelevel = 10 #changing the default grade level for student 1
print(student1.__dict__)
print(student2.__dict__)
print(student1.display()) #displaying student 1's information
print(student2.display()) #displaying student 1's information

student.default_gradelevel = 11 #changing the default grade level for all students
print(student1.display()) #displaying student 1's information
print(student2.display()) #displaying student 1's information

# i have used class variables to set a default grade level for all students. 
# When I change the default grade level for student 1, 
# it only changes for that instance and not for student 2. 
# However, when I change the default grade level for the class, 
# it changes for all instances of the class that have not overridden the class variable.