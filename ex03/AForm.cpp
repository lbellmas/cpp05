#include "AForm.hpp"

AForm::AForm(std::string name, int sign, int exec) : name(name), gSign(sign), gExec(exec) 
{
    signature = false;
};

AForm::AForm(AForm& copy) : name(copy.getName()), gSign(copy.getSign()), gExec(copy.getExec())
{
    signature = false;
};
AForm::~AForm()
{
    std::cout << "Form: " << name << " destroyed" << std::endl;
}
std::string AForm::getName() const
{
    return (name);
}
int AForm::getExec() const
{
    return (gExec);
}
int AForm::getSign() const
{
    return (gSign);
}

std::string AForm::getStatus() const
{
    if (signature == false)
        return ("not signed");
    return ("signed");
}

const AForm  &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        gExec = other.gExec;
        gSign = other.gSign;
        signature = other.signature;
    }
    return (*this);
};

void    AForm::beSigned(Bureaucrat &burocrata)
{
    if (burocrata.getGrade() > gSign)
    {
        std::cout << " couldn't sign " << name << " because: grade too low" << std::endl;
        throw GradeTooLowException();
    }
    else
    {
        signature = true;
        std::cout << " signed " << name << std::endl;
    }
}
/*std::ostream &operator<<(std::ostream &out, AForm doc)
{
    out << doc.getName() << "needs grade: " << doc.getSign() << "to be signed and grade: " << doc.getExec() << "to be executed. This form is currently: " << doc.getStatus() << std::endl;
    return (out);
}*/

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat grade is to high");
};

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat grade is to low");
};

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("The Form is not signed");
};