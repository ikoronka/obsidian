#complexity
[[složitosti tabulka sorting algoritmů]]

```c
short a[99000];
int *b[90000];

int foo(void) {
	short a[30000], b[30000];
	int c;
	/*malloc, dopln*/
	return c;
}

int main(void){
	char *c;
}
```
# Kolik paměti v zásobníku zabere tento program?
#### <u>Možnosti:</u>
- [ ] sizeof(char*) + sizeof(int*)
- [ ] 99000 * sizeof(short) + 90000 * sizeof(int*)
- [ ] sizeof(char*) + 60000\*sizeof(short) + sizeof(int)

#### <u>Odpovědi:</u>
- [ ] sizeof(char*) + sizeof(int*)
- [ ] 99000 * sizeof(short) + 90000 * sizeof(int*) 
- [x] sizeof(char*) + 60000\*sizeof(short) + sizeof(int)

#### <u>Vysvětlení:</u>
-  T(n) ∈ O(n)
	- vnější cyklus se provede vpár případech $\sqrt{n}$ , třeba když n = 16, vnější se provede 4, vnitřní se provede vždycky podle hodnoty i => $\sqrt{n} * \sqrt{n} = n$
- T(n) ∈ O(n(log(n)))
	- n = 15, vnější cyklus se provede log(n), protože se to vždycky dělí 2 (je to opak toho, co se děje v tom loopu, což je $2^x$ ) a vevnitř se to celkově spustí $2^x - 1$, což zrovna v tomto případě je těch 15, takže to proběhne n-krát
- T(n) ∈ O(n^√2)
	- nechápu, proč je toto správně