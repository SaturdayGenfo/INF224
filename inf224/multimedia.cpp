#include "multimedia.h"
#include <iostream>
using namespace std;


Multimedia::Multimedia()
{
    this->name = "";
    this->path = "";
}

Multimedia::Multimedia(string name, string path)
{
    this->name = name;
    this->path = path;
}
Multimedia::~Multimedia()
{
    cout << "OHHH SEIGNEUR DIEU ! JE DECEDE ! -" << this->getName() << endl;

}

void Multimedia::setName(string n)
{
    this->name = n;
}

void Multimedia::setPath(string p)
{
    this->path = p;
}
string Multimedia::getName() const
{
    return this->name;
}
string Multimedia::getPath() const
{
    return this->path;
}

void Multimedia::affichage(ostream &stream) const
{
    stream << "Nom : " << this->getName() << endl;
    stream << "Chemin : " << this->getPath() << endl;
}



