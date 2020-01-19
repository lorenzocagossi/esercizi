#include <iostream>
using namespace std;

int n;
int x;
int somma=0;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        somma+=x;
    }

    cout<<somma;
}