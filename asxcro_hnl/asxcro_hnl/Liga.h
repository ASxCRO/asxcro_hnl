#pragma once
#include "Klub.h"
#include "Igrac.h"
#include "Utakmica.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tinyxml2.h"
#include "cpplinq.h"
#include "TextTables.h"
#include "TextColor.h"
using namespace cpplinq;
using namespace std;
using namespace tinyxml2;
namespace XML = tinyxml2;
class Liga
{
public:
	Liga();
	~Liga();
	//utility functions
	void UlazUProgram();
	void GlavniIzbornik();
	void SporedniIzbornik(int b);
	int IzaberiOpciju() const;
	int KriviOdabir();
	void UvecajFont();
	void FullScreen();
	//vektori
	vector <Klub*> m_vKlubovi;
	vector <Igrac*>m_vIgraci;
	vector <Utakmica*> m_vRezultati;
	//Ucitavanje u vektore
	void UcitavanjeKlubovi();
	void UcitavanjeIgraci();
	void UcitavanjeRezultati();
	//XML
	XML::XMLDocument m_docKlubovi;
	XMLElement *m_eKlubovi;
	XML::XMLDocument m_docIgraci;
	XMLElement *m_eIgraci;
	XML::XMLDocument m_docRezultati;
	XMLElement *m_eRezultati;
	//spremanje vektora u xml
	void SpremiPromjene(vector<Klub*> vKlubovi);
	void SpremiPromjene(vector<Igrac*> vIgraci);
	void SpremiPromjene(vector<Utakmica*> vRezultati);
	//funkcije klub
	void AzurirajKlub();
	void DodajKlub();
	void IzbrisiKlub();
	//funkcije igrac
	void AzurirajIgrace();
	void DodajIgraca();
	void ObrisiIgraca();
	void PrijelazIgraca();
	//funkcije utakmica
	Klub* DohvatiKlubDomacina();
	Klub* DohvatiKlubGosta(Klub* kd);
	int DohvatiGoloveDomacina(Klub* kd, Klub* kg);
	int DohvatiGoloveGosta();
	void UnesiRezultat(Klub* k1, Klub* k2, int gd, int gg);//golovi domacin
	void OdigrajUtakmice();
	//Tablice
	void PrikaziKlubove(vector<Klub*> vKlubovi);
	void PrikaziIgrace(vector<Igrac*> vIgraci);
	void PrikaziRangListu();
};

