#include "pch.h"
#include "Liga.h"


Liga::Liga() // Pri konstrukciji ucitavamo bazu u vektore
{
	UcitavanjeKlubovi();
	UcitavanjeIgraci();
	UcitavanjeRezultati();
}

Liga::~Liga()
{
}

// -------------------------------------------------------------------------
// Utility class function
// -------------------------------------------------------------------------
void Liga::UlazUProgram()
{
	UvecajFont();
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
	cout << "\n\tUcitavanje...";
	Sleep(1000);
	GlavniIzbornik();
}

void Liga::GlavniIzbornik()
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
			cout << TextAttr(TextColor::CYAN) << sLine << "\n";

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
		int nGoloviDomacina = DohvatiGoloveDomacina(klubDomacin, klubGost);
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

void Liga::SporedniIzbornik(int b)
{
	if (b == 1)
	{
		cout << "\n\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[N]" << TextAttr(TextColor::WHITE) << " za dodavanje novog kluba.\t\n";
	}
	if (b == 2)
	{
		cout << "\n\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[E]" << TextAttr(TextColor::WHITE) << " za opciju brisanje kluba.\t\n";
	}
	if (b == 3)
	{
		cout << "\n\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[I]" << TextAttr(TextColor::WHITE) << " za dodavanje novog igraca.\t\n";
	}
	if (b == 4)
	{
		cout << "\n\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[F]" << TextAttr(TextColor::WHITE) << " za opciju brisanje igraca.\t\n";
	}
	if (b == 5)
	{
		cout << "\n\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[P]" << TextAttr(TextColor::WHITE) << " za opciju prijelaz igraca.\t\n";
	}
	if (b == 6)
	{
		cout << "\n\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[U]" << TextAttr(TextColor::WHITE) << " za opciju unesi rezultat.\t\n";
	}

	cout << "\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[Q]" << TextAttr(TextColor::WHITE) << " za povratak u glavni izbornik \t\n";
	cout << "\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[X]" << TextAttr(TextColor::WHITE) << " za izlazak iz programa\t\n";
	int a = IzaberiOpciju();

repeat:
	switch (a)
	{
	case 113: {
		cout << TextAttr(TextColor::CYAN) << "\n\t\Pricekajte.." << TextAttr(TextColor::WHITE);
		GlavniIzbornik();
		break;
	}
	case 120: {
		exit(0);
		break;
	}

	case 110: {
		if (b == 1)
		{
			DodajKlub();
		}
		else
		{
			a = KriviOdabir();
			goto repeat;
		}
		break;
	}
	case 101: {
		if (b == 2)
		{
			IzbrisiKlub();

		}
		else
		{
			a = KriviOdabir();
			goto repeat;
		}
		break;
	}
	case 105: {
		if (b == 3)
		{
			DodajIgraca();
		}
		else
		{
			a = KriviOdabir();
			goto repeat;
		}
		break;
	}
	case 102: {
		if (b == 4)
		{
			ObrisiIgraca();
		}
		else
		{
			a = KriviOdabir();
			goto repeat;
		}
		break;
	}
	case 112: {
		if (b == 5)
		{
			PrijelazIgraca();
		}
		else
		{
			a = KriviOdabir();
			goto repeat;
		}
		break;
	}
	case 117: {
		if (b == 6)
		{
			cout << TextAttr(TextColor::CYAN) << "\n\t\tSpremanje.." << TextAttr(TextColor::WHITE);
			Klub* k1 = DohvatiKlubDomacina();
			Klub* k2 = DohvatiKlubGosta(k1);
			int nBrojGolovaDomacina = DohvatiGoloveDomacina(k1, k2);
			int nBrojGolovaGosta = DohvatiGoloveGosta();
			UnesiRezultat(k1, k2, nBrojGolovaDomacina, nBrojGolovaGosta);
			SporedniIzbornik(6);
		}
		else
		{
			a = KriviOdabir();
			goto repeat;
		}
		break;
	}
	default: {
		a = KriviOdabir();
		goto repeat;
		break;
	}
	}
}

int  Liga::IzaberiOpciju()
{
	int a = 0;
	bool nastaviPetlju = false;
	char key = ' ';
	bool quit = false;
	while (!nastaviPetlju)
	{
		cout << "\n\t\tVas izbor: ";
			
		while (!quit)
		{
			key = _getch();
			if (int(key) > 100) //ascii
			{
				a = int(key);
			}
			else if (int(key)> 0 && int(key) <= 100) {
				a = int(key) - 48;
			}
			else if (int(key) == 0)
			{
				a = KriviOdabir();
			}
			quit = true;
			break;
		}
		nastaviPetlju = true;
	}
	return a;
}

int Liga::KriviOdabir()
{
	cout << "\t\t " << TextAttr(TextColor::RED) << " \n\t\tKrivi odabir!\n\t\tPokusajte ponovno. \n\n " << TextAttr(TextColor::WHITE);
	int a = IzaberiOpciju();
	return a;
}

