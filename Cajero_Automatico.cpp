/*---------------------------------------------------
|   Código escrito por Uriel Lara Castro             |
|   Para la materia Algoritmo y Estructura de datos  |                           |
|   Fecha de entrega: 22 de Octubre 2023             |
-----------------------------------------------------*/

#include <iostream>
#include <windows.h>

using namespace std;


//***DECLARACIÓN DE FUNCIONES***
short ModoOperador();    //Opciones para el técnico/operador del cajero
void ValidarRetirarEfectivo();  //Validar que el usuario ingresa bien la cantidad
void CalcularBilletes(int); //Algoritmo para seleccionar billetes
    //Mensajes informativos
void ImprimirBilletes(int, int, int, int, int);
void MensajeCajeroDeshabilitado();
void ConteoBilletes(); //saber cuántos billetes hay en el cajero y cuantos se han entregado


//***DECLARACIÓN DE VARIABLES***
//Constantes
#define CantBilletes 50 //Cantidad de billetes de cada denominación
#define retiroMaximo 5000 //Retiro de efectivo máximo por día
//Variables globales
bool cajeroHabilitado=true, apagarCajero=false; //Deshabilitado si no tiene dinero. 
                                                //ApagarCajero = Terminar programa
int dineroTotal=0, //Suma de todos los billetes del cajero
    cB50=CantBilletes, cB100=CantBilletes, cB200=CantBilletes, cB500=CantBilletes, cBmil=CantBilletes; //cantidad de Billetes
int b[5]={cB50, cB100, cB200, cB500, cBmil}; //vector de cantidades de billetes


int main(){

    //Para escribir con acentos (Windows.h)
    SetConsoleCP(CP_UTF8);          
    SetConsoleOutputCP(CP_UTF8); 



    //Calcular dinero total
   dineroTotal=CantBilletes*(50+100+200+500+1000);

    if(cajeroHabilitado==false)
        MensajeCajeroDeshabilitado();

    while(apagarCajero==false) {

        short opcion=50;
        while(opcion==50){
            printf("\nMENU:\n1.Retiro de efectivo\n2.Cancelar\n");
            cout <<  "Escribe el numero de tu eleccion: ";
            cin >> opcion;

            switch (opcion){
             case 1: 
                ValidarRetirarEfectivo();
                opcion=2;
            break;

            case 1234: 
                //El operador/técnico del cajero tendra un numero clave para entrar a esta opcion
                opcion = ModoOperador();
                break;
            case 2:
                cout << "\n\tGracias por su preferencia";
            }
        }
            //MODO DE ESPERA. Para evitar que se termine el programa, simula que varios "clientes" puedan retirar dinero. 
        char caracter;
    cout<<"\n\n\tModo espera...\n\nPresione un numero para usar el cajero.\n"
            <<"->Si desea terminar el programa presione 'x'.\n\tOpcion: ";
        cin>>caracter;

        if (caracter=='x')
            {apagarCajero=true;
            cout <<"***FIN.***";}
        else
            {apagarCajero=false;}

    }

    return 0;
}

//***FUNCIONES***//
short ModoOperador()
{
    short opcion;

    cout<<"\nBienvenido al Modo Operador.\n\tPresione:\n\t1. Rellenar el cajero\n\t2. "<<
            "Verificar la cantidad de billetes en el cajero\n\t3. Regresar al menu principal\n\t"<<
            "4. Cancelar\n\tOpcion: ";
    cin>>opcion;

    switch(opcion){
        case 1: cB50=CantBilletes; cB100=CantBilletes; cB200=CantBilletes; cB500=CantBilletes; cBmil=CantBilletes;
                dineroTotal=(50+100+200+500+1000)*CantBilletes;
                cajeroHabilitado=true;

                cout<<"\n Cambios guardados. \n Se han asignado "<<CantBilletes<<" billetes a cada denominacion\n\t"<<
                "Dinero en cajero: $"<<dineroTotal<<"\n";
        break;
        case 2: 
                ConteoBilletes();
        break;
        case 3: 
                return 5;
        break;
    }
    cout << "\n\tSesion cerrada.\n";
    system("pause");
}


void ValidarRetirarEfectivo()
{
        int dineroRetiro,validarCantidad, compararDinero, intentos=1;
        bool retirarDinero=false;

        if(dineroTotal<=0){
            cajeroHabilitado=false;
            MensajeCajeroDeshabilitado();
        }

    while(cajeroHabilitado==true && retirarDinero==false && intentos<=3){
        cout << "\nIngrese la cantidad que desea retirar: $";
        cin >> dineroRetiro;

        //Validar que la cantidad de dinero ingresada por el cliente sea correcta
        validarCantidad=dineroRetiro%50;

        if (dineroRetiro>retiroMaximo){
            cout << "La cantidad maxima a retirar es de $5,000."<<"\n";
            intentos=intentos+1;
        }
        else if(validarCantidad!=0){
            cout<<"El dinero a retirar solo puede ser multiplos de 50 y 100.\n"<<
            "Y maximo $5,000 por dia\n";
            intentos=intentos+1;
        }
        else{
            //Validar que el cajero tenga suficiente dinero
            compararDinero = dineroTotal-dineroRetiro;
                if (compararDinero >= 0){
                    retirarDinero=true;
                }   
                else{
                        cout << "\nCajero sin fondos suficientes.\n";
                }
        }
    }

if(intentos>=3){
        cout << "\n\tDemasiados intentos erroneos.\n";
    }

if(retirarDinero==true){
    CalcularBilletes(dineroRetiro);
    }
}


