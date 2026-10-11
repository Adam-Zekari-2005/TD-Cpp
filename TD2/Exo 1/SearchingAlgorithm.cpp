#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparaisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparaisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparaisons(0) {}

void SearchingAlgorithm::displaySearchResults(std::ostream& out, int results, int target)
{
    totalSearch++;
    totalComparaisons += numberComparaisons;

    averageComparaisons = (double)totalComparaisons / totalSearch;

    out << "Element recherche : " << target << std::endl;
    out << "Indice : " << results << std::endl;
    out << "Nombre de comparaisons : " << numberComparaisons << std::endl;
    out << "Total des comparaisons : " << totalComparaisons << std::endl;
    out << "Moyenne des comparaisons : " << averageComparaisons << std::endl;
}

