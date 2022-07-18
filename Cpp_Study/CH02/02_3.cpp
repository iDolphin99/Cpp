#include <iostream>

using namespace std;

typedef struct __Point
{
	int xPos, yPos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point *sumP = new Point; 

	sumP->xPos = p1.xPos + p2.xPos;
	sumP->yPos = p1.yPos + p2.yPos;
	
	// �Լ� ���� ����� ������ ���������� ��ȯ�Ϸ��� �ش� ������ ��� �����ؾ� �ϴ°�? 
	return *sumP;
}

int main(void)
{
	Point *p1 = new Point;
	p1->xPos = 10; 
	p1->yPos = 20;

	Point* p2 = new Point;
	p2->xPos = 1;
	p2->yPos = 2;

	// �����Ҵ� �� ������ �Լ��� ������ �Ű������� ���ڷ� ��� �����ؾ� �ϴ°�? 
	Point& p3 = PntAdder(*p1, *p2);

	cout << "x: " << p3.xPos << ", y: " << p3.yPos;

	delete p1;
	delete p2;
	delete& p3;
	
	return 0;
}