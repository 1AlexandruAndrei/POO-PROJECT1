#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

///----------------------------------------------------------------------------------------

class Financiar
{
private:
    const int idFinanciar;
    static int contorID3;
    int anRaport;
    int nrApartamenteVandute;
    int nrBirouriVandute;
    float profit;
    float datorii;


public:

    ///constructori
    Financiar();///constructor fara parametrii
    Financiar(int anRaport, int nrApartamenteVandute, int nrBirouriVandute, float profit, float datorii);///constructor  cu toti parametrii
    Financiar(int anRaport, int nrApartamenteVandute, int nrBirouriVandute);///constructor cu parametrii
    Financiar(const Financiar &obj);///copy constructor
    ~Financiar();///destructor


    ///metode de afisare si de citire
    void afisare();
    void citire();
    void analiza();

    ///operatori
    friend ostream& operator << (ostream& out, const Financiar &obj);///nu vreau sa ii modific camd ii afisez
    friend istream& operator >> (istream& in, Financiar &obj);
    Financiar &operator=(const Financiar &obj); ///operator egal
    ///DIFERENTA: Copy Constructor creeaza o zona noua in memorie, in timp ce copy constructor se foloseste de o zona existenta deja

    Financiar operator++();///++a
    Financiar operator++(int);///a+++ (face copie)

    Financiar operator +(int);///operator +
    Financiar operator +(const Financiar &obj);

    Financiar operator -(int var);
    Financiar operator -(const Financiar &obj);

    bool operator==(const Financiar &obj);///operatorul ==
    bool operator>=(const Financiar &obj);///operator >=
    operator int();

    ///getter
    float getProfit();
    float getDatorii();
    ///setteri
    void setAnRaport(int anRaport);
    void setProfit(float profit);
    void setDatorii(float datorii);

};

///setteri
void Financiar::setProfit(float profit)
{
    this->profit=profit;
}

void Financiar::setDatorii(float datorii)
{
    this->datorii=datorii;
}

///getteri
float Financiar::getProfit()
{
    return profit;
}

float Financiar::getDatorii()
{
    return datorii;
}

///operator ++
Financiar Financiar::operator++()
{
    this->nrApartamenteVandute++;
    return *this;
}

///operator ++
Financiar Financiar::operator++(int)
{
    Financiar copy(*this);///obiectul de la adresa this
    this->nrApartamenteVandute++;
    return copy;
}


///operator ==
bool Financiar::operator == (const Financiar &obj)
{
    if(this->anRaport!=obj.anRaport)
        return false;
    if(this->nrApartamenteVandute!=obj.nrApartamenteVandute)
        return false;
    if(this->nrBirouriVandute!=obj.nrBirouriVandute)
        return false;
    if(this->profit!=obj.profit)
        return false;
    if(this->datorii!=obj.datorii)
        return false;

    return true;
}

///operator cast
Financiar::operator int()
{
    return this->anRaport;
}

///constrcutor fara parametrii
Financiar::Financiar():idFinanciar(contorID3++)
{

    anRaport=0;
    nrApartamenteVandute=0;
    nrBirouriVandute=0;
    profit=0;
    datorii=0;
}

///constructor cu toti parametrii
Financiar::Financiar(int anRaport, int nrApartamenteVandute, int nrBirouriVandute, float profit, float datorii):idFinanciar(contorID3++)
{

    this->anRaport=anRaport;
    this->nrApartamenteVandute=nrApartamenteVandute;
    this->nrBirouriVandute=nrBirouriVandute;
    this->profit=profit;
    this->datorii=datorii;
}

///constructor cu parametrii
Financiar::Financiar(int anRaport, int nrApartamenteVandute, int nrBirouriVandute):idFinanciar(contorID3++)
{
    this->anRaport=anRaport;
    this->nrApartamenteVandute=nrApartamenteVandute;
    this->nrBirouriVandute=nrBirouriVandute;
}

///copy constructor
Financiar::Financiar(const Financiar& obj):idFinanciar(contorID3)
{

    this->anRaport=obj.anRaport;
    this->nrApartamenteVandute=obj.nrApartamenteVandute;
    this->profit=obj.profit;
    this->datorii=obj.datorii;
    this->nrBirouriVandute=obj.nrBirouriVandute;
}

///cirirea
void Financiar::citire()
{

    cout<<"Anul raportului financiar introdus este: ";
    cin>>this->anRaport;

    cout<<"Numarul de apartamente vandute este: ";
    cin>>this->nrApartamenteVandute;

    cout<<"Numarul de birouri vandute este: ";
    cin>>this->nrBirouriVandute;

    cout<<"Vanzarile pe care le-a generat firma sunt in valoare de: (in milioane de euro) ";
    cin>>this->profit;

    cout<<"Datoriile pe care le are firma sunt: (in milioane de euro) ";
    cin>>this->datorii;


}

///afisarea
void Financiar::afisare()
{
    cout<<"ID-ul apartamentului este: "<<this->idFinanciar<<endl;
    cout<<"Anul raportului financiar introdus este: "<<this->anRaport<<endl;
    cout<<"Numarul de apartamente vandute este: "<<this->nrApartamenteVandute<<endl;
    cout<<"Numarul de birouri vandute este: "<<this->nrBirouriVandute<<endl;
    cout<<"Vanzarile pe care le-a generat compania sunt in valoare de: "<<this->profit<<" milioane de euro"<<endl;
    cout<<"Datoriile pe care le are compania: "<<this->datorii<<" milioane de euro"<<endl;

}

///operator >>
istream& operator >>(istream& in, Financiar& obj)
{

    cout << "Introduceti anul raportului financiar al companiei: ";
    in >> obj.anRaport;

    cout << "Introduceti numarul de apartamente vandute: ";
    in >> obj.nrApartamenteVandute;

    cout <<"Introduceti numarul de birouri vandute: ";
    in >> obj.nrBirouriVandute;

    cout << "Introduceti vanzarile generate de firma: (in milioane de euro) ";
    in >> obj.profit;

    cout << "Introduceti datoriile generate de firma: (in milioane de euro) ";
    in >> obj.datorii;
    return in;
}

