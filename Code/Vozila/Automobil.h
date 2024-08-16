#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include "Vozilo.h"

class Automobil : public Vozilo{
    public:
        Automobil(int ulazKruzniTok,int izlazKruzniTok) : Vozilo(ulazKruzniTok,izlazKruzniTok){
            this->setDuzina(1);
        }
        string dohvatiVrstuVozila() const override{
            return "Automobil";
        }
};

#endif