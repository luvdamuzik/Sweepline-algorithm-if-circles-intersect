//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Forma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <string>
#include <queue>
#include <set>

TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
  boje.push_back(clRed);

  Slika->Canvas->FillRect(Rect(0,0,Slika->Width, Slika->Height));
}
//---------------------------------------------------------------------------
void __fastcall TForm4::SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if(dodavanjeKruga->Checked){
		if(!DrugiPut){
			  Tacka nova(X,Y);
			  centar = nova;
			  DrugiPut = !DrugiPut;
		}else{
			double rad = DuzinaIzmedjuTacaka(centar,Tacka(X,Y));
			Krug novi(centar,rad);
			krugovi.push_back(novi);
			novi.Crtaj(Slika);
			DrugiPut = !DrugiPut;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::GenerisiKrugoveClick(TObject *Sender)
{
  srand(time(NULL));
  int broj_krugova = EditBrojTacaka->Text.ToInt();
  for(int i = 0; i < broj_krugova;i++) {
	  double rad = rand()%100 + 5;
	  Krug nova(Tacka(rand()%(int)(Slika->Width-2*rad+1)+rad,rand()%(int)(Slika->Height-2*rad+1)+rad),rad);
	  krugovi.push_back(nova);
	  nova.Crtaj(Slika);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ImaLiPresjekaClick(TObject *Sender)
{
	priority_queue<pair<Tacka,Krug*>,vector<pair<Tacka,Krug*>>,ManjiKrug> eventi;
	for(int i = 0;i<krugovi.size();i++){
		eventi.push({Tacka((krugovi[i].C.x)+krugovi[i].radius,(krugovi[i].C.y)+krugovi[i].radius),&krugovi[i]});
		eventi.push({Tacka((krugovi[i].C.x)-krugovi[i].radius,(krugovi[i].C.y)+krugovi[i].radius),&krugovi[i]});
		eventi.push({Tacka((krugovi[i].C.x)+krugovi[i].radius,(krugovi[i].C.y)-krugovi[i].radius),&krugovi[i]});
		eventi.push({Tacka((krugovi[i].C.x)-krugovi[i].radius,(krugovi[i].C.y)-krugovi[i].radius),&krugovi[i]});
	}

	set<Polukrug*,StabloKriteriji> stablo;
	bool imaLi = false;

	while(!eventi.empty()){
		auto trenutni = eventi.top();
		eventi.pop();

		for(auto it1 = stablo.begin();it1 != stablo.end();it1++){

		}

		if(trenutni.first == trenutni.second->gornji.A){//pocetna tacka gornjeg polukruga
			stablo.insert(&trenutni.second->gornji);
			//ShowMessage("Pocetna gornja");
			auto it = stablo.find(&trenutni.second->gornji);
			if(it != stablo.begin()){
				auto prethodnik = it;
				prethodnik--;
				if(DaLiSeSijekuKrugovi(**prethodnik,**it)){
					//ShowMessage("Da");
					imaLi = true;
					break;
				}
			}
			if(it != --stablo.end()){
				auto sljedbenik = it;
				sljedbenik++;
				if(DaLiSeSijekuKrugovi(**sljedbenik,**it)){
					//ShowMessage("da");
					imaLi = true;
					break;
				}
			}
		}else if(trenutni.first == trenutni.second->donji.A){//pocetna tacka donjeg polukruga
			stablo.insert(&trenutni.second->donji);
			//ShowMessage("Pocenta donja");
			auto it = stablo.find(&trenutni.second->donji);
			if(it != stablo.begin()){
				auto prethodnik = it;
				prethodnik--;
				if(DaLiSeSijekuKrugovi(**prethodnik,**it)){
					//ShowMessage("Da");
					imaLi = true;
					break;
				}
			}
			if(it != --stablo.end()){
				auto sljedbenik = it;
				sljedbenik++;
				if(DaLiSeSijekuKrugovi(**sljedbenik,**it)){
					//ShowMessage("da");
					imaLi = true;
					break;
				}
			}
		}else if(trenutni.first == trenutni.second->gornji.B){//krajnja tacka gornjeg polukruga
			auto it = stablo.find(&trenutni.second->gornji);
			//ShowMessage("Kranja gornja");
			if(it != stablo.begin() && it != --stablo.end()){
				auto prethodnik = it, sljedbenik = it;
				prethodnik--;
				sljedbenik++;
				if(DaLiSeSijekuKrugovi(**prethodnik,**sljedbenik)){
					//ShowMessage("da");
					imaLi = true;
					break;
				}
			}
			stablo.erase(&trenutni.second->gornji);
		}else{//krajnja tacka donjeg polukruga
			auto it = stablo.find(&trenutni.second->donji);
			//ShowMessage("Kranja donja");
			if(it != stablo.begin() && it != --stablo.end()){
				auto prethodnik = it, sljedbenik = it;
				prethodnik--;
				sljedbenik++;
				if(DaLiSeSijekuKrugovi(**prethodnik,**sljedbenik)){
					//ShowMessage("da");
					imaLi = true;
					break;
				}
			}
			stablo.erase(&trenutni.second->donji);
		}

	}

	if(imaLi){
		ShowMessage("Ima presjeka");
	}else{
        ShowMessage("Nema presjeka");
	}
}
//---------------------------------------------------------------------------

