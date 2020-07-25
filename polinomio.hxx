//
//  polinomio.cpp
//  practica5
//
//  Created by Gregorio Vidoy Fajardo & JotaEle Díaz on 16/12/14.
//  Copyright (c) 2014 JotaEle Díaz. All rights reserved.
//


#include <iostream>


using namespace std;


/************************************************************ */
/*                    CLASS POLINOMIO<T>                      */
/**************************************************************/



////////// CONSTRUCTORES /////////////


polinomio::polinomio(){
    
}


polinomio::polinomio(const polinomio & otro) {
    vPolinomio = otro.vPolinomio;
    (*this).n_monomios = otro.n_monomios;
}


////////// DESTRUCTOR /////////////


polinomio::~polinomio(){
    
}
 

 
/////////// CONSULTORES ////////////


int polinomio::getGrado(){
    return (vPolinomio.size()-1);
}


int polinomio::getCoeficiente(int gm){
    return vPolinomio[gm];
}


ostream& operator<< (ostream &os, const polinomio &p) {
    
    polinomio::const_iterator itbegin = p.cbegin();
    polinomio::const_iterator itend = p.cend();
    
    bool primeraiteracion = true;
    
    while (itend != itbegin) {
        
        --itend;
        
        
        if((*itend).first == 1 ) {
            
            if (!primeraiteracion) { cout << "+ "; }
            os << (*itend).second << "x ";
            
        } else if( (*itend).first == 0 ) {
            
            if (!primeraiteracion) { cout << "+ "; }
            os << (*itend).second << " ";
            
        } else {
            
            if (!primeraiteracion) { cout << "+ "; }
            os << (*itend).second << "x^" << (*itend).first << " ";
            
        }
        
        primeraiteracion = false;
        
    }
    
    return os;
}



////////// MODIFICADORES /////////////


void polinomio::setMonomio(int c, int g){
    
    if(g < vPolinomio.size()){
     
        if(vPolinomio[g] == 0){
            n_monomios++;
        }
            
        vPolinomio.assign(g,c);
        
    } else {

        vPolinomio.resize(g);
        vPolinomio.push_back(c);           
        //vPolinomio.resize(g);
        n_monomios++;
    }
    
}



////////// OPERADORES ///////////


polinomio & polinomio::operator= (const polinomio & otro){
    (*this).vPolinomio = otro.vPolinomio;
    (*this).n_monomios = otro.n_monomios;
    
    return (*this);
}


polinomio polinomio::operator+ (const polinomio & otro){
    
    polinomio copia(otro);
    
    polinomio retorno((*this));
    
    polinomio::iterator it_begin = (*this).begin();
    polinomio::iterator it_begin_otro = copia.begin();
    polinomio::iterator it_end_otro = copia.end();
    polinomio::iterator it_end = (*this).end();;
    
    
    while((it_begin != it_end) && (it_begin_otro != it_end_otro)){
        
        
        if((*it_begin).first < (*it_begin_otro).first){
            
            it_begin++;
            
        } else if((*it_begin).first > (*it_begin_otro).first){
            
            retorno.setMonomio((*it_begin_otro).second, (*it_begin_otro).first);
            
            it_begin_otro++;
            
        } else {
            
            retorno.setMonomio((*it_begin).second + (*it_begin_otro).second ,(*it_begin).first);
            
            it_begin++;
            it_begin_otro++;
        }
    }
    
    
    while(it_begin_otro != it_end_otro) {
        
        retorno.setMonomio((*it_begin_otro).second, (*it_begin_otro).first);
        
        it_begin_otro++;
    }
    
    return retorno;
}


polinomio polinomio::operator- ( polinomio & otro){
    
    const polinomio otronegat = -otro;
    polinomio retorno;
    
    retorno = (*this) + otronegat;
    
    return retorno;

}


polinomio polinomio::operator-(){
    
    polinomio::iterator it_begin = (*this).begin();
    polinomio::iterator it_end = (*this).end();
    
    polinomio retorno((*this));
    
    while ( it_begin != it_end) {
        
            
        int nuevo = ((*it_begin).second) - (((*it_begin).second)*2);
            
        retorno.setMonomio( nuevo, ((*it_begin).first) );
        
        ++it_begin;
        
    }
    
    return retorno;
}



/////////////// MÉTODOS SOBRE LOS ITERADORES ////////////////


polinomio::iterator polinomio::begin(){
    
    polinomio::iterator it_begin;
    
    it_begin.it = vPolinomio.sbegin();
    
    return it_begin;
}


polinomio::iterator polinomio::end(){
    
    polinomio::iterator it_end;
    
    it_end.it = vPolinomio.send();
    
    return it_end;
}


polinomio::const_iterator polinomio::cbegin() const{
    
    polinomio::const_iterator it_begin;
    
    it_begin.it = vPolinomio.csbegin();
    
    return it_begin;
}


polinomio::const_iterator polinomio::cend() const{
    
    polinomio::const_iterator it_end;
    
    it_end.it = vPolinomio.csend();
    
    return it_end;
}





/************************************************************ */
/*               ITERADOR SOBRE EL POLINOMIO                  */
/**************************************************************/



polinomio::iterator & polinomio::iterator::operator=(const iterator & d){
    
    this->it=d.it;
    
    return *this;
}


polinomio::iterator::iterator(){
    vectorD<int>::stored_iterator iterador;
    this->it=iterador;
    
}


polinomio::iterator & polinomio::iterator::operator++( ){
    this->it++;
    
    return *this;
    
}

polinomio::iterator polinomio::iterator::operator++(int ){
    polinomio::iterator copia;
    
    copia = (*this);
    
    this->it++;
    
    return copia;
    
}


polinomio::iterator & polinomio::iterator::operator--( ){
    this->it--;
    
    return *this;
    
}

polinomio::iterator polinomio::iterator::operator--(int ){
    polinomio::iterator copia;
    
    copia = (*this);
    
    this->it--;
    
    return copia;
    
}


const pair<const int, int > &  polinomio::iterator::operator *(  ){
    return *it;
}


bool polinomio::iterator::operator==(const iterator & d){
    
    return ((*this).it == d.it);
}


bool polinomio::iterator::operator!=(const iterator & d){
    return !((*this).it == d.it);
}





/************************************************************ */
/*          ITERADOR CONSTANTE SOBRE EL POLINOMIO             */
/**************************************************************/




polinomio::const_iterator & polinomio::const_iterator::operator=(const const_iterator & d){
    
    this->it=d.it;
    
    return *this;
}

polinomio::const_iterator::const_iterator(){
    vectorD<int>::const_stored_iterator iterador;
    this->it=iterador;
    
}

polinomio::const_iterator & polinomio::const_iterator::operator++( ){
    this->it++;
    
    return *this;
    
}

polinomio::const_iterator polinomio::const_iterator::operator++(int ){
    polinomio::const_iterator copia;
    
    copia = (*this);
    
    this->it++;
    
    return copia;
    
}


polinomio::const_iterator & polinomio::const_iterator::operator--( ){
    this->it--;
    
    return *this;
    
}

polinomio::const_iterator polinomio::const_iterator::operator--(int ){
    polinomio::const_iterator copia;
    
    copia = (*this);
    
    this->it--;
    
    return copia;
    
}


const pair<const int, int > &  polinomio::const_iterator::operator *(  ){
    return *it;
}


bool polinomio::const_iterator::operator == (const const_iterator & d){
    
    return ((*this).it == d.it);
}


bool polinomio::const_iterator::operator != (const const_iterator & d){
    return !((*this).it == d.it);
}


