```c
const char * foo (const char * str){
	while(*str++){}
	return str;
}
int main(){
	const char *str = "PA1 quiz";
	printf("%d", *foo(str));
	return 0;
}
```
#### <u>Možnosti:</u>
- [ ] Program je správně a zobrazí: ____ 
- [ ] Program neuvolňuje paměť. 
- [ ] Program může spadnout / výsledek není definovaný.

#### <u>Odpovědi:</u>
- [ ] Program je správně a zobrazí: ____ 
- [ ] Program neuvolňuje paměť. 
- [x] Program může spadnout / výsledek není definovaný.


#### <u>Vysvětlení:</u>
- Sice to někdy vrátí 37, (% = 37) ale nemůžeme s tím počítat, že se to uloží hned po našem textu, proto je chování nedefinované