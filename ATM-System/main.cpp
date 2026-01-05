#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// =======================
// Transaction
// =======================
class Transaction
{
    string type;
    double amount;
    string timestamp;

public:
    Transaction(string t, double a)
        : type(t), amount(a)
    {
        time_t now = time(0);
        timestamp = ctime(&now);
        timestamp.pop_back();
    }

    void display() const
    {
        cout << type << " | Amount: " << amount
             << " | Time: " << timestamp << endl;
    }
};

// =======================
// Card
// =======================
class Card
{
    string cardNumber;
    int pin;

public:
    Card(string num = "", int p = 0)
        : cardNumber(num), pin(p) {}

    bool verify(const string& num, int p) const
    {
        return cardNumber == num && pin == p;
    }
};

// =======================
// Account
// =======================
class Account
{
    int id;
    double balance;
    Card card;
    vector<Transaction> transactions;

public:
    Account(int _id, string cardNum, int pin, double bal)
        : id(_id), balance(bal), card(cardNum, pin) {}

    int getId() const
    {
        return id;
    }

    bool authenticate(const string& cardNum, int pin)
    {
        return card.verify(cardNum, pin);
    }

    double getBalance() const
    {
        return balance;
    }

    bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance)
            return false;

        balance -= amount;
        transactions.emplace_back("Withdraw", amount);
        return true;
    }

    bool deposit(double amount)
    {
        if (amount <= 0)
            return false;

        balance += amount;
        transactions.emplace_back("Deposit", amount);
        return true;
    }

    void showTransactions() const
    {
        if (transactions.empty())
        {
            cout << "No transactions yet.\n";
            return;
        }

        for (const auto& t : transactions)
            t.display();
    }
};

// =======================
// BankSystem
// =======================
class BankSystem
{
    vector<Account> accounts;

public:
    BankSystem()
    {
        accounts.emplace_back(1, "111111", 1111, 2000);
        accounts.emplace_back(2, "222222", 2222, 6000);
    }

    // Authentication ONLY (no attempts here)
    Account* authenticate(const string& cardNum, int pin)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].authenticate(cardNum, pin))
            {
                return &accounts[i];
            }
        }
        return nullptr;
    }

    bool transfer(int fromId, int toId, double amount)
    {
        Account* from = nullptr;
        Account* to = nullptr;

        for (auto& acc : accounts)
        {
            if (acc.getId() == fromId) from = &acc;
            if (acc.getId() == toId)   to = &acc;
        }

        if (!from || !to) return false;
        if (!from->withdraw(amount)) return false;

        to->deposit(amount);
        return true;
    }
};

// =======================
// ATM
// =======================
class ATM
{
    BankSystem& bank;

public:
    ATM(BankSystem& b) : bank(b) {}

    Account* login()
    {
        string cardNum;
        int pin;
        Account* acc = nullptr;
        int attempts = 0;

        while (attempts < 3)
        {
            cout << "Enter Card Number: ";
            cin >> cardNum;

            cout << "Enter PIN: ";
            cin >> pin;

            acc = bank.authenticate(cardNum, pin);

            if (acc)
            {
                cout << "Login successful.\n";
                return acc;
            }

            attempts++;
            cout << "Invalid credentials.\n";
        }

        cout << "Session locked.\n";
        return nullptr;
    }

    static void showMenu()
    {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Balance\n";
        cout << "2. Withdraw\n";
        cout << "3. Deposit\n";
        cout << "4. Transfer\n";
        cout << "5. Transactions\n";
        cout << "6. Logout\n";
        cout << "Choose: ";
    }

    void run()
    {
        Account* current = login();
        if (!current) return;

        int choice;
        do
        {
            showMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Balance: " << current->getBalance() << endl;
                break;

            case 2:
            {
                double amt;
                cout << "Amount: ";
                cin >> amt;
                cout << (current->withdraw(amt) ? "Success\n" : "Failed\n");
                break;
            }

            case 3:
            {
                double amt;
                cout << "Amount: ";
                cin >> amt;
                cout << (current->deposit(amt) ? "Success\n" : "Failed\n");
                break;
            }

            case 4:
            {
                int toId;
                double amt;
                cout << "Transfer to Account ID: ";
                cin >> toId;
                cout << "Amount: ";
                cin >> amt;
                cout << (bank.transfer(current->getId(), toId, amt) ? "Success\n" : "Failed\n");
                break;
            }

            case 5:
                current->showTransactions();
                break;

            case 6:
                cout << "Logged out.\n";
                break;

            default:
                cout << "Invalid choice.\n";
            }

        } while (choice != 6);
    }
};

// =======================
// main
// =======================
int main()
{
    BankSystem bank;
    ATM atm(bank);
    atm.run();
    return 0;
}
