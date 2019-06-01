#include "pch.h"
#include "Klub.h"

Klub::Klub()
{
	m_nBrojUtakmica = 0;
	m_nBrojPobjeda = 0;
	m_nBrojNerjesenih = 0;
	m_nGolRazlika = 0;
	m_nBrojBodovaKluba = 0;
	m_nBrojIgracaKluba = 0;
}

Klub::Klub(int sk, string n, string g)
{
	m_nSifraKluba = sk;
	m_sNazivKluba = n;
	m_sGradKluba = g;
	m_nBrojUtakmica = 0;
	m_nBrojPobjeda = 0;
	m_nBrojNerjesenih = 0;
	m_nGolRazlika = 0;
	m_nBrojBodovaKluba = 0;
	m_nBrojIgracaKluba = 0;
}

Klub::~Klub()
{}

int Klub::DohvatiSifruKluba() const
{
	return m_nSifraKluba;
}

string Klub::DohvatiNazivKluba()
{
	return m_sNazivKluba;
}

string Klub::DohvatiGradKluba()
{
	return m_sGradKluba;
}
