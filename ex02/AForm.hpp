#ifndef AFORM_HPP
#define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string name;
        bool    signature;
        int gSign;
        int gExec;
    public:
        AForm(std::string name, int sign, int exec);
        AForm(AForm& copy);
        ~AForm();
        std::string getName() const;
        int getSign() const;
        int getExec() const;
        std::string getStatus() const;
        const AForm  &operator=(const AForm &form);
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
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        virtual void    execute(Bureaucrat const & executor) const = 0;
};
//std::ostream &operator<<(std::ostream &out, AForm doc);

#endif