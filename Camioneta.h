/*
 * Proyecto C++
 * Alexander Zamudio Cano
 * A01710688
 * 2/12/2025
 */

 /*
 * Clase Camioneta contiene el atributo capacidad_carga 
 * y el metodo calcular_precio_venta
 * Hereda de la clase Vehiculo
 *
 */

#include "Vehiculo.h"
#include <string>
#include <sstream>

class Camioneta: public Vehiculo {
    private:
        // Se declaran los atributos
        int capacidad_carga; // En litros

    public:
        // Se declaran los metodos
        // Constructor default
        Camioneta (): Vehiculo(), capacidad_carga(0){};
        // Constructor
        Camioneta (std::string mar, std::string mod, int pre, 
                int ye, int kil, int cap) 
                : Vehiculo(mar, mod, pre, ye, kil), capacidad_carga(cap) {};

        float calcular_precio_venta();
        int get_capacidad_carga();
        std::string toString();

        void set_capacidad_carga(int );
        
};

int Camioneta ::get_capacidad_carga(){
    return capacidad_carga;
}


void Camioneta ::set_capacidad_carga(int cap){
    capacidad_carga = cap;
}

// Se calcula el precio de venta del camioneta
// La formula es inventada
float Camioneta::calcular_precio_venta(){
    float precio = get_precio_original();
    float antiguedad = (2025 - get_year()) * 0.05;
    float uso = (get_kilometraje() / 1000.0) * 0.001; 
    float porcentaje = 1.0 - antiguedad - uso;
    float venta = precio * porcentaje + (capacidad_carga * 1.5);
        
    // El valor minimo es el 15 % del precio original
    if(venta < (precio * 0.15)){
        return precio * 0.15;
    }

    // El valor maximo es el precio original
    if (venta > precio) {
        return precio;
    }

    return venta;
}


// Agrega el valor de capacidad_carga al string
std::string Camioneta::toString(){
    std::stringstream aux;
    aux << Vehiculo::toString() << " | Capacidad de carga: " 
    << capacidad_carga;
    return aux.str();
}


