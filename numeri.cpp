#include <iostream>
#include <time.h>
#include <cstdlib>
#include <time.h>

using namespace std;


int random(int n, int m){
	int num=rand() % (m-n+1) +n;
	return num;	
}

void scambia(int &a, int &b){
	int box=a;
	a=b;
	b= box;
}

int main(){
	srand(time(NULL));
	int n;
	cout<<"qanti numeri ci sono ?"<<endl;
	cin>>n;

	int min=1;
	int max=0;

	while(min>max){
		cout<<"qual e' il numero piu' piccolo?"<<endl;
		cin>>min;
		cout<<"qual e' il numero piu' grande?"<<endl;
		cin>>max;
		if(min>max){
			cout<<"il numero minimo selezionato e' piu' grande di quello maggiore. Riprova"<<endl;
		}
	}

	int v[n];
	for(int i=0; i<n; i++){
		v[i]=random(min,max);
	}
		
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++)
			if(v[i]>v[j])
				scambia(v[i],v[j]);
	}
				
	for(int k=0;k<n;k++){
		cout<<v[k]<< " ";
	}

	cout<<endl<<"che numero vuoi cercare?"<<endl;
	int x;
	cin>>x;

	int i=0;
	int f=n-1;
	int m=(f+i)/2;

	while(x!=v[m]){
		if(v[m]>x){
			f=m-1;
		}
		if(v[m]<x){
			i=m+1;
		}
		m=(f+i)/2;
	}

	cout<<"il numero si trova in "<<m+1<<" posizione"<<endl;
}