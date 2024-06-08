/*
Se dau N dame şi o tablă de şah de dimensiune NxN. Să se găsească toate
modalităţile de a aranja toate damele astfel încât oricare două dame să nu se
atace. Două dame se atacă dacă se află pe aceeaşi linie, coloană sau diagonală.
Se cere să se afişeze prima soluţie în ordine lexicografică şi numărul total de
soluţii.

Date de intrare
Fişierul de intrare damesah.in va contine pe prima linie numărul natural N,
având semnificaţia din enunţ.

Date de ieşire
În fişierul de ieşire damesah.out se vor găsi două linii. Pe prima linie va fi
afişată prima soluţie în ordine lexicografică. Aceasta solutie va fi formată din
N numere, al i-lea număr reprezentând coloana pe care se află dama de pe linia
i. Pe cea de-a doua linie, se va găsi numărul total de soluţii.

Restricţii
§  4 ≤ N ≤ 13

Exemplu
damesah.in

damesah.out

4

2 4 1 3
2

Explicatie
Pentru N = 4 dame, prima solutie generata va fi 2 4 1 3. Fiecare numar V[i]
reprezinta coloana pe care se va afla dama de pe linia i. S-au gasit in total 2
solutii.

Problema se va rezolva utilizand un algoritm de backtracking.
*/
