class bank_account: #
#initializes the bank account class with the account holder's name, account number, savings balance, checking balance, previous transactions, and total interest earned
    def __init__(self, full_name, number, savings, balance_checking, previous_transactions, total_interest_earned):
        self.full_name = full_name
        self.account_number = number
        self.balance_savings = savings
        self.balance_checking = balance_checking
        self.previous_transactions = previous_transactions
        self.total_interest_earned = total_interest_earned
#prints the account information for the account holder, including the account holder's name, account number, savings balance, checking balance, total balance for savings and checking, and total interest earned
    def view_account_info(self):
        print(f"Account Holder: {self.full_name}")
        print(f"Account Number: {self.account_number}")
        print(f"Savings Balance: ${self.balance_savings:.2f}")
        print(f"Checking Balance: ${self.balance_checking:.2f}")
        print(f"Total Balance for savings is: ${self.balance_savings:.2f}")
        print(f"Total Balance for checking is: ${self.balance_checking:.2f}")
        print(f"Total Interest Earned: ${self.total_interest_earned:.2f}")
        print("")
#deposits money into the specified account type (savings or checking) and updates the previous transactions list with the deposit information
    def deposit(self, amount, account_type):
        if account_type == 1:
            self.balance_savings += amount
            self.previous_transactions.append(f"Deposited ${amount:.2f} to savings account.")
        elif account_type == 2:
            self.balance_checking += amount
            self.previous_transactions.append(f"Deposited ${amount:.2f} to checking account.")
        else:
            print("Invalid account type. Please try again.")
#withdraws money from the specified account type (savings or checking) if there are sufficient funds and updates the previous transactions list with the withdrawal information. If there are insufficient funds, it prints an error message.
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
#prints the total balance for both savings and checking accounts   
    def check_balance(self):
        print(f"Total Balance for savings is: ${self.balance_savings:.2f}")
        print(f"Total Balance for checking is: ${self.balance_checking:.2f}")
#prints the previous transactions for the account holder, including deposits and withdrawals for both savings and checking accounts
    def view_previous_transactions(self):
        print("Previous Transactions:")
        for transaction in self.previous_transactions:
            print(transaction)

#gets data for account 1
acc1full_name = input("Enter the account holder's name: ")
acc1number = input("Enter the account number: ")
acc1savings = float(input("Enter the initial savings balance: "))
acc1checking = float(input("Enter the initial checking balance: "))
#gets data for account 2
acc2full_name = input("Enter the account holder's name: ")
acc2number = input("Enter the account number: ")
acc2savings = float(input("Enter the initial savings balance: "))
acc2checking = float(input("Enter the initial checking balance: "))
#gets data for account 3
acc3full_name = input("Enter the account holder's name: ")
acc3number = input("Enter the account number: ")
acc3savings = float(input("Enter the initial savings balance: "))
acc3checking = float(input("Enter the initial checking balance: "))
#gets data for account 4
acc4full_name = input("Enter the account holder's name: ")
acc4number = input("Enter the account number: ")
acc4savings = float(input("Enter the initial savings balance: "))
acc4checking = float(input("Enter the initial checking balance: "))
#inputs the data for all accounts
account1 = bank_account(acc1full_name, acc1number, acc1savings, acc1checking, [], 150.00)
account2 = bank_account(acc2full_name, acc2number, acc2savings, acc2checking, [], 75.00)
account3 = bank_account(acc3full_name, acc3number, acc3savings, acc3checking, [], 200.00)
account4 = bank_account(acc4full_name, acc4number, acc4savings, acc4checking, [], 2500.00)

x = 1
while x > 0:
#menu
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
#options for the menu, including viewing account information, depositing money, withdrawing money, checking balance, viewing previous transactions, and exiting the program. Each option prompts the user for the necessary information and calls the appropriate method from the bank_account class to perform the desired action. If an invalid option is selected, it prints an error message and prompts the user to try again.
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
#options for depositing money, which prompts the user for the account holder's name, the amount to deposit, and the account type (savings or checking). It then calls the deposit method from the bank_account class to perform the deposit and updates the previous transactions list accordingly. If the account is not found, it prints an error message and prompts the user to try again.
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
#options for withdrawing money, which prompts the user for the account holder's name, the amount to withdraw, and the account type (savings or checking). It then calls the withdraw method from the bank_account class to perform the withdrawal and updates the previous transactions list accordingly. If there are insufficient funds or if the account is not found, it prints an error message and prompts the user to try again.
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
#options for checking balance, which prompts the user for the account holder's name and then calls the check_balance method from the bank_account class to display the total balance for both savings and checking accounts. If the account is not found, it prints an error message and prompts the user to try again.
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
#options for viewing previous transactions, which prompts the user for the account holder's name and then calls the view_previous_transactions method from the bank_account class to display the list of previous transactions for that account. If the account is not found, it prints an error message and prompts the user to try again.
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
#options for exiting the program, which prints a thank you message and breaks the loop to end the program. If an invalid option is selected, it prints an error message and prompts the user to try again.
    elif option == "6":
        print("Thank you for banking with us!")
        x = 0
        break
    else:
        print("Invalid option. Please try again.")