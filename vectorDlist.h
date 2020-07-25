#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

#include <list>
#include <utility> // clase pair


using namespace std;

/**
 * @author Diciembre 2014 - JotaEle Díaz & Grego Vidoy
 */

//! Clase VectorD
/*
 * Descripción
 * Un vector disperso es un contenedor similar al vector de la STL en el que la mayoría de los elementos tienen el mismo valor (conocido como valor por defecto). 
 * Gracias a la implementación interna del vector interno, el recorrido y acceso sobre este es eficiente y su almacenamiento ocupa una menor cantidad de memoria.
 * La gestión de memoria es dinámica y el tamaño del vector es modificable.
 */
template <typename  T>
class vectorD {

public:
    
    class stored_iterator; // iterador sobre elementos no nulos
    class iterator; // iterador sobre todos los elementos del vector
    class const_stored_iterator; // const iterador sobre elementos no nulos
    class const_iterator; // const iterador sobre todos los elementos del vector
    typedef unsigned int size_type;


    //////////// CONSTRUCTORES //////////////
  	
    /** @brief Constructor por defecto.
        @param[in] t Valor que se desea que se interprete como valor por defecto del vector. (Por defecto, 0)
    */
    vectorD( const  T  & t=  T () );
   
    
    /** @brief Constructor primitivo que hace una copia de un vector disperso
        @param[in] b Vector disperso que se desea copiar
    */
    vectorD(  const vectorD< T > & b);

    
    /** @brief Constructor primitivo que crea un vectorD con numcomp componentes, todas ellas inicializadas al valor por defecto t.
        @param[in] numcomp Número de componentes que tendrá el vector.
        @param[in] t Valor que se desea que se interprete como valor por defecto del vector. (Por defecto, 0)
    */
    vectorD( int numcomp, const  T  & t =  T () );
    



    ////////////// DESTRUCTOR ////////////
    
    /** @brief Destructor primitivo de vectorD.
    */
    ~vectorD();



    /////////// CONSULTORES ////////////
    
    /** @brief Calcula el tamaño del vectorD
        @return Tamaño del vectorD
    */
    size_type size() const;
    
    /** @brief Muestra el valor que tiene asignado el VectorD como valor por defecto del cector.
        @return Valor por defecto
    */
    T  default_value( ) const;

    /** @brief Comprueba si el VectorD está vacío
        @return True si está vacío, false si no lo está.
    */
    bool empty();



    ////////  MODIFICADORES //////////////////////

    /** @brief Cambia a el valor t el valor de la posicion p-ésima del vector. 
        @param[in] p Posición en el vector que se desea modificar.
        @param[in] t Nuevo valor que se desea dar a la posición del vector.
        @post No modifica el tamaño del vector
    */
    void assign(int p, const  T  & t);
    
    /** @brief Inserta un elemento al final del vectorD.
        @param[in] t Nuevo valor que se desea añadir al vectorD.
        @post El tamaño del vector aumenta en 1
     */
    void push_back( const  T  & t);
    
    /** @brief Elimina el último elemento del vectorD.
        @post El tamaño del vector disminuye en 1
    */
    void pop_back();

    /** @brief Elimina todos los elementos del vectorD.
        @post El tamaño del vector queda a 0
    */
    void clear();

    /** @brief Redimensiona el vectorD al número de posiciones dado.
        @param[in] s Nuevo tamaño del vectorD
        @post Si s es menor que el tamaño actual, se eliminan los restantes. Si es mayor, se amplia el tamaño poniendo al valor por defecto todos los elementos nuevos.
    */
    void resize(int s);



    /////////////// OPERADORES ///////////////////

    /** @brief Operador de asignación. Asigna una copia del vectorD al recibido como argumento.
        @param[in] x VectorD a copiar.
        @return Vector copiado
        @post Los valores y tamaño del vector quedan iguales que los del vectorD x.
     */
    vectorD & operator= (const vectorD & x);

    /** @brief Devuelve la componente c-ésima del VectorD. (Ej: vector[5])
        @param[in] c Número de la posición del vectorD a la que se desea acceder.
        @return Valor c-ésimo del vector
    */
    const  T  & operator[](int c) const  ;

