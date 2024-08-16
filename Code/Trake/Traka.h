#ifndef TRAKA_H
#define TRAKA_H

#include "../Vozila/Vozilo.h"
#define BROJ_PODEOKA 20



class Traka{

    public:
        class Podeok{
            bool dalJeZauzet = false;
            Vozilo* v = nullptr;
            public:
                void setZauzet(Vozilo *pom) {
                    dalJeZauzet = true;
                    v=pom;
                }
                bool getZauzet() const
                {
                    return dalJeZauzet;
                }
                Vozilo* getVozilo() const
                {
                    return v;
                }
                void setNijeZauzet()
                {
                    dalJeZauzet = false;
                    v=nullptr;
                }
                
        };
    private:
        Podeok nizPodeoka[BROJ_PODEOKA];

    public:
        bool zauzetPodeok(int Podeok) const
        {
            return nizPodeoka[Podeok].getZauzet();
        }
        double ukupnoDuzina()
        {
            double pom = 0;
            for(auto i : nizPodeoka)
            {
                if(i.getZauzet() == true)
                {
                    pom+=1;
                }
            }
            return pom;
        }
        Podeok* getNiz()
        {
            return nizPodeoka;
        }


};





#endif