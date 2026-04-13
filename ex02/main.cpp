#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    // Shrubbery
    worker.signForm(shrub);
    worker.executeForm(shrub);

    std::cout << "------------------" << std::endl;

    // Robotomy
    boss.signForm(robot);
    boss.executeForm(robot);

    std::cout << "------------------" << std::endl;

    // Presidential pardon
    boss.signForm(pardon);
    boss.executeForm(pardon);
}