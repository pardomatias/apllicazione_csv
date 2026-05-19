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
	string nometoponimo;
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
        getline(riga, dati[i].nometoponimo, ',');
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
        while (fileInput>>linea){ 
            cout << linea << '\n';
        }
        fileInput.close(); 
    } else {
        cout << "Impossibile aprire il file";
    }
}

string visualizza(numerazionecivica ele[], int dim){
	string s;
	for(int i=0;i<dim;i++){
		s+=ele[i].classetoponimo+"\t";
		s+=ele[i].nometoponimo+"\t";
		s+=ele[i].numero+"\t";
		s+=ele[i].subalterno+"\t";
		s+=ele[i].CAP+"\t";
		s+=ele[i].sezioneistat+"\n";
		
	}
	return s;
	}

void cerca(string r,numerazionecivica ele[],int l,int ini,int cont)
{
	for(int i = 0; i < l; i++)
	{
		if(r = ele[i].nometoponimo)
		{
			if(ini == 0)
			ini = i;
			
			cont++;
		}
	}
}


int main() {
	numerazionecivica dati[1000];
	int f=0;
	string r;
	
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
				aggiungi_dati(0,dati);
				break;
				
			case 2:
				cout<<visualizza(dati,1000);
				break;	
			case 3:
			    int ini = 0;
	            int cont = 0;
	            cout<<"inserisci il nome da cercare: ";
	            getline(cin,r);
				cerca(r,dati,1000,ini,cont);	
		}
	}while(f!=0);	

    return 0;
}
