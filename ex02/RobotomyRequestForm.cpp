#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{};

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: " << getName() << " destroyed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getStatus() != "signed")
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExec())
        throw AForm::GradeTooLowException();
    Drill();
};

int RobotomyRequestForm::Drill() const
{
    std::cout << "R-R-R-R-R-T R-R-R-R-R-T BZZZZT\n" << getName() << " has been robotomized succesfully 50% of the time" << std::endl;
    return (1);
};