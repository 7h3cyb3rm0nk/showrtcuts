#include <stdio.h>
#include "ui.h"
#include "config_parser.h"


int main( int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "%s <path/to/config.h\n", argv[0]);
  }
  return 0;
}
