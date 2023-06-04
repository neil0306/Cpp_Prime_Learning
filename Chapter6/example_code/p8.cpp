# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>          // Ϊ��ʹ�� EXIT_FAILUE ����

using namespace std;


int main(void)
{   
    ifstream inFile;    // ftream ����Ҫ�Լ��ֶ���������    
    string fileName;
    char ch;
    int count = 0;

    cout << "Enter the file name: ";
    getline(cin, fileName);   // getline �﷨: getline(������, �ַ�������);  cin.getline(�ַ�����, ���鳤��);

    inFile.open(fileName); // ���ļ� (�����ļ�)
    if (!inFile.is_open())  // ���ɹ�ʱ
    {
        cout << "Failed to open file!";
        exit(EXIT_FAILURE);
    }

    while (!inFile.eof()) // û��ĩβ�ż���ѭ��
    {
        inFile >> ch; // ��ȡ�ļ�, ����ַ���ȡ
        count++;
    }
    cout << fileName << " has " << count << " characters." << endl;
    inFile.close();
    return 0;
}

