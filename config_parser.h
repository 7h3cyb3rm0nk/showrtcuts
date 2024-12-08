#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SHORTCUTS 100
#define MAX_LINE_LENGTH 256


typedef struct {
  char key[32];
  char description[128];
} Shortcut;


extern Shortcut shortcuts[MAX_SHORTCUTS];
extern int shortcut_count;

void parse_config_file(const char *filename);
bool __contains_substring(const char *string, const char *c);
bool check_line_for_comments(const char *line);

#endif
