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

    PhotoPtr create();
    VideoPtr create();
    FilmPtr  create();
    GroupePtr create();




private:
    std::map<std::string, MultimediaPtr> objmults;
    std::map<std::string, GroupePtr> groupes;

};

#endif // LIBRARY_H
