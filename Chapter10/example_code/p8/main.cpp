#include <iostream>
#include "list.h"

using namespace std;

int main(void)
{
    List list;
    Item num;
    for(int i = 0; i < 5; i++){
        cout << "Please enter a number: ";
        cin >> num;
        list.add(num);
    }
    list.visit(visit_item);
}