    /** @brief Devuelve la componente c-ésima del VectorD.
        @param[in] c Número de la posición del vectorD a la que se desea acceder.
        @return Valor c-ésimo del vector
        @pre c debe ser mayor o igual que el número de componente del vector. Se hace comprobación de rango. Genera un error en caso de no cumplir la condición.
    */
    const  T  & at(int c) const  ;

    /** @brief Operador de igualdad. Comprueba si dos vectores son iguales. Es decir, si su tamaño y todos sus elementos uno a uno coinciden.
        @param[in] x VectorD a comparar.
        @return Devuelve true si ambos vectores son iguales, false en caso contrario.
        @post No se modifica el vectorD.
    */
    bool operator==( const vectorD & x);

    /** @brief Operador de desigualdad. Comprueba si dos vectores no son iguales. Es decir, si su tamaño y todos sus elementos uno a uno no coinciden.
        @param[in] x VectorD a comparar.
        @return Devuelve true si ambos vectores no son iguales, false en caso de que sí lo sean.
        @post No se modifica el vectorD.
    */
    bool operator!=( const vectorD & x);

    

    /////////////// MÉTODOS SOBRE ITERADORES ///////////////////

    /** @brief Devuelve un iterador que apunta al primer elemento del vectorD.
        @return Iterador a la primera posición.
        @post No se modifica el vectorD.
    */
    iterator begin();

    /** @brief Devuelve un iterador que apunta al final (es decir, al elemento siguiente al último) del vectorD.
        @return Iterador al elemento siguiente al último.
        @post No se modifica el vectorD.
    */
    iterator end();

    /** @brief Devuelve un iterador constante que apunta al primer elemento del vectorD.
        @return Iterador constante a la primera posición.
        @post No se modifica el vectorD.
    */
    const_iterator cbegin() const;

    /** @brief Devuelve un iterador constante que apunta al final (es decir, al elemento siguiente al último) del vectorD.
        @return Iterador constante al elemento siguiente al último.
        @post No se modifica el vectorD.
    */
    const_iterator cend() const;
    
    /** @brief Devuelve un iterador sobre elementos no nulos que apunta al primer elemento que no sea el valor por defecto.
        @return Iterador sobre elementos no nulos al primer elemento no nulo.
        @post No se modifica el vectorD.
    */
    stored_iterator sbegin();
    
    /** @brief Devuelve un iterador sobre elementos no nulos que apunta al final (el elemento siguiente al último) de los elementos no nulos.
        @return Iterador sobre elementos no nulos al último elemento no nulo.
        @post No se modifica el vectorD.
    */
    stored_iterator send();
   
    /** @brief Devuelve un iterador constante sobre elementos no nulos que apunta al primer elemento que no sea el valor por defecto.
        @return Iterador constante sobre elementos no nulos al primer elemento no nulo.
        @post No se modifica el vectorD.
    */
    const_stored_iterator csbegin() const;

    /** @brief Devuelve un iterador constante sobre elementos no nulos que apunta al final (el elemento siguiente al último) de los elementos no nulos.
        @return Iterador constante sobre elementos no nulos al último elemento no nulo.
        @post No se modifica el vectorD.
    */
    const_stored_iterator csend() const;
    

private: // parte privada
    
    /**
     * lista que aloja el vector disperso (solo los != valor nulo)
    */
    list< pair<int, T > > vd;
    
    /**
     * número de elementos totales
    */
    int n_ele;
    
    /**
     * valor nulo del vector
    */
    T   v_nulo;
 
    
    /* FA(rep): rep -- > vector
      (vd,n_ele,v_nulo):
         vd=[ (a,v1), (b,v2), ..., (n,vn) ]
         n_ele = M
         v_nulo = t
      --------->
      pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n  n+1 ..... M-1
      val: t t t ....t  v1 ... t .... v2 ..  ... t   vn  t  ...... t
    */
    
    
    /** @brief Comprueba que la invariante de representación del vector es correcta.
        @return Devuelve 0 si la invariante de representación es correcta.
                Devuelve 1 si no se cumple que 0 <= vd.size() < n_ele
                Devuelve 2 si no se cumple que vd[i].first >=0, para todo i = 0, ..., vd.size()-1
                Devuelve 3 si no se cumple que vd[i].first >=0, para todo i = 0, ..., vd.size()-1
                Devuelve 4 si no se cumple que vd[i].first < vd[j].first si i<j
    */
    int checkRep();

    

    
  /* ITERADORES SOBRE VECTOR DISPERSO */
    
public:
  
