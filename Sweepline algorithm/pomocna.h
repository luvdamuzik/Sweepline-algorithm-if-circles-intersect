//---------------------------------------------------------------------------

#ifndef pomocnaH
#define pomocnaH
#include <algorithm>
#include <vector>
using namespace std;

struct Tacka {
	double x,y;
	Tacka(double X = 0, double Y = 0):x(X),y(Y) {}
    void Crtaj(TImage*);
};

struct Duz{
	Tacka A,B;
	Duz(Tacka A,Tacka B):A(A),B(B){}
    void Crtaj(TImage*,int boja);
};

bool operator<(Tacka,Tacka);
bool operator==(Tacka,Tacka);

struct Polukrug{
	Tacka A,B,C;
	double radius;
	Polukrug(Tacka A,Tacka B,Tacka C,double radius):A(A),B(B),C(C),radius(radius){}
};

struct Krug{
	Tacka C;
	double radius;
	Polukrug gornji,donji;
	Krug(Tacka C, double radius):C(C),radius(radius),
		gornji(Tacka(C.x-radius,C.y-radius),Tacka(C.x+radius,C.y-radius),C,radius),
		donji(Tacka(C.x-radius,C.y+radius),Tacka(C.x+radius,C.y+radius),C,radius){}
	void Crtaj(TImage*);
};


int Orijentacija(Tacka A, Tacka B, Tacka C);
double DuzinaIzmedjuTacaka(Tacka A,Tacka B);
Polukrug NapraviPolukrugGornji(Krug A);
Polukrug NapraviPolukrugDonji(Krug A);
bool DaLiSeSijekuKrugovi(Polukrug A,Polukrug B);
bool DaLiSuIsti(Polukrug A,Polukrug B);

class ManjiKrug{
	public:
	bool operator()(pair<Tacka,Krug*> &prva,pair<Tacka,Krug*> &druga){
		return druga.first < prva.first;
	}
};


class StabloKriteriji{
	public:
	bool operator()(Polukrug *prvi,Polukrug *drugi) const{
		if(prvi->A.x < drugi->A.x){
			return Orijentacija(drugi->A,prvi->A,prvi->B)<0;
		}
		else return Orijentacija(prvi->A,drugi->A,drugi->B)>0;

	}
};

//---------------------------------------------------------------------------
#endif
