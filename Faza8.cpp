#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//domeniul alimentatie

class MagazinFructeAstract
{
public:
	virtual void printDenumire() = 0;
	virtual void printProduse() = 0;

};

class MagazinFructe :public MagazinFructeAstract
{
	const int id;
	string denumire;
	float suprafata;
	int nrProduse;
	float* pret;
	static float TVA;
	static int contor;
public:

	//Constructor fara parametrii
	MagazinFructe() :id(contor++)
	{
		this->denumire = "BioFruct";
		this->suprafata = 250;
		this->nrProduse = 0;
		this->pret = NULL;
	}

	//Constructor cu 2 parametrii
	MagazinFructe(string denumire, float suprafata) :id(contor++)
	{
		this->denumire = denumire;
		this->suprafata = suprafata;
		this->nrProduse = 0;
		this->pret = NULL;
	}

	//Constructor cu toti paramterii
	MagazinFructe(string denumire, float suprafata, int nrProduse, float* pret) :id(contor++)
	{
		this->denumire = denumire;
		this->suprafata = suprafata;
		this->nrProduse = nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = pret[i];
		}
	}

	~MagazinFructe()
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
	}

	void afisare()
	{
		cout << "Denumirea magazinului de fructe este: " << this->denumire << ", suprafata " << this->suprafata << " , are nr de produse " << this->nrProduse << " si pretul pentru fiecare produs este: ";
		for (int i = 0; i < this->nrProduse; i++)
		{
			cout << this->pret[i] << " ";
		}
		cout << "Magazinul de fructe are TVA-ul: " << this->TVA;
		cout << endl;
	}

	static void setTVA(float TVA)
	{
		MagazinFructe::TVA = TVA;
	}

	const int getId()
	{
		return this->id;
	}
	string getDenumire()
	{
		return this->denumire;
	}
	float getSuprafata()
	{
		return this->suprafata;
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
	void setSuprafata(float suprafataNoua)
	{
		this->suprafata = suprafataNoua;
	}
	void setProduse(int nrProduseNou, float* pretNou)
	{
		this->nrProduse = nrProduseNou;
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = pretNou[i];
		}
	}

	//Constructorul de copiere
	MagazinFructe(const MagazinFructe& f) :id(contor++)
	{
		this->denumire = f.denumire;
		this->suprafata = f.suprafata;
		this->nrProduse = f.nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = f.pret[i];
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
		return MagazinFructe::TVA;
	}

	//Operatorul=
	MagazinFructe& operator=(const MagazinFructe& f)
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
		this->denumire = f.denumire;
		this->suprafata = f.suprafata;
		this->nrProduse = f.nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = f.pret[i];
		}
		return *this;
	}

	//Operatorul<<
	friend ostream& operator<<(ostream& out, MagazinFructe& f)
	{
		cout << "Id: " << f.id << endl;
		cout << "Denumire: " << f.denumire << endl;
		cout << "Suprafata: " << f.suprafata << endl;
		cout << "Nr produse: " << f.nrProduse << endl;
		cout << "Pret: " << endl;
		for (int i = 0; i < f.nrProduse; i++)
		{
			cout << f.pret[i] << endl;
		}
		return out;
	}

	//Operatorul>>
	friend istream& operator>>(istream& in, MagazinFructe& f)
	{
		delete[]f.pret;
		in >> f.denumire;
		cout << endl;
		in >> f.suprafata;
		cout << endl;
		in >> f.nrProduse;
		cout << endl;
		f.pret = new float[f.nrProduse];
		for (int i = 0; i < f.nrProduse; i++)
		{
			in >> f.pret[i];
		}
		return in;
	}

	//Operatorul index []
	float operator[](int poz)
	{
		if (poz >= 0 && poz < this->nrProduse)
		{
			return this->pret[poz];
		}
		else
		{
			return 0;
		}
	}

	//Operatorul de comparatie intre nr produse
	bool operator>=(MagazinFructe& f)
	{
		if (this->nrProduse >= f.nrProduse)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//Operatorul de autoasignare +=, prin care adaugam un nou element in vectorul de produse
	MagazinFructe& operator+=(float pretNou)
	{
		MagazinFructe copie = *this;
		delete[]this->pret;
		this->nrProduse++;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < copie.nrProduse; i++)
		{
			this->pret[i] = copie.pret[i];
		}
		this->pret[copie.nrProduse] = pretNou;
		return *this;
	}

	//fisiere text
	friend ofstream& operator<<(ofstream& file, MagazinFructe& f)
	{
		file << f.denumire << endl;
		file << f.suprafata << endl;
		file << f.nrProduse << endl;
		for (int i = 0; i < f.nrProduse; i++)
		{
			file << f.pret[i] << endl;
		}
		return file;
	}

	friend ifstream& operator>>(ifstream& file, MagazinFructe& f)
	{
		delete[]f.pret;
		file >> f.denumire;
		file >> f.suprafata;
		file >> f.nrProduse;
		f.pret = new float[f.nrProduse];
		for (int i = 0; i < f.nrProduse; i++)
		{
			file >> f.pret[i];
		}
		return file;
	}

	//fisiere binare
	void scriereBinar(fstream& file)
	{
		int nrLitereDenumire = this->denumire.size();
		file.write((char*)&nrLitereDenumire, sizeof(int));
		file.write(this->denumire.c_str(), nrLitereDenumire);
		file.write((char*)&this->suprafata, sizeof(float));
		file.write((char*)&this->nrProduse, sizeof(int));
		for (int i = 0; i < this->nrProduse; i++)
		{
			file.write((char*)&this->pret[i], sizeof(float));
		}
	}

	void citireBinar(fstream& file)
	{
		delete[]this->pret;
		int nrLitereDenumire;
		file.read((char*)&nrLitereDenumire, sizeof(int));
		string aux;
		aux.resize(nrLitereDenumire);
		file.read((char*)aux.c_str(), nrLitereDenumire);
		this->denumire = aux;
		file.read((char*)&this->suprafata, sizeof(float));
		file.read((char*)&this->nrProduse, sizeof(int));
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			file.read((char*)&this->pret[i], sizeof(float));
		}
	}

	//Redefinire functii virtual pure
	void printDenumire()
	{
		cout << "Denumirea magazinului de fructe este: " << this->denumire << endl;
		cout << "Am redefinit functia virtual pura si clasa MagazinFructe nu mai este abstracta" << endl;
	}

	void printProduse()
	{
		cout << "Afisam nr de produse si preturile lor: " << endl;
		cout << "Nr produse: " << this->nrProduse << endl;
		cout << "Pret fiecare produs: " << endl;
		for (int i = 0; i < this->nrProduse; i++)
		{
			cout << this->pret[i] << endl;
		}
		cout << "Am redefinit functia virtual pura si clasa MagazinFructe nu mai este abstracta" << endl;
	}
};

