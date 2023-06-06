#include <iostream>       //program implementuje tablice haszuj¹ce z wykorzystaniem list https://eduinf.waw.pl/inf/alg/001_search/0099a.php
#include <vector>
#include <list>
#include <string>

using namespace std;

void tolower_and_suma(string& a,int& suma)  //zmienia na male litery i liczy sume znakow
{
	for (auto& c : a)
	{
		c = tolower(c);
		suma += int(c);
	}
}

int main()
{
	const int l_sort{ 16 };  //ile chce kontenerow na sortowanie
	vector<list<string>> nazwisko(l_sort);
	vector<list<string>> numer_tel(l_sort);

	string xyz, nr_tel;

	int wybor{ 0 };
	while (wybor != 4)
	{
		int suma{ 0 };
		cout << "\n1 - dodawanie elementu\n2 - wyszukiwanie elementu po nazwisku\n3 - wyswietlenie wszytskich elementow\n4 - wyjscie\n";
		cin >> wybor;
		switch (wybor)
		{
		case 1:		// dodawanie elementu
			cout << "\npodaj nazwisko: ";
			cin >> xyz;
			cout << "\npodaj numer telefonu: ";
			cin >> nr_tel;
			tolower_and_suma(xyz, suma);
			nazwisko[suma % l_sort].push_back(xyz);
			numer_tel[suma % l_sort].push_back(nr_tel);
			break;

		case 2:		// wyszukiwanie elementu po nazwisku
			cout << "\npodaj nazwisko: ";
			cin >> xyz;
			tolower_and_suma(xyz, suma);
			if (nazwisko[suma % l_sort].size() == 0) //gdy kontener jest pusty
			{
				cout << "\nbrak danych, nie ma takiego nazwiska bazie danych";
				break;
			}
			else
			{
				int licznik{ 0 };
				const list<string> lista = nazwisko[suma % l_sort]; //ustalanie kontenera w ktorym prawdopodobnie jest szukane nazwisko
				for (list<string>::const_iterator i = lista.begin(); i != lista.end(); i++, licznik++)
				{
					if (*i == xyz)
					{
						cout << "\nnazwisko: " << *i;
						i = numer_tel[suma % l_sort].begin();
						for (int k{ 0 }; k < licznik; k++)
							i++;
						cout << "\nnumer telefonu: " << *i;
						break;
					}
				}
				break;
			}
			break;
		case 3:
			int a{ 0 };
			vector<list<string>>::const_iterator it_naz{ nazwisko.begin() };
			vector<list<string>>::const_iterator it_tel{ numer_tel.begin() };

			for (it_naz, it_tel; it_naz != nazwisko.end(); it_naz++, a++, it_tel++) 
			{
				cout << endl << a << ".";
				list<string>::const_iterator it2_naz = it_naz->begin();
				list<string>::const_iterator it2_tel = it_tel->begin();

				for (it2_naz, it2_tel; it2_naz != it_naz->end(); it2_naz++, it2_tel++) 
				{
					cout << *it2_naz << "(" << *it2_tel << ")" << "-->";
				}
			}
			break;
		}
	}
}

