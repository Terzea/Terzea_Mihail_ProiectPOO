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
	
	const int getIdFruct()
	{
		return this->idFruct;
	}
	string getDenumire()
	{
		return this->denumire;
	}
	float getGreutate()
	{
		return this->greutate;
	}
	float getNrProduse()
	{
		return this->nrProduse;
	}
	float* getPret()
	{
		return this->pret;
	}

	void setDenumire(string denumireNou) 
	{
		this->denumire = denumireNou;
	}

	void setGreutate(float greutateNoua)
	{
		this->greutate = greutateNoua;
	}

	void setProduse(int nrProduseNou, float* pretNou)
	{
		this->nrProduse = nrProduseNou;
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
		this->pret = new float[this->nrProduse];
		for (int i = 0;i < this->nrProduse;i++)
		{
			this->pret[i] = pretNou[i];
		}
	}

   //Constr de copiere

	Fruct(const Fruct& f) :idFruct(contor++)
	{
		this->denumire = f.denumire;
		this->greutate = f.greutate;
		this->nrProduse = f.nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0;i < this->nrProduse;i++)
		{
			this->pret[i] =f.pret[i];
		}
	}

   //metoda medie
	float mediePreturi()
	{
		float rezultat = 0;
		for (int i = 0; i < this->nrProduse; i++)
		{
			rezultat = rezultat + this->pret[i];
		}
		rezultat = rezultat / this->nrProduse;
		return rezultat;
	}

	//metoda ce ofera un discount unui anumit pret
	float discountProdus(int poz, float discount)
	{
		float rezultatDiscount;
		rezultatDiscount = this->pret[poz] - discount * this->pret[poz];
		return rezultatDiscount;
	}

	//metoda statica pt a oferi acces la atributul static
	static float getTVA() {
		return Fruct::TVA;
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

	const int getId()
	{
		return this->id;
	}
	string getMarca()
	{
		return this->marca;
	}
	const char* getCategorie()
	{
		return this->categorie;
	}
	bool getEsteCuAcid()
	{
		return this->esteCuAcid;
	}
	int getCantitate()
	{
		return this->cantitate;
	}

	void setMarca(string marcaNoua)
	{
		this->marca = marcaNoua;
	}
	void setCategorie(const char* categorieNoua)
	{
		if (this->categorie != NULL)
		{
			delete[]this->categorie;
		}
		this->categorie = new char[strlen(categorieNoua) + 1];
		strcpy(this->categorie, categorieNoua);
	}
	void setEsteCuAcid(bool esteCuAcid)
	{
		this->esteCuAcid = esteCuAcid;
	}
	void setCantitate(int cantitateNoua)
	{
		this->cantitate = cantitateNoua;
	}

	//Constructorul de copiere

	Bautura(const Bautura& b) :id(contor++)
	{
		this->marca = b.marca;
		this->categorie = new char[strlen(b.categorie) + 1];
		strcpy(this->categorie, b.categorie);
		this->esteCuAcid = b.esteCuAcid;
		this->cantitate = b.cantitate;
	}

	//metoda care creste cantitatea bauturii
	float crestereCantitate(int valoare)
	{
		int rezultatCantitate;
		rezultatCantitate = this->cantitate + valoare;
		return rezultatCantitate;
	}

	static float getTVA()
	{
		return Bautura::TVA;
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
	Prajitura(string denumire, int calorii) :id(contor++)
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

	const int getId() 
	{
		return this->id;
	}
	string getDenumire()
	{
		return this->denumire;
	}
	int getCalorii()
	{
		return this->calorii;
	}
	float getNrProduse()
	{
		return this->nrProduse;
	}
	float* getPret()
	{
		return this->pret;
	}
	
	void setDenumire(string denumireNoua)
	{
		this->denumire = denumireNoua;
	}
	void setCalorii(int caloriiNoi)  
	{
		 this->calorii = caloriiNoi;
	}
	void setProduse(int nrProduseNou, float* pretNou)
	{
		this->nrProduse = nrProduseNou;
		if (this->pret != NULL)
		{
			delete[]this->pret;

		}
		this->pret = new float[this->nrProduse];
		for (int i = 0;i < this->nrProduse;i++)
		{
			this->pret[i] = pretNou[i];
		}
	}

	//Const de copiere
	Prajitura(const Prajitura& p) :id(contor++)
	{
		this->denumire = p.denumire;
		this->calorii = p.calorii;
		this->nrProduse = p.nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0;i < this->nrProduse;i++)
		{
			this->pret[i] = p.pret[i];
		}
	}

	static float getTVA() {
		return Prajitura::TVA;
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
	float vector3[] = { 4.9,6,10,5.6 };
	Fruct f3("Banana", 5.2, 4, vector3);
	float vector4[] = { 6.7,4,9 };
	Fruct f4("Piersica", 7, 3, vector4);

	f.afisare();
	cout << endl << endl;
	f1.afisare();
	cout << endl << endl;
	f2.afisare();
	cout << endl << endl;

	Bautura b;
	Bautura b1("Fanta", "Portocale");
	Bautura b2("Coca-cola", "Zero zahar", 1, 30);
	Bautura b3("Sprite", "Zero Zahar", 1, 25);
	Bautura b4("Apa", "Plata", 0, 40);

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
	float vector10[] = { 23,14,6.7,9,12,10.5 };
	Prajitura p3("Amandina", 200, 6, vector10);

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

	cout << "Id fruct: " << f.getIdFruct() << endl;
	cout << "Denumire: " << f.getDenumire() << endl;
	cout << "Greutate: " << f.getGreutate() << endl;
	cout << "Numar produse: " << f.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f.getNrProduse();i++)
	{
		cout << f.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id fruct: " << f1.getIdFruct() << endl;
	cout << "Denumire: " << f1.getDenumire() << endl;
	cout << "Greutate: " << f1.getGreutate() << endl;
	cout << "Numar produse: " << f1.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f1.getNrProduse();i++)
	{
		cout << f1.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id fruct: " << f2.getIdFruct() << endl;
	cout << "Denumire: " << f2.getDenumire() << endl;
	cout << "Greutate: " << f2.getGreutate() << endl;
	cout << "Numar produse: " << f2.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f2.getNrProduse();i++)
	{
		cout << f2.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id fruct: " << f3.getIdFruct() << endl;
	cout << "Denumire: " << f3.getDenumire() << endl;
	cout << "Greutate: " << f3.getGreutate() << endl;
	cout << "Numar produse: " << f3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f3.getNrProduse();i++)
	{
		cout << f3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id fruct: " << f4.getIdFruct() << endl;
	cout << "Denumire: " << f4.getDenumire() << endl;
	cout << "Greutate: " << f4.getGreutate() << endl;
	cout << "Numar produse: " << f4.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f4.getNrProduse();i++)
	{
		cout << f4.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	f3.setDenumire("Rodie");
	f3.setGreutate(6.2);
	float vector6[] = { 5,8.3 };
	f3.setProduse(2, vector6);

	cout << "Id fruct: " << f3.getIdFruct() << endl;
	cout << "Denumire: " << f3.getDenumire() << endl;
	cout << "Greutate: " << f3.getGreutate() << endl;
	cout << "Numar produse: " << f3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f3.getNrProduse();i++)
	{
		cout << f3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	Fruct f5 = f4;
	cout << "Id fruct: " << f4.getIdFruct() << endl;
	cout << "Denumire: " << f4.getDenumire() << endl;
	cout << "Greutate: " << f4.getGreutate() << endl;
	cout << "Numar produse: " << f4.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f4.getNrProduse();i++)
	{
		cout << f4.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;
	cout << "Id fruct: " << f5.getIdFruct() << endl;
	cout << "Denumire: " << f5.getDenumire() << endl;
	cout << "Greutate: " << f5.getGreutate() << endl;
	cout << "Numar produse: " << f5.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < f5.getNrProduse();i++)
	{
		cout << f5.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;


	cout << "Id bautura: " << b.getId() << endl;
	cout << "Marca: " << b.getMarca() << endl;
	cout << "Categorie: " << b.getCategorie() << endl;
	cout << "Este cu acid? " << b.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b.getCantitate() << endl;
	cout << endl;

	cout << "Id bautura: " << b1.getId() << endl;
	cout << "Marca: " << b1.getMarca() << endl;
	cout << "Categorie: " << b1.getCategorie() << endl;
	cout << "Este cu acid? " << b1.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b1.getCantitate() << endl;
	cout << endl;

	cout << "Id bautura: " << b2.getId() << endl;
	cout << "Marca: " << b2.getMarca() << endl;
	cout << "Categorie: " << b2.getCategorie() << endl;
	cout << "Este cu acid? " << b2.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b2.getCantitate() << endl;
	cout << endl;

	cout << "Id bautura: " << b3.getId() << endl;
	cout << "Marca: " << b3.getMarca() << endl;
	cout << "Categorie: " << b3.getCategorie() << endl;
	cout << "Este cu acid? " << b3.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b3.getCantitate() << endl;
	cout << endl;

	cout << "Id bautura: " << b4.getId() << endl;
	cout << "Marca: " << b4.getMarca() << endl;
	cout << "Categorie: " << b4.getCategorie() << endl;
	cout << "Este cu acid? " << b4.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b4.getCantitate() << endl;
	cout << endl;

	b3.setMarca("Mirinda");
	b3.setCategorie("Portocale");
	b3.setEsteCuAcid(1);
	b3.setCantitate(10);

	cout << "Id bautura: " << b3.getId() << endl;
	cout << "Marca: " << b3.getMarca() << endl;
	cout << "Categorie: " << b3.getCategorie() << endl;
	cout << "Este cu acid? " << b3.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b3.getCantitate() << endl;
	cout << endl;

	Bautura b5 = b4;
	cout << endl << endl;
	cout << "Id bautura: " << b5.getId() << endl;
	cout << "Marca: " << b5.getMarca() << endl;
	cout << "Categorie: " << b5.getCategorie() << endl;
	cout << "Este cu acid? " << b5.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b5.getCantitate() << endl;
	cout << endl;
	
	cout << "Id prajitura: " << p.getId() << endl;
	cout << "Denumire: " << p.getDenumire() << endl;
	cout << "Numarul de calori: " << p.getCalorii() << endl;
	cout << "Nr de produse: " << p.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: "  << endl;
	for (int i = 0;i < p.getNrProduse();i++)
	{
		cout << p.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id prajitura: " << p1.getId() << endl;
	cout << "Denumire: " << p1.getDenumire() << endl;
	cout << "Numarul de calori: " << p1.getCalorii() << endl;
	cout << "Nr de produse: " << p1.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < p1.getNrProduse();i++)
	{
		cout << p1.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id prajitura: " << p2.getId() << endl;
	cout << "Denumire: " << p2.getDenumire() << endl;
	cout << "Numarul de calori: " << p2.getCalorii() << endl;
	cout << "Nr de produse: " << p2.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < p2.getNrProduse();i++)
	{
		cout << p2.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id prajitura: " << p3.getId() << endl;
	cout << "Denumire: " << p3.getDenumire() << endl;
	cout << "Numarul de calori: " << p3.getCalorii() << endl;
	cout << "Nr de produse: " << p3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < p3.getNrProduse();i++)
	{
		cout << p3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	p3.setDenumire("Macarons");
	p3.setCalorii(210);
	float vector11[] = { 10,13.5 };
	p3.setProduse(2, vector11);

	cout << "Id prajitura: " << p3.getId() << endl;
	cout << "Denumire: " << p3.getDenumire() << endl;
	cout << "Numarul de calori: " << p3.getCalorii() << endl;
	cout << "Nr de produse: " << p3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < p3.getNrProduse();i++)
	{
		cout << p3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	Prajitura p4 = p2;
	cout << "Id prajitura: " << p4.getId() << endl;
	cout << "Denumire: " << p4.getDenumire() << endl;
	cout << "Numarul de calori: " << p4.getCalorii() << endl;
	cout << "Nr de produse: " << p4.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0;i < p4.getNrProduse();i++)
	{
		cout << p4.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << f3.mediePreturi() << endl << endl;
	cout << f4.mediePreturi() << endl << endl;
	cout << f3.discountProdus(0, 0.4) << endl << endl;
	cout << f4.discountProdus(0, 0.5) << endl << endl;
	cout << b4.crestereCantitate(3) << endl << endl;
	cout << b5.crestereCantitate(5) << endl << endl << endl;

	cout << f1.getTVA() << endl << endl;
	cout << b1.getTVA() << endl << endl;
	cout << p1.getTVA() << endl << endl;

}
