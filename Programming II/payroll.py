#base employee class
class employee:
    pay_raise = 1.01
    def __init__(self, first_name, last_name, emp_id, yearly_pay = 10):
        self.first_name = first_name
        self.last_name = last_name
        self.emp_id = emp_id
        self.yearly_pay = yearly_pay
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


print(develper1.pay_raise)
print(manager1.pay_raise)
print(help(develper))