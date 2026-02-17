#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bur("hola", 150);
        Form doc("cpp", 150, 14);
        bur.signForm(doc);
        Form fail("bad", 1, 1);
        bur.signForm(fail);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "Lucas gitano" << std::endl;
}