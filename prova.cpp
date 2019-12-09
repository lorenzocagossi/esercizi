#include <iostream>
#include "libreria_vettori.h"
#include <time.h>

using namespace std;

void stampaMenu(){
	cout<<"0. Uscita"<<endl;
	cout<<"1. Creazione random del vettore"<<endl;
	cout<<"2. Stampa vettore"<<endl;
	cout<<"3. Riordina il vettore"<<endl;
}

void menu(int v[], int n ){
	int scelta;
	do{
		stampaMenu();

		cout<<"inserisci scelta"<<endl;
		cin>>scelta;

		switch(scelta){
			case 0:
				cout<<"uscita"<<endl;
				cout<<endl;
				break;
			case 1:
				riempiVettoreRandom(v,n);
				break;
			case 2:
				stampaVettore(v,n);
				cout<<endl;
				break;
			case 3:
				ordinamentoIngenuo(v,n);
				break;
			case 4:
				//cose
				break;
			default:
				cout<<"opzione non valida"<<endl;
				break;

		}
		cout<<endl;
	}

	while(scelta!=0);
}


int main(){
	srand(time(NULL));
	setDimensioneMax(10000);
	setRandomMin(1);
	setRandomMax(100);

	int n;
	cout<<"quanto deve essere lungo il vettore?"<<endl;
	cin>>n;
	int v[n];
	menu(v,n);

}
