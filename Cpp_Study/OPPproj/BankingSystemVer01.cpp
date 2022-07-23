#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

typedef struct _account {
	char name[NAME_LEN];
	int ID, balance = 0;
}ACCOUNT;

int MakeAccount(int count, ACCOUNT* pArr);
void Deposit(int count, ACCOUNT* pArr);
void Withdraw(int count, ACCOUNT* pArr);
void ShowAllAccInfo(int count, ACCOUNT* pArr);

int main(void) {
	int op, count = 0;
	ACCOUNT account[20];
	ACCOUNT* pArr = account;

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
		case 1: count = MakeAccount(count, pArr);	break;
		case 2: Deposit(count, pArr);				break;
		case 3: Withdraw(count, pArr);				break;
		case 4: ShowAllAccInfo(count, pArr);		break;
		case 5: return 0; break;
		default: cout << "Illegal selection.. \n\n"; break;
		}
	}

	free(pArr);

	return 0;
}

int MakeAccount(int count, ACCOUNT* pArr) {
	cout << "\n\n[���°���] \n";
	cout << "����ID: ";
	cin >> (pArr + count)->ID;
	cout << "��  ��: ";
	cin >> (pArr + count)->name;
	cout << "�Աݾ�: ";
	cin >> (pArr + count)->balance;
	cout << "\n\n";

	return count + 1;
}
void Deposit(int count, ACCOUNT* pArr) {
	int keyID, keyBalance;

	cout << "\n\n[��   ��] \n";
	cout << "����ID: ";
	cin >> keyID;
	cout << "�Աݾ�: ";
	cin >> keyBalance;

	for (int i = 0; i < count; i++) {
		if (((pArr + i)->ID) == keyID) {
			((pArr + i)->balance) += keyBalance;
			cout << "�ԱݿϷ� \n\n\n";
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�. \n\n\n";
}
void Withdraw(int count, ACCOUNT* pArr) {
	int keyID, keyBalance;

	cout << "\n\n[��   ��] \n";
	cout << "����ID: ";
	cin >> keyID;
	cout << "�Աݾ�: ";
	cin >> keyBalance;

	for (int i = 0; i < count; i++) {
		if (((pArr + i)->ID) == keyID) {
			if (((pArr + i)->balance) < 0) {
				cout << "�ܾ׺��� \n\n\n";
				return;}
			((pArr + i)->balance) -= keyBalance;
			cout << "��ݿϷ� \n\n\n";
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�. \n\n\n";
}
void ShowAllAccInfo(int count, ACCOUNT* pArr) {
	cout << "\n\n";
	
	for (int i = 0; i < count; i++) {
		cout << "����ID: " << (pArr + i) -> ID << "\n";
		cout << "��  ��: " << (pArr + i)->name << "\n";
		cout << "�Աݾ�: " << (pArr + i)->balance<< "\n\n";
	}
	
	cout << "\n";
}