/*
Se considera un tip de date FootballPlayer care pastreaza urmatoarele
informatii:

- Name

- Salary

Se va implementa o structura de date FootballTeam ce va contine un vector de
pointeri de tipul FootballPlayer. Fiecare FootballTeam va avea un nume si alte
campuri ce se considera a fi necesare.

Se va implementa o structura de date FootballChampionship ce va contine un
vector de pointeri de tipul FootballTeam. Fiecare FootballChampionship va avea
un nume si alte campuri ce se considera a fi necesare.

Clientul va avea acces la urmatoarele functii declarate intr-un fisier header:



Primeste drept parametru un pointer la echipa de fotbal curenta si un pointer
catre un jucator nou. Functia adauga jucatorul in echipa de fotbal si returneaza
echipa de fotbal modificata



FootballTeam *addPlayer(FootballTeam *team, FootballPlayer *player);



Primeste drept parametru un pointer la campionatul de fotbal curent si un
pointer catre o echipa de fotbal noua. Functia adauga jucatorul in echipa de
fotbal si returneaza echipa de fotbal modificata



FootballChampionship *addTeam(FootballChampionship *footballChampionship, ,
                              FootballTeam *footballTeam);



Cauta un jucator in echipa de fotbal, dupa nume. Numele jucatorului se considera
a fi unic. Nu vor exista 2 jucatori cu acelasi nume. Returneaza un pointer catre
jucatorul gasit sau NULL in cazul in care acesta nu exista.



FootballPlayer *searchFootballPlayerInFootballTeam(char *name,
                                                   FootballTeam *footballTeam);



Cauta un jucator in toate echipele din campionatul de fotbal, dupa nume. Numele
jucatorului se considera a fi unic. Nu vor exista 2 jucatori cu acelasi nume.
Returneaza un pointer catre jucatorul gasit sau NULL in cazul in care acesta nu
exista.


FootballPlayer *searchFootballPlayerInFootballChampionship(
    char *name, FootballChampionship *footballChampionship);

Prezentati sub forma de comentarii in cod,
    analiza complexitatii din punct de vedere al timpului de executie si al
        memoriei utilizate,
    in termeni de O() pentru functiile implementate;

Puteti implementa si orice alte functii /
    tipuri de date pe care le considerati necesare pentru
    "eleganta" solutiei.In fisierul header dedicate clientului,
    nu se vor expune detaliile de implementare ale tipurilor de date.

*/
