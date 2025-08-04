MAN = cub3D
BON = cub3D_bonus

all: 
	make all -C $(MAN)
	make all -C $(BONUS)

bonus:
	make -C $(BON)

clean:
	make clean -C $(MAN)
	make clean -C $(BON)

fclean: 
	make fclean -C $(MAN)
	make fclean -C $(BON)

re:
	make re -C $(MAN)
	make re -C $(BON)

start: pull
	make start -C $(MAN)
	make start -C $(BON)

pull: 
	git pull

push: 
	./upd.sh

.PHONY: all bonus clean fclean re start pull push
.SILENT: