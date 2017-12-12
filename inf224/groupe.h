#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include <memory>
#include "multimedia.h"

typedef std::shared_ptr<Multimedia>  MultimediaPtr;

class Groupe : public std::list<MultimediaPtr>
{
public:
    Groupe(std::string n = "") : std::list<MultimediaPtr>(), name(n) {}
    void display(std::ostream& stream);
    std::string getName() const;
private:
    std::string name;
};

#endif // GROUPE_H
