//funkcja generuj?ca liczb? w polu
void generuj_liczby(){
    int x=rand()%4;
    int y=rand()%4;
    int los=(rand()%2)+1;
    
    if(tab[x][y]==0){
        tab[x][y]=los*2;
    } else {
        generuj_liczby();
    }
}