void Liga::UvecajFont()
{
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = 0;                   //
	font.dwFontSize.Y = 28;                  //velicina slova
	font.FontFamily = FF_MODERN;
	font.FontWeight = FW_BOLD;
	wcscpy_s(font.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);
}

void Liga::FullScreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0); // keybd_event flag Alt push
	keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter push
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // enter release
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);// Alt release
}

// -------------------------------------------------------------------------
// Ucitavanje u vektore
// -------------------------------------------------------------------------
void Liga::UcitavanjeKlubovi()
{
	m_docKlubovi.LoadFile("klubovi.xml");
	m_eKlubovi = m_docKlubovi.FirstChildElement("Klubovi");
	XMLElement *eKlub;
	for (eKlub = m_eKlubovi->FirstChildElement("klub"); eKlub != NULL; eKlub = eKlub->NextSiblingElement())
	{
		string sNazivKluba = eKlub->Attribute("nazivKluba");
		string sGradKluba = eKlub->Attribute("gradKluba");
		int nKlubID = atoi(eKlub->Attribute("klubID"));
		Klub *k1 = new Klub(nKlubID, sNazivKluba, sGradKluba);
		k1->m_nBrojBodovaKluba = 0;
		m_vKlubovi.push_back(k1);
	}
}

void Liga::UcitavanjeIgraci()
{
	m_docIgraci.LoadFile("igraci.xml");
	m_eIgraci = m_docIgraci.FirstChildElement("Igraci");
	XMLElement *eIgrac;
	for (eIgrac = m_eIgraci->FirstChildElement("igrac"); eIgrac != NULL; eIgrac = eIgrac->NextSiblingElement())
	{
		int nSifraIgraca = atoi(eIgrac->Attribute("igracID"));
		string sImeIgraca = eIgrac->Attribute("ime");
		string sPrezimeIgraca = eIgrac->Attribute("prezime");
		int nGodinaRodjenja = atoi(eIgrac->Attribute("godinaRodjenja"));
		int nSifraKluba = atoi(eIgrac->Attribute("klubID"));
		Igrac *i1 = new Igrac(nSifraIgraca, sImeIgraca, sPrezimeIgraca, nGodinaRodjenja, nSifraKluba);
		m_vIgraci.push_back(i1);
	}
	for (int j = 0; j < m_vKlubovi.size(); j++)
	{
		for (int i = 0; i < m_vIgraci.size(); i++)
		{
			if (m_vKlubovi[j]->DohvatiSifruKluba() == m_vIgraci[i]->DohvatiSifruKluba())
				m_vKlubovi[j]->m_nBrojIgracaKluba++;
		}
	}
}

void Liga::UcitavanjeRezultati()
{
	m_docRezultati.LoadFile("rezultati.xml");
	m_eRezultati = m_docRezultati.FirstChildElement("Rezultati");
	XMLElement *eRezultat;
	for (eRezultat = m_eRezultati->FirstChildElement("utakmica"); eRezultat != NULL; eRezultat = eRezultat->NextSiblingElement())
	{
		Klub* k1 = new Klub();
		Klub* k2 = new Klub();
		k1->m_nSifraKluba = atoi(eRezultat->Attribute("klubDomacinID"));
		k2->m_nSifraKluba = atoi(eRezultat->Attribute("klubGostID"));
		int nGoloviDomacina = atoi(eRezultat->Attribute("goloviDomacin"));
		int nGoloviGosta = atoi(eRezultat->Attribute("goloviGost"));
		Utakmica *u1 = new Utakmica(k1, k2, nGoloviDomacina, nGoloviGosta);
		m_vRezultati.push_back(u1);
		if (nGoloviDomacina > nGoloviGosta) //Dohvacanje broja bodova kluba na rang listi
		{
			k1->m_nBrojBodovaKluba = 3;
		}
		else if (nGoloviDomacina == nGoloviGosta)
		{
			k1->m_nBrojBodovaKluba = 1;
			k2->m_nBrojBodovaKluba = 1;
		}
		else
		{
			k2->m_nBrojBodovaKluba = 3;
		}
		for (int i = 0; i < m_vKlubovi.size(); i++)
		{
			if (m_vKlubovi[i]->DohvatiSifruKluba() == k1->DohvatiSifruKluba())
			{
				m_vKlubovi[i]->m_nBrojBodovaKluba = m_vKlubovi[i]->m_nBrojBodovaKluba + k1->m_nBrojBodovaKluba;
			}
			if (m_vKlubovi[i]->DohvatiSifruKluba() == k2->DohvatiSifruKluba())
			{
				m_vKlubovi[i]->m_nBrojBodovaKluba = m_vKlubovi[i]->m_nBrojBodovaKluba + k2->m_nBrojBodovaKluba;
			}
		}
	}
}

