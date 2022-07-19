#include <iostream>
#include <cstring>
using namespace std;

class Book {
private : 
	char* title;
	char* isbn;
	int price;
public : 
	Book(const char *btitle, const char * bisbn, int bprice) : price(bprice) {
		title = new char[strlen(btitle) + 1];
		isbn = new char[strlen(bisbn) + 1];
		strcpy_s(title, strlen(btitle) + 1, btitle);
		strcpy_s(isbn, strlen(bisbn) + 1, bisbn);
	}
	void ShowBookInfo() {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book() {
		delete[] title, isbn;
	}
};

class EBook : public Book {
private : 
	char* DRMKey;
public :
	EBook(const char* btitle, const char* bisbn, int bprice, const char* eDRMKey)
		: Book(btitle, bisbn, bprice) 
	{
		DRMKey = new char[strlen(eDRMKey) + 1];
		strcpy_s(DRMKey, strlen(eDRMKey) + 1, eDRMKey);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey;
	}
	~EBook() {
		delete[] DRMKey;
	}
};

int main() {
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}