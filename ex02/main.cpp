#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bur("hola", 1);
        ShrubberyCreationForm doc("cpp");
        bur.signForm(doc);
        bur.executeForm(doc);
        RobotomyRequestForm rob("rob");
        bur.signForm(rob);
        bur.executeForm(rob);
        PresidentialPardonForm pres("pres");
        bur.signForm(pres);
        bur.executeForm(pres);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "Lucas gitano" << std::endl;
}