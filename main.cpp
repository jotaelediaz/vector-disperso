//
//  main.cpp
//
//  Created by Juan Luis Díaz on 13/12/14.
//  (CC) 2014 Juan Luis Díaz & Gregorio Vidoy
//


#include <iostream>
#include "vectorDmap.h"
#include "polinomio.h"

int main() {
    
    /* --- EJEMPLOS Y PRUEBAS SOBRE UN VECTOR DISPERSO --- */
    
    
    cout << "\n\n----------- VECTOR DISPERSO -----------\n\n\n" ;
    
    
    vectorD<int> miVectorDisperso_int; // Vector disperso de ints. (Valor nulo por defecto = 0)
    vectorD<string> miVectorDisperso_string(3,"nulo"); // Vector disperso de strings. (String nulo = "nulo");
    
    
    miVectorDisperso_string.push_back("nulo");
    miVectorDisperso_string.push_back("Amarillo");
    miVectorDisperso_string.push_back("Verde");
    miVectorDisperso_string.push_back("Azul");
    miVectorDisperso_string.push_back("nulo");
    miVectorDisperso_string.push_back("Morado");
    miVectorDisperso_string.push_back("Rojo");
    
    
    miVectorDisperso_int.push_back(4);
    miVectorDisperso_int.push_back(0);
    miVectorDisperso_int.push_back(5);
    miVectorDisperso_int.push_back(1);
    miVectorDisperso_int.push_back(13);
    miVectorDisperso_int.push_back(11);
    miVectorDisperso_int.push_back(0);
    
    
    
    
    vectorD<int>::const_iterator iter1 = miVectorDisperso_int.begin();
    vectorD<string>::iterator iter2 = miVectorDisperso_string.begin();
    
    vectorD<int>::const_iterator iter1_end = miVectorDisperso_int.cend();
    vectorD<string>::iterator iter2_end = miVectorDisperso_string.end();
    
    
    for(int i = 0; iter2 != iter2_end; i++){
        cout << "Posición: " << i << " ; Valor: " << (*iter2) << endl;
        ++iter2;
    }
    
    
    
    cout << "\n\n\n" ;
    
    
    
    for(int i = 1; iter1 != iter1_end; i++){
        cout << "Posición: " << i << " ; Valor: " << (*iter1) << endl;
        ++iter1;
    }
    
    
    
    
    
    miVectorDisperso_string.pop_back();  // Quitamos el Rojo
    miVectorDisperso_string.assign(2,"Naranja"); // Asignamos a la posición 2 el valor "Naranja"
    miVectorDisperso_string.assign(1,"Rojo"); // Asignamos a la posición 1 el valor "Rojo"
    
    
    
    miVectorDisperso_int.resize(3); // Cambio a tamaño 3 al vector de enteros
    
    
    
    
    vectorD<int>::const_stored_iterator st_iter1 = miVectorDisperso_int.csbegin(); //Iteradores a posiciones no nulas
    vectorD<string>::stored_iterator st_iter2 = miVectorDisperso_string.sbegin();
    
    vectorD<int>::const_stored_iterator st_iter1_end = miVectorDisperso_int.csend();
    vectorD<string>::stored_iterator st_iter2_end = miVectorDisperso_string.send();
    
    
    
    cout << "\n\n---------------------------- \n\n" ;
    
    
    
    for(int i = 0; st_iter2 != st_iter2_end; i++){
        cout << "Posición: " << (*st_iter2).first << " ; Valor: " << (*st_iter2).second << endl;
        ++st_iter2;
    }
    
    
    cout << "\n\n";
    
    
    for(int i = 0; st_iter1 != st_iter1_end; i++){
        cout << "Posición: " << (*st_iter1).first << " ; Valor: " << (*st_iter1).second << endl;
        ++st_iter1;
    }
    
    
    
    
    cout << "\n\n---------------------------- \n\n" ;
    
    
    
    
    cout << "El elemento 5 del VectorD de Strings -> " << miVectorDisperso_string[5] << endl;
    cout << "El elemento 3 del VectorD de Strings -> " << miVectorDisperso_string.at(3) << endl;
    
    
    cout << "\n\n";
    
    
    vectorD<int> miVectorDisperso_int_copia = miVectorDisperso_int;
    
    
    if (miVectorDisperso_int == miVectorDisperso_int_copia) {
        cout << "El vector de enteros y su copia SON IGUALES" << endl;
    } else {
        cout << "El vector de enteros y su copia NO SON IGUALES" << endl;
    }
    
    
    if(st_iter1 == st_iter1_end){
        cout << "Los iteradores st_iter1 y st_iter1_end SÍ apuntan a la misma posición" << endl;
    } else {
        cout << "Los iteradores st_iter1 y st_iter1_end NO apuntan a la misma posición" << endl;
    }
    
    
    cout << "\n\n------------------------------------------ \n\n" ;
    
    
    
    
    
    
    /* --- EJEMPLOS Y PRUEBAS SOBRE UN POLINOMIO --- */
    
    
    
    
    cout << "\n\n----------- POLINOMIO -----------\n\n\n" ;
    
    
    
    polinomio miPolinomio;
    polinomio miPolinomio2;
    
    
    miPolinomio.setMonomio(7, 5);  // Añadimos el monomio 7x^5 al polinomio
    miPolinomio.setMonomio(25, 2);
    miPolinomio.setMonomio(10, 1);
    miPolinomio.setMonomio(3, 0);
    
    
    miPolinomio2.setMonomio(100, 3);
    miPolinomio2.setMonomio(200, 2);
    miPolinomio2.setMonomio(300, 1);
    
    
    cout << "Polinomio 1 -> " << miPolinomio << endl;
    
    cout << "Polinomio 2 -> " << miPolinomio2 << endl;
    
    
    cout << "\n\n---------------------------- \n\n" ;
    
    
    cout << "El grado del Polinomio 1 es -> " << miPolinomio.getGrado() << endl;
    cout << "El coeficiente de grado 3 del Polinomio 2 es -> " << miPolinomio2.getCoeficiente(3) << endl;
    
    
    cout << "\n\n---------------------------- \n\n" ;
    
    
    cout << "La suma del Polinomio1 + Polinomio2 es -> " << miPolinomio + miPolinomio2 << endl;
    
    cout << "La diferencia del Polinomio1 - Polinomio2 es -> " << miPolinomio - miPolinomio2 << endl;
    
    
    cout << "\n\n---------------------------- \n\n" ;
    
    

    return 0;
}
