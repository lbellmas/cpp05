#include "AForm.hpp"
#include <iostream>
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string name);
        ~ShrubberyCreationForm();
        int Trees() const;
        void    execute(Bureaucrat const & executor) const;
};