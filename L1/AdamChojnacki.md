[comment]: <> (Plik należy wyświetlić przy użyciu interpretera markdown, przepraszam jeśli sprawiło to problem, jeśli trzeba to przepiszę go do innego formatu. Wykonałem go w ramach ćwiczenia posługiwania się tym narzędziem)

# Adam Chojnacki <br> 254615 <br> Zadanie 2

### Wszystkie obliczenia wykonano w konsoli python3

---

## **Część pierwsza**  

<br>

**Szybkość szyfrowania v** := $10^6$ $\frac{szyfrogramy}{s}$

**Długość klucza k** $\in$ {40, 56, 90, 128, 256}

**Ilość wszystkich możliwych kluczy** - $2^k$

Zatem sprawdzenie wszystkich ilości kluczy zajmie nam:

**t** := $\frac{2^k}{v}$


| **k** 	|  40 	| 56   	|  90 	|  128 	| 257   |
|---    |---    |---    | ---   | ---   | ---   |
| **t**    	|   $10^{6}$  	|   $7.2 * 10^{10}$  	|   $1.2379*10^{21}$	|   $3.4*10^{32}$ 	| $1.1*10^{71}$|


Liczby te w swojej surowej postaci nie przedstawiają wystarczająco skali problemu. 
Dla uproszczenia, przyjmijmy, że:

**Dzień d** := $8.64 * 10^4$ s

**Rok r** :=  $3.1536 * 10^7$ s

**Wiek Wszechświata u**  := $10^{18}$ s

Zatem w nowej skali: 

| **k** 	|  40 	| 56   	|  90 	|  128 	| 257   |
|---    |---    |---    | ---   | ---   | ---   |
| **t (s)**    	|   $11.57$ d  	|   $2283.1$ r  	|   $1237.9$ u	|   $3.4*10^{14}$ u	| $1.1*10^{53}$ u|

Jak widać, czasy te przekraczają ludzkie możliwości już dla **k** = 90.

<br>

---

<br>

## **Część druga**

<br>


Do sprawdzenia szybkości szyfrowania **AES** użyję narzędzia OpenSSL na swoim komputerze stacjonarnym.

Wyniki komendy *openssl speed aes-128-cbc* prezentują się następująco:

The 'numbers' are in 1000s of bytes per second processed.
| **type**  | 16 bytes  | 64 bytes  | 256 bytes | 1024 bytes    | 8192 bytes    |  16384 bytes |
| ---   | ---   | ---   | ---   | ---   | ---   | ---   |
| **aes-128 cbc**   | 266466.94k    | 289487.51k    |  289997.57k   |  290676.74k   |  292719.27k   | 294513.32k    |

Obliczenia wykonam dla 16 bajtowych bloków. 

Pobór mocy w moim komputerze wyniosi: <br> **P** := $222$ W = $0.222$ kW <br> Wynik uzyskałem dzięki narzędziu *LocalCooling*

Dla wybranch bloków szybkość szyfrowania wynosi: <br> **V** := $266466.94 * 1000 * 8 \frac{bit}{s}$ = $2131735520.0 \frac{bit}{s}$ = $7674247872000 \frac{bit}{h}$

Koszt energi wynosi: <br> **Cs** := $1 \frac {PLN}{kWh}$

Mając te dane możemy policzyć koszt **C** szyfrowania dla kolejnych **k** jako: <br> **C** := $\frac{P * 2^k}{V} * Cs$

| **k** 	|  40 	| 56   	|  90 	|  128 	| 257   |
|---    |---    |---    | ---   | ---   | ---   |
| **C (PLN)**    	|   $0.03$  	|   $2084.47$  	|   $3.58 * 10^{13}$	|   $9.84 * 10^{24}$ 	| $3.34 * 10^{63}$|

Jak widać, dla 40 jest to jeszcze opłacalne, tak dla dłuższych kluczy koszty rosną do niewyobrażalnych wartości. 

<br> 

---

Oczywiście wszystkie te obliczenia zakładają, że na własciwy klucz natrafimy na samym końcu.
