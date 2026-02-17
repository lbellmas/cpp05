#include "Form.hpp"

Form::Form(std::string name, int sign, int exec) : name(name), gSign(sign), gExec(exec) 
{
    signature = false;
};

Form::Form(Form& copy) : name(copy.getName()), gSign(copy.getSign()), gExec(copy.getExec())
{
    signature = false;
};
Form::~Form()
{
    std::cout << "Form: " << name << " destroyed" << std::endl;
}
std::string Form::getName()
{
    return (name);
}
int Form::getExec()
{
    return (gExec);
}
int Form::getSign()
{
    return (gSign);
}

std::string Form::getStatus()
{
    if (signature == false)
        return ("not signed");
    return ("signed");
}

const Form  &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        gExec = other.gExec;
        gSign = other.gSign;
        signature = other.signature;
    }
    return (*this);
};

void    Form::beSigned(Bureaucrat &burocrata)
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
std::ostream &operator<<(std::ostream &out, Form doc)
{
    out << doc.getName() << "needs grade: " << doc.getSign() << "to be signed and grade: " << doc.getExec() << "to be executed. This form is currently: " << doc.getStatus() << std::endl;
    return (out);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat grade is to high");
};

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat grade is to low");
};