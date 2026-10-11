#include "LinearSearch.h"
#include <vector>

LinearSearch::LinearSearch() : SearchingAlgorithm() {}

int LinearSearch::search(std::vector<int> elements, int target)
{
    numberComparaisons = 0;

    int n = elements.size();

    for (int i = 0; i < n; i++)
    {
        numberComparaisons++;

        if (elements[i] == target)
        {
            return i;
        }
    }

    return -1;
}