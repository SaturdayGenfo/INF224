#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"

class Photo : public Multimedia
{
public:
    Photo(double lng = 0, double lat = 0, std::string name = "" , std::string p = "") : Multimedia(name, p) {
        longitude = lng; lattitude = lat;
    }

    double getLongitude() const {return longitude; }
    void setLongitude(double l) { longitude = l ;}
    double getLattitude() const { return lattitude ;}
    void setLattitude(double l) { lattitude = l ;}

    void play() const override { system(("imagej " + this->getPath() + " &").c_str()) ;}

    void affichage(std::ostream& stream) const override {
        Multimedia::affichage(stream) ;
        stream << " Longitude : " << longitude  << " ; Lattitude : " << lattitude;
    }

    void write(std::ostream &f) const override {
        Multimedia::write(f);
        f << longitude << lattitude << std::endl;
    }

    void read(std::istream &f) override {
        Multimedia::read(f);
        f >> longitude >> lattitude;
    }

private:
    double longitude;
    double lattitude;
};

#endif // PHOTO_H
