#include <string>
#include <iostream>
#include <vector>
#include <memory>

class BankAccount {
private:
	std::string accountNumber;
	double balance;
	std::string accountHolder;

public:
	BankAccount(const std::string& accountNumber, double balance, const std::string& accountHolder)
		: accountNumber(accountNumber), balance(balance), accountHolder(accountHolder) {}

	void Deposit(double amount) {
		if (amount >= 0) {
			balance += amount;
		}
		else {
			Withdraw(-amount);
		}
	}

	void Withdraw(double amount) {
		if (balance >= amount && amount >= 0) {
			balance -= amount;
		}
		else if (amount < 0) {
			Deposit(-amount);
		}
		else {
			throw std::invalid_argument("Cannot withdraw: insufficient funds in the balance");
		}
	}

	double GetBalance() const {
		return balance;
	}

	std::string GetAccountNumber() const {
		return accountNumber;
	}

	std::string GetAccountHolder() const {
		return accountHolder;
	}

	void PrintAccountInfo() const {
		std::cout << "Account number: " << accountNumber << std::endl;
		std::cout << "Account holder: " << accountHolder << std::endl;
		std::cout << "Account balance: " << balance << std::endl;
	}
};


class Bank {
private:
	std::vector <std::shared_ptr <BankAccount>> accounts;

public:
	void AddAccount(const std::shared_ptr<BankAccount> account) {
		accounts.push_back(account);
	}

	double GetTotalBalance() const {
		double total = 0;
		for (const auto& account : accounts) {
			total += account->GetBalance();
		}
		return total;
	}

	void PrintAllAccountsInfo() const {
		for (const auto& account : accounts) {
			account->PrintAccountInfo();
			std::cout << std::endl;
		}
	}
};


int main(int argc, char* argv[]) {
	auto andreyIsakov = std::make_shared <BankAccount>("1", 0.0, "Andrey Isakov");
	auto denisKravchenko = std::make_shared <BankAccount>("2", 0.5, "Denis Kravchenko");
	auto daddyNesterchuk = std::make_shared <BankAccount>("3", 1e9, "Grigory Nesterchuk");

	Bank spbu;
	spbu.AddAccount(andreyIsakov);
	spbu.AddAccount(denisKravchenko);
	spbu.AddAccount(daddyNesterchuk);

	spbu.PrintAllAccountsInfo();
	std::cout << std::endl;

	daddyNesterchuk->Withdraw(1000.0);
	andreyIsakov->Deposit(100.0);
	denisKravchenko->Deposit(900.0);

	spbu.PrintAllAccountsInfo();
	spbu.GetTotalBalance();

	return 0;
}