///operator <<
ostream& operator <<(ostream& out, const Financiar& obj)
{
    out << "ID-ul obiectului Financiar este: "<<obj.idFinanciar<<endl;
    out << "Anul raportului financiar introdus este: " << obj.anRaport << endl;
    out << "Numarul de apartamente vandute este: " << obj.nrApartamenteVandute << endl;
    out << "Numarul de birouri vandute este: " << obj.nrBirouriVandute << endl;
    out << "Vanzarile pe care le-a generat firma sunt in valoare de: " << obj.profit <<" milioane de euro."<< endl;
    out << "Datoriile pe care le-a avut firma sunt in valoare de: " << obj.datorii << " milioane de euro." <<endl;
    return out;
}

///supraincarcarea operatorului egal
Financiar& Financiar::operator=(const Financiar &obj)
{
    if(this != &obj)
    {
        this->anRaport=obj.anRaport;
        this->nrApartamenteVandute=obj.nrApartamenteVandute;
        this->nrBirouriVandute=obj.nrBirouriVandute;
        this->datorii=obj.datorii;
        this->profit=obj.profit;

    }
    return *this;
}

///functionalitate
void Financiar::analiza()
{
    float x=this->datorii, y=this->profit;
    if(x>y)
        cout<<"Compania risca sa intre in faliment!"<<endl;
    else if(x<y)
        cout<<"Compania este profitabila!"<<endl;
    else
        cout<<"Compania stagneaza, valoarea profitului este egala cu valoarea datoriilor."<<endl;

}


///operaor >=
bool Financiar::operator>=(const Financiar& obj)
{
    if(this->datorii>=obj.datorii)
        return true;
    return false;
}

///operator +
Financiar Financiar::operator+(const Financiar &obj)
{
    Financiar aux(*this);
    aux.datorii+=obj.datorii;
    aux.profit+=obj.profit;
    return aux;

}

Financiar Financiar::operator+(int x)
{
    Financiar aux(*this);
    aux.nrApartamenteVandute+=x;
    return aux;
}

///a+10
Financiar operator+(int x, Financiar obj)
{
    return obj+x;
}

///operator -
Financiar Financiar::operator-(int var)
{
    Financiar aux(*this);
    aux.datorii=aux.datorii-var;
    return aux;
}

Financiar Financiar::operator-(const Financiar &obj)
{
    Financiar aux(*this);
    aux.datorii=aux.datorii-obj.datorii;
    return aux;
}

///destructor
Financiar::~Financiar()
{

    this->anRaport=0;
    this->nrApartamenteVandute=0;
    this->nrBirouriVandute=0;
    this->profit=0;
    this->datorii=0;
}

int Financiar::contorID3=0;

///-----------------------------------------------------------------------------------------

class Chirias
{
private:
    const int idChirias;
    static int contorID2;
    char *nume;
    string prenume;
    int nrApartament;
    double datorii;
    int perioada;

public:

    ///constructori
    Chirias();///constructor fara parametrii
    Chirias(char *nume, string prenume, int nrApartament, double datorii, int perioada);///constructor parametrizat
    Chirias(int nrApartament, int perioada);///constructor cu parametrii
    Chirias(const Chirias &obj);///copy constructor
    ~Chirias();///destructor


    ///metode de afisare si de citire
    void afisare();
    void citire();
    void etaj();

    ///operatori
    friend ostream& operator << (ostream& out, const Chirias &obj);///pun const pentru ca nu vreau sa il modific camd il afisez
    friend istream& operator >> (istream& in, Chirias &obj);
    Chirias &operator=(const Chirias &obj);

    Chirias operator++();
    Chirias operator++(int);///++

    Chirias operator+(const Chirias obj);
    Chirias operator+(int);///operator +

    bool operator==(const Chirias &obj);///operatorul ==
    bool operator>=(const Chirias& obj);///operator >=
    friend Chirias operator+(int, Chirias obj);
    Chirias operator-(int var);
    Chirias operator-(const Chirias &obj);

    operator double();
    operator int() const;


    ///setteri
    void setNume(char *nume);
    void setPrenume(string prenume);
    void setNrApartament(int nrApartament);
    void setDatorii(double datorii);
    void setPerioada(int perioada);

    ///getteri (pun const
    int getPerioada ()const;
    double getDatorii()const;
    int getNrApartament()const;
    const char* getNume() const;
    string getPrenume()const;
};

///getteri
int Chirias::getNrApartament() const
{
    return nrApartament;
}

int Chirias::getPerioada()const
{
    return perioada;
}

double Chirias::getDatorii() const
{
    return datorii;
}

string Chirias::getPrenume() const
{
    return prenume;
}

const char* Chirias::getNume() const
{
    return nume;
}


///setteri
void Chirias::setNume(char *nume)
{
    if(this->nume != NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }
}

void Chirias::setPrenume(string prenume)
{
    this->prenume=prenume;
}

void Chirias::setNrApartament(int nrApartament)
{
    this->nrApartament=nrApartament;
}

void Chirias::setDatorii(double datorii)
{
    this->datorii=datorii;
}

void Chirias::setPerioada(int perioada)
{
    this->perioada=perioada;
}

///operator cast
Chirias::operator double()
{
    return this->datorii;
}
Chirias::operator int() const
{
    return this->nrApartament;
}

///operator ++
Chirias Chirias::operator++()
{
    this->perioada++;
    return *this;
}

///operator ++
Chirias Chirias::operator++(int)
{
    Chirias copy(*this);///obiectul de la adresa this
    this->perioada++;
    return copy;
}

///operator +
Chirias operator+(int x, Chirias obj)
{
    return obj+x;
}

///operator +
Chirias Chirias::operator+(int x)
{
    Chirias aux(*this);
    aux.perioada+=x;
    return aux;
}

///operator -
Chirias Chirias::operator-(const Chirias &obj)
{
    Chirias aux(*this);
    aux.datorii=aux.datorii-obj.datorii;
    return aux;
}

///operator -
Chirias Chirias::operator-(int var)
{
    Chirias aux(*this);
    aux.datorii=aux.datorii-var;
    return aux;
}

///operator ==
bool Chirias::operator == (const Chirias &obj)
{
    if(this->nrApartament!=obj.nrApartament)
        return false;
    if(this->datorii!=obj.datorii)
        return false;
    if(this->perioada!=obj.perioada)
        return false;
    if(strcmp(this->nume,obj.nume)!=0)
        return false;
    if(this->prenume!=obj.prenume)
        return false;

    return true;

}

