#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
class Barco
{
//Atributos
private: 
	int Speed;
	int Distance;
	string Name;
	int Turbo;
	char trb;

//Metodos
public:

	int finalDistance();
	int Dado();
	bool TURBO();
	void turno();
	void turnoRaival();
	void drawDistance();


	Barco(int SPD, int DST, string NME, int TRB);
};

