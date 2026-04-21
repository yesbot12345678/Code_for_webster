#base employee class
class employee:
    pay_raise = 1.01
    def __init__(self, first_name, last_name, emp_id, yearly_pay = 10):
        self.first_name = first_name
        self.last_name = last_name
        self.emp_id = emp_id
        self.yearly_pay = yearly_pay

    def get_info(self):
        self.first_name = input("Enter employee's first name: ")
        self.last_name = input("Enter employee's last name: ")
        self.emp_id = input("Enter employee's ID: ")
        self.yearly_pay = float(input("Enter employee's yearly pay: "))
        self.yearly_pay = self.yearly_pay * self.pay_raise

    def print_info(self):
        print(f"Employee Name: {self.first_name} {self.last_name}")
        print(f"Employee ID: {self.emp_id}")
        print(f"Yearly Pay: {self.yearly_pay}")
        print(f"Pay Raise: {self.pay_raise}")
        print(f"New Yearly Pay: {self.yearly_pay * self.pay_raise}")

    def give_raise(self):
        self.yearly_pay = self.yearly_pay * self.pay_raise

#developer class
class develper(employee):
    pay_raise = 1.05
    def __init__(self, first_name, last_name, emp_id, yearly_pay = 10):
        super().__init__(first_name, last_name, emp_id, yearly_pay)
        self.yearly_pay = yearly_pay * self.pay_raise
        
#manager class
class manager(employee):
    pay_raise = 1.08
    def __init__(self, first_name, last_name, emp_id, yearly_pay = 10):
        super().__init__(first_name, last_name, emp_id, yearly_pay)
        self.yearly_pay = yearly_pay * self.pay_raise
#creating employee, developer and manager objects

develper1 = develper("Jane", "Smith", 456)
manager1 = manager("Bob", "Johnson", 789)


develper1.print_info()
manager1.print_info()
#print(help(develper))
