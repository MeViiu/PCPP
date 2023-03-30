//funkcja zapisuj?ca stan gry do pliku
void zapisz_gre(){
    ofstream plik;
    plik.open("zapis_gry.txt");
    plik << "zapis Gry Gracza: " << endl;
    plik << "Zdobyte Punkty:   " << punkty << endl;
    plik << "Ilosc ruchow:     " << ruch << endl;
    
    plik << "Zapisana Plansza" << endl;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            plik << tab[i][j] << " ";
        }
        plik << endl;
    }
    plik.close();
}
//funkcja wczytywania stanu gry z pliku
void wczytaj_gre(){
    ifstream plik;
    plik.open("zapis_gry.txt");
    plik >> punkty;
    plik >> ruch;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            plik >> tab[i][j];
        }
    }
    plik.close();
}
