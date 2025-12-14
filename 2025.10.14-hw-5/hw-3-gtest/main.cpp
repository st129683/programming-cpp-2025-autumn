#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>

#include "BankAccount.h"

class BankAccountTest : public ::testing::Test {
protected:
    std::shared_ptr<BankAccount> account;

    void SetUp() override {
        account = std::make_shared<BankAccount>("123456", 1000.0, "John Doe");
    }
};

TEST_F(BankAccountTest, PositiveDeposit) {
    account->Deposit(500.0);
    EXPECT_DOUBLE_EQ(account->GetBalance(), 1500.0);
}

TEST_F(BankAccountTest, NegativeDeposit) {
    account->Deposit(-200.0);
    EXPECT_DOUBLE_EQ(account->GetBalance(), 800.0);
}

TEST_F(BankAccountTest, SuccessfulWithdraw) {
    account->Withdraw(300.0);
    EXPECT_DOUBLE_EQ(account->GetBalance(), 700.0);
}

TEST_F(BankAccountTest, InsufficientFundsWithdraw) {
    EXPECT_THROW({
        account->Withdraw(1500.0);
    }, std::invalid_argument);
}

TEST_F(BankAccountTest, NegativeWithdraw) {
    account->Withdraw(-200.0);
    EXPECT_DOUBLE_EQ(account->GetBalance(), 1200.0);
}

class BankTest : public ::testing::Test {
protected:
    Bank bank;
    std::shared_ptr<BankAccount> account1;
    std::shared_ptr<BankAccount> account2;

    void SetUp() override {
        account1 = std::make_shared<BankAccount>("111", 1000.0, "Alice");
        account2 = std::make_shared<BankAccount>("222", 2000.0, "Bob");
        bank.AddAccount(account1);
        bank.AddAccount(account2);
    }
};

TEST_F(BankTest, AddAccount) {
    EXPECT_DOUBLE_EQ(bank.GetTotalBalance(), 3000.0);
}

TEST_F(BankTest, TotalBalanceCalculation) {
    account1->Deposit(500.0);
    account2->Withdraw(300.0);
    EXPECT_DOUBLE_EQ(bank.GetTotalBalance(), 3200.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
