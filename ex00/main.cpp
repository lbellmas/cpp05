#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bur("hola", 150);
        std::cout << bur;
        //bur.setGrade(160);
        //bur.setGrade(0);
        bur.incrementGrade(1);
        std::cout << bur;
        bur.decrementGrade(2);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "Lucas gitano" << std::endl;
}