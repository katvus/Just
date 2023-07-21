#include <cstddef> // size_t
#include <cstring>
#include<algorithm>
#include <iostream>
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
struct PodStr {
	PodStr(const char* str = "", int ind = 0) {
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str);
		ind_st = ind;
	}
	char* operator[] (int end) const {
		//std::cout << "start " << str << " end" << std::endl;
		char* stroka = new char[end - ind_st + 1];
		for (int i = 0; i < end - ind_st; i++) {
			stroka[i] = str[i];
		}
		stroka[end - ind_st] = '\0';
		//std::cout << "start " << stroka << " end" << std::endl;
		//String a(stroka);
		return stroka;
	}
	PodStr(const PodStr& other) {
		std::cout << "PodStr cop work" << std::endl;
		size = other.size;
		ind_st = other.ind_st;
		str = new char[size + 1];
		for (int i = 0; i < size + 1; i++) {
			this->str[i] = other.str[i];
		}
	}
	//void swap(PodStr& other) {
	//	std::swap(this->size, other.size);
	//	std::swap(str, other.str);
	//}
	//PodStr& operator=(const PodStr& other) {
	//	std::cout << "PodStr = work" << std::endl;
	//	size = other.size;
	//	if (this != &other) {
	//		PodStr(other).swap(*this);
	//	}
	//	return *this;
	//}
	~PodStr() {delete[]str; }
	int ind_st;
	size_t size;
	char* str;
};
//std::cout << "I work"; 
struct String {
	String(const char* str = "") {
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str);
	}
	//String(size_t n, char c);
	~String() {
		delete[]str;
	}
	PodStr operator[] (int start) const {
		char* podstr = new char[size - start + 1];
		for (int i = 0; i < size - start + 1; i++) {
			podstr[i] = str[start + i];
		}
		PodStr a(podstr, start);
		delete[] podstr;
		return a;
	}
	//String(const String& other) {
	//	std::cout << "String cop work"<< std::endl;
	//	size = other.size;
	//	str = new char[size + 1];
	//	for (int i = 0; i < size + 1; i++) {
	//		this->str[i] = other.str[i];
	//	}
	//}
	void swap(String& other) {
		std::swap(this->size, other.size);
		std::swap(str, other.str);
	}

	/* Реализуйте конструктор копирования */
	String& operator=(const String& other) {
		std::cout<<"String = work" << std::endl;
		size = other.size;
		if (this != &other) {
			String(other).swap(*this);
		}
		return *this;
	}

	//void append(const String& other);

	size_t size;
	char* str;
};

int main()
{
	{
		String const hello("hello");
		/*char*a = hello[0][4];
		delete[] a;*/
		//String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
		//String const ell = hello[1][4]; // теперь в ell хранится подстрока "ell"
		//_CrtDumpMemoryLeaks();
		//std::cout << hell.str;
	}
	std::cout << " all" << std::endl;
	_CrtDumpMemoryLeaks();
    return 0;
}