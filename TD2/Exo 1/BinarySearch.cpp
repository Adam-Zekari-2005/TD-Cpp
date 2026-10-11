
#include "BinarySearch.h"

BinarySearch::BinarySearch() : SearchingAlgorithm() {}

int BinarySearch::search(std::vector<int> elements, int target)
{
    numberComparaisons = 0;

    int left = 0;
    int right = elements.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        numberComparaisons++;

        if (elements[mid] == target)
            return mid;

        numberComparaisons++;

        if (elements[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
