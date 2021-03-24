#include <iostream>
#include <math.h>

using namespace std;
class masina
{
protected:
    int anul_inceperii_productiei;
    char nume_model[40];
    int viteza_maxima;
    int greutate;
public:
    virtual void citire_masina();
    virtual void afisare_masina();

    friend istream& operator>>(istream &in,masina &ob)
    {
        ob.citire_masina();
        return in;
    }
    friend ostream& operator<<(ostream &out,masina &ob)
    {
        ob.afisare_masina();
        return out;
    }

};
void masina::citire_masina()
{
    cout<<"introdu anul_inceperii_productiei"<<endl;
    cin>>anul_inceperii_productiei;
    cout<<"introdu nume_model"<<endl;
    cin>>nume_model;
    cout<<"introdu viteza_maxima"<<endl;
    cin>>viteza_maxima;
    cout<<"introdu greutate"<<endl;
    cin>>greutate;
}
void masina::afisare_masina()
{
    cout<<"anul_inceperii_productiei"<<endl;
    cout<<anul_inceperii_productiei<<endl;
    cout<<"nume_model"<<endl;
    cout<<nume_model<<endl;
    cout<<"viteza_maxima"<<endl;
    cout<<viteza_maxima<<endl;
    cout<<"greutate"<<endl;
    cout<<greutate<<endl;
}














class masini_pe_combustibil:virtual public masina
{
protected:
    char tip_conbustibil[30]; //benzina sau motorina
    float capacitate_rezervor;
public:

    void citire_masina();
    void afisare_masini();

    int autonomie_combustibil()
    {
        return capacitate_rezervor/sqrt(greutate);
    }
};
void masini_pe_combustibil::citire_masina()
{
    cout<<"CITIRE MASINA PE COMBUSTIBIL"<<endl;
    masina::citire_masina();
    cout<<"introdu tip_conbustibil"<<endl;
    cin>>tip_conbustibil;
    cout<<"introdu capacitate_rezervor"<<endl;
    cin>>capacitate_rezervor;
}
void masini_pe_combustibil::afisare_masini()
{
    cout<<"AFISARE MASINA PE COMBUSTIBIL"<<endl;
    masina::afisare_masina();

    cout<<"tip_conbustibil"<<endl;
    cout<<tip_conbustibil<<endl;
    cout<<"capacitate_rezervor"<<endl;
    cout<<capacitate_rezervor<<endl;
}















class masini_electrice:virtual public masina
{
protected:
    int capacitate_baterie;

public:
    void citire_masini();
    void afisare_masini();

    int autonomie_electrice()
    {
        return capacitate_baterie/(greutate*greutate);
    }

};
void masini_electrice::citire_masini()
{
    cout<<"CITIRE MASINI ELECTRICE"<<endl;
    masina::citire_masina();

    cout<<"introdu capacitate_baterie:"<<endl;
    cin>>capacitate_baterie;




}
void masini_electrice::afisare_masini()
{
    cout<<"AFISARE MASINI ELECTRICE"<<endl;
    masina::afisare_masina();

    cout<<"capacitate_baterie:"<<endl;
    cout<<capacitate_baterie<<endl;
}










class masini_hibride:public masini_pe_combustibil,public masini_electrice
{
public:
    void citire_masina()
    {
        cout<<"CITIRE MASINI HIBRID"<<endl;
        masina::citire_masina();

        //de la benzina
        cout<<"introdu tip_conbustibil"<<endl;
        cin>>tip_conbustibil;
        cout<<"introdu capacitate_rezervor"<<endl;
        cin>>capacitate_rezervor;

        //de la electrica
        cout<<"introdu capacitate_baterie:"<<endl;
        cin>>capacitate_baterie;

    }
    void afisare_masina()
    {
        cout<<"AFISARE MASINI HIBRID"<<endl;
        masina::afisare_masina();

        //de la benzina
        cout<<"tip_conbustibil"<<endl;
        cout<<tip_conbustibil<<endl;
        cout<<"capacitate_rezervor"<<endl;
        cout<<capacitate_rezervor<<endl;

        //de la electrica
        cout<<"capacitate_baterie:"<<endl;
        cout<<capacitate_baterie<<endl;
    }

