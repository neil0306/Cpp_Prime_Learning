#include <iostream>

// 為了使用隨機數, 引入一下兩個頭文件
#include <cstdlib>
#include <ctime>

#include <typeinfo>  // 為了使用 typeid

using namespace std;

class Grand
{
    private:
        int hold;
    public:
        Grand(int h = 0) : hold(h){}
        virtual ~Grand(){}

        virtual void Speak() const { cout << "I am a grand class" << endl; }
        virtual int Value() const { return hold; }
};

class SuperB : public Grand
{
    public:
        SuperB(int h = 0) : Grand(h){}
        virtual ~SuperB() {}

        virtual void Speak() const { cout << "I am a SuperB class" << endl; }
        virtual void Say() const {cout << "I hold the SuperB value of " << Value() << endl;}  // 基類 Grand 裡沒有, 這裡首次定義
};

class Magnificent : public SuperB
{
    private:
        char ch;
    public:
        Magnificent(int h = 0, char c = 'A') : SuperB(h), ch(c) {}
        ~Magnificent(){};
        virtual void Speak() const {cout << "I am a Magnificent class." << endl;} 
        virtual void Say() const {cout << "I hold the Character " << ch << " and the integer " << Value() << endl;}  // 注意: 這是從 SuperB 中繼承過來的, 祖先類Grand中並沒有這個函數!!
};

Grand * GetOne();

int main(void)
{
    Grand *pg;          // 基類指針, 可以指向基類對象, 也可以指向派生類對象
    SuperB *ps;

    srand(time(0));     // 使用時間來固定隨機種子

    for (int i = 0; i < 5; i++){
        pg = GetOne();      // 此時 pg 指針指向的對象類型是不確定的
        cout << "Now processing type: " << typeid(*pg).name() << endl;
        pg->Speak();        // 由於 speak 在這三個類中都定義了虛函數, 所以這裡調用不會報錯

        // ps = (SuperB *)pg;   // 這行代碼編譯雖然不會出錯, 但是運行的時候只要 pg 是 Grand類, 就會出現`segmentation fault`, 這是因為基類轉派生類是不允許的(容易出現某些成員變量沒有對象值進行初始化的情況)
        // ps->Say();           //基類Grand 裡是沒有 Say() 的, 所以如果 pg 是 Grand類型, 就會出錯.

        // 如果要調用 Say() 函數, 為了防止出現錯誤, 這裡就必須提前知道 pg 指向的類型
        ps = dynamic_cast<SuperB*>(pg);     // 如果轉換失敗, ps 將是一個空指針
        if(ps){     // 如果轉換失敗, 則什麼都不做, 此時就不會引起錯誤   
            ps->Say();
        }

        if(typeid(Magnificent) == typeid(*pg)){
            cout << "Yes, you are really magnificent." << endl;
        }
    }

    return 0;
}

Grand * GetOne()        // 這裡返回的雖然寫了基類指針, 但是它也可以指向派生類, 這裡不要忽略!
{
    Grand *p;

    switch (rand() % 3)     // 用隨機數摸3, 得到的值為 0 1 2 中的一個
    {
        case 0:
            p = new Grand(rand() % 100);   // 生成一個 0~99 的隨機數丟進構造函數
            break;
        case 1:
            p = new SuperB(rand() % 100);
            break;
        case 2:
            p = new Magnificent(rand() % 100, 'A' + rand() % 26);  // 這裡利用隨機值作為偏移量生成了一個大寫字母的隨機字符
            break;
    }

    return p;
}