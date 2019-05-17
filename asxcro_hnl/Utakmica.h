#pragma once
#include "Klub.h"
class Utakmica
{
public:
	Utakmica(Klub* k1, Klub* k2, int gd, int gg); //klub domacin id
	~Utakmica();
	int m_nGoloviDomacina;
	int m_nGoloviGosta;
	Klub* m_oKlubDomacina;
	Klub* m_oKlubGosta;
};

