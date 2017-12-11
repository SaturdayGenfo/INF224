#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video
{
public:
    Film(int * chap = nullptr, int n = 0, int d =0, std::string name = "", std::string path = "");
    ~Film();

    void setChapitres(int * chap, int n);
    int getNChapitres() const { return nchap; }
    int const * getChapitres() const;

private:
    int * chapitres;
    int nchap;
};

#endif // FILM_H
