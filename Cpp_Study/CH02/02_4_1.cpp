/*
char *str1 = "ABC 123";
>>> Error : C++ ������ ���� ����Ͽ� ������ ����Ƽ�� �ʱ�ȭ�� �� �����ϴ�.
>>> Why? : VS2017���� �����ϰ� ǥ�� ������ ���� �����ϴ� permissive �ɼ��� �⺻������ Ȱ��ȭ�Ǿ� �ִ�.
>>> Solution : ���� �������� ǥ���� �����ϴ� ����� ������ -> ������Ʈ �Ӽ� -> �ؼ� ��� -> �ƴϿ� 
>>> Solution : ǥ�� ������ ������ ������ -> const Ű���� �߰� or string ���� ��� 
*/
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const char *str1 = "ABC 123";
	const char *str2 = "EFG 456";
	char str3[50];

	// ���ڿ� ���� ���
	cout << "strlen: " << strlen(str1) << endl;
	// ���ڿ� ����
	strcpy_s(str3, str1);
	cout << "strcpy: " << str3 << endl;
	// ���ڿ� �ڿ� �����̱�
	strcat_s(str3, str2);
	cout << "strcat: " << str3 << endl;
	// ���ڿ� ��, ������ 0 �ٸ��� 1 
	if (strcmp(str3, str1)) cout << "�ٸ� ���ڿ��Դϴ�" << endl;
	else					cout << "���� ���ڿ��Դϴ�" << endl;

	return 0;
}