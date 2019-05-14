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
	vector <Utakmica*> m_vRezultati;
	Klub* DohvatiKlubDomacina();
	Klub* DohvatiKlubGosta(Klub* kd);
	int DohvatiGoloveDomacina(Klub* kd, Klub* kg);
	int DohvatiGoloveGosta();
	void UnesiRezultat(Klub* k1, Klub* k2, int gd, int gg);//golovi domacin
	void UlazUProgram();
	void UcitavanjeRezultati();
protected:
	void SpremiPromjene(vector<Utakmica*> vRezultati);
	void OdigrajUtakmice();
	void PrikaziRangListu();
private:
	TXML::XMLDocument m_docRezultati;
	XMLElement *m_eRezultati;
	Klub* m_oKlubDomacina;
	Klub* m_oKlubGosta;
	int m_nGoloviDomacina;
	int m_nGoloviGosta;
	void NormalniFont();

};

