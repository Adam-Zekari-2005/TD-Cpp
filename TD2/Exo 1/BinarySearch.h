#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm
{
public:
    BinarySearch();

    int search(std::vector<int> elements, int target) override;
};

#endif
