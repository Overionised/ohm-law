 # Ohmuv zakon

# Zadání
Napište funkce na elektrotechnické výpočty podle Ohmova zákona s využitím všech kombinací počátečních zadání (napětí, odpor, proud, výkon).  Pro každý ze vzorců použijte funkci.

Nápověda: Vždy dvě veličiny budou zadány přes klávesnici a poté zbylé dvě dopočítány v programu, nakonec budou všechny čtyři veličiny vytištěny na monitor.



Na monitor bude vytištěno:

ELEKTROTECHNICKÉ VÝPOČTY

Zadej hodnoty veličin nebo 0 pro dopočet:

Napětí [V]: zadavatel zadá číslo
Odpor [Ohm]: zadavatel zadá číslo
Proud [A]: zadavatel zadá číslo
Výkon [W]: zadavatel zadá číslo
Po provedení výpočtů počítačem bude zadavateli vytištěno na monitor:

ELEKTROTECHNICKÉ VÝPOČTY

Napětí je ... V.

Odpor je  ... Ohm.

Proud je .. A.

Výkon je ... W.



## Build
### option 1 dočasná instalace
~~~ shell
git clone https://github.com/Overionised/ohm-law
cd ohm-zakon
g++ main.cpp -o rovnice
~~~

### option 2 instalace
~~~ shell
git clone https://github.com/Overionised/ohm-law
cd ohm-zakon
g++ main.cpp -o rovnice
sudo cp rovnice /usr/bin/
~~~
## Run
### option 1 usecase
~~~ shell
./rovnice
~~~

### option 2 usecase
~~~ shell
rovnice
~~~

## uzivaní
~~~ shell
rovnice
~~~
