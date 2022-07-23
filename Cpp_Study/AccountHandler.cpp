/*
Ver 0.7
- file division
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : AccNum(0) {};
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccNum; i++)  // Noted! not size(pArr)
		delete pArr[i];
}
void AccountHandler::ShowMenu(void) const
{
	cout << "\n\n-----Menu-----\n";
	cout << "1. ���°��� \n";
	cout << "2. ��    �� \n";
	cout << "3. ��    �� \n";
	cout << "4. �������� ��ü ��� \n";
	cout << "5. ���α׷� ���� \n";
	cout << "����: ";
}
void AccountHandler::MakeAccount(void) {
	int op;

	cout << "[������������] \n";
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ��� \n";
	cout << "����: ";
	cin >> op;

	if (op == 1)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}
void AccountHandler::MakeNormalAccount(void) {
	char name[NAME_LEN];
	int ID, balance, rate;

	cout << "[���뿹�ݰ���] \n";
	cout << "����ID: ";
	cin >> ID;
	cout << "��  ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> rate;

	pArr[AccNum] = new NormalAccount(name, ID, balance, rate);
	AccNum++;
}
void AccountHandler::MakeCreditAccount(void) {
	char name[NAME_LEN];
	int ID, balance, rate, rank;

	cout << "[�ſ�ŷڰ���] \n";
	cout << "����ID: ";
	cin >> ID;
	cout << "��  ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> rate;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
	cin >> rank;

	pArr[AccNum] = new HighCreditAccount(name, ID, balance, rate, rank);
	AccNum++;
}
void AccountHandler::DepositMoney(void) {
	int keyID, keyBalance;

	cout << "[��   ��] \n";
	cout << "����ID: ";
	cin >> keyID;
	cout << "�Աݾ�: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			(pArr[i]->Deposit(keyBalance));
			cout << "�ԱݿϷ�\n";
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�.\n";
}
void AccountHandler::WithdrawMoney(void) {
	int keyID, keyBalance;

	cout << "[��   ��] \n";
	cout << "����ID: ";
	cin >> keyID;
	cout << "��ݾ�: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			pArr[i]->Withdraw(keyBalance);
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�.";
}
void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < AccNum; i++) {
		pArr[i]->ShowAccInfo();
		cout << "\n";
	}
}