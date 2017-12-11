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


private:
    std::string name;
    std::string path;
};

#endif // MULTIMEDIA_H
