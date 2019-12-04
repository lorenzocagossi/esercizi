#include <iostream>
#include <time.h>

using namespace std;


void aggiungi(int &p){
	p=p+1;
	cout<<p<<endl;
}

void scambia(int &a, int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

int main(){
	int p=0;

	cout<<p<<endl;
	
	aggiungi(p);
	aggiungi(p);
	
	cout<<p<<endl;
	
	cout<<(p>0 ? -p : p)<<endl;
	
	int *c;
	cout<<c<<endl;
	
	int v[5]{1,2,3,4,5};
	cout<<*(v+3)<<endl;
	
	cout<<"____________________"<<endl;
	int a=2;
	int b=5;
	
	scambia(a,b);
	cout<<a<<endl<<b<<endl;
	

}
