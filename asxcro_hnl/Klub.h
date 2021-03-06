#pragma once
#include <string>
using namespace std;

class Klub
{
public:
	Klub();
	Klub(int sk, string n, string g);
	virtual ~Klub();
	int DohvatiSifruKluba() const;
	string DohvatiNazivKluba();
	string DohvatiGradKluba();
	int m_nSifraKluba;
	int m_nBrojUtakmica;
	int m_nBrojPobjeda;
	int m_nBrojNerjesenih;
	int m_nGolRazlika;
	int m_nBrojBodovaKluba;
	int m_nBrojIgracaKluba;
private:
	string m_sNazivKluba;
	string m_sGradKluba;
};