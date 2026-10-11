
#include "JumpSearch.h"
#include <cmath>
#include <algorithm>

JumpSearch::JumpSearch() : SearchingAlgorithm() {}

int JumpSearch::search(std::vector<int> elements, int target)
{
    numberComparaisons = 0;

    int n = elements.size();

    if (n == 0)
        return -1;

    int step = std::sqrt(n);
    int start = 0;
    int end = std::min(step, n);

    while (start < n)
    {
        numberComparaisons++;

        if (elements[end - 1] >= target)
            break;

        start = end;
        end = std::min(end + step, n);
    }

    if (start >= n)
        return -1;

    for (int i = start; i < end; i++)
    {
        numberComparaisons++;

        if (elements[i] == target)
            return i;

        numberComparaisons++;

        if (elements[i] > target)
            break;
    }

    return -1;
}
