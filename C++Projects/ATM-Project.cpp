#include<iostream>
using namespace std;
class BankAccount{
	private:
	int accountNumber;
    string accountHolder;
    int balance;
    public:
    BankAccount(int accountno,string name,int bal){
        accountNumber=accountno;
		accountHolder=name;
		balance=bal;		
	}
	int getaccountnumber(){
		return accountNumber;
	}
	string getaccountholder(){
		return accountHolder;
	}
	int getbalance(){
		return balance;
	}
	void depositbalance(){
		int deposit,count=0;
		cout<<"Enter the amount you want to deposit: ";
		cin>>deposit;
		balance=balance+deposit;
}
	void withdrawamount(){
		int withdraw;
		cout<<"Enter the amount you want to withdraw: ";
		cin>>withdraw;
		if(withdraw>balance){
			cout<<"not possible"<<endl;
		}
		else{
			cout<<"Succesfully withdraw";
			balance=balance-withdraw;
		}
	}
	void checkbalance(){
		cout<<"Your balance is : "<<balance<<endl;
	}
	~BankAccount(){
		cout<<"Objects are released "<<endl;
	}
};
int main (){
	int accountno,bal,n=2345,choice;
	string name;
	cout<<"Enter the value of account number: ";
	cin>>accountno;
	cout<<"Enter the name of account holder: ";
	cin>>name;
	cout<<"Enter the balance: ";
	cin>>bal;
	BankAccount B1(accountno,name,bal);
	cout<<"Displaying information of account holder: "<<endl;
	cout<<"The value of account number is : "<<B1.getaccountnumber()<<endl;
	cout<<"The name of account holder is: "<<B1.getaccountholder()<<endl;
	cout<<"The balance of the account holder is : "<<B1.getbalance()<<endl;
	while(choice!=4){
		cout<<"Please select the following choice: "<<endl;
		cout<<"1.Deposit\n2.Withdraw\n3.Check Balance\n4.Exit"<<endl;
		cout<<"Option: ";
		cin>>choice;
		if(choice==1){
			B1.depositbalance();
		}
		else if(choice==2){
			B1.withdrawamount();
		}
		else if(choice==3){
			B1.checkbalance();
		}
		else
		break;	
	}
}
