#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();

        Intern &operator=(const Intern &other);

        AForm *makeForm(const std::string &formName, const std::string &target);
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPresidential(const std::string& target);
        class UnknownFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};