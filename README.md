# Proiect POO - Petshop

## Clase implementate

### Utilizator

Clasa contine date care retin informatii depsre  numele, prenumele, username-ul, parola si email-ul fiecarui utilizator. Email-ul, numele si prenumele sunt optionale, iar in cazul in care utilizatorul nu doreste sa le completeze acestea sunt populate cu un sir de caractere vid. De asemenea, clasa Utilizator contine un element de tip Cos, un vector de elemente de tip Adresa, pentru cazul in care Utilizatorul doreste sa primeasca comenzi la mai multe adrese, si o variabila "numar_adrese" de tip int care retine cate adrese a salvat utilizatorul. Clasa utilizator este capabila sa adauge si sa stearga adrese si sa afiseze toate adresele completate de utilizator.

### Cos

Cos contine un vector de produse, reprezentand produsele care se afla in cosul utilizatorului, numarul acestora, o variabila de tip Discount care ne arata daca se aplica o reducere pentru produsele dintr-o anumita categorie, precum si o varabila de tip int care arata suma produselor din cos. Clasa cos este capabila sa adauge si sa stearga produse din vectorul de produse, sa calculeze pretul produselor din cos, atat atunci cand pentru acestea nu se aplica nicio reducere, cat si in cazul in care exista un discount pentru o anumita categorie, sa adauge un discount si sa afiseze produsele care se afla la acel moment in cos sau mesajul "Momentan nu exista produse in cos" in cazul in care cosul este gol.

### Produs

Aceasta clasa retine numele, descrierea, categoria din care face parte si pretul fiecarui produs. Singurul atribut optional este descrierea, iar in cazul in care aceasta nu este completata se populeaza cu un sir vid de caractere. In plus, pentru aceasta clasa este supraincarcat operatorul "<<" pentru a se putea afisa mai usor datele despre fiecare produs in parte.

### Adresa

Clasa Adresa retine informatii despre strada, numarul strazii, numarul locuintei, blocul si scara. In cazul in care adresa introdusa este cea a unei case, blocul si scara sunt populate cu un sir de caractere vid. Pentru aceasta clasa este supraincarcat operatorul "<<", pentru a se putea afisa mai usor datele retinute de clasa.

### Discount

Clasa discount retine doar categoria pentru care se aplica discount-ul si procentul.

## Functionalitati Bonus

* Aplicatia are un meniu interactiv care, cu ajutorul functiilor implementate in clasele descrise mai sus, poate: crea un utilizator, crea un produs si mai apoi sa il adauge in cosul utilizatorului, crea o adresa de livrare si sa o adauge in lista adreselor de livrare a utilizatorului, sa afiseze datele utilizatorului, produsele din cos si adresele de livrare, sa calculeze valoarea produselor din cos si sa o afiseze.

* Pentru clasa Cos a fost implementat constructorul de mutare si a fost supraincarcat operatorul = de mutare.
