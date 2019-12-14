#include <iostream>
#include "libreria_vettori.h"
#include <time.h>
#include <process.h>

using namespace std;

void stampaMenu(){
	cout<<"0. Impostare i valori random min e random max (i predefiniti sono 1 e 10)"<<endl;
	cout<<"1. Uscita"<<endl;
	cout<<"2. visualizza il vettore."<<endl;
	cout<<"3. Aumenta del 10% ogni elemento del vettore."<<endl;
	cout<<"4. Mostra l'elemento massimo."<<endl;
	cout<<"5. Mostra quante volte e' presente il numero maggiore."<<endl;
	cout<<"6. Mostra gli elementi di indice pari."<<endl;
	cout<<"7. Visualizza il vettore e specifica se pari o dispari."<<endl;
	cout<<"8. Ordina il vettore dal piu' piccolo al piu' grande."<<endl;
	cout<<"9. Ordina il vettore dal piu' grande al piu' piccolo."<<endl;
	cout<<"10. Somma di tutti gli elementi del vettore"<<endl;
	cout<<"11. Calcolare la media degli elementi del vettore"<<endl;
	cout<<"12. Rimuovere un elemento dalla lista"<<endl;



}

void menu(int v[], int n ){
	int scelta, c,x;
	int min=0;
	int max=10;
	do{	
		stampaMenu();


		cout<<"inserisci scelta"<<endl;
		cin>>scelta;
		system("cls");

		switch(scelta){
			case 0:
				cout<<"inserire il valore random min"<<endl;
				cin>>min;
				setRandomMin(min);
				cout<<"inserire il valore random max"<<endl;
				cin>>max;
				setRandomMax(max);
				riempiVettoreRandom(v,n);
				cout<<endl;
				break;

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

			case 8:
				bubbleSort(v,n, false);
				stampaVettore(v,n);
				break;

			case 9:
				bubbleSort(v,n, true);
				stampaVettore(v,n);
				break;

			case 10:
				cout<<"la somma degli elementi del vettore e' "<<sommaVettore(v,n)<<endl;
				break;

			case 11:
				cout<<"la media degli elementi del vettore e' "<<media(v,n)<<endl;
				break;

			case 12:
				cout<<endl<<"che elemento vuoi rimuovere dalla lista?"<<endl;
				cin>>x;

				rimuoviElemento(v,n,presente(v,n,x));
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
