#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

void mostrarVenta(Ventas vta)
{
    if(vta.codCl!=0)
    {
        cout<<endl;
        cout<<"Mes: "<<vta.mes<<endl;
        cout<<"Anio: "<<vta.anio<<endl;
        cout<<"Cliente: "<<vta.codCl<<endl;
        cout<<"Articulo: "<<vta.codigo<<endl;
        cout<<"Cantidad: "<<vta.cantidad<<endl;
        cout<<endl;
        system("pause");
    }
}
bool listarVenta()
{
    Ventas vta;
    FILE *p=fopen("ventas.dat","rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&vta,sizeof (Ventas),1,p)==1)
    {
        mostrarVenta(vta);
    }
    fclose(p);
    return true;
}

bool grabarVenta(Ventas vta)
{
    FILE *p=fopen("ventas.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    fwrite(&vta, sizeof vta,1,p);
    fclose(p);
    return true;
}
bool verificarArticulo(int cod)
{
    struct Articulos art;
    FILE *p=fopen("articulos.dat","rb");
    if(p!=NULL)
    {
        while(fread(&art,sizeof(Articulos),1,p))
        {
            if(cod==art.codigo)
            {
                if(art.estado==true)
                {
                    fclose(p);
                return false;
                }
            }
        }
    }
    fclose(p);
    return true;
}
bool verificarCliente (int cod)
{
    struct Clientes cl;
    FILE *p= fopen("clientes.dat", "rb");
    if(p!=NULL)
    {
        while(fread(&cl, sizeof (Clientes), 1, p))
        {
            if(cod ==cl.codCl)
            {
                fclose(p);
                return false;
            }
        }
    }
    fclose(p);
    return true;
}
bool verificarStock(int cant, int cod)
{
    Articulos art;
    FILE *p=fopen("articulos.dat","rb+");
    if(p==NULL)
        {
            exit(1);
    }
    while(fread(&art,sizeof art,1,p))
    {
        if(art.stock>=cant&&art.codigo==cod)
        {
            fseek(p,-sizeof art,1);
            art.stock-=cant;
            fwrite(&art,sizeof art,1,p);
            cout<<endl;
            cout<<"Stock descontado"<<endl;
            system("pause");
            fclose(p);
            return false;
        }
    }
    fclose(p);
    return true;
}
struct Ventas cargarVenta()
{
    struct Ventas vta;
    int c,x,z;
    system("cls");
    cout<<"Ingrese mes: ";
    cin>>vta.mes;
    cout<<"ingrese anio: ";
    cin>>vta.anio;
    cout<<"Ingrese codigo del cliente: ";
    cin>>c;
    while(verificarCliente(c)==true)
    {
        cout<<endl;
        cout<<"Codigo incorrecto"<<endl;
        system("pause");
        cout<<"Ingrese codigo del cliente: ";
        cin>>c;

    }
    vta.codCl=c;
    cout<<"Ingrese codigo de articulo: ";
    cin>>x;
    while(verificarArticulo(x)==true)
    {
        cout<<endl;
        cout<<"articulo incorrecto"<<endl;
        system ("pause");
        cout<<"Ingrese codigo de articulo: ";
        cin>>x;
    }
    vta.codigo=x;
    cout<<"ingrese cantidad: ";
    cin>>z;
    while(verificarStock (z,x)==true)
    {
        cout<<"Stock insufuciente"<<endl;
        system("pause");
        cout<<"ingrese cantidad: ";
    cin>>z;
    }
    vta.cantidad=z;
    return vta;
}
void menu3()
{
    system("cls");
    cout<<endl;
    cout<<"-------------VENTAS-------------"<<endl;
    cout<<endl;
    cout<<" 1- Ventas"<<endl;
    cout<<" 2- Producto mas vendido"<<endl;
    cout<<" 3- Mes con menos ventas"<<endl;
    cout<<" 4- Mostrar ventas"<<endl;
    cout<<endl;
    cout<<" 0- Salir"<<endl;
    cout<<endl;
    cout<<"-------------VENTAS-------------"<<endl;
    cout<<endl;
    cout<<"Ingrese una opcion: ";
}
void menuVentas()
{
    Ventas vta;
    bool salir=false;
    while(!salir)
    {
        int op;
        menu3();
        cin>>op;
        switch(op)
        {
        case 1:
            vta=cargarVenta();
            if(grabarVenta(vta)==true)
            {
                cout<<endl;
                cout<<"Se grabo la venta"<<endl;
                cout<<endl;
                system("pause");
            }
            else
            {
                cout<<endl;
                cout<<"No se grabo la venta"<<endl;
                cout<<endl;
                system("pause");
            }
            break;
        case 4:
            listarVenta();
            break;
        case 0:
            salir=true;
            break;
        default:
            cout<<"Opcion incorrecta"<<endl;
            system("pause");
            break;
        }
    }
}

#endif // VENTAS_H_INCLUDED
