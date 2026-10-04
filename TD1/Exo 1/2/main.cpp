#include <iostream>
#include <string>

void afficher(std::string texte)
{
    std::cout << texte << std::endl;
}

int main()
{
    afficher("Hello World !");
    return 0;
}