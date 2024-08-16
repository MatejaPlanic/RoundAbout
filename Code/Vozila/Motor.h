#ifndef MOTOR_H
#define MOTOR_H

#include "Vozilo.h"

class Motor : public Vozilo{
    
    public:
        Motor(int ulazKruzniTok,int izlazKruzniTok) : Vozilo(ulazKruzniTok,izlazKruzniTok){
            this->setDuzina(1);
        }
        string dohvatiVrstuVozila() const override{
            return "Motor";
        }

};

#endif