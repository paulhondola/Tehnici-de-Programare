Recursivitate 2023
Recursivitatea este o tehnică de programare prin care o funcție se apelează pe sine pentru a rezolva o problemă mai mare. În mod general, aceasta presupune definirea unei funcții care se va apela repetat (pe sine insusi), până când se va ajunge la o soluție finală. Această soluție finală este de obicei rezultatul unei serii de operații efectuate de funcția recursivă.

Spre exemplu, să presupunem că vrem să calculăm factorialul unui număr n. Definim funcția factorial(n) astfel:

```c
function factorial(n) {
  if (n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
```

În acest caz, funcția factorial se apelează pe sine până când se ajunge la valoarea 1, caz în care se întoarce rezultatul 1. În caz contrar, se calculează produsul dintre n și factorialul pentru n-1. Astfel, dacă vrem să calculăm factorialul lui 5, apelăm funcția astfel:

factorial(5);
Aceasta va apela funcția pentru valorile 4, 3, 2 și 1, iar rezultatul final va fi 120 (5 x 4 x 3 x 2 x 1).

Recursivitatea poate fi foarte utilă pentru rezolvarea problemelor care implică procesarea recursivă a datelor sau a structurilor de date, precum arbori sau liste. Cu toate acestea, trebuie utilizată cu grijă, deoarece poate duce la probleme de depășire a stivei (stack overflow) dacă nu este implementată corect.

Expresie prefix
O expresie aritmetică în notația prefix (sau notația poloneză prefixă) este o modalitate de a reprezenta o expresie matematică în care operatorii precedă operanzii. În notația prefix, operatorii apar înaintea operanzilor și nu este nevoie de paranteze pentru a specifica ordinea de evaluare a expresiilor.

Spre exemplu, în notația prefix, expresia aritmetică 3 + 4 _ 5 este reprezentată astfel: + 3 _ 4 5. În această notație, operatorul de adunare (+) apare înaintea operanzilor 3 și _ 4 5, unde operatorul de înmulțire (_) apare înaintea operanzilor 4 și 5.

Pentru a evalua o expresie aritmetică în notația prefix, se parcurge expresia de la stânga la dreapta, se identifică operatorii și se aplică operația corespunzătoare asupra operanzilor.

Implementarea s-a facut la curs!

Expresie infix
Pentru a implementa un program C care evaluează o expresie aritmetică în notația infix, putem folosi o stivă pentru a păstra operatorii și operanzii în ordinea corectă de evaluare. Iată un exemplu de implementare (!!! este generat algoritmic: este necesar sa il analizati si validati):

Bibliografie
https://staff.cs.upt.ro/~marius/curs/pc/old/notes2.pdf

Aplicatii propuse

1. https://staff.cs.upt.ro/~marius/curs/lp/tema2.html : exercitiile 1,2 si 3

2. https://staff.cs.upt.ro/~marius/curs/lp/tema3.html : Exercitiul 2

### Limbaje de programare: Tema 2

1. Limita unor termeni infiniţi. Scrieţi o funcţie care calculează prin aproximări succesive valoarea expresiei 1/(x + 1/(x + 1/(... + 1/x))) cu o precizie dată (de exemplu 10-6). Calculaţi şi tipăriţi o aproximaţie a expresiei pentru x = 4.

Indicaţii: În problemă se dă un termen cu un număr infinit de apariţii ale lui x. El are o structură recursivă, fiind de forma 1/(x + ...) unde în loc de ... apare termenul însuşi. Putem scrie tn=1/(x+tn-1), pentru n > 0, cu t0 = 0. Rezolvăm problema similar cu cea de la curs (rădăcina), calculând în fiecare pas din termenul curent termenul următor, pânâ când diferenţa lor nu depăşeşte precizia cerută.
Puteţi verifica, comparând valoarea găsită cu cea a ecuaţiei lim = 1/(x + lim) (de gradul 2 în variabila lim).

// lim = 1 / (x + lim)
// lim _ (x + lim) = 1
// lim^2 + lim _ x - 1 = 0
// lim = (-x\*x + sqrt(1 + 4x)) / 2
// delta = b^2 - 4ac = x^2 + 4
// lim = (-x + sqrt(delta)) / 2

2. Numere în format hexazecimal. Scrieţi o funcţie care returnează valoarea unui număr citit de la intrare caracter cu caracter, în format hexazecimal (cifrele 0-9, A-F sau a-f).

