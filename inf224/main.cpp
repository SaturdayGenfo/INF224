//
//  main.cpp
//  

#include <iostream>
#include <fstream>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "groupe.h"
#include "library.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;


int main(int argc, char* argv[]) {



  std::cout << "Testing interface" << std::endl;
  int n = 3;

  Multimedia*  table [] = {new Photo(0.5, 156, "The Incredebiles", "c:/file/movie.avi"), new Video(56, "The departed", "c:/scorcese.mov"), new Video(5, "Burn After Reading ", "Z:/mooovie.mp4")};
  for(int i=0; i < n; i++)
      table[i]->affichage(cout);

  Film * f = new Film();
  int test [] = {1, 2, 3, 4};
  f->setChapitres(test, 4);

  int const * x = f->getChapitres();
  int len = f->getNChapitres();

  for(int k=0; k<len; k++)
  	cout << x[k] << " ";
  cout << endl;


  Groupe * g = new Groupe("Vacances");
  MultimediaPtr m(new Photo(0.5, 156, "The Incredebiles", "c:/file/movie.avi"));

  g->push_back(m);
  g->push_back(MultimediaPtr(new Video(56, "The departed", "c:/scorcese.mov")));
  Groupe * g2 = new Groupe("Second Groupe");
  g2->push_back(m);
  g2->push_back(MultimediaPtr((new Video(5, "Burn After Reading ", "Z:/mooovie.mp4"))));

  g->display(cout);
  delete g;
  g2->display(cout);
  delete g2;

  m.reset();

  shared_ptr<Library> l(new Library());
  VideoPtr v = l->createVideo(5, "Burn After Reading ", "Z:/mooovie.mp4");
  VideoPtr v2 = l->createVideo(899, "Goodfellas", "C:/downnloads/movie.movie");
  PhotoPtr p = l->createPhoto(45, 78, "pic", "image.jpg");
  GroupePtr GG = l->createGroupe("MOVIES");

  GG->push_back(v);
  GG->push_back(v2);
  /*


  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());


  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*l, &Library::processRequest);

  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
    */

  ofstream file("serial.txt");

  f->write(file);

  file.close();

  ifstream file2("serial.txt");
  FilmPtr testing(new Film());
  testing->read(file2);
  cout << "HERE IS WHAT I WAS ABLE TO READ ////" << endl;
  testing->affichage(cout);


  return 0;



}