// -------------------------------------------------------------------------
// Zapisivanje u XML
// -------------------------------------------------------------------------
void Liga::SpremiPromjene(vector<Klub*> vKlubovi)
{
	sort(vKlubovi.begin(), vKlubovi.end(), [](const Klub *lhs, const Klub *rhs)
		{
			return lhs->DohvatiSifruKluba() < rhs->DohvatiSifruKluba();
		});
	m_eKlubovi->DeleteChildren();
	for (int i = 0; i < vKlubovi.size(); i++)
	{
		XMLElement *noviKlub = m_docKlubovi.NewElement("klub");
		noviKlub->SetAttribute("nazivKluba", (vKlubovi[i]->DohvatiNazivKluba()).c_str());
		noviKlub->SetAttribute("klubID", (vKlubovi[i]->DohvatiSifruKluba()));
		noviKlub->SetAttribute("gradKluba", (vKlubovi[i]->DohvatiGradKluba()).c_str());
		m_eKlubovi->LinkEndChild(noviKlub);
	}
	m_docKlubovi.SaveFile("klubovi.xml");
}

void Liga::SpremiPromjene(vector<Igrac*> vIgraci)
{
	auto vPoredaniIgraci = from(vIgraci)
		>> orderby_ascending([&](Igrac const *igrac) {  return igrac->DohvatiSifruIgraca(); })
		>> to_vector();
	vIgraci = vPoredaniIgraci;
	m_docIgraci.LoadFile("igraci.xml");
	m_eIgraci = m_docIgraci.FirstChildElement("Igraci");
	m_eIgraci->DeleteChildren();
	for (int i = 0; i < vIgraci.size(); i++)
	{
		XMLElement *noviIgrac = m_docIgraci.NewElement("igrac");
		noviIgrac->SetAttribute("klubID", (vIgraci[i]->DohvatiSifruKluba()));
		noviIgrac->SetAttribute("godinaRodjenja", (vIgraci[i]->DohvatiGodinuRodjenja()));
		noviIgrac->SetAttribute("prezime", (vIgraci[i]->DohvatiPrezimeIgraca().c_str()));
		noviIgrac->SetAttribute("ime", (vIgraci[i]->DohvatiImeIgraca().c_str()));
		noviIgrac->SetAttribute("igracID", (vIgraci[i]->DohvatiSifruIgraca()));
		m_eIgraci->LinkEndChild(noviIgrac);
	}
	m_docIgraci.SaveFile("igraci.xml");
}

void Liga::SpremiPromjene(vector<Utakmica*> vRezultati)
{
	auto vSortiraneUtakmice = from(vRezultati)
		>> orderby_ascending([&](Utakmica const *u) {  return u->m_oKlubDomacina->DohvatiSifruKluba(); })
		>> thenby_ascending([&](Utakmica const *u) {  return u->m_oKlubGosta->DohvatiSifruKluba(); })
		>> to_vector();
	vRezultati = vSortiraneUtakmice;
	vSortiraneUtakmice.clear();
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

// -------------------------------------------------------------------------
// Funkcije implementirane za manipulaciju Klubova
// -------------------------------------------------------------------------
void Liga::AzurirajKlub()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: AZURIRAJ KLUB\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n\n";
	cout << TextAttr(TextColor::WHITE) << "\tOdaberite jednu od ponudenih opcija u izborniku\n\n";
	cout << TextAttr(TextColor::CYAN) << "\t\t[1] " << TextAttr(TextColor::WHITE) << "-> " << "Dodaj klub\n";
	cout << TextAttr(TextColor::CYAN) << "\t\t[2] " << TextAttr(TextColor::WHITE) << "-> " << "Izbrisi klub\n";
	int a = IzaberiOpciju();
repeat:
	switch (a)
	{
	case 1: {
		DodajKlub();
		break;
	}
	case 2: {
		IzbrisiKlub();
		break;
	}
	default: {
		a = KriviOdabir();
		goto repeat;
	}
	}
}

