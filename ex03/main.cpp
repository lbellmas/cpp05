#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat bur("hola", 1);
        Intern someRandomIntern;
        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* presidential = someRandomIntern.makeForm("presidential pardon", "presi");
        bur.signForm(*shrubbery);
        bur.signForm(*robotomy);
        bur.signForm(*presidential);
        bur.executeForm(*shrubbery);
        bur.executeForm(*robotomy);
        bur.executeForm(*presidential);
        delete shrubbery;
        delete robotomy;
        delete presidential;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "Lucas gitano" << std::endl;
}