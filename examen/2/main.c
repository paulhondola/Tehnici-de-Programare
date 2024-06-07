#include "lib.h"
/*
Se considera un tip de date Film_t, cate pastreaza urmatoarele informatii: un
sir de maxim 40 de caractere ce contine numele filmului, durata in minute,
costul de productie in milioane de dolari si genurile acestuia (sir de caractere
de forma gen1 , gen2). Pentru simplitate, se vor considera urmatoarele 4 genuri:
actiune, comedie, romance, thriller.

De asemenea, se va implementa o structura de date Site_t care va contine un
pointer la un tablou de elemente de tip Film_t si alte date considerate
necesare.

Clientul va avea acces la urmatoarele functii declarate intr-un fisier header:

Site_t* adaugare(Site_t*, char*, char*, int, int); //primeste drept parametru un
pointer la un Site_t curent si parametrii specifici unui Film_t. Functia adauga
filmul nou creat site-ului si returneaza site-ul modificat.

void afisareFilme(Site_t*); //afiseaza in ordine descrescatoare a (costului de
productie)/(minut de filmare) toate filmele de pe site

void afisareMaxim(Site_t*); //afiseaza cele mai lungi filme pentru fiecare gen.
Obs: Un film poate fi cel mai lung pe mai multe genuri

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

int main(void) {

  site_t movies = init_site(100);

  movies = add_movie(movies, "Dune", "jmecher", 100, 10000000);

  movies = add_movie(movies, "Dune 2", "prea jmecher", 1000, 100000000);

  show_movies(movies);

  return 0;
}
