#include "film.h"

Film::Film(int * chap, int n, int d, std::string name, std::string path) : Video(d, name, path)
{
    this->chapitres = nullptr;
    this->nchap = n;
    if(n > 0)
    {
        this->chapitres = new int[n];
        for(int i=0; i<n; i++)
            this->chapitres[i] = chap[i];
    }

}

Film::~Film()
{
    delete[] this->chapitres;
}

void Film::setChapitres(int *chap, int n)
{

    delete[] this->chapitres;

    this->nchap = n;
    this->chapitres = new int[n];

    for(int i=0; i< this->nchap ; i++)
        this->chapitres[i] = chap[i];
}

int const * Film::getChapitres() const
{
    return this->chapitres;
}


