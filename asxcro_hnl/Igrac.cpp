#include "pch.h"
#include "Igrac.h"


Igrac::Igrac(int s, string i, string p, int gr, int sk)
{
	m_nSifraIgraca = s;
	m_sImeIgraca = i;
	m_sPrezimeIgraca = p;
	m_nGodinaRodjenja = gr;
	m_nSifraKluba = sk;
}

Igrac::Igrac()
{
	UcitavanjeIgraci();
}


Igrac::~Igrac()
{
}

int Igrac::DohvatiSifruIgraca() const
{
	return m_nSifraIgraca;
}

string Igrac::DohvatiImeIgraca() 
{
	return m_sImeIgraca;
}

string Igrac::DohvatiPrezimeIgraca()
{
	return m_sPrezimeIgraca;
}

int Igrac::DohvatiGodinuRodjenja()
{
	return m_nGodinaRodjenja;
}

void Igrac::UcitavanjeIgraci()
{
	if (m_vIgraci.size() > 0)
	{
		for (int i = 0; i < m_vIgraci.size(); i++)
		{
			delete m_vIgraci[i];
		}
	}
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
		Igrac *i1 = new Igrac(nSifraIgraca,sImeIgraca,sPrezimeIgraca,nGodinaRodjenja,nSifraKluba);
		m_vIgraci.push_back(i1);
	}
	for(int j = 0; j < m_vKlubovi.size(); j++)
	{
		for (int i = 0; i < m_vIgraci.size(); i++)
		{
			if (m_vKlubovi[j]->DohvatiSifruKluba() == m_vIgraci[i]->DohvatiSifruKluba())
				m_vKlubovi[j]->m_nBrojIgracaKluba++;
		}
	}
}


void Igrac::AzurirajIgrace()
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

void Igrac::DodajIgraca()
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
		int i = 0;
		for (int n = 0; n <= m_vIgraci.size(); n++)
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
	//cpplinq
	auto odabraniKlub = from(m_vKlubovi)
		>> where([&](Klub const *klub)
	{
		return (klub->DohvatiSifruKluba() == a);
	})
		>> select([&](Klub const *klub)
	{
		return klub->DohvatiSifruKluba();
	})
		>> to_vector();
	if (odabraniKlub.size()==1)
	{
		nSifraKluba = odabraniKlub[0];
	}
	else
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n\t\tPokusajte ponovno.\n" << TextAttr(TextColor::WHITE);
		a = IzaberiOpciju();
		goto repeat;
	}
	m_vIgraci.push_back(new Igrac(nSifraIgraca, sImeIgraca, sPrezimeIgraca, nGodinaRodjenja, nSifraKluba));
	try {
		SpremiPromjene(m_vIgraci);
		cout << TextAttr(TextColor::CYAN) << "\n\n\t\tUspjesno ste dodali novog igraca!" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(3);
	}
	catch (int) {
		cout << "\t\t " << TextAttr(TextColor::RED) << " \nNešto nije u redu.\nSpremanje novog klupa nije valjano izvrseno.\n Provjerite datoteku igraci.xml \n\n " << TextAttr(TextColor::WHITE);
		SporedniIzbornik(0);
	}
	
}

void Igrac::ObrisiIgraca()
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
	PrikaziKlubove(m_vKlubovi);//tablica
	int a = IzaberiOpciju();

	//cpplinq
	//select klub
	auto odabraniKlub = from(m_vKlubovi)
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
		cout << "\n\t\tOdabrali ste klub: " << TextAttr(TextColor::CYAN) <<  odabraniKlub[0]->DohvatiNazivKluba() << "\n\n" << TextAttr(TextColor::WHITE);
		cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru igraca kojeg zelite obrisati\n  " << TextAttr(TextColor::WHITE);
		//select igrac
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
		PrikaziIgrace(igraciOdabranogKluba);//tablica
		int b;
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
			try {
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

void Igrac::PrijelazIgraca()
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

	//cpplinq
	//select klub
	auto odabraniKlub = from(m_vKlubovi)
		>> where([&](Klub const *klub)
	{
		return (klub->DohvatiSifruKluba() == a);
	})
		>> to_vector();
	auto kluboviBezOdabranog = from(m_vKlubovi)
		>> where([&](Klub const *klub)
	{
		return (klub->DohvatiSifruKluba() != a);
	})
		>> to_vector();
	if (odabraniKlub.size() == 0)
	{
		cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!\n" << TextAttr(TextColor::WHITE);
		SporedniIzbornik(5);
	}
	else
	{
		system("CLS");
		cout << "\n\t\tOdabrali ste klub: " << TextAttr(TextColor::CYAN) << odabraniKlub[0]->DohvatiNazivKluba() << "\n\n" << TextAttr(TextColor::WHITE);
		cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru igraca na kojem zelite napraviti prijelaz\n  " << TextAttr(TextColor::WHITE);
		//select igrac
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
		PrikaziIgrace(igraciOdabranogKluba);//tablica
		int b;
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
			SporedniIzbornik(5);
		}
		else
		{
			system("CLS");
			cout << "\n\t\tOdabrali ste igraca: " << TextAttr(TextColor::CYAN) << odabraniIgrac[0]->DohvatiImeIgraca() << odabraniIgrac[0]->DohvatiPrezimeIgraca() << "\n\n" << TextAttr(TextColor::WHITE);
			cout << TextAttr(TextColor::CYAN) << "\tOdaberite sifru kluba u kojeg zelite da igrac predje\n  " << TextAttr(TextColor::WHITE);
			PrikaziKlubove(kluboviBezOdabranog);//tablica
			int a = IzaberiOpciju();

			//cpplinq
			//select klub
			auto odabraniKlub = from(kluboviBezOdabranog)
				>> where([&](Klub const *klub)
			{
				return (klub->DohvatiSifruKluba() == a);
			})
				>> to_vector();

			if (odabraniKlub.size() == 0)
			{
				cout << "\n\t" << TextAttr(TextColor::RED) << "\tKlub sa unesenom sifrom ne postoji!" << TextAttr(TextColor::WHITE);
				SporedniIzbornik(5);
			}
			else
			{
				odabraniIgrac[0]->m_nSifraKluba = odabraniKlub[0]->DohvatiSifruKluba();
				igraciBezOdabranog.push_back(odabraniIgrac[0]);
				m_vIgraci = igraciBezOdabranog;
				try {
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

void Igrac::SpremiPromjene(vector<Igrac*> vIgraci)
{
	auto vSortiraniIgraci = from(vIgraci)
		>> orderby_ascending([&](Igrac const *i) {  return i->DohvatiSifruIgraca(); })
		>> to_vector();
	vIgraci = vSortiraniIgraci;
		m_docIgraci.LoadFile("igraci.xml");
		m_eIgraci = m_docIgraci.FirstChildElement("Igraci");
		m_eIgraci->DeleteChildren();
		for (int i = 0; i < m_vIgraci.size(); i++)
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

void Igrac::PrikaziIgrace(vector<Igrac*> vIgraci)
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