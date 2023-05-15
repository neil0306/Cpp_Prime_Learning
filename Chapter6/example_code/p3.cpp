#include <iostream>

using namespace std;
// enum {c, p, t, g};

int main(void)
{
    char ch;

    cout << "Please enter one of the following choices: " << endl;
    cout << "c) carnivore \t p) pianist \n";
    cout << "t) tree \t g) game \n";

    do 
    {cout << "Please enter a c, p, t, or g: ";
    cin >> ch;
    }
    while (ch != 'c' && ch != 'p' && ch!= 't' && ch != 'g');
    
    switch (ch)
    {
        case 'c' : cout << "A maple is a tree.\n"; break;
        case 'p' : cout << "A maple is a tree.\n"; break;
        case 't' : cout << "A maple is a tree.\n"; break;
        case 'g' : cout << "A maple is a tree.\n"; break;
        // default : cout << "Please enter a c, p, t, or g: " << endl; 
    }

    return 0;
}
