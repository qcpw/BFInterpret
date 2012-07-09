#include "stdio.h"
#include "stdlib.h"
#include "bfInterpret.h"

int main(int argc, char ** argv){
  machine turing;
  initMachine(5, &turing);

  //printValue();
  
  if(argc == 1){
    printf("usage: bfInterpret <input>\nor, for interactive mode:\nbfInterpret -i\n");
    return 0;
  }

  if(!strcmp(argv[1],"-i")){
    getInput(&turing); 
  }
  else
    argInput(argv[1], &turing);
  //getInput();
  //  printTape();
  printf("\n");
  return 0;
}


