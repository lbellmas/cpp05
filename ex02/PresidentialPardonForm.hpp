#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string name);
        ~PresidentialPardonForm();
        int Pardoned() const;
        void    execute(Bureaucrat const & executor) const;
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
};