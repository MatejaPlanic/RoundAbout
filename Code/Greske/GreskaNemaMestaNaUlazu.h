#ifndef GRESKANEMAMESTANAULAZU_H
#define GRESKANEMAMESTANAULAZU_H

#include <iostream>
#include <exception>
using namespace std;

class GreskaNemaMestaNaUlazu : public exception{

    public:
        const char* what() const throw() override{
            return "Ulaz je pun !!!";
        }


};



#endif