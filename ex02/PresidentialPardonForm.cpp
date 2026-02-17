#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{};

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: " << getName() << " destroyed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getStatus() != "signed")
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExec())
        throw AForm::GradeTooLowException();
    Pardoned();
};

int PresidentialPardonForm::Pardoned() const
{
    std::cout << getName() << " has been pardoned by: Zaphod Beeblebrox" << std::endl;
    return (1);
};