void Liga::DodajKlub()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: DODAJ KLUB\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n\n";

	if (m_vKlubovi.size() == 10)
	{
		cout << "\t\t " << TextAttr(TextColor::RED) << " \n\t\tHNL vec ima deset klubova!\n\t\tIzaberite jednu od sljedecih opcija: \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(2);
	}
	else
	{
		sort(m_vKlubovi.begin(), m_vKlubovi.end(), [](const Klub * lhs, const Klub * rhs)
			{
				return lhs->DohvatiSifruKluba() < rhs->DohvatiSifruKluba();
			});

		int nSifraKluba;
		string sNazivKluba;
		string sGradKluba;
		int i = 0;
		if (m_vKlubovi.size() == 0)
		{
			cout << "\tSifra kluba: " << 0 << endl;
			nSifraKluba = 0;
			goto korak;
		}
		for (int n = 0; n < m_vKlubovi.size(); n++) // petlja za automatski odabir sifre kluba
		{
			if (i >= m_vKlubovi.size() - 1)
			{
				cout << "\tSifra kluba: " << n + 1 << endl;
				nSifraKluba = n + 1;
				break;
			}
			else if (m_vKlubovi[i]->DohvatiSifruKluba() == n) {
				i++;
			}
			else
			{
				cout << "\tSifra kluba: " << n << endl;
				nSifraKluba = n;
				break;
			}
		}
	korak:
		cout << "\tUnesite naziv kluba: ";
		getline(cin, sNazivKluba);
		cout << "\tUnesite grad kluba: ";
		getline(cin, sGradKluba);
		m_vKlubovi.push_back(new Klub(nSifraKluba, sNazivKluba, sGradKluba));
		try { // uhvati iznimku ako se ovaj kod nemoze izvrsiti
			SpremiPromjene(m_vKlubovi);
			cout << TextAttr(TextColor::CYAN) << "\n\n\tUspjesno ste dodali novi klub!" << TextAttr(TextColor::WHITE);
			SporedniIzbornik(1);
		}
		catch (int) {
			cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog klupa nije valjano izvrseno.\n Provjerite datoteku klubovi.xml \n\n " << TextAttr(TextColor::WHITE);
			SporedniIzbornik(0);
		}
	}
}

void Liga::IzbrisiKlub()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: OBRISI KLUB\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";

	if (m_vKlubovi.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "Ne postoji ni jedan klub. \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(1);
	}

	cout << "\n\t" << TextAttr(TextColor::RED) << "*Brisanjem kluba ce se obrisati svi igraci koji igraju za taj klub! \n\n " << TextAttr(TextColor::WHITE);
	cout << TextAttr(TextColor::CYAN) << "\tOdaberite redni broj kluba kojeg zelite obrisati\n  " << TextAttr(TextColor::WHITE);
	PrikaziKlubove(m_vKlubovi);//tablica
	int a = IzaberiOpciju();

	auto kluboviBezOdabranog = from(m_vKlubovi)	//brisanje kluba
		>> where([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba() != a);
			})
		>> orderby_ascending([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba());
			}
		)
		>> to_vector();

	auto igraciBezOdabranih = from(m_vIgraci)	//brisanje igraca odabranog kluba
		>> where([&](Igrac const *igracina)
			{
				return (igracina->DohvatiSifruKluba() != a);
			})
		>> orderby_ascending([&](Igrac const *igracina)
			{
				return (igracina->DohvatiSifruIgraca());
			}
		)
		>> to_vector();

	auto rezultatiBezOdabranogKluba = from(m_vRezultati)	//brisanje rezultata odabranog kluba
		>> where([&](Utakmica const* u1)
			{
				return (u1->m_oKlubDomacina->DohvatiSifruKluba() != a);
			})
		>> where([&](Utakmica const* u1)
			{
				return (u1->m_oKlubGosta->DohvatiSifruKluba() != a);
			})
		>> to_vector();
	if (m_vKlubovi.size() == kluboviBezOdabranog.size())
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
	}
	else
	{
		m_vKlubovi = kluboviBezOdabranog;
		m_vIgraci = igraciBezOdabranih;
		m_vRezultati = rezultatiBezOdabranogKluba;
		SpremiPromjene(m_vKlubovi);
		SpremiPromjene(m_vIgraci);
		SpremiPromjene(m_vRezultati);
		cout << TextAttr(TextColor::CYAN) << "\n\n\t\tUspjesno ste izbrisali igrace kluba i klub pod sifrom " << a << TextAttr(TextColor::WHITE);
	}
	SporedniIzbornik(2);
}

// -------------------------------------------------------------------------
// Funkcije implementirane za manipulaciju Igraca
// -------------------------------------------------------------------------
void Liga::AzurirajIgrace()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: AZURIRAJ IGRACE\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n\n";
	cout << TextAttr(TextColor::WHITE) << "\tOdaberite jednu od ponudenih opcija u izborniku\n\n";
	cout << TextAttr(TextColor::CYAN) << "\t\t[1] " << TextAttr(TextColor::WHITE) << "-> " << "Dodaj igraca\n";
	cout << TextAttr(TextColor::CYAN) << "\t\t[2] " << TextAttr(TextColor::WHITE) << "-> " << "Obrisi igraca\n";
	int a = IzaberiOpciju();
repeat:
	switch (a)
	{
	case 1: {
		DodajIgraca();
		break;
	}
	case 2: {
		ObrisiIgraca();
		break;
	}
	default: {
		a = KriviOdabir();
		goto repeat;
	}
	}
}

