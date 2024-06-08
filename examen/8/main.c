/*
Se considera un tip de date Memorie_t, cate pastreaza urmatoarele informatii: un
sir de maxim 40 de caractere ce contine informatia de la locatie, un numar
natural ce reprezinta adresa si un indicator daca sectiunea este protejata sau
nu,

De asemenea, se va implementa o structura de date Hdd_t care va contine doi
pointeri la cate un tablou de Memorie_t corespunzand celor doua categorii
(protejata sau nu), numarul de adrese disponibile pentru memorie protejata ,
numarul de adrese disponibile pentru memorie neprotejata si orice alte date
considerate necesare.

Clientul va avea acces la urmatoarele functii declarate intr-un fisier header

Hdd_t* adaugare(Hdd_t* a, char* info, int adresa, int nr_cat); //primeste drept
parametru un pointer la un Hdd_t curent si parametrii specifici unui element
Memorie_t. Functia adauga informatia de memorie nou creata la categoria
corespunzatoare DOAR daca mai exista locuri disponibile la acea categorie. In
caz contrar, se va returna Hdd nemodificat si se va afisa mesajul “Nu mai sunt
adrese la categoria de memorie x” (x poate fi  protejata sau neprotejata).

void afisareMemoriei(Hdd_t*a); //afiseaza in ordinea adreselor continutul
memoriei

int mutareInformatie(Hdd_t*, int x, int nr_cat); //ultimele x inregistrari din
categoria nr_cat trebuie mutati in cealalta categorie. Functia returneaza
numarul de memorii care au putut fi mutate tinandu-se cont de numarul de adrese
disponibile

Prezentati sub forma de comentarii in cod, analiza complexitatii din punct de
vedere al timpului de executie si al memoriei utilizate, in termeni de O()
pentru functiile implementate;

Biblioteca nu va expune clientului detaliile de implementare ale tipului de
date, iar utilizarea se va face doar prin intermediul functiilor implementate.

Puteti implementa si orice alte functii/tipuri de date pe care le considerati
necesare pentru "eleganta" solutiei. In fisierul header nu pot fi adaugate alte
functii.

Implementati de asemenea si un client in care sa ilustrati utilizarea
bibliotecii. Pentru simplificarea testarii, puteti genera siruri de caractere
aleatoare de lungime fixa.
*/
