#!/bin/bash

git pull || exit 1
clear
make fclean
clear
(cd cub3D && rm -f temp) && (cd cub3D_bonus && rm -f temp) 
read -p "Insert commit message: " M
git add . && git commit -m "$M" && git push || exit 2
printf "PUSH OK! \n"
