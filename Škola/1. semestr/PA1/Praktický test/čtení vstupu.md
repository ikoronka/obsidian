```c
char *line = NULL;  
size_t linecap = 0;  
ssize_t linelen;    

// načteme line
while ((linelen = getline(&line, &linecap, stdin)) > 0){ 
	int hodnota;
	// podmínka pro to jak vypadá vstup
    if (sscanf(line, "%d", &hodnota){  
        // uložení
    } else if (sscanf(line, "+ %d", &hodnota)){
	    // zpracování dotazu
    } else {  
        printf("Nespravny vstup.\n");  
    }  
}
```