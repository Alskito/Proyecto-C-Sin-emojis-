/*
 * Proyecto C++
 * Alexander Zamudio Cano
 * A01710688
 * 2/12/2025
 */

 /*
 * Clase Moto contiene el atributo cc y el metodo
 * calcular_precio_venta
 * Hereda de la clase Vehiculo
 *
 */

#include<string>
#include "Vehiculo.h"
#include <sstream>

class Moto: public Vehiculo{
    private: // Se declaran los atributos
        int cc; //indica la potencia y el rendimiento de la moto

    public: // Se declaran los metodos
        /**
        * Constructor por default
        * Inicializa el objeto utilizando el constructor default de Vehiculo
        * inicializa cc en 0.
        *
        * @param
        * @return Objeto Moto
        */
        Moto(): Vehiculo(), cc(0) {};

        /**
        *Constructor con parametros
        * Recibe los datos del vehiculo y el cc para inicializar el objeto.
        * Llama al constructor de la clase padre (Vehiculo).
        *
        * @param mar La marca de la moto
        * @param mod El modelo de la moto
        * @param pre El precio original
        * @param ye El año de la moto
        * @param kil El kilometraje
        * @param c El cilindraje (cc)
        * @return Objeto Moto
        */
        Moto(std::string mar, std::string mod, int pre,
            int ye, int kil, int c)
            : Vehiculo(mar, mod, pre, ye, kil), cc(c){};

        float calcular_precio_venta();
        int get_cc();
        std::string to_string();

        void set_cc(int );

};

/**
 * Obtiene el valor almacenado en la variable cc.
 *
 * @param
 * @return int con el cilindraje de la moto
 */
int Moto::get_cc(){
    return cc;
}

/**
 * Modifica el valor de la variable cc.
 *
 * @param c El nuevo cilindraje a asignar
 * @return
 */
void Moto::set_cc(int c){
    cc = c;
}

/**
* Utiliza los atributos de la clase padre (precio, año, kilometraje)
 * y el atributo propio (cc).
 * Calcula el precio de venta basado en la depreciacion por antiguedad,
 * uso y el cilindraje.
 *
 * Valida que el precio no exceda el original ni sea menor al 15%.
 *
 * @param
 * @return float con el precio calculado de venta
 */
float Moto::calcular_precio_venta(){ // La formula es inventada
    float precio = get_precio_original();
    float antiguedad = (2025 - get_year()) * 0.05;
    float uso = (get_kilometraje() / 1000.0) * 0.001;
    float porcentaje = 1.0 - antiguedad - uso;
    float venta = precio * porcentaje + (cc * 2);

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
 * Agrega el valor del cilindraje (cc) al string.
 *
 * @param
 * @return string con la informacion completa de la moto
 */
std::string Moto::to_string(){
    std::stringstream aux;
    aux << Vehiculo::to_string() << " | CC: " << cc;
    return aux.str();
}

