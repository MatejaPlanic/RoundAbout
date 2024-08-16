#include <iostream>
#include "Vozila/Automobil.h"
#include "Vozila/Autobus.h"
#include "Vozila/Kamion.h"
#include "Vozila/Motor.h"
#include "KruzniTok/KruzniTok.h"
#include <cstdlib>
#include <thread>
#include <unistd.h>
#include "mutex"
#include "Greske/GreskaNemaMestaNaUlazu.h"
mutex Semafor;

using namespace std;

void GenerisiRandomVozila(KruzniTok *kt)
{
    while (1)
    {
        Semafor.lock();
        int pom = rand() % 4;

        if(pom == 0)
        {
            Automobil *a = new Automobil((rand()%5 +1),(rand()%5 +1));
            try{
                kt->dodajNaUlaz(a); 
            }
            catch(GreskaNemaMestaNaUlazu g)
            {
                cout << g.what() <<endl;
            }
        }

        if(pom == 1)
        {
            Motor *m = new Motor((rand()%5 +1),(rand()%5 +1));
            try{
                kt->dodajNaUlaz(m);
            }
            catch(GreskaNemaMestaNaUlazu g) 
            {
                cout << g.what() <<endl;
            }
        }

        if(pom == 2)
        {
            Kamion *k = new Kamion((rand()%5 +1),(rand()%5 +1));
            try{
                kt->dodajNaUlaz(k); 
            }
            catch(GreskaNemaMestaNaUlazu g)
            {
                cout << g.what() <<endl;
            }
        }

        if(pom == 3)
        {
            Autobus *au = new Autobus((rand()%5 +1),(rand()%5 +1));
            try{
                kt->dodajNaUlaz(au);
            }
            catch(GreskaNemaMestaNaUlazu g)
            {
                cout << g.what() <<endl;
            }
        }

        Semafor.unlock();
        sleep(5);
    }
}

void KreniDodavanje(KruzniTok *kt)
{
    while(1)
    {
        
        int pom = rand() % 5 + 1;
        if(kt->dajPrvog(pom))
        {
            Semafor.lock();
            if(kt->dodajNaTraku(kt->dajPrvog(pom)))
                cout << "Vozilo sa ulaza " << pom << " Ulazi u kruzni tok" <<endl;
            Semafor.unlock();
            sleep(5);
        }
        
        
    }
}

void PokreciVozilaRand(KruzniTok *kt)
{
        kt->PokreniVozila();
}


int main()
{
    KruzniTok *kt = new KruzniTok();

    thread t1(PokreciVozilaRand,kt);
    thread t2(GenerisiRandomVozila,kt);
    thread t3(KreniDodavanje,kt);

    t1.join();
    t2.join();
    t3.join();
    delete kt;
    return 0;
}