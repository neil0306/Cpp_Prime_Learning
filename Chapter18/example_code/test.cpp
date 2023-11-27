#include <iostream>

using namespace std;

class Action
{
    private:
        int a;
    public:
        Action(int i = 0) : a(i){}
        int val() const {return a;}

        // ----  case 3  -----
        // virtual void f(char ch) const {cout << val() << ch << "\n";}

        // ----  case 4  -----
        virtual void f(char ch) const final {cout << val() << ch << "\n";}

};

class Bingo: public Action
{
    public:
        Bingo(int i = 0) : Action(i) {}

        // ------ case 1 ------
        // virtual void f(char *ch) const {cout << val() << ch << "!\n";}     
        /*
            在第十三章, 中文书 page 506页 有提到, 这种方式叫 "重新定义":
                virtual void f(char ch) const
                virtual void f(char *ch) const
                这辆个函数虽然参数列表(特征标)不相同, 但是由于是虚函数, 此时 **并不会生成两个版本的 f 函数**!!  (对于虚函数来说, 此时特征标不一样, 不是实现不同功能那种 多态)
                    此时发生的现象是: 
                        派生类 Bingo 中定义的 "virtual void f(char *ch) const" 将直接把基类的同名函数 f 给隐藏掉, 
                        此时我们将无法通过派生类对象调用基类的 f 函数.
        */

        // ------ case 2 ------
        // virtual void f(char ch) const {cout << val() << ch << "!\n";}       // 打印的时候会多出一个 !

        // ------ case 3: 使用 override ------
        virtual void f(char ch) const override {cout << val() << ch << "!\n";}       // 此时override 与 基类的final冲突, 编译会报错

};

int main(void)
{
    Bingo b(10);

    // ------ case 1 ------
    // b.f('@');       // 没有加 final 或 override 时, 这行语句编译会报错, 因为 '@'无法与 const char * 类型匹配.
    // b.Action::f('@');    // 没有加 final 或 override 时, 通过指明作用域, 可以正常调用到基类的 f 方法

    // ------ case 2: 如果基类有同名函数, 则派生类的函数是基类函数的重载; 如果注释掉基类的同名函数, 则派生类的函数是一个独立的普通函数. ------
    // b.f('@');       // 此时 打印的信息多一个 !, 表示调用的是派生类的f函数.  注意此时这两个虚函数的特征标是一模一样的! (这时候实现的是多态/重载)
                       //    这时候, 如果注释掉基类的 f 方法, 编译和运行都不会报错!! 

    // ------ case 3: 加 override, 显式表明f是基类的重载, 此时基类的同名函数不允许被删除, 如果删除, 则编译会报错"你既然表明是重载, 你就得有个原来的版本" ------
    // b.f('@');       // 此时 打印的信息多一个 !, 表示调用的是派生类的f函数.  注意此时这两个虚函数的特征标是一模一样的! (加了override之后, 显式地表明这个函数是基类函数的重载)
                    //      这时候, 如果注释掉基类的 f 方法, 编译会报错!! 

    // ------ case 4: 基类加 final, 表示不允许重载 (不允许派生类 override), 但是派生类的同名函数使用了 override ==> 此时编译报错
    b.f('@');  

    return 0;    
}