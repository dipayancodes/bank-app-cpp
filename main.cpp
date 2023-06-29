#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    string accountHolderName;
    double balance;
};

// Function to open a new account
void openAccount(vector<BankAccount>& accounts) {
    BankAccount newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cin.ignore(); // Ignore the newline character in the input buffer
    cout << "Enter account holder name: ";
    getline(cin, newAccount.accountHolderName);
    cout << "Enter initial balance: ";
    cin >> newAccount.balance;
    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

// Function to display account details
void displayAccount(const BankAccount& account) {
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Account Holder Name: " << account.accountHolderName << endl;
    cout << "Balance: " << account.balance << endl;
}

// Function to deposit funds into an account
void deposit(vector<BankAccount>& accounts, int accountNumber, double amount) {
    for (BankAccount& account : accounts) {
        if (account.accountNumber == accountNumber) {
            account.balance += amount;
            cout << "Deposit successful!" << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

// Function to withdraw funds from an account
void withdraw(vector<BankAccount>& accounts, int accountNumber, double amount) {
    for (BankAccount& account : accounts) {
        if (account.accountNumber == accountNumber) {
            if (account.balance >= amount) {
                account.balance -= amount;
                cout << "Withdrawal successful!" << endl;
            } else {
                cout << "Insufficient balance!" << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}

// Function to search for an account
void searchAccount(const vector<BankAccount>& accounts, int accountNumber) {
    for (const BankAccount& account : accounts) {
        if (account.accountNumber == accountNumber) {
            displayAccount(account);
            return;
        }
    }
    cout << "Account not found!" << endl;
}

int main() {
    vector<BankAccount> accounts;
    int choice;
    
    do {
        cout << "\n***** Banking App *****" << endl;
        cout << "1. Open an account" << endl;
        cout << "2. Show account details" << endl;
        cout << "3. Deposit funds" << endl;
        cout << "4. Withdraw funds" << endl;
        cout << "5. Search for an account" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                openAccount(accounts);
                break;
            }
            case 2: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                searchAccount(accounts, accountNumber);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(accounts, accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(accounts, accountNumber, amount);
                break;
            }
            case 5: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                searchAccount(accounts, accountNumber);
                break;
            }
            case 6: {
                cout << "Exiting the program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

