#include "stdio.h"
#include "stdlib.h"
#include "bfInterpret.h"

int main(int argc, char ** argv){
  initMachine(5);

  //printValue();
  
  if(argc == 1){
    printf("usage: bfInterpret <input>\nor, for interactive mode:\nbfInterpret -i\n");
    return 0;
  }

  if(!strcmp(argv[1],"-i")){
    getInput();
  }
  else
    argInput(argv[1]);
  //getInput();
  //  printTape();
  printf("\n");
  return 0;
}


