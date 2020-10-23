#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct Articulos
{
    int codigo;
    char descripcion[20]="";
    bool estado=false;
    int produccion=0;
    int stock=0;

};

struct Clientes
{
    int codCl=0;
    char nombre[20]="";
    char direccion[20]="";
    bool estado=false;
};
struct Ventas
{
    int mes,anio;
    int codCl=0;
    int codigo;
    int cantidad;
};

#endif // TIPOS_H_INCLUDED