///constrcutor fara parametrii
Chirias::Chirias():idChirias(contorID2++)
{
    nume=new char[strlen("Anonim")+1];
    strcpy(nume,"Anonim");
    prenume="Anonim";
    nrApartament=0;
    datorii=0;
    perioada=0;
}

///constructor cu toti parametrii
Chirias::Chirias(char *nume, string prenume, int nrApartament, double datorii, int perioada):idChirias(contorID2++)
{
    this->nume=new char[strlen(nume)+1];/// doar am alocat memorie
    strcpy(this->nume,nume);/// atribui valoarea
    this->prenume=prenume;
    this->nrApartament=nrApartament;
    this->datorii=datorii;
    this->perioada=perioada;
}

///constructor cu parametrii
Chirias::Chirias(int nrApartament, int perioada):idChirias(contorID2++)
{
    this->nrApartament=nrApartament;
    this->perioada=perioada;
}
Chirias::Chirias(const Chirias& obj):idChirias(contorID2)
{
    this->nume=new char[strlen(obj.nume)+1];/// doar am alocat memorie
    strcpy(this->nume,obj.nume);/// atribui valoarea
    this->prenume=obj.prenume;
    this->nrApartament=obj.nrApartament;
    this->datorii=obj.datorii;
    this->perioada=obj.perioada;
}

///cirirea
void Chirias::citire()
{
    cout<<"Numele chiriasului este: ";
    char aux[25];
    cin>>aux;
    if(this->nume!=NULL)
    {
        delete[] this->nume;
    }
    this->nume=new char[strlen(aux)+1];
    strcpy(this->nume, aux);

    cout<<"Prenumele chiriasului este: ";
    cin>>this->prenume;

    cout<<"Numarul apartamentului in care locuieste este: ";
    cin>>this->nrApartament;

    cout<<"Chiriasul are datorii in valoare de (euro): ";
    cin>>this->datorii;

    cout<<"Persoana este chiriasa de (luni): ";
    cin>>this->perioada;

    cout<<endl;

}

///afisarea
void Chirias::afisare()
{
    cout<<"ID-ul chiriasului este: "<<this->idChirias<<endl;
    cout<<"Numele chiriasului este: "<<this->nume<<endl;
    cout<<"Prenumele chiriasului este: "<<this->prenume<<endl;
    cout<<"Numarul apartamentului in care locuieste este: "<<this->nrApartament<<endl;
    cout<<"Chiriasul are datorii in valoare de "<<this->datorii<<" euro"<<endl;
    cout<<"Persoana este chiriasa de  "<<this->perioada<<" luni"<<endl;

}

///operator <<
ostream& operator <<(ostream& out, const Chirias& obj)
{
    out <<"ID-ul apartamentului este: "<<obj.idChirias<<endl;
    out << "Numele chiriasului este: " << obj.nume << endl;
    out << "Prenume chiriasului este: " << obj.prenume << endl;
    out << "Numarul apartamentului este: " << obj.nrApartament << endl;
    out << "Datoriile sunt in valoare de: " << obj.datorii <<" euro"<< endl;
    out << "Perioada de cazare este: " << obj.perioada <<" luni"<< endl;
    return out;
}

///operator >>
istream& operator >>(istream& in, Chirias& obj)
{
    cout << "Introduceti numele chiriasului: ";
    char nume[100];
    in >> nume;
    if(obj.nume != NULL)
    {
        delete obj.nume;
        obj.nume = NULL;
    }
    obj.nume = new char[strlen(nume) + 1];
    strcpy(obj.nume, nume);

    cout << "Introduceti prenumele chiriasului: ";
    in >> obj.prenume;

    cout << "Introduceti perioada de sedere (luni): ";
    in >> obj.perioada;

    cout << "Introduceti numarul apartamentului: ";
    in >> obj.nrApartament;

    cout << "Introduceti datoriile (euro): ";
    in >> obj.datorii;
    cout<<endl;
    return in;
}

///supraincarcarea operatorului egal
Chirias& Chirias::operator=(const Chirias &obj)
{
    if(this != &obj)
    {
        if(this->nume!=NULL)
        {
            delete[] this->nume;
            this->nume=NULL;
        }

        this->nume=new char[strlen(obj.nume)+1];
        strcpy(this->nume, obj.nume);

        this->nrApartament=obj.nrApartament;
        this->datorii=obj.datorii;

        this->perioada=obj.perioada;

        this->prenume=obj.prenume;

    }
    return *this;
}

///functionalitate
void Chirias::etaj()
{
    int x=this->nrApartament, first=0;
    int y=x;
    while(x!=0)
    {
        first=x%10;
        x/=10;
    }
    if(y<100)
        cout<<"Rezidentul "<<getPrenume()<<" sta la parter"<<endl;
    else
        cout<<"Rezidentul "<<getPrenume()<< " sta la etajul "<<first<<endl;

}

///operaor >=
bool Chirias::operator>=(const Chirias& obj)
{
    if(this->perioada>=obj.perioada)
        return true;
    return false;
}

///destructor
Chirias::~Chirias()
{
    if(this->nume!=NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }
    this->prenume="-";
    this->nrApartament=0;
    this->datorii=0;
    this->perioada=0;
}
int Chirias::contorID2=0;

///------------------------------------------------------------------------------------------------

class Apartament
{
private:
    const int idApartament;
    static int contorID1;
    int nrLocuitori;
    int nrCamere;
    float pret;
    int suprafata;
public:
    static int getContorID1()
    {
        return Apartament::contorID1;
    }

    Apartament();///constructor fara parametrii
    Apartament(int nrLocuitori, int nrCamere, float pret, int suprafata);///constructor parametrizat
    Apartament(int nrCamere, float pret, int suprafata);///constructor cu 3 parametrii
    Apartament(const Apartament &obj);///copy constructor

    ~Apartament();///destructor pt a sterge memoria alocata dinamic


    Apartament &operator=(const Apartament &obj);
    friend ostream& operator << (ostream& out, const Apartament &a1);///pun const pentru ca nu modific nimic la afisare
    friend istream& operator >> (istream& in, Apartament &a1);

    Apartament operator++();///++a
    Apartament operator++(int);///a++

    Apartament operator+(const Apartament& obj);
    Apartament operator+(int);

