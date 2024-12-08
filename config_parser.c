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
      printf("%s\n", line);
    }
  }
  fclose(config_file);
}

int main(){
  parse_config_file("/home/ramees/.config/dwm/config.h");
  return 0;
}
