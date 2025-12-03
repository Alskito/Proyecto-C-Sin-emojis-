
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
    private:
        // Se decalran sus atributos 
        std::string marca; 
        std::string modelo;
        int precio_original;
        int year;
        int kilometraje;
    public:
        // Se decalran sus metodos
        // Constructor default
        Vehiculo(): marca(""), modelo(""), 
        precio_original(0), year(0), kilometraje(0) {}; 
        // Constructor
        Vehiculo(std::string mar, std::string mod, int pre, 
            int ye, int kil)
            : marca(mar), modelo(mod), precio_original(pre), 
            year(ye), kilometraje(kil) {};

        // Setters y getters
        std::string get_marca();
        std::string get_modelo();
        std::string toString();
        int get_precio_original();
        int get_year();
        int get_kilometraje();
    

        void set_marca(std::string ); 
        void set_modelo(std::string ); 
        void set_precio_original(int );
        void set_year(int );
        void set_kilometraje(int );
};

std::string Vehiculo ::get_marca(){
  return marca;
}

std::string Vehiculo ::get_modelo(){
  return modelo;
}

int Vehiculo ::get_precio_original(){
    return precio_original;
}

int Vehiculo ::get_year(){
    return year;
}

int Vehiculo ::get_kilometraje(){
    return kilometraje;
}

void Vehiculo ::set_marca(std::string mar){
    marca = mar;
}

void Vehiculo ::set_modelo(std::string mod){
    modelo = mod;
}

void Vehiculo ::set_precio_original(int pre){
    precio_original = pre;
}

void Vehiculo ::set_year(int ye){
    year = ye;
}

void Vehiculo ::set_kilometraje(int kil){
    kilometraje = kil;
}

// Almacena los valores de los atributos en un string
std::string Vehiculo::toString(){
    std::stringstream aux;
    aux << marca << " " << modelo << " (" << year 
    << ") " << kilometraje << "km";
    return aux.str();
}

#endif
