#include<iostream>
#include<windows.h>
#include<conio.h>
#include<algorithm>
#include<numeric>
using namespace std;

#define test cout<<"\nTu sam";

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
}

bool negativan(double br){
    if(br<0){
        return true;
    }
    return false;
}

bool tekuci(unsigned long long br){
    if(br/100000000==32){
        return true;
    }
    return false;
}

void ispis_podataka(unsigned long long br_racuna[], string ime[], double saldo[], int korisnik, double &s, string &bist, int &brNegativnih, int &brTekucih){
    for(int i=0;i<korisnik;i++){
        cout<<"Broj racuna: "<<br_racuna[i]<<"\n";
        cout<<"Ime i prezime: "<<ime[i]<<"\n";
        cout<<"Saldo: "<<saldo[i]<<"\n\n";
    }
    s=accumulate(saldo, saldo+korisnik, 0);
    int maxi=max_element(saldo, saldo+korisnik)-saldo;
    bist=ime[maxi];
    brNegativnih=count_if(br_racuna, br_racuna+korisnik, negativan);
    brTekucih=count_if(br_racuna, br_racuna+korisnik, tekuci);
}

void imeprezime(unsigned long long br_racuna[], string ime[], double saldo[], int korisnik){
    cout<<"Upisite prezime i ime: ";
    string pretraga;
    cin.ignore();
    getline(cin, pretraga);
    int z=0;
    for(int i=0;i<korisnik;i++){
        if(pretraga==ime[i]){
            cout<<"Broj racuna: "<<br_racuna[i]<<endl<<"Stanje na racunu: "<<saldo[i]<<endl<<endl;
            z++;
        }
        else if(z==0 && i==korisnik-1){
            cout<<"Takav racun ne postoji"<<endl;
        }
    }
    getch();
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
            korisnik++;
        }
        else if(choice==2){
            if(korisnik>0){
                double s;
                string bist;
                int brNegativnih;
                int brTekucih;
                ispis_podataka(br_racuna, ime, saldo, korisnik, s, bist, brNegativnih, brTekucih);
                cout<<"Zbroj novaca: "<<s<<endl<<"Racun sa najvise novaca: "<<bist<<endl<<"Negativni racuni: "<<brNegativnih<<endl<<"Broj tekucih racuna: "<<brTekucih<<endl;
                getch();
            }
            else{
                cout<<"Nema racuna koje mozemo prikazati"<<"\n";
            }
            getch();
        }
        else if(choice==3){
            imeprezime(br_racuna, ime, saldo, korisnik);
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
