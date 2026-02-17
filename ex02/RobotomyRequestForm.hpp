#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string name);
        ~RobotomyRequestForm();
        int Drill() const;
        void    execute(Bureaucrat const & executor) const;
};