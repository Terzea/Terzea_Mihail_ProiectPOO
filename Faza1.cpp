#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//domeniul alimentatie

class Fruct {
	const int idFruct;
	string denumire;
	float greutate;
	int nrProduse;
	float* pret;
public:

	static float TVA;
	static int contor;

	//Constr fara parametrii
	Fruct() :idFruct(contor++)
	{
		this->denumire = "Mar";
		this->greutate = 2.5;
		this->nrProduse = 0;
		this->pret = NULL;
	}

	//Constr cu 2 parametrii
	Fruct(string denumire, float greutate) :idFruct(contor++)
	{
		this->denumire = denumire;
		this->greutate = greutate;
		this->nrProduse = 0;
		this->pret = NULL;
	}

	//Constr cu toti paramterii
	Fruct(string denumire, float greutate, int nrProduse, float* pret) :idFruct(contor++)
	{
		this->denumire = denumire;
		this->greutate = greutate;
		this->nrProduse = nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0;i < this->nrProduse;i++)
		{
			this->pret[i] = pret[i];
		}
	}

	~Fruct()
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
	}

	void afisare()
	{
		cout << "Denumirea fructului este: " << this->denumire << ", nr de kg " << this->greutate << " , are nr de produse " << this->nrProduse << " si pretul pentru fiecare produs este: ";
		for (int i = 0;i < this->nrProduse;i++)
		{
			cout << this->pret[i] << " ";
		}
		cout << "Fructul are TVA-ul: " << this->TVA;
		cout << endl;
	}

	static void setTVA(float TVA) 
	{
		Fruct::TVA = TVA;
	}

};

	
class Bautura {
	const int id;
	string marca;
	char* categorie;
	bool esteCuAcid;
	int cantitate;

public:
	static int contor;
	static float TVA;

	//Constr fara parametrii
	Bautura() :id(contor++)
	{
		this->marca = "Borsec";
		this->categorie = new char[strlen("Apa minerala") + 1];
		strcpy(this->categorie, "Apa minerala");
		this->esteCuAcid = 1;
		this->cantitate = 5;

	}

	//Constr cu 2 parametrii
	Bautura(string marca, const char* categorie) :id(contor++)
	{
		this->marca = marca;
		this->categorie = new char[strlen(categorie) + 1];
		strcpy(this->categorie, categorie);
		this->esteCuAcid = 0;
		this->cantitate = 3;

	}

	//Constr cu toti parametrii
	Bautura(string marca, const char* categorie, bool esteCuAcid, int cantitate) :id(contor++)
	{
		this->marca = marca;
		this->categorie = new char[strlen(categorie) + 1];
		strcpy(this->categorie, categorie);
		this->esteCuAcid = esteCuAcid;
		this->cantitate = cantitate;
	}

	~Bautura()
	{
		if (this->categorie != NULL)
		{
			delete[]this->categorie;
		}
	}

	void afisare()
	{
		cout << "Bautura are marca: " << this->marca << " , categoria este: " << this->categorie << " , este cu acid: " << this->esteCuAcid << " si are cantitatea de: " << this->cantitate;
		cout << " Bautura are TVA-ul: " << this->TVA;
		cout << endl;
	}

	static void setTVA(float TVA)
	{
		Bautura::TVA = TVA;
	}
};

class Prajitura {
		const int id;
		string denumire;
		int calorii;
		int nrProduse;
		float* pret;

	public:
		static int contor;
		static float TVA;

		//Constr fara parametrii
		Prajitura() :id(contor++)
		{
			this->denumire = "Ecler";
			this->calorii = 261;
			this->nrProduse = 0;
			this->pret = NULL;
		}

		//Constr cu doi parametri
		Prajitura(string denumire,int calorii) :id(contor++)
		{
			this->denumire = denumire;
			this->calorii = calorii;
			this->nrProduse = 0;
			this->pret = NULL;
		}

		//Constr cu toti parametrii
		Prajitura(string denumire, int calorii, int nrProduse, float* pret) :id(contor++)
		{
			this->denumire = denumire;
			this->calorii = calorii;
			this->nrProduse = nrProduse;
			this->pret = new float[this->nrProduse];
			for (int i = 0;i < this->nrProduse;i++)
			{
				this->pret[i] = pret[i];
			}
			
		}

		~Prajitura()
		{
			if (this->pret != NULL)
			{
				delete[]this->pret;

			}
	}

		void afisare()
		{
			cout << "Denumirea prajiturii este: " << this->denumire << " ,contine numarul de calorii: " << this->calorii << " ,are nr produse " << this->nrProduse << " si are pretul de:  ";
			for (int i = 0;i < this->nrProduse;i++)
			{
				cout << this->pret[i] << " ";

			}
			cout << "Prajitura are TVA-ul: " << this->TVA;
			cout << endl;

		}

		static void setTVA(float TVA)
		{
			Prajitura::TVA = TVA;
		}

};


int Fruct::contor = 1;
float Fruct::TVA = 0.9;
int Bautura::contor = 1;
float Bautura::TVA = 0.9;
int Prajitura::contor = 1;
float Prajitura::TVA = 0.9;



void main() 
{
	Fruct f;
	Fruct f1("Para", 1.2);
	float vector1[] = { 20.5,19,10 };
	Fruct f2("Portocala", 1.5, 3, vector1);

	f.afisare();
	cout << endl << endl;
	f1.afisare();
	cout << endl << endl;
	f2.afisare();
	cout << endl << endl;

	Bautura b;
	Bautura b1("Fanta", "Portocale");
	Bautura b2("Coca-cola", "Zero zahar", 1, 30);

	b.afisare();
	cout << endl << endl;
	b1.afisare();
	cout << endl << endl;
	b2.afisare();
	cout << endl << endl;

	Prajitura p;
	Prajitura p1("Tiramisu", 210);
	float vector2[] = { 14.5,20.3,25,11 };
	Prajitura p2("Televizor", 310, 4, vector2);

	p.afisare();
	cout << endl << endl;
	p1.afisare();
	cout << endl << endl;
	p2.afisare();
	cout << endl << endl;

	Fruct::setTVA(0.1);
	f.afisare();
	cout << endl << endl;
	f1.afisare();
	cout << endl << endl;
	f2.afisare();
	cout << endl << endl;

	Bautura::setTVA(0.15);
	b.afisare();
	cout << endl << endl;
	b1.afisare();
	cout << endl << endl;
	b2.afisare();
	cout << endl << endl;

	Prajitura::setTVA(0.2);
	p.afisare();
	cout << endl << endl;
	p1.afisare();
	cout << endl << endl;
	p2.afisare();
	cout << endl << endl;

}