  public:
    
/** @brief class iterator
  * Iterador hacia delante sobre todas las posiciones del vector Disperso.
  * iterator, operator*, operator++, ++operator operator=(iterator), operator==, operator!=
  **/
class iterator{
  public:
    
    friend class vectorD;
    
    /** @brief Constructor primitivo del iterador sobre el VectorD.
    */
    iterator() ;
    
    /** @brief Constructor primitivo que crea un iterador sobre un VectorD copia de otro iterador.
        @param[in] d Iterador al vector disperso que se desea copiar
    */
    iterator(const iterator & d);
    
    /** @brief Operador de indirección. Devuelve el elemento del VectorD al cual hace referencia el iterador.
        @return Elemento al cual hace referencia el iterador.
    */
    const  T  & operator *(  ) ;
    
    /** @brief Operador de incremento (++it). Incrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
        @return Iterador a la posición siguiente a la actual.
    */
    iterator & operator++( );
    
    /** @brief Operador de incremento (it++). Incrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
        @return Iterador original antes de ser incrementado.
    */
    iterator operator++(int ) ;
    
    /** @brief Operador de decremento (--it). Decrementa el iterador, es decir referencia el iterador a la posición anterior a la actual.
     @return Iterador a la posición anterior a la actual.
     */
    iterator & operator--( );
    
    /** @brief Operador de decremento (it--). Decrementa el iterador, es decir referencia el iterador a la posición anterior a la actual.
     @return Iterador original antes de ser decrementado.
     */
    iterator operator--(int ) ;
    
    /** @brief Operador de igualdad. Comprueba si dos iteradores hacen referencia a una misma posición del VectorD.
        @param[in] d Iterador a comparar.
        @return True si hacen referencia a la misma posición, false en caso contrario
    */
    bool operator == (const iterator & d);
    
    /** @brief Operador de desigualdad. Comprueba si dos iteradores hacen referencia a distintas posiciones del VectorD.
        @param[in] d Iterador a comparar.
        @return True si hacen referencia distintas posiciones, false en caso contrario
    */
    bool operator != (const iterator & d);
    
    /** @brief Operador de asignación. Asigna al iterador la posición a la que apunta el iterador recibido.
     @param[in] d Iterador a copiar.
    */
    iterator & operator=(const iterator & d);
    
  private:
    
    /**
     * Índice sobre el vector abstracto
     */
    int i_vect;
    
    /**
     * Iterador a la representacion
     */
    typename list<pair<int, T > >::iterator ite_rep;
    
    /**
     * Puntero al vector para obtener el valor nulo del vector
     */
    vectorD *el_vect;
    
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p 
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */
   
      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep): 
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
     */
       
};
    

    
    
/** @brief class const_iterator
  * Iterador constante hacia delante sobre todas las posiciones del vector Disperso. Lectura
  * const_iterator, const_iterator(const_iterator), const_iterator(iterator), operator*, operator++, ++operator, operator=(iterator), operator==, operator!=
  **/
class const_iterator{
    
    public:
    
        friend class vectorD;
    
        /** @brief Constructor primitivo del iterador sobre el VectorD.
        */
        const_iterator() ;
    
        /** @brief Constructor primitivo que crea un iterador constante sobre un VectorD copia de otro iterador constante.
            @param[in] d Iterador al vector disperso que se desea copiar
        */
        const_iterator(const const_iterator & d);
    
        /** @brief Constructor primitivo que crea un iterador constante en base a un iterador no constante.
            @param[in] d Iterador al vector disperso que se desea copiar.
        */
        const_iterator(const iterator & d);
    
        /** @brief Operador de indirección. Devuelve el elemento del VectorD al cual hace referencia el iterador constante.
            @return Elemento al cual hace referencia el iterador constante.
        */
        const  T  &  operator *(  );
    
        /** @brief Operador de incremento (++it). Incrementa el iterador constante, es decir referencia el iterador a la posición siguiente a la actual.
            @return Iterador constante a la posición siguiente a la actual.
        */
        const_iterator & operator++( ) ;
    
