#base employee class
class employee:
    pay = 10
    def __init__(self, first_name, last_name, emp_id):
        self.first_name = first_name
        self.last_name = last_name
        self.emp_id = emp_id
#developer class
class develper(employee):
    pay = 100
#manager class
class manager(employee):
    pay = 1000
#creating employee, developer and manager objects
epm1 = employee("John", "Doe", 123, )
develper1 = develper("Jane", "Smith", 456)
mannager1 = manager("Bob", "Johnson", 789)

print(help(develper))