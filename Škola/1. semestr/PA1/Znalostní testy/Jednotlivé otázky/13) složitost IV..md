#complexity
[[složitosti tabulka sorting algoritmů]]
# Máme množinu n bodů v rovině (x,y) a máme zjistit duplicity. Jakou bude mít algoritmus složitost?
#### <u>Možnosti:</u>
- [ ] $\sqrt{n}$
- [ ] $n^2*log(n)$
- [ ] $log(n)$
- [ ] $n^\sqrt{2}$
- [ ] 1
- [ ] $n*log(n^3)$

#### <u>Odpovědi:</u>
- [ ] $\sqrt{n}$
- [x] $n^2*log(n)$
- [ ] $log(n)$
- [x] $n^\sqrt{2}$
- [ ] 1
- [x] $n*log(n^3)$

#### <u>Vysvětlení:</u>
- vždy, když chceme něco sesortit, tak to má složitost $n*log(n)$
	-  $n^2*log(n)$
		```python
		def find_duplicates(points): 
			duplicates = set() 
			n = len(points) 
			points.sort() # O(n*log(n)) 
			for i in range(n): # O(n) 
				for j in range(i+1, n): # O(n) 
					if points[i] == points[j]: 
						duplicates.add(points[i]) 
			return duplicates
		```
	-  $n^\sqrt{2}$
		```python
		def find_duplicates(points):
		    seen = set()
		    duplicates = set()
			for point in points:  # O(n)
		        if point in seen:  # O(sqrt(n))
		            duplicates.add(point)
		        else:
		            seen.add(point)
		    return duplicates
		```
	- $n*log(n^3)$
		- to jde jen o tom, jak to sesortime