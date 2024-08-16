#ifndef KAMION_H
#define KAMION_H

#include "Vozilo.h"

class Kamion : public Vozilo{
    public:
        Kamion(int ulazKruzniTok,int izlazKruzniTok) : Vozilo(ulazKruzniTok,izlazKruzniTok){
            this->setDuzina(1);
        }
        string dohvatiVrstuVozila() const override{
            return "Kamion";
        }

};



#endif