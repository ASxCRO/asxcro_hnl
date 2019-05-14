#include "pch.h"
#include "Utakmica.h"


Utakmica::Utakmica()
{
	UcitavanjeKlubovi();
	UcitavanjeIgraci();
	UcitavanjeRezultati();
}

Utakmica::Utakmica(int i)
{

}

Utakmica::Utakmica(Klub* k1, Klub* k2, int gd, int gg)
{
	m_oKlubDomacina = k1;
	m_oKlubGosta = k2;
	m_nGoloviDomacina = gd;
	m_nGoloviGosta = gg;
}


Utakmica::~Utakmica()
{

}

void Utakmica::UlazUProgram()
{
	NormalniFont();
	system("CLS");
	string sPath = "";
	string sLine = "";
	sPath = "hnl_dobrodosli.txt";
	ifstream oDatoteka(sPath);
	if (oDatoteka.is_open())
	{
		while (getline(oDatoteka, sLine))
		{
			cout << TextAttr(TextColor::CYAN) << sLine << "\n";

		}
		oDatoteka.close();
	}

	Sleep(1000);
	cout << "\n\tUcitavanje...";

	GlavniIzbornik();
}

void Utakmica::NormalniFont()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // sirina slova
	cfi.dwFontSize.Y = 28;                  // visina
	cfi.FontFamily = FF_MODERN;
	cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, L"Consolas"); //font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Utakmica::GlavniIzbornik()
{
	system("CLS");
	string sPath = "";
	string sLine = "";
	sPath = "glavni_izbornik.txt";
	ifstream oDatoteka(sPath);
	if (oDatoteka.is_open())
	{
		while (getline(oDatoteka, sLine))
		{
			cout << TextAttr(TextColor::CYAN) <<  sLine << "\n";

		}
		oDatoteka.close();
	}
	cout << TextAttr(TextColor::WHITE) << "\n\tOdaberite jednu od ponudenih opcija u izborniku\n\n";
	cout << "\t\t[1] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Azuriraj klubove\n";
	cout << "\t\t[2] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Azuriraj igrace\n";
	cout << "\t\t[3] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Prijelaz igraca\n";
	cout << "\t\t[4] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Unesi rezultat\n";
	cout << "\t\t[5] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Odigraj utakmice\n";
	cout << "\t\t[6] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Prikazi rang listu\n";
	cout << "\t\t[7] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Fullscreen/Restore Down\n";
	cout << "\t\t[8] " << TextAttr(TextColor::CYAN) << "-> " << TextAttr(TextColor::WHITE) << "Ugasi program\n";
	int a = IzaberiOpciju();
repeat:
	switch (a) 
	{
		case 1: {
			AzurirajKlub();
			break;
		}
		case 2: {
			AzurirajIgrace();
			break;
		}
		case 3: {
			PrijelazIgraca();
			break;
		}
		case 4: {
			Klub* klubDomacin = DohvatiKlubDomacina();
			Klub *klubGost = DohvatiKlubGosta(klubDomacin);
			int nGoloviDomacina = DohvatiGoloveDomacina(klubDomacin,klubGost);
			int nGoloviGosta = DohvatiGoloveGosta();
			UnesiRezultat(klubDomacin, klubGost, nGoloviDomacina, nGoloviGosta);
			SporedniIzbornik(6);
			break;
		}
		case 5: {
			OdigrajUtakmice();
			break;
		}
		case 6: {
			PrikaziRangListu();
			break;
		}
		case 7: {
			FullScreen();
			GlavniIzbornik();
			break;
		}
		case 8: {
			exit(0);
			break;
		}
		default: {
			a = KriviOdabir();
			goto repeat;
		}
	}
}



