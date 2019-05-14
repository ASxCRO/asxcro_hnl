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
	int DohvatiSifruKluba() const;
	string DohvatiNazivKluba();
	string DohvatiGradKluba();
	void SporedniIzbornik(int b);
	int IzaberiOpciju() const;
	int KriviOdabir();
	void UcitavanjeKlubovi();
	vector <Klub*> m_vKlubovi;
	void AzurirajKlub();
	void PrikaziKlubove(vector<Klub*> vKlubovi);
	void FullScreen();
	int m_nSifraKluba;
	int m_nBrojBodovaKluba;
	int m_nBrojIgracaKluba;
private:
	TXML::XMLDocument m_docKlubovi;
	XMLElement *m_eKlubovi;
	string m_sNazivKluba;
	string m_sGradKluba;
	void DodajKlub();
	void IzbrisiKlub();
	void SpremiPromjene(vector<Klub*> vKlubovi);

};


//std::cout << "Regular text\n"
//<< TextAttr(ConsoleForeground::CYAN)
//<< "Bright green text\n"
//<< TextAttr(ConsoleForeground::WHITE)
//<< "Back to regular\n";

