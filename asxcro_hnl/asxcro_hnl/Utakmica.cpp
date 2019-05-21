#include "pch.h"
#include "Utakmica.h"

Utakmica::Utakmica(Klub* k1, Klub* k2, int gd, int gg)
{
	m_oKlubDomacina = k1;
	m_oKlubGosta = k2;
	m_nGoloviDomacina = gd;
	m_nGoloviGosta = gg;
}


Utakmica::~Utakmica()
{

}


