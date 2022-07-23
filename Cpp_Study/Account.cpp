/*
Ver 0.7
- file division
*/

#include "BankingCommonDecl.h"
#include "Account.h"



Account::Account(const char* n, int id, int b) : ID(id), balance(b)	   // default constructor 
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Account::Account(const Account& ref) : ID(ref.ID), balance(ref.balance) // copy constructor 
{
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);
}
int Account::GetAccID() { return ID; };
int Account::GetBalance() { return balance; };
void Account::Withdraw(int money)
{
	if (balance < money)
		cout << "�ܾ׺���";
	else {
		balance -= money;
		cout << "��� �Ϸ�";
	}
};
void Account::Deposit(int money) { balance += money; };
void Account::ShowAccInfo() const
{
	cout << "����ID: " << ID << "\n";
	cout << "��  ��: " << name << "\n";
	cout << "�Աݾ�: " << balance << "\n";
};
Account::~Account()
	{
		delete this->name;
		cout << "called Account destructor!" << "\n";
	};