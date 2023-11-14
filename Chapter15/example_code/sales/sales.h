#ifndef __SALES_H__
#define __SALES_H__

#include <iostream>
#include <stdexcept>        // 為了使用自帶的異常類 logic_error, runtime_error
#include <string>

using namespace std;

class Sales
{
    public:
        enum{MONTHS = 12};
    private:
        int year;
        double gross[MONTHS];
    public:
        explicit Sales(int yy = 0);        // 用explicit 禁止隱式地 調用構造函數進行類型轉換, 常用於構造函數的入參只有一個基礎類型參數的情況
        Sales(int yy, const double * gr, int n);
        virtual ~Sales(){};                 // 作為基類使用的話, 必須定義虛析構函數

        int Year() {return year;}
        virtual double operator[](int i) const; // 返回的是double類型, 並且不允許修改類的成員變量
        virtual double &operator[](int i);      // 返回double類型的引用, 允許修改類成員變量

        // 嵌套, 定義一個異常類
        class bad_index : public logic_error
        {
            private:
                int bi;     // bad index
            public:
                // 寫異常類, 尤其是繼承自系統提供的庫時, 一定要包含一個 const string &, 用來初始化(異常)基類對象
                explicit bad_index(int ix, const string &s = "Index Error in Sales Object!\n") : bi(ix), logic_error(s){};
                int bi_val() const { return bi; }

                virtual ~bad_index() throw() {};     
                /*
                    針對這個析構函數的說明:
                        1. 如果我們把它寫為 ~bad_index() {} 時, 編譯器會直接報錯; 
                        2. 寫成 ~bad_index() throw(){} 是正確的寫法, 但此時不會引發異常
                        3. 如果我們把它寫為 ~bad_index() throw(int, char) {} 時, 這個析構函數將引發一個 int 和 char 類型的異常
                        4. 如果我們把它寫為 ~bad_index() throw(...) {} 時, 這個析構函數將引發一個 "任意類型" 的異常
                */

        };
};

class LabelSales : public Sales
{
    private:
        string label;
    public:
        explicit LabelSales(const string &lb = "none", int yy = 0) : Sales(yy), label(lb){}
        LabelSales(const string &lb, int yy, const double *gr, int n) : Sales(yy, gr, n), label(lb){}

        virtual ~LabelSales(){}

        const string & Label() const {return label;}
        virtual double operator[](int i) const; // 返回的是double類型, 並且不允許修改類的成員變量
        virtual double &operator[](int i);      // 返回double類型的引用, 允許修改類成員變量

        // 嵌套, 第二代異常類
        class nbad_index : public Sales::bad_index
        {
            private:
                string lbl;
            public:
                nbad_index(const string &lb, int ix, const string &s = "Index error in LabelSales Object!\n") : Sales::bad_index(ix, s), lbl(lb){}
                const string &label_val() const { return lbl; }
                
                virtual ~nbad_index() throw() {};   // 同樣是不拋出異常
        };
};

#endif //!__SALES_H__