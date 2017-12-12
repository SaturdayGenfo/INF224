//
//  main.cpp
//  

#include <iostream>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "groupe.h"

using namespace std;

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


}