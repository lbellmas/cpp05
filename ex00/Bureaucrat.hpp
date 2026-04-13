#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        void setGrade(int grade);
        const std::string getName() const;
        int getGrade() const;
        void checkGrade(int grade);
        void incrementGrade(void);
        void decrementGrade(void);
        const Bureaucrat    &operator=(const Bureaucrat &other);
        ~Bureaucrat();
       
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