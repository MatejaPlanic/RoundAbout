#ifndef VOZILO_H
#define VOZILO_H


#include <iostream>
using namespace std;

class Vozilo{
    private:
        double duzinaVozila;
        int ulazKruzniTok;
        int izlazKruzniTok;
        int Id;
        static int brojacVozila;
    
    public:
        Vozilo(int,int);
        void setDuzina(double);
        int dohvatiUlaz() const;
        int dohvatiIzlaz() const;
        double dohvatiDuzinu() const;
        virtual string dohvatiVrstuVozila() const = 0;
        int IdVozila() const;
        friend ostream& operator << (ostream&,Vozilo&);

};

#endif