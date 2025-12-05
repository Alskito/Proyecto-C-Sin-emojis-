/*
 * Proyecto C++
 * Alexander Zamudio Cano
 * A01710688
 * 2/12/2025
 */

 /*
 * Clase Vehiculo contiene los metodos y atributos genericos de
 * todos los vehiculos.
 * Tiene 3 clases hijas que son diferentes tipos de vehiculos:
 * Moto, Coche y Camioneta
 *
 */
#ifndef VEHICULO_H
#define VEHICULO_H

#include<string>
#include <sstream>

// Se declara la clase Vehiculo
class Vehiculo {
    private: // Se declaran sus atributos
        std::string marca;
        std::string modelo;
        int precio_original;
        int year;
        int kilometraje;

    public: // Se declaran sus metodos

        /**
        * Constructor por default
        * Inicializa las variables de instancia en cadenas vacias o ceros
        *
        * @param
        * @return Objeto Vehiculo
        */
        Vehiculo(): marca(""), modelo(""),
        precio_original(0), year(0), kilometraje(0) {};

        /**
        * Constructor con parametros
        * Recibe los datos del vehiculo para inicializar el objeto.
        *
        * @param mar La marca del vehiculo
        * @param mod El modelo del vehiculo
        * @param pre El precio original del vehiculo
        * @param ye El año del vehiculo
        * @param kil El kilometraje del vehiculo
        * @return Objeto Vehiculo
        */
        Vehiculo(std::string mar, std::string mod, int pre,
            int ye, int kil)
            : marca(mar), modelo(mod), precio_original(pre),
            year(ye), kilometraje(kil) {};

        std::string get_marca();
        std::string get_modelo();
        std::string to_string();
        int get_precio_original();
        int get_year();
        int get_kilometraje();


        void set_marca(std::string );
        void set_modelo(std::string );
        void set_precio_original(int );
        void set_year(int );
        void set_kilometraje(int );
};


/**
 * Obtiene el valor almacenado en la variable marca.
 *
 * @param
 * @return string con la marca del vehiculo
 */
std::string Vehiculo ::get_marca(){
  return marca;
}

/**
 * Obtiene el valor almacenado en la variable modelo.
 *
 * @param
 * @return string con el modelo del vehiculo
 */
std::string Vehiculo ::get_modelo(){
  return modelo;
}

/**
 * Obtiene el valor almacenado en la variable precio_original.
 *
 * @param
 * @return int con el precio original
 */
int Vehiculo ::get_precio_original(){
    return precio_original;
}

/**
 * Obtiene el valor almacenado en la variable year.
 *
 * @param
 * @return int con el año del vehiculo
 */
int Vehiculo ::get_year(){
    return year;
}

/**
 * Obtiene el valor almacenado en la variable kilometraje.
 *
 * @param
 * @return int con el kilometraje actual
 */
int Vehiculo ::get_kilometraje(){
    return kilometraje;
}

/**
 * Modifica el valor de la variable marca.
 *
 * @param mar La nueva marca a asignar
 * @return
 */
void Vehiculo ::set_marca(std::string mar){
    marca = mar;
}

/**
 * Modifica el valor de la variable modelo.
 *
 * @param mod El nuevo modelo a asignar
 * @return
 */
void Vehiculo ::set_modelo(std::string mod){
    modelo = mod;
}

/**
 * Modifica el valor de la variable precio_original.
 *
 * @param pre El nuevo precio a asignar
 * @return
 */
void Vehiculo ::set_precio_original(int pre){
    precio_original = pre;
}

/**
 * Modifica el valor de la variable year.
 *
 * @param ye El nuevo año a asignar
 * @return
 */
void Vehiculo ::set_year(int ye){
    year = ye;
}

/**
 * Modifica el valor de la variable kilometraje.
 *
 * @param kil El nuevo kilometraje a asignar
 * @return
 */
void Vehiculo ::set_kilometraje(int kil){
    kilometraje = kil;
}

/**
 * Almacena los valores de los atributos en un string
 *
 * @param
 * @return string con la informacion completa del vehiculo
 */
std::string Vehiculo::to_string(){
    std::stringstream aux;
    aux << marca << " " << modelo << " (" << year
    << ") " << kilometraje << "km";
    return aux.str();
}

#endif

