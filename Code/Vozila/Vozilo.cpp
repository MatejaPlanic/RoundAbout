#include "Vozilo.h"

int Vozilo:: brojacVozila = 0;

Vozilo::Vozilo(int ulazKruzniTok , int izlazKruzniTok) : ulazKruzniTok(ulazKruzniTok), izlazKruzniTok(izlazKruzniTok),Id(brojacVozila++){}

int Vozilo::dohvatiUlaz() const
{
    return ulazKruzniTok;
}

int Vozilo::dohvatiIzlaz() const
{
    return izlazKruzniTok;
}
double Vozilo::dohvatiDuzinu() const
{
    return duzinaVozila;
}

int Vozilo::IdVozila() const
{
    return Id;
}

void Vozilo::setDuzina(double duz)
{
    duzinaVozila = duz;
}

ostream& operator << (ostream& izlaz , Vozilo& v)
{
    return izlaz << "Id Vozila: " << v.IdVozila() << " | Vozilo tipa: " << v.dohvatiVrstuVozila() << " | Duzine: " << v.dohvatiDuzinu() <<" | Ulazi na ulaz: " << v.dohvatiUlaz() << " | Izlazi na izlaz: " <<v.dohvatiIzlaz() <<endl;
}