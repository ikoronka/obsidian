#complexity
[[složitosti tabulka sorting algoritmů]]

```c
for (i = 1; i < n; i *= 2, n -= i)
```

# Určete složitost T(n)

#### <u>Možnosti:</u>
- [ ] T(n) ∈ O(n^3)
- [ ] T(n) ∈ O(log(n))
- [ ] T(n) ∉ O(3^n)
- [ ] T(n) ∉ O(n)
- [ ] T(n) ∉ O(n^2(log(n)))

#### <u>Odpovědi:</u>
- [x] T(n) ∈ O(n^3)
- [x] T(n) ∈ O(log(n))
- [ ] T(n) ∉ O(3^n)
- [ ] T(n) ∉ O(n)
- [ ] T(n) ∉ O(n^2(log(n)))

#### <u>Vysvětlení:</u>
- Když to zanalyzujeme, zjistíme, že n se vždycky dělí a je logaritmicky menší a menší a že i roste rychlostí 2^x. tedy z toho vyplývá, že složitost může náležet jak n^3, tak log(n)