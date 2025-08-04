#!/bin/bash

cd cub3D_bonus
find . -type f -name '*.c' | while IFS= read -r file; do
  dir=$(dirname "$file")
  base=$(basename "$file" .c)
  mv "$file" "$dir/${base}_bonus.c"
done
cd ..