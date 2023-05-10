//crear funcion menuprinciapal y llamdarlo desde el main
//1.arbol abb
//2.arbol avl
//3.arbol rojonegro
//4.salir

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include "arbolABB.h"
#include "arbolAVL.h"
#include "arbolRN.h"

using namespace std;

void submenuArbolAbb();
void submenuArbolAvl();
void submenuArbolRojonegro();


int main()
{
    
    int opcion;
    do{
        cout<<"1. arbol abb"<<endl;
        cout<<"2. arbol avl"<<endl;
        cout<<"3. arbol rojonegro"<<endl;
        cout<<"4. salir"<<endl;
        cout<<"ingrese una opcion: ";
        cin>>opcion;
        cout<<endl;
        switch(opcion){
            case 1:
                cout<<"arbol abb"<<endl;
                submenuArbolAbb();
                cout<<endl;
                break;
            case 2:
                cout<<"arbol avl"<<endl;
                submenuArbolAvl();
                cout<<endl;
                break;
            case 3:
                cout<<"arbol rojonegro"<<endl;
                submenuArbolRojonegro();
                cout<<endl;
                break;
            case 4:
                cout<<"salir"<<endl;
                break;
            default:
                cout<<"opcion no valida"<<endl;
                break;
        }
        system("pause");
        system("cls");
    }while(opcion!=4);
    
    return 0;
}

//crear funcion submenuArbolAbb
//1. insertar
//2. eliminar
//3. buscar
//4. mostrar
//5. recoorer el arbol en-orden
//6. recoorer el arbol pre-orden
//7. recoorer el arbol post-orden
//8. calcular peso del arbol
//9. calcular altura del arbol
//10. contar hojas
//11. padre de un nodo
//12. regresar al menu principal

void submenuArbolAbb(){
    int opcion;
    int dato,altura,peso,hojas,nivel,padre;
    arbolABB arbol1=NULL;
    do{
        cout<<"1. insertar"<<endl;
        cout<<"2. eliminar"<<endl;
        cout<<"3. buscar"<<endl;
        cout<<"4. mostrar"<<endl;
        cout<<"5. recoorer el arbol en-orden"<<endl;
        cout<<"6. recoorer el arbol pre-orden"<<endl;
        cout<<"7. recoorer el arbol post-orden"<<endl;
        cout<<"8. calcular peso del arbol"<<endl;
        cout<<"9. calcular altura del arbol"<<endl;
        cout<<"10. contar hojas"<<endl;
        cout<<"11. padre de un nodo"<<endl;
        cout<<"12. nivel del arbol"<<endl;
        cout<<"13. regresar al menu principal"<<endl;
        cout<<"ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"insertar un dato"<<endl;
                cin>>dato;
                insertarAbb(arbol1,dato);
                cout<<endl;
                break;
            case 2:
                cout<<"ingrese el dato que desea eliminar"<<endl;
                cin>>dato;
                eliminarAbb(arbol1,dato);
                cout<<endl;
                break;
            case 3:
                cout<<"ingrese el dato a buscar"<<endl;
                cin>>dato;
                buscarAbb(arbol1,dato);
                cout<<endl;
                break;
            case 4:
                cout<<"mostrar"<<endl;
                mostrarAbb(arbol1,0);
                cout<<endl;
                break;
            case 5:
                cout<<"recoorer el arbol en-orden"<<endl;
                recorrerEnOrden(arbol1);
                cout<<endl;
                break;
            case 6:
                cout<<"recoorer el arbol pre-orden"<<endl;
                recorrerPreOrden(arbol1);
                cout<<endl;
                break;
            case 7:
                cout<<"recoorer el arbol post-orden"<<endl;
                recorrerPostOrden(arbol1);
                cout<<endl;
                break;
            case 8:
                cout<<"calcular peso del arbol"<<endl;
                peso=pesoArbol(arbol1);
                cout<<"el peso del arbol es: "<<peso<<endl;
                cout<<endl;
                break;
            case 9:
                cout<<"calcular altura del arbol"<<endl;
                altura=alturaArbol(arbol1);
                cout<<"la altura del arbol es: "<<altura<<endl;
                cout<<endl;
                break;
            case 10:
                cout<<"contar hojas"<<endl;
                hojas=hojasArbol(arbol1);
                cout<<"el numero de hojas del arbol es: "<<hojas<<endl;
                cout<<endl;

                break;
            case 11:
                cout<<"ingrese un dato"<<endl;
                cin>>dato;
                padre=NodoPadre(arbol1,dato);
                cout<<"el padre del nodo es: "<<padre<<endl;
                break;
            case 12:
                cout<<"ingrese un dato"<<endl;
                cin>>dato;
                nivel=nivelArbol(arbol1,dato);
                cout<<"el nivel del arbol es: "<<nivel<<endl;
                break;
            case 13:
                cout<<"regresar al menu principal"<<endl;
                break;
            default:
                cout<<"opcion no valida"<<endl;
                break;
        }
        system("pause");
        system("cls");

    }while(opcion!=13);
}

