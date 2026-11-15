#include <iostream>
#include <string>
#include "MatrixNumerical.h"

int main()
{
    try
    {
        MatrixBase<std::string> words(1, 2);
        words.addElement(0, 0, "Bonjour");
        words.addElement(0, 1, "Matrices");
        words.Display();
        std::cout << "Dimensions : " << words.getRows() << " x " << words.getCols()
                  << "\nElement (0, 1) : " << words.getElement(0, 1) << "\n\n";

        MatrixNumerical<int> a({{4, 7}, {2, 6}});
        MatrixNumerical<int> b({{1, 2}, {3, 4}});

        std::cout << "A :\n";
        a.Display();
        std::cout << "B :\n";
        b.Display();
        std::cout << "\nA + B :\n";
        (a + b).Display();
        std::cout << "\nA - B :\n";
        (a - b).Display();
        std::cout << "\nA * B :\n";
        (a * b).Display();
        std::cout << "\nDeterminant de A : " << a.getDeterminant() << '\n';
        std::cout << "\nInverse de A :\n";
        a.getInverse().Display();
        std::cout << "\nA / B (= A * inverse(B)) :\n";
        (a / b).Display();
        std::cout << "\nIdentite 3 x 3 :\n";
        MatrixNumerical<double>::getIdentity(3).Display();
    }
    catch (const std::exception& error)
    {
        std::cerr << "Erreur : " << error.what() << '\n';
        return 1;
    }
    return 0;
}
