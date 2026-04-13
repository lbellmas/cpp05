#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        AForm* form4 = someRandomIntern.makeForm("unknown form", "???");
        if (form4)
            delete form4;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "garden");
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur");

        if (form1) {
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }

        if (form2) {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }

        if (form3) {
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}