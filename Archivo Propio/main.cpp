#include <iostream>
#include <stdlib.h>//system
#include <string.h>
#include <stdio.h>//fopen, fflush

using namespace std;

#include "tipos.h"
#include "articulos.h"
#include "clientes.h"
#include "ventas.h"

void Menu()
{
    system("cls");
    cout<<"----------MENU------------"<<endl;
    cout<<endl;
    cout<<" 1- Atriculos"<<endl;
    cout<<" 2- Clientes"<<endl;
    cout<<" 3- Ventas"<<endl;
    cout<<endl;
    cout<<" 0- Salir"<<endl;
    cout<<endl;
    cout<<"----------MENU------------"<<endl;
    cout<<"Ingrese una opcion: ";
    }
int main()
{
    bool salir=false;
    while(!salir)
    {
        int op;
        Menu();
        cin>>op;
        switch(op)
        {
        case 1:
            menuArticulos();
            break;
        case 2:
            menuClientes();
            break;
        case 3:
            menuVentas();
            break;
        case 0:
            salir=true;
            break;
        default:
            cout<<"OPCION INCORRECTA"<<endl,
            system("pause");
            break;
        }
    }

    return 0;
}
