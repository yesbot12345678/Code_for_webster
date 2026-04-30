class bank_account: #
#initializes the bank account class with the account holder's name, account number, savings balance, checking balance, previous transactions, and total interest earned
    def __init__(self, full_name, number, date):
        self.full_name = full_name
        self.account_number = number
        self.date = date

#prints the account information for the account holder, including the account holder's name, account number, savings balance, checking balance, total balance for savings and checking, and total interest earned
    def view_account_info(self):
        print(f"Account Holder: {self.full_name}")
        print(f"Account Number: {self.account_number}")
        print(f"Date: {self.date}")
        print("")

class savings_account(bank_account):
    def __init__(self, full_name, number, balance_savings, date):
        super().__init__(full_name, number, date)
        self.balance_savings = balance_savings

    #deposits money into the specified account type (savings or checking) and updates the previous transactions list with the deposit information
    def deposit(self, amount):
            self.balance_savings += amount

#withdraws money from the specified account type (savings or checking) if there are sufficient funds and updates the previous transactions list with the withdrawal information. If there are insufficient funds, it prints an error message.
    def withdraw(self, amount):
            if amount > self.balance_savings:
                print("Insufficient funds in savings account. Please try again.")
            else:
                self.balance_savings -= amount

#prints the total balance for savings   
    def check_balance(self):
        print(f"Total Balance for savings is: ${self.balance_savings:.2f}")

class checking_account(bank_account):
    def __init__(self, full_name, number, balance_checking, date):
        super().__init__(full_name, number, date)
        self.balance_checking = balance_checking

#deposits money into the specified account type (savings or checking) and updates the previous transactions list with the deposit information
    def deposit(self, amount):
            self.balance_checking += amount

#withdraws money from the specified account type (savings or checking) if there are sufficient funds and updates the previous transactions list with the withdrawal information. If there are insufficient funds, it prints an error message.
    def withdraw(self, amount):
            if amount > self.balance_checking:
                print("Insufficient funds in checking account. Please try again.")
            else:
                self.balance_checking -= amount

#prints the total balance for checking
    def check_balance(self):
        print(f"Total Balance for checking is: ${self.balance_checking:.2f}")

class auto_loan_account(bank_account):
    interest_rate = 1.05
    def __init__(self, full_name, number, balance_auto_loan, date = None):
        super().__init__(full_name, number, date)
        self.balance_auto_loan = balance_auto_loan
    def make_payment(self, amount):
        self.balance_auto_loan -= amount
    def check_balance(self):
        print(f"Auto Loan Balance: ${self.balance_auto_loan:.2f}")

account1 = bank_account("John Doe", "123456789", "2024-06-01")
account2 = savings_account("John Doe", "123456789", 1000.00, "2024-06-01")
account3 = checking_account("John Doe", "123456789", 500.00, "2024-06-01")
account4 = auto_loan_account("John Doe", "123456789", 15000.00, "2024-06-01")

x = 1
while x > 0:
#menu
    print("Welcome to the Bank of Python!")
    print("Please select an option:")
    print("1. View account information")
    print("2. Deposit money")
    print("3. Withdraw money")
    print("4. Make auto loan payment")
    print("5. Check balance")
    print("6. Exit")
    print("")

    option = input("Enter your choice: ")
#options for the menu, including viewing account information, depositing money, withdrawing money, checking balance, viewing previous transactions, and exiting the program. Each option prompts the user for the necessary information and calls the appropriate method from the bank_account class to perform the desired action. If an invalid option is selected, it prints an error message and prompts the user to try again.
    if option == "1":
        account1.view_account_info()
#options for depositing money, which prompts the user for the account holder's name, the amount to deposit, and the account type (savings or checking). It then calls the deposit method from the bank_account class to perform the deposit and updates the previous transactions list accordingly. If the account is not found, it prints an error message and prompts the user to try again.
    elif option == "2":
    
            print("enter the amount of monney you want to deposit: ")
            amount = float(input())
            print ("enter the account you want to deposit to: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            if account_type == 1:
                account2.deposit(amount)
            elif account_type == 2:
                account3.deposit(amount)

#options for withdrawing money, which prompts the user for the account holder's name, the amount to withdraw, and the account type (savings or checking). It then calls the withdraw method from the bank_account class to perform the withdrawal and updates the previous transactions list accordingly. If there are insufficient funds or if the account is not found, it prints an error message and prompts the user to try again.
    elif option == "3":
    
            print("enter the amount of monney you want to withdraw: ")
            amount = float(input())
            print ("enter the account you want to withdraw from: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            if account_type == 1:
                account2.withdraw(amount)
            elif account_type == 2:
                account3.withdraw(amount)

#options for checking balance, which prompts the user for the account holder's name and then calls the check_balance method from the bank_account class to display the total balance for both savings and checking accounts. If the account is not found, it prints an error message and prompts the user to try again.
    elif option == "4":
            print("enter the amount of monney you want to withdraw: ")
            amount = float(input())
            account4.make_payment(amount)
            print(f"Payment of ${amount:.2f} made towards auto loan account.")
         
    elif option == "5":
            print("enter the account you want to check balance for: ")
            print("1. Savings")
            print("2. Checking")
            print("3. Auto Loan")
            account_type = int(input("Enter your choice: "))
            if account_type == 1:
                account2.check_balance()
            elif account_type == 2:
                account3.check_balance()
            elif account_type == 3:
                account4.check_balance()
        
#options for exiting the program, which prints a thank you message and breaks the loop to end the program. If an invalid option is selected, it prints an error message and prompts the user to try again.
    elif option == "6":
        print("Thank you for banking with us!")
        x = 0
        break
    else:
        print("Invalid option. Please try again.")