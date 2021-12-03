#include <iostream>
#include "grafo.h"
#include "hash.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main(){

    HashTable<string, int> hash_obj(10, string("empty"), myHash);
    
    Grafo G;
    G.inicializa();
    int opc;

    G.insertarVertice("PE");
    G.insertarVertice("PA");
    G.insertarVertice("PV");
    G.insertarVertice("LC");
    G.insertarVertice("PM");
    G.insertarVertice("SC");
    G.insertarVertice("PN");
    G.insertarVertice("MP");
    G.insertarVertice("PL");
    G.insertarVertice("SR");

    G.insertarArista(G.getVertice("PE"), G.getVertice("PA"), 800);
    G.insertarArista(G.getVertice("PV"), G.getVertice("PE"), 400);
    G.insertarArista(G.getVertice("PV"), G.getVertice("LC"), 300);
    G.insertarArista(G.getVertice("PA"), G.getVertice("LC"), 700);
    G.insertarArista(G.getVertice("LC"), G.getVertice("SC"), 900);
    G.insertarArista(G.getVertice("LC"), G.getVertice("PN"), 400);
    G.insertarArista(G.getVertice("LC"), G.getVertice("MP"), 350);
    G.insertarArista(G.getVertice("PM"), G.getVertice("PV"), 500);
    G.insertarArista(G.getVertice("PM"), G.getVertice("PA"), 450);
    G.insertarArista(G.getVertice("PM"), G.getVertice("LC"), 250);
    G.insertarArista(G.getVertice("PM"), G.getVertice("MP"), 500);
    G.insertarArista(G.getVertice("SC"), G.getVertice("SR"), 1200);
    G.insertarArista(G.getVertice("PN"), G.getVertice("SR"), 450);
    G.insertarArista(G.getVertice("MP"), G.getVertice("SR"), 450);
    G.insertarArista(G.getVertice("MP"), G.getVertice("PL"), 650);
    G.insertarArista(G.getVertice("PL"), G.getVertice("PM"), 650);

    do
    {
        system("cls");
        cout<<"Bienvenido a Embarcaciones Guanipa, seleccione una opción: "<<endl<<
        "----------------------"<<endl;
        cout<<"1. Conocer puertos de salida y destino"<<endl;
        cout<<"2. Horas de salida"<<endl;
        cout<<"3. Lista de adyacencia"<<endl;
        cout<<"4. Calcular recorrido más corto"<<endl; 
        cout<<"5. Salir"<<endl; 
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;


        switch(opc)
        {
        case 1:
        {
            cout<<"Nuestros puertos de salida y destino aparecerán a continuación"<<endl<<
        "----------------------"<<endl;
            cout<<"Puerto de Ensenada [PE]"<<endl << 
            "Puerto de Altamira [PA]"<<endl<< 
            "Puerto de Veracruz[PV]"<<endl<<
            "Puerto Lazaro Cardenas [LC]"<<endl<<
            "Puerto Manzanillo[PM]"<<endl<<
            "Puerto San Carlos [SC]"<<endl<<
            "Puerto Nuevo [PN]"<<endl<<
            "Puerto Maritimo Pichilingue [MP]"<<endl<<
            "Puerto de Loreto [PL]"<<endl<<
            "Puerto de Santa Rosalia [SR]"<<endl;
            cout<<"---------------------"<<endl; 
            cout<<"Al ingresar su ruta, ingrese unicamente las iniciales descritas al lado del nombre del puerto."<<endl;  
            cout<<"---------------------"<<endl; 
            break; 
        }
        case 2:
        { 
            hash_obj.crear();  
            
            cout << "Lista de horarios de salida:"<< endl <<hash_obj.toString()<<endl; 
            
           
            break;
        }
        case 3:
        {
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                G.listaAdyacencia();
            }
            cin.get();
            cin.get();
            break;
        }
        

        case 4:
        {
            string origen, destino;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del puerto de origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del puerto de destino: ";
                getline(cin, destino, '\n');
                if(G.getVertice(origen) == NULL || G.getVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    G.calcularRuta(G.getVertice(origen), G.getVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        
        case 5:
        {
            break;
        }
        default:
        {
            cout<<"Elija una opcion valida"<<endl;
        }
        }
    }
    while(opc != 5);
    return 0;
}