void Utakmica::UcitavanjeRezultati()
{
	m_docRezultati.LoadFile("rezultati.xml");
	m_eRezultati = m_docRezultati.FirstChildElement("Rezultati");
	XMLElement *eRezultat;

	for (eRezultat = m_eRezultati->FirstChildElement("utakmica"); eRezultat != NULL; eRezultat = eRezultat->NextSiblingElement())
	{	
		m_oKlubDomacina = new Klub();
		m_oKlubGosta = new Klub();
		m_oKlubDomacina->m_nSifraKluba = atoi(eRezultat->Attribute("klubDomacinID"));
		m_oKlubGosta->m_nSifraKluba = atoi(eRezultat->Attribute("klubGostID"));
		m_nGoloviDomacina = atoi(eRezultat->Attribute("goloviDomacin"));
		m_nGoloviGosta = atoi(eRezultat->Attribute("goloviGost"));
		Utakmica *u1 = new Utakmica(m_oKlubDomacina, m_oKlubGosta, m_nGoloviDomacina, m_nGoloviGosta);
		m_vRezultati.push_back(u1);
		if (m_nGoloviDomacina > m_nGoloviGosta)
		{
			m_oKlubDomacina->m_nBrojBodovaKluba = 3;
		}
		else if (m_nGoloviDomacina == m_nGoloviGosta)
		{
			m_oKlubDomacina->m_nBrojBodovaKluba = 1;
			m_oKlubGosta->m_nBrojBodovaKluba = 1;
		}
		else
		{
			m_oKlubGosta->m_nBrojBodovaKluba = 3;
		}
		for (int i = 0; i < m_vKlubovi.size(); i++)
		{
			if (m_vKlubovi[i]->DohvatiSifruKluba() == m_oKlubDomacina->DohvatiSifruKluba())
			{
				m_vKlubovi[i]->m_nBrojBodovaKluba = m_vKlubovi[i]->m_nBrojBodovaKluba + m_oKlubDomacina->m_nBrojBodovaKluba;
			}
			if (m_vKlubovi[i]->DohvatiSifruKluba() == m_oKlubGosta->DohvatiSifruKluba())
			{
				m_vKlubovi[i]->m_nBrojBodovaKluba = m_vKlubovi[i]->m_nBrojBodovaKluba + m_oKlubGosta->m_nBrojBodovaKluba;
			}
		}
	}
}

Klub* Utakmica::DohvatiKlubDomacina()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: UNESI REZULTAT\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru kluba domacina\n  " << TextAttr(TextColor::WHITE);
	PrikaziKlubove(m_vKlubovi);//tablica
	int a = IzaberiOpciju();
	//cpplinq
	//select klub
	auto odabraniKlubDomacin = from(m_vKlubovi)
		>> where([&](Klub const *klub)
	{
		return (klub->DohvatiSifruKluba() == a);
	})
		>> to_vector();
/*	auto brojIgracaUKlubu = from(m_vIgraci)
		>> where([&](Klub const *igrac)
	{
		return (odabraniKlubDomacin[0]->DohvatiSifruKluba() == igrac->DohvatiSifruKluba());
	})
		>> to_vector();*/
	if (odabraniKlubDomacin.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(6);
	}
	else if (odabraniKlubDomacin[0]->m_nBrojIgracaKluba < 11)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub treba imati minimalno 11 igraca kako bi se utakmica odigrala.\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(3);
	}
	else
	{
		return odabraniKlubDomacin[0];
	}
}

Klub* Utakmica::DohvatiKlubGosta(Klub* kd)
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: UNESI REZULTAT\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	auto kluboviBezDomacina = from(m_vKlubovi)
		>> where([&](Klub const *klub)
	{
		return (klub->DohvatiSifruKluba() != kd->DohvatiSifruKluba());
	})
		>> to_vector();
	cout << "\n\t\tOdabrali ste klub domacina: " << TextAttr(TextColor::CYAN) << kd->DohvatiNazivKluba() << "\n\n" << TextAttr(TextColor::WHITE);
	cout << TextAttr(TextColor::CYAN) << "\t\tOdaberite sifru kluba gosta\n  " << TextAttr(TextColor::WHITE);
	PrikaziKlubove(kluboviBezDomacina);//tablica
	int a = IzaberiOpciju();

	//cpplinq
	//select klub
	auto odabraniKlubGost = from(kluboviBezDomacina)
		>> where([&](Klub const *klub)
	{
		return (klub->DohvatiSifruKluba() == a);
	})
		>> to_vector();
	
	if (odabraniKlubGost.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(6);
	}
	else if (odabraniKlubGost[0]->m_nBrojIgracaKluba < 11)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub treba imati minimalno 11 igraca kako bi se utakmica odigrala.\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(3);
	}
	else
	{
		Klub* klubGost = odabraniKlubGost[0];
		auto odigranaUtakmica = from(m_vRezultati)
			>> where([&](Utakmica const *u1)
		{
			return (u1->m_oKlubDomacina->DohvatiSifruKluba() == kd->DohvatiSifruKluba());
		})
			>> where([&](Utakmica const *u1)
		{
			return (u1->m_oKlubGosta->DohvatiSifruKluba() == klubGost->DohvatiSifruKluba());
		})
			>> to_vector();
		if (odigranaUtakmica.size() == 1)
		{
			cout << "\n\t" << TextAttr(TextColor::RED) << "\tTa utakmica vec je odigrana!" << TextAttr(TextColor::WHITE);
			SporedniIzbornik(6);
		}
		else 
		{
			return klubGost;
		}
	}
}

