#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {};

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    checkGrade(grade);
    this->grade = grade;
};

void Bureaucrat::checkGrade(int grade)
{
    if (grade > 150)
        throw GradeTooHighException();
    else if (grade < 1)
        throw GradeTooLowException();
}

void Bureaucrat::incrementGrade(int plus)
{
    checkGrade(grade - plus);
    grade -= plus;
}
void Bureaucrat::decrementGrade(int minus)
{
    checkGrade(grade + minus);
    grade += minus;
}
Bureaucrat::Bureaucrat(Bureaucrat& copy) : name(copy.name), grade(copy.grade) {};

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: " << name << " destroyed" << std::endl;
};

const Bureaucrat    &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        grade = other.grade;
    return (*this);
}

void    Bureaucrat::setGrade(int grade)
{
    checkGrade(grade);
    this->grade = grade;
};

const std::string    Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade selected is too high");
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade selected is too low");
};

void    Bureaucrat::signForm(Form &tosign)
{
    std::cout << name;
    tosign.beSigned(*this);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &burocrata)
{
    out << burocrata.getName() << ", bureaucrat grade " << burocrata.getGrade();
    return (out);
};