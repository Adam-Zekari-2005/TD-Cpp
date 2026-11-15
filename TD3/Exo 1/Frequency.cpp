#include <iostream>
#include <vector>
#include <map>
#include "Frequency.h"

using namespace std;

// Temps : O(n^2). Memoire supplementaire : O(1).
void countFrequencyBruteForce(const vector<int>& numbers)
{
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        // Ne pas afficher une valeur deja rencontree.
        bool alreadyCounted = false;
        for (size_t j = 0; j < i; ++j)
            if (numbers[j] == numbers[i])
            {
                alreadyCounted = true;
                break;
            }
        if (alreadyCounted)
            continue;

        int count = 0;
        for (int value : numbers)
            if (value == numbers[i])
                ++count;

        cout << numbers[i] << ": " << count << " times" << endl;
    }
}

// Temps : O(n log(k + 1)), k = nombre de valeurs distinctes.
// Memoire : O(k). map conserve les cles dans l'ordre croissant.
map<int, int> countFrequencyOptimal(const vector<int>& numbers)
{
    map<int, int> frequencies;
    for (int value : numbers)
        ++frequencies[value];
    return frequencies;
}