class BauturaAbstract
{
public:

	virtual void printMarca() = 0;
	virtual void printCantitate() = 0;
	virtual void printObject() = 0;
};

class Bautura : public BauturaAbstract
{
protected:
	const int id;
	string marca;
	char* categorie;
	bool esteCuAcid;
	int cantitate;
	static int contor;
	static float TVA;

public:

	//Constructorul fara parametrii
	Bautura() :id(contor++)
	{
		this->marca = "Borsec";
		this->categorie = new char[strlen("Apa minerala") + 1];
		strcpy(this->categorie, "Apa minerala");
		this->esteCuAcid = 1;
		this->cantitate = 5;

	}

	//Constructorul cu 2 parametrii
	Bautura(string marca, const char* categorie) :id(contor++)
	{
		this->marca = marca;
		this->categorie = new char[strlen(categorie) + 1];
		strcpy(this->categorie, categorie);
		this->esteCuAcid = 0;
		this->cantitate = 3;

	}

	//Constructorul cu toti parametrii
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

	//Operatorul<<
	friend ostream& operator<<(ostream& out, Bautura& b)
	{
		out << "Id: " << b.id << endl;
		out << "Marca: " << b.marca << endl;
		out << "Categorie: " << b.categorie << endl;
		out << "Este cu acid? " << b.esteCuAcid << endl;
		out << "Cantitate: " << b.cantitate << endl;
		return out;
	}

	//Operatorul>>
	friend istream& operator>>(istream& in, Bautura& b)
	{
		delete[]b.categorie;
		in >> b.marca;
		cout << endl;
		char aux[50];
		in >> aux;
		b.categorie = new char[strlen(aux) + 1];
		strcpy(b.categorie, aux);
		cout << endl;
		in >> b.esteCuAcid;
		cout << endl;
		in >> b.cantitate;
		return in;
	}

	//Operatorul=
	Bautura& operator=(const Bautura& b)
	{
		if (this->categorie != NULL)
		{
			delete[]this->categorie;
		}
		this->marca = b.marca;
		this->categorie = new char[strlen(b.categorie) + 1];
		strcpy(this->categorie, b.categorie);
		this->esteCuAcid = b.esteCuAcid;
		this->cantitate = b.cantitate;
		return *this;
	}

	//Operatorul de negatie !
	friend void operator!(Bautura& b)
	{
		if (b.esteCuAcid == 1)
		{
			b.esteCuAcid = 0;
		}
		else
		{
			b.esteCuAcid = 1;
		}
	}

	//Operatorul de cast la float
	operator float()
	{
		float cantitateModif;
		cantitateModif = this->cantitate / 2 + 0.5;
		return cantitateModif;
	}

	//Operator de testare a egalitatii == pt cantitate
	bool operator==(Bautura& b)
	{
		if (this->cantitate == b.cantitate)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//Operatorul functie prin care sa cresc cantitatea cu o valoare
	void operator()(int valoare)
	{
		this->cantitate = this->cantitate + valoare;
	}


	//fisiere text
	friend ofstream& operator<<(ofstream& file, Bautura& b)
	{
		file << b.marca << endl;
		file << b.categorie << endl;
		file << b.esteCuAcid << endl;
		file << b.cantitate << endl;
		return file;
	}

	friend ifstream& operator>>(ifstream& file, Bautura& b)
	{
		delete[]b.categorie;
		file >> b.marca;
		char aux[50];
		file >> aux;
		b.categorie = new char[strlen(aux) + 1];
		strcpy(b.categorie, aux);
		file >> b.esteCuAcid;
		file >> b.cantitate;
		return file;
	}

	//fisiere binare
	void scriereBinar(fstream& file)
	{
		int nrLitereMarca = this->marca.size();
		file.write((char*)&nrLitereMarca, sizeof(int));
		file.write(this->marca.c_str(), nrLitereMarca);
		int nrLitereCategorie = strlen(this->categorie);
		file.write((char*)&nrLitereCategorie, sizeof(int));
		for (int i = 0; i < nrLitereCategorie; i++)
		{
			file.write((char*)&this->categorie[i], sizeof(char));
		}
		file.write((char*)&this->esteCuAcid, sizeof(bool));
		file.write((char*)&this->cantitate, sizeof(int));
	}

	void citireBinar(fstream& file)
	{
		delete[] this->categorie;
		int nrLitereMarca;
		file.read((char*)&nrLitereMarca, sizeof(int));
		string aux;
		aux.resize(nrLitereMarca);
		file.read((char*)aux.c_str(), nrLitereMarca);
		this->marca = aux;
		int nrLitereCategorie;
		file.read((char*)&nrLitereCategorie, sizeof(int));
		this->categorie = new char[nrLitereCategorie + 1];
		for (int i = 0; i < nrLitereCategorie; i++)
		{
			file.read((char*)&this->categorie[i], sizeof(char));
		}
		this->categorie[nrLitereCategorie] = '\0';
		file.read((char*)&this->esteCuAcid, sizeof(bool));
		file.read((char*)&this->cantitate, sizeof(int));
	}

	//redefinire functii virtual pure
	void printMarca()
	{
		cout << "Marca bauturii este: " << this->marca << endl;
		cout << "Am redefinit functia virtual pura si clasa Bautura nu mai este clasa abstracta" << endl;
	}
	void printCantitate()
	{
		cout << "Cantitatea bauturii este: " << this->cantitate << endl;
		cout << "Am redefinit functia virtual pura si clasa Bautura nu mai este clasa abstracta" << endl;
	}
	void printObject()
	{
		cout << this->marca << endl;
		cout << this->categorie << endl;
		cout << this->esteCuAcid << endl;
		cout << this->cantitate;
	}

};

class MagazinPrajituri {
	const int id;
	string denumire;
	int suprafata;
	int nrProduse;
	float* pret;
	static int contor;
	static float TVA;

public:

