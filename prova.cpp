#include <iostream>
#include "libreria_vettori.h"
#include <time.h>

using namespace std;

void stampaMenu(){
	cout<<"1. Uscita"<<endl;
	cout<<"2. visualizza il vettore."<<endl;
	cout<<"3. Aumenta del 10% ogni elemento del vettore."<<endl;
	cout<<"4. Mostra l'elemento massimo."<<endl;
	cout<<"5. Mostra quante volte e' presente il numero maggiore."<<endl;
	cout<<"6. Mostra gli elementi di indice pari."<<endl;
	cout<<"7. Visualizza il vettore e specifica se pari o dispari."<<endl;

}

void menu(int v[], int n ){
	int scelta;
	int c;
	do{
		stampaMenu();

		cout<<"inserisci scelta"<<endl;
		cin>>scelta;

		switch(scelta){
			case 1:
				cout<<"uscita"<<endl;
				cout<<endl;
				break;

			case 2:
				stampaVettore(v,n);
				cout<<endl;
				break;

			case 3:
				for(int i=0; i<n; i++){
					v[i]+=(v[i]/10);
				}
				cout<<endl;
				break;

			case 4:
				cout<<maggiore(v,n)<<endl;
				break;

			case 5:
				c=0;
				for(int i=0; i<n; i++){	
					if (v[i]==minore(v,n)){
						c++;
					}
				}
				if (c==1){
					cout<<"il numero maggiore e' presente "<<c<<" volta"<<endl;
				}
				else {
					cout<<"il numero maggiore e' presente "<<c<<" volte"<<endl;
				}
				break;

			case 6:
				for(int i=0; i<n; i++){
					if(i%2!=0){
						cout<<v[i]<<" ";
					}
				}
				cout<<endl;
				break;

			case 7:
				for(int i=0; i<n; i++){
					if(v[i]%2==0){
						cout<<v[i]<<" --> pari"<<endl;
					}
					else{
						cout<<v[i]<<" --> dispari"<<endl;
					}
				}
				break;

			default:
				cout<<"opzione non valida"<<endl;
				break;

		}
		cout<<endl;
	}

	while(scelta!=1);
}


int main(){
	srand(time(NULL));
	setDimensioneMax(10000);
	setRandomMin(1);
	setRandomMax(10);
	

	int n;
	cout<<"quanto deve essere lungo il vettore?"<<endl;
	cin>>n;
	int v[n];
	riempiVettoreRandom(v,n);
	menu(v,n);

}
