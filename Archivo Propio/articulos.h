#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED


bool grabarArticulo(Articulos art)
{
    FILE *pa;
    pa=fopen("articulos.dat","ab");
    if(pa==NULL)
    {
        return false;
    }
    fwrite(&art, sizeof art, 1, pa);
    fclose(pa);
    return true;
}

struct Articulos altaArticulo()
{
    system("cls");
    struct Articulos art;
    cout<<"INGRESE CODIGO:";
    cin>>art.codigo;
    fflush(stdin);
    cout<<"INGRESE DESCRIPCION:";
    cin.getline(art.descripcion,20);
    cout<<"INGRESE PRODUCCION:";
    cin>>art.produccion;
    cout<<"INGRESE STOCK:";
    cin>>art.stock;
    art.estado=true;
    return art;
}
void mostrar(Articulos art)
{
    if(art.estado==true)
    {
        cout<<endl;
        cout<<"CODIGO: "<<art.codigo<<endl;
        cout<<"DESCRIPCION: "<<art.descripcion<<endl;
        cout<<"PRODUCCION: "<<art.produccion<<endl;
        cout<<"STOCK: "<<art.stock<<endl;
        system("pause");
    }
}
bool listar()
{
    Articulos art;
    FILE *p=fopen("articulos.dat","rb");
    if(p==NULL)
    {
        cout<<endl;
        cout<<"No hay datos"<<endl;
        system("Pause");
        return false;
    }
    while(fread(&art,sizeof (Articulos),1,p)==1)
    {
        mostrar(art);
    }
    fclose(p);
    return true;
}
void mostrarBaja(Articulos art)
{
    if(art.estado==false)
    {
        cout<<endl;
        cout<<"CODIGO: "<<art.codigo<<endl;
        cout<<"DESCRIPCION: "<<art.descripcion<<endl;
        cout<<"PRODUCCION: "<<art.produccion<<endl;
        cout<<"STOCK: "<<art.stock<<endl;
        system("pause");
    }
}
bool listarBaja()
{
    Articulos art;
    FILE *p=fopen("articulos.dat","rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&art,sizeof (Articulos),1,p)==1)
    {
        mostrarBaja(art);
    }
    fclose(p);
    return true;
}
void baja(int cod)
{
    Articulos art;
    FILE *p=fopen("articulos.dat","rb+");
    if(p==NULL)
    {
        exit(1);
    }
    while(fread(&art,sizeof art,1,p))
    {
        if(art.codigo==cod)
        {
            fseek(p,-sizeof art,1);
            art.estado=false;
            fwrite(&art,sizeof art,1,p);
            cout<<endl;
            cout<<"Baja Exitosa"<<endl;
            system("pause");
            fclose(p);
        }
    }
    fclose(p);
}
void producion(int cod)
{
    Articulos art;
    int cant;
    FILE *p=fopen("articulos.dat","rb+");
    if(p==NULL)
    {
        exit(1);
    }
    while(fread(&art,sizeof art,1,p))
    {
        if(art.codigo==cod&&art.estado==true)
        {
            cout<<endl;
            cout<<"Ingrese cantidad en produccion: ";
            cin>>cant;
            fseek(p,-sizeof art,1);
            art.produccion+=cant;
            fwrite(&art,sizeof art,1,p);
            cout<<endl;
            cout<<"Produccion agregada"<<endl;
            system("pause");
            fclose(p);
        }
    }
    fclose(p);
}
void stock(int cod)
{
    Articulos art;
    int cant;
    FILE *p=fopen("articulos.dat","rb+");
    if(p==NULL)
        {
            exit(1);
    }
    while(fread(&art,sizeof art,1,p))
    {
        if(art.codigo==cod&&art.estado==true)
        {
            cout<<endl;
            cout<<"Ingrese cantidad en stock: ";
            cin>>cant;
            fseek(p,-sizeof art,1);
            art.produccion-=cant;
            art.stock+=cant;
            fwrite(&art,sizeof art,1,p);
            cout<<endl;
            cout<<"Stock Agregado"<<endl;
            system("pause");
            fclose(p);
        }
    }
    fclose(p);
}
void menu1()
{
    system("cls");
    cout<<"-------ARTICULOS---------"<<endl;
    cout<<endl;
    cout<<" 1- Alta"<<endl;
    cout<<" 2- Baja"<<endl;
    cout<<" 3- Produccion"<<endl;
    cout<<" 4- Stock"<<endl;
    cout<<" 5- Listado de Articulos Activos"<<endl;
    cout<<" 6- Listado de Articulos Inactivos"<<endl;
    cout<<endl;
    cout<<" 0- Salir"<<endl;
    cout<<endl;
    cout<<"-------ARTICULOS---------"<<endl;
    cout<<"Ingrese una opcion: ";
}
void menuArticulos()
{
    Articulos art;
    bool salir=false;
    while(!salir)
    {
        int op,cod;
        menu1();
        cin>>op;
        switch(op)
        {
        case 1:
            art=altaArticulo();
            if(grabarArticulo(art)==true)
            {
                cout<<"EL REGISTRO SE GRABO CORRECTAMENTE"<<endl;
                system("pause");
            }
            else
            {
                cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                system("pause");
            }
            break;
        case 2:
            cout<<endl;
            cout<<"INGRESE CODIGO A DAR DE BAJA: ";
            cin>>cod;
            baja(cod);
            break;
        case 3:
            cout<<endl;
            cout<<"Ingrese codigo de produccion: ";
            cin>>cod;
            producion(cod);
            break;
        case 4:
            cout<<endl;
            cout<<"Ingrese codigo de stock: ";
            cin>>cod;
            stock(cod);
            break;
        case 5:
            listar();
            break;
        case 6:
            listarBaja();
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
}

#endif // ARTICULOS_H_INCLUDED
