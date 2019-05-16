#include <iostream>
#include "CVector.h"
using namespace std;

class MyString : public CVector
{
	friend ostream &operator<<(ostream& output, const MyString& str);

public:
	MyString();
	MyString(const MyString &str);
	MyString(const MyString &str, int pos, int len = msize);
	MyString(const char *s);

	
	//~MyString();
	static const size_t msize = 999;
	////Note: maximum size.
	MyString& append(const MyString &str);
	MyString substr(size_t pos = 0, size_t len = msize) const;
	MyString& insert(int pos, const MyString &str);
	MyString& insert(size_t pos, const MyString &str, size_t subpos, size_t sublen);
	MyString& erase(int subpos, int sublen);
	int find(const MyString &str, int pos = 0) const;
	//size_t find_first_of(const MyString &str, size_t pos = 0) const;
	//
	////Add several operators
	MyString operator+ (const MyString& rhs) const;
	MyString operator+ (const char* rhs) const;
	friend MyString operator+ (const char* lhs, const MyString& rhs);
	MyString& operator= (const MyString& str);
	MyString& operator= (const char* s);

}; // end class MyString