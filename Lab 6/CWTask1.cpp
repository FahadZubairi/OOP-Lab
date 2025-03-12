#include<iostream>
using namespace std;
class BankAccount{
    int AccountNumber;
    float balance;
    float deposit;
    float withdraw;
    public:
    int getAccountNum(){
        return AccountNumber;
    }
    float getbalance(){
        return balance;
    }
    int getDeposit(){
        return deposit;
    }
    int getwithdraw(){
        return withdraw;
    }
    void setbalance(float b){
        balance = b;
    }
    void Deposit(float dep){
        balance += dep;
    }
    void Withdraw(float withdrawAmount){
        balance-=withdrawAmount;
    }
    
};

class Employee{
    int AccountNumber;
    float balance;
    float deposit;
    float withdraw;
    bool IsFreeze;
    int AccountLimit;
    public:
    int getAccountNum(){
        return AccountNumber;
    }
    float getbalance(){
        return balance;
    }
    int getDeposit(){
        return deposit;
    }
    int getwithdraw(){
        return withdraw;
    }
    void setbalance(float b){
        balance = b;
    }
    void Deposit(float dep){
        balance += dep;
    }
    void Withdraw(float withdrawAmount){
        balance-=withdrawAmount;
    }
    bool getIsFreeze(){
        return IsFreeze;
    }
    void setIsFreeze(bool choice){
        IsFreeze = choice;
    }
    int GetAccLimits(){
        return AccountLimit;
    }
    void setAccLimits(int newlimit){
        AccountLimit = newlimit;
    }

};
class SavingAccount: public BankAccount{
    float interest;
    public:
    void ApplyInterest(float interestAmount){
        interest = getbalance()*5/100; //Charges 5% interest
    }
};
class CheckingAccount: public BankAccount{
    float overdraft = -1000;
    public:
    void Overdraft(){
        if (getbalance()<0&& getbalance()>=overdraft){
            cout<<"Balance is under overdraft limit"<<endl;
        }
        else{
            cout<<"Overdraft limit exceeded"<<endl;
        }
    }
};
class BusinessAccount: public BankAccount{
    float CorporateTax;
    public:
    void CalCorporatetax(){
        CorporateTax = getDeposit()*(13/100); //Corporate Tax is 13%
    }
};
class Customer: public BankAccount{
    public:
    void Callwithdraw(float Amount){
        Withdraw(Amount);
    }
    void CallDeposit(float Amount){
        Deposit(Amount);
    }

};
class Teller: public Employee{
public:
    void Callwithdraw(float Amount){
        if (getIsFreeze() == 0){
            Withdraw(Amount);
        }
    }
    void CallDeposit(float Amount){
        if (getIsFreeze() == 0)
        Deposit(Amount);
    }
    void FreezeAccount(bool choice){
        setIsFreeze(choice);
    }

};
class Manager:public Employee{
    void Callwithdraw(float Amount){
        if (getIsFreeze() == 0){
            Withdraw(Amount);
        }
    }
    void CallDeposit(float Amount){
        if (getIsFreeze() == 0)
        Deposit(Amount);
    }
    void FreezeAccount(bool choice){
        setIsFreeze(choice);
    }
    void Override(int NewValue){
        int originalvalue = GetAccLimits();
    }

};
int main(){
    Manager manager;
    manager.Deposit(1000);
    cout<<manager.getbalance()<<endl;
    manager.setAccLimits(10000);
    cout<<manager.GetAccLimits();
}
