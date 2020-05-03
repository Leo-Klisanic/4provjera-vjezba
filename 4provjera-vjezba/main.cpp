#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void main_menu(){
    cout<<"1. Unos novog racuna\n";
    cout<<"2. Ispisi sve podatke\n";
    cout<<"3. Pretraga prema prezimenu i imenu\n";
    cout<<"4. Brisanje racuna\n";
    cout<<"5. Izmjena podataka prema broju racuna\n";
    cout<<"6. Ispisi sortirano po prezimenu i imenu\n";
    cout<<"7. Izlaz iz programa\n";
}

void novi_racun(unsigned long long br_racuna[1000], string ime[1000], double saldo[1000], int korisnik){
    while(1){
        try{
            cout<<"Unesite broj racuna: ";
            cin>>br_racuna[korisnik];
            if(br_racuna[korisnik]<1000000000 || br_racuna[korisnik]>9999999999){
                throw "Neispravan unos";
            }
            break;
        }
        catch(const char *x){
            cout<<x<<"\n";
        }
    }
    cout<<"Unesite ime i prezime: ";
    cin>>ime[korisnik];
    cout<<"Unesite saldo: ";
    cin>>saldo[korisnik];
    korisnik++;
}

int main()
{
    int choice;
    unsigned long long *br_racuna=new unsigned long long [1000];
    string *ime=new string [1000];
    double *saldo=new double [1000];
    int korisnik=0;
    while(1){
        system("cls");
        main_menu();
        cin>>choice;
        if(choice==1){
            novi_racun(br_racuna, ime, saldo, korisnik);
        }
        else if(choice==2){

        }
        else if(choice==3){

        }
        else if(choice==4){

        }
        else if(choice==5){

        }
        else if(choice==6){

        }
        else if(choice==7){
            system("cls");
            return 0;
        }
        else{
            cout<<"\nPogresan unos.\nPritisnite enter za ponovni unos";
            getch();
        }
    }
}
