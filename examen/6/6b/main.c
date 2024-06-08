/*
Se considera un tip de date Angajat. Acesta are urmatoarele campuri:

   - nume

   - cod departament(poate fi doar unul dintre SOFTWARE, TESTARE, MANAGEMENT) -
SW, TST, MNG

   - Un pointer la Proiectul la care lucreaza

Proiectul este caracterizat de urmatoarele:

    -nume

    -vector de de pointeri de Angajati care lucreaza la acesta

    -tipul de prioritate(poate fi unul dintre: HIGH_PRIORITY, MEDIUM_PRIORITY,
LOW_PRIORITY)

Compania este caracterizata de urmatoarele:

    - nume

    - vector de pointeri de Angajati

    - vector de pointeri de Proiecte

Clientul va avea acces la urmatoarele functii declarate intr-un fisier header:

a) Se va scrie o functie care primeste ca parametru un vector de pointeri de
Angajati si returneaza un nou vector sortat alfabetic dupa numele Angajatului

b) Sa se scrie o functie ce primeste ca parametru un pointer catre o Companie,
un anumit departament si o prioritate.. Functia va returna un vector de pointeri
format din toti angajatii din departamentul primit ca parametru care lucreaza la
un proiect cu prioritatea celui primit ca parametru. Acest vector se vrea sa fie
sortat alfabetic dupa numele angajatului.

Pentru rezolvarea punctului b) este optionala utilizarea functiei a).

Prezentati sub forma de comentarii in cod, analiza complexitatii din punct de
vedere al timpului de executie si al memoriei utilizate, in termeni de O()
pentru functiile implementate;

Puteti implementa si orice alte functii/tipuri de date pe care le considerati
necesare pentru "eleganta" solutiei. In fisierul header dedicate clientului, nu
se vor expune detaliile de implementare ale tipurilor de date.
*/
