#include <iostream>
#include <string>

class my_class
{
private:
    std::string element;

public:
    my_class()
    {
        element = "";
    }

    my_class(std::string texte)
    {
        element = texte;
    }
   
    void print_my_element()
    {
        std::cout << element << std::endl;
    }
};

int main()
{
    my_class objet("Hello World !");
    objet.print_my_element();
    return 0;
}