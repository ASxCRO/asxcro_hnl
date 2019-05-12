#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "tinyxml2.h"
#include <fstream>
#include <algorithm>
#include "cpplinq.h"
#include "TextTables.h"
#include "TextColor.h"
using namespace cpplinq;
using namespace std;
using namespace tinyxml2;
namespace TXML = tinyxml2;

class Klub
{
public:
	Klub();
	Klub(int sk, string n, string g);
	~Klub();
	int m_nBrojGolovaKluba;
	int m_nBrojIgracaKluba;
	int m_nBrojBodovaKluba;
	int IzaberiOpciju() const;
	void SporedniIzbornik(int b);
	int KriviOdabir();
	int DohvatiSifruKluba() const;
	string DohvatiNazivKluba();
	string DohvatiGradKluba();
	TXML::XMLDocument m_docKlubovi;
	XMLElement *m_eKlubovi;
	vector <Klub*>m_vKlubovi;
	void UcitavanjeKlubovi();
	void AzurirajKlub();
	void DodajKlub();
	void IzbrisiKlub();
	void SpremiPromjene(vector<Klub*> vKlubovi);
	void PrikaziKlubove(vector<Klub*> vKlubovi);
	void FullScreen();
	bool operator<(const Klub& k1) const;
	int m_nSifraKluba;
private:
	string m_sNazivKluba;
	string m_sGradKluba;
	
};





//std::cout << "Regular text\n"
//<< TextAttr(ConsoleForeground::CYAN)
//<< "Bright green text\n"
//<< TextAttr(ConsoleForeground::WHITE)
//<< "Back to regular\n";

