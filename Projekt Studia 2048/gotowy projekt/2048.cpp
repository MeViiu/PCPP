#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
//Struktura danych gracza
//jendak nie u¿yta
struct Gracz{
    char Nazwa[20];
    int iloscPkt;
    int iloscRuchow;
};
//deklaracja zmiennych
int tab[4][4]; //tablica gry
int ruch=0;    //zmienna przechowuj¹ca iloœæ ruchów gracza
int punkty=0;  //zmienna przechowuj¹ca pkt gracza

//funkcja zawieraj¹ca menu gry
void generuj_menu(){
	cout<<"--------------------------"<<endl;
	cout<<"|   Witaj w Grze  2048!  |"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"|1.      Nowa Gra        |"<<endl;
	//cout<<"|2.     Wczytaj Gre      |"<<endl;//nie dzia³a 
	//cout<<"|3. Sprawdz ostatni wynik|"<<endl;//te¿ nie dzia³a 
	cout<<"|5.     Wyjdz z Gry      |"<<endl;
	cout<<"--------------------------"<<endl;
}

//funkcja generuj¹ca liczbê w polu
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

//funkcja obliczaj¹ca punkty
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

//funkcja wyœwietlaj¹ca planszê
void wyswietl_plansze(){
    system("cls");
    cout<<"Aby zapisac i wyjsc wpisz x/X"<<endl;
    cout<<"Punkty: "<<punkty<<endl;
    cout<<"Ilosc ruchow: "<<ruch<<endl;
    cout<<endl;
    cout<<"--------------"<<endl;
    for(int i=0; i<4; i++){
    	cout<<"| ";
        for(int j=0; j<4; j++){
            cout<<tab[i][j]<<" |";
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;
}

//funkcja ³¹cz¹ca dwie liczby
void scal(int a, int b){
    tab[a][b]*=2;
    punkty+=tab[a][b];
}

//funkcja poruszania po planszy
void przesun(int kierunek){
    int tab2[4][4];
    //kopiujemy tablicê
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tab2[i][j]=tab[i][j];
        }
    }
    //przesuwamy liczby
    if(kierunek==1){ //w górê
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
    } else if(kierunek==2){ //w dó³
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
    //sprawdzamy czy jakaœ liczba zmieni³a swoj¹ pozycjê
    bool zmiana=false;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tab2[i][j]!=tab[i][j]){
                zmiana=true;
            }
        }
    }
    //jeœli coœ siê zmieni³o, generujemy nowe liczby
    if(zmiana){
        generuj_liczby();
    }
}
//funkcja sprawdzaj¹ca czy gra siê skoñczy³a
bool czy_koniec(){
    //sprawdzamy czy wszystkie pola s¹ zape³nione
    int zajete = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(tab[i][j] > 0){
                zajete++;
            }
        }
    }
    
    //jeœli wszystkie pola s¹ zape³nione, sprawdzamy czy s¹ jeszcze mo¿liwe ruchy
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
    
    //w innym przypadku gra nie jest jeszcze skoñczona
    return false;
}

//funkcja zapisuj¹ca stan gry do pliku
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
//Funkcja obs³uguj¹ca opcje menu
void wybor_opcji(){
	int opcja, opcja2;
	cin>>opcja;
	switch(opcja)
		{
			case 1:
			{
				system("cls");
				cout<<"Rozpoczynasz nowa gre za: ";
				for(int i=1;i<=5;i++)
			    {
			        Sleep(1000);
			        cout<<i<<" ";
			    }
			    //generowanie pierwszych liczb do gry
			    generuj_liczby();
			    generuj_liczby();
			    //pojawienie siê planszy w konsoli
			    wyswietl_plansze();
			    
			    //pêtla odpowiedzialna za dzia³anie gry
			    while(true){
			        //wpisujemy klawisz z kalwiatury i przypisujemy do zmiennej
			        int klawisz=getch();
			        //sorawdzamy czy gra mo¿e toczyæ siê dalej, czy gracz ma mo¿liwoœæ ruchu
			        if(czy_koniec()){
			        	//Je¿eli nie, wypisujemy pkt i ruchy na ekran
			        	system("cls");
			            cout<<"Koniec gry!"<<endl;
						cout<<"Zdobyles: "<<punkty<<" punktow!"<<endl;
						cout<<"Twoj gra zostala zapisana."<<endl;
						zapisz_gre();
						cout<<"Powrot do menu glownego za 10s."<<endl;
						for(int i=1;i<=10;i++)
					    {
					        Sleep(1000);
					        cout<<i<<" ";
					    }
						system("cls");
						generuj_menu();
						wybor_opcji();
			            break;
			        }
			        //sprawdzamy czy gracz chce zapisaæ grê
					if(klawisz=='x' || klawisz=='X'){
					    zapisz_gre();
					    break;
					}
					//sprawdzamy czy gracz chce wczytaæ grê
					//nie dzia³a
					else if(klawisz=='z' || klawisz=='Z'){
					    wczytaj_gre();
			    	}
			        //sprawdzanie ruchu gracza
			        else if(klawisz==72){ //strza³ka w górê
			            przesun(1);
			            ruch++;
			        } else if(klawisz==80){ //strza³ka w dó³
			            przesun(2);
			            ruch++;
			        } else if(klawisz==75){ //strza³ka w lewo
			            przesun(3);
			            ruch++;
			        } else if(klawisz==77){ //strza³ka w prawo
			            przesun(4);
			            ruch++;
			        }
			        //spisanie pkt
			        punkty=oblicz_punkty();
			        //aktualizowanie planszy
			        wyswietl_plansze();
			    }
				break;
			}
			case 2:
			{
				system("cls");
				cout<<"Wczytywanie zapisu gry"<<endl;
				wczytaj_gre();
				break;
			}
			case 3:
			{
				cout<<"Wczytywanie ostatniego wyniku"<<endl;
				break;
			}
			case 4:
			{
				cout<<"Otwieranie opcji gry"<<endl;
				break;
			}
			case 5:
			{
				cout<<"Wy³¹czanie gry"<<endl;
				break;
			}
			default:
				{
					cout<<"Nie ma takiej opcji do wyboru!"<<endl;
					wybor_opcji();
					break;
				}
		}
}

int main(){
	generuj_menu();
	wybor_opcji();
    
    return 0;
}
