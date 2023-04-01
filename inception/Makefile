NAME = Inception

all: $(NAME)

$(NAME):
	@docker-compose -f srcs/docker-compose.yml build && docker-compose -f srcs/docker-compose.yml up -d

logs:
	@docker-compose -f srcs/docker-compose.yml build && docker-compose -f srcs/docker-compose.yml up #-d

down:
	@docker-compose -f srcs/docker-compose.yml down --volumes

fclean: down
	@docker rmi -f $$(docker images -qa);\
	docker system prune -a --force

re: fclean all

.PHONY : all fclean down re logs

