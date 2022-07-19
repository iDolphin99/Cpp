/*
Banking System Ver 0.3
* add Deep Copy Constructor
* adjust object pointer array (��ü ������ �迭)
*/

#include <iostream>
#include <cstring>

using namespace std;
const int MAX_ACCNUM = 100;
const int NAME_LEN = 20;

class Account {
private:
	char* name;
	int ID;
	int balance = 0;
public:
	Account(const char* n, int id, int b) : ID(id), balance(b)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Account(const Account& ref) : ID(ref.ID), balance(ref.balance)
	{
		name = new char[strlen(ref.name) + 1];
		strcpy_s(name, strlen(ref.name) + 1, ref.name);
	}
	int GetAccID() { return ID; }
	void Deposit(int b)
	{
		balance += b;
	}
	void Withdraw(int b)
	{
		if (balance < b)
			cout << "�ܾ׺��� \n\n\n";
		else {
			balance -= b;
			cout << "��� �Ϸ� \n\n";
		}
	}
	void ShowAccInfo()
	{
		cout << "����ID: " << ID << "\n";
		cout << "��  ��: " << name << "\n";
		cout << "�Աݾ�: " << balance << "\n\n";
	}
	~Account()
	{
		delete this->name;
		cout << "called destructor!" << endl;
	}
};

class AccountHandler {
private:
	int AccNum;
	Account* pArr[MAX_ACCNUM];
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};

AccountHandler::AccountHandler() : AccNum(0) {};
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccNum; i++)  // Noted! not size(pArr)
		delete pArr[i];
}
void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----\n";
	cout << "1. ���°��� \n";
	cout << "2. ��    �� \n";
	cout << "3. ��    �� \n";
	cout << "4. �������� ��ü ��� \n";
	cout << "5. ���α׷� ���� \n";
	cout << "����: ";
}
void AccountHandler::MakeAccount(void) {
	char name[NAME_LEN];
	int ID, balance;

	cout << "\n\n[���°���] \n";
	cout << "����ID: ";
	cin >> ID;
	cout << "��  ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "\n\n";

	pArr[AccNum] = new Account(name, ID, balance);
	AccNum += 1;
}
void AccountHandler::DepositMoney(void) {
	int keyID, keyBalance;

	cout << "\n\n[��   ��] \n";
	cout << "����ID: ";
	cin >> keyID;
	cout << "�Աݾ�: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			(pArr[i]->Deposit(keyBalance));
			cout << "�ԱݿϷ� \n\n\n";
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�. \n\n\n";
}
void AccountHandler::WithdrawMoney(void) {
	int keyID, keyBalance;

	cout << "\n\n[��   ��] \n";
	cout << "����ID: ";
	cin >> keyID;
	cout << "�Աݾ�: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			pArr[i]->Withdraw(keyBalance);
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�. \n\n\n";
}
void AccountHandler::ShowAllAccInfo() const {
	cout << "\n\n";

	for (int i = 0; i < AccNum; i++)
		pArr[i]->ShowAccInfo();

	cout << "\n";
}


int main(void) {
	AccountHandler manager;
	int op;

	while (true) {
		manager.ShowMenu();
		cin >> op;

		switch (op) {
		case 1: manager.MakeAccount();		break;
		case 2: manager.DepositMoney();		break;
		case 3: manager.WithdrawMoney();	break;
		case 4: manager.ShowAllAccInfo();   break;
		case 5: return 0;				    break;
		default: cout << "Illegal selection.. \n\n"; break;
		}
	}
}