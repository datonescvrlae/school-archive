#include <iostream> // Daje nam dostep do "cout" oraz "cin"
#include <cmath> // A to daje nam dostep do potegowania oraz pierwiastkowania
using namespace std; // Dzieki temu nie musimy pisac za kazdym razem np. std::cout tylko samo cout

int main() {
    float a, b, c; // Deklarujemy zmienne w ktorych zapiszemy liczby podane przez uzytkownika

    // Jeden po drugim pytamy uzytkownika o liczby "a", "b" oraz "c"
    // Wazne jest zeby strzalki byly w strone "cout" oraz w strone przeciwna do "cin"
    cout << "Podaj liczbe A: ";
    cin >> a;

    cout << "Podaj liczbe B: ";
    cin >> b;

    cout << "Podaj liczbe C: ";
    cin >> c;

    // Tutaj ze wzorow matematycznych obliczamy delte oraz pierwiastek z delty (sqrtDelta)
    float delta = pow(b, 2) - 4 * a * c;
    float sqrtDelta = sqrt(delta); // Funkcja "sqrt()" pierwiastkuje podana liczbe (wazne jest aby byl to "float")

    cout << endl << "Wynik wynosi: " << endl; // Ten tekst chcemy wypisac zawsze bez wzgledu na wynik dlatego jest poza ifami

    if (delta > 0) {
        // Dla delty wiekszej od 0 liczymy "x1" oraz "x2" ze wzorow matematycznych
        float x1 = (-b - sqrtDelta) / (2 * a);
        float x2 = (-b + sqrtDelta) / (2 * a);

        // I wypisujemy wyniki obu x'ow do konsoli
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2;

    } else if (delta == 0) {
        // Dla delty rownej 0 obliczamy "x0" tez z wzoru matematycznego
        float x0 = -b / (2 * a);

        cout << "x0 = " << x0;

    } else {
        cout << "Brak rozwiazan"; // I dla delty mniejszej niz 0 wypisujemy blad
    }

    cout << endl; // "endl" to po prostu zejscie linie nizej w konsoli

    // Na samym koncu jezyk C++ wymaga od nas napisania "return 0;"
    // Nie wazne dlaczego po prostu trzeba o tym pamietac
    return 0;
}