int Utakmica::DohvatiGoloveDomacina(Klub* kd, Klub* kg)
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: UNESI REZULTAT\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	cout << "\n\t\tOdabrali ste klub domacina: " << TextAttr(TextColor::CYAN) << kd->DohvatiNazivKluba() << "\n" << TextAttr(TextColor::WHITE);
	cout << "\n\t\tOdabrali ste klub gosta: " << TextAttr(TextColor::CYAN) << kg->DohvatiNazivKluba() << "\n\n" << TextAttr(TextColor::WHITE);

	cout << TextAttr(TextColor::CYAN) << "\t\tUnesite broj golova kluba domacina: " << TextAttr(TextColor::WHITE);
	int nGoloviDomacina;
	cin >> nGoloviDomacina;
	return nGoloviDomacina;
}

int Utakmica::DohvatiGoloveGosta()
{
	cout << TextAttr(TextColor::CYAN) << "\t\tUnesnite broj golova kluba gosta: " << TextAttr(TextColor::WHITE);
	int nGoloviGosta;
	cin >> nGoloviGosta;
	cout << TextAttr(TextColor::CYAN) << "\t\tUtakmica je uspjesno zapisana!\n  " << TextAttr(TextColor::WHITE);
	return nGoloviGosta;
}

void Utakmica::UnesiRezultat(Klub* k1, Klub* k2, int gd, int gg)
{
	try {
		Utakmica *u1 = new Utakmica(k1, k2, gd, gg);
		auto odigranaUtakmica = from(m_vRezultati)
			>> where([&](Utakmica const *u2)
		{
			return (u2->m_oKlubDomacina->DohvatiSifruKluba() == u1->m_oKlubDomacina->DohvatiSifruKluba());
		})
			>> where([&](Utakmica const *u2)
		{
			return (u2->m_oKlubGosta->DohvatiSifruKluba() == u2->m_oKlubDomacina->DohvatiSifruKluba());
		})
			>> to_vector();
		if (odigranaUtakmica.size() == 1)
		{
			cout << "\n\t" << TextAttr(TextColor::RED) << "\tTa utakmica vec je odigrana!" << TextAttr(TextColor::WHITE);
			SporedniIzbornik(0);
		}
		else
		{
			m_vRezultati.push_back(u1);
			SpremiPromjene(m_vRezultati);
		}
	}
	catch (int) {
		cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog klupa nije valjano izvrseno.\n Provjerite datoteku rezultati.xml \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(0);
	}

}

