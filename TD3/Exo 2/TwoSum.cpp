#include <iostream>
#include <vector>
#include <unordered_map>
#include "TwoSum.h"

using namespace std;

// Temps : O(n^2). Memoire supplementaire : O(1).
vector<int> twoSumBruteForce(const vector<int>& nums, int target)
{
    for (size_t i = 0; i < nums.size(); ++i)
        for (size_t j = i + 1; j < nums.size(); ++j)
            // Conversion avant l'addition pour eviter un debordement d'int.
            if (static_cast<long long>(nums[i]) + nums[j] == target)
                return {static_cast<int>(i), static_cast<int>(j)};
    return {};
}

// Temps moyen : O(n), pire cas : O(n^2). Memoire : O(n).
vector<int> twoSumOptimal(const vector<int>& nums, int target)
{
    unordered_map<long long, int> seen;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        long long complement = static_cast<long long>(target) - nums[i];
        auto found = seen.find(complement);
        if (found != seen.end())
            return {found->second, static_cast<int>(i)};

        // Insertion apres la recherche : on ne reutilise pas le meme indice.
        seen.emplace(nums[i], static_cast<int>(i));
    }
    return {};
}
