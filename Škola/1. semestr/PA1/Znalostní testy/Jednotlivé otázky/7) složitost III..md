#complexity
[[složitosti tabulka sorting algoritmů]]

```c
for (i = 1; i < n; i *= 2){
	for (j = 0; j < i; j++){
		doIt();
	}
}
```
# Určete složitost T(n)
#### <u>Možnosti:</u>
- [ ] T(n) ∈ O(log(log(log(n))))
- [ ] T(n) ∈ O(n)
- [ ] T(n) ∉ O(n^2(log(n)))
- [ ] T(n) ∈ O(n(log(n)))
- [ ] T(n) ∈ O(n^√2)

#### <u>Odpovědi:</u>
- [ ] T(n) ∈ O(log(log(log(n))))
- [x] T(n) ∈ O(n)
- [ ] T(n) ∉ O(n^2(log(n)))
- [x] T(n) ∈ O(n(log(n)))
- [x] T(n) ∈ O(n^√2)

#### <u>Vysvětlení:</u>
-  T(n) ∈ O(n)
	- vnější cyklus se provede vpár případech $\sqrt{n}$ , třeba když n = 16, vnější se provede 4, vnitřní se provede vždycky podle hodnoty i => $\sqrt{n} * \sqrt{n} = n$
- T(n) ∈ O(n(log(n)))
	- n = 15, vnější cyklus se provede log(n), protože se to vždycky dělí 2 (je to opak toho, co se děje v tom loopu, což je $2^x$ ) a vevnitř se to celkově spustí $2^x - 1$, což zrovna v tomto případě je těch 15, takže to proběhne n-krát
- T(n) ∈ O(n^√2)
	- nechápu, proč je toto správně