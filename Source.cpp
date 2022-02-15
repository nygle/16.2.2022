#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class osoba {
protected:
	string jmeno;
	int vek; 
public:
	osoba() {}
	osoba(string jmeno, int vek) {
		this->jmeno = jmeno;
		this->vek = vek;
	}
	string DejJmeno() { return jmeno; }
	int DejVek() { return vek; }
};

class zamestnanec : public osoba {
private:
	string zamestnani;
	int plat; 
public:
	zamestnanec() {}
	zamestnanec(string jmeno, int vek, string zamestnani, int plat) {
		this->zamestnani = zamestnani;
		this->jmeno = jmeno;
		this->vek = vek;
		this->plat = plat;
	}
	string DejZamestnani() { return zamestnani; }
	int DejPlat() { return plat; }
	void vypis_info(int poradi) {
		ofstream zapis;
		zapis.open("zapis.txt");
		cout << poradi << "zamestnanec: " << "jmeno: " << jmeno << ", vek: " << vek << ", zamestnani: " << zamestnani << ", s platem: " << plat << endl;
		zapis << poradi << "zamestnanec: " << "jmeno: " << jmeno << ", vek: " << vek << ", zamestnani: " << zamestnani << ", s platem: " << plat << endl;
	}

};




int main() {
	int osoby;
	int zamestnanci;
	string jmeno, jmenoZ, zamestnani4;
	int vek, vekZ, plat;
	cout << "Kolik chces pridat osob?: "; 
	cin >> osoby;
	cout << endl;
	int pO = 1;
	osoba* ukO = new osoba[osoby]; 
	for (int i = 0; i < osoby; i++)
	{
		system("cls");
		cout << pO << ". osoba" << endl; cout << "zadej jmeno osoby: "; cin >> jmeno;
		cout << "zadej vek osoby: ";
		cin >> vek;
		ukO[i] = osoba(jmeno, vek); 
		pO++;
	}
	cout << endl;
	for (int i = 0; i < osoby; i++) {
		cout << "jmeno: " << ukO[i].DejJmeno() << ", vek: " << ukO[i].DejVek() << endl;
	}
	delete[] ukO;
	cout << "\nKolik chces pridat zamestnancu?: "; 
	cin >> zamestnanci;
	cout << endl;
	int p = 1;
	zamestnanec* ukZ = new zamestnanec[zamestnanci];
	for (int i = 0; i < zamestnanci; i++)
	{
		system("cls");
		cout << p << ". zamestnanec" << endl; cout << "zadej jmeno zamestnance: "; cin >> jmenoZ;
		cout << "zadej vek zamestnance: "; cin >> vekZ;
		cout << "zadej zamestnani: ";
		cin >> zamestnani4;

		cout << "zadej plat: ";
		cin >> plat;
		ukZ[i] = zamestnanec(jmenoZ, vekZ, zamestnani4, plat); p++;
	}
	cout << endl;
	int poradi = 0;
	for (int i = 0; i < zamestnanci; i++) {
		poradi++;
		ukZ[i].vypis_info(poradi);
		//cout << "jmeno: " << ukZ[i].DejJmeno() << ", vek: " << ukZ[i].DejVek() << ", zamestnani: " << ukZ[i].DejZamestnani() << ", s platem: " << ukZ[i].DejPlat() << endl;
	}
	delete[] ukZ;
	system("pause");
	return 0;
}