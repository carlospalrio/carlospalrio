#include "Enemigo.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

int Barco::Dado() {
	return 1 + rand() % 6;
}
bool Barco::TURBO() {
	return rand() % 2;
}
void Barco::turno() {
	cout << "Es tu turno, presiona enter para lanzar los dados!"; 
	cin.get(); cin.get();
	int dado = Dado(); Sleep(500);
	cout << "Te ha salido el numero " << dado << "\n";
	Speed = Speed + dado; Sleep(500);
	cout << "Tu velocidad es de " << Speed << "km/h\n"; Sleep(500);
	if (Turbo == 1) {
		cout << "Deseas usar el turbo (S/N)?\n"; cin >> trb; Sleep(500);
		trb = toupper(trb);
		if (trb == 'S') {
			if (TURBO() == 1) {
				cout << "El turbo a sido un exito, duplicas la velocidad\n";
				Speed = Speed * 2; 
			}
			else {
				cout << "El turbo a sido un fracaso, tu velocidad se reduce a la mitad\n";
				Speed = Speed / 2;
			}
			Turbo--;
		}
		else {
			cout << "No usas el turbo\n";
		}
	}
	else if (Turbo == 0) {
		cout << "Ya no puedes usar el turbo!!\n";
	}
	Distance = Distance + (Speed * 100); Sleep(500);

}
void Barco::turnoRaival() {
	cout << "Es el turno de " <<  Name << "!\n"; Sleep(500);
	int dado = Dado();
	cout << "Le ha salido el numero " << dado << "\n"; Sleep(500);
	Speed = Speed + dado;
	cout << "Su velocidad es de " << Speed << "km/h\n"; Sleep(500);
	if (Turbo == 1) {
		
		if (Speed >= 10) {
			if (TURBO() == 1) {
				Sleep(500);
				cout << Name << "ha ejecutado con exito el turbo\n";
				Speed = Speed * 2;
			}
			else {
				Sleep(500);
				cout << Name << "ha fallado el turbo\n";
				Speed = Speed / 2;
			}
			Turbo--;
		}
		else {
			Sleep(500);
			cout << Name << " no usa el turbo\n";
		}
	}
	else if (Turbo == 0) {
		Sleep(500);
		cout << Name << "ya no puede usar el turbo!!\n";
	}
	Distance = Distance + (Speed * 100); Sleep(500);
	cout << "Su distancia actual es de " << Distance << "m\n";
}
int Barco::finalDistance() {
	Sleep(500);
	cout << "El jugador " << Name << " ha acabado la partida con una distancia de " << Distance << "m\n";
	return Distance;
}
void Barco::drawDistance() {
	int i = Distance / 500;
	cout << "\n";
	if (i >= 1 && i < 17) {
		cout << "             ";
		while (i > 0) {
			cout << ">>>>> ";
			i --;
		}
		cout << "\n";
	}
	i = 0;
	} 

Barco::Barco(int SPD, int DST, string NME, int TRB) {
	Name = NME;
	Speed = SPD;
	Distance = DST;
	Turbo = TRB;
}

