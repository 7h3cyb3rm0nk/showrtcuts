#include <stdio.h>
#include "ui.h"
#include "config_parser.h"
#include <wordexp.h>

int main( int argc, char *argv[]) {

  if (argc > 2) {
    fprintf(stdout, "Usage: showrtcuts <path/to/config.h>\n");
    return -1;
  }
  if (argc == 1){
    wordexp_t expanded_filepath;
    wordexp("~/.config/dwm/config.h", &expanded_filepath, 0);
    char filepath[256];
    /*strncpy(filepath, expanded_filepath.we_wordv[0], strlen(expanded_filepath.we_wordv[0]));*/
  
    /*wordfree(&expanded_filepath);*/
    display_ui((const char*) expanded_filepath.we_wordv[0]);
    wordfree(&expanded_filepath);
  }
  else{
  display_ui(argv[1]);
  }
  return 0;
}
