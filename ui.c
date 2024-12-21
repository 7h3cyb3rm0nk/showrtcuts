#include "ui.h"
#include "config_parser.h"


void display_ui(const char *path ) {
  int file_found = parse_config(path);
  if(file_found == -1) {
    printf("file does not exist!!");
    return;
  }
  int row, col;

  initscr();
  raw();
  noecho();
  attron(A_BOLD);
  getmaxyx(stdscr, row, col);
  

  for(int i=0; i<shortcut_count; ++i){
  printw("%s\n",shortcuts[i].description);
  refresh();
  }
  /*mvprintw(row-2, 0, "press 'q' to quit!");*/
  refresh();

  while(getch() != 'q'){
    refresh();
  }
  endwin();
  
  


}


