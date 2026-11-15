#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include "Palindrome.h"

using namespace std;

// Temps : O(n). Memoire : O(n). L'entree doit etre un texte UTF-8 valide.
bool isPalindrome(const string& input)
{
    queue<string> fifo;
    stack<string> lifo;

    for (size_t i = 0; i < input.size();)
    {
        unsigned char first = static_cast<unsigned char>(input[i]);
        string character;
        if (first < 128)
        {
            ++i;
            if (!isalnum(first))
                continue;
            character = static_cast<char>(tolower(first));
        }
        else
        {
            // Garder ensemble les octets d'une lettre accentuee UTF-8.
            size_t length = (first < 224) ? 2 : (first < 240 ? 3 : 4);
            character = input.substr(i, length);
            i += length;

            // Mettre en minuscules les lettres accentuees du bloc Latin-1.
            if (first == 195 && character.size() == 2)
            {
                unsigned char second = static_cast<unsigned char>(character[1]);
                if ((second >= 128 && second <= 150) ||
                    (second >= 152 && second <= 158))
                    character[1] = static_cast<char>(second + 32);
            }
        }
        fifo.push(character);
        lifo.push(character);
    }

    while (!fifo.empty())
    {
        // La file lit de gauche a droite, la pile de droite a gauche.
        if (fifo.front() != lifo.top())
            return false;
        fifo.pop();
        lifo.pop();
    }
    return true;
}