//crear funcion submenuArbolAvl
//1. insertar
//2. eliminar
//3. buscar
//4. mostrar
//5. regresar al menu principal

void submenuArbolAvl(){
    AVL arbol2=NULL;
    int dato;
    int opcion;
    do{
        cout<<"1. insertar"<<endl;
        cout<<"2. eliminar"<<endl;
        cout<<"3. buscar"<<endl;
        cout<<"4. mostrar"<<endl;
        cout<<"5. regresar al menu principal"<<endl;
        cout<<"ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"ingrese un dato: ";
                cin>>dato;
                insertarAVL(arbol2, dato);
                break;
            case 2:
                cout<<"eliminar"<<endl;
                cout<<"ingrese un dato: ";
                cin>>dato;
                eliminarNodoAVL(arbol2, dato);
                break;
            case 3:
                cout<<"buscar"<<endl;
                cout<<"ingrese un dato: ";
                cin>>dato;
                buscarAVL(arbol2, dato);
                break;
            case 4:
                cout<<"mostrar"<<endl;
                verArbolAVL(arbol2, 0);
                break;
            case 5:
                cout<<"regresar al menu principal"<<endl;
                break;
            default:
                cout<<"opcion no valida"<<endl;
                break;
        }
        system("pause");
        system("cls");
        
    }while(opcion!=5);
}

//crear funcion submenuArbolRojonegro
//1. insertar
//2. eliminar
//3. buscar
//4. mostrar
//5. regresar al menu principal

void submenuArbolRojonegro(){
    RBT arbol3=NULL;
    int dato;
    int opcion;
    do{
        cout<<"1. insertar"<<endl;
        cout<<"2. eliminar"<<endl;
        cout<<"3. buscar"<<endl;
        cout<<"4. mostrar"<<endl;
        cout<<"5. regresar al menu principal"<<endl;
        cout<<"ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"insertar"<<endl;
                cout<<"ingrese un dato: ";
                cin>>dato;
                insertarRN(arbol3, dato);
                cout<<endl; 
                break;
            case 2:
                cout<<"eliminar"<<endl;
                cout<<"ingrese un dato: ";
                cin>>dato;
                eliminar_rbt(arbol3, dato);
                cout<<endl;
                break;
            case 3:
                cout<<"buscar"<<endl;
                cout<<"ingrese un dato: ";
                cin>>dato;
                buscarRN(arbol3, dato);
                cout<<endl;
                break;
            case 4:
                cout<<"mostrar"<<endl;
                verArbolRN(arbol3, 0);
                cout<<endl;

                break;
            case 5:
                cout<<"regresar al menu principal"<<endl;
                break;
            default:
                cout<<"opcion no valida"<<endl;
                break;
        }
        system("pause");    
        system("cls");  
    }while(opcion!=5);
}

