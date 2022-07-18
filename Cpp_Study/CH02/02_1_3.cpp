#include <iostream>

using namespace std;

void SwapPointer(int* (&ptr1), int* (&ptr2)) 
{
	int *temp = ptr1; 
	ptr1 = ptr2;
	ptr2 = temp;
}
// temp(&�ּ�, ptr1=num1�ּ�)
// ptr1(&�ּ�, num1�ּ�) 
// ptr2(&�ּ�, num2�ּ�) 
int main(void) 
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2; 

	cout << "original value of ptr1 : " << *ptr1 << ", ptr2 : " << *ptr2 << endl;
	SwapPointer(ptr1, ptr2);
	cout << "After SwapPointer function, value of ptr1 : " << *ptr1 << ", ptr2 : " << *ptr2 << endl;

	return 0;
}