	//Constructorul fara parametrii
	MagazinPrajituri() :id(contor++)
	{
		this->denumire = "Ecler";
		this->suprafata = 261;
		this->nrProduse = 0;
		this->pret = NULL;
	}

	//Constructorul cu doi parametri
	MagazinPrajituri(string denumire, int suprafata) :id(contor++)
	{
		this->denumire = denumire;
		this->suprafata = suprafata;
		this->nrProduse = 0;
		this->pret = NULL;
	}

	//Constructorul cu toti parametrii
	MagazinPrajituri(string denumire, int suprafata, int nrProduse, float* pret) :id(contor++)
	{
		this->denumire = denumire;
		this->suprafata = suprafata;
		this->nrProduse = nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = pret[i];
		}

	}

	~MagazinPrajituri()
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;

		}
	}

	void afisare()
	{
		cout << "Denumirea prajiturii este: " << this->denumire << " ,suprafata de: " << this->suprafata << " ,are nr produse " << this->nrProduse << " si are pretul de:  ";
		for (int i = 0; i < this->nrProduse; i++)
		{
			cout << this->pret[i] << " ";

		}
		cout << "Prajitura are TVA-ul: " << this->TVA;
		cout << endl;

	}

	static void setTVA(float TVA)
	{
		MagazinPrajituri::TVA = TVA;
	}

	const int getId()
	{
		return this->id;
	}
	string getDenumire()
	{
		return this->denumire;
	}
	int getSuprafata()
	{
		return this->suprafata;
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
	void setSuprafata(int suprafataNoua)
	{
		this->suprafata = suprafataNoua;
	}
	void setProduse(int nrProduseNou, float* pretNou)
	{
		this->nrProduse = nrProduseNou;
		if (this->pret != NULL)
		{
			delete[]this->pret;

		}
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = pretNou[i];
		}
	}

	//Constructorul de copiere
	MagazinPrajituri(const MagazinPrajituri& p) :id(contor++)
	{
		this->denumire = p.denumire;
		this->suprafata = p.suprafata;
		this->nrProduse = p.nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = p.pret[i];
		}
	}

	static float getTVA() {
		return MagazinPrajituri::TVA;
	}

	//Operatorul<<
	friend ostream& operator<<(ostream& out, MagazinPrajituri& p)
	{
		cout << "Id: " << p.id << endl;
		cout << "Denumire: " << p.denumire << endl;
		cout << "Suprafata: " << p.suprafata << endl;
		cout << "Nr produse: " << p.nrProduse << endl;
		cout << "Pret: " << endl;
		for (int i = 0; i < p.nrProduse; i++)
		{
			cout << p.pret[i] << endl;
		}
		return out;
	}

	//Operatorul>>
	friend istream& operator>>(istream& in, MagazinPrajituri& p)
	{
		delete[]p.pret;
		in >> p.denumire;
		cout << endl;
		in >> p.suprafata;
		cout << endl;
		in >> p.nrProduse;
		cout << endl;
		p.pret = new float[p.nrProduse];
		for (int i = 0; i < p.nrProduse; i++)
		{
			in >> p.pret[i];
		}
		return in;
	}

	//Operatorul=
	MagazinPrajituri& operator=(const MagazinPrajituri& p)
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
		this->denumire = p.denumire;
		this->suprafata = p.suprafata;
		this->nrProduse = p.nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->pret[i] = p.pret[i];
		}
		return *this;
	}

	//Operatorul index []
	float operator[](int poz)
	{
		if (poz >= 0 && poz < this->nrProduse)
		{
			return this->pret[poz];
		}
		else
		{
			return 0;
		}
	}

	//Operatorul functie ()
	void operator()(int valoare)
	{
		this->suprafata = this->suprafata + valoare;
	}

	//Operatorul ++ autoincrementare
	//preincrementare
	MagazinPrajituri& operator++()
	{
		this->suprafata++;
		return *this;
	}
	//postincrementare
	MagazinPrajituri& operator++(int)
	{
		MagazinPrajituri copie = *this;
		this->suprafata++;
		return copie;
	}

	//fisiere text
	friend ofstream& operator<<(ofstream& file, MagazinPrajituri& p)
	{
		file << p.denumire << endl;
		file << p.suprafata << endl;
		file << p.nrProduse << endl;
		for (int i = 0; i < p.nrProduse; i++)
		{
			file << p.pret[i] << endl;
		}
		return file;
	}

	friend ifstream& operator>>(ifstream& file, MagazinPrajituri& p)
	{
		delete[]p.pret;
		file >> p.denumire;
		file >> p.suprafata;
		file >> p.nrProduse;
		p.pret = new float[p.nrProduse];
		for (int i = 0; i < p.nrProduse; i++)
		{
			file >> p.pret[i];
		}
		return file;
	}

	//fisiere binare
	void scriereBinar(fstream& file)
	{
		int nrLitereDenumire = this->denumire.size();
		file.write((char*)&nrLitereDenumire, sizeof(int));
		file.write(this->denumire.c_str(), nrLitereDenumire);
		file.write((char*)&this->suprafata, sizeof(int));
		file.write((char*)&this->nrProduse, sizeof(int));
		for (int i = 0; i < this->nrProduse; i++)
		{
			file.write((char*)&this->pret[i], sizeof(float));
		}
	}

	void citireBinar(fstream& file)
	{
		delete[]this->pret;
		int nrLitereDenumire;
		file.read((char*)&nrLitereDenumire, sizeof(int));
		string aux;
		aux.resize(nrLitereDenumire);
		file.read((char*)aux.c_str(), nrLitereDenumire);
		this->denumire = aux;
		file.read((char*)&this->suprafata, sizeof(int));
		file.read((char*)&this->nrProduse, sizeof(int));
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			file.read((char*)&this->pret[i], sizeof(float));
		}
	}


};

class MagazinBauturi
{
	int nrBauturi;
	Bautura* vectorBauturi;
	BauturaAbstract* bauturiAbstract;

public:

	// Constructor care primeste un obiect de tip abstract
	MagazinBauturi(BauturaAbstract* bauturiAbstract) : bauturiAbstract(bauturiAbstract) {}

	// Metoda care utilizeaza obiectul de tip abstract
	void metodaCareUtilizeazaObiectulAbstract() {
		bauturiAbstract->printObject();
	}

