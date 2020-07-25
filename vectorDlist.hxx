#include <list>
#include <utility> // clase pair


using namespace std;



/************************************************************ */
/*                      CLASS VECTORD<T>                      */
/**************************************************************/


////////////// CONSTRUCTORES //////////////


template <typename T>
vectorD<T>::vectorD( const  T  & t ) {
    v_nulo = t;
    n_ele = 0;
}


template <typename  T >
vectorD<T>::vectorD(  const vectorD< T > & b) {
    vd = b.vd;
    n_ele = b.n_ele;
    v_nulo = b.v_nulo;
}


template <typename  T >
vectorD<T>::vectorD( int numcomp, const  T  & t) {
    
    if (numcomp < 0) {
        cerr << "ERROR!: El número de componentes del vector no puede ser inferior a 0\n";
        exit(-1);
    }
        
    n_ele = numcomp;
    v_nulo = t;
}



////////////// DESTRUCTOR //////////////


template <typename  T >
vectorD<T>::~vectorD() {
}



////////////// CONSULTORES //////////////


template <typename  T >
typename vectorD<T>::size_type vectorD<T>::size() const {
    return n_ele;
}


template <typename  T >
T vectorD<T>::default_value( ) const {
    return v_nulo;
}


template <typename  T >
bool vectorD<T>::empty() {
    if (n_ele == 0) {
        return true;
    } else {
        return false;
    }
}



//////////////  MODIFICADORES //////////////


template<typename T>
void vectorD<T>::assign(int p, const T & t){
    
    pair<int,T> aux;
    aux.first = p;
    aux.second = t;
    
    bool insertado=false;
    typename list<pair<int,T>>::iterator it_begin = vd.begin();
    typename list<pair<int,T>>::iterator it_end = vd.end();
    
    if(t==v_nulo){
        for(it_begin; (it_begin != it_end)&&(!insertado); ++it_begin){
            if((*it_begin).first == p){
                (*this).vd.erase(it_begin);
                insertado=true;
            }
        }
        
    } else {
        
        for(it_begin; (it_begin != it_end)&&(!insertado); ++it_begin){
            if((*it_begin).first == p){
                (*it_begin).second = t;
                insertado=true;
                
            }
            else if((*it_begin).first > p){
                (*this).vd.insert(it_begin,aux);
                insertado=true;
            }
            
        }
    }
    
}


template <typename T >
void vectorD< T >::push_back( const  T  & t){
    if(t != v_nulo){
        pair<int,T> nuevo;
        nuevo.first= n_ele;
        nuevo.second= t;
        vd.push_back(nuevo);
    }
    n_ele++;
}


template <typename T >
void vectorD< T >::pop_back( ){
    
    vectorD<T>::stored_iterator it = (*this).send();
    
    --it;
    
    if((*it).first == (n_ele-1) ){
        vd.pop_back();
        n_ele--;
    } else {
        n_ele--;
    }
    
}


template <typename T >
void vectorD<T>::clear(){
    vd.clear();
    n_ele=0;
}


template <typename T >
void vectorD< T >::resize(int s){
    
    if(s < n_ele){
        int aux=n_ele - s;
        for(int i = 0; i < aux;i++){
            (*this).pop_back();
        }
    }else {
        n_ele = s;
    }
    
}



////////////// OPERADORES //////////////


template <typename T >
vectorD< T > & vectorD< T >::operator= (const vectorD< T > & x){
    vd = x.vd;
    n_ele = x.n_ele;
    v_nulo = x.v_nulo;
    
    return *this;
}


template <typename T >
const  T  & vectorD< T >::operator[](int c) const{
    
    vectorD<T>::const_stored_iterator iter  = (*this).csbegin();
    vectorD<T>::const_stored_iterator iterend  = (*this).csend();
    bool encontrado = false;
    
    while ( (iter != iterend)&&( (*iter).first   <= c )&&(!encontrado) ) {
        
        if ( ((*iter).first) == c) {
            encontrado = true;
        } else {
            ++iter;
        }
    }
    
    if (encontrado) {
        return (*iter).second;
    } else {
        return (*this).v_nulo;
    }
}


template <typename T >
const  T  & vectorD< T >::at(int c) const{
    
    if (c <= (*this).n_ele ) {
        
        return ( (*this)[c] );
        
    } else {
        cerr << "ERROR!!: Intento de acceso a elemento fuera de los límites del vector\n";
        exit(8);
    }
    
}


