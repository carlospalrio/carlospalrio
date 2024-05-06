#include <iostream>
#include "Enemigo.h"

using namespace std;
string name;
string raival;
string ganador;
int turno = 1;
int tamano;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void medidor() {
    cout << "             _______________________________________________________________________________________________\n";
    cout << "             |          |           |           |           |           |           |           |          |\n";
    cout << "             0        1000        2000        3000        4000        5000        6000        7000       8000";
    cout << "\n";
}


int main()
{   
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Bienvenido a la carrera de barcos.\n"; Sleep(500);
    while (raival == name){
    cout << "Escribe el nombre de tu barco: "; cin >> name; Sleep(500);
    cout << "Ahora, escribe el nombre de tu rival(debe ser diferente): "; cin >> raival;
    }
    Sleep(500);
    cout << "Perfecto, que empieza la carrera entre " << name << " y " << raival << "!!\n";
    Barco competidor = Barco(0, 0, name, 1);
    Barco rival = Barco(0, 0, raival, 1);
    Sleep(1000);
    srand(time(NULL));
    
  
    while (turno < 6) {
        system("CLS"); cout << "\n";
        for (int i = 0; i < 56; i++) {
            cout << " ";
        }
        cout << "TURNO " << turno << "\n"; Sleep(500);
        competidor.turno(); Sleep(500);
        rival.turnoRaival(); 
        turno++; 
        tamano = (120 - (name.length() + raival.length() + 5))/2;
        for (int i = 0; i < tamano; i++) {
            cout << " ";
        }
        SetConsoleTextAttribute(hConsole, 1); cout << name << "     "; SetConsoleTextAttribute(hConsole, 4); cout << raival;
        cout << "\n"; SetConsoleTextAttribute(hConsole, 1); competidor.drawDistance();
        SetConsoleTextAttribute(hConsole, 4); rival.drawDistance();
        SetConsoleTextAttribute(hConsole, 6);
        medidor(); 
        Sleep(1500);
    }
    Sleep(500);
    int distcomp = competidor.finalDistance();
    int distrai = rival.finalDistance();
    if (distrai < distcomp) {   
        ganador = name;
        cout << "El ganador es " << ganador;
    }
    else if (distrai == distcomp) {
        cout << "Inpensablemente, el resultado es un empate\n";
    }
    else {
        ganador = raival;
        cout << "El ganador es " << ganador;
    }
}