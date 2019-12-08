#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



int randomnum(int n, int m){
	int numero_casuale = rand() % (m-n+1)+n;
	return numero_casuale;
}


void riempi_vettore(int v[], int n){
	int valmax;
	int valmin;
	cout<<"inserire il valore minore"<<endl;
	cin>>valmin;
	cout<<"inserisci il valore maggiore"<<endl;
	cin >>valmax;

	for(int i=0; i<n; i++){
		v[i]=randomnum(valmin, valmax);
	}
}

void inserisci_numero(int &n){
	do{
		cout<<"inserisci la lunghezza del vettore (un numero compreso tra 1 e 1000"<<endl;
		cin>>n;
	}while(n<=0 || n>=1001);
}

void stampa_vettore(int v[], int n){
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
}

void scambia(int &a, int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

void ordinamento_ingenuo(int v[],int n){
	for(int i=0; i <n-1; i++){
		for(int j=i+1; j<n; j++){
			if(v[i]>v[j]){
				scambia(v[i], v[j]);
			}
		}
	}
}

bool ricerca_binaria(int v[], int n, int x){
	int inizio=0;
	int fine=n-1;
	int medio;
	while(inizio <= fine){
		medio=(inizio + fine )/2;
		if (v[medio]==x){
			return true;
		}
		if(v[medio]>x){
			fine = medio-1;
		}
		else{
			inizio=medio+1;
		}
	}
	return false;
}


int main(){
	srand(time(NULL));


	int n;
	inserisci_numero(n);
	cout<<endl;


	int v[n];
	riempi_vettore(v,n);
	cout<<"vettore:"<<endl;
	stampa_vettore(v,n);
	ordinamento_ingenuo(v,n);
	cout<<endl<<"vettore ordinato:"<<endl;
	stampa_vettore(v,n);



}


