#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <iostream>
#include <vector>

class SearchingAlgorithm
{ 
    protected : 
        int numberComparaisons;

    public : 
        static int totalComparaisons;
        static int totalSearch; 
        static double averageComparaisons;

        SearchingAlgorithm();

        virtual int search(std::vector<int> elements,int target) = 0;

        void displaySearchResults(std::ostream& out, int results, int target);

}; 

#endif