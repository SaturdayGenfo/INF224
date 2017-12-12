#ifndef LIBRARY_H
#define LIBRARY_H
#include <map>
#include "groupe.h"
#include "multimedia.h"
#include "film.h"
#include "video.h"
#include "photo.h"

typedef std::shared_ptr<Groupe> GroupePtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;

class Library
{
public:
    Library();

    PhotoPtr create(double lng = 0, double lat = 0, std::string name = "" , std::string p = "");
    VideoPtr create(int d = 0, std::string name = "" , std::string p = "");
    FilmPtr  create(int * chap = nullptr, int n = 0, int d =0, std::string name = "", std::string path = "");
    GroupePtr create(std::string n = "");

    void searchDisplay(std::string name, std::ostream & stream);
    void play(std::string name);




private:
    std::map<std::string, MultimediaPtr> objmults;
    std::map<std::string, GroupePtr> groupes;

};

#endif // LIBRARY_H
