#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friends.";

    cout << "Sizes: " << endl;
    cout << "\t Empty: " << empty.size() << endl;
    cout << "\t Small: " << small.size() << endl;
    cout << "\t Larger: " << larger.size() << endl;

    cout << "Capacities: " << endl;
    cout << "\t Empty: " << empty.capacity() << endl;
    cout << "\t Small: " << small.capacity() << endl;
    cout << "\t Larger: " << larger.capacity() << endl;

    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;
    return 0;
}