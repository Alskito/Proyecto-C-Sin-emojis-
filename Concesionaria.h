/*
 * Proyecto C++
 * Alexander Zamudio Cano
 * A01710688
 * 2/12/2025
 */

 /*
 * Clase Concesionaria maneja los vehiculos
 * Moto, Coche y Camioneta
 *
 */

#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H
#include <iostream>
#include "Moto.h"
#include "Coche.h"
#include "Camioneta.h"

class Concesionaria {
    private:// Se declaran los atributos
        //Arreglos para guardar los vehiculos
        Moto inventario_motos[100];
        Coche inventario_coches[100];
        Camioneta inventario_camionetas[100];

        // Contadores para saber cuantos estan guardados en los arreglos
        int cantidad_motos;
        int cantidad_coches;
        int cantidad_camionetas;


    public: //Se declaran los metodos
        /**
        * Constructor por default
        * Inicializa los contadores de cantidad de vehiculos en 0.
        *
        * @param
        * @return Objeto Concesionaria
        */
        Concesionaria ()
            : cantidad_motos(0), cantidad_coches(0),
            cantidad_camionetas(0){};

        void agregar_moto(Moto &mo);
        void agregar_coche(Coche &co);
        void agregar_camioneta(Camioneta &ca);
        void mostrar_precios_venta();
};

/**
 * Utiliza el arreglo inventario_motos y su contador cantidad_motos.
 * Recibe un objeto de tipo Moto y lo agrega al inventario.
 * Verifica que no se exceda el limite del arreglo (100).
 *
 * @param mo Objeto Moto a agregar
 * @return
 */
void Concesionaria :: agregar_moto(Moto &mo){
    if (cantidad_motos < 100) {
        inventario_motos[cantidad_motos] = mo;
        cantidad_motos++;
    }
    else {
        std::cout << "DE ALGUNA MANERA LLENASTE EL INVENTARIO DE MOTOS"
        << std::endl;
    }
}

/**
 * Utiliza el arreglo inventario_coches y su contador cantidad_coches.
 * Recibe un objeto de tipo Coche y lo agrega al inventario.
 * Verifica que no se exceda el limite del arreglo (100).
 *
 * @param co Objeto Coche a agregar
 * @return
 */
void Concesionaria :: agregar_coche(Coche &co){
    if (cantidad_coches < 100) {
        inventario_coches[cantidad_coches] = co;
        cantidad_coches++;
    }
    else {
        std::cout << "DE ALGUNA MANERA LLENASTE EL INVENTARIO DE COCHES"
        << std::endl;
    }
}

/**
 * Utiliza el arreglo inventario_camionetas y su contador cantidad_camionetas.
 * Recibe un objeto de tipo Camioneta y lo agrega al inventario.
 * Verifica que no se exceda el limite del arreglo (100).
 *
 * @param ca Objeto Camioneta a agregar
 * @return
 */
void Concesionaria :: agregar_camioneta(Camioneta &ca){
    if (cantidad_camionetas < 100) {
        inventario_camionetas[cantidad_camionetas] = ca;
        cantidad_camionetas++;
    }
    else {
        std::cout << "DE ALGUNA MANERA LLENASTE EL INVENTARIO DE CAMIONETAS"
        << std::endl;
    }
}

/**
 * Recorre los arreglos de motos, coches y camionetas.
 * Calcula el precio de venta de cada vehiculo utilizando su metodo
 * calcular_precio_venta() y muestra la informacion en la consola.
 *
 * @param
 * @return
 */
void Concesionaria :: mostrar_precios_venta(){
    std::cout << "\n========== PRECIOS DE VENTA (MXN) :D =========="
    << std::endl;

    for(int i = 0; i < cantidad_motos; i++) {
        float precio_final = inventario_motos[i].calcular_precio_venta();

        std::cout << "[MOTO] " << inventario_motos[i].to_string()
                  << " | TOTAL: $" << precio_final << std::endl;
    }

    for(int i = 0; i < cantidad_coches; i++) {
        float precio_final = inventario_coches[i].calcular_precio_venta();

        std::cout << "[COCHE] " << inventario_coches[i].to_string()
                  << " | TOTAL: $" << precio_final << std::endl;
    }

    for(int i = 0; i < cantidad_camionetas; i++) {
        float precio_final = inventario_camionetas[i].calcular_precio_venta();

        std::cout << "[CAMIONETAS] " << inventario_camionetas[i].to_string()
                  << " | TOTAL: $" << precio_final << std::endl;
    }
}
#endif



