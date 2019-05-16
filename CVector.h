
#include <iostream>
using namespace std;

class CVector {
	friend ostream &operator<<(ostream&, const CVector&);
public:
	CVector();
	CVector(const char*);
	CVector(const CVector&); //copt constructor
	~CVector();

	int getSize(); //�^�� size �j�p
	int getCapacity() const; //�^�� getCapacity �j�p;

	void resize(int, char);  // Q: ����ݭn char? ???????? �A n > �I�]�j�p�C�N�I�]�ե��� n�A�ñN�h�l���R�����A n < �I�]�j�p�C��I�]�ե��� n,�s�W�h���Ů�
	void reserve(int);  // �ƥ�������j���]�]
	void shrink_to_fit();  // �I�]�j�p��ܪ���e�q
	void clear();  //�M���Ҧ���

	char& front(); //�^�ǲĤ@�ӭȦr���� referance
	char& back();  //�^�ǳ̫�@�ӭȦr���� referance(�`�N:�D�̫�@�Ӫ���@��)

	void push_back(char);  // �W�[�r����b array �̫�@��
	void pop_back();  //���X�r��

	char& operator[](int pos); // �s���� i �Ӥ������� array[i]
	char operator[] (int pos) const; //�s���� i �Ӥ������� array[i]
	bool operator==(const CVector &str) const;  //assign operator
	bool operator!=(const CVector &str) const;


protected:
	int vsize; // ��ک񪺤j�p
	int maxsize; //�I�]���j�p
	char* sPtr;
	void alloc_new(); // �n�D�s���Ŷ�
};