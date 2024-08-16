#ifndef AUTOBUS_H
#define AUTOBUS_H

#include "Vozilo.h"


class Autobus : public Vozilo{
    public:
        Autobus(int ulazKruzniTok,int izlazKruzniTok) : Vozilo(ulazKruzniTok,izlazKruzniTok){
            this->setDuzina(1);
        }
        string dohvatiVrstuVozila() const override{
            return "Autobus";
        }
};





#endif