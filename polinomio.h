#ifndef practica5_polinomio_h
#define practica5_polinomio_h


#include"vectorDlist.h"

using namespace std;

/**
 * @author Diciembre 2014 - JotaEle Díaz & Grego Vidoy
 */

//! TDA polinomio
/*
 * Descripción
 *TDA que permite la representación de polinomios. Permite realizar varias operaciones con polinomios como la suma y resta de ellos.
 * Gracias a la implementación interna usando un Vector Disperso (vectorD), el recorrido y acceso sobre este es eficiente y su almacenamiento ocupa una menor cantidad de memoria.
 * La gestión de memoria es dinámica y el tamaño del polinomio es modificable a medida que se van añadiendo monomios a éste.
*/
class polinomio{
    
    public:
    
    class iterator; // iterador sobre todos los elementos del polinomio
    class const_iterator; // const iterador sobre todos los elementos del polinomio
    
    
    /** @brief Imprime por la salida estándar un polinomio
        @param[in] os Salida del polinomio
        @param[in] p Polinomio a imprimir.
    */
    friend ostream& operator<<(ostream& os, const polinomio& p);
    
    
    //////////// constructores //////////////
    
    /** @brief Constructor por defecto.
    */
    polinomio();
    
    /** @brief Constructor primitivo que hace una copia de un polinomio
        @param[in] otro polinomio que se desea copiar
    */
    polinomio(const polinomio & otro);//constructor primitivo hace una copia del polinomio recibe un polinomio
    
    
    
    //////////Destructor/////////////
    
    /** @brief Destructor primitivo de vectorD.
    */
    ~polinomio();
    
    
    /////////// Consultores ////////////
    
    /** @brief Consulta el grado del polinomio
        @return el grado del polinomio. (El mayor de los grados de los monomios que lo componen) (int)
    */
    int getGrado();
    
    
    /** @brief Consulta el coeficiente de un monomio
        @param[in] gm grado del monomio
        @return retorna su coeficiente (int)
    */
    int getCoeficiente(int gm);
    
    
    ////////// Modificadores /////////////
    
    /** @brief Añade un nuevo monomio al polinomio de coeficiente c y grado g (cx^g)
        @param[in] c Coeficiente del nuevo monomio.
        @param[in] g Grado del nuevo monomio.
        @post Si ya existía en el polinomio un monomio con el mismo grado, se sustituirá por el nuevo.
    */
    void setMonomio(int c, int g);
    
    ////////// Operadores ///////////
    
    /** @brief Operador de asignación. Asigna una copia del polinomio al recibido como argumento.
        @param[in] otro polinomio a copiar.
        @return polinomio copiado
        @post Los valores los valores del polinomio quedan igual que otro polinomio.
    */
    polinomio & operator= (const polinomio & otro);
    
    
    /** @brief Operador suma. Suma al polinomio el polinomio recibido como argumento.
        @param[in] otro polinomio a sumar.
        @return polinomio suma de ambos
        @post El polinomio original no se ve alterado.
    */
    polinomio operator+ (const polinomio & otro);
    
    
    /** @brief Operador diferencia. Resta al polinomio el polinomio recibido como argumento.
        @param[in] otro polinomio a restar.
        @return Polinomio diferencia de ambos
        @post El polinomio original no se ve alterado.
    */
    polinomio operator- (polinomio & otro);
    
    
    /** @brief Operador unario -. Da como resultado un polinomio que es igual al polinomio original en negativo (-polinomio).
     @return Polinomio en negativo (-polinomio).
     @post El polinomio original no se ve alterado.
     */
    polinomio operator-();
    
    
    /////////////// MÉTODOS SOBRE ITERADORES ///////////////////
    
    
    /** @brief Devuelve un iterador que apunta al primer elemento del polinomio.
        @return Iterador a la primera posición.
        @post No se modifica el polinomio.
     */
    iterator begin();
    
    
    /** @brief Devuelve un iterador que apunta al final (es decir, al elemento siguiente al último) del polinomio.
        @return Iterador al elemento siguiente al último.
        @post No se modifica el polinomio.
    */
    iterator end();
    
    
    /** @brief Devuelve un iterador constante que apunta al primer elemento del polinomio.
        @return Iterador constante a la primera posición.
        @post No se modifica el polinomio.
    */
    const_iterator cbegin() const;

    
    /** @brief Devuelve un iterador constante que apunta al final (es decir, al elemento siguiente al último) del polinomio.
        @return Iterador constante al elemento siguiente al último.
        @post No se modifica el polinomio.
    */
    const_iterator cend() const;
   
    
    private:
    
