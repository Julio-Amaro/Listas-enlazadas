#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

typedef struct _nodo{

char nombre[20] , apellido[20] , telefono[20] , direccion[20];
struct _nodo *siguiente;
struct _nodo *anterior;
struct _nodo *Lista_trabajador;

}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

//Funciones de con las listas

void insertar(Lista *Lista, char *nom, char const *tlf, char const *dir){
    pNodo nuevo, actual;
    //creando nuevo nodo
    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    memcpy(nuevo->nombre, nom, strlen(nom));
    memcpy(nuevo->telefono, tlf, strlen(tlf));
    memcpy(nuevo->direccion, dir, strlen(dir));

    //colocamos actual en la primera posición de la lista
    actual= *Lista;
    if(actual) while(actual ->anterior) actual = actual->anterior;
    //si la lista está vacía

    if(!actual || strcmp(actual->nombre, nom)== 1){
        //añadimos la lista a continuación del nuevo nodo
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        if(actual) actual->anterior = nuevo;
        if(!*Lista) *Lista = nuevo;


    }

    else{
            while(actual->siguiente && strcmp(actual->siguiente->nombre, nom)== -1) actual = actual->siguiente;

                nuevo->siguiente = actual->siguiente;
                actual->siguiente = nuevo;
                nuevo->anterior = actual;
                if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;

    }

}

void MostrarLista(Lista *Lista){
    pNodo nodo = *Lista;

    if(!nodo){ printf("Lista Vacia"); return;}

    nodo = *Lista;

        while(nodo->anterior) nodo= nodo->anterior;
        printf("Lista: ");
        while(nodo){
            cout<<nodo->nombre<<"-> ";
            nodo = nodo->siguiente;
        }


    printf("\n");
}


void eliminar_empresa(Lista *Lista, char const *nom){

    pNodo nodo;

    //Revisamos que la lista no esté vacía
    nodo = *Lista;
   if(!nodo) cout<< "La lista esta vacia, por lo tanto la empresa buscada no se encuentra dentro de ella";

   //Ubicamos nodo al principio de la lista
    else{
        while(nodo->anterior) nodo = nodo->anterior;

        while(nodo){
            if(strcmp(nodo->nombre, nom)==0){
            //Borrando el nodo
            //Si lista apunta al nodo que queremos
            if(nodo == *Lista)
                if(nodo->anterior)*Lista = nodo->anterior;
                else *Lista = nodo->siguiente;

            if(nodo->anterior)//no es el primer elemento
            nodo->anterior->siguiente = nodo->siguiente;

            if(nodo->siguiente)//No es el último
            nodo->siguiente->anterior = nodo->anterior;

            free(nodo);
            return;
            }
            else nodo = nodo->siguiente;

            }
    }
}


void eliminar_emp_repe(Lista *Lista){
  pNodo nodo;
    nodo = *Lista;
    if(!nodo) cout<< "La lista esta vacia";

    else{
            //lo llevo al inicio de la lista
        while(nodo->anterior) nodo = nodo->anterior;

        while(nodo->siguiente){
            if(strcmp(nodo->nombre, nodo->siguiente->nombre)==0){
            //Borrando el nodo
            //Si lista apunta al nodo que queremos
            if(nodo == *Lista)
                if(nodo->anterior)*Lista = nodo->anterior;
                else *Lista = nodo->siguiente;

            if(nodo->anterior)//no es el primer elemento
            nodo->anterior->siguiente = nodo->siguiente;

            if(nodo->siguiente)//No es el último
            nodo->siguiente->anterior = nodo->anterior;

            free(nodo);
            }

            else nodo= nodo->siguiente;

            }

    }
}

void menu_trabajadores()
{
     cout<<"\n1- Ingresar trabajador a la lista";
     cout<<"\n2- Eliminar trabajador";
     cout<<"\n3- Mostrar lista de trabajadores y cantidad de trabajadores";
     cout<<"\n4- Eliminar trabajadores duplicados";
     cout<<"\n5- Buscar un trabajador de la empresa";
     cout<<"\n6- Salir";

     cout<<"\n\n ingrese opcion: ";
}

