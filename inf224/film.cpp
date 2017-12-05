#include "film.h"

Film::Film(int * chap = nullptr, int n = 0, int d =0, string name, string path) : Video(d, name, path)
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

void Film::setChapitres(int *chap)
{
    for(int i=0; i< this->nchap ; i++)
        this->chapitres[i] = chap[i];
}

void Film::getChapitres(int *tab)
{
    for(int i=0; i < this->nchap; i++)
        tab[i] = this->chapitres[i];
}


