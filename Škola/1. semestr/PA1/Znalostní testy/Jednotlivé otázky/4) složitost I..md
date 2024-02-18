#complexity
[[složitosti tabulka sorting algoritmů]]
#  T(x,y,z) je časová složitost algoritmu pro hledání největšího společného dělitele tří čísel: GCD(x,y,z). Aritmetická operace s čísly mají složitost O(1). Co platí:
#### <u>Možnosti:</u>
- [ ] T(x,y,z) ∈ O(xyz)
- [ ] T(x,y,z) ∈ O(x^2 + y^2 + z^2)
- [ ] T(x,y,z) ∈ O(log(log(x + y + z)))
- [ ] T(x,y,z) ∈ O(xy + yz + xz)
- [ ] T(x,y,z) ∈ O(x + y + z)
- [ ] T(x,y,z) ∈ O(log(xyz))

#### <u>Odpovědi:</u>
- [x] T(x,y,z) ∈ O(xyz)
- [x] T(x,y,z) ∈ O(x^2 + y^2 + z^2)
- [ ] T(x,y,z) ∈ O(log(log(x + y + z)))
- [x] T(x,y,z) ∈ O(xy + yz + xz)
- [x] T(x,y,z) ∈ O(x + y + z)
- [x] T(x,y,z) ∈ O(log(xyz))

#### <u>Vysvětlení:</u>
- T(x,y,z) ∈ O(xyz)
	- musí se provést operace, které jsou na sobě lineárně závislé. Třeba máme v sobě 3 for loopy, jeden pro x, jeden pro y, jeden pro z
-  T(x,y,z) ∈ O(x^2 + y^2 + z^2)
	- můžeme iterovat u každého prvku samo přes sebe
- ~~T(x,y,z) ∈ O(log(log(x + y + z))) ~~
	- tohle pro GCD prostě není typické, nikdy by tak nízkou složitost nemělo
- T(x,y,z) ∈ O(xy + yz + xz)
	- další součet nějakých závislostí, dává smysl
- T(x,y,z) ∈ O(x + y + z)
	- součet čísel samo o sobě, taky možnost
- T(x,y,z) ∈ O(log(xyz))
	- při ideálním Euklidově algoritmu se čísla budou zmenšovat a zmenšovat a při tom i sníží průběh funkce -> logaritmická složitost