void Utakmica::OdigrajUtakmice()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: ODIGRAJ UTAKMICE\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	if (m_vKlubovi.size() != 10)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tDa bi se utakmice odigrale potrebno je tocno 10 klubova!" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(1);
	}
	for (int i = 0; i < m_vKlubovi.size(); i++)
	{
		if (m_vKlubovi[i]->m_nBrojIgracaKluba < 11)
		{
			cout << "\n\t" << TextAttr(TextColor::RED) << "\tDa bi se utakmice odigrale potrebno je minimalno 11 igraca u svakom klubu!" << TextAttr(TextColor::WHITE);
			cout << "\n\t" << "\tKlub: " << TextAttr(TextColor::CYAN) << m_vKlubovi[i]->DohvatiNazivKluba() << TextAttr(TextColor::WHITE) << " nema dovoljno igraca." ;
			SporedniIzbornik(3);
		}
	}
	if (m_vRezultati.size() == 90)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tSve su utakmice odigrane!" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(7);
	}
	cout << TextAttr(TextColor::CYAN) << "\t\tOdigravanje utakmica.Pricekajte...\n  " << TextAttr(TextColor::WHITE);
	int odigraneUtakmice = 0;
	int nk = m_vKlubovi.size();
	for (int j = 0; j < nk; j++)
	{
		m_oKlubDomacina = m_vKlubovi[j];
		auto kluboviUGostima = from(m_vKlubovi)
			>> where([&](Klub const *k1)
		{
			return (m_oKlubDomacina->DohvatiSifruKluba() != k1->DohvatiSifruKluba());
		})
			>> to_vector();
		for (int i = 0; i < kluboviUGostima.size(); i++)
		{
			m_oKlubGosta = kluboviUGostima[i];
			m_nGoloviDomacina = rand() % 5;
			m_nGoloviGosta = rand() % 5;
			vector<Utakmica*> klubDomacina;
			auto odigranaUtakmica = from(m_vRezultati)
				>> where([&](Utakmica const *u1)
			{
				return (u1->m_oKlubDomacina->DohvatiSifruKluba() == m_oKlubDomacina->DohvatiSifruKluba());
			})
				>> where([&](Utakmica const *u1)
			{
				return (u1->m_oKlubGosta->DohvatiSifruKluba() == m_oKlubGosta->DohvatiSifruKluba());
			})
				>> to_vector();
			if (odigranaUtakmica.size() == 1)
			{
				odigraneUtakmice++;
				if (odigraneUtakmice == 90)
				{
					cout << "\n\t" << TextAttr(TextColor::RED) << "\tSve su utakmice odigrane!" << TextAttr(TextColor::WHITE);
					SporedniIzbornik(0);
				}
			}
			else
			{
				UnesiRezultat(m_oKlubDomacina,m_oKlubGosta, m_nGoloviDomacina, m_nGoloviGosta);
				if (m_vRezultati.size() == 90)
				{
					cout << TextAttr(TextColor::CYAN) << "\n\t\tUtakmice su uspjesno odigrane!\n  " << TextAttr(TextColor::WHITE);
					SporedniIzbornik(0);
				}
			}
		}
	}
}

void Utakmica::SpremiPromjene(vector<Utakmica*> vRezultati)
{
	auto vSortiraneUtakmice = from(vRezultati)
		>> orderby_ascending([&](Utakmica const *u) {  return u->m_oKlubDomacina->DohvatiSifruKluba(); })
		>> thenby_ascending([&](Utakmica const *u) {  return u->m_oKlubGosta->DohvatiSifruKluba(); })
		>> to_vector();
	vRezultati = vSortiraneUtakmice;
	m_docRezultati.LoadFile("rezultati.xml");
	m_eRezultati = m_docRezultati.FirstChildElement("Rezultati");
	m_eRezultati->DeleteChildren();
	for (int i = 0; i < vRezultati.size(); i++)
	{
		XMLElement *noviRezultat = m_docRezultati.NewElement("utakmica");
		noviRezultat->SetAttribute("klubDomacinID", (vRezultati[i]->m_oKlubDomacina->DohvatiSifruKluba()));
		noviRezultat->SetAttribute("klubGostID", (vRezultati[i]->m_oKlubGosta->DohvatiSifruKluba()));
		noviRezultat->SetAttribute("goloviDomacin", (vRezultati[i]->m_nGoloviDomacina));
		noviRezultat->SetAttribute("goloviGost", (vRezultati[i]->m_nGoloviGosta));
		m_eRezultati->LinkEndChild(noviRezultat);
	}
	m_docRezultati.SaveFile("rezultati.xml");
}

void Utakmica::PrikaziRangListu()
{	
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: PRIKAZI RANG LISTU\n  " << TextAttr(TextColor::WHITE);
	cout << "\t=======================================================\n";
	if (m_vKlubovi.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "Ne postoji ni jedan klub. \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(1);
	}
	auto vRang = from(m_vKlubovi)
		>> orderby_descending([&](Klub const *klub) {  return klub->m_nBrojBodovaKluba; })
		>> to_vector();
	TextTables t('-', '|', '+');
	t.add("Redni broj");
	t.add("Naziv kluba");
	t.add("Grad");
	t.add("Bodovi");
	t.endOfRow();
	for (int i = 0; i < vRang.size(); i++)
	{
		t.add(to_string(i+1));
		t.add(vRang[i]->DohvatiNazivKluba());
		t.add(vRang[i]->DohvatiGradKluba());
		t.add(to_string(vRang[i]->m_nBrojBodovaKluba));
		t.endOfRow();
	}
	cout << "\n\t" << t;
	SporedniIzbornik(7);
}
