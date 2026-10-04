#include <iostream>
#include "Complex2D.h"

int main()
{
    Complex2D z1(2, 3);
    Complex2D z2(1, 4);

    Complex2D somme = z1 + z2;
    Complex2D difference = z1 - z2;
    Complex2D produit = z1 * z2;
    Complex2D quotient = z1 / z2;

    std::cout << "Somme : "
              << somme.getReel()
              << " + "
              << somme.getImaginaire()
              << "i"
              << std::endl;

    std::cout << "Difference : "
              << difference.getReel()
              << " + "
              << difference.getImaginaire()
              << "i"
              << std::endl;

    std::cout << "Produit : "
              << produit.getReel()
              << " + "
              << produit.getImaginaire()
              << "i"
              << std::endl;

    std::cout << "Quotient : "
              << quotient.getReel()
              << " + "
              << quotient.getImaginaire()
              << "i"
              << std::endl;

    if (z1 > z2)
    {
        std::cout << "z1 est plus grand que z2" << std::endl;
    }
    else
    {
        std::cout << "z1 est plus petit ou egal a z2" << std::endl;
    }

    return 0;
}