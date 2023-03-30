//funkcja obliczaj?ca punkty
int oblicz_punkty(){
    int p=0;
    for(int i=0;i<4;i++){
        for(int j=0; j<4; j++){
            if(tab[i][j] > 0){
                p += tab[i][j];
            }
        }
    }
    return p;
}
