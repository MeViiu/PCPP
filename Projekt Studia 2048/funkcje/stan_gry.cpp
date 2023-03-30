//funkcja sprawdzaj?ca czy gra si? sko?czy?a
bool czy_koniec(){
    //sprawdzamy czy wszystkie pola s? zape?nione
    int zajete = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(tab[i][j] > 0){
                zajete++;
            }
        }
    }
    
    //je?li wszystkie pola s? zape?nione, sprawdzamy czy s? jeszcze mo?liwe ruchy
    if(zajete == 16){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(i > 0){
                    if(tab[i][j] == tab[i-1][j]){
                        return false;
                    }
                }
                if(i < 3){
                    if(tab[i][j] == tab[i+1][j]){
                        return false;
                    }
                }
                if(j > 0){
                    if(tab[i][j] == tab[i][j-1]){
                        return false;
                    }
                }
                if(j < 3){
                    if(tab[i][j] == tab[i][j+1]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    //w innym przypadku gra nie jest jeszcze sko?czona
    return false;
}
