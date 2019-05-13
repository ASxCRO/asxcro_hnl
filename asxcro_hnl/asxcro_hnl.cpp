#include "pch.h"
#include "Klub.h"
#include "Igrac.h"
#include "Utakmica.h"

void UlazUProgram();
void NormalniFont();

int main()
{
	UlazUProgram();
}

void UlazUProgram()
{
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
	NormalniFont();
	cout << "\n\tUcitavanje...";
	Utakmica *u1 = new Utakmica();
	Sleep(1000);
	u1->GlavniIzbornik();
}


void NormalniFont()
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