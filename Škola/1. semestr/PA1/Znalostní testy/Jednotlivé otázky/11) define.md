```c
#include <stdio.h>
#include <limits.h>

int main(){
	#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
	int a = 6, b = 5;
	printf("%d %d %d", MIN(a++,b++), a, b);
	return 0;
}
```
# Co platí pro následující kód?
#### <u>Možnosti:</u>
- [ ] Program půjde zkompilovat, ale po spuštění spadne.
- [ ] Program půjde zkompilovat, nespadne a zobrazí: doplnit
- [ ] Program půjde zkompilovat, nespadne a ukončí se, ale výsledek není definovaný.
- [ ] Program půjde zkompilovat, nespadne, ale zacyklí se.
- [ ] Program nepůjde zkompilovat.

#### <u>Odpovědi:</u>
- [ ] Program půjde zkompilovat, ale po spuštění spadne.
- [ ] Program půjde zkompilovat, nespadne a zobrazí: doplnit
- [x] Program půjde zkompilovat, nespadne a ukončí se, ale výsledek není definovaný.
- [ ] Program půjde zkompilovat, nespadne, ale zacyklí se.
- [ ] Program nepůjde zkompilovat.

#### <u>Vysvětlení:</u>
- nevíme, o kolik se zvýší a++