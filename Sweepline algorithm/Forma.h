//---------------------------------------------------------------------------

#ifndef FormaH
#define FormaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
#include <list>
#include "pomocna.h"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TImage *Slika;
	TEdit *EditBrojTacaka;
	TRadioButton *dodavanjeKruga;
	TRadioButton *DodavanjeKruga;
	TButton *GenerisiKrugove;
	TButton *ImaLiPresjeka;
	void __fastcall SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall GenerisiKrugoveClick(TObject *Sender);
	void __fastcall ImaLiPresjekaClick(TObject *Sender);
private:
  vector<Tacka> tacke;
  vector<Krug> krugovi;
  bool DrugiPut = false;
  Tacka centar;
  vector<int> boje;

  public:
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
