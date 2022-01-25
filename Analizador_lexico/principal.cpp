#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "lexico.cpp"

using namespace std;

int main(int argc, char *argv[]){
    
    Lexico lexico;
    //llamamos a la funcion entreda de lexico
    lexico.entrada("robles estrada\" + } 1998 / 135.48 >= ! != && , if ( ) else while  int  {  = return ; ");
    
    cout << "Resultado del Analisis Lexico" << endl << endl;
    cout << "Simbolo\t\tTipo" << endl;
    
    while (lexico.simbolo.compare("$") != 0 ){
        //llamamos a la funcion sigSimbolo
        lexico.sigSimbolo();
        cout <<  lexico.simbolo << "\t\t" << lexico.tipoAcad(lexico.tipo) << endl;          
    }
        
    cin.get();
    return 0;
}
