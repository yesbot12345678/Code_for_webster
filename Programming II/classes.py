class student: #creating the class
    def __init__(self, first, last , studentID, gradelevel): #method to create atributes
        self.first = first #first name
        self.last = last #last name
        self.studentID = studentID #student ID
        self.gradelevel = gradelevel #grade level
    def display(self): #method to display the atributes
        print("First Name:", self.first) #first name
        print("Last Name:", self.last) #last name
        print("Student ID:", self.studentID) #student ID
        print("Grade Level:", self.gradelevel) #grade level

student1 = student("John", "Doe", "1234", 11) #creating student 1
student2 = student("Jane", "Smith", "6789", 12) #creating student 2

# outputting students
print(student1.display())
print(student2.display())

