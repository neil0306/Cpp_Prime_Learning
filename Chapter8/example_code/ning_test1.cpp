/*
    本例子用于测试 "函数返回" 与 "临时变量" 之间的关系.
*/

#include <iostream>

using namespace std;

// 先定义一个类, 里面定义了各种构造函数
class B {
public:
	B(){
		cout << "B的构造函数" << endl;
	}

	B(int i){
		cout << "带int型参数的B的构造函数" << endl;
	}

	B(const B &ano){
		cout << "B的复制构造函数" << endl;
	}

	B& operator=(const B& rhs){         // 注意这里定义了操作符 =, 它返回的是引用类型
		cout << "B的赋值操作符" << endl;
		return *this;
	}

	virtual ~B(){
		cout << "B的析构函数" << endl;
	}
};

// 定义一个函数用来测试这个类, 这个函数返回一个"非引用类型"
B func2()
{
	B b;
	return b;
}

// 定义测试函数, 用于测试 "函数返回非引用类型" 的情况
void test1() {
	B t;
	t = func2();
}

// 定义测试函数, 用于测试 "函数返回引用类型" 的情况, 注意 =号 在类中定义为返回 "引用"!!!
void test2() {
	B t = func2();
}

int main(void)
{
    cout << "运行 test 1 函数...." << endl;
    test1();

    cout << "--------------------" << endl;

    cout << "运行 test 2 函数...." << endl;
    test2();
    return 0;
}