template <typename T >
bool vectorD< T >::operator==( const vectorD< T > & x){
    
    bool iguales = true;
    
    if (x.size() == (*this).size() ) {
        
        for (int i=0; i<x.size();i++) {
            if ( x[i] != (*this)[i] )
                iguales = false;
        }
        
    } else {
        iguales = false;
    }
    
    return iguales;
}


template <typename T >
bool vectorD< T >::operator!=( const vectorD< T > & x){
    
    bool noiguales = true;
    
    if ( (*this) == x ) {
        noiguales = false;
    }
    
    return noiguales;
}



/////////////// MÉTODOS SOBRE ITERADORES ///////////////////


template <typename  T>
typename vectorD<T>::iterator vectorD<T>::begin() {
    
    typename vectorD<T>::iterator iter;
    
    iter.i_vect = 0;
    iter.el_vect = this;
    iter.ite_rep = (*this).vd.begin();
    
    return iter;
}


template <typename  T>
typename vectorD<T>::iterator vectorD<T>::end() {
    
    typename vectorD<T>::iterator iter;
    
    iter.i_vect = ( (*this).n_ele +1 );
    iter.el_vect = this;
    iter.ite_rep = (*this).vd.end();
    
    return iter;
}

template <typename  T>
typename vectorD<T>::const_iterator vectorD<T>::cbegin() const {
    
    typename vectorD<T>::const_iterator c_iter;
    
    c_iter.i_vect = 0;
    c_iter.el_vect = this;
    c_iter.ite_rep = (*this).vd.cbegin();
    
    
    return c_iter;
}


template <typename  T>
typename vectorD<T>::const_iterator vectorD<T>::cend() const {
    
    typename vectorD<T>::const_iterator c_iter;
    
    c_iter.i_vect = ( (*this).n_ele +1 );
    c_iter.el_vect = this;
    c_iter.ite_rep = (*this).vd.cend();
    
    return c_iter;
}


template <typename T>
typename vectorD<T>::stored_iterator vectorD<T>::sbegin() {
    
    typename vectorD<T>::stored_iterator s_iter;
    
    s_iter.ite = (*this).vd.begin();
    
    return s_iter;
}


template <typename T>
typename vectorD<T>::stored_iterator vectorD<T>::send() {
    
    typename vectorD<T>::stored_iterator s_iter;
    
    s_iter.ite = vd.end();
    
    return s_iter;
}


template <typename T >
typename vectorD< T >::const_stored_iterator vectorD< T >::csbegin() const{
    
    typename vectorD< T >::const_stored_iterator cs_iter;
    
    cs_iter.ite = vd.cbegin();
    
    return cs_iter;
    
}

template <typename T >
typename vectorD< T >::const_stored_iterator vectorD< T >::csend() const{
    
    typename vectorD< T >::const_stored_iterator cs_iter;
    
    cs_iter.ite = vd.cend();
    
    return cs_iter;
    
}



/****************************************** */
/*                ITERATOR                  */
/********************************************/



////////////// CONSTRUCTORES //////////////


template <typename T >
vectorD< T >::iterator::iterator(){
    
    i_vect = 0;
    
}


template <typename T >
vectorD< T >::iterator::iterator(const iterator & d){
    
    i_vect = d.i_vect;
    ite_rep = d.ite_rep;
    el_vect=d.el_vect;
    
}


////////////// OPERADORES //////////////


template <typename T >
const  T  & vectorD< T >::iterator::operator *(  ){
    
  if (el_vect->vd.size() == 0) {
      return el_vect->v_nulo;
  }
    

  if((*ite_rep).first == i_vect){
        return (*ite_rep).second;
    }
  else{
      return el_vect->v_nulo;
  }
    
}


template <typename T >
typename vectorD< T >::iterator & vectorD< T >::iterator::operator++( ){

    if(i_vect == (*ite_rep).first){
        ++ite_rep;
    }
    i_vect++;
    
    return (*this);
}


template <typename T >
typename vectorD< T >::iterator vectorD< T >::iterator::operator++(int ){
    
    typename vectorD<T>::iterator copia;
    
    copia.i_vect = i_vect;
    copia.ite_rep = ite_rep;
    copia.el_vect= el_vect;
    
    if(i_vect == (*ite_rep).first){
        ite_rep++;
    }
    i_vect++;
    
    return copia;
}

template <typename T >
typename vectorD< T >::iterator & vectorD< T >::iterator::operator--( ){
    
    if(i_vect == (*ite_rep).first){
        --ite_rep;
    }
    i_vect--;
    
    return (*this);
}