    friend Apartament operator+(int, Apartament obj);
    bool operator==(const Apartament &obj);///operatorul ==
    bool operator>(const Apartament& obj);///operator >
    operator int();
    operator int() const
    {
        return this->suprafata;
    }
    Apartament operator-(int var);
    Apartament operator-(const Apartament &obj);


    ///metode de afisare si citire
    void afisare();
    void citire();
    void dimensiune();

    ///getter
    int getNrCamere()const;
    int getNrLocuitori()const;
    int getSuprafata()const;
    float getPret()const;
    int getidApartament()const;

    ///setter
    void setNrCamere(int nrCamere);
    void setNrLocuitori(int nrLocuitori);
    void setPret(float pret);
    void setSuprafata(int suprafata);


};

///cast operator
Apartament::operator int()
{
    return this->pret;
}

///getters
int Apartament::getNrLocuitori()const
{
    return nrLocuitori;
}

int Apartament::getNrCamere()const
{
    return nrCamere;
}

int Apartament::getSuprafata()const
{
    return suprafata;
}

float Apartament::getPret()const
{
    return pret;
}

int Apartament::getidApartament()const
{
    return idApartament;
}

///setteri
void Apartament::setNrLocuitori(int nrLocuitori)
{
    this->nrLocuitori=nrLocuitori;
}
void Apartament::setNrCamere(int nrCamere)
{
    this->nrCamere=nrCamere;
}

void Apartament::setPret(float pret)
{
    this->pret=pret;
}

void Apartament::setSuprafata(int suprafata)
{
    this->suprafata=suprafata;
}

///constructor fara parametrii
Apartament::Apartament():idApartament(contorID1++)
{

    nrLocuitori=0;
    nrCamere=0;
    pret=0;
    suprafata=0;

}

///copy constructor
Apartament::Apartament(const Apartament &obj):idApartament(obj.idApartament)
{
    this->nrLocuitori=obj.nrLocuitori;
    this->nrCamere=obj.nrCamere;
    this->pret=obj.pret;
    this->suprafata=obj.suprafata;
}

///cosntructor cu 3 parametrii
Apartament::Apartament(int nrCamere, float pret, int suprafata):idApartament(contorID1++)
{
    this->nrCamere=nrCamere;
    this->pret=pret;
    this->suprafata=suprafata;
}

///constructor cu toti parametrii
Apartament::Apartament(int nrLocuitori, int nrCamere, float pret, int suprafata):idApartament(contorID1++)
{

    this->nrLocuitori=nrLocuitori;
    this->nrCamere=nrCamere;
    this->pret=pret;
    this->suprafata=suprafata;

}

///operatorul egal
Apartament& Apartament::operator=(const Apartament &obj)
{
    if(this!=&obj)
    {
        this->nrLocuitori=obj.nrLocuitori;
        this->nrCamere=obj.nrCamere;
        this->pret=obj.pret;
        this->suprafata=obj.suprafata;

    }
    return *this;
}

///operator ++
Apartament Apartament::operator++()
{
    this->nrLocuitori++;
    return *this;
}

///operator ++
Apartament Apartament::operator++(int)
{
    Apartament copy(*this);///obiectul de la adresa this
    this->nrLocuitori++;
    return copy;
}

///operatorul ==
bool Apartament::operator == (const Apartament &obj)
{
    if(this->nrLocuitori!=obj.nrLocuitori)
        return false;
    if(this->nrCamere!=obj.nrCamere)
        return false;
    if(this->suprafata!=obj.suprafata)
        return false;
    if(this->pret!=obj.pret)
        return false;
    return true;
}

///operator +
Apartament Apartament::operator+(int x)
{
    Apartament aux(*this);
    aux.suprafata+=x;

    return aux;
}

///a+10
Apartament operator+(int x, Apartament obj)
{
    return obj+x;
}

///operator -
Apartament Apartament::operator-(const Apartament &obj)
{
    Apartament aux(*this);
    aux.nrLocuitori=aux.nrLocuitori-obj.nrLocuitori;
    return aux;
}

///operator -
Apartament Apartament::operator-(int var)
{
    Apartament aux(*this);
    aux.nrLocuitori=aux.nrLocuitori-var;
    return aux;
}

///operator >
bool Apartament::operator>(const Apartament& obj)
{
    if(this->pret>obj.pret)
        return true;
    return false;
}

///operator 10+obiect
Apartament Apartament::operator+(const Apartament& obj)
{
    Apartament aux(*this);
    aux.nrLocuitori+=obj.nrLocuitori;
    aux.pret+=obj.pret;
    return aux;
}

///citire
void Apartament::citire()
{
    cout<<"Numarul de locuitori este: ";
    cin>>this->nrLocuitori;

    cout<<"Numarul de camere este: ";
    cin>>this->nrCamere;

    cout<<"Pretul apartamentului este: ";
    cin>>this->pret;

    cout<<"Suprafata apartamentului este: ";
    cin>>this->suprafata;
}

///afisare
void Apartament::afisare()
{
    cout<<"ID-ul apartamentului este: "<<this->idApartament<<endl;
    cout<<"Numarul de locuitori este: "<<this->nrLocuitori<<endl;
    cout<<"Numarul de camere din apartament este: "<<this->nrCamere<<endl;
    cout<<"Pretul apartamentului este: "<<this->pret<<" mii de euro"<<endl;
    cout<<"Suprafata apartamentului este: "<<this->suprafata<<" metri patrati"<<endl;

}

///functionalitate
void Apartament::dimensiune()
{
    if(this->suprafata>=100)
        cout<<"Apartamentul "<<this->idApartament<< " este de dimensiuni mari, ideal pentru o familie."<<endl;
    else if(this->suprafata>=40 && this->suprafata<100)
        cout<<"Apartamentul "<<this->idApartament<<" este de dimensiuni medii, ideal pentru doua persoane."<<endl;
    else
        cout<<"Apartamentul "<<this->idApartament<<" este de dimensiuni mici."<<endl;
}

///supraincarcarea operatorului >>
istream& operator >>(istream& in, Apartament& a1)
{
    cout<<"Numarul de locuitori din apartament este: ";
    in>>a1.nrLocuitori;

    cout<<"Numarul de camere din apartament este: ";
    in>>a1.nrCamere;

    cout<<"Pretul apartamentului este (mii de euro): ";
    in>>a1.pret;

    cout<<"Suprafata apartamentului este (metri patrati): ";
    in>>a1.suprafata;
    return in;

}

