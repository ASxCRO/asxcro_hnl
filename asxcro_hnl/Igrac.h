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
	string DohvatiImeIgraca();
	string DohvatiPrezimeIgraca();
	int DohvatiGodinuRodjenja();
	void UcitavanjeIgraci();
	vector <Igrac*>m_vIgraci;
	void AzurirajIgrace();
	void DodajIgraca();
	void ObrisiIgraca();
	void PrijelazIgraca();
	void SpremiPromjene(vector<Igrac*> vIgraci);
private:
	TXML::XMLDocument m_docIgraci;
	XMLElement *m_eIgraci;
	int m_nSifraIgraca;
	string m_sImeIgraca;
	string m_sPrezimeIgraca;
	int m_nGodinaRodjenja;
	void PrikaziIgrace(vector<Igrac*> vIgraci);
};

