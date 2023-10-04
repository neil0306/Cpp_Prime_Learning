#include "list.h"

List::List()
{
    top = 0;    // 初始化列表头指针, 栈顶指针永远指向栈的 "下一个元素位置"
}

bool List::isEmpty() const
{
    return 0 == top;  // 如果为0则表明当前栈为空
}

bool List::isFull() const 
{
    return top == MAX;
}

bool List::add(Item &item)
{
    if(top < MAX){
        items[top++] = item;
        return true;
    }
    else{
        return false;
    }
}

// 访问列表中的每一项数据, 注意传入的是一个 函数指针 pf!
void List::visit(void (*pf)(Item &))
{
    for(int i = 0; i < top; i++){
        pf(items[i]);
    }
}

void visit_item(Item &item)
{
    cout << "Item = " << item << endl;
}
