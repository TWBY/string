
#include <iostream>
using namespace std;

class CVector {
	friend ostream &operator<<(ostream&, const CVector&);
public:
	CVector();
	CVector(const char*);
	CVector(const CVector&); //copt constructor
	~CVector();

	int getSize(); //回傳 size 大小
	int getCapacity() const; //回傳 getCapacity 大小;

	void resize(int, char);  // Q: 為何需要 char? ???????? ， n > 背包大小。將背包調正到 n，並將多餘的刪除掉， n < 背包大小。把背包調正到 n,新增多的空格
	void reserve(int);  // 事先拿比較大的包包
	void shrink_to_fit();  // 背包大小改至物件容量
	void clear();  //清除所有物

	char& front(); //回傳第一個值字元的 referance
	char& back();  //回傳最後一個值字元的 referance(注意:非最後一個的後一個)

	void push_back(char);  // 增加字元放在 array 最後一個
	void pop_back();  //拿出字元

	char& operator[](int pos); // 存取第 i 個元素的值 array[i]
	char operator[] (int pos) const; //存取第 i 個元素的值 array[i]
	bool operator==(const CVector &str) const;  //assign operator
	bool operator!=(const CVector &str) const;


protected:
	int vsize; // 實際放的大小
	int maxsize; //背包的大小
	char* sPtr;
	void alloc_new(); // 要求新的空間
};