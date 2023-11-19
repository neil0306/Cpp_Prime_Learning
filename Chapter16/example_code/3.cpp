#include <iostream>
#include <string>
#include <cctype>   // 用到 tolower 就要引入
#include <ctime>    
#include <cstdlib>

using namespace std;

const int NUM = 26;
const string wordlist[NUM] = {
	"apiary", "beetle", "cereal", "danger", "ensign", "florid",
	"health", "insult", "jackal", "keeper", "loaner", "manage",
	"nonce",  "onset",  "plaid",  "quilt",  "remote", "stolid",
	"train",  "useful", "valid",  "whence", "xenon",  "yearn",
	"zippy"
};

int main(void)
{
    char play;

    srand(time(0));     // 設置隨機數種子

    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    tolower(play);  // 為了方便判斷, 全部轉小寫

    while(play == 'y'){
        string target = wordlist[rand() % NUM];     // 0~25 中隨機選一個數
        int length = target.length();
        string attempt(length, '-');
        string badchars;    // 歷史猜錯的字符
        int guess = 6;      // 最多允許猜 6 次
        cout << "Guess my secret word, it has " << length << " length, and you guess one character at a time. You get " << guess << " wrong guesses." << endl;

        cout << attempt << endl;
        while(guess > 0 && attempt != target){
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            // 檢查是否猜過
            if(badchars.find(letter) != string::npos || attempt.find(letter) != string::npos){      // 如果輸入的字符有出現在輸錯的記錄中, 或者 正確字符中曾經出現過
                cout << "You have already guessed that, try again!" << endl;
                continue;
            }

            // 沒出現過:
            int loc = target.find(letter);
            if(loc == string::npos){        // 當前猜的字符在target中找到末尾也沒有找到 ==> 猜錯了
                cout << "Oh, Bad Guess!" << endl;
                guess --;
                badchars += letter;
            }
            else{                           // 猜對的情況
                cout << "Good Guess!" << endl;
                attempt[loc] = letter;      // 這裡只替換了一個字符
                while(loc != string::npos){
                    attempt[loc] = letter;
                    loc = target.find(letter, loc +1);
                };
                
            }
            // 猜完一輪, 輸出當前猜測狀態
            cout << "Your word: " << attempt << endl;
            if(attempt != target){
                if(badchars.length() > 0){
                    cout << "Bad choices: " << badchars << endl;
                }
                cout << guess << " bad guess left!" << endl;
            }
        }
        // 判斷猜完之後是否正確
        if( guess > 0 || attempt == target){
            cout << "That's right!" << endl;
        }
        else{
            cout << "Sorry, the word is: " << target <<  endl;
        }

        cout << "Will you play another time? <y/n>" << endl;
        cin >> play;
        tolower(play);  // 為了方便判斷, 全部轉小寫
    }

    return 0;
}