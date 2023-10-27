#include<iostream>
#include<string>
using namespace std;

class ATM_BaseClass
{
protected:
	int ATM_PIN;
	int balance;
	int withdraw;
	int credit;

public:
	ATM_BaseClass()
	{
		ATM_PIN = 0;
		balance = 0;
		withdraw = 0;
		credit = 0;

	}
	ATM_BaseClass(int ATM_PIN, int balance, int withdraw, int credit)
	{
		this->ATM_PIN = ATM_PIN;
		this->balance = balance;
		this->withdraw = withdraw;
		this->credit = credit;

	}
	void SetATM_BaseClass(int ATM_PIN)
	{
		this->ATM_PIN = ATM_PIN;

	}
	void SetBalance(int balance)
	{
		this->balance = balance;
	}
	void SetCredit(int credit)
	{
		this->credit = credit;
	}

	int GetATM_BaseClassNumber()
	{
		return ATM_PIN;
	}
	int GetBalance()
	{
		return balance;
	}
	int Getcredit()
	{
		return credit;
	}

	virtual void display() = 0;		//Pure virtual function with no function body
};

class InputData : public ATM_BaseClass
{
public:
	InputData()
	{
		

	}
	InputData (int ATM_PIN, int balance)
	{
		this->ATM_PIN = ATM_PIN;
		this->balance = balance;
	}
	void SetATM_PIN()
	{
		cout << "\t Enter your 4 digits PIN: ";
		cin >> ATM_PIN;

	}
	void SetBalance()
	{
		cout << "\t Enter your current balance:  ";
		cin >> balance;
		cout << endl;
	}
	int GetATM_PIN()
	{
		return ATM_PIN;
	}
	int GetBalance()
	{
		return balance;
	}

};

class Credit : public ATM_BaseClass
{
public:
	virtual void display()
	{
		cout << "\tEnter Amount to be Credited: ";
		cin >> credit;
		balance = balance + credit;
		system("cls");
		cout << "\n\t <<-- Your new balance is: " << balance << " -->>" << endl;
	}
};

class Debit : public ATM_BaseClass
{
public:
	void display()
	{
		int confirm;
		cout << "\t Enter Amount to be Withdrawl: ";
		cin >> withdraw;

		cout << "\t << CONFIRMATION MESSAGE >>\n\n";
		cout << "\t   1- Confirm Withdraw \n";
		cout << "\t   0- Cancel Withdraw \n\n";
		cout << "\t YOUR CHOICE:  ";
		cin >> confirm;

		if (confirm == 1)
		{

			if (balance >= withdraw)
			{
				system("cls");
				balance = balance - withdraw;
				cout << "\n\t <<-- Your Remaining balance is: " << balance << " -->>" << endl;
			}
			else
			{
				system("cls");
				cout << "\n\t <<-- Withdrawl amount is exceding your available balance! -->>";
			}

		}
		if (confirm == 0)
		{
			system("cls");
			cout << "\n\t<< Thank You >>\n";
		}
	}

};

class Balance_Inquiry : public ATM_BaseClass
{
public:
	void display()
	{
		system("cls");
		cout << "\n\t <<-- Your NET BALANCE is " << balance << " -->>" << endl;
	}
};

class Bills_Payments : public ATM_BaseClass
{
public:
	void display()
	{
		system("cls");
		int comp;
		cout << "\n\t\t <<-- Billing Compnies -->> \n";
		cout << "\n\t 1- WAPDA \n\t 2- SUI GASS \n\t 3- PTCL \n";
		cout << "Your desired Compny: ";
		cin >> comp;

		if (comp == 1)
		{
			system("cls");
			cout << "\n\t\t <<--- FATA Bank ATM ---->> \n\n";
			int ref, payable;
			cout << "\t Enter WAPDA referance number: ";
			cin >> ref;

			cout << "\t Enter your Payable bill: ";
			cin >> payable;

			balance = balance - payable;
			system("cls");
			cout << "\n\t Balance after Paid Bill: " << balance;
			cout << endl;
		}
		if (comp == 2)
		{
			system("cls");
			cout << "\n\t\t <<--- FATA Bank ATM ---->> \n\n";
			int ref, payable;
			cout << "\t Enter SUI GASS referance number: ";
			cin >> ref;

			cout << "\t Enter your Payable bill: ";
			cin >> payable;

			balance = balance - payable;
			system("cls");
			cout << "\n\t Balance after Paid Bill: " << balance;
			cout << endl;
		}
		if (comp == 3)
		{
			system("cls");
			cout << "\n\t\t <<--- FATA Bank ATM ---->> \n\n";
			int ref, payable;
			cout << "\t Enter PTCL referance number: ";
			cin >> ref;

			cout << "\t Enter your Payable bill: ";
			cin >> payable;

			balance = balance - payable;
			system("cls");
			cout << "\n\t Balance after Paid Bill: " << balance;
			cout << endl;
		}
	}
};

class PIN_Reset : public ATM_BaseClass
{
public:
	void display()
	{
		system("cls");
		int NEW_PIN;
		cout << "\t Please enter your Old PIN: ";
		cin >> ATM_PIN;
		cout << "\t Please enter your New PIN: ";
		cin >> NEW_PIN;

		if (ATM_PIN == NEW_PIN)
		{
			system("cls");
			cout << "\n\t <--- SAME PIN entered ---> \n\n";

		}
		else
		{
			system("cls");
			ATM_PIN = NEW_PIN;
			cout << "\n\t <--- PIN CHANGED successfully! ---> \n\n";
		}
	}
};

int main()
{

	int i = 0;
	while (i < 4)
	{
		{
			while (1)   //Infinite loop , use 1 inside the while condition 
			{

				cout << "\n\t\t <<--- FATA Bank ATM ---->> \n\n";


				int choice;
				cout << "\n -- MAIN MENU -- ";

				cout << "\n\n\t 1. Credit \n\t 2. Withdraw \n\t";
				cout << " 3. Balance Inquiery \n\t 4. Bills Payments \n\t 5. PIN Reset \n\t 6. Quite";
				cout << "\n\n Enter the choice: ";
				cin >> choice;
				cout << "\n";


				if (choice == 1)
				{
					Credit cre;
					cre.display();

				}


				if (choice == 2)
				{
					Debit deb;
					deb.display();

				}


				if (choice == 3)
				{
					Balance_Inquiry RemBal;
					RemBal.display();

				}


				if (choice == 4)
				{
					Bills_Payments BillPay;
					BillPay.display();
				}


				if (choice == 5)
				{
					PIN_Reset PinRe;
					PinRe.display();

				}

				if (choice == 3)
				{
					break;

				}
			}
		}
	}
	return 0;
}
