#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "SearchingAlgorithm.h"

class JumpSearch : public SearchingAlgorithm
{
public:
    JumpSearch();

    int search(std::vector<int> elements, int target) override;
};

#endif
