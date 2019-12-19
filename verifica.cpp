#include <iostream>
#include "libreria_vettori.h"
#include <time.h>
#include <process.h>

using namespace std;


void stampamenu(){
	cout<<"1. Uscita."<<endl;
	cout<<"2. Visualizza il vettore."<<endl;
	cout<<"3. Diminuisci del 5% ogni conto con credito minore di 30000."<<endl;
	cout<<"4. Mostrare il credito di un conto a scelta."<<endl;
	cout<<"5. Aumentare di un valore V il credito di un conto a scelta C."<<endl;
	cout<<"6. Mostra l'indice del conto corrente con il valore maggiore."<<endl;
	cout<<"7. Scegliere un conto C, quel conto verrà azzerato e il suo valore verrà diviso equalmente tra tutti gli altri conti."<<endl;
	cout<<"8. Capire se i crediti dei conti sono in ordine crescente"<<endl;
}

void menu(float v[], int n){

	int scelta,somma,C,V;
	int crescente=1;

	do{
		stampamenu();
		cout<<"inserisci scelta"<<endl;
		cin>>scelta;
		system("cls");

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
					if(v[i]<30000){
						v[i]-=(v[i]/100*5);
					}
				}
				break;

			case 4:
				cout<<"inserire l'indice del conto da visualizzare"<<endl;
				cin>>C;
				cout<<"il credito del conto "<<C<<" e' "<<v[C]<<endl<<endl;

				break;

			case 5:
				cout<<"inserire l'indice del conto"<<endl;
				cin>>C;
				cout<<"inserire l'importo da aggiungere al conto"<<endl;
				cin>>V;
				v[C]+=V;
				break;

			case 6:
				for(int i=0; i<n; i++){	
						if (v[i]==maggiore(v,n)){
							cout<<"l'indice del conto piu' alto e' "<<i<<endl<<endl;
						}
					}

			break;

			case 7:
				cout<<"inserire l'indice del conto C da azzerare"<<endl
				cin>>C;
				aggiunta=v[C]/(n-1);
				for(int i=0; i<n; i++){
					v[i]+=aggiunta;
				}
				v[C]=0;

				break;

			case 8:
				for(int i=0; i<n; i++){
					if(v[i+1]>=v[i]){
						crescente+=1;
					}
				}
				if(crescente==n){
					cout<<"i conti sono in ordine crescente"<<endl;
				}
				else{
					cout<<"i conti non sono in ordine crescente"<<endl;
				}



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

	float v[n];
	riempiVettoreRandom(v,n);
	menu(v,n);


}