///supraincarcarea operatorului <<
ostream& operator <<(ostream& out, const Apartament& a1)
{
    out<<"ID-ul apartamentului este: "<<a1.idApartament<<endl;
    out<<"Numarul de locuitori din apartament este: "<<a1.nrLocuitori<<endl;
    out<<"Numarul de camere pe care le are apartamentul este: "<<a1.nrCamere<<endl;
    out<<"Pretul apartamentului este: "<<a1.pret<<" mii de euro "<<endl;
    out<<"Suprafata apartamentului este: "<<a1.suprafata<<" metri patrati"<<endl;

    return out;
}

///destructor
Apartament::~Apartament()
{
    this->pret=0.0;
    this->suprafata=0;
    this->nrCamere=0;
    this->nrLocuitori=0;
}

int Apartament::contorID1=0;

///-----------------------------------------------------------------

class Residence
{
private:
    const int idCladire;
    static int contorID;
    char *NumeCladire;
    string proprietar;
    float valoare;

    int *NrRezidenti;
    int nrCamere;

    bool soldOut;
    char cladirePrincipala;
public:
    static int getContorId()
    {
        return Residence::contorID;
    }

    ///constructori
    Residence();
    Residence(char* NumeCladire, string proprietar, float valoare,
              int nrCamere, int* NrRezidenti, bool soldOut, char cladirePrincipala);
    Residence(const Residence &obj);
    ~Residence();///destructor


    ///supraincarcarea
    Residence &operator =(const Residence &obj);
    friend ostream& operator << (ostream& out, const Residence &r1);
    friend istream& operator >> (istream& in, Residence &r1);

    Residence operator++();///++a
    Residence operator++(int);///a+++

    Residence operator+(const Residence& obj);
    Residence operator+(int);

    friend Residence operator+(int, Residence obj);
    bool operator ==(const Residence &r);///operator ==
    int operator[](int);
    bool operator<(const Residence& obj);///operator <
    operator float() const
    {
        return this->valoare;
    }
    operator int();
    operator int() const;

    Residence operator-(const Residence &obj);
    Residence operator-(float valoare);

    friend Residence operator+(int a, Residence);

    ///metodele
    void afisare();
    void citire();
    void tipResidence();
    void adaug(Residence& objResidence, Financiar& objFinanciar);

    ///getters
    int getNrCamere()const;
    const int* getNrRezidenti() const
    {
        return NrRezidenti;
    }
    float getValoare()const;
    bool getSoldOut()const;
    char getCladirePrincipala()const;
    const char* getNumeCladire() const;
    string getProprietar()const;

    ///setters
    void setNrCamere(int nrCamere);
    void setSoldOut(bool soldOut);
    void setProprietar(string proprietar);
    void setCladirePrincipala(char cladirePrincipala);
    void setNrRezidenti(int* NrRezidenti);
    void setValoare(float valoare);

};

int Residence::contorID=0;

///setteri
void Residence::setProprietar(string proprietar)
{
    this->proprietar=proprietar;
}
void Residence::setNrCamere(int nrCamere)
{
    this->nrCamere=nrCamere;
}

void Residence::setCladirePrincipala(char cladirePrincipala)
{
    this->cladirePrincipala=cladirePrincipala;
}

void Residence::setNrRezidenti(int* NrRezidenti)
{
    if(this->NrRezidenti!=NULL)
    {
        delete[] this->NrRezidenti;
        this->NrRezidenti=NULL;
    }
    this->NrRezidenti=new int[this->nrCamere];
    for(int i=0; i<this->nrCamere; i++)
        this->NrRezidenti[i]=NrRezidenti[i];
}

void Residence::setValoare(float valoare)
{
    this->valoare=valoare;
}

///getteri
int Residence::getNrCamere()const
{
    return nrCamere;
}

float Residence::getValoare()const
{
    return valoare;
}

bool Residence::getSoldOut()const
{
    return soldOut;
}

string Residence::getProprietar()const
{
    return proprietar;
}

char Residence::getCladirePrincipala()const
{
    return cladirePrincipala;
}

const char* Residence::getNumeCladire()const
{
    return NumeCladire;
}

///constructor fara parametrii
Residence::Residence():idCladire(contorID++)
{
    NumeCladire=new char[strlen("Anonim")+1];
    strcpy(NumeCladire,"Anonim");
    proprietar="ANONIM";
    valoare=0;

    nrCamere=0;
    NrRezidenti=NULL;

    soldOut=true;
    cladirePrincipala='-';
}

///constructor cu toti parametrii
Residence::Residence(char* NumeCladire, string proprietar, float valoare,
                     int nrCamere, int* NrRezidenti, bool soldOut, char cladirePrincipala):idCladire(contorID++)
{
    this->NumeCladire=new char[strlen(NumeCladire)+1];
    strcpy(this->NumeCladire, NumeCladire);
    this->proprietar=proprietar;
    this->valoare=valoare;

    this->nrCamere=nrCamere;
    this->NrRezidenti=NrRezidenti;

    for(int i=0; i<nrCamere; i++)
    {
        this->NrRezidenti[i]=NrRezidenti[i];
    }

    this->soldOut=soldOut;
    this->cladirePrincipala=cladirePrincipala;

}

///copy constructor
Residence::Residence(const Residence &obj):idCladire(obj.idCladire)
{
    this->NumeCladire=new char[strlen(obj.NumeCladire)+1];
    strcpy(this->NumeCladire, obj.NumeCladire);

    this->proprietar=obj.proprietar;
    this->valoare=obj.valoare;

    this->nrCamere=obj.nrCamere;

    this->NrRezidenti=new int[obj.nrCamere];
    for(int i=0; i<obj.nrCamere; i++)
    {
        this->NrRezidenti[i]=obj.NrRezidenti[i];///zona de memorie diferita
    }
    this->soldOut=obj.soldOut;
    this->cladirePrincipala=obj.cladirePrincipala;
}