void Liga::DodajIgraca()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: DODAJ IGRACA\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n\n";
	int nSifraIgraca;
	string sImeIgraca;
	string sPrezimeIgraca;
	int nGodinaRodjenja;
	int nSifraKluba;
	if (m_vIgraci.size() == 0)
	{
		cout << "\tSifra igraca: " << 0 << endl;
		nSifraIgraca = 0;
	}
	else
	{
		sort(m_vIgraci.begin(), m_vIgraci.end(), [](const Igrac * lhs, const Igrac * rhs)
			{
				return lhs->DohvatiSifruIgraca() < rhs->DohvatiSifruIgraca();
			});
		int i = 0;
		for (int n = 0; n <= m_vIgraci.size(); n++) // petlja za pronalazak slobodne sifre za igraca
		{
			if (i >= m_vIgraci.size() - 1)
			{
				cout << "\tSifra igraca: " << n + 1 << endl;
				nSifraIgraca = n + 1;
				break;
			}
			else if (m_vIgraci[i]->DohvatiSifruIgraca() == n) {
				i++;
			}
			else
			{
				cout << "\tSifra igraca: " << n << endl;
				nSifraIgraca = n;
				break;
			}
		}
	}
	cout << "\tUnesite ime igraca: ";
	cin >> sImeIgraca;
	cout << "\tUnesite prezime igraca: ";
	cin >> sPrezimeIgraca;
	cout << "\tUnesite godinu rodjenja igraca: ";
	cin >> nGodinaRodjenja;
	cout << "\tUnesite sifru kluba igraca: \n";
	PrikaziKlubove(m_vKlubovi); // tablica
	int a = IzaberiOpciju();
repeat:
	auto odabraniKlub = from(m_vKlubovi)	//klub u kojeg zelimo dodati igraca
		>> where([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba() == a);
			})
		>> to_vector();
	if (odabraniKlub.size() == 1)
	{
		nSifraKluba = odabraniKlub[0]->DohvatiSifruKluba();
		for (int j = 0; j < m_vKlubovi.size(); j++) // dodaj igraca u klub brojcano
		{
				if (odabraniKlub[0]->DohvatiSifruKluba() == m_vKlubovi[j]->DohvatiSifruKluba())
					m_vKlubovi[j]->m_nBrojIgracaKluba++;
		}
	}
	else
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n\t\tPokusajte ponovno.\n" << TextAttr(TextColor::WHITE);
		a = IzaberiOpciju();
		goto repeat;
	}
	m_vIgraci.push_back(new Igrac(nSifraIgraca, sImeIgraca, sPrezimeIgraca, nGodinaRodjenja, nSifraKluba));
	try { // uhvati iznimku ako se ovaj kod nemoze izvrsiti
		SpremiPromjene(m_vIgraci);
		cout << TextAttr(TextColor::CYAN) << "\n\n\t\tUspjesno ste dodali novog igraca!" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(3);
	}
	catch (int) {
		cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog klupa nije valjano izvrseno.\n Provjerite datoteku igraci.xml \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(0);
	}

}

void Liga::ObrisiIgraca()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: OBRISI IGRACA\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	if (m_vIgraci.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "Ne postoji ni jedan igrac. \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(3);
	}

	cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru kluba iz kojeg zelite obrisati igraca\n  " << TextAttr(TextColor::WHITE);
	PrikaziKlubove(m_vKlubovi); //tablica
	int a = IzaberiOpciju();

	auto odabraniKlub = from(m_vKlubovi)	//klub iz kojeg zelimo obrisati igraca
		>> where([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba() == a);
			})
		>> to_vector();

	if (odabraniKlub.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(4);
	}
	else
	{
		system("CLS");
		cout << "\n\t\tOdabrali ste klub: " << TextAttr(TextColor::CYAN) << odabraniKlub[0]->DohvatiNazivKluba() << "\n\n" << TextAttr(TextColor::WHITE);
		cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru igraca kojeg zelite obrisati\n  " << TextAttr(TextColor::WHITE);
		auto igraciOdabranogKluba = from(m_vIgraci)	
			>> where([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruKluba() == odabraniKlub[0]->DohvatiSifruKluba());
				})
			>> orderby_ascending([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruIgraca());
				}
			)
			>> to_vector();
		PrikaziIgrace(igraciOdabranogKluba); //tablica
		int b; //odabir igraca kojeg zelimo obrisati
		cout << "\n\t\tVas izbor: ";
		cin >> b;
		auto odabraniIgrac = from(igraciOdabranogKluba)
			>> where([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruIgraca() == b);
				})
			>> to_vector();
		auto igraciBezOdabranog = from(m_vIgraci) 
			>> where([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruIgraca() != b);
				})
			>> to_vector();
		if (odabraniIgrac.size() == 0)
		{
			cout << "\n\t" << TextAttr(TextColor::RED) << "\tIgrac sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
			SporedniIzbornik(4);
		}
		else
		{
			m_vIgraci = igraciBezOdabranog;
			for (int j = 0; j < m_vKlubovi.size(); j++) // smanji broj igraca u klubu iz kojeg smo obrisali igraca
			{
				if (odabraniKlub[0]->DohvatiSifruKluba() == m_vKlubovi[j]->DohvatiSifruKluba())
					m_vKlubovi[j]->m_nBrojIgracaKluba--;
			}
			try { // catch exeption if this code cannot run
				SpremiPromjene(m_vIgraci);
				cout << TextAttr(TextColor::CYAN) << "\n\n\t\tUspjesno ste obrisali igraca!" << TextAttr(TextColor::WHITE);
				SporedniIzbornik(4);
			}
			catch (int) {
				cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog klupa nije valjano izvrseno.\n Provjerite datoteku igraci.xml \n\n " << TextAttr(TextColor::WHITE);
				SporedniIzbornik(0);
			}
		}
	}
}

