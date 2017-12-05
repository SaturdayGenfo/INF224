//
//  main.cpp
//  

#include <iostream>
#include "multimedia.h"
#include "photo.h"
#include "video.h"

using namespace std;

int main(int argc, char* argv[]) {



  std::cout << "Hello World" << std::endl;
  int n = 3;

  Multimedia*  table [] = {new Photo(0.5, 156, "The Incredebiles", "c:/file/movie.avi"), new Video(56, "The departed", "c:/scorcese.mov"), new Video(5, "Burn After Reading ", "Z:/mooovie.mp4")};
  for(int i=0; i < n; i++)
      table[i]->affichage(cout);

}