///supraincarcarea operatorului egal
Residence& Residence::operator=(const Residence &obj)
{
    if(this != &obj)
    {

        if(this->NrRezidenti!=NULL)
        {
            delete[] this->NrRezidenti;
            this->NrRezidenti=NULL;
        }

        if(this->NumeCladire!=NULL)
        {
            delete[] this->NumeCladire;
            this->NumeCladire=NULL;
        }

        this->NumeCladire=new char[strlen(obj.NumeCladire)+1];
        strcpy(this->NumeCladire, obj.NumeCladire);
        this->proprietar=obj.proprietar;
        this->valoare=obj.valoare;

        this->nrCamere=obj.nrCamere;

        this->NrRezidenti=new int[obj.nrCamere];
        for(int i=0; i<obj.nrCamere; i++)
        {
            this->NrRezidenti[i]=obj.NrRezidenti[i];
        }
        this->soldOut=obj.soldOut;
        this->cladirePrincipala=obj.cladirePrincipala;

    }
    return *this;
}

///supraincarcarea operatorului <<
ostream& operator <<(ostream& out, const Residence& r1)
{
    out<<"ID-ul cladirii este: "<<r1.idCladire<<endl;
    out<<"Numele cladirii este: "<<r1.NumeCladire<<endl;
    out<<"Numele proprietarului este: "<<r1.proprietar<<endl;
    out<<"Pret (milioane de euro): "<<r1.valoare<<endl;
    out<<"Numarul de camere: "<<r1.nrCamere<<endl;

    for(int i=0; i<r1.nrCamere; i++)
    {
        out<<"Numar de rezidenti din camera "<<i+1<<":"<<r1.NrRezidenti[i]<<endl;
    }
    cout<<"RESIDENCE-UL ";
    if(r1.soldOut==false)
    {
        out<<"NU ESTE ";
    }
    out<<"SOLD OUT "<<endl;
    out<<"Cladirea principala este: "<<r1.cladirePrincipala<<endl;
    return out;

}

///supraincarcarea operatorului >>
istream& operator >>(istream& in, Residence& r1)
{

    cout<<"Numele cladirii este: ";
    char aux[20];
    in>>aux;

    if (r1.NumeCladire!=NULL)
    {
        delete[] r1.NumeCladire;
    }
    r1.NumeCladire= new char[strlen(aux)+1];
    strcpy(r1.NumeCladire, aux);

    cout<<"Numele proprietarului este: ";
    in>>r1.proprietar;

    cout<<"Valoarea totala a ansamblului este (milioane de euro): ";
    in>>r1.valoare;

    cout<<"Numar de apartamente: ";
    in>>r1.nrCamere;

    if(r1.NrRezidenti!=NULL)
    {
        delete [] r1.NrRezidenti;
        r1.NrRezidenti=NULL;
    }
    r1.NrRezidenti=new int [r1.nrCamere];
    for(int i=0; i<r1.nrCamere; i++)
    {
        cout<<"Numarul de rezidenti din apartamentul "<<i+1<<": ";
        in>>r1.NrRezidenti[i];
    }
    cout<<"Sunt toate apartamentele inchiriate?"<<endl<<"1=True \t 0=False"<<endl;
    in>>r1.soldOut;

    cout<<"Cladirea principala este: ";
    in>>r1.cladirePrincipala;

    return in;

}

///functia de citire
void Residence::citire()
{
    cout<<"Numele cladirii este: ";
    char aux[20];
    cin>>aux;
    if (this->NumeCladire!=NULL)
    {
        delete[] this->NumeCladire;
    }
    this->NumeCladire= new char[strlen(aux)+1];
    strcpy(this->NumeCladire, aux);

    cout<<"Numele proprietarului este: ";
    cin>>this->proprietar;

    cout<<"Valoarea totala a ansamblului este: (milioane de euro) ";
    cin>>this->valoare;

    cout<<"Numarul de camere este: ";
    cin>>this->nrCamere;

    if(this->NrRezidenti!=NULL)
    {
        delete[] this->NrRezidenti;
    }
    this->NrRezidenti=new int[this->nrCamere];
    for(int i=0; i<nrCamere; i++)
    {
        cout<<"Rezidenti "<<i+1<<":";
        cin>>this->NrRezidenti[i];
    }
    cout<<"Sunt toate apartamentele inchiriate?"<<endl<<"1=True \t 0=False"<<endl;
    cin>>this->soldOut;

    cout<<"Initiala cladirii principale este: ";
    cin>>this->cladirePrincipala;
    cout<<endl;

}

///functia de afisare
void Residence::afisare()
{
    cout<<"ID-ul cladirii este: "<<this->idCladire<<endl;
    cout<<"Numele cladirii este: "<<this->NumeCladire<<endl;
    cout<<"Numele proprietarului este: "<<this->proprietar<<endl;
    cout<<"Valoarea totala a ansamblului este: "<<this->valoare<<" milioane de euro"<<endl;

    if(this->soldOut==true)
        cout<<"Toate apartamentele sunt inchiriate!"<<endl;
    else if (this->soldOut==false)
        cout<<"Exista apartamente dispobinile!"<<endl;

    cout<<"Numar de camere: "<<this->nrCamere<<endl;
    for(int i=0; i<this->nrCamere; i++)
    {
        cout<<"Numarul de rezidenti din camera "<<i+1<<" este:"<<this->NrRezidenti[i]<<" ";
        cout<<endl;
    }
    cout<<"Initiala sediului principal este: "<<this->cladirePrincipala<<endl;

}

///functionalitate
void Residence::tipResidence()
{
    if (this->valoare>=50)
        cout<<"Residence-ul "<<this->NumeCladire<<" este unul de lux."<<endl;
    else
        cout<<"Residence-ul "<<this->NumeCladire <<" este unul pentru middle-class."<<endl;

}

///operatorul ==
bool Residence::operator == (const Residence &obj)
{
    if(strcmp(this->NumeCladire, obj.NumeCladire)!=0)
        return false;
    if(this->valoare !=obj.valoare)
        return false;
    if(this->nrCamere!=obj.nrCamere)
        return false;
    if(this->soldOut!=obj.soldOut)
        return false;
    if(this->cladirePrincipala!=obj.cladirePrincipala)
        return false;

    return true;
}

///operator []
int Residence::operator[](int a)
{
    if(this->NrRezidenti==NULL)
        throw runtime_error("Nr Rezidenti nu are elemente!");
    if(a<0 || a>this->nrCamere)
        throw runtime_error("INDEX INVALID");
    else
        return this->NrRezidenti[a];

}

