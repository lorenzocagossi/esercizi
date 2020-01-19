//agent lorenzo cagossi nella cartella verifica creata sul desktop. i file di output devono essere
//chiamati esattamente come i file di input




//scanf("%d %d %d", &C, &D, &Y);
//legge tre decimali e passo tre variabili per riferimento, cosi' prende delle variabili per riferimento e le riempie
//scanf restituisce anche il numero di dati che è riuscito a leggere correttamente

int main(){
    freopen("./input/1", "r", stdin);
    freopen("./outputs/1", "w", stdout);
    //cambia lo stdout e sdtin del programma
    //quando il programma funziona tolgo il commento di output e mette l'output nel file.
    int N;
    assert(3 == scanf("%d %d %d", &C, &D, &Y));

    int M[N];

    for(int i=0; i<N , i++){
        assert(1== scanf("d%", &M[i]));
    }

    //insert ur code

    printf("%d\n", 42); //print the result
}

