#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("date.in");

class Discount
{
    int procent;
    char categorie[50];

    public:

        Discount(int procent = 0, char categorie[] = "")
        {
            this->procent = procent;
            strcpy(this->categorie, categorie);
        }

        int getProcent()
        {
            return procent;
        }

        void getCategorie(char* output)
        {
            strcpy(output, categorie);
        }

        void setProcent(int input)
        {
            procent = input;
        }

        void setCategorie(char input[])
        {
            strcpy(categorie, input);
        }
};

class Adresa
{

    char strada[50], blocul[20], scara[20];
    int numar_strada, numar_locuinta;

    public:

        Adresa()
        {
            strcpy(strada, "");
            strcpy(blocul, "");
            strcpy(scara, "");
            numar_strada = numar_locuinta = 0;
        }

        Adresa(char strada[], int numar_strada,
        int numar_locuinta, char blocul[20] = "",
        char scara[20] = "")
        {
            strcpy(this->strada, strada);
            strcpy(this->blocul, blocul);
            strcpy(this->scara, scara);
            this->numar_strada = numar_strada;
            this->numar_locuinta = numar_locuinta;
        }

        void getStrada(char* output)
        {
            strcpy(output, strada);
        }

        void getBlocul(char* output)
        {
            strcpy(output, blocul);
        }

        void getScara(char* output)
        {
            strcpy(output, scara);
        }

        int getNumar_Strada()
        {
            return numar_strada;
        }

        int getNumar_Locuinta()
        {
            return numar_locuinta;
        }

        void setStrada(char input[])
        {
            strcpy(strada, input);
        }

        void setBlocul(char input[])
        {
            strcpy(blocul, input);
        }

        void setScara(char input[])
        {
            strcpy(scara, input);
        }

        void setNumar_Strada(int input)
        {
            numar_strada = input;
        }

        void setNumar_Locuinta(int input)
        {
            numar_locuinta = input;
        }

        Adresa(const Adresa& adresa);
        Adresa& operator = (const Adresa& adresa);
        friend ostream & operator << ( ostream & out, const Adresa& adresa );

};

ostream & operator << ( ostream & out, const Adresa& adresa )
{
    out << "Strada: "<<adresa.strada<<", numarul: "<<adresa.numar_strada<<", ";

    if ( strcmp(adresa.blocul, "") != 0 )
        out<<"blocul: "<<adresa.blocul<<", scara: "<<adresa.scara<<", ";

    out<<"numar locuinta: "<<adresa.numar_locuinta<<endl;

    return out;
}

Adresa::Adresa(const Adresa& adresa)
        {
            strcpy(strada, adresa.strada);
            strcpy(blocul, adresa.blocul);
            strcpy(scara, adresa.scara);
            numar_strada = adresa.numar_strada;
            numar_locuinta = adresa.numar_locuinta;
        }

Adresa& Adresa::operator = (const Adresa& adresa)
{

    if ( this != &adresa )
    {
        strcpy(strada, adresa.strada);
            strcpy(blocul, adresa.blocul);
            strcpy(scara, adresa.scara);
            numar_strada = adresa.numar_strada;
            numar_locuinta = adresa.numar_locuinta;
    }

    return *this;
}

class Produs
{

    char nume[50], descriere[50], categorie[50];
    float pret;

    public:
        Produs()
        {
            strcpy(nume, "");
            strcpy(descriere, "");
            strcpy(categorie, "");
            pret = 0;
        }

        Produs(char nume[], char categorie[], float pret, char descriere[] = "")
        {
            strcpy(this->nume, nume);
            strcpy(this->categorie, categorie);
            strcpy(this->descriere, descriere);
            this->pret = pret;
        }

        void getNume(char* output)
        {
            strcpy(output, nume);
        }

        void getDescriere(char* output)
        {
            strcpy(output, descriere);
        }

        void getCategorie(char* output)
        {
            strcpy(output, categorie);
        }

        float getPret()
        {
            return pret;
        }

        void setNume(char input[])
        {
            strcpy(nume, input);
        }

        void setDescriere(char input[])
        {
            strcpy(descriere, input);
        }

        void setCategorie(char input[])
        {
            strcpy(categorie, input);
        }

        void setPret(float input)
        {
            pret = input;
        }

        friend ostream & operator << ( ostream & out, const Produs& produs );

};

