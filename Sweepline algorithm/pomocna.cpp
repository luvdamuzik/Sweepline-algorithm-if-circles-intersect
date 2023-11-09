//---------------------------------------------------------------------------

#pragma hdrstop

#include "pomocna.h"

void Tacka::Crtaj(TImage* slika) {
	slika->Canvas->Ellipse(Rect(x-3,y-3,x+3, y+3));
}

void Tacka::Duz(TImage* slika,int boja) {
	slika->Canvas->MoveTo(A.x,A.y);

	slika->Canvas->Ellipse(Rect(x-3,y-3,x+3, y+3));
}

bool operator<(Tacka A, Tacka B) {
	if(A.x < B.x) return true;
	if(A.x == B.x) return A.y < B.y;
	return false;
}


void Krug::Crtaj(TImage* slika){
	slika->Canvas->Brush->Style = bsClear;
	slika->Canvas->Ellipse(Rect(C.x-radius,C.y-radius,C.x+radius,C.y+radius));
}
/////////////////////////////////////////////////////////////

int Orijentacija(Tacka A, Tacka B, Tacka C) {
	int P = A.x*(B.y-C.y) + B.x*(C.y-A.y)+ C.x*(A.y - B.y);
	if(P > 0) return -1;
	else if(P < 0) return 1;
	else return 0;
}

/////////////////////////////////////////////////////////////

bool operator==(Tacka A, Tacka B) {
    return A.x == B.x && A.y == B.y;
}

/////////////////////////////////////////////////////////////


double DuzinaIzmedjuTacaka(Tacka A,Tacka B){
	return sqrt(pow((B.x - A.x),2) + pow((B.y-A.y),2));
}

Polukrug NapraviPolukrugGornji(Krug A){
	Polukrug nova(Tacka(A.C.x-A.radius,A.C.y-A.radius),Tacka(A.C.x+A.radius,A.C.y-A.radius),A.C,A.radius);
	return nova;
}

Polukrug NapraviPolukrugDonji(Krug A){
	Polukrug nova(Tacka(A.C.x-A.radius,A.C.y+A.radius),Tacka(A.C.x+A.radius,A.C.y+A.radius),A.C,A.radius);
	return nova;
}

bool DaLiSuIsti(Polukrug A,Polukrug B){
	return A.C.x == B.C.x && A.C.y == B.C.y && A.radius == B.radius;
}

bool DaLiSeSijekuKrugovi(Polukrug A,Polukrug B){
	double distanca = DuzinaIzmedjuTacaka(A.C,B.C);
	double zbir = (A.radius + B.radius);
	double epsilon = 0.000001;
	if(DaLiSuIsti(A,B)){
		//ShowMessage("Isti su");
		return false;
	}else if(distanca - abs(B.radius-A.radius)<-1){
		//ShowMessage("D<=abs(r1-r2)");
		return false;
	}else if(distanca > (A.radius + B.radius)){
		//ShowMessage("D>r1+r2");
		return false;
	}else{
		//ShowMessage("else");
		return true;
	}
}



#pragma package(smart_init)
