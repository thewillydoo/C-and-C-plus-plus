//
// ECE 220 Lab - Winter 2023 - Programming for Electrical Engineering
// // Lab 1: Play with a Machine
// // Lab 2: Let us Translate
// // Lab 3: Divide and Conquer
// // Lab 4: Modular and Tailored
// ---> Lab 5: Object Oriented
//
//


#include <iostream>
#include <string.h>

using namespace std;

#define MAX_NAME_LEN 40
#define OWN 1
#define RENT 0
// The 1st-level class: BankAccount
class BankAccount {
protected:
    char name[MAX_NAME_LEN];
    int account_number;
    double balance;
public:
    BankAccount();

    BankAccount(char *);

    BankAccount(char *, int, double);

    void printSummary();

    double withdraw(double);

    void deposit(double);

    double getBalance();

    void setName(char *);

    void setAccount_number(int);

    void setBalance(double);
};

// The 2nd-level class: saveBankAccount
class saveBankAccount : public BankAccount { //inheritance of BankAccount
protected:
    double interestRate;
    int MAXnoWithDraws;
    int noWithDraws;

public:
    saveBankAccount(char *name0, int acc_num0, double balance0, double interestRate0, int MAXnoWtdraws0);

    void printSummary();

    double withdraw(double);

    void callInterest();

    void resetWithdraws();

    void transfer(saveBankAccount &acc2, double);

};

// The 3rd-level class: CreditScoreAccount
class CreditScoreAccount : public saveBankAccount {   //inherit from saveBankAccount
protected:
    int age;
    long income;
    bool home_ownership;
    int CreditScore;
public:
    CreditScoreAccount(char *name0, int acc_num0, double balance0, double interestRate0, int MAXnoWtdraws0, int age0,
                       long income0, bool home0);

    void CreditScoreReport();
};


int main(void) {

    //create an object
    saveBankAccount tomAcc("Tom", 110011, 2000, 0.05, 1);
    tomAcc.printSummary();

    tomAcc.deposit(1000);
    tomAcc.printSummary();

    tomAcc.withdraw(500);
    tomAcc.printSummary();

    tomAcc.withdraw(500);
    tomAcc.printSummary();

    cout << "Balance: " << tomAcc.getBalance() << endl;

    tomAcc.resetWithdraws();
    tomAcc.printSummary();

    tomAcc.withdraw(500);
    tomAcc.printSummary();

    tomAcc.callInterest();
    tomAcc.printSummary();

    saveBankAccount ericAcc("Eric", 220011, 5000, 0.04, 1);
    ericAcc.printSummary();

    ericAcc.transfer(tomAcc, 1000);
    ericAcc.printSummary();
    tomAcc.printSummary();

    CreditScoreAccount amyCredit("Amy", 330011, 5000, 0.03, 5, 25, 80000, RENT);
    amyCredit.printSummary();
    amyCredit.CreditScoreReport();

    CreditScoreAccount kateCredit("Kate", 330022, 5000, 0.03, 5, 35, 120000, OWN);
    kateCredit.printSummary();
    kateCredit.CreditScoreReport();

    return 0;
}



////**********************************************
//// class BankAccount: methods
////**********************************************

BankAccount::BankAccount() {
    name[0] = 0;
    account_number = 0;
    balance = 0.0;
}

BankAccount::BankAccount(char *n) {
    strcpy(name, n);
    account_number = 0;
    balance = 0.0;
}

BankAccount::BankAccount(char *n, int a_no, double bal) {
    strcpy(name, n);
    account_number = a_no;
    balance = bal;
}

void BankAccount::printSummary() {
    cout << "---------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
    cout << "---------------------" << endl;
}

double BankAccount::withdraw(double toWD) {
    if (balance - toWD > 0) {
        balance -= toWD;
        cout << "Withdraw succeed!: " << toWD << endl;
        return toWD; //teng4 modified.
    } else {
        cout << "!!!Sorry, not enough money!!!" << endl;
        cout << "Withdraw failed!: " << toWD << endl;
        return 0;
    }
}

void BankAccount::deposit(double toDep) {
    balance += toDep;
    cout << "Deposit succeed!: " << toDep << endl;
}

double BankAccount::getBalance() {
    return balance;
}


void BankAccount::setName(char *n) {
    strcpy(name, n);
}

void BankAccount::setAccount_number(int a_no) {
    account_number = a_no;
}

