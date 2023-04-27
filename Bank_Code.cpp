Sayantan2k24
/
Banking_Management_System
Public
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Beta Try the new code view
Banking_Management_System/bank_code.cpp

SAYANTAN first commit
 0 contributors
287 lines (265 sloc)  7.56 KB
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string name;
    string mobile;
    int pin;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, string mobile, int pin, int accountNumber) {
        this->name = name;
        this->mobile = mobile;
        this->pin = pin;
        this->accountNumber = accountNumber;
        this->balance = 0;
    }

    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Mobile: " << mobile << endl;
        cout << "Balance: $" << balance << endl;
    }
    
    // Add a member function to set the PIN for an account
    void setPin(int pin)
    {
        this->pin = pin;
    }

    // Add a member function to verify the PIN for an account
    bool verifyPin(int pin)
    {
        return this->pin == pin;
    }    

    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully! New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Amount withdrawn successfully! New balance: $" << balance << endl;
        }
    }

    void updateAccountDetails(string name, string mobile, int pin) {
        this->name = name;
        this->mobile = mobile;
        this->pin = pin;
        cout << "Account details updated successfully!" << endl;
    }

    void deleteAccount() {
        // Reset account details
        name = "";
        mobile = "";
        pin = 0;
        balance = 0;
        cout << "Account deleted successfully!" << endl;
    }

    // Getter methods
    int getAccountNumber() {
        return accountNumber;
    }

    int getPin() {
        return pin;
    }
};

int findAccount(vector<BankAccount>& accounts, int accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<BankAccount> accounts;
    int choice;
    int accountNumber;
    int pin;
    string name;
    string mobile;
    double amount;
    int index;

    do {
        cout << "     ######  Bank Management System ######" <<endl;
        cout << "###############################################"<<endl;
		cout << "########### 1. Open an account      ###########" << endl;
        cout << "########### 2. Show account details ###########" << endl;
        cout << "########### 3. Deposit              ###########"  << endl;
        cout << "########### 4. Withdraw             ###########"  << endl;
        cout << "########### 5. Edit account details ###########" << endl;
        cout << "########### 6. Delete account       ###########" << endl;
        cout << "########### 7. Exit                 ###########" << "\n" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Open an account
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter mobile: ";
                //cin.ignore();
                getline(cin, mobile);
                cout << "Enter pin (4 digits): ";
                cin >> pin;
                accountNumber = accounts.size() + 1;
                accounts.push_back(BankAccount(name, mobile, pin, accountNumber));
                cout << "Account created successfully! Account Number: " << accountNumber << endl;
                break;
            case 2:
            {
        		// Show account details
   				cout << "Enter account number: ";
    			cin >> accountNumber;
   				index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
       				int enteredPin;
        			cout << "Enter PIN for VERIFICATION: ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
            			accounts[index].displayAccountDetails();
        			}
        			else
        			{
       			    	cout << "Incorrect PIN!" << endl;
        			}
    			}
    			else
    			{
    		    	cout << "Account not found!" << endl;
    			}
    			break;
			}
   
            case 3:
   			{
    			// Deposit
    			cout << "Enter account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        			cout << "Enter PIN for VERIFICATION: ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
            			cout << "Enter deposit amount: $";
            			cin >> amount;
            			accounts[index].deposit(amount);
        			}
        			else
        			{
            			cout << "Incorrect PIN!" << endl;
        			}
    			}
    			else
    			{
  			     	cout << "Account not found!" << endl;
    			}
    			break;
			}
			case 4:
			{
    			// Withdraw
    			cout << "Enter account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        			cout << "Enter PIN for VERIFICATION: ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
            		cout << "Enter withdrawal amount: $";
            		cin >> amount;
            		accounts[index].withdraw(amount);
        			}
        			else
        			{
            			cout << "Incorrect PIN!" << endl;
        			}
    			}
    			else
    			{
        		cout << "Account not found!" << endl;
    			}
				break;
			}

			case 5:
			{
			    // Edit account details
 		    	cout << "Enter account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        			cout << "Enter PIN for VERIFICATION: ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
       				{
            			cout << "Enter new name: ";
            			cin.ignore();
            			getline(cin, name);
            			cout << "Enter new mobile: ";
            			getline(cin, mobile);
            			cout << "Enter new pin (4 digits): ";
            			cin >> pin;
            			accounts[index].updateAccountDetails(name, mobile, pin);
        			}
        			else
        			{
            			cout << "Incorrect PIN!" << endl;
        			}
    			}
    			else
    			{	
        			cout << "Account not found!" << endl;
    			}
    			break;
			}
			case 6:
			{
    			// Delete account
    			cout << "Enter account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        			cout << "Enter PIN for VERIFICATION: ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
        	    		accounts[index].deleteAccount();
            			accounts.erase(accounts.begin() + index);
        			}
        			else
        			{
            			cout << "Incorrect PIN!" << endl;
        			}				
    			}
    			else
    			{
        			cout << "Account not found!" << endl;
    			}
    			break;
			}		

            case 7:
                // Exit
                cout << "Thank you for using Bank Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
