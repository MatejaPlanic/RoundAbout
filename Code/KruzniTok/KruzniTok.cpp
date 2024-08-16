#include "KruzniTok.h"
#include "../Greske/GreskaNemaMestaNaUlazu.h"
#include <unistd.h>
void KruzniTok::dodajNaUlaz(Vozilo *v)
{
    switch(v->dohvatiUlaz())
    {
        case 1:
        {
            if(ulaz1.size() < VOZILANAULAZU)
                ulaz1.push_back(v);
            else
                throw GreskaNemaMestaNaUlazu();
            break;
        }

        case 2:
        {
            if(ulaz2.size() < VOZILANAULAZU)
                ulaz2.push_back(v);
            else
                throw GreskaNemaMestaNaUlazu();
            break;
        }

        case 3:
        {
            if(ulaz3.size() < VOZILANAULAZU)
                ulaz3.push_back(v);
            else
                throw GreskaNemaMestaNaUlazu();
            break;
        }

        case 4:
        {
            if(ulaz4.size() < VOZILANAULAZU)
                ulaz4.push_back(v);
            else
                throw GreskaNemaMestaNaUlazu();
            break;
        }

        case 5:
        {
            if(ulaz5.size() < VOZILANAULAZU)
                ulaz5.push_back(v);
            else
                throw GreskaNemaMestaNaUlazu();
            break;
        }
    }
}

Vozilo * KruzniTok::izbaciSaUlaza(int ulaz)
{
    switch (ulaz)
    {
    case 1:
        {
            Vozilo *pom = ulaz1.front();
            ulaz1.pop_front();
            return pom;
        }
    case 2:
        {
            Vozilo *pom = ulaz2.front();
            ulaz2.pop_front();
            return pom;
        }
    case 3:
        {
            Vozilo *pom = ulaz3.front();
            ulaz3.pop_front();
            return pom;
        }
    case 4:
        {
            Vozilo *pom = ulaz4.front();
            ulaz4.pop_front();
            return pom;
        }
    case 5:
        {
            Vozilo *pom = ulaz5.front();
            ulaz5.pop_front();
            return pom;
        }
    default:
    {
       return NULL;
    }
    }
}

Vozilo * KruzniTok::dajPrvog(int ulaz) const
{
    switch (ulaz)
    {
        case 1:
        {
            return ulaz1.front();
        }

        case 2:
        {
            return ulaz2.front();
        }

        case 3:
        {
            return ulaz3.front();
        }

        case 4:
        {
            return ulaz4.front();
        }

        case 5:
        {
            return ulaz5.front();
        }
    }
    return NULL;
}

bool KruzniTok::stigoDoIzlaza(Vozilo *v , int stigo) const
{
    if(v==nullptr) return false;
    switch (v->dohvatiIzlaz())
    {
        case 1:
            {
                if(stigo == 19)
                    return true;
                break;
            }
        case 2:
            {
                if(stigo == 3)
                    return true;
                break;
            }
        case 3:
            {
                if(stigo == 7)
                    return true;
                break;
            }
        case 4:
            {
                if (stigo == 11)
                    return true;
                break;
            }
        case 5:
            {
                if(stigo == 15)
                    return true;
                break;
            }
        default:
            return false;
    }

    return false;
}