    /**
     * valor constante indica el valor que tomara el vector como nulo
     */
    const int nulo = 0;
    
    /**
     * vectodD usado para almacenar los valores del polinomio (posicion = grado del monomio) (valor = coeficiente del monomio)
     */
    vectorD <int> vPolinomio;
    
    /**
     * numero de nodos almacenados
     */
    int n_monomios=0;
    
    
    public:
    
    /** @brief class iterator
     * Iterador hacia delante sobre todas las posiciones del polinomio itera sobre las oposiciones != nulo.
     * iterator, operator*, operator++, ++operator operator=(iterator), operator==, operator!=
     **/
    class iterator{
        
    public:
        
        friend class polinomio;
        
        /** @brief Constructor primitivo del iterador sobre el VectorD.
        */
        iterator() ;
        
        
        /** @brief Constructor primitivo que crea un iterador sobre un VectorD copia de otro iterador.
            @param[in] d Iterador al vector disperso que se desea copiar
        */
        iterator(const iterator & d);
        
        
        /** @brief Operador de indirección. Devuelve el elemento del VectorD al cual hace referencia el iterador.
            @return la referencia a un pair <coeficiente,grado>.
        */
        const pair<const int, int > & operator *(  ) ;
        
        
        /** @brief Operador de incremento (++it). Incrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
            @return Iterador a la posición siguiente a la actual
            @post Se modifica el iterador.
        */
        iterator & operator++( );
        
        /** @brief Operador de incremento (it++). Incrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
            @return Iterador original antes de ser incrementado.
        */
        iterator operator++(int ) ;
        
        
        /** @brief Operador de decremento (--it). Incrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
         @return Iterador a la posición anterior a la actual.
         @post Se modifica el iterador.
         */
        iterator & operator--( );
        
        
        /** @brief Operador de decremento (it--). Decrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
         @return Iterador original antes de ser decrementado.
         */
        iterator operator--(int );
        
        /** @brief Operador de igualdad. Comprueba si dos iteradores hacen referencia a una misma posición del polinomio.
            @param[in] d Iterador a comparar.
            @return True si hacen referencia a la misma posición, false en caso contrario.
        */
        bool operator == (const iterator & d) ;
        
        
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
         * iterador tipo stored_iterator de vectorD
         */
        vectorD<int>::stored_iterator it;
    };
    
    
    /** @brief class const_iterator
     * Iterador constante hacia delante sobre todas las posiciones del vectorD. Lectura
     * const_iterator, const_iterator(const_iterator), const_iterator(iterator), operator*, operator++, ++operator, operator=(iterator), operator==, operator!=
     **/
    class const_iterator{
    public:
        
        friend class polinomio;
        
        /** @brief Constructor primitivo del iterador sobre el VectorD.
        */
        const_iterator() ;
        
        
        /** @brief Constructor primitivo que crea un iterador constante sobre un VectorD copia de otro iterador constante.
            @param[in] d Iterador al vector disperso que se desea copiar
        */
        const_iterator(const const_iterator & d);
        
        
        /** @brief Operador de indirección. Devuelve el elemento del VectorD al cual hace referencia el iterador.
            @return la referencia a un pair <coeficiente,grado>.
        */
        const pair<const int, int > & operator*(  );
        
        
        /** @brief Operador de decremento (++it). Incrementa el iterador constante, es decir referencia el iterador a la posición siguiente a la actual.
            @return Iterador constante a la posición siguiente a la actual.
        */
        const_iterator & operator++( );
        
        
        /** @brief Operador de decremento (it++). Devuelve un iterador constante a la posición siguiente a la referenciada por el iterador actual.
            @return Iterador constante original antes de ser incrementado.
        */
        const_iterator operator++(int ) ;
        
        
        /** @brief Operador de decremento (--it). Incrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
         @return Iterador constante a la posición siguiente a la actual.
         */
        const_iterator & operator--( );
        
        
        /** @brief Operador de decremento (it--). Incrementa el iterador, es decir referencia el iterador a la posición siguiente a la actual.
         @return Iterador original antes de ser decrementado.
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
        bool operator != (const const_iterator & d);
        
        /** @brief Operador de asignación. Asigna al iterador la posición a la que apunta el iterador recibido.
            @param[in] d Iterador a copiar.
        */
        const_iterator & operator=(const const_iterator & d);
   
    private:
        
        /**
         * iterador tipo const_stored_iterator de vectorD
        */
        vectorD<int>::const_stored_iterator it;
    };
};


#include "polinomio.hxx"


#endif
