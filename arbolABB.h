//crear estructura de un arbol binario de busqueda

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodo{
    int dato;
    nodo *izq;
    nodo *der;
};

typedef nodo *arbolABB;

//crear funcion insertar

void insertarAbb(arbolABB &abb, int x){
    if(abb==NULL){
        nodo *nuevo=new nodo();
        nuevo->dato=x;
        nuevo->izq=NULL;
        nuevo->der=NULL;
        abb=nuevo;
    }else{
        if(x<abb->dato){
            insertarAbb(abb->izq,x);
        }else{
            insertarAbb(abb->der,x);
        }
    }
}

//crear funcion eliminar y me idique cuando se elimine el dato en un comentario

void eliminarAbb(arbolABB &abb, int x){
    if(abb==NULL){
        cout<<"el dato no existe"<<endl;
    }else{
        if(x<abb->dato){
            eliminarAbb(abb->izq,x);
        }else if(x>abb->dato){
            eliminarAbb(abb->der,x);
        }else{
            nodo *aux=abb;
            if(aux->der==NULL){
                abb=aux->izq;
            }else if(aux->izq==NULL){
                abb=aux->der;
            }else{
                nodo *aux2=aux->izq;
                nodo *padre=NULL;
                while(aux2->der!=NULL){
                    padre=aux2;
                    aux2=aux2->der;
                }
                abb->dato=aux2->dato;
                aux=aux2;
                if(padre!=NULL){
                    padre->der=aux->izq;
                }else{
                    abb->izq=aux->izq;
                }
            }
            delete aux;
            cout<<"el dato se elimino"<<endl;
        }
    }
}


//crear funcion buscar un dato y me idiique si existe o no mediante un comentario

void buscarAbb(arbolABB abb, int x){
    if(abb==NULL){
        cout<<"el dato no existe"<<endl;
    }else{
        if(x<abb->dato){
            buscarAbb(abb->izq,x);
        }else if(x>abb->dato){
            buscarAbb(abb->der,x);
        }else{
            cout<<"el dato existe"<<endl;
        }
    }
}

//crear funcion mostrar

void mostrarAbb(arbolABB abb, int cont){
    if(abb==NULL){
        return;
    }else{
        mostrarAbb(abb->der,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"   ";
        }
        cout<<abb->dato<<endl;
        mostrarAbb(abb->izq,cont+1);
    }
}

//crear funcion que recorra el arbol en-orden

void recorrerEnOrden(arbolABB abb){
    if(abb==NULL){
        return;
    }else{
        recorrerEnOrden(abb->izq);
        cout<<abb->dato<<" ";
        recorrerEnOrden(abb->der);
    }
}

//crear funcion que recorra el arbol en-preorden

void recorrerPreOrden(arbolABB abb){
    if(abb==NULL){
        return;
    }else{
        cout<<abb->dato<<" ";
        recorrerPreOrden(abb->izq);
        recorrerPreOrden(abb->der);
    }
}

//crear funcion que recorra el arbol post-orden

void recorrerPostOrden(arbolABB abb){
    if(abb==NULL){
        return;
    }else{
        recorrerPostOrden(abb->izq);
        recorrerPostOrden(abb->der);
        cout<<abb->dato<<" ";
    }
}

//crear funcion que calcule el peso del arbol 

int pesoArbol(arbolABB abb){
    if(abb==NULL){
        return 0;
    }else{
        int izq=pesoArbol(abb->izq);
        int der=pesoArbol(abb->der);
        return izq+der+1;
    }
}

//crear funcion que calcule la altura del arbol

int alturaArbol(arbolABB abb){
    if(abb==NULL){
        return 0;
    }else{
        int izq=alturaArbol(abb->izq);
        int der=alturaArbol(abb->der);
        if(izq>der){
            return izq+1;
        }else{
            return der+1;
        }
    }
}

//crear funcion que calcule cuantas hojas tiene el arbol

int hojasArbol(arbolABB abb){
    if(abb==NULL){
        return 0;
    }else{
        if(abb->izq==NULL && abb->der==NULL){
            return 1;
        }else{
            int izq=hojasArbol(abb->izq);
            int der=hojasArbol(abb->der);
            return izq+der;
        }
    }
}

//funcion que me retorne el padre de un nodo dado sin importar en el nivel que se encuentre

int NodoPadre(arbolABB arbol, int valor) {
    if (arbol == NULL || arbol->dato == valor) {
        return 0; // No se encontró el padre o se encontró el nodo raíz
    } else if ((arbol->izq != NULL && arbol->izq->dato == valor) ||
               (arbol->der != NULL && arbol->der->dato == valor)) {
        return arbol->dato; // Se encontró el padre del nodo actual
    } else if (valor < arbol->dato) {
        return NodoPadre(arbol->izq, valor); // Buscar en el subárbol izquierdo
    } else {
        return NodoPadre(arbol->der, valor); // Buscar en el subárbol derecho
        }
    }

//funcion que me diga que nivel es el arbol 

int nivelArbol(arbolABB abb, int x){
    if(abb==NULL){
        return 0;
    }else{
        int nivel=0;
        nodo *aux=abb;
        while(aux!=NULL){
            if(x==aux->dato){
                return nivel;
            }else{
                nivel++;
                if(x<aux->dato){
                    aux=aux->izq;
                }else{
                    aux=aux->der;
                }
            }
        }
        return -1;
    }
}




