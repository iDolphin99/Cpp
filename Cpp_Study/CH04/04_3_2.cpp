#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum{
		CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos)
	{
		switch (pos){
		case CLERK: cout << "���" << endl;	  break;
		case SENIOR: cout << "����" << endl;  break;
		case ASSIST: cout << "�븮" << endl;  break; 
		case MANAGER: cout << "����" << endl; break; 
		}
	}
}

class NameCard
{
private :
	int position;
	char* name;
	char* company;
	char* tel;
public :
	NameCard(const char *n, const char *c, const char *t, int pos)
		:position(pos)
	{
		int cLen = strlen(c) + 1;
		int tLen = strlen(t) + 1;

		name = new char[strlen(n) + 1];
		company = new char[cLen];
		tel = new char[tLen];
		
		strcpy_s(name, strlen(n) + 1, n);
		strcpy_s(company, cLen, c);
		strcpy_s(tel, tLen, t);
	}
	void ShowNameCardInfo() 
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << tel << endl;
		cout << "����: "; COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]tel;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	manClerk.ShowNameCardInfo();
	NameCard manAssist("Hong", "OrangeEng", "010-3333-4444", COMP_POS::ASSIST);
	manAssist.ShowNameCardInfo();

	return 0; 
}