template <typename T >
typename vectorD< T >::iterator vectorD< T >::iterator::operator--(int ){
    
    typename vectorD<T>::iterator copia;
    
    copia.i_vect = i_vect;
    copia.ite_rep = ite_rep;
    copia.el_vect= el_vect;
    
    if(i_vect == (*ite_rep).first){
        ite_rep--;
    }
    i_vect--;
    
    return copia;
}


template <typename T >
typename vectorD<T>::iterator & vectorD<T>::iterator::operator=(const iterator & d){
    
    this->i_vect = d.i_vect;
    this->ite_rep = d.ite_rep;
    this->el_vect=d.el_vect;
    
    return *this;
    
}


template <typename T >
bool vectorD< T >::iterator::operator == (const iterator & d){
    if(i_vect == d.i_vect){
        return true;
    }
    
    return false;
}


template <typename T >
bool vectorD< T >::iterator::operator != (const iterator & d){
    return !(*this==d);
}



/****************************************** */
/*          ITERADOR CONSTANTE              */
/********************************************/



////////////// CONSTRUCTORES //////////////


template <typename T >
vectorD< T >:: const_iterator::const_iterator(){
    i_vect = 0;
}


template <typename T >
vectorD< T >::const_iterator::const_iterator(const const_iterator & d){
    
    i_vect = d.i_vect;
    ite_rep = d.ite_rep;
    el_vect = d.el_vect;
    
}


template <typename T >
vectorD< T >::const_iterator::const_iterator(const iterator & d){
    
    i_vect = d.i_vect;
    ite_rep = d.ite_rep;
    el_vect = d.el_vect;
    
}


////////////// OPERADORES //////////////



template <typename T >
const  T  &  vectorD< T >::const_iterator::operator *(  ){
    
    if (el_vect->vd.size() == 0) {
        return el_vect->v_nulo;
    }
    
    
    if( (*ite_rep).first == i_vect){
        
        return (*ite_rep).second;
    }
    else{
        return el_vect->v_nulo;
    }
    
}


template <typename T >
typename vectorD< T >::const_iterator & vectorD< T >::const_iterator::operator++( ){
    
    pair<int,T> aux = *ite_rep;
    
    if( i_vect == aux.first ){
        
        ++ite_rep;
        
    }
    
    i_vect++;
    
    return *this;
    
}


template <typename T >
typename vectorD< T >::const_iterator vectorD< T >::const_iterator::operator++(int ){
    
    vectorD< T >::const_iterator copia;
    pair<int,T> aux = *ite_rep;
    
    copia.i_vect = i_vect;
    copia.ite_rep = ite_rep;
    copia.el_vect = el_vect;
    if( i_vect == aux.first ){
        
        ite_rep++;
        
    }
    
    i_vect++;
    
    return copia;
    
}


template <typename T >
typename vectorD< T >::const_iterator & vectorD< T >::const_iterator::operator--( ){
    
    if(i_vect == (*ite_rep).first){
        --ite_rep;
    }
    i_vect--;
    
    return (*this);
}


template <typename T >
typename vectorD< T >::const_iterator vectorD< T >::const_iterator::operator--(int ){
    
    typename vectorD<T>::iterator copia;
    
    copia.i_vect = i_vect;
    copia.ite_rep = ite_rep;
    copia.el_vect= el_vect;
    
    if(i_vect == (*ite_rep).first){
        ite_rep--;
    }
    i_vect--;
    
    return copia;
}


template <typename T >
bool vectorD< T >::const_iterator::operator == (const const_iterator & d){
    
    if( (i_vect == d.i_vect)){
        return true;
    }
    else{
        return false;
    }
    
}


template <typename T >   
bool vectorD< T >::const_iterator::operator != (const const_iterator & d){
    
    if( (i_vect != d.i_vect)){
        return true;
    }
    else{
        return false;
    }
    
}


/***************************************************************** */
/*          ITERADOR A POSICIONES NO NULAS DEL VECTOR              */
/*******************************************************************/



////////////// CONSTRUCTOR //////////////


template <typename T >
vectorD< T >::stored_iterator::stored_iterator() {
   
}


template <typename T >
vectorD< T >::stored_iterator::stored_iterator(const stored_iterator & d){
    
    ite = d.ite;
}



////////////// OPERADORES //////////////


template <typename T >
const pair<int, T > & vectorD< T >::stored_iterator::operator *(  ) {
    
    return (*ite);
    
}


template <typename T >
typename vectorD< T >::stored_iterator & vectorD< T >::stored_iterator::operator++( ) {
    
    ++ite;
    
    return *this;
    
}


template <typename T >
typename vectorD< T >::stored_iterator vectorD< T >::stored_iterator::operator++(int ) {
    
    vectorD< T >::stored_iterator tmp(*this);
    ++ite;
    
    return tmp;
    
}