ostream & operator << ( ostream & out, const Produs& produs )
{
    out<<"Nume produs: "<<produs.nume<<", ";

    if ( strcmp(produs.descriere, "") != 0 )
        out<<"descriere: "<<produs.descriere<<", ";

    out<<"categorie: "<<produs.categorie<<", pret: "<<produs.pret<<endl;

    return out;
}

class Cos
{

    Produs* produse;
    Discount discount;
    int numar_produse;
    float suma_totala;

    public:

        Cos()
        {
            numar_produse = suma_totala = 0;
            produse = NULL;
        }

        ~Cos()
        {
            if ( produse != NULL )
                delete[] produse;
        }

        Cos(const Cos& cos)
        {
            numar_produse = cos.numar_produse;
            suma_totala = cos.suma_totala;
            discount = cos.discount;
            produse = new Produs[numar_produse];

            for ( int i = 0; i < numar_produse; i++)
            {
                produse[i] = cos.produse[i];
            }
        }

        void adauga_produs(const Produs& produs);
        void scoate_produs(int pozitie);
        void valoare_produse();
        void valoare_dupa_discount();
        void adaugare_discount(int procent, char categorie[]);
        Cos& operator = (const Cos& cos);

        int getNumar_Produse()
        {
            return numar_produse;
        }

        float getSuma_Totala()
        {
            return suma_totala;
        }

};

void Cos::adauga_produs(const Produs& produs)
{
    if ( produse == NULL )
            {
                numar_produse++;
                produse = new Produs[numar_produse];
                produse[0] = produs;
            }
            else
            {
                Produs* aux = new Produs[numar_produse + 1];

                for( int i = 0; i < numar_produse; i++)
                {
                    aux[i] = produse[i];
                }

                aux[numar_produse] = produs;
                numar_produse++;
                delete[]produse;
                produse = aux;

            }
}

void Cos::scoate_produs(int pozitie)
{
    if ( produse != NULL)
    {
        if ( pozitie <= numar_produse)
        {
            Produs* aux = new Produs[numar_produse - 1];

            for ( int i = 0; i < numar_produse; i++ )
                if ( i != ( pozitie - 1 ) )
                    aux[i] = produse[i];

            numar_produse--;
            delete[] produse;
            produse = aux;
        }
        else
        {
            cout<<"Nu exista un produs pe pozitia "<<pozitie<<".\n";
        }
    }
    else
        cout<<"Cosul este deja gol.\n";
}

void Cos::valoare_produse()
{
    suma_totala = 0;

    for( int i = 0; i < numar_produse; i++)
    {
        suma_totala += produse[i].getPret();
    }
    
}

void Cos::valoare_dupa_discount()
{
    if (discount.getProcent() != 0)
    {
        suma_totala = 0;

        for(int  i = 0; i < numar_produse; i++)
        {
            char cat_prod[50], cat_discount[50];
            produse[i].getCategorie(cat_prod);
            discount.getCategorie(cat_discount);

            if (strcmp(cat_prod, cat_discount) == 0 || strcmp(cat_discount, "toate") == 0)
            {
                suma_totala += ( produse[i].getPret() - produse[i].getPret() * discount.getProcent() / 100 );
            }
            else
            {
                suma_totala += produse[i].getPret();
            }
        }
    }
    else
    {
        valoare_produse();
    }
}

void Cos::adaugare_discount(int procent, char categorie[])
{
    discount.setProcent(procent);
    discount.setCategorie(categorie);
}

Cos& Cos::operator = (const Cos& cos)
{
    if ( this != &cos )
    {
        discount = cos.discount;
        numar_produse = cos.numar_produse;
        suma_totala = cos.suma_totala;

        if ( produse != NULL)
            delete[] produse;

        produse = new Produs[numar_produse];

        for ( int i = 0; i < numar_produse; i++)
        {
            produse[i] = cos.produse[i];
        }
    }
 
    return *this;
}

class Utilizator
{

    char nume[50], prenume[50], username[50], parola[50], email[50];
    Cos cos;
    Adresa* adrese;
    int numar_adrese;

    public:

        Utilizator()
        {
            adrese = NULL;
            numar_adrese = 0;
            strcpy(nume, "");
            strcpy(prenume, "");
            strcpy(username, "");
            strcpy(parola, "");
            strcpy(email, "");
        }