	//Constructor fara parametrii
	MagazinBauturi()
	{
		this->nrBauturi = 0;
		this->vectorBauturi = NULL;
	}

	//Constructor cu toti parametrii
	MagazinBauturi(int nrBauturi, Bautura* vectorBauturi)
	{
		this->nrBauturi = nrBauturi;
		this->vectorBauturi = new Bautura[this->nrBauturi];
		for (int i = 0; i < this->nrBauturi; i++)
		{
			this->vectorBauturi[i] = vectorBauturi[i];
		}
	}

	//Destructor
	~MagazinBauturi()
	{
		if (this->vectorBauturi != NULL)
		{
			delete[]this->vectorBauturi;
		}
	}

	//Constructorul de copiere
	MagazinBauturi(const MagazinBauturi& m)
	{
		this->nrBauturi = m.nrBauturi;
		this->vectorBauturi = new Bautura[this->nrBauturi];
		for (int i = 0; i < this->nrBauturi; i++)
		{
			this->vectorBauturi[i] = m.vectorBauturi[i];
		}
	}

	//Operatorul=
	MagazinBauturi& operator=(const MagazinBauturi& m)
	{
		if (this->vectorBauturi != NULL)
		{
			delete[]this->vectorBauturi;
		}
		this->nrBauturi = m.nrBauturi;
		this->vectorBauturi = new Bautura[this->nrBauturi];
		for (int i = 0; i < this->nrBauturi; i++)
		{
			this->vectorBauturi[i] = m.vectorBauturi[i];
		}
		return *this;
	}

	//Getteri si Setteri
	int getNrBauturi()
	{
		return this->nrBauturi;
	}
	Bautura* getVectorBauturi()
	{
		return this->vectorBauturi;
	}

	void setBauturi(int nrBauturi, Bautura* vectorBauturi)
	{
		if (this->vectorBauturi != NULL)
		{
			delete[]this->vectorBauturi;
		}
		this->nrBauturi = nrBauturi;
		this->vectorBauturi = new Bautura[this->nrBauturi];
		for (int i = 0; i < this->nrBauturi; i++)
		{
			this->vectorBauturi[i] = vectorBauturi[i];
		}
	}

	//Operatorul <<
	friend ostream& operator<<(ostream& out, MagazinBauturi& m)
	{
		cout << "Nr bauturi: " << m.nrBauturi << endl;
		cout << "Vector bauturi: " << endl;
		for (int i = 0; i < m.nrBauturi; i++)
		{
			cout << m.vectorBauturi[i] << endl;
		}
		return out;
	}

	//Operatorul[]
	Bautura& operator[](int poz)
	{
		if (poz >= 0 && poz < this->nrBauturi)
		{
			return this->vectorBauturi[poz];
		}
	}

	//Operatorul>>
	friend istream& operator>>(istream& in, MagazinBauturi& m)
	{
		delete[]m.vectorBauturi;
		cout << "Introduceti de la tastatura nr de bauturi: " << endl;
		in >> m.nrBauturi;
		cout << "Introduceti de la tastatura vectorul de bauturi: " << endl;
		m.vectorBauturi = new Bautura[m.nrBauturi];
		for (int i = 0; i < m.nrBauturi; i++)
		{
			in >> m.vectorBauturi[i];
		}
		return in;
	}

	//Op+=
	MagazinBauturi& operator+=(Bautura bautura)
	{
		MagazinBauturi copie = *this;
		delete[]this->vectorBauturi;
		this->nrBauturi++;
		this->vectorBauturi = new Bautura[this->nrBauturi];
		for (int i = 0; i < copie.nrBauturi; i++)
		{
			this->vectorBauturi[i] = copie.vectorBauturi[i];
		}
		this->vectorBauturi[copie.nrBauturi] = bautura;
		return *this;
	}

	//Op-=
	MagazinBauturi& operator-=(int poz)
	{
		MagazinBauturi copie = *this;
		delete[]this->vectorBauturi;
		this->nrBauturi--;
		this->vectorBauturi = new Bautura[this->nrBauturi];
		for (int i = 0; i < poz; i++)
		{
			this->vectorBauturi[i] = copie.vectorBauturi[i];
		}
		for (int i = poz + 1; i < copie.nrBauturi; i++)
		{
			this->vectorBauturi[i - 1] = copie.vectorBauturi[i];
		}
		return *this;
	}
};

class BauturaAlcoolica :public Bautura
{
	float nrGrade;

public:
	BauturaAlcoolica() :Bautura()
	{
		this->nrGrade = 30;
	}
	BauturaAlcoolica(float nrGrade, string marca, const char* categorie, bool esteCuAcid, int cantitate) :Bautura(marca, categorie, esteCuAcid, cantitate)
	{
		this->nrGrade = nrGrade;
	}
	friend ostream& operator<<(ostream& out, const BauturaAlcoolica& ba)
	{
		out << (Bautura&)ba;
		out << ba.nrGrade;
		return out;
	}
	float getNrGrade()
	{
		return this->nrGrade;
	}
	void setNrGrade(float nrGrade)
	{
		this->nrGrade = nrGrade;
	}
	BauturaAlcoolica(const BauturaAlcoolica& ba) :Bautura(ba)
	{
		this->nrGrade = ba.nrGrade;
	}
	BauturaAlcoolica& operator=(const BauturaAlcoolica& ba)
	{
		Bautura::operator=(ba);
		this->nrGrade = ba.nrGrade;
		return *this;
	}

	~BauturaAlcoolica()
	{

	}
};

class BauturaCarbogazoasa :public Bautura
{
	string aroma;
public:
	BauturaCarbogazoasa() :Bautura()
	{
		this->aroma = "Mar";
	}
	BauturaCarbogazoasa(string aroma, string marca, const char* categorie, bool esteCuAcid, int cantitate) :Bautura(marca, categorie, esteCuAcid, cantitate)
	{
		this->aroma = aroma;
	}
	friend ostream& operator<<(ostream& out, const BauturaCarbogazoasa& bc)
	{
		out << (Bautura&)bc;
		out << bc.aroma;
		return out;
	}
	string getAroma()
	{
		return this->aroma;
	}
	void setAroma(string aromaNoua)
	{
		this->aroma = aromaNoua;
	}
	BauturaCarbogazoasa(const BauturaCarbogazoasa& bc) :Bautura(bc)
	{
		this->aroma = bc.aroma;
	}
	BauturaCarbogazoasa& operator=(const BauturaCarbogazoasa& bc)
	{
		Bautura::operator=(bc);
		this->aroma = bc.aroma;
		return *this;
	}