        /** @brief Operador de incremento (it++). Incrementa el iterador constante, es decir referencia el iterador a la posición siguiente a la actual.
            @return Iterador constante original antes de ser incrementado.
        */
        const_iterator operator++(int ) ;
    
        /** @brief Operador de decremento (--it). Decrementa el iterador constante, es decir referencia el iterador a la posición anterior a la actual.
            @return Iterador constante a la posición anterior a la actual.
        */
        const_iterator & operator--( ) ;
    
        /** @brief Operador de incremento (it--). Decrementa el iterador constante, es decir referencia el iterador a la posición anterior a la actual.
            @return Iterador constante original antes de ser incrementado.
        */
        const_iterator operator--(int ) ;
    
        /** @brief Operador de igualdad. Comprueba si dos iteradores hacen referencia a una misma posición del VectorD.
            @param[in] d Iterador a comparar.
            @return True si hacen referencia a la misma posición, false en caso contrario
        */
        bool operator == (const const_iterator & d) ;
    
        /** @brief Operador de desigualdad. Comprueba si dos iteradores hacen referencia a distintas posiciones del VectorD.
            @param[in] d Iterador a comparar.
            @return True si hacen referencia distintas posiciones, false en caso contrario
        */
        bool operator != (const const_iterator & d) ;
        
    private:
    
        /**
         * Índice sobre el vector abstracto
         */
        int i_vect;
    
        /**
        * Iterador a la representacion
        */
        typename list<pair<int, T > >::const_iterator ite_rep;
    
        /**
        * Puntero al vector para obtener el valor nulo del vector
        */
        const vectorD *el_vect;
    
    
        /* FA(rep): rep -- > iterador sobre vector abstracto
         (i_vect, ite_rep, el_vec):
         i_vect = k
         ite_rep = p
         el_vect = v
         --------->
         iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
         */
        
        /* IR :
         IR(rep): rep ---> bool
         (i_vect, ite_rep):
         --------->
         0 <= i_vect <=n_ele
         i_vect <= (*ite_rep).first
         */
        
};

    
    
/** @brief class stored_iterator
  * Iterador hacia delante que sólo recorre las posiciones que no son el valor por defecto del vector Disperso.
  * stored_iterator, stored_iterator(stored_iterator), operator*, operator++, ++operator, operator==, operator!=
  **/
class stored_iterator{
    
    public:
    
        friend class vectorD;
        friend class vectorD< T >::const_stored_iterator;
    
        /** @brief Constructor primitivo del iterador a posiciones no nulas del VectorD.
        */
        stored_iterator();
    
        /** @brief Constructor primitivo que crea un iterador sobre elementos no nulos copia de otro.
            @param[in] d Iterador sobre elementos no nulos del vector disperso que se desea copiar
        */
        stored_iterator(const stored_iterator & d);
    
        /** @brief Operador de indirección. Devuelve el elemento del VectorD al cual hace referencia el iterador.
            @return pair <int, T> que contiene la posición y el elemento del VectorD al cual hace referencia el iterador.
        */
        const pair<int, T > & operator *(  );
    
        /** @brief Operador de incremento (++it). Incrementa el iterador, es decir referencia el iterador a la posición no nula siguiente a la actual.
            @return Iterador a la posición no nula siguiente a la actual.
        */
        stored_iterator & operator++( );
    
        /** @brief Operador de incremento (it++). Incrementa el iterador, es decir referencia el iterador a la posición no nula siguiente a la actual.
            @return Iterador original antes de ser incrementado.
        */
        stored_iterator operator++(int );
    
        /** @brief Operador de decremento (--it). Decrementa el iterador, es decir referencia el iterador a la posición no nula anterior a la actual.
            @return Iterador a la posición no nula anterior a la actual.
        */
        stored_iterator & operator--( );
    
        /** @brief Operador de decremento (it--). Decrementa el iterador, es decir referencia el iterador a la posición no nula anterior a la actual.
            @return Iterador original antes de ser decrementado.
        */
        stored_iterator operator--(int );
    
