#include <iostream>
#include <string>

int main(void){
    using namespace std;

    cout << "Enter an word: ";

    string word;
    cin >> word;

    for(int i = word.size() -1; i>=0 ;i--){
        cout << word[i] ;
    }
    cout << endl;

    return 0;
}
