[V]	Parsing
    {X} The map must be closed/surrounded by walls, if not the program must return
        an error.
    {X} Except for the map content, each type of element can be separated by one or
        more empty lines.
    {X} Except for the map content which always has to be the last, each type of
        element can be set in any order in the file.
    {X} Except for the map, each type of information from an element can be separated
        by one or more spaces.
    {X} The map must be parsed as it looks in the file. Spaces are a valid part of the
        map and are up to you to handle. You must be able to parse any kind of map,
        as long as it respects the rules of the map.
[X]	Minilibx structure
    {X} Inizializzare immagini e texture
    {X} Creare la finestra e far partire il mlx loop hook
    
[X]	Struttura dati
[X]	Inizializzazione
[Leo si, ale un pochino dai]	Studiare raycasting
    ----> https://hackmd.io/@nszl/H1LXByIE2
[X]	Chiusura tutto

[X]	MANDATORY
	{X}	Sostituire muro debug con texture vera
    {X}  Evitare il segfault quando si esce dalla mappa

[X] RAYCASTING
	{X}	Muovere player
	{X}	Ottimizzare algoritmo linea con intersezioni in x e y
	{X}	Ottenere get_data_address textures
	{X}	Creare cornice
	{X}	Modificare get_data_address cornice
	{X}	Salvare punti di collisione, calcolare lunghezza raggio
	{X}	Castare nella cornice
		{X}	Sostituire muro debug con texture vera
            (X) Percentuale del muro in cui viene colpito dal raggio in modo da prendere i pixel dele texture nel punto corrispondente
            (X) Distanza dal muro
		{}	DDA
		{X}	Sistemare codice
		{X}	Sistemare globali
        
[]	GAME
	{}	Animazioni
	{}	Generare mappe randomiche
	{}	Alzare abbassare visuale
	{X}	Porte
	{X}	Minimappa
	{X}	Rotazione visuale con mouse
	{}	Hitbox