void CalcularBilletes(int dineroRetiro){
    /*Esta función calcula los billetes que se le entregarán al cliente, 
    y busca repartirlos equitativamente para evitar que se acaben todos los de una misma
    denominación. */
    int bValor[5]={50, 100, 200, 500, 1000};
    int billsEntregar[5]={0}, restante;

restante=dineroRetiro;

while(restante>=0){

        if(restante>=1000 && cBmil>0){
            if(cBmil>=cB500){
                cBmil=cBmil-1;
                billsEntregar[4]=billsEntregar[4]+1;
                restante=restante-1000;
            }
            else{
                cB500=cB500-1;
                billsEntregar[3]=billsEntregar[3]+1;
                restante=restante-500;
            }
        
        }
        if(restante>=500 && cB500>0){
            if(cB500>=cB200){
                cB500=cB500-1;
                billsEntregar[3]=billsEntregar[3]+1;
                restante=restante-500;
            }
            else{
                cB200=cB200-1;
                billsEntregar[2]=billsEntregar[2]+1;
                restante=restante-200;
            }
        }
        if(restante>=200 && cB200>0){
            if(cB200>=cB100){
                cB200=cB200-1;
                billsEntregar[2]=billsEntregar[2]+1;
                restante=restante-200;
            }
            else{
                cB100=cB100-1;
                billsEntregar[1]=billsEntregar[1]+1;
                restante=restante-100;
            }
        }
        if(restante>=100 && cB100>0){
            if(cB100>=cB50){
                cB100=cB100-1;
                billsEntregar[1]=billsEntregar[1]+1;
                restante=restante-100;
            }
            else{
                    cB50=cB50-1;
                    billsEntregar[0]=billsEntregar[0]+1;
                restante=restante-50;
            }
        }
        if(restante>=50 && cB50>0){
                cB50=cB50-1;
                restante=restante-50;
                billsEntregar[0]=billsEntregar[0]+1;
        }
        else{
            restante=-1;
        }  
    }

ImprimirBilletes(billsEntregar[4],billsEntregar[3],billsEntregar[2], billsEntregar[1], billsEntregar[0]);
}


//MENSAJES 
void ImprimirBilletes(int a, int b, int c, int d, int e){
    cout<<"Entregar al cliente:\n"<<
    a<<" billetes de $1,000\n"<<
    b<<" billetes de $500\n"<<
    c<<" billetes de $200\n"<<
    d<<" billetes de $100\n"<<
    e<<" billetes de $50\n";

    int efectivoRetirado=a*1000+b*500+c*200+d*100+e*50; 
    cout<<"\nEfectivo retirado: $"<<efectivoRetirado;

    dineroTotal=dineroTotal-efectivoRetirado;

    if(dineroTotal<=10000){
        cout<<"\n\t***MENSAJE PARA SUCURSAL:***\n\tADVERTENCIA, RELLENAR CAJERO\n";
        cout<<"Dinero en cajero: $"<<dineroTotal;
    }

}


void MensajeCajeroDeshabilitado(){
    //Mensaje cuando el cajero no tiene el efectivo necesario
    cout << "\n\tCajero fuera de servicio.\n\tDisculpe las molestias.";
}


void ConteoBilletes(){

    cout<<"\n\t*Billetes Entregados:\n"<<
    CantBilletes-cBmil<<" billetes de $1,000\n"<<
    CantBilletes-cB500<<" billetes de $500\n"<<
    CantBilletes-cB200<<" billetes de $200\n"<<
    CantBilletes-cB100<<" billetes de $100\n"<<
    CantBilletes-cB50<<" billetes de $50\n";

    cout<<"\n\t*Billetes Restantes:\n"<<
    cBmil<<" billetes de $1,000\n"<<
    cB500<<" billetes de $500\n"<<
    cB200<<" billetes de $200\n"<<
    cB100<<" billetes de $100\n"<<
    cB50<<" billetes de $50\n";

    cout<<"\nDinero en cajero: $"<<dineroTotal;

    cout<<"\nEl numero minimo de personas que pueden retirar son: "<<dineroTotal/retiroMaximo <<
    " y máximo: "<<dineroTotal/50<<"\n";
}