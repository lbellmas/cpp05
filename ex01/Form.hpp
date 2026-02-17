#ifndef FORM_HPP
#define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string name;
        bool    signature;
        int gSign;
        int gExec;
    public:
        Form(std::string name, int sign, int exec);
        Form(Form& copy);
        ~Form();
        std::string getName();
        int getSign();
        int getExec();
        std::string getStatus();
        const Form  &operator=(const Form &form);
        void    beSigned(Bureaucrat &burocrata);
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
std::ostream &operator<<(std::ostream &out, const Form doc);

#endif