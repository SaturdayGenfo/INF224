#ifndef LIBRARY_H
#define LIBRARY_H
#include <map>
#include <sstream>
#include "groupe.h"
#include "multimedia.h"
#include "film.h"
#include "video.h"
#include "photo.h"
#include "tcpserver.h"

typedef std::shared_ptr<Groupe> GroupePtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;

class Library
{
public:
    Library();

    PhotoPtr createPhoto(double lng = 0, double lat = 0, std::string name = "" , std::string p = "");
    VideoPtr createVideo(int d = 0, std::string name = "" , std::string p = "");
    FilmPtr  createFilm(int * chap = nullptr, int n = 0, int d =0, std::string name = "", std::string path = "");
    GroupePtr createGroupe(std::string n = "");

    void displayMult(std::string name, std::ostream & stream);
    void displayGroup(std::string name, std::ostream & stream);
    void play(std::string name);
    void remove(std::string name);


    //Cote Serveur
    bool processRequest(cppu::TCPConnection& cnx, const std::string& request, std::string& response);




private:
    std::map<std::string, MultimediaPtr> objetsmult;
    std::map<std::string, GroupePtr> groupes;

};

#endif // LIBRARY_H
