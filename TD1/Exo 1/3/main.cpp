#include <iostream>
#include "affichage.h"

void afficher(std::string texte)
{
    std::cout << texte << std::endl;
}

int main()
{
    afficher("Hello World !");
    return 0;
}