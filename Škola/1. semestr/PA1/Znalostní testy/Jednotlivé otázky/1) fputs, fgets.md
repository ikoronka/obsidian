```c
int main(){
	char s[100]={0};
	fgets(s, sizeof(s), stdin);
	printf("%s", s);
	fputs(s, stdout);
	return 0;
}
```
#### <u>Možnosti:</u>
- [ ] Jestliže přijde „a“ 100x na vstup, program může přepsat paměť a spadnout. 
- [x] Při zobrazení mohou být obě řádky stejně dlouhé. 
- [ ] Pokud program spustíme vícekrát a zadáme stejný vstup, může být zobrazený výstup pokaždé jiný. 
- [x] Program vždy zobrazí ten samý text 2x. 
- [ ] Program nikdy nezobrazí ten samý text 2x.

#### <u>Odpovědi:</u>
- [ ] Jestliže přijde „a“ 100x na vstup, program může přepsat paměť a spatnout. 
- [x] Při zobrazení mohou být obě řádky stejně dlouhé. 
- [ ] Pokud program spustíme vícekrát a zadáme stejný vstup, může být zobrazený výstup pokaždé jiný. 
- [x] Program vždy zobrazí ten samý text 2x. 
- [ ] Program nikdy nezobrazí ten samý text 2x.


#### <u>Vysvětlení:</u>
- fputs se nezastaví na nenulovém znaku jako printf se svým formátováním
- ale tady to nevadí