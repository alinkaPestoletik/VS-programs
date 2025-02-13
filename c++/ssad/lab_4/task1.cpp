#include <iostream>
#include <string>
using namespace std;


class Account {
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    Account() = default;

    Account(int accountNumber, double balance, const string& ownerName) : 
        accountNumber(accountNumber), balance(balance), ownerName(ownerName) {}

    virtual ~Account() = default; 

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= this->balance) { 
                this->balance -= amount;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    double getBalance() const { 
        return this->balance;
    }

    int getAccountNumber() const { 
        return this->accountNumber;
    }

    string getOwnerName() const { 
        return this->ownerName;
    }

    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;
};

class SavingsAccount : public Account {
    private:
        double interestRate;
    
    public:
        SavingsAccount(int accountNumber, double balance, const std::string& ownerName, double interestRate) :
            Account(accountNumber, balance, ownerName), interestRate(interestRate) {}
    
        void calculateInterest(double a) {
            double interest = this->getBalance() * (this->interestRate / 100.0);
            this->deposit(interest); 
        }
    
        double getInterestRate() const {
            return this->interestRate;
        }
    };

int main() {
    SavingsAccount savings(123456, 1000.0, "John Doe", 2.5);
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateInterest(500.0);
    cout << "Account number: " << savings.getAccountNumber() << '\n';
    cout << "Owner's Name: " << savings.getOwnerName() << '\n';
    cout << "Current Balance: " << savings.getBalance() << '\n';
    cout << "Interest Rate: " << savings.getInterestRate() << '\n';

    return 0;

}