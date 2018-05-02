#include <iostream>
#include <list>

using namespace std;

struct subProceso{
    double tiempoSuperComputador;
    double tiempoPc;
};

int main(int argc, char * argv[])
{

    list<subProceso> subprocesos;
    list<subProceso> lista_ejecucion;
    double tiempoMayor = 0;
    list<subProceso>::iterator it_mayor;

    while(!subprocesos.empty()){
        for(list<subProceso>::iterator it = subprocesos.begin(); it != subprocesos.end(); ++it ){
            if(it->tiempoSuperComputador > tiempoMayor){
                tiempoMayor = it->tiempoSuperComputador;
                it_mayor = it;
            }
        }
        lista_ejecucion.push_back(*it_mayor);
        subprocesos.erase(it_mayor);
    }

    return 0;
}
 
