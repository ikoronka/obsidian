#typy
```c
unsigned safeSizeOf( unsigned int ** x){
	if ( !x ) return 0;
	return sizeof(x);
}

int main(){
	unsigned int * foo[199];
	printf("%u %u"), (unsigned)sizeof(foo), safeSizeOf(foo));
	return 0;
}
```
# Co zobrazí následující kód?
#### <u>Bez možností, doplňovačka</u>

#### <u>Odpovědi:</u>
- 1592 8

#### <u>Vysvětlení:</u>
- první se ptá na velikost pole ukazatelů, což je 199\*velikost_ukazatele, tzn. 199\*8 = 1592; to druhé (safeSizeOf) se ptá jen na velikost ukazatele, v daném případě 8B, tzn. vrátí 8 ; pokud by tam bylo sizeof(\*foo), tak to vrátí velikost unsigned intu