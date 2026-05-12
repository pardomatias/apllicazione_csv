#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct location
{
	float lat;
	float lon;
};

struct numerazionecivica
{
	string classetoponimo;
	string tipotoponimo;
	int numero;
	string subalterno;
	string CAP;
	string sezioneistat;
	float lat;
	float lon;
	location locuzione;
};

void aggiungi()
/*void lettura_strut(int x)
{
	ifstream fileInput("Comune_Bergamo_-_Numerazione_civica.csv");
    string linea;

    if (fileInput.is_open()) {
        while (fileInput>>linea){ //getline(fileInput, linea)) { // Legge riga per riga
            cout << linea << '\n';
        }
        fileInput.close(); // Chiude lo stream
    } else {
        cout << "Impossibile aprire il file";
    }
}*/


int main() {
	numerazionecivica dati[100];
	int f=0;
	/*do
	{
		cout<<"\n";
		cout<<"\n";
		cout<<"1: - Aggiunta\n";
		cout<<"2: - Visualizzazione\n";
		cout<<"0: - finito\n";
		cin>>f;
		cout<<"\n";
		cout<<"\n";
		fflush(stdin);*/
	//lettura_strut(100);
		ifstream fileInput("Comune_Bergamo_-_Numerazione_civica.csv");
    string linea;

    if (fileInput.is_open()) 
	{
        while (fileInput>>linea)
		{ 
            cout << linea << '\n';
        }
        fileInput.close();
    } 
	else 
	{
        cout << "Impossibile aprire il file";
    }

    return 0;
}
