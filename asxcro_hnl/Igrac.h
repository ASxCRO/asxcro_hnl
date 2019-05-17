#pragma once
#include "Klub.h"
class Igrac :
	public Klub
{
public:
	Igrac(int s, string i, string p, int gr, int sk);
	~Igrac();
	int DohvatiSifruIgraca() const;
	string DohvatiImeIgraca();
	string DohvatiPrezimeIgraca();
	int DohvatiGodinuRodjenja();
private:
	int m_nSifraIgraca;
	string m_sImeIgraca;
	string m_sPrezimeIgraca;
	int m_nGodinaRodjenja;

};

