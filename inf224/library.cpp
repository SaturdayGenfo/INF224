#include "library.h"
using namespace std;


Library::Library()
{

}

PhotoPtr Library::createPhoto(double lng, double lat, string name, string p)
{
	PhotoPtr photo(new Photo(lng, lat, name, p));
	this->objetsmult[name] = photo;
	return photo;
}

VideoPtr Library::createVideo(int d, string name, string p)
{
	VideoPtr video(new Video(d, name, p));
	this->objetsmult[name] = video;
    return video;
}

FilmPtr Library::createFilm(int * chap, int n, int d, string name, string p)
{
	FilmPtr film(new Film(chap, n, d, name, p));
	this->objetsmult[name] = film;
	return film;
}

GroupePtr Library::createGroupe(string n)
{
	GroupePtr groupe(new Groupe(n));
	this->groupes[n] = groupe;
	return groupe;
}

void Library::displayMult(string name, ostream & stream)
{
	auto element = this->objetsmult.find(name);
	if(element != this->objetsmult.end())
		element->second->affichage( stream );
	else
		stream << "OBJET NON TROUVE " << endl;

}

void Library::displayGroup(string name, ostream & stream)
{
	auto element = this->groupes.find(name);
	if(element  != this->groupes.end())
		element->second->display(stream);
	else
		stream << "GROUPE NON TROUVE " << endl;
}

void Library::play(string name)
{
	auto element = this->objetsmult.find(name);
	if(element != this->objetsmult.end())
		element->second->play();
	else
		cout << "FICHIER NON TROUVE " << endl;
}
void Library::remove(string name)
{
    this->objetsmult.erase(name);
    for(auto g : this->groupes)
    {
        auto it = g.second->begin();
        while (it != g.second->end())
        {
            if(it->get()->getName() == name)
                it = g.second->erase(it);
            else
                it++;
        }
    }

}
