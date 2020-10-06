#include <iostream>
using namespace std;

struct date{
    int dia;
    int mes;
    int anio;
};

struct vox{
    string nombre;
    int expediente;
    date cumple;
    vox *sgt;
};

vox *peek = NULL;

void push(string n, int e, date c, vox *peek){
    vox *nvox =  new vox;
    nvox->nombre= n;
    nvox->expediente= e;
    nvox->cumple= c;

    nvox->sgt=peek;
    peek=nvox;
}

void pop(){
    if(peek==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
        peek=peek->sgt;
}

void prt(){
    vox *aux = peek;
    if(aux==NULL)
        cout<<"Nada que imprimir, Stack vacia\n";
    else
        while(aux!=NULL){
            cout<<"Nombre: "<<aux->nombre <<"\n";
            cout<<"Expediente: "<<aux->expediente <<"\n";
            cout<<"Cumpleaños-> "<<aux->cumple.dia <<"/"<<aux->cumple.mes <<"/"<<aux->cumple.anio <<"\n";
            aux=aux->sgt;
        }
}

int main(){

    int op, e;
    date c;
    string n;

    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija opcion: ",cin>>op;
        switch (op){
            case 1:
                cout<<"\n Ingresa su nombre : ",cin>>n;
                cout<<"\n Ingresa su numero de expediente : ",cin>>e;
                cout<<"\n Ingresa el dia de su cumple : ",cin>>c.dia;
                cout<<"\n Ingresa el mes de su cumple : ",cin>>c.mes;
                cout<<"\n Ingresa el anio de su cumple : ",cin>>c.anio;

                push(n, e, c, peek);
                break;
            case 2:
                cout<<"Eliminando ..... : ";
                pop();
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                prt();
                break;
            case 4:
                cout<<"------Bye--------";
        }
    }while(op!=4);
}
