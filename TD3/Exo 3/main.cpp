#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include "Palindrome.h"

using namespace std;

int main()
{
    cout << boolalpha;

    cout << "Is 'racecar' a palindrome? "
         << isPalindrome("racecar") << endl;

    cout << "Is 'hello' a palindrome? "
         << isPalindrome("hello") << endl;

    return 0;
}
