#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
	string numero;
	string subalterno;
	string CAP;
	string sezioneistat;
	float lat;
	float lon;
	location locuzione;
};

void aggiungi_dati(int i, numerazionecivica dati[])
{
    ifstream fileInput("Comune_Bergamo_-_Numerazione_civica.csv");
    string linea;

    if (!fileInput.is_open())
    {
        cout << "Impossibile aprire il file\n";
        return;
    }

    getline(fileInput, linea);

    while (i < 1000 && getline(fileInput, linea))
    {
        stringstream riga(linea);

        getline(riga, dati[i].classetoponimo, ',');
        getline(riga, dati[i].tipotoponimo, ',');
        getline(riga, dati[i].numero, ',');
        getline(riga, dati[i].subalterno, ',');
        getline(riga, dati[i].CAP, ',');
        getline(riga, dati[i].sezioneistat, ',');

        i++;
    }

    fileInput.close();
    }
void stampa_file(int x)
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
}
string visualizza(numerazionecivica ele[], int dim){
	string s;
	for(int i=0;i<dim;i++){
		s+=ele[i].classetoponimo+"\t";
		s+=ele[i].tipotoponimo+"\t";
		s+=ele[i].numero+"\t";
		s+=ele[i].subalterno+"\t";
		s+=ele[i].CAP+"\t";
		s+=ele[i].sezioneistat+"\n";
		
	}
	return s;
	}


int main() {
	numerazionecivica dati[1000];
	int f=0;
	do
	{
		cout<<"\n";
		cout<<"\n";
		cout<<"1: - Aggiunta\n";
		cout<<"2: - Visualizzazione\n";
		cout<<"0: - finito\n";
		cin>>f;
		cout<<"\n";
		cout<<"\n";
		fflush(stdin);
		
		switch(f)
		{
			case 1:
				aggiungi_dati(1000,dati);
				break;
				
			case 2:
				visualizza(dati,1000);
				break;	
		}
	}while(f!=0);	

    return 0;
}
