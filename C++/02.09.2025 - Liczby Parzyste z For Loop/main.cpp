#include <iostream> // To daje nam dostep do "cout" oraz "cin"
using namespace std; // Dzieki temu nie musimy pisac za kazdym razem np. std::cout tylko samo cout

int main()
{
       unsigned int n; // Tworzymy nowa pusta zmienna o nazwie "n" typu "int" czyli liczba

       // Najpierw wypisujemy w konsoli nasz tekst za pomoca "cout"
       // Warto zapamietac ze strzalki musza w tym przypadku byc w strone slowa "cout"

       // Pozniej dajemy uzytkownikowi opcje wpisania liczby ktora zostanie przypisana do naszej zmiennej "n" zdeklarowanej wyzej w linii 6
       // Tutaj tez warto zapamietac ze strzalki musza byc w PRZECIWNA STRONE niz slowo "cin"

       // A zeby zapamietac same slowa "cout" oraz "cin" wystarczy je rozdzielic np. cout to "c" + "out"
       cout << "Podaj ile liczb parzystych chcesz wyswietlic: ";
       cin >> n;

       // Petle for mozna podzielic na 3 glowne elementy: "[zmienne]; [warunki]; [zmiany po powtorzeniu]"
       
       // W przypadku tej petli tworzymy dwie zmienne "i" oraz "j" ODDZIELONE PRZECINKIEM!!
       // Naszym warunkiem jest to ze dopoki "i" jest mniejsze niz "n" (ktore uzytkownik podal wyzej w "cin") petla dziala
       // I na koniec po kazdej iteracji (czyli powtorzeniu) zwiekszamy "i" o 1 oraz "j" o 2

       for (int i = 0, j = 0; i < n; i++, j+=2) 
       {
              cout << j << " "; // Wypisujemy nasza zmienna "j" i dodajemy po niej spacje
       }

       cout << endl; // "endl" to po prostu zejscie linie nizej w konsoli

       // Na samym koncu jezyk C++ wymaga od nas napisania "return 0;"
       // Nie wazne dlaczego po prostu trzeba o tym pamietac
       return 0;
}
