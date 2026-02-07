#!/bin/bash

TARGET_DIR=${1:-"."}

for f in "$TARGET_DIR"/*.xpm; do
    [ -e "$f" ] || continue

    FILENAME=$(basename "$f" .xpm)
    UPPER_NAME=$(echo "$FILENAME" | tr '[:lower:]' '[:upper:]')
    H_FILE="${TARGET_DIR}/${FILENAME}.h"

    echo "Converting $f to $H_FILE..."

    # Inizio file
    echo "#ifndef ${UPPER_NAME}_H" > "$H_FILE"
    echo "# define ${UPPER_NAME}_H" >> "$H_FILE"
    echo "" >> "$H_FILE"

    # Invece di una macro, creiamo una stringa statica
    # Nota: Rimuoviamo la dichiarazione dell'array se già presente nell'xpm
    # per evitare conflitti, o lo importiamo "così com'è"
    echo "static const char *${FILENAME}_data = " >> "$H_FILE"
    
    # Aggiunge le virgolette e i backslash per rendere il file XPM una stringa C valida
    sed 's/"/\\"/g' "$f" | sed 's/$/\\n"/' | sed 's/^/"/' >> "$H_FILE"
    
    echo ";" >> "$H_FILE"
    echo "" >> "$H_FILE"
    echo "#endif" >> "$H_FILE"
done

echo "Conversione completata con successo!"