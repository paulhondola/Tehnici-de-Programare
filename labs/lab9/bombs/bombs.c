/*
3. Se dau n bombe, numerotate de la 1 la n, pentru fiecare cunoscandu-se
coordonatele (x,y) unde sunt plasate si raza de distrugere r. La explozia unei
bombe se va distruge totul in interiorul si pe cercul de centru (x,y) si raza r,
iar daca exista alte bombe in aceasta zona, acestea vor exploda la randul lor.
Se da indicele k al primei bombe care explodeaza si se cere sa se calculeze cate
bombe raman neexplodate. Datele se citesc din fisierul bombe.in si rezultatele
se vor afisa in fisierul bombe.out. In fisierul bombe.in pe prima linie se afla
numerele n si k, iar pe urmatoarele n linii coordonatele si razele de distrugere
ale celor n bombe. n si k sunt numere naturale, coordonatele numere intregi, iar
razele numere naturale. Exemplu:

bombe.in
8 5
4 5 4
-3 -4 1
4 1 1
2 1 3
2 2 2
1 1 2
-1 1 2
-3 3 3
bombe.out
3
Explicatie: Prima explodeaza bomba rosie (a 5-a), ea declanseaza cele doua bombe
verzi, iar fiecare dintre cele verzi declaseaza cate una albastra. Bombele negre
raman neexplodate.
1
*/