///operator ++a
Residence Residence::operator++()
{
    this->valoare++;
    return *this;
}

///operator a++
Residence Residence::operator++(int)
{
    Residence aux(*this);///obiectul de la adresa this
    this->valoare++;
    return aux;
}

///operator +
Residence operator+(int a, Residence obj)
{
    Residence aux(obj);
    if(aux.NrRezidenti!=NULL)
    {
        delete [] aux.NrRezidenti;
    }
    aux.NrRezidenti= new int [aux.nrCamere+1];
    for(int i=0; i<obj.nrCamere; i++)
    {
        aux.NrRezidenti[i]=obj.NrRezidenti[i];

    }
    aux.NrRezidenti[obj.nrCamere]=a;
    aux.nrCamere++;
    return aux;
}

///operator +
Residence Residence::operator+(const Residence &r)
{
    Residence aux(*this);
    aux.valoare=this->valoare+aux.valoare;
    return aux;
}

///operator +
Residence Residence::operator+(int x)
{
    Residence aux(*this);
    aux.valoare+=x;
    return aux;
}

///operator -
Residence Residence::operator-(const Residence &obj)
{
    Residence temp(*this);
    temp.valoare=temp.valoare-obj.valoare;
    return temp;
}

///operator -
Residence Residence::operator-(float valoare)
{
    Residence aux(*this);
    aux.valoare=aux.valoare-valoare;
    return aux;
}

///operaor <
bool Residence::operator<(const Residence& obj)
{
    if(this->valoare<obj.valoare)
        return true;
    return false;
}

///operator cast
Residence::operator int()
{
    return this->valoare;
}
Residence::operator int() const
{
    return this->valoare;

}

///updatez pretul Residence in functie de datele financiare din acel an
void Residence::adaug(Residence& objResidence, Financiar& objFinanciar)
{
    objResidence.setValoare(objResidence.getValoare() + objFinanciar.getProfit() - objFinanciar.getDatorii());
}

///destructor
Residence::~Residence()
{
    if(this->NrRezidenti!=NULL)
    {
        delete[] this->NrRezidenti;
        this->NrRezidenti=NULL;
    }
    if(this->NumeCladire!=NULL)
    {
        delete[] this->NumeCladire;
        this->NumeCladire=NULL;
    }

    this->proprietar="ANONIM";
    this->valoare=0;

    this->nrCamere=0;
    this->NrRezidenti=NULL;

    this->soldOut=true;
    this->cladirePrincipala='-';
}

///----------------------------------------------------------------

