#include "library.h"
using namespace std;
using namespace cppu;


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

bool Library::processRequest(TCPConnection& cnx, const string& request, string& response)
{
  cerr << "\nRequest: '" << request << "'" << endl;
  string command, name;
  stringstream ss;
  ss.str(request);
  ss >> command >> name;
  cout << name << endl;
  // 2) faire le traitement:
  // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
  // - sinon juste: TCPLock lock(cnx);
  stringstream stream;



  if(command=="searchgrp")
  {

      this->displayGroup(name, stream);

  }
  else if(command=="searchmult")
  {

      this->displayMult(name, stream);

  }
  else if(command=="play")
  {
      this->play(name);
  }





  // 3) retourner la reponse au client:
  // - pour l'instant ca retourne juste OK suivi de la requête
  // - pour retourner quelque chose de plus utile on peut appeler la methode print()
  //   des objets ou des groupes en lui passant en argument un stringstream
  // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
  //   ils servent à délimiter les messages entre le serveur et le client

  response = stream.str();
  cerr << "response : ";
  cerr << response;
  cerr << endl;

  // renvoyer false si on veut clore la connexion avec le client
  return true;
}
