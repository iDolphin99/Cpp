/*
Banking System Ver 0.4
* add const keyword 
* declare all member functions that can be editted as const
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
	int GetAccID() const { return ID; }
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
	void ShowAccInfo() const
	{
		cout << "����ID: " << ID << "\n";
		cout << "��  ��: " << name << "\n";
		cout << "�Աݾ�: " << balance << "\n\n";
	}
	~Account()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

void MakeAccount();
void Deposit();
void Withdraw();
void ShowAllAccInfo();

int AccNum = 0;
Account* pArr[MAX_ACCNUM];

int main(void) {
	int op;

	while (true) {
		cout << "-----Menu-----\n";
		cout << "1. ���°��� \n";
		cout << "2. ��    �� \n";
		cout << "3. ��    �� \n";
		cout << "4. �������� ��ü ��� \n";
		cout << "5. ���α׷� ���� \n";
		cout << "����: ";
		cin >> op;

		switch (op) {
		case 1: MakeAccount();			break;
		case 2: Deposit();				break;
		case 3: Withdraw();				break;
		case 4: ShowAllAccInfo();		break;
		case 5: return 0;				break;
		default: cout << "Illegal selection.. \n\n"; break;
		}
	}

	free(pArr);

	return 0;
}

void MakeAccount() {
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
void Deposit() {
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
void Withdraw() {
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
void ShowAllAccInfo() {
	cout << "\n\n";

	for (int i = 0; i < AccNum; i++)
		pArr[i]->ShowAccInfo();

	cout << "\n";
}