#include <iostream>
#include "libreria_vettori.h"
#include <time.h>
#include <process.h>

using namespace std;


void stampamenu(){
	cout<<"1. Uscita."<<endl;
	cout<<"2. Visualizza il vettore."<<endl;
	cout<<"3. Aumenta di 100 tutti i valori maggiori di 5000."<<endl;
	cout<<"4. Conta quanti sono i conti tra 6000 e 7000 compresi."<<endl;
	cout<<"5. Mostra l'indice del conto con il valore maggiore."<<endl;
	cout<<"6. Mostra tutti i conti con i valori minori del conto con indice h."<<endl;
	cout<<"7. Conta quante volte un conto e' maggiore del suo precedente."<<endl;
}

void menu(int v[], int n){

	int scelta,h;
	int c=0;
	int d=0;

	do{
		stampamenu();
		cout<<"inserisci scelta"<<endl;
		cin>>scelta;
		//system("cls");

		switch(scelta){
			case 1:
				cout<<"uscita"<<endl;
				cout<<endl;
				break;

			case 2:
				stampaVettore(v,n);
				cout<<endl<<endl;
				break;

			case 3:
				for (int i=0; i<n; i++){
					if(v[i]>5000){
						v[i]+=100;
					}
				}
				break;

			case 4:
				for(int i=0; i<n; i++){
					if(v[i]>5999 and v[i]<7001){
						c++;
					}
				}
				cout<<"il numero di conti compresi tra 6000 e 7000 e' "<<c<<endl<<endl;
				break;

			case 5:
				for(int i=0; i<n; i++){	
						if (v[i]==maggiore(v,n)){
							cout<<"l'indice del valore piu' alto e' "<<i<<endl<<endl;
						}
					}

				break;

			case 6:
				cout<<"inserisci l'indice del conto"<<endl;
				cin>>h;
				for(int i=0; i<n; i++){
					if(v[i]<v[h]){
						cout<<v[i]<<endl<<endl;
					}
				}
			break;

			case 7:
				d=0;
				for (int i=0; i<n; i++){
					if(v[i+1]>v[i]){
						d++;
					}
				}


				if(d==1){
					cout<<"un conto e' maggiore del suo precedente una volta"<<endl<<endl;
				}
				else{
					cout<<"un conto e' maggiore del suo precedente "<<d<<" volte"<<endl<<endl;
				}
				break;


			default:
				cout<<"scelta non valida"<<endl;
				break;

			cout<<endl;
		}
	}
	while(scelta!=1);
}


int main(){
	srand(time(NULL));
	setDimensioneMax(10000);
	setRandomMin(1000);
	setRandomMax(10000);

	int n;
	cout<<"Quanto conti deve contenere il vettore?"<<endl;
	cin>>n;

	int v[n];
	riempiVettoreRandom(v,n);
	menu(v,n);


}
