#include "config_parser.h"




Shortcut shortcuts[MAX_SHORTCUTS];
int shortcut_count =  0;


bool __contains_substring(const char *string, const char *c){
  return (strstr(string, c) != NULL);
}


bool  check_line_for_comments(const char *line) {
  return ( (__contains_substring(line, "{MODKEY") &&
                 !(__contains_substring(line, "TAGKEY")) && __contains_substring(line, "//<"))
         && ( __contains_substring(line, "}")) );

}

 
void parse_config_file(const char* filename){

  FILE *config_file = fopen(filename, "r");
  if(config_file == NULL){
    perror("Error opening file..!\n");

    return;
  }

  char line[MAX_LINE_LENGTH];
  while(fgets(line, MAX_LINE_LENGTH, config_file)){
    /*printf("%s\n", line);*/
   if( check_line_for_comments(line))
    {
      char *key_start = strstr(line,"MODKEY");
      char *key_end = strstr(line, "}}") + 2;
      int key_length = key_end - key_start;
      char key[key_length] ;
      
      strncpy(key,key_start, key_length);
      key[key_length] = '\0';
      printf("%s %d\n", key, key_length);
      
    }
  }
  fclose(config_file);
}

int main(){
  parse_config_file("/home/ramees/.config/dwm/config.h");
  return 0;
}
