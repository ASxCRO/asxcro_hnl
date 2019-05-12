#pragma once
#include "Klub.h"
#include "Igrac.h"
class Utakmica :
	public Igrac
{
public:
	Utakmica();
	Utakmica(int i);
	Utakmica(Klub* k1, Klub* k2, int gd, int gg); //klub domacin id
	~Utakmica();
	void GlavniIzbornik();
	int DohvatiSifruKlubaDomacina();
	int DohvatiSifruKlubaGosta();
	int DohvatiGoloveDomacina(Klub* kd, Klub* kg);
	int DohvatiGoloveGosta();
	TXML::XMLDocument m_docRezultati;
	XMLElement *m_eRezultati;
	vector <Utakmica*>m_vRezultati;
	void UcitavanjeRezultati();
	void SpremiPromjene();
	Klub* DohvatiKlubDomacina();
	Klub* DohvatiKlubGosta(Klub* kd);
	void OdigrajUtakmice();
	void UnesiRezultat(Klub* k1, Klub* k2, int gd, int gg);//golovi domacin
	void PrikaziRangListu();
	Klub* m_oKlubDomacina;
	Klub* m_oKlubGosta;
private:

	int m_nGoloviDomacina;
	int m_nGoloviGosta;

};

