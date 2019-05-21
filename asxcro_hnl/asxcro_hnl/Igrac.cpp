#include "pch.h"
#include "Igrac.h"


Igrac::Igrac(int s, string i, string p, int gr, int sk)
{
	m_nSifraIgraca = s;
	m_sImeIgraca = i;
	m_sPrezimeIgraca = p;
	m_nGodinaRodjenja = gr;
	m_nSifraKluba = sk;
}

Igrac::~Igrac()
{
}

int Igrac::DohvatiSifruIgraca() const
{
	return m_nSifraIgraca;
}

string Igrac::DohvatiImeIgraca() 
{
	return m_sImeIgraca;
}

string Igrac::DohvatiPrezimeIgraca()
{
	return m_sPrezimeIgraca;
}

int Igrac::DohvatiGodinuRodjenja()
{
	return m_nGodinaRodjenja;
}