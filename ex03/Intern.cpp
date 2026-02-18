#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}
Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern created by copy" << std::endl;
}
Intern::~Intern()
{}
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string form[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (Intern::*formCreators[3])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == form[i])
        {
            std::cout << "Intern creates: " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    throw UnknownFormException();
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

const char* Intern::UnknownFormException::what() const throw()
{
    return "Intern cannot create form: Unknown form name";
}