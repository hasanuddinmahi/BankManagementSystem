#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
protected:
    int account_number;
    int balance = 0;
private:
    string password;

public:
    BankAccount(string account_holder,string address,int age,string password)
    {
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->account_number = rand()%1000000000;
        cout<<"Your account number is "<<this->account_number<<endl;
    }

    int show_balance(string password)
    {
        if(this->password == password)
        {
            return balance;
        }
        else
        {
            return -1;
        }
    }
    void add_money(string password,int amount)
    {
        if(amount<0)
        {
            cout<<"Invalid amount"<<endl;
        }
        if(this->password==password)
        {
            this->balance += amount;
            cout<<"Add money successful"<<endl;

        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }

    void deposit_money(string password,int amount)
    {
        if(amount<0)
        {
            cout<<"Invalid Amount"<<endl;
        }
        if(this->balance<amount)
        {
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance -= amount;
            cout<<"Deposit money successful"<<endl;

        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }
    friend class Mycash;
};

class Mycash
{
protected:
    int balance;
public:
    Mycash()
    {
        this->balance = 0;
    }
public:
    void add_money_from_bank(BankAccount *myAccount,string password,int amount)
    {
        if(amount<0)
        {
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if(myAccount->balance < amount)
        {
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(myAccount->password==password)
        {
            this->balance+=amount;
            myAccount->balance-=amount;
            cout<<"Add money from bank is successful"<<endl;
        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }
    int show_balance()
    {
        return balance;
    }
};

BankAccount* create_account()
{
    string account_holder,password,address;
    int age;
    cout<<"Create account"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *myAccount = new BankAccount(account_holder,address,age,password);
    return myAccount;
}

void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add Money"<<endl;
    cin>>password>>amount;
    myAccount->add_money(password,amount);
    cout<<"Your bank balance is "<<myAccount->show_balance("2345")<<endl;
}

void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Deposit Money"<<endl;
    cin>>password>>amount;
    myAccount->deposit_money(password,amount);
    cout<<"Your bank balance is "<<myAccount->show_balance("2345")<<endl;
}

void add_money_from_bank(Mycash *mycash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add Money"<<endl;
    cin>>password>>amount;
    mycash->add_money_from_bank(myAccount,password,amount);
    cout<<"Mycash balance is "<<mycash->show_balance()<<endl;
}

int main()
{
    BankAccount *myAccount = create_account();
    add_money(myAccount);
    deposit_money(myAccount);
    Mycash *mycash = new Mycash();
    add_money_from_bank(mycash,myAccount);
    return 0;
}
