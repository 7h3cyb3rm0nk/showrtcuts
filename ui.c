#include "ui.h"
#include "config_parser.h"



void display_ui(const char *path ) {
  int file_found = parse_config(path);
  if(file_found == -1) {
    printf("file does not exist!!");
    return;
  }
  int row, col;

  WINDOW *screen = initscr();
  CDKSCREEN *cdkscreen = initCDKScreen(screen);
  initCDKColor();
  raw();
  noecho(); 
  idlok(stdscr, TRUE);
  attron(A_BOLD);
  getmaxyx(stdscr, row, col);
  scrollok(stdscr, true);
  refresh();

  char *items[shortcut_count];
  int i=0;
  int j=0;
  while((items[i++] = shortcuts[j++].description) && (i < shortcut_count));

 CDKSCROLL *cdkscroll = newCDKScroll(cdkscreen, 
                           CENTER, CENTER, RIGHT,
                           0, 0,
                           "DWM Shortcuts",
                           items, shortcut_count,
                           TRUE, A_REVERSE,
                           TRUE,TRUE );

  /*destroyCDKSwindow(win);*/
  activateCDKScroll(cdkscroll, 0);
  destroyCDKScroll(cdkscroll);
	destroyCDKScreen(cdkscreen);
	endCDK();

  

  /*for(int i=0; i<shortcut_count; ++i){*/
  /*printw("%s\n",shortcuts[i].description);*/
  /**/
  /*}*/
  /*printw( "press 'q' to quit!\n");*/
  /*char c;*/
  /**/
  /*while((c = getch() )!= 'q'){*/
  /*  if(c == 'j'){*/
  /*    scrl(1);*/
  /*  }*/
  /*  else if(c == 'k'){*/
  /*    scrl(-1);*/
  /*  }*/
  /*  refresh();*/
  /*}*/

  
  


}

void draw_borders_after_refresh(){
  box(stdscr, '+', '-');
  
}


