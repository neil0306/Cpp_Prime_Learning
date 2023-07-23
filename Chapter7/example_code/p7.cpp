/*
    编程题第七题
*/

#include <iostream>
const int Max = 5;

double* fill_array(double* begin, double* end);
void show_array(double* begin, double* end);
void revaluate(double r, double* begin, double* end);


using namespace std;

int main(void){

    double properties[Max];

    double* pa = fill_array(properties, properties + Max);  // 录入
    
    show_array(properties, pa);       // 回显

    int size = (pa - properties);
    if( size > 0){
        cout << "Enter revaluation factor: ";
        double factor;
        while(!(cin >> factor)){    // 检查cin是不是停止工作
            cin.clear();            // 清除cin的标志位
            while(cin.get() != '\n'){  // 清掉cin的缓冲区
                continue;
            }
            cout << "Bad input; Please enter a number: ";
        }
        revaluate(factor, properties, pa); // 重新评估(重新写入数据)

        show_array(properties, properties + size);       // 回显
        // show_array(properties, pa);       // 等价于上一行
    }


    return 0;
}

/// @brief 填充数组, 返回数组末尾指针
/// @param begin 数组起始指针
/// @param end  数组末尾指针的下一个位置 (为了确保数组最后一个元素能访问到)
/// @return 数组末尾指针
double* fill_array(double* begin, double* end){

    double* pt;
    double temp;

    for(pt = begin; pt != end; pt++){         // 注意end是数组最后一个元素的下一个地址
        // 换算数组下标: (pt - begin) + 1
        cout << "Enter value #" << (pt - begin) + 1 << ": ";
        cin >> temp;
        if (!cin){
            cin.clear();
            while(cin.get() != '\n');
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0){         // 负数视为非法值
            break;
        }
        else{
            *pt = temp;
        }
    }

    return pt;          // 返回尾指针
}

/// @brief 回显数组
/// @param begin 数组起始位置
/// @param end 数组最后元素的下一个位置
void show_array(double* begin, double* end ){   // const 保护数组指针指向的内容
    for(double * pt = begin; pt != end; pt++){
        cout << "Property #" << (pt-begin) + 1 << ": $";
        cout << *pt << endl;
    }
}

void revaluate(double r, double* begin, double* end){

    for(double* pt = begin; pt != end; pt++){
       *pt *= r;
    }
}
