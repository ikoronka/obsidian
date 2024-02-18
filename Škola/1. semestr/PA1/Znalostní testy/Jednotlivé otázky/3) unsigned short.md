[[datové typy shrnutí]]
```c
int main()
{
	unsigned short a[27][10];
	foo(a);
	return 0;
}
```
# Jaké rozhraní může mít fce foo, aby bylo její volání správné?

#### <u>Možnosti:</u>
- [ ] void foo(unsigned short (*x)\[27\])
- [ ] void foo(unsigned short x\[10]\[10])
- [ ] void foo(unsigned short ∗∗∗x)
- [ ] void foo(unsigned short x\[27\]\[10\])

#### <u>Odpovědi:</u>
- [ ] void foo(unsigned short (*x)\[27\])
- [x] void foo(unsigned short x\[10]\[10])
- [ ] void foo(unsigned short ∗∗∗x)
- [x] void foo(unsigned short x\[27\]\[10\])
- [x] void foo(unsigned short x\[]\[10])


#### <u>Vysvětlení:</u>
- void foo(unsigned short x\[10]\[10]) - můžu se prostě rozhodnout přečíst jen prvních 10 míst
- void foo(unsigned short x\[27\]\[10]) - tohle je jasný
- void foo(unsigned short x\[]\[10]) - tohle vlastně taky