#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), 145, 137)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: " << this->getName() << " destroyed" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getStatus() != "signed")
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExec())
        throw AForm::GradeTooLowException();
    Trees();

};

int ShrubberyCreationForm::Trees() const
{
    std::ofstream Myfile((this->getName() + "_shrubbery").c_str());
    Myfile << "   🌲 ASCII TREE 🌲\n";
    Myfile.close();
    std::cout << "file created" << std::endl;
    return (1);
};