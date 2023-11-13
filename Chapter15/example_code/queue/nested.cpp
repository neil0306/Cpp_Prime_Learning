#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main(void)
{
    Queue<string> cs(5);

    string temp;

    while(!cs.isFull())
    {
        cout << "Please enter client's name, then push to queue: " << endl;
        getline(cin, temp);
        cs.enqueue(temp);
    }

    cout << "The Queue is full, processing begin!" << endl;

    while(!cs.isEmpty())
    {
        cs.dequere(temp);
        cout << "Now processing: " << temp << endl;
    }

    return 0;
}
