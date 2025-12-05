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
    private: // Se declaran los atributos
        int capacidad_carga; // En litros

    public: // Se declaran los metodos
        /**
        * Constructor por default
        * Inicializa el objeto utilizando el constructor default de Vehiculo
        * inicializa capacidad_carga en 0.
        *
        * @param
        * @return Objeto Camioneta
        */
        Camioneta (): Vehiculo(), capacidad_carga(0){};

        /**
        * Constructor con parametros
        * Recibe los datos del vehiculo y la capacidad de carga
        * para inicializar el objeto.
        * Llama al constructor de la clase padre (Vehiculo).
        *
        * @param mar La marca de la camioneta
        * @param mod El modelo de la camioneta
        * @param pre El precio original
        * @param ye El año de la camioneta
        * @param kil El kilometraje
        * @param cap La capacidad de carga en litros
        * @return Objeto Camioneta
        */
        Camioneta (std::string mar, std::string mod, int pre,
                int ye, int kil, int cap)
                : Vehiculo(mar, mod, pre, ye, kil), capacidad_carga(cap) {};

        float calcular_precio_venta();
        int get_capacidad_carga();
        std::string to_string();

        void set_capacidad_carga(int );

};

/**
 * Obtiene el valor almacenado en la variable capacidad_carga.
 *
 * @param
 * @return int con la capacidad de carga
 */
int Camioneta ::get_capacidad_carga(){
    return capacidad_carga;
}

/**
 * Modifica el valor de la variable capacidad_carga.
 *
 * @param cap La nueva capacidad de carga a asignar
 * @return
 */
void Camioneta ::set_capacidad_carga(int cap){
    capacidad_carga = cap;
}

/**
 * Utiliza los atributos de la clase padre (precio, año, kilometraje)
 * y el atributo propio (capacidad_carga).
 * Calcula el precio de venta basado en la depreciacion por antiguedad
 * ,uso y la capacidad de carga.
 *
 * Valida que el precio no exceda el original ni sea menor al 15%.
 *
 * @param
 * @return float con el precio calculado de venta
 */
float Camioneta::calcular_precio_venta(){ // La formula es inventada
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


/**
 * Utiliza el metodo to_string de la clase padre Vehiculo.
 * Agrega la capacidad de carga al string.
 *
 * @param
 * @return string con la informacion completa de la moto
 */
std::string Camioneta::to_string(){
    std::stringstream aux;
    aux << Vehiculo::to_string() << " | Capacidad de carga: "
    << capacidad_carga;
    return aux.str();
}



