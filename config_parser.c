#include "config_parser.h"

Shortcut shortcuts[MAX_SHORTCUTS];
int shortcut_count =  0;



char* find_closing_brace(char *str) {
  int brace_count = 0;
  while(*str ) {
    if(*str == '{') brace_count++;
    if(*str == '}'){
      brace_count--;
      if(brace_count == 0)
        return str;
    }
    str++;
  }
}

void trim_start(char **line){
  while(isspace((unsigned char)**line) && **line != 0) (*line)++;
  return;
}

void trim_end(char **line) {
  char *end = *line + strlen(*line) -1;
  while(isspace((unsigned char) *end) && end >= *line ){ end--;}
  end[1] = '\0';
}

void trim(char **line) {
  trim_start(line);
  trim_end(line);
}


void parse_line(Shortcut *s,char *line) {
  /*trim(&line);*/
  if(line == "") {
    shortcut_count>0?shortcut_count--:0;
    return;

  }
  char *key_start = strstr( line, "MODKEY");
  char *key_end = find_closing_brace(key_start)+1;
  char *description_start = strstr(line,"//<") + 3;
  char *description_end = strstr(line, ">");
  trim_start(&description_start);
  trim_start(&key_start);
  if(key_start && key_end && description_start && description_end) {
    int key_length = key_end - key_start;
    int description_length = description_end - description_start;

    strncpy(s->key, key_start, key_length);
    s->key[key_length]  = '\0';
    strncpy(s->description, description_start, description_length);
    s->description[description_length] = '\0';
    shortcut_count++;


  }
}

int parse_config(const char *filepath) {
  FILE *config = fopen(filepath, "r");
  if(config == NULL){
    fprintf(stderr, "Error Opening File: %s\n", filepath);
    return -1;
  }
  char line[MAX_LINE_LENGTH];

  
  while(fgets(line, MAX_LINE_LENGTH, config)){

    if(strstr(line, "MODKEY") && strstr(line, "//<")){
      parse_line(&shortcuts[shortcut_count], line);
    }
  }

  fclose(config);
  if(shortcut_count == 0 ) {
    return -1;}
  else{
    return 1;
  }
  
}


/*int main(){*/
/*  parse_config("/home/ramees/.config/dwm/config.h");*/
/*  for(int i = 0; i< shortcut_count; i++){*/
/*    printf("%s ---> [%s]\n", &shortcuts[i].key, strupr(shortcuts[i].description));*/
/**/
/*  }*/
/*  return 0;*/
/*}*/
