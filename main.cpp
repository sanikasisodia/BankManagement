#include <iostream>
#include <string>
#include <vector>

class BankAccount
{
private:
    std::string name;
    double balance;
    double interestRate;
    std::vector<std::string> transactionHistory;
    std::string accountType;

public:
    BankAccount(std::string accountName, double initialBalance, double interest, std::string type)
        : name(accountName), balance(initialBalance), interestRate(interest), accountType(type) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            recordTransaction("Deposit: +$" + std::to_string(amount));
        }
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            recordTransaction("Withdrawal: -$" + std::to_string(amount));
        }
        else
        {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    void display()
    {
        std::cout << "Account: " << name << "\nType: " << accountType << "\nBalance: $" << balance << std::endl;
    }

    void calculateInterest()
    {
        double interestEarned = balance * interestRate / 100.0;
        std::cout << "Interest Earned: $" << interestEarned << std::endl;
    }

    void recordTransaction(std::string transaction)
    {
        transactionHistory.push_back(transaction);
    }

    void displayTransactionHistory()
    {
        std::cout << "Transaction History:" << std::endl;
        for (const auto &transaction : transactionHistory)
        {
            std::cout << transaction << std::endl;
        }
    }
};

int main()
{
    std::string name, type;
    double initialDeposit, interestRate;

    std::cout << "Enter your name: ";
    getline(std::cin, name);
    std::cout << "Enter account type (e.g., savings, checking): ";
    getline(std::cin, type);
    std::cout << "Enter initial deposit: ";
    std::cin >> initialDeposit;
    std::cout << "Enter interest rate: ";
    std::cin >> interestRate;

    BankAccount account(name, initialDeposit, interestRate, type);

    int choice;
    double amount;

    do
    {
        std::cout << "\n1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Display Account" << std::endl;
        std::cout << "4. Calculate Interest" << std::endl;
        std::cout << "5. Display Transaction History" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.display();
            break;
        case 4:
            account.calculateInterest();
            break;
        case 5:
            account.displayTransactionHistory();
            break;
        case 6:
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
