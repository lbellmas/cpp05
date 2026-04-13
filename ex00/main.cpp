#include "Bureaucrat.hpp"

int main() 
{
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << "After increment: " << a << std::endl;

        a.decrementGrade();
        std::cout << "After decrement: " << a << std::endl;

        // Esto debería lanzar excepción
        Bureaucrat b("Bob", 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}