template <typename T >
typename vectorD< T >::stored_iterator & vectorD< T >::stored_iterator::operator--( ) {
    
    --ite;
    
    return (*this);
    
}


template <typename T >
typename vectorD< T >::stored_iterator vectorD< T >::stored_iterator::operator--(int ) {
    
    vectorD< T >::stored_iterator tmp(*this);
    
    ite--;
    
    return tmp;
    
}


template <typename T >
bool vectorD< T >::stored_iterator::operator == (const vectorD< T >::stored_iterator & d) {
    
    return ite == d.ite;
    
}


template <typename T >
bool vectorD< T >::stored_iterator::operator != (const vectorD< T >::stored_iterator & d) {
    
    return ite != d.ite;
    
}


/***************************************************************** */
/*      ITERADOR CONSTANTE A POSICIONES NO NULAS DEL VECTOR        */
/*******************************************************************/



////////////// CONSTRUCTOR //////////////


template <typename T >
vectorD< T >::const_stored_iterator::const_stored_iterator(){
    
}


template <typename T >
vectorD< T >::const_stored_iterator::const_stored_iterator(const const_stored_iterator & d){
    
    ite = d.ite;
    
}


template <typename T >
vectorD< T >::const_stored_iterator::const_stored_iterator(const stored_iterator & d){
    // Conversion de iterator a const_iterator
    ite = d.ite;
    
}



////////////// OPERADOR //////////////


template <typename T >
const pair<int, T > & vectorD< T >::const_stored_iterator::operator *(  ){
    
    return (*ite);
    
}


template <typename T >
typename vectorD< T >::const_stored_iterator & vectorD< T >::const_stored_iterator::operator++( ){
    
    ++ite;
    
    return *this;
    
}


template <typename T >
typename vectorD< T >::const_stored_iterator vectorD< T >::const_stored_iterator::operator++(int ){
    
    vectorD< T >::const_stored_iterator tmp = (*this);
    
    ++ite;
    
    return tmp;
}


template <typename T >
typename vectorD< T >::const_stored_iterator & vectorD< T >::const_stored_iterator::operator--( ) {
    
    --ite;
    
    return (*this);
    
}


template <typename T >
typename vectorD< T >::const_stored_iterator vectorD< T >::const_stored_iterator::operator--(int ) {
    
    vectorD< T >::const_stored_iterator tmp(*this);
    --ite;
    
    return tmp;
    
}


template <typename T >
bool vectorD< T >::const_stored_iterator::operator == (const const_stored_iterator & d){
    
    return ite == d.ite;
    
}


template <typename T >
bool vectorD< T >::const_stored_iterator::operator != (const const_stored_iterator & d){
    
    return ite != d.ite;
    
}


template <typename T >
typename vectorD< T >::const_stored_iterator & vectorD< T >::const_stored_iterator::operator= (const const_stored_iterator & d){
    
    (*this).ite = d.ite;
    
    return (*this);
    
}



//////////////// INVARIANTE DE LA REPRESENTACION DEL VECTORD  ////////////////


template<typename T>
int vectorD<T>::checkRep(){
    
    typename vectorD<T>::stored_iterator its_begin = vd.begin();
    typename vectorD<T>::stored_iterator its_end = vd.end();
    typename vectorD<T>::stored_iterator its_begin_aux = its_begin;
    int cont = vd.size();
    
    
    //Fallo tipo 1
    if (vd.size() > n_ele || n_ele < 0) {
        cerr << "ERROR DE REPRESENTACIÓN!!: El número de elementos no puede ser negativo o inferior al número de elementos no nulos..." << endl;
        return 1;
    }
    
    for(its_begin; its_begin != its_end; ++its_begin, cont--){
        
        // Fallo tipo 2
        if ((*its_begin).second == v_nulo) {
            cerr << "ERROR DE REPRESENTACIÓN!!: En la lista interna de elementos no nulos no puede haber elementos nulos..." << endl;
            return 2;
        }
        
        // Fallo tipo 3
        if ((*its_begin).first < 0 ) {
            cerr << "ERROR DE REPRESENTACIÓN!!: En la lista interna no puede haber posiciones negativas..." << endl;
            return 3;
        }
        
        //Fallo tipo 4
        its_begin_aux++;
        
        if (cont > 1) {
            if ( (*its_begin).first >= (*its_begin_aux).first ) {
                cerr << "ERROR DE REPRESENTACIÓN!!: Las posiciones de la lista interna deben estar ordenadas..." << endl;
                return 4;
            }
        }
        
    }
    
    return 0;
}
