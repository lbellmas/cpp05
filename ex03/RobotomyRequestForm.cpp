#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), 72, 45)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

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
    srand(time(NULL));
    int n = rand();
    std::cout << "R-R-R-R-R-T R-R-R-R-R-T BZZZZT\n" << getName() << " has been robotomized succesfully 50% of the time" << std::endl;
    if (n % 2 == 0)
        std::cout << "This time " << getName() << " has been robotomized :)" << std::endl;
    else
        std::cout << "This time " << getName() << " hasn't been robotomized :(" << std::endl;
    return (1);
};