        /** @brief Operador de igualdad. Comprueba si dos iteradores sobre posiciones no nulas hacen referencia a una misma posición del VectorD.
            @param[in] d Iterador sobre posicionesn no nulas a comparar.
            @return True si hacen referencia a la misma posición, false en caso contrario
        */
        bool operator == (const stored_iterator & d);
    
        /** @brief Operador de desigualdad. Comprueba si dos iteradores sobre posiciones no nulas hacen referencia a distintas posiciones del VectorD.
            @param[in] d Iterador sobre posicionesn no nulas a comparar.
            @return True si hacen referencia a la diferentes posiciones, false en caso contrario
        */
        bool operator != (const stored_iterator & d);
        
    private:
    
        /**
         * Iterador a la lista vd interna del vector
         */
        typename list<pair<int, T > >::iterator ite;
};

    
    
/** @brief class const_stored_iterator
  * Iterador constante hacia delante que sólo recorre las posiciones que no son el valor por defecto del vector Disperso. Lectura.
  * const_stored_iterator, const_stored_iterator(const_stored_iterator), const_stored_iterator(stored_iterator), operator*, operator++, ++operator, operator==, operator!=, operator=
  **/
class const_stored_iterator{
    
  public:
    
    friend class vectorD;
    
    /** @brief Constructor primitivo del iterador constante a posiciones no nulas del VectorD.
    */
    const_stored_iterator();
    
    /** @brief Constructor primitivo que crea un iterador constante sobre elementos no nulos copia de otro.
        @param[in] d Iterador constante sobre elementos no nulos del vector disperso que se desea copiar
    */
    const_stored_iterator(const const_stored_iterator & d);
    
    /** @brief Constructor primitivo que crea un iterador constante sobre posiciones no nulas en base a uno no constante.
        @param[in] d Iterador sobre posiciones no nulas que se desea copiar.
    */
    const_stored_iterator(const stored_iterator & d);
    
    /** @brief Operador de indirección. Devuelve el elemento del VectorD al cual hace referencia el iterador constante.
        @return pair <int, T> que contiene la posición y el elemento del VectorD al cual hace referencia el iterador constante.
    */
    const pair<int, T > & operator *(  );
    
    /** @brief Operador ++. Devuelve un iterador constante a la posición no nula siguiente a la actual.
        @return Iterador consante a la posición no nula siguiente a la actual.
    */
    const_stored_iterator & operator++( );
    
    /** @brief Operador ++. Devuelve un iterador constante a la posición no nula siguiente a la actual.
        @return Iterador constante a la posición no nula siguiente a la actual.
    */
    const_stored_iterator operator++(int );
    
    /** @brief Operador de decremento (--it). Decrementa el iterador, es decir referencia el iterador a la posición no nula anterior a la actual.
        @return Iterador constante a la posición no nula anterior a la actual.
    */
    const_stored_iterator & operator--( );
    
    /** @brief Operador de decremento (it--). Decrementa el iterador constante, es decir referencia el iterador a la posición no nula anterior a la actual.
        @return Iterador constante original antes de ser decrementado.
    */
    const_stored_iterator operator--(int );
    
    /** @brief Operador de igualdad. Comprueba si dos iteradores constantes sobre posiciones no nulas hacen referencia a una misma posición del VectorD.
        @param[in] d Iterador constante sobre posiciones no nulas a comparar.
        @return True si hacen referencia a la misma posición, false en caso contrario
    */
    bool operator == (const const_stored_iterator & d);
    
    /** @brief Operador de desigualdad. Comprueba si dos iteradores constantes sobre posiciones no nulas hacen referencia a distintas posiciones del VectorD.
        @param[in] d Iterador constante sobre posicionesn no nulas a comparar.
        @return True si hacen referencia a la diferentes posiciones, false en caso contrario
    */
    bool operator != (const const_stored_iterator & d);
    
    /** @brief Operador de asignación. Asigna al iterador constante sobre elementos no nulos a posición a la que apunta el recibido.
        @param[in] d Iterador constante sobre posiciones no nulas a copiar.
    */
    const_stored_iterator & operator= (const const_stored_iterator & d) ;
 
  private:
    
    /**
     * Iterador a la lista vd interna del vector
     */
    typename list<pair<int, T > >::const_iterator ite;
    
};


};


#include "vectorDlist.hxx"

#endif
 
