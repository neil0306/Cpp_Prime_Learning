#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
    int whitespace = 0;
    int digit = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    char ch;
    cout << "Enter text for analysis, and type @ to terminate the input progress. \n";
    cin.get(ch);
    while (ch != '@')
    {
        if (isalpha(ch))
            chars++;
        else if (isspace(ch))
            whitespace++;
        else if (ispunct(ch))
            punct++;
        else if (isdigit(ch))
            digit++;
        else
            others++;
        
        cin.get(ch);
    }

    cout << "You've enter: " << chars << " letters, " << whitespace <<" whitespaces, " 
        << punct << " punctuations, " << digit << " digits, and " << others << " others.\n";
    return 0;
}

