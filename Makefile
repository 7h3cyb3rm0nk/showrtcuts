ui_headers = ui.c ui.h
config_headers = config_parser.c config_parser.h
ui_o = ui.o
config_o = config.o

default: $(ui_o) $(config_o)
	cc -o showrtcuts $(config_o) $(ui_o) main.c -lncurses -lcdk -ggdb3

config.o: $(config)
	cc -c config_parser.c -o config.o

ui.o: $(ui_headers)
	cc -c ui.c -o ui.o



.PHONY: clean
clean:
	rm -rf *.o ncurses