void Liga::PrijelazIgraca()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: PRIJELAZ IGRACA\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	if (m_vKlubovi.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "Ne postoji ni jedan klub. \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(1);
	}
	if (m_vIgraci.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "Ne postoji ni jedan igrac. \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(3);
	}
	cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru kluba iz kojeg zelite odabrati igraca\n  " << TextAttr(TextColor::WHITE);
	PrikaziKlubove(m_vKlubovi);//tablica
	int a = IzaberiOpciju();

	auto odabraniKlubDomacin = from(m_vKlubovi) // it kojeg kluba zelite prebaciti igraca
		>> where([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba() == a);
			})
		>> to_vector();
	auto kluboviBezOdabranog = from(m_vKlubovi) // svi klubovi bez proslo odabranog
		>> where([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba() != a);
			})
		>> to_vector();
	if (odabraniKlubDomacin.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(5);
	}
	else
	{
		system("CLS");
		cout << "\n\t\tOdabrali ste klub: " << TextAttr(TextColor::CYAN) << odabraniKlubDomacin[0]->DohvatiNazivKluba() << "\n\n" << TextAttr(TextColor::WHITE);
		cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru igraca na kojem zelite napraviti prijelaz\n  " << TextAttr(TextColor::WHITE);
		auto igraciOdabranogKluba = from(m_vIgraci) //odabir igraca iz odabranog kluba
			>> where([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruKluba() == odabraniKlubDomacin[0]->DohvatiSifruKluba());
				})
			>> orderby_ascending([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruIgraca());
				}
			)
			>> to_vector();
		PrikaziIgrace(igraciOdabranogKluba);//tablica
		int b;
		cout << "\n\t\tVas izbor: ";
		cin >> b;

		auto odabraniIgrac = from(igraciOdabranogKluba) // odaberi igraca kojeg zeli prebaciti
			>> where([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruIgraca() == b);
				})
			>> to_vector();
		auto igraciBezOdabranog = from(m_vIgraci) // svi igraci osim proslo odabranog
			>> where([&](Igrac const *igracina)
				{
					return (igracina->DohvatiSifruIgraca() != b);
				})
			>> to_vector();
		if (odabraniIgrac.size() == 0)
		{
			cout << "\n\t" << TextAttr(TextColor::RED) << "\tIgrac sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
			SporedniIzbornik(5);
		}
		else
		{
			system("CLS");
			cout << "\n\t\tOdabrali ste igraca: " << TextAttr(TextColor::CYAN) << odabraniIgrac[0]->DohvatiImeIgraca() << odabraniIgrac[0]->DohvatiPrezimeIgraca() << "\n\n" << TextAttr(TextColor::WHITE);
			cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru kluba u kojeg zelite da igrac predje\n  " << TextAttr(TextColor::WHITE);
			PrikaziKlubove(kluboviBezOdabranog);//tablica
			int a = IzaberiOpciju();

			auto odabraniKlubGost = from(kluboviBezOdabranog) // klub U kojeg zelim prebaciti odabranog igraca
				>> where([&](Klub const *klub)
					{
						return (klub->DohvatiSifruKluba() == a);
					})
				>> to_vector();
			if (odabraniKlubGost.size() == 0)
			{
				cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!" << TextAttr(TextColor::WHITE);
				SporedniIzbornik(5);
			}
			else
			{
				for (int j = 0; j < m_vKlubovi.size(); j++) //oduzmi igraca kojeg prebacujemo klubu iz kojeg zelimo prebaciti
				{
					if (odabraniKlubDomacin[0]->DohvatiSifruKluba() == m_vKlubovi[j]->DohvatiSifruKluba())
						m_vKlubovi[j]->m_nBrojIgracaKluba--;
				}			
				for (int j = 0; j < m_vKlubovi.size(); j++) //dodaj igraca kojeg prebacujemo klubu u kojeg zelimo prebaciti
				{
					if (odabraniKlubGost[0]->DohvatiSifruKluba() == m_vKlubovi[j]->DohvatiSifruKluba())
						m_vKlubovi[j]->m_nBrojIgracaKluba++;
				}
				odabraniIgrac[0]->m_nSifraKluba = odabraniKlubGost[0]->DohvatiSifruKluba();
				igraciBezOdabranog.push_back(odabraniIgrac[0]);
				m_vIgraci = igraciBezOdabranog;

				try { // and catch it if code isnt right
					SpremiPromjene(m_vIgraci);
					cout << TextAttr(TextColor::CYAN) << "\n\n\t\tUspjesno ste napravili prijelaz igraca!" << TextAttr(TextColor::WHITE);
					SporedniIzbornik(5);
				}
				catch (int) {
					cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog klupa nije valjano izvrseno.\n Provjerite datoteku igraci.xml \n\n " << TextAttr(TextColor::WHITE);
					SporedniIzbornik(0);
				}
			}
		}
	}
}

