#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

//template<class T>
//
//T Add(T& a, T& b)//函数模板
//{
//	return a + b;
//}
//template<class T>
//class Stack//类模板
//{
//public:
//	
//	Stack(T* _a = nullptr, int _size = 0, int _capacity = 0)//缺省值
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
	T& operator[](size_t i)//引用传返回值 后面在类外面调用可以改这个值 因为引用是别名
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
			memcpy(tmp,_a,sizeof(T)*_size);//把老数据拷贝过来
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
//#include <stdexcept> // 为了使用 std::out_of_range 异常
//
//template<class T>
//class Stack {
//private:
//    T* elements; // 元素数组
//    int capacity; // 数组容量
//    int topIndex; // 指向栈顶元素的索引
//
//public:
//    // 构造函数
//    Stack(int capacity = 10) : capacity(capacity), topIndex(-1) {
//        elements = new T[capacity];
//    }
//
//    // 析构函数
//    ~Stack() {
//        delete[] elements;
//    }
//
//    // 压入元素
//    void push(const T& element) {
//        if (topIndex >= capacity - 1) {
//            // 栈已满，抛出异常或进行扩容
//            throw std::out_of_range("Stack<>::push(): stack is full");
//        }
//        elements[++topIndex] = element;
//    }
//
//    // 弹出元素
//    T pop() {
//        if (isEmpty()) {
//            // 栈为空，抛出异常
//            throw std::out_of_range("Stack<>::pop(): stack is empty");
//        }
//        return elements[topIndex--];
//    }
//
//    // 返回栈顶元素
//    T top() const {
//        if (isEmpty()) {
//            // 栈为空，抛出异常
//            throw std::out_of_range("Stack<>::top(): stack is empty");
//        }
//        return elements[topIndex];
//    }
//
//    // 检查栈是否为空
//    bool isEmpty() const {
//        return topIndex == -1;
//    }
//};
//
//int main() {
//    Stack<int> intStack(5); // 创建一个容量为5的int类型的栈
//
//    // 压入一些元素
//    intStack.push(1);
//    intStack.push(2);
//    intStack.push(3);
//
//    // 弹出并打印每个元素
//    while (!intStack.isEmpty()) {
//        std::cout << intStack.pop() << std::endl;
//    }
//
//    return 0;
//}