	~BauturaCarbogazoasa()
	{

	}
};


int MagazinFructe::contor = 1;
float MagazinFructe::TVA = 0.9;
int Bautura::contor = 1;
float Bautura::TVA = 0.9;
int MagazinPrajituri::contor = 1;
float MagazinPrajituri::TVA = 0.9;

void main()
{
	MagazinFructe f;
	MagazinFructe f1("FructeDelicioase", 120);
	float vector1[] = { 20.5,19,10 };
	MagazinFructe f2("LumeaPortocalei", 150, 3, vector1);
	float vector3[] = { 4.9,6,10,5.6 };
	MagazinFructe f3("GradinaGustarilor", 210, 4, vector3);
	float vector4[] = { 6.7,4,9 };
	MagazinFructe f4("Aprozar", 200, 3, vector4);

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

	MagazinPrajituri p;
	MagazinPrajituri p1("Tiramisu", 210);
	float vector2[] = { 14.5,20.3,25,11 };
	MagazinPrajituri p2("Televizor", 310, 4, vector2);
	float vector10[] = { 23,14,6.7,9,12,10.5 };
	MagazinPrajituri p3("Amandina", 200, 6, vector10);

	p.afisare();
	cout << endl << endl;
	p1.afisare();
	cout << endl << endl;
	p2.afisare();
	cout << endl << endl;

	MagazinFructe::setTVA(0.1);
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

	MagazinPrajituri::setTVA(0.2);
	p.afisare();
	cout << endl << endl;
	p1.afisare();
	cout << endl << endl;
	p2.afisare();
	cout << endl << endl;

	cout << "----Getteri----" << endl << endl;
	cout << "Id : " << f.getId() << endl;
	cout << "Denumire: " << f.getDenumire() << endl;
	cout << "Suprafata: " << f.getSuprafata() << endl;
	cout << "Numar produse: " << f.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f.getNrProduse(); i++)
	{
		cout << f.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id: " << f1.getId() << endl;
	cout << "Denumire: " << f1.getDenumire() << endl;
	cout << "Suprafata: " << f1.getSuprafata() << endl;
	cout << "Numar produse: " << f1.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f1.getNrProduse(); i++)
	{
		cout << f1.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id : " << f2.getId() << endl;
	cout << "Denumire: " << f2.getDenumire() << endl;
	cout << "Suprafata: " << f2.getSuprafata() << endl;
	cout << "Numar produse: " << f2.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f2.getNrProduse(); i++)
	{
		cout << f2.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id: " << f3.getId() << endl;
	cout << "Denumire: " << f3.getDenumire() << endl;
	cout << "Suprafata: " << f3.getSuprafata() << endl;
	cout << "Numar produse: " << f3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f3.getNrProduse(); i++)
	{
		cout << f3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id: " << f4.getId() << endl;
	cout << "Denumire: " << f4.getDenumire() << endl;
	cout << "Suprafata: " << f4.getSuprafata() << endl;
	cout << "Numar produse: " << f4.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f4.getNrProduse(); i++)
	{
		cout << f4.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "----Setteri----" << endl << endl;
	f3.setDenumire("FructeleVerii");
	f3.setSuprafata(200);
	float vector6[] = { 5,8.3 };
	f3.setProduse(2, vector6);

	cout << "Id: " << f3.getId() << endl;
	cout << "Denumire: " << f3.getDenumire() << endl;
	cout << "Suprafata: " << f3.getSuprafata() << endl;
	cout << "Numar produse: " << f3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f3.getNrProduse(); i++)
	{
		cout << f3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "----Constructorul de copiere----" << endl << endl;
	MagazinFructe f5 = f4;
	cout << "Id: " << f4.getId() << endl;
	cout << "Denumire: " << f4.getDenumire() << endl;
	cout << "Suprafata: " << f4.getSuprafata() << endl;
	cout << "Numar produse: " << f4.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f4.getNrProduse(); i++)
	{
		cout << f4.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;
	cout << "Id: " << f5.getId() << endl;
	cout << "Denumire: " << f5.getDenumire() << endl;
	cout << "Suprafata: " << f5.getSuprafata() << endl;
	cout << "Numar produse: " << f5.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f5.getNrProduse(); i++)
	{
		cout << f5.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "----Getteri----" << endl << endl;
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

	cout << "----Setteri----" << endl << endl;
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

	cout << "----Constructorul de copiere----" << endl << endl;
	Bautura b5 = b4;
	cout << endl << endl;
	cout << "Id bautura: " << b5.getId() << endl;
	cout << "Marca: " << b5.getMarca() << endl;
	cout << "Categorie: " << b5.getCategorie() << endl;
	cout << "Este cu acid? " << b5.getEsteCuAcid() << endl;
	cout << "Cantitatea este: " << b5.getCantitate() << endl;
	cout << endl;

	cout << "----Getteri----" << endl << endl;
	cout << "Id: " << p.getId() << endl;
	cout << "Denumire: " << p.getDenumire() << endl;
	cout << "Suprafata: " << p.getSuprafata() << endl;
	cout << "Nr de produse: " << p.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p.getNrProduse(); i++)
	{
		cout << p.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id: " << p1.getId() << endl;
	cout << "Denumire: " << p1.getDenumire() << endl;
	cout << "Suprafata: " << p1.getSuprafata() << endl;
	cout << "Nr de produse: " << p1.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p1.getNrProduse(); i++)
	{
		cout << p1.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id: " << p2.getId() << endl;
	cout << "Denumire: " << p2.getDenumire() << endl;
	cout << "Suprafata: " << p2.getSuprafata() << endl;
	cout << "Nr de produse: " << p2.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p2.getNrProduse(); i++)
	{
		cout << p2.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "Id: " << p3.getId() << endl;
	cout << "Denumire: " << p3.getDenumire() << endl;
	cout << "Suprafata: " << p3.getSuprafata() << endl;
	cout << "Nr de produse: " << p3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p3.getNrProduse(); i++)
	{
		cout << p3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "----Setteri----" << endl << endl;
	p3.setDenumire("Macarons");
	p3.setSuprafata(210);
	float vector11[] = { 10,13.5 };
	p3.setProduse(2, vector11);

	cout << "Id: " << p3.getId() << endl;
	cout << "Denumire: " << p3.getDenumire() << endl;
	cout << "Suprafata: " << p3.getSuprafata() << endl;
	cout << "Nr de produse: " << p3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p3.getNrProduse(); i++)
	{
		cout << p3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "----Constructorul de copiere----" << endl << endl;
	MagazinPrajituri p4 = p2;
	cout << "Id: " << p4.getId() << endl;
	cout << "Denumire: " << p4.getDenumire() << endl;
	cout << "Suprafata: " << p4.getSuprafata() << endl;
	cout << "Nr de produse: " << p4.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p4.getNrProduse(); i++)
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


	cout << "------------------Operator=-----------------" << endl << endl;
	cout << endl << endl;
	cout << "Id: " << f4.getId() << endl;
	cout << "Denumire: " << f4.getDenumire() << endl;
	cout << "Suprafata: " << f4.getSuprafata() << endl;
	cout << "Numar produse: " << f4.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f4.getNrProduse(); i++)
	{
		cout << f4.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;
	f4 = f3;
	cout << "Id: " << f3.getId() << endl;
	cout << "Denumire: " << f3.getDenumire() << endl;
	cout << "Suprafata: " << f3.getSuprafata() << endl;
	cout << "Numar produse: " << f3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < f3.getNrProduse(); i++)
	{
		cout << f3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "------------------Operator<<-----------------" << endl << endl;
	cout << f3 << endl << endl;
	cout << f4 << endl << endl;
	cout << f5 << endl << endl;
	/*cout << "------------------Operator>>-----------------" << endl << endl;
	cout << f3 << endl << endl;
	cin >> f3;
	cout << f3 << endl << endl;*/

	cout << "--------------Operatorul []------------------" << endl << endl;
	cout << f4[0] << endl << endl;
	cout << f5[1] << endl << endl;
	cout << f5[-2] << endl << endl;

	cout << "--------------Operatorul de comparatie------------------" << endl << endl;
	cout << f3.getNrProduse() << endl;
	cout << f4.getNrProduse() << endl;
	cout << (f3 >= f4) << endl << endl;

	cout << "--------------Operatorul de autoasignare += ------------------" << endl << endl;
	cout << f5 << endl << endl;
	f5 += 45.6;
	cout << f5 << endl << endl;

	cout << "--------------Operatorul<<----------------" << endl << endl;
	cout << b3 << endl << endl;
	cout << b4 << endl << endl;
	cout << b5 << endl << endl;

	/*cout << "--------------Operatorul>>----------------" << endl << endl;
	cout << b3 << endl << endl;
	cin >> b3;
	cout << b3 << endl << endl;*/

	cout << "--------------Operatorul=----------------" << endl << endl;
	cout << b3 << endl << endl;
	b5 = b3;
	cout << b5 << endl << endl;

	cout << "--------------Operatorul!----------------" << endl << endl;
	cout << b5 << endl << endl;
	!b5;
	cout << b5 << endl << endl;

	cout << "--------------Operatorul de cast la float----------------" << endl << endl;
	cout << (float)b5 << endl;

	cout << "--------------Operatorul==----------------" << endl << endl;
	cout << b3.getCantitate() << endl;
	cout << b4.getCantitate() << endl;
	cout << b5.getCantitate() << endl;
	cout << (b3 == b4) << endl << endl;
	cout << (b3 == b5) << endl << endl;

	cout << "--------------Operatorul()----------------" << endl << endl;
	cout << b5 << endl << endl;
	b5(3);
	cout << b5 << endl << endl;

	cout << "------------------Operator<<-----------------" << endl << endl;
	cout << p2 << endl << endl;
	cout << p3 << endl << endl;
	/*cout << "------------------Operator>>-----------------" << endl << endl;
	cout << p2 << endl << endl;
	cin >> p2;
	cout << p2 << endl << endl;*/

	cout << "----Operatorul=----" << endl << endl;
	cout << endl << endl;
	cout << "Id: " << p3.getId() << endl;
	cout << "Denumire: " << p3.getDenumire() << endl;
	cout << "Suprafata: " << p3.getSuprafata() << endl;
	cout << "Nr de produse: " << p3.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p3.getNrProduse(); i++)
	{
		cout << p3.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;
	p3 = p2;
	cout << "Id: " << p2.getId() << endl;
	cout << "Denumire: " << p2.getDenumire() << endl;
	cout << "Suprafata: " << p2.getSuprafata() << endl;
	cout << "Nr de produse: " << p2.getNrProduse() << endl;
	cout << "Pret pentru fiecare produs: " << endl;
	for (int i = 0; i < p2.getNrProduse(); i++)
	{
		cout << p2.getPret()[i] << ";" << endl;
	}
	cout << endl << endl;

	cout << "--------------Operatorul []------------------" << endl << endl;
	cout << p2[0] << endl << endl;
	cout << p2[-2] << endl << endl;

	cout << "--------------Operatorul()----------------" << endl << endl;
	cout << p2 << endl << endl;
	p2(5);
	cout << p2 << endl << endl;

	cout << "----Operatorul de autoincrementare----" << endl << endl;
	cout << p3 << endl << endl;
	++p3;
	cout << p3 << endl << endl;

	cout << p2 << endl << endl;
	p2++;
	cout << p2 << endl << endl;

	//Vectori de obiecte
	MagazinFructe* vectorFructe = new MagazinFructe[4];
	vectorFructe[0] = f1;
	vectorFructe[1] = f2;
	vectorFructe[2] = f3;
	vectorFructe[3] = f4;
	cout << "--------------Afisare vector fructe--------------------" << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << vectorFructe[i] << endl << endl;
	}

	Bautura* vectorBautura = new Bautura[3];
	vectorBautura[0] = b2;
	vectorBautura[1] = b3;
	vectorBautura[2] = b4;
	cout << "--------------Afisare vector bauturi--------------------" << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << vectorBautura[i] << endl << endl;
	}

	MagazinPrajituri* vectorPrajituri = new MagazinPrajituri[5];
	vectorPrajituri[0] = p2;
	vectorPrajituri[1] = p1;
	vectorPrajituri[2] = p3;
	vectorPrajituri[3] = p4;
	vectorPrajituri[4] = p3;
	cout << "--------------Afisare vector prajituri--------------------" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << vectorPrajituri[i] << endl << endl;
	}

	//Matricea de obiecte
	Bautura* bauturi = new Bautura[3];
	bauturi[0] = b1;
	bauturi[1] = b2;
	bauturi[2] = b3;
	if (bauturi) {
		delete[]bauturi;
	}

	Bautura* bauturiInLine = new Bautura[3]{ b1,b2,b3 };
	delete[]bauturiInLine;


	Bautura** bauturi2 = new Bautura * [3];
	bauturi2[0] = &b1;
	bauturi2[1] = &b2;
	bauturi2[2] = &b3;

	delete[]bauturi2;


	Bautura* pointerBautura = new Bautura();
	Bautura* vector = new Bautura[5];

	Bautura** pointeri = new Bautura * [5];
	for (int i = 0; i < 5; i++) {
		pointeri[i] = new Bautura();
	}

	Bautura** matrice = new Bautura * [5];
	for (int i = 0; i < 5; i++) {
		matrice[i] = new Bautura[5];
	}

	cout << *pointerBautura;
	for (int i = 0; i < 5; i++) {
		cout << vector[i] << endl << endl;
	}
	for (int i = 0; i < 5; i++) {
		cout << *(pointeri[i]) << endl << endl;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << matrice[i][j];
		}
	}


	//dezalocare
	delete pointerBautura;
	delete[]vector;

	for (int i = 0; i < 5; i++) {
		delete pointeri[i];
	}
	delete[] pointeri;
	for (int i = 0; i < 5; i++) {
		delete[]matrice[i];
	}
	delete[]matrice;

	bool variabila = true;

	//!variabila;

	bool var2 = !variabila;
	cout << endl << endl;
	cout << "--------------Clasa MagazinBauturi------------------" << endl << endl;
	Bautura vectorBautura1[] = { b1,b2,b3,b4 };
	MagazinBauturi m1(4, vectorBautura1);

	cout << "--------------Apelare getteri--------------" << endl << endl;
	cout << m1.getNrBauturi() << endl << endl;
	for (int i = 0; i < m1.getNrBauturi(); i++)
	{
		cout << m1.getVectorBauturi()[i] << endl;
	}

	cout << endl << endl;
	Bautura vectorBautura2[] = { b2,b4 };
	cout << "----------------Apelare setteri------------------" << endl << endl;
	m1.setBauturi(2, vectorBautura2);
	cout << m1.getNrBauturi() << endl << endl;
	for (int i = 0; i < m1.getNrBauturi(); i++)
	{
		cout << m1.getVectorBauturi()[i] << endl;
	}

	Bautura vectorBautura3[] = { b1,b2,b3 };
	MagazinBauturi m2(3, vectorBautura3);

	MagazinBauturi m3(4, vectorBautura1);

	cout << "----------------Apelare operatorul<<------------------" << endl << endl;
	cout << m1 << endl << endl << endl;
	cout << m2 << endl << endl << endl;
	cout << m3 << endl << endl << endl;

	cout << "----------------Apelare constr de copiere-----------------" << endl << endl;

	MagazinBauturi m4 = m2;
	cout << m4 << endl << endl;

	cout << "----------------Apelare operatorul=------------------" << endl << endl;

	m3 = m4;
	cout << m3 << endl << endl;

	cout << "----------------Apelare operatorul[]------------------" << endl << endl;

	cout << m2[0] << endl << endl;

	/*cout << "----------------Apelare operatorul>>------------------" << endl << endl;

	cout << m3 << endl << endl;
	cin >> m3;
	cout << endl << endl;
	cout << m3 << endl << endl;*/

	cout << "--------------Apelare operatorul +=-----------------" << endl << endl;
	cout << m3 << endl << endl;
	m3 += b3;
	cout << m3 << endl << endl;

	cout << "--------------Apelare operatorul -=-----------------" << endl << endl;
	cout << m4 << endl << endl;
	m4 -= 0;
	cout << m4 << endl << endl;

	cout << "-------------------FISIERE -----------------------" << endl << endl;
	ofstream file1("MagazinFructe.txt", ios::out);
	file1 << f5 << endl;
	file1.close();
	ifstream file2("MagazinFructe.txt", ios::in);
	file2 >> f;
	file2.close();

	fstream file3("MagazinFructe.bin", ios::binary | ios::out);
	f1.scriereBinar(file3);
	file3.close();
	fstream file4("MagazinFructe.bin", ios::binary | ios::in);
	f.citireBinar(file4);
	file4.close();

	ofstream file5("Bautura.txt", ios::out);
	file5 << b3 << endl;
	file5.close();
	ifstream file6("Bautura.txt", ios::in);
	file6 >> b;
	file6.close();

	fstream file7("Bautura.bin", ios::binary | ios::out);
	b1.scriereBinar(file7);
	file7.close();
	fstream file8("Bautura.bin", ios::binary | ios::in);
	b.citireBinar(file8);
	file8.close();

	ofstream file9("MagazinPrajituri.txt", ios::out);
	file9 << p3 << endl;
	file9.close();
	ifstream file10("MagazinPrajituri.txt", ios::in);
	file10 >> p;
	file10.close();

	fstream file11("MagazinPrajituri.bin", ios::binary | ios::out);
	p1.scriereBinar(file11);
	file11.close();
	fstream file12("MagazinPrajituri.bin", ios::binary | ios::in);
	p.citireBinar(file12);
	file12.close();


	cout << "--------------Clasa Bautura Alcoolica----------------------" << endl << endl;
	BauturaAlcoolica ba;
	BauturaAlcoolica ba1(45, "Absolut", "Vodka-Tarie", 1, 30);
	BauturaAlcoolica ba2(17, "Purcari", "Vin", 1, 25);
	BauturaAlcoolica ba3(7, "Ciucas", "Bere", 0, 40);

	cout << ba.getNrGrade() << endl << endl;
	cout << ba.getMarca() << endl << endl;
	cout << ba.getCategorie() << endl << endl;
	cout << ba.getEsteCuAcid() << endl << endl;
	cout << ba.getCantitate() << endl << endl;
	cout << endl << endl;
	cout << ba1.getNrGrade() << endl << endl;
	cout << ba1.getMarca() << endl << endl;
	cout << ba1.getCategorie() << endl << endl;
	cout << ba1.getEsteCuAcid() << endl << endl;
	cout << ba1.getCantitate() << endl << endl;
	cout << endl << endl;
	cout << ba2.getNrGrade() << endl << endl;
	cout << ba2.getMarca() << endl << endl;
	cout << ba2.getCategorie() << endl << endl;
	cout << ba2.getEsteCuAcid() << endl << endl;
	cout << ba2.getCantitate() << endl << endl;
	cout << endl << endl;
	cout << ba3.getNrGrade() << endl << endl;
	cout << ba3.getMarca() << endl << endl;
	cout << ba3.getCategorie() << endl << endl;
	cout << ba3.getEsteCuAcid() << endl << endl;
	cout << ba3.getCantitate() << endl << endl;
	cout << endl << endl;

	ba3.setNrGrade(35);
	ba3.setCategorie("Spumante");
	ba3.setMarca("Purcari");
	ba3.setEsteCuAcid(1);
	ba3.setCantitate(750);
	cout << ba3.getNrGrade() << endl << endl;
	cout << ba3.getMarca() << endl << endl;
	cout << ba3.getCategorie() << endl << endl;
	cout << ba3.getEsteCuAcid() << endl << endl;
	cout << ba3.getCantitate() << endl << endl;
	cout << endl << endl;

	cout << ba << endl << endl;
	cout << ba1 << endl << endl;
	cout << ba2 << endl << endl;
	cout << ba3 << endl << endl;

	BauturaAlcoolica ba4 = ba2;
	cout << ba4 << endl << endl;

	ba4 = ba2;
	cout << ba4 << endl << endl;

	//upcasting
	Bautura b10 = ba3;
	cout << ba3 << endl << endl;
	cout << b10 << endl << endl;

	cout << "--------------Clasa Bautura Carbogazoasa----------------------" << endl << endl;
	BauturaCarbogazoasa bc;
	BauturaCarbogazoasa bc1("Zmeura", "Sirop", "Cu Zahar", 1, 10);
	BauturaCarbogazoasa bc2("Mar", "Profructta", "Fara Zahar", 1, 20);
	BauturaCarbogazoasa bc3("Struguri", "Aronia", "Fara Zahar", 1, 35);

	cout << bc.getAroma() << endl << endl;
	cout << bc.getMarca() << endl << endl;
	cout << bc.getCategorie() << endl << endl;
	cout << bc.getEsteCuAcid() << endl << endl;
	cout << bc.getCantitate() << endl << endl;
	cout << endl << endl;
	cout << bc1.getAroma() << endl << endl;
	cout << bc1.getMarca() << endl << endl;
	cout << bc1.getCategorie() << endl << endl;
	cout << bc1.getEsteCuAcid() << endl << endl;
	cout << bc1.getCantitate() << endl << endl;
	cout << endl << endl;
	cout << bc2.getAroma() << endl << endl;
	cout << bc2.getMarca() << endl << endl;
	cout << bc2.getCategorie() << endl << endl;
	cout << bc2.getEsteCuAcid() << endl << endl;
	cout << bc2.getCantitate() << endl << endl;
	cout << endl << endl;
	cout << bc3.getAroma() << endl << endl;
	cout << bc3.getMarca() << endl << endl;
	cout << bc3.getCategorie() << endl << endl;
	cout << bc3.getEsteCuAcid() << endl << endl;
	cout << bc3.getCantitate() << endl << endl;
	cout << endl << endl;

	bc3.setAroma("Castravete");
	bc3.setCategorie("Cu Zahar");
	bc3.setMarca("Sprite");
	bc3.setEsteCuAcid(1);
	bc3.setCantitate(100);
	cout << bc3.getAroma() << endl << endl;
	cout << bc3.getMarca() << endl << endl;
	cout << bc3.getCategorie() << endl << endl;
	cout << bc3.getEsteCuAcid() << endl << endl;
	cout << bc3.getCantitate() << endl << endl;
	cout << endl << endl;

	cout << bc3 << endl << endl;

	BauturaCarbogazoasa bc4 = bc2;
	cout << bc2 << endl;
	cout << bc4 << endl;
	cout << endl << endl;

	bc4 = bc2;
	cout << bc4 << endl << endl;
	cout << endl << endl;

	//upcasting
	BauturaCarbogazoasa b11 = bc3;
	cout << bc3 << endl;
	cout << b11 << endl;
	cout << endl << endl;

	MagazinFructeAstract* pointerMagazinFructeAbstract;
	MagazinFructe* pointerMagazinFructe = new MagazinFructe[2];
	pointerMagazinFructe[0] = f4;
	pointerMagazinFructe[1] = f5;

	pointerMagazinFructeAbstract = pointerMagazinFructe;

	cout << "Late binding: " << endl << endl;
	pointerMagazinFructeAbstract->printDenumire();
	cout << endl << endl;
	pointerMagazinFructeAbstract->printProduse();
	pointerMagazinFructe->printDenumire();
	cout << endl << endl;
	pointerMagazinFructe->printProduse();


	BauturaAbstract* pointerBauturaAbstract;
	Bautura* pointerBautura1 = new Bautura[10];
	pointerBautura1[0] = b2;
	pointerBautura1[1] = b3;
	pointerBautura1[2] = bc1;
	pointerBautura1[3] = bc2;
	pointerBautura1[4] = ba2;
	pointerBautura1[5] = ba4;
	pointerBautura1[6] = ba3;
	pointerBautura1[7] = b5;
	pointerBautura1[8] = b4;
	pointerBautura1[9] = bc3;
	pointerBauturaAbstract = pointerBautura1;
	pointerBauturaAbstract->printCantitate();
	cout << endl << endl;
	pointerBauturaAbstract->printMarca();
	cout << endl << endl;
	pointerBauturaAbstract->printObject();
	cout << endl << endl;
	pointerBautura1->printCantitate();
	cout << endl << endl;
	pointerBautura1->printMarca();
	cout << endl << endl;
	pointerBautura1->printObject();
	cout << endl << endl;

	//clasa has a 
	Bautura bautura;
	MagazinBauturi magazin(&bautura);

	magazin.metodaCareUtilizeazaObiectulAbstract();
}