void insertar_trabajador(Lista *Lista, char const *nom, char const *tlf, char const *dir, char const *apell){
    pNodo nuevo, actual;
    //creando nuevo nodo
    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    memcpy(nuevo->nombre, nom, strlen(nom));
    memcpy(nuevo->telefono, tlf, strlen(tlf));
    memcpy(nuevo->direccion, dir, strlen(dir));
    memcpy(nuevo->apellido, apell, strlen(apell));

    //colocamos actual en la primera posición de la lista
    actual= *Lista;
    if(actual) while(actual ->anterior) actual = actual->anterior;
    //si la lista está vacía

    if(!actual || strcmp(actual->nombre, nom)== 1){
        //añadimos la lista a continuación del nuevo nodo
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        if(actual) actual->anterior = nuevo;
        if(!*Lista) *Lista = nuevo;


    }

    else{
            while(actual->siguiente && strcmp(actual->siguiente->nombre, nom)== -1) actual = actual->siguiente;

                nuevo->siguiente = actual->siguiente;
                actual->siguiente = nuevo;
                nuevo->anterior = actual;
                if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;

    }

}

void MostrarLista_trabajador(Lista *Lista){
    pNodo nodo = *Lista;
    int i = 0;

    if(!nodo){ printf("Lista Vacia"); return;}

    nodo = *Lista;

        while(nodo->anterior) nodo= nodo->anterior;
        printf("Lista: ");
        while(nodo){
            cout<<nodo->nombre<<" "<<nodo->apellido<<"-> ";
            nodo = nodo->siguiente;
            i++;
        }

    cout<<"\n El numero de trabajadores en la empresa es de "<<i<<"\n";
}

void eliminar_trabajador(Lista *Lista, char const *nom, char const *apell){

    pNodo nodo;

    //Revisamos que la lista no esté vacía
    nodo = *Lista;
   if(!nodo) cout<< "La lista esta vacia, por lo tanto el trabajador buscado no se encuentra dentro de ella";

   //Ubicamos nodo al principio de la lista
    else{
        while(nodo->anterior) nodo = nodo->anterior;

        while(nodo){
            if(strcmp(nodo->nombre, nom)==0 && strcmp(nodo->apellido, apell)==0){
            //Borrando el nodo
            //Si lista apunta al nodo que queremos
            if(nodo == *Lista)
                if(nodo->anterior)*Lista = nodo->anterior;
                else *Lista = nodo->siguiente;

            if(nodo->anterior)//no es el primer elemento
            nodo->anterior->siguiente = nodo->siguiente;

            if(nodo->siguiente)//No es el último
            nodo->siguiente->anterior = nodo->anterior;

            free(nodo);
            return;
            }
            else nodo = nodo->siguiente;

            }
    }
}

void Buscar_trabajador(Lista *Lista, char const *nom, char const *apell){

    pNodo nodo;

    //Revisamos que la lista no esté vacía
    nodo = *Lista;
   if(!nodo) cout<< "La lista está vacia, por lo tanto la empresa buscada no se encuentra dentro de ella";


    else{
        //Ubicamos nodo al principio de la lista
        while(nodo->anterior) nodo = nodo->anterior;

        while(nodo){
            if(strcmp(nodo->nombre, nom)==0 && strcmp(nodo->apellido, apell)==0){
                cout<<"\nNombre del trabajador: "<<nodo->nombre;
                cout<<"\nApellido del trabajador: "<<nodo->apellido;
                cout<<"\nDireccion del trabajador: "<<nodo->direccion;
                cout<<"\ntelefono del trabajador: "<<nodo->telefono;
            }

            else nodo = nodo->siguiente;
        }

    }

}

void eliminar_tra_repe(Lista *Lista){
  pNodo nodo;
    nodo = *Lista;
    if(!nodo) cout<< "La lista esta vacia";

    else{
            //lo llevo al inicio de la lista
        while(nodo->anterior) nodo = nodo->anterior;

        while(nodo->siguiente){
            if(strcmp(nodo->nombre, nodo->siguiente->nombre)==0 && strcmp(nodo->apellido, nodo->siguiente->apellido)==0)
            {
            //Borrando el nodo
            //Si lista apunta al nodo que queremos
            if(nodo == *Lista)
                if(nodo->anterior)*Lista = nodo->anterior;
                else *Lista = nodo->siguiente;

            if(nodo->anterior)//no es el primer elemento
            nodo->anterior->siguiente = nodo->siguiente;

            if(nodo->siguiente)//No es el último
            nodo->siguiente->anterior = nodo->anterior;

            free(nodo);
            }

            else nodo= nodo->siguiente;

            }

    }
}



