#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <iostream>

class Multimedia
{
public:
    Multimedia();
    Multimedia(std::string name, std::string path);
    ~Multimedia();

    void setName(std::string n);
    void setPath(std::string p);
    std::string getName() const;
    std::string getPath() const;

    virtual void affichage(std::ostream& stream) const;
    virtual void play() const = 0;

    //Serialisation
    virtual void write(std::ostream &f) const;
    virtual void read(std::istream &f);



private:
    std::string name;
    std::string path;
};

#endif // MULTIMEDIA_H
