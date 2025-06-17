#include <iostream>
#include <vector>
#include <string>
#include <cmath>

constexpr double DEBT_LIMIT = 0;
unsigned long long int MAX_UUID = std::pow(2, sizeof(unsigned long long int) * 8) - 1;
std::size_t unused_UUID = 0;

class BankAccount
{
public:
    using n = unsigned long long int; // half UUID
private:
    n accountNumber = MAX_UUID;
    std::string ownerName = std::string("Wasn't ChatGPT's requirement");
    double balance = double(0);
public:
    BankAccount(): accountNumber(unused_UUID), ownerName("Wasn't ChatGPT's requirement"), balance(0) { ++unused_UUID; }
    void deposit(double amount) { if (amount >= 0) balance += amount; }
    bool widthdraw(double amount)
    {
        if (((balance - amount) >= DEBT_LIMIT) && (amount >= 0))
            balance -= amount;
        else return false;
        return true;
    }
    void display()
    {
        std::cout
            << "--- ACCOUNT UUID " << accountNumber << "---"
            << "\n>> UUID (may change over time): " << accountNumber
            << "\n>> Owner's Name: " << ownerName
            << "\n>> Balance: " << balance << "\n--- Displayed all data ---\n" << std::endl;
    }

    n getUUID() { return accountNumber; }
    bool setUUID(n newUUID)
    {
        if (newUUID >= unused_UUID)
        {
            accountNumber = newUUID;
            unused_UUID = accountNumber + 1;
            return true;
        }
        return false;
    }
};

char mainMenu(const std::vector<BankAccount>& acc) // int8_t, don't feel like importing cstddef
{
    char selection;
    do
    {
        std::cout
            << "--- Main Menu ---"
            << "\n>> Session-specific statistic: " << acc.size() << " accounts active in this session."
            << "\n>> Options: "
            << "\n>> 1. Create an account"
            << "\n>> 2. Delete an account"
            << "\n>> 3. View   an account"
            << "\n>> 4. Deposit to    an account"
            << "\n>> 5. Withdraw from an account"
            << "\n>> 6. Exit (data isn't saved)"
            << "\n>_ Select 1 - 6: " << std::flush;
        std::cin >> selection; std::cout << "--- Selected " << selection << " ---\n" << std::endl;
        selection -= 48;
    }
    while ((selection == 0) || (selection > 6));
    return selection;
}

BankAccount::n getUUID(const std::vector<BankAccount>& acc, std::string prompt)
{
    std::cout << prompt;
    BankAccount::n UUID; std::cin >> UUID;
    if (UUID >= acc.size())
    {
        std::cout << ">> Sorry... it doesn't quite look that this UUID doesn't exist (anymore).\n" << std::endl;
        return MAX_UUID;
    }
    return UUID;
}

void removeUUID(std::vector<BankAccount>& acc, BankAccount::n UUID)
{
    BankAccount::n set_back;
    for (BankAccount::n i = 0; i < acc.size(); ++i)
    {
        if (UUID == acc[i].getUUID())
        {
            acc.erase(acc.begin() + i);
            unused_UUID = UUID;
        }
        else set_back = i;
    }
    for (; set_back < acc.size(); ++set_back)
    {
        acc[set_back].setUUID(unused_UUID);
        ++unused_UUID;
    }
}

int main()
{
    std::vector<BankAccount> accounts(0);
    while (true)
    {
        char selection = mainMenu(accounts);
        if (selection == 1) // 1. Create an account
        {
            BankAccount newAcc;
            std::cout << ">> Created an empty account.\n";
            newAcc.display();
            accounts.push_back(newAcc);
        }
        else if (selection == 2) // 2. Delete an account
        {
            BankAccount::n UUID = getUUID(accounts, std::string(">> Enter UUID of the account you want to delete: "));
            if (UUID != MAX_UUID)
            {
                removeUUID(accounts, UUID);
                std::cout << ">> Removed account with the UUID " << UUID << ".\n" << std::endl;
            }
        }
        else if (selection == 3) // 3. View an account
        {
            BankAccount::n UUID = getUUID(accounts, std::string(">> Enter UUID of the account you want to view: "));
            if (UUID != MAX_UUID) accounts[UUID].display();
        }   
        else if (selection == 4) // 4. Deposit to an account
        {
            BankAccount::n UUID = getUUID(accounts, std::string(">> Enter UUID of the account you want to deposit to: "));
            if (UUID != MAX_UUID)
            {
                double amount;
                std::cout << ">> Enter the amount you want to deposit: ";
                std::cin >> amount;
                accounts[UUID].deposit(amount);
                accounts[UUID].display();
            }
        }   
        else if (selection == 5) // 5. Withdraw from an account
        {
            BankAccount::n UUID = getUUID(accounts, std::string(">> Enter UUID of the account you want to withdraw from: "));
            if (UUID != MAX_UUID)
            {   
                double amount;
                std::cout << ">> Enter the amount you want to withdraw: ";
                std::cin >> amount;
                if (accounts[UUID].widthdraw(amount))
                    accounts[UUID].display();
                else std::cout << ">> Failed to withdraw" << amount << " due to either invalid input or invalid balance.\n" << std::endl;
            }
        }   
        else if (selection == 6)
        {
            std::cout << "I understand." << std::endl;
            return 0;
        }
    }
    return 0;
}