// -------------------------------------------------------------------------
// Funkcije implementirane za manipulaciju Utakmica
// -------------------------------------------------------------------------
Klub* Liga::DohvatiKlubDomacina()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: UNESI REZULTAT\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru kluba domacina\n  " << TextAttr(TextColor::WHITE);
	PrikaziKlubove(m_vKlubovi);//tablica
	int a = IzaberiOpciju();

	auto odabraniKlubDomacin = from(m_vKlubovi)
		>> where([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba() == a);
			})
		>> to_vector();
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

Klub* Liga::DohvatiKlubGosta(Klub* kd)
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
	else if (odabraniKlubGost[0]->m_nBrojIgracaKluba < 11) // provjeri broj igraca kluba
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub treba imati minimalno 11 igraca kako bi se utakmica odigrala.\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(3);
	}
	else
	{
		Klub* klubGost = odabraniKlubGost[0];
		auto odigranaUtakmica = from(m_vRezultati)// provjeri je li utakmica odigrana
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

int Liga::DohvatiGoloveDomacina(Klub* kd, Klub* kg)
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

int Liga::DohvatiGoloveGosta()
{
	cout << TextAttr(TextColor::CYAN) << "\t\tUnesnite broj golova kluba gosta: " << TextAttr(TextColor::WHITE);
	int nGoloviGosta;
	cin >> nGoloviGosta;
	cout << TextAttr(TextColor::CYAN) << "\t\tUtakmica je uspjesno zapisana!\n  " << TextAttr(TextColor::WHITE);
	return nGoloviGosta;
}

void Liga::UnesiRezultat(Klub* k1, Klub* k2, int gd, int gg)
{
	try { // ulovi iznimku koja moze biti u ovom bloku
		int nBrojBodovaDomacina = 0;
		int nBrojBodovaGosta = 0;
		if (gd > gg)
		{
			nBrojBodovaDomacina = 3;
		}
		else if (gd == gg)
		{
			nBrojBodovaDomacina = 1;
			nBrojBodovaGosta = 1;
		}
		else
		{
			nBrojBodovaGosta = 3;
		}
		for (int i = 0; i < m_vKlubovi.size(); i++) // zbroji bodove
		{
			if (m_vKlubovi[i]->DohvatiSifruKluba() == k1->DohvatiSifruKluba())
			{
				m_vKlubovi[i]->m_nBrojBodovaKluba = m_vKlubovi[i]->m_nBrojBodovaKluba + nBrojBodovaDomacina;
			}
			if (m_vKlubovi[i]->DohvatiSifruKluba() == k2->DohvatiSifruKluba())
			{
				m_vKlubovi[i]->m_nBrojBodovaKluba = m_vKlubovi[i]->m_nBrojBodovaKluba + nBrojBodovaGosta;
			}
		}
		Utakmica *u1 = new Utakmica(k1, k2, gd, gg);
		auto odigranaUtakmica = from(m_vRezultati) // provjeri je li utakmica odigrana
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
		cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog kluba nije valjano izvrseno.\n Provjerite datoteku rezultati.xml \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(0);
	}

}

void Liga::OdigrajUtakmice()
{
	system("CLS");
	cout << TextAttr(TextColor::CYAN) << "\n\n\t\tOPCIJA: ODIGRAJ UTAKMICE\n  " << TextAttr(TextColor::WHITE);
	cout << "\t==========================================\n";
	if (m_vKlubovi.size() != 10) // provjeri broj klubova
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tDa bi se utakmice odigrale potrebno je tocno 10 klubova!" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(1);
	}
	for (int i = 0; i < m_vKlubovi.size(); i++)
	{
		if (m_vKlubovi[i]->m_nBrojIgracaKluba < 11) // provjeri broj igraca u klubovima
		{
			cout << "\n\t" << TextAttr(TextColor::RED) << "\tDa bi se utakmice odigrale potrebno je minimalno 11 igraca u svakom klubu!" << TextAttr(TextColor::WHITE);
			cout << "\n\t" << "\tKlub: " << TextAttr(TextColor::CYAN) << m_vKlubovi[i]->DohvatiNazivKluba() << TextAttr(TextColor::WHITE) << " nema dovoljno igraca.";
			SporedniIzbornik(3);
		}
	}
	if (m_vRezultati.size() == 90) // provjeri jesu sve utakmice odigrane
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tSve su utakmice odigrane!" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(7);
	}
	cout << TextAttr(TextColor::CYAN) << "\t\tOdigravanje utakmica.Pricekajte...\n  " << TextAttr(TextColor::WHITE);
	int odigraneUtakmice = 0;
	for (int j = 0; j < m_vKlubovi.size(); j++) // svaki klub igra sa svakim klubom osim sebe samog, vrijedi za gostovanje i kad su domacini
	{
		Klub* klubDomacina = m_vKlubovi[j];
		auto kluboviUGostima = from(m_vKlubovi)
			>> where([&](Klub const *k1)
				{
					return (klubDomacina->DohvatiSifruKluba() != k1->DohvatiSifruKluba());
				})
			>> to_vector();
		for (int i = 0; i < kluboviUGostima.size(); i++)
		{
			Klub* klubGosta = kluboviUGostima[i];
			int nGoloviDomacina = rand() % 7;
			int nGoloviGosta = rand() % 7;
			auto odigranaUtakmica = from(m_vRezultati) // provjeri je li utakmica odigrana
				>> where([&](Utakmica const *u1)
					{
						return (u1->m_oKlubDomacina->DohvatiSifruKluba() == klubDomacina->DohvatiSifruKluba());
					})
				>> where([&](Utakmica const *u1)
					{
						return (u1->m_oKlubGosta->DohvatiSifruKluba() == klubGosta->DohvatiSifruKluba());
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
				UnesiRezultat(klubDomacina, klubGosta, nGoloviDomacina, nGoloviGosta);
				if (m_vRezultati.size() == 90)
				{
					cout << TextAttr(TextColor::CYAN) << "\n\t\tUtakmice su uspjesno odigrane!\n  " << TextAttr(TextColor::WHITE);
					SporedniIzbornik(0);
				}
			}
		}
	}
}

