#include "MyString.h"


//Consturctor ----------------------------------------------------------------
MyString::MyString() :CVector() {}
MyString::MyString(const MyString &str) : CVector(str) {}
MyString::MyString(const MyString &str, int pos, int len) : CVector(str.substr(pos, len)) {};
MyString::MyString(const char *s) : CVector(s) {}


//MyString::~MyString()
//{
//}

//Operator ----------------------------------------------------------------
// string + string
MyString MyString::operator+(const MyString& rhs) const {
	MyString tmpstr;
	for (int i = 0; i < this->vsize; i++) {
		tmpstr.push_back(this->sPtr[i]);
	}
	for (int i = 0; i < rhs.vsize; i++) {
		tmpstr.push_back(rhs[i]);
	}
	return tmpstr;
};
// string + char
MyString MyString::operator+(const char* rhs) const {
	MyString tmpstr;
	for (int i = 0; i < this->vsize; i++) {
		tmpstr.push_back(this->sPtr[i]);
	}
	for (int j = 0; j < strlen(rhs); j++) {
		tmpstr.push_back(rhs[j]);
	}
	return tmpstr;
};

//string = char
MyString& MyString::operator=(const char* s) {
	this->vsize = strlen(s);
	for (int i = 0; i < strlen(s); i++) {
		this->sPtr[i] = s[i];
	}
	return *this;
};

MyString operator+(const char* lhs, const MyString& rhs) {
	MyString tmpstr;
	for (int j = 0; j < strlen(lhs); j++) {
		tmpstr.push_back(lhs[j]);
	}
	for (int i = 0; i < rhs.vsize; i++) {
		tmpstr.push_back(rhs.sPtr[i]);
	}
	return tmpstr;
};

//string = char
MyString& MyString::operator=(const MyString& str) {
	for (int i = 0; i < str.vsize; i++) {
		this->sPtr[i] = str.sPtr[i];
	}
	return *this;
};

ostream &operator<<(ostream& output, const MyString& str) {
	//CVector::ostream &operator<<(ostream& output, const MyString& str)
	//output << " vec.size() = " << str.vsize << endl;
	//output << " vec.getCapacity() = " << str.maxsize << endl;
	//output << "you have enter " << str.vsize << "element";
	for (int i = 0; i < str.vsize; i++) {
		output << str.sPtr[i] << " ";
	}

	return output;
};

//------------------------------------------------------------------------
MyString& MyString::append(const MyString &str) {
	for (int i = 0; i < str.vsize; i++) {
		this->push_back(str.sPtr[i]);
	}
	return *this;
};

MyString& MyString::erase(int subpos, int sublen) {
	MyString tmpstr;
	for (int i = 0; i < this->vsize; i++) {
		if (i >= subpos && i <= (subpos + sublen)) {
			continue;
		}
		tmpstr.push_back(this->sPtr[i]);
	}

	this->vsize = tmpstr.vsize;
	for (int i = 0; i < tmpstr.vsize; i++) {
		this->sPtr[i] = tmpstr[i];
	}

	return *this;
};

MyString MyString::substr(size_t pos, size_t len) const {
	MyString tmpstr;
	for (size_t i = pos; i < (pos + len); i++) {
		tmpstr.push_back(this->sPtr[i]);
	}
	return tmpstr;
};


MyString&  MyString::insert(int pos, const MyString &str) {
	MyString tmpstr;
	for (int i = 0; i < this->vsize; i++) {
		if (i == pos) {
			for (size_t j = 0; j < str.vsize; j++) {
				tmpstr.push_back(str.sPtr[j]);
			}
		}
		tmpstr.push_back(this->sPtr[i]);
	}
	this->vsize = tmpstr.vsize;
	for (int i = 0; i < tmpstr.vsize; i++) {
		this->sPtr[i] = tmpstr[i];
	}
	return *this;
};


MyString& MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen) {
	MyString tmpstr(this->substr(subpos, sublen));
	this->insert(pos, tmpstr);
	return *this;
};

//int find(const MyString &str, int pos = 0) const;
int MyString::find(const MyString &str, int pos) const {
	char ch = str[0];
	int position = 0;
	for (int i = 0; i < this->vsize; i++) {
		if (this->sPtr[i] == ch) {
			position = i;
			break;
		}
	}
	if (position == 0) {
		return 0;
	}
	else {
		return position;
	}
};

//cout << "i = " << i ;
//cout << " sPtr[i] = " << sPtr[i] << endl;
//cout << "tmpstr= " << tmpstr << endl;
//cout << "this->vsize" << this->vsize << endl;
//cout << "tmpstr.vsize" << tmpstr.vsize << endl;