        Utilizator(char username[], char parola[], char email[] = "", char nume[] = "", char prenume[] = "")
        {
            adrese = NULL;
            numar_adrese = 0;
            strcpy(this->nume, nume);
            strcpy(this->prenume, prenume);
            strcpy(this->username, username);
            strcpy(this->parola, parola);
            strcpy(this->email, email);

        }

        ~Utilizator()
        {
            if ( adrese != NULL )
                delete[] adrese;
        }

        void adauga_adresa(const Adresa& adresa);
        void sterge_adresa(int pozitie);
        
        void getNume(char* output)
        {
            strcpy(output, nume);
        }

        void getPrenume(char* output)
        {
            strcpy(output, prenume);
        }

        void getUsername(char* output)
        {
            strcpy(output, username);
        }

        void getParola(char* output)
        {
            strcpy(output, parola);
        }

        void getEmail(char* output)
        {
            strcpy(output, email);
        }
        
        void setNume(char input[])
        {
            strcpy(nume, input);
        }

        void setPrenume(char input[])
        {
            strcpy(prenume, input);
        }

        void setUsername(char input[])
        {
            strcpy(username, input);
        }

        void setParola(char input[])
        {
            strcpy(parola, input);
        }

        void setEmail(char input[])
        {
            strcpy(email, input);
        }

        void afisare_adrese();

};

void Utilizator::adauga_adresa(const Adresa& adresa)
{
    if ( adrese == NULL )
    {
        numar_adrese = 1;
        adrese = new Adresa[numar_adrese];

        adrese[0] = adresa;
    }
    else
    {
        Adresa* aux = new Adresa[numar_adrese + 1];

        for ( int i = 0; i < numar_adrese; i++)
        {
            aux[i] = adrese[i];
        }

        aux[numar_adrese] = adresa;
        numar_adrese++;
        delete[] adrese;
        adrese = aux;
    }
}

void Utilizator::sterge_adresa(int pozitie)
{
    if ( adrese != NULL )
    {
        if ( pozitie <= numar_adrese )
        {
            Adresa* aux = new Adresa[numar_adrese - 1];

            for ( int i = 0; i < numar_adrese; i++ )
            {            
                if ( i != ( pozitie - 1 ) )
                {
                    aux[i] = adrese[i];
                }
            }

            numar_adrese--;
            delete[] adrese;
            adrese = aux;
        }
        else
        {
            cout<<"Nu exista o adresa pe pozitia "<<pozitie<<".\n";
        }
    }
    else
    {
        cout<<"Nu exista nicio adresa care poate fi stearsa";
    }
}

void Utilizator::afisare_adrese()
{
    for ( int i = 0; i < numar_adrese; i++ )
    {
        cout<<adrese[i];
    }
}

void testare()
{
    Cos cos, cos2;

    Produs produs("Aspirator", "Casnic", 250);
    Produs prod("Periuta", "Igiena", 100);
    Produs prod2("Laptop", "Tech", 4000);
    Produs prod3("iPhone", "Tech", 3500);

    char nume[50], categorie[50], descriere[50];

    produs.getNume(nume);
    produs.getCategorie(categorie);
    produs.getDescriere(descriere);

    cos.adauga_produs(produs);
    cos.valoare_produse();
    cout<<cos.getSuma_Totala()<<endl;

    cos.adauga_produs(prod);
    cos.valoare_produse();
    cout<<cos.getSuma_Totala()<<endl;
    
    cos.adaugare_discount(20, "Igiena");
    cos.valoare_dupa_discount();
    cout<<cos.getSuma_Totala()<<endl;

    cos2.adauga_produs(prod2);
    cos2.adauga_produs(prod3);

    cout<<endl;

    cos = cos2;
    cos.valoare_produse();
    cout<<cos.getSuma_Totala()<<endl;

    cos.adaugare_discount(50, "Tech");
    cos.valoare_dupa_discount();
    cout<<cos.getSuma_Totala()<<endl;

    cos.scoate_produs(2);
    cos.valoare_dupa_discount();
    cout<<cos.getSuma_Totala()<<endl;

    Utilizator Marcel;
    Adresa adresa("Victoriei", 10, 20);
    Adresa adresa2("Plevnei", 15, 3);
    Marcel.adauga_adresa(adresa);
    Marcel.adauga_adresa(adresa2);
    Marcel.afisare_adrese();

    cout<<prod2;


}

int main()
{

    testare();

    fin.close();

    return 0;
}

