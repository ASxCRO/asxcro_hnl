#pragma once
#include <string>
using namespace std;

class Klub
{
public:
	Klub();
	Klub(int sk, string n, string g);
	~Klub();
	int DohvatiSifruKluba() const;
	string DohvatiNazivKluba();
	string DohvatiGradKluba();
	int m_nSifraKluba;
	int m_nBrojBodovaKluba;
	int m_nBrojIgracaKluba;
private:
	string m_sNazivKluba;
	string m_sGradKluba;
};


//std::cout << "Regular text\n"
//<< TextAttr(ConsoleForeground::CYAN)
//<< "Bright green text\n"
//<< TextAttr(ConsoleForeground::WHITE)
//<< "Back to regular\n";