// -------------------------------------------------------------------------
// TABLICE - TextTables.h
// -------------------------------------------------------------------------
void Liga::PrikaziKlubove(vector<Klub*> vKlubovi)
{
	auto vPoredaniKlubovi = from(vKlubovi)
		>> orderby_ascending([&](Klub const *klub) {  return klub->DohvatiSifruKluba(); })
		>> to_vector();
	vKlubovi = vPoredaniKlubovi;
	if (vKlubovi.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "Ne postoji ni jedan klub. \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(1);
	}
	TextTables t('-', '|', '+');
	t.add("Sifra");
	t.add("Naziv kluba");
	t.add("Grad");
	t.endOfRow();
	for (int i = 0; i < vKlubovi.size(); i++)
	{
		t.add(to_string(vKlubovi[i]->DohvatiSifruKluba()));
		t.add(vKlubovi[i]->DohvatiNazivKluba());
		t.add(vKlubovi[i]->DohvatiGradKluba());
		t.endOfRow();
	}
	cout << "\t" << t;
}

void Liga::PrikaziIgrace(vector<Igrac*> vIgraci)
{
	if (m_vIgraci.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tNepostoji ni jedan igrac!\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(4);
	}
	TextTables t('-', '|', '+');
	t.add("Sifra Igraca");
	t.add("Ime");
	t.add("Prezime");
	t.add("Godina Rodjenja");
	t.add("Sifra kluba");
	t.endOfRow();
	for (auto igrac : vIgraci)
	{
		t.add(to_string(igrac->DohvatiSifruIgraca()));
		t.add(igrac->DohvatiImeIgraca());
		t.add(igrac->DohvatiPrezimeIgraca());
		t.add(to_string(igrac->DohvatiGodinuRodjenja()));
		t.add(to_string(igrac->DohvatiSifruKluba()));
		t.endOfRow();
	}
	cout << "\t" << t;
}

void Liga::PrikaziRangListu()
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
	int i = 0;
	for (vector<Klub*>::iterator it = m_vKlubovi.begin();it != m_vKlubovi.end(); ++it)
	{
		t.add(to_string(i + 1));
		t.add((*it)->DohvatiNazivKluba());
		t.add((*it)->DohvatiGradKluba());
		t.add(to_string((*it)->m_nBrojBodovaKluba));
		t.endOfRow();
		i++;
	}
	cout << "\n\t" << t;
	SporedniIzbornik(7);
}
