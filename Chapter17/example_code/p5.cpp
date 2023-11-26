#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
    set<string> Mat, Pat, Guest;
    string name;
    ifstream fin1;
    ifstream fin2;
    fin1.open("mat.dat");
    fin2.open("pat.dat");

    while(getline(fin1, name) && name.size() > 0){
        Mat.insert(name);
    }
    while(getline(fin2, name) && name.size() > 0){
        Pat.insert(name);
    }

    // 合并: 由于 set 本身就排序 & 去重, 所以直接丢进去就好了
    Guest.insert(Mat.begin(), Mat.end());
    Guest.insert(Pat.begin(), Pat.end());

    ofstream fout;
    fout.open("matnpat.dat");

    set<string>::iterator pd;
    for(pd = Guest.begin(); pd != Guest.end(); pd++){
        fout << *pd << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}