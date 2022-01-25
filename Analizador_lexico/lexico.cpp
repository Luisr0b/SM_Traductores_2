#include "lexico.h"

  Lexico::Lexico(string fuente){
    ind= 0;                  
    this->fuente= fuente;
  }      

  Lexico::Lexico(){
    ind= 0;                  
  }      
  
  string Lexico::tipoAcad(int tipo){
         string cad= "";
         
         switch (tipo){
           case TipoSimbolo::IDENTIFICADOR:
                cad= "  0";
                break;
                
           case TipoSimbolo::OPSUMA:
                cad= "  5";
                break;

           case TipoSimbolo::OPMULT:
                cad= "  6";
                break;            

           case TipoSimbolo::PESOS:
                cad= "Fin de la Entrada";
                break;            

           case TipoSimbolo::ENTERO:
                cad= "  1";
                break;
                
         }
         
         return cad;
  }
  
  void Lexico::entrada(string fuente){
       ind= 0;                  
      this->fuente= fuente;
  }

int Lexico::sigSimbolo(){
    
    estado=0;
    continua= true;
    simbolo= "";
    
    //Inicio del Automata
    while (continua){
      c= sigCaracter();
      
      switch (estado){
        case 0:
             if ( c == '+' || c=='-') aceptacion(5);
             else
              if ( c == '$' ) aceptacion(3);
              else
               if (( c >= 'A' && c<= 'Z') || ( c >= 'a' && c<= 'z')) aceptacion(0);
               else
                if ( c >= '0' && c<= '9') aceptacion(4);
                 else
                  if ( c == '*' || c=='/') aceptacion(6);

             break;
                                       
      }  
           
   }    
    //Fin del Automata
    
      switch (estado){
              
        case 5:
            tipo= TipoSimbolo::OPSUMA;
            break;
		case 6:
            tipo= TipoSimbolo::OPMULT;
            break; 
        case 0:
        	tipo= TipoSimbolo::IDENTIFICADOR;
            break;
		case 4:
            tipo= TipoSimbolo::ENTERO;
            break; 
              
        dafault:                 
              tipo= TipoSimbolo::ERROR;
      }
    		
	return tipo;
}

 char Lexico::sigCaracter(){
      if (terminado()) return '$';
      
      return fuente[ind++];
 }

  void Lexico::sigEstado(int estado){
       this->estado= estado;
       simbolo+= c;
  }
  
  void Lexico::aceptacion(int estado){
       sigEstado(estado);
       continua= false;
  }

  bool Lexico::terminado(){//fin de cadena
         return ind >= fuente.length();
  }

   bool Lexico::esLetra(char c){
        return isalpha(c) || c=='_';
   }
   
   
   bool Lexico::esDigito(char c){
        return isdigit(c);
   }
   
   bool Lexico::esEspacio(char c){
        return c== ' ' || c== '\t';        
   }

            
   void Lexico::retroceso(){
      if ( c != '$') ind--;
        continua= false;
    }
