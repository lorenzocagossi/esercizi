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
	int n= 15;
	srand(time(NULL));
	int v[n]; 
	for(int i=0; i<n; i++)
 		v[i]=random(1,10);
 		
	
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(v[i]>v[j])
				scambia(v[i],v[j]);
				
	for(int k=0; k<n; k++)	 
		cout<<v[k]<<" ";	
}

