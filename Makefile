ui = ui.c ui.h
config = config_parser.c config_parser.h

default: $(ui) $(config)
	cc -o showrtcuts $(ui) $(config)
	
config_parser: $(config)
	cc -o a.out config_parser.c

.PHONY: clean
clean:
	rm -rf a.out
