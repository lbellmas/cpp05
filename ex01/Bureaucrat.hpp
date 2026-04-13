#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat& copy);
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        void setGrade(int grade);
        const std::string getName() const;
        int getGrade() const;
        void checkGrade(int grade);
        void incrementGrade(int plus);
        void decrementGrade(int minus);
        const Bureaucrat    &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        void    signForm(Form &tosign);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};  
std::ostream &operator<<(std::ostream &out, const Bureaucrat &burocrata);
#endif