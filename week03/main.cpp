#include "../std_lib_facilities.h"

class B1 {
 	public:
   		virtual void vf(){ cout << "B1::vf()\n"; }
   		void f(){ cout << "B1::f()\n"; }
   		virtual void pvf(){ cout << "B1::pvf()\n"; }	//5.feladat: ezt is felulirta a D1-ben levo pfv()
};

class D1:public B1 {
    public:
    	void vf() override { cout << "D1::vf()\n"; }
    	void f() { cout << "D1::f()\n"; }		//4.feladat: ez is felulirja a B1::f()-et
    	void pvf() { cout << "D1::pvf()\n"; }
};

class D2:public D1 {
    public:
    	void pvf() override { cout << "D2::pvf()\n"; }	//6.feladat: felulirja a B1:pvf()-et
};

class B2 {
	public:
		virtual void pvf() = 0;
};

class D21 : public B2{
	public:
		string text; 
		void pvf() override { cout << text << endl; }
};

class D22 : public B2{
	public:
		int n; 
		void pvf() override { cout << n << endl; }
		void f(B2& b) { b.pvf(); }  
};
    	

int main(){

	/*	1-3 Feladat
	//1.feladat
	B1 b1;
	b1.vf();
    b1.f();

    //2.feladat
    D1 d1;
	d1.vf();	//2.feladat: felulirja a B1.vf()-et
    d1.f();		//2.feladat: kiirja a B1.f()-et es nem irja felul

	//3.feladat
    B1& ref = d1;
	ref.vf();	
	ref.f();*/

	/*	4 Feladat
	//1.feladat
	B1 b1;
	b1.vf();
    b1.f();

    //2.feladat
    D1 d1;
	d1.vf();
	d1.f();	

	//3.feladat
    B1& ref = d1;
	ref.vf();	
	ref.f();	//4.feldat: a B1::f()-et irja ki*/

	/*	5 Feladat
	//1.feladat
	B1 b1;
	b1.vf();
    b1.f();
    b1.pvf();

    //2.feladat
    D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();	

	//3.feladat
    B1& ref = d1;
	ref.vf();	
	ref.f();	
	ref.pvf();*/

	/*6.feladat
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();*/

	
	//7.feladat
	D21 d21;
	d21.text = "Something";

	D22 d22;
	d22.n = 15;

	d22.f(d21);
	d22.f(d22);

	return 0;
}