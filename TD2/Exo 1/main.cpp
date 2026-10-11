
#include <iostream>
#include <vector>

#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main()
{
    std::vector<int> elements = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 9;

    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;

    std::cout << "=== Linear Search ===" << std::endl;

    int result1 = linear.search(elements, target);
    linear.displaySearchResults(std::cout, result1, target);

    std::cout << "\n=== Jump Search ===" << std::endl;

    int result2 = jump.search(elements, target);
    jump.displaySearchResults(std::cout, result2, target);

    std::cout << "\n=== Binary Search ===" << std::endl;

    int result3 = binary.search(elements, target);
    binary.displaySearchResults(std::cout, result3, target);

    return 0;
}
