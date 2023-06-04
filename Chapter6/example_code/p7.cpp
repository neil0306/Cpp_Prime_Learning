# include <iostream>
# include <string>
# include <cctype>          // 使用 isalpha() 函数

using namespace std;

int main(void)
{
    string words;
    int vowerls = 0, consonants = 0, others = 0;

    cout << "Enter words (q to quit): \n";
    while ((cin >> words) && "q" != words ) // 输入有效, 且不是q
    {
        if(isalpha(words[0]))       // 英文字母开头
        {  
            switch (words[0])       // 元音字母开头
            {
                case 'a': 
                case 'e': 
                case 'i': 
                case 'o': 
                case 'u': 
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U': 
                    vowerls++;
                    break;
                default: 
                    consonants++;
                    break;
            }

        }
        else        // 不是元音, 也不是辅音
        {
            others++;
        }
    }

    cout << "vowerls: " << vowerls << endl;
    cout << "consonants: " << consonants << endl;
    cout << "others: " << others << endl;
    return 0;
}


