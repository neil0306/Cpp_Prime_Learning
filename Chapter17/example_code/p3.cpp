#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[])
{
    if (argc != 3){
        cout << "Wrong argument number! Please check your input!" << endl;
        exit(0);
    }

    ifstream fin;
    ofstream fout;
    char ch;

    fin.open(argv[1]);
    fout.open(argv[2]);

    if (fin.is_open() && fout.is_open())
    {
        while(fin.get(ch)){
            fout << ch;
        }
    }

    fin.close();
    fout.close();
    return 0;
}