#ifndef KRUZNITOK_H
#define KRUZNITOK_H

#include "../Vozila/Vozilo.h"
#include "../Trake/Traka.h"
#include <deque>
#define BROJ_TRAKA 2
#define VOZILANAULAZU 8



class KruzniTok{

    private:
        deque <Vozilo*> ulaz1;
        deque <Vozilo*> ulaz2;
        deque <Vozilo*> ulaz3;
        deque <Vozilo*> ulaz4;
        deque <Vozilo*> ulaz5;
        Traka trake[BROJ_TRAKA];

    public:
        ~KruzniTok();
        void dodajNaUlaz(Vozilo*);
        Vozilo* izbaciSaUlaza(int);
        void PokreniVozila();
        bool stigoDoIzlaza(Vozilo*,int) const;
        Vozilo* dajPrvog(int) const;
        bool dodajNaTraku (Vozilo*);
};







#endif