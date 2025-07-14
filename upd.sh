#!/bin/bash

git pull || exit 1
clear
make fclean
clear
read -p "Insert commit message: " M
git add . && git commit -m "$M" && git push || exit 2
printf "PUSH OK! \n"
