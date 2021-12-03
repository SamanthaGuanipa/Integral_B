#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <queue>
#include <list>
#include <stack>


using namespace std; 

class Arista; 

class Vertice
{
    Vertice *sig; 
    Arista *ady; 
    string nombre; 
    friend class Grafo; 

}; 

class Arista 
{
    Arista *sig; 
    Vertice *ady; 
    int peso; 
    friend class Grafo; 

};

class Grafo 
{
    Vertice *h;
    public: 
        void inicializa(); 
        bool vacio(); 
        int tamano(); 
        Vertice *getVertice(string nombre); 
        void calcularRuta(Vertice *origen, Vertice *destino); 
        void insertarArista(Vertice *origen, Vertice *destino, int peso); 
        void insertarVertice(string nombre); 
        void listaAdyacencia(); 
        

};

void Grafo :: inicializa(){
    h = NULL; 

}

bool Grafo :: vacio()
{
    if (h==NULL)
    {
        return true; 
    }
    return false; 
}

int Grafo :: tamano(){

    int cont = 0; 
    Vertice *aux; 
    aux = h; 

    while (aux != NULL){
        cont ++;
        aux = aux -> sig; 
    }

    return cont; 
}

//Esta funcion recorrerá el grafo, para saber si posee el parametro, si no existe regresara un NULL
Vertice *Grafo :: getVertice(string nombre){

    Vertice *aux; 
    aux = h; 
    while (aux != NULL)
    {
        if (aux -> nombre == nombre)
        {
            return aux; 
        }
        aux = aux -> sig; 
     
    }
    return NULL; 

}


void Grafo :: insertarVertice(string nombre)
{
    Vertice *nuevo = new Vertice; 
    nuevo -> nombre = nombre; 
    nuevo -> sig = NULL; 
    nuevo -> ady = NULL; 

    if (vacio())
    { 
        h = nuevo; 
    }
    else 
    {
        Vertice *aux; 
        aux = h; 
        while (aux -> sig != NULL)
        {
            aux = aux -> sig; 
        }
        aux -> sig = nuevo; 
    }

}

void Grafo :: insertarArista(Vertice *origen, Vertice *destino, int peso)
{
    Arista *nueva = new Arista; 
    nueva -> peso = peso; 
    nueva -> sig = NULL; 
    nueva -> ady = NULL; 

    Arista *aux; 
    aux = origen -> ady; 

    if(aux == NULL)
    {
        origen -> ady = nueva;
        nueva -> ady = destino; 
    }

    else 
    {
        while(aux -> sig != NULL)
        {
            aux = aux -> sig; 
        }
        aux -> sig = nueva; 
        nueva -> ady = destino; 
    }
}

void Grafo :: listaAdyacencia(){

    Vertice *vertAux; 
    Arista *arisAux; 

    vertAux = h; 
    while(vertAux != NULL)
    {
        cout<<vertAux->nombre<<"->"; 
        arisAux = vertAux -> ady; 
        while(arisAux != NULL)
        {
            cout<<arisAux->ady->nombre<<"->"; 
            arisAux = arisAux -> sig; 

        }
        vertAux = vertAux -> sig; 
        cout<<endl; 
    }




}

void Grafo :: calcularRuta(Vertice *origen, Vertice *destino)
{
    Vertice *verticeActual, *destinoActual; 
    Arista *aux; 
    int band, band2, band3 = 0; 
    typedef pair<Vertice*, Vertice*> VerticeVertice; 
    queue<Vertice*> cola; 
    stack<VerticeVertice> pila; 
    list<Vertice*> lista; 
    list<Vertice*> :: iterator i; 


    cola.push(origen); 
    while (!cola.empty())
    {
        band = 0; 
        verticeActual = cola.front(); 
        cola.pop(); 

        for (i = lista.begin(); i!=lista.end(); i++)
        {
            if(verticeActual == *i)
            {
                band = 1; 

            }
        }

        if(band==0)
        {
            if(verticeActual == destino)
            {
                band3=1; 
                destinoActual = destino; 
                while (!pila.empty())
                {
                    cout<<destinoActual -> nombre << "<-"; 

                    while(!pila.empty() && pila.top().second != destinoActual)
                    {
                        pila.pop(); 
                    }
                    if(!pila.empty())
                    {
                        destinoActual = pila.top().first; 
                    }

                }

            }
            lista.push_back(verticeActual); 

            aux = verticeActual -> ady; 
            while (aux != NULL)
            {
                for(i = lista.begin(); i!=lista.end(); i++)
                {
                    if(aux->ady == *i)
                    {
                        band2 = 1; 

                    }

                }
                if(band2 == 0)
                {
                    cola.push(aux->ady); 
                    pila.push(VerticeVertice(verticeActual, aux->ady )); 
                }
                aux = aux -> sig; 
            }


        }

    }
    if(band3==0)
    {
        cout<<"No existe una ruta entre esos dos vertices"<<endl; 

    }





}

#endif