    int autonomie_hibrid()
    {
        return autonomie_combustibil()+autonomie_electrice();
    }
};












template <class T>
class tranzactie
{
private:
    char nume_client[30];
    int data_tranzactie;
    int cate_modele;
    T *modele_actizitionate; //vector
public:
    tranzactie(int nr=0)
    {
        try
        {
            modele_actizitionate=new T[nr];
            cate_modele=nr;


            if(cate_modele<10)
                throw 10;
        }
        catch(int x)
        {
            cout<<"numere negative"<<endl;
        }

    }
    /*
    tranzactie(const tranzactie &ob)
    {
        for(int i=0; i<ob.cate_modele; i++)
            modele_actizitionate[i]=ob.modele_actizitionate[i];
        cate_modele=ob.cate_modele;
    }
    */
    ~tranzactie()
    {
        delete []modele_actizitionate;
    }

    void citire_tranzactie()
    {

        cout<<"introdu nume_client"<<endl;
        cin>>nume_client;
        cout<<"introdu data_tranzactie"<<endl;
        cin>>data_tranzactie;
        cout<<"cate modele? "<<endl;
        cin>>cate_modele;

        modele_actizitionate=new T[cate_modele];

        for(int i=0; i<cate_modele; i++)
            cin>>modele_actizitionate[i];

    }
    void afisare_tranzactie()
    {
        cout<<"nume_client"<<endl;
        cout<<nume_client<<endl;
        cout<<"data_tranzactie"<<endl;
        cout<<data_tranzactie<<endl;


        for(int i=0; i<cate_modele; i++)
            cout<<modele_actizitionate[i]<<endl;;
    }

};
int main()
{
    cout<<endl;
    cout<<"MASINI";
    cout<<endl;

    int nr;
    do
    {

        cout<<"optiunea 1 inregistrare masini pe combustibil"<<endl;
        cout<<"optiunea 2 inregistrare masini electrice"<<endl;
        cout<<"optiunea 3 inregistrare masini hibrid"<<endl;
        cout<<"optiunea 4 IESIRE"<<endl;
        cin>>nr;

        switch(nr)
        {
        case 1:
        {
            masini_pe_combustibil mc;
            mc.citire_masina();
            mc.afisare_masini();
            cout<<"Autonomia este: "<<endl;
            cout<<mc.autonomie_combustibil();
            cout<<endl;

        }
        break;

        case 2:
        {
            masini_electrice me;
            me.citire_masina();
            me.afisare_masina();
            cout<<"Autonomia este: "<<endl;
            cout<<me.autonomie_electrice();
            cout<<endl;
        }
        break;
        case 3:
        {
            masini_hibride mh;
            mh.citire_masina();
            mh.afisare_masina();
            cout<<"Autonomia este: "<<endl;
            cout<<mh.autonomie_hibrid();
            cout<<endl;
        }
        break;
        case 4:
        {
            cout<<"iesire"<<endl;
        }
        break;
        default:
            cout<<"numar gresit"<<endl;

        }

    }
    while(nr!=4);


    cout<<endl;
    cout<<"TRANZACTII";
    cout<<endl;

    int k;
    do
    {

        cout<<"optiunea 1 tranzactie masini pe combustibil"<<endl;
        cout<<"optiunea 2 tranzactie masini electrice"<<endl;
        cout<<"optiunea 3 tranzactie masini hibrid"<<endl;
        cout<<"optiunea 4 IESIRE"<<endl;
        cin>>k;

        switch(k)
        {
        case 1:
        {
            tranzactie<masini_pe_combustibil>MC;
            MC.citire_tranzactie();
            MC.afisare_tranzactie();

        }
        break;

        case 2:
        {
            tranzactie<masini_electrice>ME;
            ME.citire_tranzactie();
            ME.afisare_tranzactie();
        }
        break;
        case 3:
        {
            tranzactie<masini_hibride>MH;
            MH.citire_tranzactie();
            MH.afisare_tranzactie();
        }
        break;
        case 4:
        {
            cout<<"iesire"<<endl;
        }
        break;
        default:
            cout<<"numar gresit"<<endl;

        }

    }
    while(k!=4);


    return 0;
}
