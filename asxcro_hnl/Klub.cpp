#include "pch.h"
#include "Klub.h"
#include "Utakmica.h"

Klub::Klub(int sk, string n, string g)
{
	m_nSifraKluba = sk;
	m_sNazivKluba = n;
	m_sGradKluba = g;
}

Klub::Klub()
{
	UcitavanjeKlubovi();
}


Klub::~Klub()
{}

int Klub::DohvatiSifruKluba() const
{
	return m_nSifraKluba;
}

string Klub::DohvatiNazivKluba()
{
	return m_sNazivKluba;
}

string Klub::DohvatiGradKluba()
{
	return m_sGradKluba;
}

void Klub::SporedniIzbornik(int b)
{
	Igrac* i1 = new Igrac();
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
	if ((b != 6) && (b > 0))
	{
		cout << "\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[W]" << TextAttr(TextColor::WHITE) << " za povratak u glavni izbornik\t\n";
	}
	else
	{
		cout << "\n\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[Q]" << TextAttr(TextColor::WHITE) << " za povratak u glavni izbornik \t\n";
	}

	cout << "\t\tPritisnite " << TextAttr(TextColor::CYAN) << "[X]" << TextAttr(TextColor::WHITE) << " za izlazak iz programa\t\n";
	int a = IzaberiOpciju();

repeat:
	switch (a)
	{
		case 113: {
			cout << TextAttr(TextColor::CYAN) << "\n\t\tSpremanje.." << TextAttr(TextColor::WHITE);
			Utakmica* u1 = new Utakmica();
			u1->GlavniIzbornik();
			break;
		}
		case 119: {
			if ((b != 6) && (b > 0))
			{
				Utakmica* u1 = new Utakmica(1);
				Igrac* i1 = new Igrac();
				Klub *k1 = new Klub();
				u1->GlavniIzbornik();
			}
			else
			{
				a = KriviOdabir();
				goto repeat;
			}
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
				i1->DodajIgraca();
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
				i1->ObrisiIgraca();
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
				i1->PrijelazIgraca();
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
				Utakmica* u1 = new Utakmica();
				Klub* k1 = u1->DohvatiKlubDomacina();
				Klub* k2 = u1->DohvatiKlubGosta(k1);
				int nBrojGolovaDomacina = u1->DohvatiGoloveDomacina(k1, k2);
				int nBrojGolovaGosta= u1->DohvatiGoloveGosta();
				u1->UnesiRezultat(k1, k2,nBrojGolovaDomacina, nBrojGolovaGosta);
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

int  Klub::IzaberiOpciju() const
{
	int a = 0;
	bool keepGoing = true;
	char key = ' ';
	while (keepGoing)
	{
		cout << "\n\t\tVas izbor: ";
		while (_kbhit() == 0) {
			key = _getch();
			if (int(key) > 100) //ascii
			{
				a = int(key);
			}
			else {
				a = int(key) - 48;
			}
			keepGoing = false;
			break;
		}
		return a;
	}
}

int Klub::KriviOdabir()
{
	cout << "\t\t " << TextAttr(TextColor::RED) << " \n\t\tKrivi odabir!\n\t\tPokusajte ponovno. \n\n " << TextAttr(TextColor::WHITE);
	int a = IzaberiOpciju();
	return a;
}

void Klub::UcitavanjeKlubovi()
{
	if (m_vKlubovi.size() > 0)
	{
		for (int i = 0; i < m_vKlubovi.size(); i++)
		{
			delete m_vKlubovi[i];
		}
	}

	m_docKlubovi.LoadFile("klubovi.xml");
	m_eKlubovi = m_docKlubovi.FirstChildElement("Klubovi");
	XMLElement *eKlub;
	for (eKlub = m_eKlubovi->FirstChildElement("klub"); eKlub != NULL; eKlub = eKlub->NextSiblingElement())
	{
		string sNazivKluba = eKlub->Attribute("nazivKluba");
		string sGradKluba = eKlub->Attribute("gradKluba");
		int nKlubID = atoi(eKlub->Attribute("klubID"));
		Klub *k1 = new Klub(nKlubID,sNazivKluba,sGradKluba);
		m_vKlubovi.push_back(k1);
	}
}

void Klub::AzurirajKlub()
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

void Klub::DodajKlub()
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
		for (int n = 0; n < m_vKlubovi.size(); n++) 
		{
			if (i >= m_vKlubovi.size()-1)
			{
				cout << "\tSifra kluba: " << n+1 << endl;
				nSifraKluba = n+1;
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
		try {
			SpremiPromjene(m_vKlubovi);
			cout << TextAttr(TextColor::CYAN) << "\n\n\tUspjesno ste dodali novi klub!" << TextAttr(TextColor::WHITE);
			SporedniIzbornik(1);
		}
		catch (int){
			cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog klupa nije valjano izvrseno.\n Provjerite datoteku klubovi.xml \n\n " << TextAttr(TextColor::WHITE);
			SporedniIzbornik(0);
		}
	}	
}

void Klub::IzbrisiKlub()
{
	Igrac* i1 = new Igrac;
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

	//cpplinq
	//brisanje kluba
	auto kluboviBezOdabranog = from(m_vKlubovi)
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

	//brisanje igraca
	auto igraciBezOdabranih = from(i1->m_vIgraci)
		>> where([&] (Igrac const *igracina)
	{
		return (igracina->DohvatiSifruKluba() != a);
	})
		>> orderby_ascending([&](Igrac const *igracina)
	{	
		return (igracina->DohvatiSifruIgraca());
	}
		)
		>> to_vector();

	if (m_vKlubovi.size() == kluboviBezOdabranog.size())
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
	}
	else
	{
		m_vKlubovi = kluboviBezOdabranog;
		i1->m_vIgraci = igraciBezOdabranih;
		this->SpremiPromjene(m_vKlubovi);
		i1->SpremiPromjene(i1->m_vIgraci);
		cout << TextAttr(TextColor::CYAN) << "\n\n\t\tUspjesno ste izbrisali igrace kluba i klub pod sifrom " << a << TextAttr(TextColor::WHITE);
	}
	SporedniIzbornik(2);
}

void Klub::SpremiPromjene(vector<Klub*> vKlubovi)
{
	sort(vKlubovi.begin(), vKlubovi.end(), [](const Klub* lhs, const Klub* rhs) {
		return lhs->DohvatiSifruKluba() < rhs->DohvatiSifruKluba();
	});
	m_eKlubovi->DeleteChildren();
	for (int i = 0; i < m_vKlubovi.size(); i++)
	{
		XMLElement *noviKlub = m_docKlubovi.NewElement("klub");
		noviKlub->SetAttribute("nazivKluba", (m_vKlubovi[i]->DohvatiNazivKluba()).c_str());
		noviKlub->SetAttribute("klubID", (m_vKlubovi[i]->DohvatiSifruKluba()));
		noviKlub->SetAttribute("gradKluba", (m_vKlubovi[i]->DohvatiGradKluba()).c_str());
		m_eKlubovi->LinkEndChild(noviKlub);
	}
	m_docKlubovi.SaveFile("klubovi.xml");
}

void Klub::PrikaziKlubove(vector<Klub*> vKlubovi)
{
	if (m_vKlubovi.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "Ne postoji ni jedan klub. \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(1);
	}
	TextTables t('-', '|', '+');
	t.add("Sifra");
	t.add("Naziv kluba");
	t.add("Grad");
	t.endOfRow();
	for (int i=0; i < vKlubovi.size(); i++)
	{
		t.add(to_string(vKlubovi[i]->DohvatiSifruKluba()));
		t.add(vKlubovi[i]->DohvatiNazivKluba());
		t.add(vKlubovi[i]->DohvatiGradKluba());
		t.endOfRow();
	}
	cout << "\t" <<  t;
}

void Klub::FullScreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}
