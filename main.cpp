/*
 * Proyecto C++
 * Alexander Zamudio Cano
 * A01710688
 * 2/12/2025
 */

 /*
 * Main del proyecto C++, muestra los costos de venta
 * de distintos vehiculos deppendiendo de sus caracteristicas
 */

#include<iostream>
#include<string>
#include "Concesionaria.h"



int main(){
    Concesionaria Concesionaria_Benito_Juarez_IDK; // Nombre de la concesionaria
    int opcion = 0; 
    // Varibles temporales para los cin
    std::string t_marca; 
    std::string t_modelo;
    int t_precio;
    int t_year;
    int t_km;
    int t_extra;

    do {
        // Menu para que todo se vea bonito
        std::cout << "\n=================================================" 
        << std::endl;
        std::cout << "      APLICACION PARA GESTIONAR PRECIOS :d     " 
        << std::endl;
        std::cout << "=================================================" 
        << std::endl;
        std::cout << "1. Agregar MOTO" << std::endl;
        std::cout << "2. Agregar COCHE" << std::endl;
        std::cout << "3. Agregar CAMIONETA" << std::endl;
        std::cout << "4. Mostrar Precios de Venta" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "-----------------------------------------" 
        << std::endl;
        std::cout << "Selecciona una opcion(1 al 5): ";  std::cin >> opcion;


        switch(opcion) {
            case 1: { 
                // Se agrega una moto
                std::cout << "\n[NUEVA MOTO]" << std::endl;
                std::cout << "Marca(NO USES ESPACIOS): ";      
                std::cin >> t_marca;
                std::cout << "Modelo(NO USES ESPACIOS): ";     
                std::cin >> t_modelo;
                std::cout << "Precio Base(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_precio;
                std::cout << "Year(SOLO USA NUMEROS ENTEROS): ";        
                std::cin >> t_year;
                std::cout << "Kilometraje(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_km;
                std::cout << "Cilindraje (CC),(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_extra;

                Moto mo(t_marca, t_modelo, t_precio, t_year, t_km, t_extra);
            
                Concesionaria_Benito_Juarez_IDK.agregar_moto(mo);
                std::cout << ">> Moto agregada" << std::endl;
                break;
            }

            case 2: { 
                // Se agrega un coche
                std::cout << "\n[NUEVO COCHE]" << std::endl;
                std::cout << "Marca(NO USES ESPACIOS): ";      
                std::cin >> t_marca;
                std::cout << "Modelo(NO USES ESPACIOS): ";     
                std::cin >> t_modelo;
                std::cout << "Precio Base(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_precio;
                std::cout << "Year(SOLO USA NUMEROS ENTEROS): ";        
                std::cin >> t_year;
                std::cout << "Kilometraje(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_km;
                std::cout << "Numero de Puertas(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_extra;
                
                Coche co(t_marca, t_modelo, t_precio, t_year, t_km, t_extra);
           
                
                Concesionaria_Benito_Juarez_IDK.agregar_coche(co);
                std::cout << ">> Coche agregado" << std::endl;
                break;
            }

            case 3: { 
                // Se agrega un camioneta
                std::cout << "\n[NUEVA CAMIONETA]" << std::endl;
                std::cout << "Marca(NO USES ESPACIOS): ";     
                std::cin >> t_marca;
                std::cout << "Modelo(NO USES ESPACIOS): ";     
                std::cin >> t_modelo;
                std::cout << "Precio Base(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_precio;
                std::cout << "Year(SOLO USA NUMEROS ENTEROS): ";        
                std::cin >> t_year;
                std::cout << "Kilometraje(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_km;
                std::cout << "Capacidad de Carga (L),"
                    <<"(SOLO USA NUMEROS ENTEROS): "; 
                std::cin >> t_extra;

                Camioneta ca(t_marca, t_modelo, 
                    t_precio, t_year, t_km, t_extra);

               
                
                Concesionaria_Benito_Juarez_IDK.agregar_camioneta(ca);
                std::cout << ">> Camioneta agregada" << std::endl;
                break;
            }

            case 4: {
                // Muestra los precios de todo a manera de lista
                Concesionaria_Benito_Juarez_IDK.mostrar_precios_venta();
                break;
            }

            case 5:{
                // Mensajito de despedida :D
                std::cout << "MENSAJE DE DESPEDIDA GENERICO (•　ω　•) " 
                << std::endl;
                break;
            }
            default:
                std::cout << "Selecciona uno de los" 
                << "numeros del 1 al 5 (⌣̀_⌣́) )" 
                << std::endl;
            
        }

    } while(opcion != 5);


    

    return 0;
}


