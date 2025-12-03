/*
 * Proyecto C++
 * Alexander Zamudio Cano
 * A01710688
 * 2/12/2025
 */

 /*
 * Clase Coche contiene el atributo puertas y el metodo
 * calcular_precio_venta
 * Hereda de la clase Vehiculo
 *
 */

#include "Vehiculo.h"
#include <string>
#include <sstream>

class Coche: public Vehiculo{
    private:
        // Se declaran los atributos
        int puertas;

    public:
        // Se declaran los metodos
        // Constructor default
        Coche(): Vehiculo(), puertas(0){};
        // Constructor
        Coche(std::string mar, std::string mod, int pre, int ye, 
            int kil, int pu)
            : Vehiculo(mar, mod, pre, ye, kil), puertas(pu){};


        float calcular_precio_venta();
        int get_puertas();
        std::string toString();

        void set_puertas(int );
        

};

int Coche::get_puertas(){
    return puertas;
}

void Coche::set_puertas(int pu){
    puertas = pu;
}

// Se calcula el precio de venta del coche 
// La formula es inventada
float Coche::calcular_precio_venta(){
    float precio = get_precio_original();
    float antiguedad = (2025 - get_year()) * 0.05;
    float uso = (get_kilometraje() / 1000.0) * 0.001; 
    float porcentaje = 1.0 - antiguedad - uso;
    float venta = precio * porcentaje;

    if(puertas == 4){
        venta += 500;
    }

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


// Agrega el valor de puertas al string
std::string Coche::toString(){
    std::stringstream aux;
    aux << Vehiculo::toString() << " | Puertas: " << puertas;
    return aux.str();
}



