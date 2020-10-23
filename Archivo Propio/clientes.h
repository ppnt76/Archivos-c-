#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

bool grabarCliente(Clientes cl)
{
    FILE *p=fopen("clientes.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    fwrite(&cl, sizeof cl, 1, p);
    fclose(p);
    return true;
}
struct Clientes altaCliente()
{
    system("cls");
    struct Clientes cl;
    fflush(stdin);
    cout<<"INGRESE ID: ";
    cin>>cl.codCl;
    fflush(stdin);
    cout<<"INGRESE NOMBRE: ";
    cin.getline(cl.nombre,20);
    cout<<"INGRESE DIRECCION: ";
    cin.getline(cl.direccion,20);
    cl.estado=true;
    return cl;
}
void bajaCl(int cod)
{
    Clientes cl;
    FILE *p=fopen("clientes.dat","rb+");
    if(p==NULL)
    {
        cout<<"ERROR"<<endl;
        system("pause");
    }
    while(fread(&cl,sizeof cl,1,p))
    {
        if(cl.codCl==cod&&cl.estado==true)
        {
            fseek(p,-sizeof cl,1);
            cl.estado=false;
            fwrite(&cl,sizeof cl,1,p);
             fclose(p);
            cout<<endl;
            cout<<"Baja Exitosa"<<endl;
            system("pause");
        }
    }
    fclose(p);
}
void buscarCl(int cod)
{
    Clientes cl;
    bool salir=false;
    FILE *p=fopen("clientes.dat","rb+");
    if(p==NULL)
    {
        cout<<"Error"<<endl;
        system("pause");
    }
    while(fread(&cl,sizeof cl,1,p))
    {
        if(cl.codCl==cod&&salir==false)
        {
            cout<<"ID: "<<cl.codCl<<endl,
                cout<<"NOMBRE: "<<cl.nombre<<endl;
                salir=true;
            system("pause");
        }
    }
    if(salir==false)
    {
        cout<<"No existe"<<endl;
    system("pause");
    }
    fclose(p);
}
void mostrarCl(Clientes cl)
{
    if(cl.estado==true)
    {
        cout<<endl;
        cout<<"CODIGO: "<<cl.codCl<<endl;
        cout<<"NOMBRE: "<<cl.nombre<<endl;
        cout<<"DIRECCION: "<<cl.direccion<<endl;
        system("pause");
    }
}
bool listarCl()
{
    Clientes cl;
    FILE *p=fopen("clientes.dat","rb");
    if(p==NULL)
    {
        cout<<endl;
        cout<<"No hay datos"<<endl;
        system("pause");
        return false;
    }
    while(fread(&cl,sizeof(Clientes),1,p)==1)
    {
        mostrarCl(cl);
    }
    fclose(p);
    return true;
}
void mostrarClInacativo(Clientes cl)
{
    if(cl.estado==false)
    {
        cout<<endl;
        cout<<"CODIGO: "<<cl.codCl<<endl;
        cout<<"NOMBRE: "<<cl.nombre<<endl;
        cout<<"DIRECCION: "<<cl.direccion<<endl;
        system("pause");
    }
}
bool listarClInacativo()
{
    Clientes cl;
    FILE *p=fopen("clientes.dat","rb");
    if(p==NULL)
    {
        cout<<endl;
        cout<<"No hay datos"<<endl;
        system("pause");
        return false;
    }
    while(fread(&cl,sizeof(Clientes),1,p)==1)
    {
        mostrarClInacativo(cl);
    }
    fclose(p);
    return true;
}
void menu2()
{
    system("cls");
    cout<<"-----------CLIENTES----------"<<endl;
    cout<<endl;
    cout<<" 1- Alta"<<endl;
    cout<<" 2- Baja"<<endl;
    cout<<" 3- Buscar por ID"<<endl;
    cout<<" 4- Listado de ativos"<<endl;
    cout<<" 5- listado de inactivos"<<endl;
    cout<<endl;
    cout<<" 0- Salir"<<endl;
    cout<<endl;
    cout<<"-----------CLIENTES----------"<<endl;
    cout<<"Ingrese una opcion: ";
}
void menuClientes()
{
    Clientes cl;
    bool salir=false;
    while(!salir)
    {
        int op,cod;
        menu2();
        cin>>op;
        switch(op)
        {
        case 1:
            cl=altaCliente();
            if(grabarCliente(cl)==true)
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
            cout<<"INGRESE ID CLIENTE A DAR DE BAJA: ";
            cin>>cod;
            bajaCl(cod);
            break;
        case 3:
            cout<<endl;
            cout<<"INGRESE ID DEL CLIENTE A BUSCAR: ";
            cin>>cod;
            buscarCl(cod);
            break;
        case 4:
            listarCl();
            break;
        case 5:
            listarClInacativo();
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

#endif // CLIENTES_H_INCLUDED