void Buscar_empresa(Lista *Lista, char const *nom){

    pNodo nodo;

    //Revisamos que la lista no esté vacía
    nodo = *Lista;
   if(!nodo) cout<< "La lista está vacia, por lo tanto la empresa buscada no se encuentra dentro de ella";


    else{
        //Ubicamos nodo al principio de la lista
        while(nodo->anterior) nodo = nodo->anterior;

        while(nodo){
            if(strcmp(nodo->nombre, nom)==0){
                cout<<"\nNombre de la empresa: "<<nodo->nombre;
                cout<<"\nDireccion de la empresa: "<<nodo->direccion;
                cout<<"\ntelefono de la empresa: "<<nodo->telefono;

            char nomTra[20] , apellTra[20] , tlfTra[20] ;
            char dirTra[20] ;
            int op;

            do{
                menu_trabajadores(); cin>>op;

                switch(op)
                {
                case 1: cout<<"\n Nombre del trabajador: "; cin>>nomTra;
                        cout<<"\nApellido del trabajador: ";cin>>apellTra;
                        cout<<"\n direccion del trabajador: "; cin>>dirTra;
                        cout<<"\n telefono del trabajador: "; cin>>tlfTra;
                        insertar_trabajador(&nodo->Lista_trabajador, nomTra, tlfTra, dirTra, apellTra);
                        cout<<"\n\n Los datos de "<<nom <<" se han adjuntado a la lista...\n\n";
                        break;

                        case 2:cout<<"\n Nombre del trabajador que desea eliminar: "; cin>>nomTra;
                               cout<<"\n Nombre del trabajador que desea eliminar: "; cin>>apellTra;
                        eliminar_trabajador(&nodo->Lista_trabajador, nomTra, apellTra);

                        break;

                        case 3:
                        MostrarLista_trabajador(&nodo->Lista_trabajador);
                        break;

                        case 4:
                            eliminar_tra_repe(&nodo->Lista_trabajador);
                        break;

                        case 5:cout<<"\n Nombre del trabajador que desea buscar: "; cin>>nomTra;
                               cout<<"\n Apellido del trabajador que desea buscar: "; cin>>apellTra;
                                Buscar_trabajador(&nodo->Lista_trabajador, nomTra, apellTra);
                        break;

                        case 6: cout<< "\n\n volviendo al menú principal... \n\n";
                        break;

                        default: cout<< "\n\n opcion invalida intente nuevamente \n\n";
                        }

                        cout<<"\n\nPresione una tecla para continuar\n\n";
                        getch();

                }while(op != 6);
              return;
            }

            else nodo = nodo->siguiente;

            }
    }
}

void menu()
{
     cout<<"\n1- Ingresar empresa a la lista";
     cout<<"\n2- Eliminar empresa";
     cout<<"\n3- Mostrar empresas";
     cout<<"\n4- eliminar empresas repetidas";
     cout<<"\n5- Buscar una empresa determinada";
     cout<<"\n6- Salir";

     cout<<"\n\n ingrese opcion: ";
}

int main(){
Lista Lista = NULL;
pNodo p;

int op;
char nom[20] , apell[20] , tlf[20] , dir[20] ;

 do{
        menu(); cin>>op;

     switch(op)
     {
    case 1: cout<<"\n Nombre de la empresa: "; cin>>nom;
            cout<<"\n direccion de la empresa: "; cin>>dir;
            cout<<"\n telefono de la empresa: "; cin>>tlf;
            insertar(&Lista, nom, tlf, dir);
            cout<<"\n\n Los datos de "<<nom <<" se han adjuntado a la lista...\n\n";
    break;

    case 2:cout<<"\n Nombre de la empresa que desea eliminar: "; cin>>nom;
            eliminar_empresa(&Lista, nom);

    break;

    case 3:
            MostrarLista(&Lista);
    break;

    case 4:
            eliminar_emp_repe(&Lista);
    break;

    case 5:cout<<"\n Nombre de la empresa que desea buscar: "; cin>>nom;
           Buscar_empresa(&Lista, nom);
    break;

    case 6: cout<< "\n\n Saliendo del programa... \n\n";
    break;

    default: cout<< "\n\n opcion invalida intente nuevamente \n\n";
     }

     cout<<"\n\nPresione una tecla para continuar\n\n";
    getch();

   }while(op != 6);

return 0;
}
