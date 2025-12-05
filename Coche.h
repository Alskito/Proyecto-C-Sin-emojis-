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
    private: // Se declaran los atributos
        int puertas;

    public: // Se declaran los metodos

        /**
        * Constructor por default
        * Inicializa el objeto utilizando el constructor default de Vehiculo
        * inicializa puertas en 0.
        *
        * @param
        * @return Objeto Coche
        */
        Coche(): Vehiculo(), puertas(0){};

        /**
        * Constructor con parametros
        * Recibe los datos del vehiculo y
        * el numero de puertas para inicializar el objeto.
        * Llama al constructor de la clase padre (Vehiculo).
        *
        * @param mar La marca del coche
        * @param mod El modelo del coche
        * @param pre El precio original
        * @param ye El año del coche
        * @param kil El kilometraje
        * @param pu El numero de puertas
        * @return Objeto Coche
        */
        Coche(std::string mar, std::string mod, int pre, int ye,
            int kil, int pu)
            : Vehiculo(mar, mod, pre, ye, kil), puertas(pu){};


        float calcular_precio_venta();
        int get_puertas();
        std::string to_string();

        void set_puertas(int );


};

/**
 * Obtiene el valor almacenado en la variable puertas.
 *
 * @param
 * @return int con el numero de puertas
 */
int Coche::get_puertas(){
    return puertas;
}

/**
 * Modifica el valor de la variable puertas.
 *
 * @param pu El nuevo numero de puertas a asignar
 * @return
 */
void Coche::set_puertas(int pu){
    puertas = pu;
}


/**
 * Utiliza los atributos de la clase padre (precio, año, kilometraje)
 * y el atributo propio (puertas).
 * Calcula el precio de venta basado en la depreciacion por antiguedad
 * y uso. Si el coche tiene 4 puertas, aumenta su valor.
 *
 * Valida que el precio no exceda el original ni sea menor al 15%.
 *
 * @param
 * @return float con el precio calculado de venta
 */
float Coche::calcular_precio_venta(){ // La formula es inventada
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


/**
 * Utiliza el metodo to_string de la clase padre Vehiculo.
 * Agrega el numero de puertas al string.
 *
 * @param
 * @return string con la informacion completa de la moto
 */
std::string Coche::to_string(){
    std::stringstream aux;
    aux << Vehiculo::to_string() << " | Puertas: " << puertas;
    return aux.str();
}



