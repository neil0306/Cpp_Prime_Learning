#include <iostream>
#include <string> 

using namespace std;

class Cpmv
{
	public:
		struct Info
		{
			string qcode;
			string zcode;
		};
	private:
		Info *pi;
	public:
		Cpmv();
		Cpmv(string g, string z);
		Cpmv(const Cpmv &cp);
		Cpmv(Cpmv &&mv);
		~Cpmv();
		Cpmv &operator=(const Cpmv &cp);
		Cpmv &operator=(Cpmv &&mv);
		Cpmv operator+(const Cpmv &obj) const;
		void Display() const;
};

Cpmv::Cpmv()
{
    pi = nullptr;
    cout << "default construction. " << endl;
}

Cpmv::Cpmv(string q, string z)
{
    pi = new Info();
    pi->qcode = q;
    pi->zcode = z;
    cout << "Construction with arguments." << endl;
}

Cpmv::Cpmv(const Cpmv &cp)
{
    pi = new Info();
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cout << "Copy Construction." << endl;
}

Cpmv::Cpmv(Cpmv &&mv)
{
    pi = mv.pi;         // 所有权转移
    mv.pi = nullptr;
    cout << "Move construction." << endl;
}

Cpmv::~Cpmv()
{
    delete pi;
    cout << "Deconstructino." << endl;
}

Cpmv & Cpmv::operator=(const Cpmv &cp)
{
    // 赋值运算符的书写套路:
    // 1. 判断是否为自身
    // 2. 删除当前对象里的变量
    // 3. new 一段新空间给当前对象
    // 4. 从传入对象中拷贝数据

    if(this == &cp){
        return *this;
    }

    delete pi;

    pi = new Info();
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;

    cout << "Assignment construction function." << endl;

    return *this;
}

Cpmv & Cpmv::operator=(Cpmv &&mv)
{
    // 赋值运算符的书写套路:
    // 1. 判断是否为自身
    // 2. 删除当前对象里的变量
    // 3. new 一段新空间给当前对象
    // 4. 从传入对象中拷贝数据

    if(this == &mv){
        return *this;
    }
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;

    cout << "Move assignment construction function." << endl;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    cout << "operator+" << endl;
    return Cpmv((pi->qcode + obj.pi->qcode), (pi->zcode + obj.pi->zcode));
}

void Cpmv::Display() const
{
    cout << "Display info" << endl;
    if(pi == nullptr){
        cout << "Pi is null!" << endl;
    }
    cout << "Address: " << pi << endl;
    cout << "qcode: " << pi->qcode << endl;
    cout << "zcode: " << pi->zcode << endl;
}

int main(void)
{
    Cpmv cp1("C", "C++");
	Cpmv cp2("computer", "language");

	Cpmv cp3(cp2);
	cp2 = cp1;
	Cpmv cp4(cp1 + cp2);

    return 0;
}

