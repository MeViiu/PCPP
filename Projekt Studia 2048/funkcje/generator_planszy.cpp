//funkcja wy?wietlaj?ca plansz?
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
