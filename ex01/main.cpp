#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 50);
        Form f("FormA", 40, 30);

        std::cout << f << std::endl;

        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat a("Balice", 50);
        Form f("FormB", 60, 30);

        std::cout << f << std::endl;

        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}