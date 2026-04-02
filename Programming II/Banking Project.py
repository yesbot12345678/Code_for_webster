class bank_account:
    def __init__(self, full_name, number, savings, balance_checking, previous_transactions, total_interest_earned):
        self.full_name = full_name
        self.account_number = number
        self.balance_savings = savings
        self.balance_checking = balance_checking
        self.previous_transactions = previous_transactions
        self.total_interest_earned = total_interest_earned

    def view_account_info(self):
        print(f"Account Holder: {self.full_name}")
        print(f"Account Number: {self.account_number}")
        print(f"Savings Balance: ${self.balance_savings:.2f}")
        print(f"Checking Balance: ${self.balance_checking:.2f}")
        print(f"Total Balance for savings is: ${self.balance_savings:.2f}")
        print(f"Total Balance for checking is: ${self.balance_checking:.2f}")
        print(f"Total Interest Earned: ${self.total_interest_earned:.2f}")
        print("")

    def deposit(self, amount, account_type):
        if account_type == 1:
            self.balance_savings += amount
            self.previous_transactions.append(f"Deposited ${amount:.2f} to savings account.")
        elif account_type == 2:
            self.balance_checking += amount
            self.previous_transactions.append(f"Deposited ${amount:.2f} to checking account.")
        else:
            print("Invalid account type. Please try again.")
    
    def withdraw(self, amount, account_type):
        if account_type == 1:
            if amount > self.balance_savings:
                print("Insufficient funds in savings account. Please try again.")
            else:
                self.balance_savings -= amount
                self.previous_transactions.append(f"Withdrew ${amount:.2f} from savings account.")
        elif account_type == 2:
            if amount > self.balance_checking:
                print("Insufficient funds in checking account. Please try again.")
            else:
                self.balance_checking -= amount
                self.previous_transactions.append(f"Withdrew ${amount:.2f} from checking account.")
        else:
            print("Invalid account type. Please try again.")
    
    def check_balance(self):
        print(f"Total Balance for savings is: ${self.balance_savings:.2f}")
        print(f"Total Balance for checking is: ${self.balance_checking:.2f}")

    def view_previous_transactions(self):
        print("Previous Transactions:")
        for transaction in self.previous_transactions:
            print(transaction)
            
acc1full_name = input("Enter the account holder's name: ")
acc1number = input("Enter the account number: ")
acc1savings = float(input("Enter the initial savings balance: "))
acc1checking = float(input("Enter the initial checking balance: "))

acc2full_name = input("Enter the account holder's name: ")
acc2number = input("Enter the account number: ")
acc2savings = float(input("Enter the initial savings balance: "))
acc2checking = float(input("Enter the initial checking balance: "))

acc3full_name = input("Enter the account holder's name: ")
acc3number = input("Enter the account number: ")
acc3savings = float(input("Enter the initial savings balance: "))
acc3checking = float(input("Enter the initial checking balance: "))

acc4full_name = input("Enter the account holder's name: ")
acc4number = input("Enter the account number: ")
acc4savings = float(input("Enter the initial savings balance: "))
acc4checking = float(input("Enter the initial checking balance: "))


account1 = bank_account(acc1full_name, acc1number, acc1savings, acc1checking, [], 150.00)
account2 = bank_account(acc2full_name, acc2number, acc2savings, acc2checking, [], 75.00)
account3 = bank_account(acc3full_name, acc3number, acc3savings, acc3checking, [], 200.00)
account4 = bank_account(acc4full_name, acc4number, acc4savings, acc4checking, [], 2500.00)

x = 1
while x > 0:

    print("Welcome to the Bank of Python!")
    print("Please create an account:")
    print("Please select an option:")
    print("1. View account information")
    print("2. Deposit money")
    print("3. Withdraw money")
    print("4. Check balance")
    print("5. View previous transactions")
    print("6. Exit")
    print("")

    option = input("Enter your choice: ")

    if option == "1":
        name = input("Enter the account holder's name: ")
        print("")
        if name == account1.full_name:
            account1.view_account_info()
        elif name == account2.full_name:
            account2.view_account_info()
        elif name == account3.full_name:
            account3.view_account_info()
        elif name == account4.full_name:
            account4.view_account_info()
        else:
            print("Account not found. Please try again.")
    elif option == "2":
        name = input("Enter the account holder's name: ")
        print("")
        if name == account1.full_name:
            print("enter the amount of monney you want to deposit: ")
            amount = float(input())
            print ("enter the account you want to deposit to: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            account1.deposit(amount, account_type)

        elif name == account2.full_name:
            print("enter the amount of monney you want to deposit: ")
            amount = float(input())
            print ("enter the account you want to deposit to: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            account2.deposit(amount, account_type)
                   
        elif name == account3.full_name:
            print("enter the amount of monney you want to deposit: ")
            amount = float(input())
            print ("enter the account you want to deposit to: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            account3.deposit(amount, account_type)
            
        elif name == account4.full_name:
            print("enter the amount of monney you want to deposit: ")
            amount = float(input())
            print ("enter the account you want to deposit to: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            account4.deposit(amount, account_type)
        else:
            print("Account not found. Please try again.")
    elif option == "3":
        name = input("Enter the account holder's name: ")
        print("")
        if name == account1.full_name:
            print("enter the amount of monney you want to withdraw: ")
            amount = float(input())
            print ("enter the account you want to withdraw from: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            account1.withdraw(amount, account_type)            

        elif name == account2.full_name:
            print("enter the amount of monney you want to withdraw: ")
            amount = float(input())
            print ("enter the account you want to withdraw from: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            account_type = int(input("Enter your choice: "))
            account1.withdraw(amount, account_type)      

        elif name == account3.full_name:
            print("enter the amount of monney you want to withdraw: ")
            amount = float(input())
            print ("enter the account you want to withdraw from: ")
            print("1. Savings")
            print("2. Checking")
            account_type = int(input("Enter your choice: "))
            account_type = int(input("Enter your choice: "))
            account1.withdraw(amount, account_type)      
            
        elif name == account4.full_name:
            print("enter the amount of monney you want to withdraw: ")
            amount = float(input())
            print ("enter the account you want to withdraw from: ")
            print("1. Savings")
            print("2. Checking")
            account_type = input("Enter your choice: ")
            account_type = int(input("Enter your choice: "))
            account1.withdraw(amount, account_type)      

    elif option == "4":
        name = input("Enter the account holder's name: ")
        print("")
        if name == account1.full_name:
            account1.check_balance()
        elif name == account2.full_name:
            account2.check_balance()
        elif name == account3.full_name:
            account3.check_balance()
        elif name == account4.full_name:
            account4.check_balance()
        else:
            print("Account not found. Please try again.")
    elif option == "5": 
        name = input("Enter the account holder's name: ")
        print("")
        if name == account1.full_name:
            account1.view_previous_transactions()
        elif name == account2.full_name:
            account2.view_previous_transactions()
        elif name == account3.full_name:
            account3.view_previous_transactions()
        elif name == account4.full_name:
            account4.view_previous_transactions()
        else:
            print("Account not found. Please try again.")
    elif option == "6":
        print("Thank you for banking with us!")
        x = 0
        break
    else:
        print("Invalid option. Please try again.")