# include <iostream>
# include <string>
# include <cctype>          // ʹ�� isalpha() ����

using namespace std;

int main(void)
{
    string words;
    int vowerls = 0, consonants = 0, others = 0;

    cout << "Enter words (q to quit): \n";
    while ((cin >> words) && "q" != words ) // ������Ч, �Ҳ���q
    {
        if(isalpha(words[0]))       // Ӣ����ĸ��ͷ
        {  
            switch (words[0])       // Ԫ����ĸ��ͷ
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
        else        // ����Ԫ��, Ҳ���Ǹ���
        {
            others++;
        }
    }

    cout << "vowerls: " << vowerls << endl;
    cout << "consonants: " << consonants << endl;
    cout << "others: " << others << endl;
    return 0;
}


