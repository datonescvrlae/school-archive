const wypiszWynik = document.getElementById("wypisz_wynik")
const wyczysc = document.getElementById("wyczysc")

const wynik = document.getElementById("wynik")

const input1 = document.getElementById("liczba1")
const input2 = document.getElementById("liczba2")

function onWypiszWynik() {
        const liczba1 = parseInt(input1.value)
        const liczba2 = parseInt(input2.value)

        wynik.style.color = "rgb(0, 0, 0)"

        if (input1.value == "" || input2.value == "") {
            wynik.innerHTML = "Musisz podac dwie liczby!"
            wynik.style.color = "rgb(255, 0, 0)"

            return
        }

        const opcja = parseInt(document.getElementById("opcja").value)
        let wynikLiczba = 0

        switch(opcja) {
            case 1:
                    wynikLiczba = liczba1 + liczba2
                    break
            case 2:
                    wynikLiczba = liczba1 - liczba2
                    break
            case 3:
                    wynikLiczba = liczba1 * liczba2
                    break
            case 4:
                    if (liczba1 == 0 || liczba2 == 0) {
                            wynik.innerHTML = "Nie wolno dzielic przez zero!"
                            wynik.style.color = "rgb(255, 0, 0)"

                            return
                    }

                    wynikLiczba = liczba1 / liczba2
                    break
        }

        wynik.innerHTML = wynikLiczba
}

function onWyczysc() {
        input1.value = null
        input2.value = null
}

wypiszWynik.addEventListener("click", onWypiszWynik)
wyczysc.addEventListener("click", onWyczysc)