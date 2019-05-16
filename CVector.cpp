#include "CVector.h"



//constructor------------------------------------------------------------------
CVector::CVector() {
	maxsize = 20;
	sPtr = new char[maxsize]; //array int���Ы��V�o�� new �X�Ӫ��Ŷ�
	vsize = 0; //�٥��o����󪺤����A�ҥH�]�w�� 0
}

CVector::CVector(const char* s) {
	maxsize = 20;
	sPtr = new char[maxsize]; //array int���Ы��V�o�� new �X�Ӫ��Ŷ�
	vsize = 0; //�٥��o����󪺤����A�ҥH�]�w�� 0

	for (int i = 0; i < 999; i++) {
		if (s[i] == '\0') {
			break;
		}
		this->push_back(s[i]);
	}
}

CVector::CVector(const CVector& v) {
	if (this != &v) {
		maxsize = v.maxsize;
		vsize = v.vsize;
		sPtr = new char[maxsize];

		for (int i = 0; i < v.vsize; i++) {
			sPtr[i] = v.sPtr[i];
		}
	}
}
CVector::~CVector() {
	delete[] sPtr;
}

// size / getCapacity   --------------------------------------------------------------
int CVector::getSize() {
	return vsize;

}
int CVector::getCapacity() const {
	return maxsize;

}
// resize / reserve / shrink_to_fit / clear  -------------------------------------------------------------
void CVector::resize(int n, char c = '\0') {
	if (n > maxsize) {
		maxsize = n;
	}
	if (n < maxsize) {
		maxsize = n;
		vsize = n;
	}

}
void CVector::reserve(int n = 0) {
	maxsize = n;
	sPtr = new char[maxsize]; //array int���Ы��V�o�� new �X�Ӫ��Ŷ�
	vsize = 0; //�٥��o����󪺤����A�ҥH�]�w�� 0
}

void CVector::shrink_to_fit() {
	maxsize = vsize;
};

void CVector::clear() {
	vsize = 0;
};

// front / back �i�H���o�ȡA���O�p����o�a�}???  ---------------------------------------------------
char& CVector::front() {
	return sPtr[0];
}
char& CVector::back() {
	return sPtr[this->vsize - 1];
}

// push_back /  pop_back()  ---------------------------------------------------
void CVector::push_back(char ch) {
	//���T�{�I�]�O�_�٦��Ŷ�
	if (vsize + 1 > maxsize) {
		alloc_new();
	}
	else {
		sPtr[vsize] = ch;
		vsize++;
	}
}
void CVector::pop_back() {
	vsize--;

}

//operator overloading  -------------------------------------------------------------------------
char& CVector::operator[](int i) {
	return sPtr[i];
}

char CVector::operator[](int i) const {
	return sPtr[i];
}
bool CVector::operator==(const CVector &str) const {
	bool flag = true;
	for (int i = 0; i < this->vsize; i++) {
		if (this->sPtr[i] != str.sPtr[i]) {
			flag = false;
		}
	}
	return flag;
};
bool CVector::operator!=(const CVector &str) const {
	bool flag = false;
	for (int i = 0; i < this->vsize; i++) {
		if (this->sPtr[i] != str.sPtr[i]) {
			flag = true;
		}
	}
	return flag;
};


//alloc_new() -------------------------------------------
void CVector::alloc_new() {
	//��ثe���j�p�ܦ��{�b���⭿ 
	maxsize = vsize * 2;
	//new �@�ӷs���}�C�A�N�°}�C���\��L�h�A�ñN�즳���}�C�R��
	char* tmp = new char[maxsize];
	for (int i = 0; i < vsize; i++) {
		tmp[i] = sPtr[i];
	}
	delete[] sPtr; //�쥻�ҫ��� a
	sPtr = tmp;
}

//friend cout opreator
ostream &operator<<(ostream& output, const CVector& vec) {
	//output << " vec.size() = " << vec.vsize << endl;
	//output << " vec.getCapacity() = " << vec.maxsize << endl;
	//output << "you have enter " << vec.vsize << "element";

	//output << " element ! Here is = ";
	//for (int i = 0; i < vec.vsize; i++) {
	//	output << vec.sPtr[i] << " ";
	//}
	// vec.sPtr[i] (O)
	// vec.[i] (X)
	return output;
}