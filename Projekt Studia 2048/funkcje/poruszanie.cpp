/funkcja poruszania po planszy
void przesun(int kierunek){
    int tab2[4][4];
    //kopiujemy tablic?
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tab2[i][j]=tab[i][j];
        }
    }
    //przesuwamy liczby
    if(kierunek==1){ //w g?r?
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tab[i][j]>0){
                    int a=i;
                    int b=j;
                    while(a>0){
                        if(tab[a-1][b]==0){
                            tab[a-1][b]=tab[a][b];
                            tab[a][b]=0;
                            a--;
                        } else if(tab[a-1][b]==tab[a][b]){
                            scal(a-1,b);
                            tab[a][b]=0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } else if(kierunek==2){ //w d?
        for(int i=3;i>=0;i--){
            for(int j=0;j<4;j++){
                if(tab[i][j]>0){
                    int a=i;
                    int b=j;
                    while(a<3){
                        if(tab[a+1][b]==0){
                            tab[a+1][b]=tab[a][b];
                            tab[a][b]=0;
                            a++;
                        } else if(tab[a+1][b]==tab[a][b]){
                            scal(a+1,b);
                            tab[a][b]=0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } else if(kierunek==3){ //w lewo
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tab[i][j]>0){
                    int a=i;
                    int b=j;
                    while(b>0){
                        if(tab[a][b-1]==0){
                            tab[a][b-1]=tab[a][b];
                            tab[a][b]=0;
                            b--;
                        } else if(tab[a][b-1]==tab[a][b]){
                            scal(a,b-1);
                            tab[a][b]= 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } else if(kierunek == 4){ //w prawo
        for(int i=0; i<4; i++){
            for(int j=3; j>=0;j--){
                if(tab[i][j]>0){
                    int a=i;
                    int b=j;
                    while(b<3){
                        if(tab[a][b+1]==0){
                            tab[a][b+1]=tab[a][b];
                            tab[a][b]=0;
                            b++;
                        } else if(tab[a][b+1]==tab[a][b]){
                            scal(a,b+1);
                            tab[a][b]=0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    //sprawdzamy czy jaka? liczba zmieni?a swoj? pozycj?
    bool zmiana=false;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tab2[i][j]!=tab[i][j]){
                zmiana=true;
            }
        }
    }
    //je?li co? si? zmieni?o, generujemy nowe liczby
    if(zmiana){
        generuj_liczby();
    }
}
