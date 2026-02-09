#!/bin/bash

TARGET_DIR=${1:-"."}

for f in "$TARGET_DIR"/*.xpm; do
    [ -e "$f" ] || continue

    FILENAME=$(basename "$f" .xpm)
    UPPER_NAME=$(echo "$FILENAME" | tr '[:lower:]' '[:upper:]' | tr '-' '_')
    H_FILE="${TARGET_DIR}/${FILENAME}.h"

    echo "Converting $f to $H_FILE..."

    # Inizio file header
    echo "#ifndef ${UPPER_NAME}_H" > "$H_FILE"
    echo "# define ${UPPER_NAME}_H" >> "$H_FILE"
    echo "" >> "$H_FILE"

    # Definizione della macro
    echo "# define ${UPPER_NAME}_data \\" >> "$H_FILE"
    
    # Processamento del file XPM:
    # 1. Escaping dei doppi apici esistenti: \" -> \\\"
    # 2. Avvolgimento riga: aggiunge " all'inizio e "\ alla fine
    # 3. L'ultima riga non deve avere il backslash finale
    
    sed 's/"/\\"/g' "$f" | sed 's/$/" \\/' | sed 's/^/"/' >> "$H_FILE"
    
    # Aggiungiamo una riga vuota finale per chiudere in sicurezza la sequenza di backslash
    echo "\"\"" >> "$H_FILE"
    echo "" >> "$H_FILE"
    echo "#endif" >> "$H_FILE"
done

echo "Conversione completata! Ora puoi usare ${UPPER_NAME}_data nell'array statico."