int main()
{
    Residence listaResidence[1000];
    Apartament listaApartamente[1000];
    Chirias listaChiriasi[1000];
    Financiar listaFinanciar[1000];

    /*
    Residence R1, R2;
    Chirias C;
    Apartament A;
    Financiar F;
    //int v[]={2019,2020};
    char n[]= {"Alexandru"};
    Chirias C2(n, "Andrei", 200, 155, 19);

    char n1[]= {"Alexandru"};
    Chirias C3(n1, "Andrei", 200, 155, 19);

    //cout<<C2<<endl<<C3<<endl;
    //cout<<C3+5;


    //cout<<C3<<endl;
    //C3.afisare();


    //cout<<endl;

    R1.citire();
    //R2.citire();
    //cout<<endl;
    R1.afisare();
    cout<<endl;
    cout<<R1<<endl;
    //cout<<R1+2;
    //R2.afisare();
    //Residence res=R1+R2;
    //cout<<res<<endl;
    //cout<<endl;
    //R.tipResidence();
    //cout<<endl;

    //cout<<endl<<R1;
    //cout<<endl<<C3;

    //A.citire();
    //cout<<endl;
    //A.afisare();
    //cout<<endl;
    //R1.adaug(Residence& objResidence, Chirias& objChirias);
    //A.dimensiune();
    //cout<<endl;


    F.citire();
    cout<<endl;
    F.afisare();
    //cout<<endl;
    //F.analiza();
    R1.adaug(R1,F);
    cout<<R1<<endl;
    //++R1;
    //cout<<R1;
    //R1.tipResidence();
    */


    int contor=0, contor1=0, contor2=0, contor3=0;
    int k=1;
    while(k==1)
    {
        int comanda;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"1-Citeste Obiect Residence";
        cout<<"\n2-Afiseaza Lista Obiecte Residence";
        cout<<"\n3-Updateaza Un Obiect Residence";
        cout<<"\n4-Sterge Un Obiect Residence";
        cout<<"\n5-Afla Tipul De Residence"<<endl;

        cout<<"\n6-Citeste Obiect Apartament";
        cout<<"\n7-Afiseaza Lista Obiecte Apartament";
        cout<<"\n8-Updateaza Un Obiect Apartament";
        cout<<"\n9-Sterge un Obiect Apartament";
        cout<<"\n10-Afla Tipul De Apartament"<<endl;


        cout<<"\n11-Citeste Obiect Chirias";
        cout<<"\n12-Afiseaza Lista Obiecte Chirias";
        cout<<"\n13-Updateaza Un Obiect Chiriasi";
        cout<<"\n14-Sterge Un Obiect Chirias";
        cout<<"\n15-Afla Etajul Unde Sta Un Chirias"<<endl;

        cout<<"\n16-Citeste Obiect Financiar";
        cout<<"\n17-Afiseaza Lista Obiecte Financiar";
        cout<<"\n18-Updateaza Un Obiect Financiar";
        cout<<"\n19-Sterge Un Obiect Financiar";
        cout<<"\n20-Analiza Financiara A Unei Companii"<<endl;

        cout<<"\n22-Adauga Date Financiare La Obiectul Din Clasa Residence"<<endl;
        cout<<"\n23-STOP"<<endl;
        cout<<"----------------------------------------------------"<<endl;


        cin>>comanda;

        switch (comanda)
        {
        case 1:
        {
            Residence r;
            cin>>r;
            listaResidence[contor]=r;
            contor++;
            break;
        }

        case 2:
        {
            //system("CLS");
            for(int i=0; i<contor; i++)
                cout<<listaResidence[i]<<endl;
            break;
        }

        case 3:
        {
            //system("CLS");
            int a;
            cout<<endl<<"Ce ID are obiectul din Residence pe care vrei sa il schimbi?"<<endl;
            cin>>a;

            string prop;
            cout<<"Prenumele noului proprietar este: ";
            cin>>prop;
            listaResidence[a].setProprietar(prop);

            float val;
            cout<<"Valoarea noii cladiri este: ";
            cin>>val;
            listaResidence[a].setValoare(val);

            char ch;
            cout<<"Initiala noii cladiri principale este: ";
            cin>>ch;
            listaResidence[a].setCladirePrincipala(ch);
            cout<<endl;

            break;
        }

        case 4:
        {
            //system("CLS");
            int m;
            cout<<endl<<"Sterge obiectul cu ID-ul: ";
            cin>>m;
            if(m<contor)
            {
                for(int i=m; i<contor-1; i++)
                    listaResidence[i]=listaResidence[i+1];
            contor--;
            cout<<endl<<"OBIECTUL A FOST STERS!"<<endl;
            }
            else
                cout<<"Obiectul NU exista!"<<endl;

            break;
        }

        case 5:
        {
            //system("CLS");
            for(int i=0; i<contor; i++)
                listaResidence[i].tipResidence();
            cout<<endl;
            break;
        }

        case 6:
        {
            Apartament a;
            cin>>a;
            listaApartamente[contor1]=a;
            contor1++;

            break;
        }

        case 7:
        {
            //system("CLS");
            for(int i=0; i<contor1; i++)
                cout<<listaApartamente[i]<<endl;
            break;
        }

        case 8:
        {
            system("CLS");
            int id;
            cout<<"ID-ul apartamentului pe care vrei sa il modifici este: ";
            cin>>id;

            int l;
            cout<<"Noul numar de locuitori este: ";
            cin>>l;
            listaApartamente[id].setNrLocuitori(l);

            float a;
            cout<<"Noul pret al apartamentului este: ";
            cin>>a;
            listaApartamente[id].setPret(a);
            cout<<endl;

            break;
        }

        case 9:
        {
            //system("CLS");
            int m;
            cout<<endl<<"Sterge obiectul cu ID-ul: ";
            cin>>m;
            if(m<contor1)
            {
                for(int i=m; i<contor1-1; i++)
                    listaApartamente[i]=listaApartamente[i+1];
                contor1--;
                cout<<endl<<"OBIECTUL A FOST STERS!"<<endl;
            }
            else
                cout<<"Obiectul NU exista!"<<endl;

            break;
        }

        case 10:
        {
            //system("CLS");
            for(int i=0; i<contor1; i++)
                listaApartamente[i].dimensiune();
            cout<<endl;

            break;
        }

        case 11:
        {
            Chirias c;
            cin>>c;
            listaChiriasi[contor2]=c;
            contor2++;

            break;
        }

        case 12:
        {
            //system("CLS");
            for(int i=0; i<contor2; i++)
                cout<<listaChiriasi[i]<<endl;

            break;
        }
        case 13:
        {
            //system("CLS");
            int a;
            cout<<endl<<"Ce ID are obiectul din Chirias pe care vrei sa il modifici?"<<endl;
            cin>>a;

            int dat;
            cout<<"Noile datorii pe care le are chiriasul sunt in valoare de: (euro) ";
            cin>>dat;
            listaChiriasi[a].setDatorii(dat);

            int pr;
            cout<<"Noua perioada in care este cazat chiriasul este: (luni) ";
            cin>>pr;
            listaChiriasi[a].setPerioada(pr);

            break;
        }

        case 14:
        {
            //system("CLS");
            int m;
            cout<<endl<<"Sterge obiectul cu ID-ul: ";
            cin>>m;
            if(m<contor2)
            {
                for(int i=m; i<contor2-1; i++)
                    listaChiriasi[i]=listaChiriasi[i+1];

                contor2--;
                cout<<endl<<"OBIECTUL A FOST STERS!"<<endl;
            }
            else
                cout<<"Obiectul NU exista!"<<endl;
            break;
        }
        case 15:
        {
            //system("CLS");
            for(int i=0; i<contor2; i++)
            {
                listaChiriasi[i].etaj();
                cout<<endl;
            }

            break;
        }
        case 16:
        {
            Financiar f;
            cin>>f;
            listaFinanciar[contor3]=f;
            contor3++;

            break;
        }

        case 17:
        {
            //system("CLS");
            for(int i=0; i<contor3; i++)
                cout<<listaFinanciar[i]<<endl;

            break;
        }

        case 18:
        {
            //system("CLS");
            int a;
            cout<<endl<<"Ce ID are obiectul din Financiar pe care vrei sa il schimbi?"<<endl;
            cin>>a;

            float pr;
            cout<<"Noul profit al companiei sunt in valoare de: (milioane de euro) ";
            cin>>pr;
            listaFinanciar[a].setProfit(pr);

            float dt;
            cout<<"Noile datorii al companiei sunt in valoare de: (milioane de euro) ";
            cin>>dt;
            listaFinanciar[a].setDatorii(dt);

            break;
        }

        case 19:
        {
            system("CLS");
            int m;
            cout<<endl<<"Sterge obiectul cu ID-ul: ";
            cin>>m;
            if(m<contor3)
            {
                for(int i=m; i<contor3-1; i++)
                    listaFinanciar[i]=listaFinanciar[i+1];
                contor3--;
                cout<<endl<<"OBIECTUL A FOST STERS!"<<endl;
            }
            else
                cout<<"Obiectul NU exista!"<<endl;

            break;
        }

        case 20:
        {
            system("CLS");
            for(int i=0; i<contor3; i++)
            {
                cout<<"Analiza financiara pentru compania "<<i<<endl;
                listaFinanciar[i].analiza();
                cout<<endl;
            }

            break;
        }

        case 22:
        {
            int i,j;
            cout<<"INTRODU ID RESIDENCE PE CARE VREI SA O UPDATEZI:";
            cin>>i;
            cout<<endl<<"INTRODU ID FINANCIAR PE CARE VREI SA O UTILIZEZI:";
            cin>>j;
            listaResidence[i].adaug(listaResidence[i],listaFinanciar[j]);
            break;


        }

        case 23:
        {

            k=0;

            break;
        }
        default:
        {
            cout<<"\n\tComanda Necunoscuta"<<endl;
        }


        }

    }
    return 0;
}
