#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#define MAX_SHORTCUTS 100
#define MAX_LINE_LENGTH 512


typedef struct {
  char key[128];
  char description[512];
} Shortcut;


extern Shortcut shortcuts[MAX_SHORTCUTS];
extern int shortcut_count;

int parse_config(const char *filepath);
void parse_line(Shortcut *s, char *description);
void trim_start( char **line);
void trim_end(char **line);
void trim(char **line);
bool starts_with(char *string, char *line);
bool ends_with(char *string, char *line);

#endif
