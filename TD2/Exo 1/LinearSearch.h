#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm
{
public:
    LinearSearch();

    int search(std::vector<int> elements, int target) override;
};

#endif
