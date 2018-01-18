#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"

class Video : public Multimedia
{
public:
	
    Video(int d = 0, std::string name = "" , std::string p = "") : Multimedia(name, p) { duration = d; }
    ~Video() {}


    int getDuration() const { return duration; }
    void setDuration(int d) { duration = d ;}


    void play() const override { system(("mpv " + this->getPath() + " &").c_str()); }

    virtual void affichage(std::ostream& stream) const override {
        Multimedia::affichage(stream); stream << " Durée : " << duration;
    }

    virtual void write(std::ostream &f) const override{
        Multimedia::write(f);
        f << duration << std::endl;
    }

    virtual void read(std::istream &f) override{
        Multimedia::read(f);
        f >> duration;
    }

private:
    int duration;
};

#endif // VIDEO_H