bool KruzniTok::dodajNaTraku(Vozilo *v)
{
    switch (v->dohvatiUlaz())
    {
        case 1:
            {
                if(v->dohvatiVrstuVozila() == "Automobil" || v->dohvatiVrstuVozila() == "Motor"){
                    if((trake[0].getNiz()[19].getZauzet() == false || trake[0].getNiz()[19].getVozilo()->dohvatiIzlaz()==1) && (trake[0].getNiz()[0].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 2 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu())<=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[0].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[19].getZauzet() == false  && trake[1].getNiz()[0].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[0].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }
                }
                else
                {
                    if((trake[0].getNiz()[19].getZauzet() == false || trake[0].getNiz()[19].getVozilo()->dohvatiIzlaz()==1) && (trake[0].getNiz()[0].getZauzet() == false) && (trake[0].getNiz()[1].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 2 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu())<=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[0].setZauzet(v);
                            trake[0].getNiz()[1].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[19].getZauzet() == false  && trake[1].getNiz()[0].getZauzet() == false && trake[1].getNiz()[1].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[0].setZauzet(v);
                                trake[1].getNiz()[1].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }

                }
                break;
            }
        
        case 2:
            {
                 if(v->dohvatiVrstuVozila() == "Automobil" || v->dohvatiVrstuVozila() == "Motor"){
                if((trake[0].getNiz()[3].getZauzet() == false || trake[0].getNiz()[3].getVozilo()->dohvatiIzlaz()==2) && (trake[0].getNiz()[4].getZauzet() == false))
                {
                    if(v->dohvatiIzlaz() == 3 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                    {
                        trake[0].getNiz()[4].setZauzet(v);
                        this->izbaciSaUlaza(v->dohvatiUlaz());
                        return true;
                    }
                    else
                    {
                        if(trake[1].getNiz()[3].getZauzet() == false  && trake[1].getNiz()[4].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                        {
                            trake[1].getNiz()[4].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                    }
                }
                else
                    {
                        sleep(1);
                    }
                 }
                 else
                {
                    if((trake[0].getNiz()[3].getZauzet() == false || trake[0].getNiz()[3].getVozilo()->dohvatiIzlaz()==2) && (trake[0].getNiz()[4].getZauzet() == false) && (trake[0].getNiz()[5].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 3 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu())<=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[4].setZauzet(v);
                            trake[0].getNiz()[5].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[3].getZauzet() == false  && trake[1].getNiz()[4].getZauzet() == false && trake[1].getNiz()[5].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[4].setZauzet(v);
                                trake[1].getNiz()[5].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }

                }
                
                break;
            }

        case 3:
            {
                  if(v->dohvatiVrstuVozila() == "Automobil" || v->dohvatiVrstuVozila() == "Motor"){
                    if((trake[0].getNiz()[7].getZauzet() == false || trake[0].getNiz()[7].getVozilo()->dohvatiIzlaz()==3) && (trake[0].getNiz()[8].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 4 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[8].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[7].getZauzet() == false  && trake[1].getNiz()[8].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu())<=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[8].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }
                }
                else
                {
                    if((trake[0].getNiz()[7].getZauzet() == false || trake[0].getNiz()[7].getVozilo()->dohvatiIzlaz()==3) && (trake[0].getNiz()[8].getZauzet() == false) && (trake[0].getNiz()[9].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 4 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu())<=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[8].setZauzet(v);
                            trake[0].getNiz()[9].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[7].getZauzet() == false  && trake[1].getNiz()[8].getZauzet() == false && trake[1].getNiz()[9].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[8].setZauzet(v);
                                trake[1].getNiz()[9].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }

                }
                break;
            }

        case 4:
        {
            if(v->dohvatiVrstuVozila() == "Automobil" || v->dohvatiVrstuVozila() == "Motor"){
                if((trake[0].getNiz()[11].getZauzet() == false || trake[0].getNiz()[11].getVozilo()->dohvatiIzlaz()==4) && (trake[0].getNiz()[12].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 5 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[12].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[11].getZauzet() == false  && trake[1].getNiz()[12].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[12].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }
            }
            else
            {
                if((trake[0].getNiz()[11].getZauzet() == false || trake[0].getNiz()[11].getVozilo()->dohvatiIzlaz()==3) && (trake[0].getNiz()[12].getZauzet() == false) && (trake[0].getNiz()[13].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 5 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu())<=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[12].setZauzet(v);
                            trake[0].getNiz()[13].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[11].getZauzet() == false  && trake[1].getNiz()[12].getZauzet() == false && trake[1].getNiz()[13].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[12].setZauzet(v);
                                trake[1].getNiz()[13].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }
            }
                break;
        }

        case 5:
        {
            if(v->dohvatiVrstuVozila() == "Automobil" || v->dohvatiVrstuVozila() == "Motor"){
                if((trake[0].getNiz()[15].getZauzet() == false || trake[0].getNiz()[15].getVozilo()->dohvatiIzlaz()==5) && (trake[0].getNiz()[16].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 1 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[16].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[15].getZauzet() == false  && trake[1].getNiz()[16].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[16].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }
            }
            else{
                if((trake[0].getNiz()[15].getZauzet() == false || trake[0].getNiz()[15].getVozilo()->dohvatiIzlaz()==3) && (trake[0].getNiz()[16].getZauzet() == false) && (trake[0].getNiz()[17].getZauzet() == false))
                    {
                        if(v->dohvatiIzlaz() == 1 && ((trake[0].ukupnoDuzina() + v->dohvatiDuzinu())<=BROJ_PODEOKA))
                        {
                            trake[0].getNiz()[16].setZauzet(v);
                            trake[0].getNiz()[17].setZauzet(v);
                            this->izbaciSaUlaza(v->dohvatiUlaz());
                            return true;
                        }
                        else
                        {
                            if(trake[1].getNiz()[15].getZauzet() == false  && trake[1].getNiz()[16].getZauzet() == false && trake[1].getNiz()[17].getZauzet() == false && ((trake[1].ukupnoDuzina() + v->dohvatiDuzinu()) <=BROJ_PODEOKA))
                            {
                                trake[1].getNiz()[16].setZauzet(v);
                                trake[1].getNiz()[17].setZauzet(v);
                                this->izbaciSaUlaza(v->dohvatiUlaz());
                                return true;
                            }
                        }
                    }
                    else
                    {
                        sleep(1);
                    }
            }
                break;
        }

    }
    return false;
}

void KruzniTok::PokreniVozila()
{
    cout << "UCITAVANJE SVIH VOZILA, KRUZNOG TOKA I POKRETANJE SIMULACIJE..." <<endl;
    while(1){
        for(int j=0;j<BROJ_PODEOKA;j++)
        {
            sleep(1);
            if(trake[0].getNiz()[j].getZauzet() == true)
            {
                if(trake[0].getNiz()[j].getVozilo()->dohvatiVrstuVozila() == "Automobil" || trake[0].getNiz()[j].getVozilo()->dohvatiVrstuVozila() == "Motor"){
                if(stigoDoIzlaza(trake[0].getNiz()[j].getVozilo(),j))
                    {
                        cout << "------------------------------------" << endl;
                        cout << "VOZILO " << *(trake[0].getNiz()[j].getVozilo()) << "se iskljucilo" << endl;
                        cout << "------------------------------------" << endl;
                        trake[0].getNiz()[j].setNijeZauzet();
                    }
                else
                    {
                        if(trake[0].getNiz()[(j+1)%BROJ_PODEOKA].getZauzet() == false)
                        {
                            cout << "VOZILO: " << *(trake[0].getNiz()[j].getVozilo()) << "SE POMERILO SA " << j << "NA" << (j+1)%BROJ_PODEOKA << endl;
                            trake[0].getNiz()[(j+1)%BROJ_PODEOKA].setZauzet(trake[0].getNiz()[j].getVozilo());
                            trake[0].getNiz()[j].setNijeZauzet();
                        }
                    }

                }
                else
                {
                    if(trake[0].getNiz()[(j+1)%BROJ_PODEOKA].getZauzet() == true && (trake[0].getNiz()[(j+1)%BROJ_PODEOKA].getVozilo()->IdVozila() == trake[0].getNiz()[j].getVozilo()->IdVozila()))
                    {
                        if(stigoDoIzlaza(trake[0].getNiz()[(j+1)%BROJ_PODEOKA].getVozilo(),(j+1)%BROJ_PODEOKA))
                        {
                            cout << "------------------------------------" << endl;
                            cout << "VOZILO " << *(trake[0].getNiz()[j].getVozilo()) << "se iskljucilo" << endl;
                            cout << "------------------------------------" << endl;
                            trake[0].getNiz()[j].setNijeZauzet();
                            trake[0].getNiz()[(j+1)%BROJ_PODEOKA].setNijeZauzet();
                        }
                        else
                        {
                            if(trake[0].getNiz()[(j+2)%BROJ_PODEOKA].getZauzet() == false)
                            {
                                cout << "VOZILO: " << *(trake[0].getNiz()[j].getVozilo()) << "SE POMERILO SA " << (j+1)%BROJ_PODEOKA << "NA" << (j+2)%BROJ_PODEOKA << endl;
                                trake[0].getNiz()[(j+2)%BROJ_PODEOKA].setZauzet(trake[0].getNiz()[j].getVozilo());
                                trake[0].getNiz()[j].setNijeZauzet();
                            }
                        }
                    }
                    
                }
            }
            if(trake[1].getNiz()[j].getZauzet() == true)
            {
                
                if(trake[1].getNiz()[j].getVozilo()->dohvatiVrstuVozila() == "Automobil" || trake[1].getNiz()[j].getVozilo()->dohvatiVrstuVozila() == "Motor")
                {
                      
                    if(stigoDoIzlaza(trake[1].getNiz()[j].getVozilo(),j))
                    {
                        if(trake[0].getNiz()[j].getZauzet() == false && trake[0].getNiz()[j==0?19:(j-1)].getZauzet() == false)
                            {
                                cout<<"------------------------------------" << endl;
                                cout << "VOZILO " << *(trake[1].getNiz()[j].getVozilo()) << "se iskljucilo" << endl;
                                cout << "------------------------------------" << endl;
                                trake[1].getNiz()[j].setNijeZauzet();
                            }
                    }
                    else
                    {
                        if(trake[1].getNiz()[(j+1)%BROJ_PODEOKA].getZauzet() == false)
                        {
                            cout << "VOZILO: " << *(trake[1].getNiz()[j].getVozilo()) << "SE POMERILO SA " << j << "NA" << (j+1)%BROJ_PODEOKA << endl;
                            trake[1].getNiz()[(j+1)%BROJ_PODEOKA].setZauzet(trake[1].getNiz()[j].getVozilo());
                            trake[1].getNiz()[j].setNijeZauzet();
                        }
                    }
                }
                else
                {
                        if(trake[1].getNiz()[(j+1)%BROJ_PODEOKA].getZauzet() == true && (trake[1].getNiz()[(j+1)%BROJ_PODEOKA].getVozilo()->IdVozila() == trake[1].getNiz()[j].getVozilo()->IdVozila()))
                        {
                            if(stigoDoIzlaza(trake[1].getNiz()[(j+1)%BROJ_PODEOKA].getVozilo(),((j+1)%BROJ_PODEOKA)))
                            {
                                if(trake[0].getNiz()[j].getZauzet() == false && trake[0].getNiz()[j==0?19:(j-1)].getZauzet() == false && trake[0].getNiz()[(j+1)%BROJ_PODEOKA].getZauzet() == false)
                                    {
                                        cout << "------------------------------------" << endl;
                                        cout << "VOZILO " << *(trake[1].getNiz()[j].getVozilo()) << "se iskljucilo" << endl;
                                        cout << "------------------------------------" << endl;
                                        trake[1].getNiz()[j].setNijeZauzet();
                                        trake[1].getNiz()[(j+1)%BROJ_PODEOKA].setNijeZauzet();
                                    }
                            }
                            else
                            {
                       
                                if(trake[1].getNiz()[(j+2)%BROJ_PODEOKA].getZauzet() == false)
                                {
                                    cout << "VOZILO: " << *(trake[1].getNiz()[j].getVozilo()) << "SE POMERILO SA " << (j+1)%BROJ_PODEOKA << "NA" << (j+2)%BROJ_PODEOKA << endl;
                                    trake[1].getNiz()[(j+2)%BROJ_PODEOKA].setZauzet(trake[1].getNiz()[j].getVozilo());
                                    trake[1].getNiz()[j].setNijeZauzet();
                                }
                            }
                        }
                }
            }
        }
    }
}

KruzniTok::~KruzniTok()
{
    for(auto it = ulaz1.begin() ; it!=ulaz1.end() ; it++)
    {
        delete *it;
    }

    for (auto it = ulaz2.begin() ; it!=ulaz2.end() ; it++)
    {
        delete *it;
    }

    for (auto it = ulaz3.begin() ; it!=ulaz3.end() ; it++)
    {
        delete *it;
    }

    for (auto it = ulaz4.begin() ; it!=ulaz4.end() ; it++)
    {
        delete *it;
    }

    for (auto it = ulaz5.begin() ; it!=ulaz5.end() ; it++)
    {
        delete *it;
    }
}