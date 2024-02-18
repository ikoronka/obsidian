```c
#inclue <stdio.h>
#include <limits.h>
int main(){
	int a = 35, b = 35, c = 35;
	printf("%s", a==b==c ? "true" : "false");
	return 0; 
}
```
#### <u>Možnosti:</u>
- [ ] Program půjde zkompilovat, ale po spuštění spadne.
- [ ] Program půjde zkompilovat, nespadne a zobrazí: (doplnit)
- [ ] Program půjde zkompilovat, nespadne a ukončí se, ale výsledek není definovaný.
- [ ] Program půjde zkompilovat, nespadne, ale zacyklí se.
- [ ] Program nepůjde zkompilovat.

#### <u>Odpovědi:</u>
- [ ] Program půjde zkompilovat, ale po spuštění spadne.
- [x] Program půjde zkompilovat, nespadne a zobrazí: ==false
- [ ] Program půjde zkompilovat, nespadne a ukončí se, ale výsledek není definovaný.
- [ ] Program půjde zkompilovat, nespadne, ale zacyklí se.
- [ ] Program nepůjde zkompilovat.

#### <u>Vysvětlení:</u>
- a\==b se vyhodnotí 1 což != 35