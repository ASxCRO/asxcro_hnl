#pragma once
#include "Klub.h"
class Igrac :
	public Klub
{
public:
	Igrac();
	Igrac(int s, string i, string p, int gr, int sk);
	~Igrac();
	int DohvatiSifruIgraca() const;
	int DohvatiSifruKluba() const;
	string DohvatiImeIgraca();
	string DohvatiPrezimeIgraca();
	int DohvatiGodinuRodjenja();
	TXML::XMLDocument m_docIgraci;
	XMLElement *m_eIgraci;
	vector <Igrac*>m_vIgraci;
	void UcitavanjeIgraci();
	void AzurirajIgrace();
	void DodajIgraca();
	void ObrisiIgraca();
	void PrijelazIgraca();
	void SpremiPromjene();
	void PrikaziIgrace(vector<Igrac*> vIgraci);
	bool operator<(const Igrac& k1) const;
private:

	int m_nSifraIgraca;
	string m_sImeIgraca;
	string m_sPrezimeIgraca;
	int m_nGodinaRodjenja;
};

