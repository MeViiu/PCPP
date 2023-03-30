//Funkcja obs?uguj?ca opcje menu
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
			    //pojawienie si? planszy w konsoli
			    wyswietl_plansze();
			    
			    //p?tla odpowiedzialna za dzia?anie gry
			    while(true){
			        //wpisujemy klawisz z kalwiatury i przypisujemy do zmiennej
			        int klawisz=getch();
			        //sorawdzamy czy gra mo?e toczy? si? dalej, czy gracz ma mo?liwo?? ruchu
			        if(czy_koniec()){
			        	//Je?eli nie, wypisujemy pkt i ruchy na ekran
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
			        //sprawdzamy czy gracz chce zapisa? gr?
					if(klawisz=='x' || klawisz=='X'){
					    zapisz_gre();
					    break;
					}
					//sprawdzamy czy gracz chce wczyta? gr?
					//nie dzia?a
					else if(klawisz=='z' || klawisz=='Z'){
					    wczytaj_gre();
			    	}
			        //sprawdzanie ruchu gracza
			        else if(klawisz==72){ //strza?ka w g?r?
			            przesun(1);
			            ruch++;
			        } else if(klawisz==80){ //strza?ka w d?
			            przesun(2);
			            ruch++;
			        } else if(klawisz==75){ //strza?ka w lewo
			            przesun(3);
			            ruch++;
			        } else if(klawisz==77){ //strza?ka w prawo
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
				cout<<"Wy??czanie gry"<<endl;
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