void BankAccount::setBalance(double bal) {
    balance = bal;
}



////**********************************************
//// class saveBankAccount: methods
////**********************************************

saveBankAccount::saveBankAccount(char *name0, int acc_num0, double balance0, double interestRate0, int MAXnoWtdraws0): BankAccount(name0, acc_num0, balance0) {
    strcpy(name, name0);
    account_number = acc_num0;
    balance = balance0;
    interestRate = interestRate0;
    MAXnoWithDraws = MAXnoWtdraws0;
    noWithDraws = 0;
}

void saveBankAccount::printSummary() {
    cout << "---------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
    cout << "Interest Rate: " << interestRate << endl;
    cout << "Current Num Withdraws: " << noWithDraws << endl;
    cout << "Max Num Withdraws: " << MAXnoWithDraws << endl;
    cout << "---------------------" << endl;
}


void saveBankAccount::callInterest() {
    int interest;
    interest = interestRate * balance;
    balance += interest;
    cout << "New balance: " << balance << endl;
}

void saveBankAccount::resetWithdraws() {
    noWithDraws = 0;
}

void saveBankAccount::transfer(saveBankAccount &acc2, double amount) {
    bool withdrawSuccess = withdraw(amount);
    if (withdrawSuccess) {
        acc2.deposit(amount);
    } else {
        cout << "Transfer failed." << endl;
    }
}

double saveBankAccount::withdraw(double amount) {
    if (noWithDraws < MAXnoWithDraws) {
        if (balance - amount > 0) {
            balance -= amount;
            noWithDraws++;
            cout << "Withdrawal amount: " << amount << endl;
            cout << "New balance: " << balance << endl;
            return amount;
        } else {
            cout << "Not enough balance in account." << endl;
            return 0;
        }
    } else {
        cout << "You have no more withdrawals available." << endl;
        return 0;
    }
}

////**********************************************
//// class CreditScoreAccount: methods
////**********************************************

CreditScoreAccount::CreditScoreAccount(char *name0, int acc_num0, double balance0, double interestRate0, int MAXnoWtdraws0, int age0, long income0, bool home0) : saveBankAccount(name0, acc_num0, balance0, interestRate0, MAXnoWtdraws0) {
    strcpy(name, name0);
    account_number = acc_num0;
    balance = balance0;
    interestRate = interestRate0;
    MAXnoWithDraws = MAXnoWtdraws0;
    age = age0;
    income = income0;
    home_ownership = home0;
    CreditScore = 0;
}

// Credit Score report
void CreditScoreAccount::CreditScoreReport() {
    int age_factor, income_factor, home_factor;
//---------------------------------------------
    if (age < 22) {
        age_factor = 100;
    } else if (22 <= age && age < 26) {
        age_factor = 120;
    } else if (26 <= age && age < 29) {
        age_factor = 185;
    } else if (29 <= age && age < 32) {
        age_factor = 200;
    } else if (32 <= age && age < 37) {
        age_factor = 210;
    } else if (37 <= age && age < 42) {
        age_factor = 225;
    } else if (age >= 42) {
        age_factor = 250;
    }

//---------------------------------------------
    if (income < 10000) {
        income_factor = 120;
    } else if (10000 <= income && income < 17000) {
        income_factor = 140;
    } else if (17000 <= income && income < 28000) {
        income_factor = 180;
    } else if (28000 <= income && income < 35000) {
        income_factor = 200;
    } else if (35000 <= income && income < 42000) {
        income_factor = 225;
    } else if (42000 <= income && income < 58000) {
        income_factor = 230;
    } else if (income >= 58000) {
        income_factor = 260;
    }
//---------------------------------------------
//calculating home_factor
    if (home_ownership == 1) {
        home_factor = 225;
    } else
        home_factor = 110;
//---------------------------------------------
    CreditScore = age_factor + income_factor + home_factor;
    cout << "---------------------" << endl;
    cout << "Credit report for " << name << endl;
    cout << "Age " << age_factor << endl;
    cout << "Income " << income_factor << endl;
    cout << "Home " << home_factor << endl;
    cout << "Credit Score: " << CreditScore << endl;
    cout << "" << endl;
    if (CreditScore < 600)
        cout << "Sorry, " << name << " is not eligible!" << endl;
    else
        cout << "Congratulations!! " << name << " is eligible!" << endl;
    cout << "---------------------" << endl;
}