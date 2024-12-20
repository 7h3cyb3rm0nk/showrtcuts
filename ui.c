#include "ui.h"
#include "config_parser.h"


void display_ui(const char *path) {
again:parse_config_file(path);

  initscr();
  for(int i=0; i<shortcut_count; ++i){
    printw("%s: %s\n\n", shortcuts[i].key, shortcuts[i].comment);
  }
  refresh();
  char quit = getch();
  if(quit == 'q')
  endwin();
  else
  goto again;


}


