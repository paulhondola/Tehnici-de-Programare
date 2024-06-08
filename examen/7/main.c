/*
Se considera un tip de date Carte_t cate pastreaza urmatoarele informatii: titul
(sir de caractere), autorul (sir de caractere),  numarul de pagini (numar
intreg) si genurile acesteia (sir de caractere de forma gen1 , gen2). Pentru
simplitate, se vor considera urmatoarele 4 genuri: fictiune, dezvoltare,
romance, manga.


De asemenea, se va implementa o structura de date Biblioteca_t care va contine
un pointer la un tablou de elemente de tipul Carte_t, numarul maxim de carti din
fiecare gen ce pot fi adaugate si alte date considerate necesare.


Clientul va avea acces la urmatoarele functii declarate intr-un fisier header:


Biblioteca_t* adaugare(Biblioteca_t*, Carte_t); //primeste drept parametru un
pointer la biblioteca si un element de tip Carte_t. Functia adauga cartea in
biblioteca doar daca mai exista loc disponibil pentru carti din genul respectiv
si returneaza biblioteca modificata. In cazul in care nu mai exista loc pentru
carte, se va afisa mesajul “Ai prea multe carti de tipul x” (x poate fi unul din
cele 4 genuri literare mentionate mai sus).



void afisareMaxim(Biblioteca_t*); //afiseaza cartile cu cel mai mare numar de
pagini pentru fiecare gen literar. Obs: O carte poate fi maximul pe mai multe
genuri literare.


void afisareAutor(Biblioteca* b, char* autor); //functia va cauta si afisa in
ordine alfabetica dupa titlu toate cartile scrise de autorul dat ca parametru


Prezentati sub forma de comentarii in cod, analiza complexitatii din punct de
vedere al timpului de executie si al memoriei utilizate, in termeni de O()
pentru functiile implementate;


Biblioteca nu va expune clientului detaliile de implementare ale tipului de
date, iar utilizarea se va face doar prin intermediul functiilor implementate.


Puteti implementa si orice alte functii/tipuri de date pe care le considerati
necesare pentru "eleganta" solutiei. In fisierul header nu pot fi adaugate alte
functii.


Implementati de asemenea si un client in care sa ilustrati utilizarea
bibliotecii. Pentru simplificarea testarii, puteti genera elemente aleatoare.
*/
