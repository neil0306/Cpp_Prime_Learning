#include "somedefs.h"
#include <functional>   // 使用包装器必须包含这个头文件

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;};

int main(void)
{
    double y = 1.21;

    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = square;
    function<double(double)> ef3 = Fp(10);
    function<double(double)> ef4 = Fq(10);
    function<double(double)> ef5 = [](double u) {return u*u;};
    function<double(double)> ef6 = [](double u) {return u+u/2.0;};

    // ------ method 1: 传递函数指针; F => double (*)(double) ------
    cout << use_f(y, ef1) << endl;   // 模板函数 use_f 的类型 T 实例化为 double, 类型F实例化为函数指针
    cout << use_f(y, ef2) << endl;
    /*
        从打印信息可以看到, 打印的 count 的地址是相同的, 说明 use_f(y, dub) 和 use_f(f, square) 实例化的都是同一个函数模板.
    */
    cout << " ----------- " << endl;

    // ------ method 2: 传递函数符; F => 某个类对象, 要求这个类的成员函数里对operator()进行过重载 ------
    cout << use_f(y, ef3) << endl;              // Fp(5.0)调用了构造函数创造匿名对象; 在 use_f 的 return 语句中把 y 传给了运算符()的重载函数 
    cout << use_f(y, ef4) << endl;              // Fq(5.0)调用了构造函数创造匿名对象; 在 use_f 的 return 语句中把 y 传给了运算符()的重载函数 
    /*
        从打印信息可以看到, 打印的 count 的地址是 **不同** 的, 因为 模板F对应的类型是两个不一样的类对象(函数符), 相当于函数实例化使用的参数就不一样.
    */
    cout << " ----------- " << endl;

    // ------ method 2: 传递lambda表达式; F => lambda表达式 ------
    cout << use_f(y, ef5) << endl;      // use_f 的 F 类型将是一个函数指针, 不过这个函数指针是由lambda表达式弄出来的
    cout << use_f(y, ef5) << endl;      // use_f 的 F 类型将是一个函数指针, 不过这个函数指针是由lambda表达式弄出来的

    cout << use_f(y, ef6) << endl;      // use_f 的 F 类型将是一个函数指针, 不过这个函数指针是由lambda表达式弄出来的
    /*
        从打印信息可以看到, 打印的 count 的地址都是 **不同** 的, 这说明:
            即使 lambda 表达式就是相同的, 但是编译器仍然生成了两个函数指针(不认为这两个模板是同一个函数), 相当于函数实例化使用的参数还是不同.
    */
    cout << " ----------- " << endl;

    return 0;
}