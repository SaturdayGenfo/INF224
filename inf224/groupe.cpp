#include "groupe.h"

void Groupe::display(std::ostream &stream)
{
    stream << "Objets dans " << this->name << std::endl;
    for(auto element : *this)
        element->affichage(stream);
}

std::string Groupe::getName() const
{
    return this->name;
}
