NAME1 = server
NAME2 = client
NAMEB1 = server_bon
NAMEB2 = client_bon
INC = minitalk.h
SRCS1 = server.c
SRCS2 = client.c
SRCSB1 = server_bon.c
SRCSB2 = client_bon.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJSB1 = $(SRCSB1:.c=.o)
OBJSB2 = $(SRCSB2:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all : $(NAME1) $(NAME2)

bonus: $(NAMEB1) $(NAMEB2)

$(NAME1) : $(OBJS1)
	$(CC) $(CFLAGS) -o $(NAME1) $^

$(NAME2) : $(OBJS2)
	$(CC) $(CFLAGS) -o $(NAME2) $^

$(NAMEB1) : $(OBJSB1)
	$(CC) $(CFLAGS) -o $(NAMEB1) $^

$(NAMEB2) : $(OBJSB2)
	$(CC) $(CFLAGS) -o $(NAMEB2) $^

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS1) $(OBJS2) $(OBJSB1) $(OBJSB2)

fclean:clean
	$(RM) $(NAME1) $(NAME2) $(NAMEB1) $(NAMEB2)

re:fclean all
