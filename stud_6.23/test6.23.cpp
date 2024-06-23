#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

//template<class T>
//
//T Add(T& a, T& b)//����ģ��
//{
//	return a + b;
//}
//template<class T>
//class Stack//��ģ��
//{
//public:
//	
//	Stack(T* _a = nullptr, int _size = 0, int _capacity = 0)//ȱʡֵ
//		:_a (nullptr)
//		, _size(0)
//		, _capacity (0)
//	{
//		cout << "Stack()" << endl;
//	}
//
//private:
//	T* _a;
//	int _size;
//	int _capacity;
//};

template<class T>
class vector
{
private:
	T* _a;
	size_t _size;
	size_t _capacity;

public:
	vector()
		:_a(nullptr)
		, _size(0)
		, _capacity(0)
	{}
	~vector()
	{
		delete[] _a;
		_a = nullptr;
		_size = _capacity = 0;
	}
	void push_back(const T& x);

	size_t size()
	{
		return _size;
	}
	T& operator[](size_t i)//���ô�����ֵ ��������������ÿ��Ը����ֵ ��Ϊ�����Ǳ���
	{
		assert(i < _size);
			return _a[i];
	}

};

template<class T>
void vector<T>::push_back(const T& x)
{
	if (_size == _capacity)
	{
		size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
		T* tmp = new T[newcapacity];
		if (_a)
		{
			memcpy(tmp,_a,sizeof(T)*_size);//�������ݿ�������
			delete[] _a;

		}
		_a = tmp;
		_capacity = newcapacity;

	}
	_a[_size] = x;
	++_size;

}

int main()
{
	/*int a = 0;
	int b = 2;
	cout << Add(a, b) << endl;
	double c = 2.5;
	double d = 2;
	cout << Add(c, d) << endl;
	Stack<int> st1;
	Stack<double> st2;*/
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i]*=3;
	}
	cout << endl;

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	string s1;
	string s2("hello");
	string s3(s2);
	string s4(10, 'a');
	string s5("12345");
	string s6=s5 + "1111111";



	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4<< endl;
	cout << s5 << endl;
	cout << s6 << endl;
	int val = 1;
	for (size_t i = 0; i < s5.size(); ++i)
	{
		val *= 10;
		val +=(s5[i] - '0');
	}
	cout << val << endl;


	return 0;
}

//#include <iostream>
//#include <stdexcept> // Ϊ��ʹ�� std::out_of_range �쳣
//
//template<class T>
//class Stack {
//private:
//    T* elements; // Ԫ������
//    int capacity; // ��������
//    int topIndex; // ָ��ջ��Ԫ�ص�����
//
//public:
//    // ���캯��
//    Stack(int capacity = 10) : capacity(capacity), topIndex(-1) {
//        elements = new T[capacity];
//    }
//
//    // ��������
//    ~Stack() {
//        delete[] elements;
//    }
//
//    // ѹ��Ԫ��
//    void push(const T& element) {
//        if (topIndex >= capacity - 1) {
//            // ջ�������׳��쳣���������
//            throw std::out_of_range("Stack<>::push(): stack is full");
//        }
//        elements[++topIndex] = element;
//    }
//
//    // ����Ԫ��
//    T pop() {
//        if (isEmpty()) {
//            // ջΪ�գ��׳��쳣
//            throw std::out_of_range("Stack<>::pop(): stack is empty");
//        }
//        return elements[topIndex--];
//    }
//
//    // ����ջ��Ԫ��
//    T top() const {
//        if (isEmpty()) {
//            // ջΪ�գ��׳��쳣
//            throw std::out_of_range("Stack<>::top(): stack is empty");
//        }
//        return elements[topIndex];
//    }
//
//    // ���ջ�Ƿ�Ϊ��
//    bool isEmpty() const {
//        return topIndex == -1;
//    }
//};
//
//int main() {
//    Stack<int> intStack(5); // ����һ������Ϊ5��int���͵�ջ
//
//    // ѹ��һЩԪ��
//    intStack.push(1);
//    intStack.push(2);
//    intStack.push(3);
//
//    // ��������ӡÿ��Ԫ��
//    while (!intStack.isEmpty()) {
//        std::cout << intStack.pop() << std::endl;
//    }
//
//    return 0;
//}