Indicaţii: problema e similară cu funcţia readnat de la curs. Un prim test se face pentru cifra hexazecimala (isxdigit, tot din ctype.h), apoi pentru a obţine valoarea cifrei trebuie tratat diferit cazul cifrelor şi al literelor (de la A la F). Cum scrierea cu litere mari sau mici nu contează se poate folosi funcţia toupper din ctype.h (returnează literă mare dacă argumentul e literă mică; altfel returnează chiar litera dată ca argument) pentru a trata cele două cazuri uniform. (La fel de bine se poate folosi funcţia pereche tolower).

Probleme suplimentare

3. Serii de puteri. Calculaţi, cu o precizie dată, valoarea lui ex după dezvoltarea în serie Taylor:

   ex = 1 + x1/1! + x2/2! + x3/3! + ...
   Calculaţi suma până când termenul curent devine mai mic decât o valoare dată (de ex. 10-6). Pentru a evita recalcularea lui n! transmiteţi ca parametru şi termenul curent, şi calculaţi-l pe următorul după relaţia: xn/n! = xn-1/(n-1)! \* x/n.

4. Fractali. După modelul de la curs, scrieţi o funcţie care generează, în format SVG, fractalul din figură, care, pornind de la un pătrat pe care îl împarte în 3x3 pătrate egale, desenează recursiv figuri similare în cele 5 din 9 pătrate care formează o cruce. Când latura devine prea mică pentru a o împărţi, se desenează un pătrat.

### Limbaje de programare: Tema 3

De rezolvat şi predat la laboratorul din săptămâna 3

1. Numere în format hexazecimal. Scrieţi o funcţie care returnează valoarea unui număr natural citit de la intrare caracter cu caracter, în format hexazecimal (cifrele 0-9, A-F sau a-f).

Indicaţii: problema e similară cu funcţia readnat de la curs. Un prim test se face pentru cifra hexazecimala (isxdigit, tot din ctype.h), apoi pentru a obţine valoarea cifrei trebuie tratat diferit cazul cifrelor şi al literelor (de la A la F). Cum scrierea cu litere mari sau mici nu contează se poate folosi funcţia toupper din ctype.h (returnează literă mare dacă argumentul e literă mică; altfel returnează chiar litera dată ca argument) pentru a trata cele două cazuri uniform. (La fel de bine se poate folosi funcţia pereche tolower).

Pentru o variantă mai simplă, presupuneţi că în scriere se foloseşte doar un singur fel de litere (mari sau mici).

2. Rădăcina unei funcţii. Găsiţi, cu o aproximaţie dată (de exemplu 10-6), o rădăcină a unei funcţii f continuă pe un interval [a, b] şi care schimbă semnul pe acel interval (adică o valoare x pentru care f(x) = 0).

Rezolvaţi problema pentru o funcţie dată (de exemplu f(x) = x2 - 3) pe care o definiţi în program, şi alegeţi valori corespunzătoare pentru a şi b (de exemplu 1 şi 3).

Indicaţii Deoarece f(a) ≤ 0 (f(1) = 1 * 1 - 3 = -2) şi f(b) ≥ 0 (f(3) = 3*3 - 3 = 6) iar funcţia e continuă pe [a, b], ea va avea o rădăcină în acest interval. Problema se rezolvă înjumătăţind la fiecare pas intervalul de căutare pe care funcţia schimbă semnul, până când acesta devine mai mic decât precizia dată. Atunci orice punct din interval e o soluţie cu precizia cerută.

Se calculează valoarea funcţiei în mijlocul intervalului. Dacă valoarea funcţiei e ≥ 0, funcţia schimbă semnul pe jumătatea din stânga a intervalului. Altfel (dacă valoarea funcţiei la mijlocul intervalului e < 0), funcţia schimbă semnul pe jumătatea din dreapta. (în exemplul dat, f(2) = 2\*2 - 3, şi cum f(2) ≥ 0, continuăm cu intervalul [1,2]). Ajungem astfel la aceeaşi problemă, dar cu intervalul redus la jumătate. Continuând să înjumătăţim lungimea intervalului ajungem la cazul de bază, când putem returna orice valoare din interval (de exemplu mijlocul).

Se poate eventual testa suplimentar dacă în mijlocul intervalului, funcţia are valoarea zero, şi returna direct rădăcina în acest caz.
