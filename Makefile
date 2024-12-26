ui_headers = ui.c ui.h
config_headers = config_parser.c config_parser.h
ui_o = ui.o
config_o = config.o
CC = gcc

default: $(ui_o) $(config_o)
	$(CC) -o showrtcuts $(config_o) $(ui_o) main.c -lncurses -lcdk  -ggdb3

config.o: $(config)
	$(CC) -c config_parser.c -o config.o

ui.o: $(ui_headers)
	$(CC) -c ui.c  -o ui.o



.PHONY: clean
clean:
	rm -rf *.o ncurses
