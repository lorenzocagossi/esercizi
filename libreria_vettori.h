
//LorenzoCagossi

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


int random_min = 0;
int random_max = 100;
int DimesioneMax = 1000;
bool random_inizializzato = false;


int minore(int v[], int n){
	int min = v[0];
	for (int i=0; i<n; i++){
		if (v[i] < min){
			min = v[i];
		}
	}
	return min;
}

float minore(float v[], int n){
	float min = v[0];
	for (int i=0; i<n; i++){
		if (v[i] < min){
			min = v[i];
		}
	}
	return min;
}

int maggiore(int v[], int n){
	int max = v[0];
	for (int i=0; i<n; i++){
		if (v[i] > max)
			max = v[i];
	}
	return max;
}

float maggiore(float v[], int n){
	float max = v[0];
	for (int i=0; i<n; i++){
		if (v[i] > max)
			max = v[i];
	}
	return max;
}


int randomNM(int n, int m){
	int numeroRandom = rand()%(m-n+1)+n;
	return numeroRandom;
}

float randomNM_float(int n, int m){
	int dividendo = randomNM(n, m);
	int divisore = randomNM(0,99);
	return dividendo + (float) divisore / 100;
}

int random0N(int n){
	int numeroRandom = rand()%(n+1);
	return numeroRandom;
}

float random0N_float(int n){
	float numeroRandom =rand()%(n*10+1)/10.0;
	return numeroRandom;
}

void setRandomMin(int min){
	random_min = min;
}

void setRandomMax(int max){
	random_max = max;
}


void setDimensioneMax(int x){
	int DimensioneMax = x;
}

void riempiVettore(int v[], int n){
	for (int i=0; i<n; i++){
		cin >> v[i];
	}
}

void riempiVettore(float v[], int n){
	for (int i=0; i<n; i++){
		cin >> v[i];
	}
}

void riempiVettoreRandom(int v[], int n){
	for (int i=0; i<n; i++){
		v[i] = randomNM(random_min, random_max);
	}
}

void riempiVettoreRandom(float v[], int n){
	for (int i=0; i<n; i++){
		v[i] = randomNM_float(random_min, random_max);
	}
}

bool aggiungiElemento(int v[], int &n){
	int DimensioneMax = 1000;
	if (n == DimensioneMax){
		return false;
	}
	cin >> v[n];
	n++; 
	return true;
}

bool aggiungiElemento(float v[], int &n){
	int DimensioneMax = 1000;
	if (n == DimensioneMax){
		return false;
	}
	
	cin >> v[n];
	n++;
	return true;
}

bool rimuoviElemento(int v[], int &n, int pos){
	if (n == 0){
		return false;
	}
	for (int i=pos; i<n; i++){
		v[i] = v[i + 1];
	}
	n = n-1;
	return true;
}

bool rimuoviElemento(float v[], int &n, int pos){
	if (n == 0){
		return false;
	}
	for (int i=pos; i<n; i++){
		v[i] = v[i + 1];
	}
	n = n-1;
	return true;
}


void stampaVettore(float v[], int n){
	for (int i=0; i<n; i++){
		cout << v[i] << " ";
	}
}

void stampaVettore(int v[], int n){
	for (int i=0; i<n; i++){
		cout << v[i] << " ";
	}
}


void ordinamentoIngenuo(int v[], int n, bool inverso = false){
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (v[i] > v[j] && inverso == false){
				swap(v[i], v[j]);
			}
			if (v[i] < v[j] && inverso == true){
				swap(v[i], v[j]);
			}
		}
	}
}

void ordinamentoIngenuo(float v[], int n, bool inverso = false){
	
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (v[i] > v[j] && inverso == false){
				swap(v[i], v[j]);
			}
			if (v[i] < v[j] && inverso == true){
				swap(v[i], v[j]);
			}
		}
	}
}

void bubbleSort(int v[], int n, bool inverso){
	
	for(int j=0; j<n-1 ;j++)
		for(int i=0; i<n-1; i++)
			if(v[i] > v[i+1] && inverso == false){
				swap(v[i], v[i+1]);
			}
			else if (v[i] < v[i+1] && inverso == true){
				swap(v[i], v[i+1]);
			}
}

void bubbleSort(float v[], int n, bool inverso){
	
	for(int j=0; j<n-1 ;j++)
		for(int i=0; i<n-1; i++)
			if(v[i] > v[i+1] && inverso == false){
				swap(v[i], v[i+1]);
			}
			else if (v[i] < v[i+1] && inverso == true){
				swap(v[i], v[i+1]);
			}
}


int sommaVettore(int v[], int n){
	int sum = 0;
	for (int i=0; i<n; i++){
		sum += v[i];
	}
	return sum;
}

float sommaVettore(float v[], int n){
	float sum = 0;
	for (int i=0; i<n; i++){
		sum += v[i];
	}
	return sum;
}

float media(int v[], int n){
	int sum = sommaVettore(v, n);
	return (float) sum / (float) n;
}

float media(float v[], int n){
	float sum = sommaVettore(v, n);
	return (float) sum/ (float) n;
}

void inverti(int v[], int n){
	for (int i=0; i<n/2; i++){
		swap(v[i], v[(n-1)-i]);
	}
}

void inverti(float v[], int n){
	for (int i=0; i<n/2; i++){
		swap(v[i], v[(n-1)-i]);
	}
}

bool ricercaBinaria(int v[], int n, int x){
	int i = 0;
	int f = n-1;
	while (i<=f){
		int mid = (i+f)/2;
		if (v[mid] == x){
			return true;
		}
		if (v[mid] > x){
			f = mid -1;
		}
	else {
			i = mid +1;
		}
	}
	return false;
}

bool ricercaBinaria(float v[], int n, int x){
	int i = 0;
	int f = n-1;
	while (i<=f){
		int mid = (i+f)/2;
		if (v[mid] == x){
			return true;
		}
		if (v[mid] > x){
			f = mid -1;
		}
		else {
			i = mid +1;
		}
	}
	return false;
}

int presente(int v[], int n, int x){
	for (int i=0; i<n; i++){
		if (v[i] == x)
			return i;
	}
	return -1;
}

int presente(float v[], int n, float x){
	for (int i=0; i<n; i++){
		if (v[i] == x)
			return i;
	}
	return -1;
}


int posizioneMaggiore(int v[], int n){	
	int max = maggiore(v, n);
	return presente(v, n, max);
}
int posizioneMaggiore(float v[], int n){
	
	float max = maggiore(v, n);
	return presente(v, n, max);
}

int posizioneMinore(int v[], int n){	
	int min = minore(v, n);
	return presente(v, n, min);
}

int posizioneMinore(float v[], int n){	
	float min = minore(v, n);
	return presente(v, n, min);
}
