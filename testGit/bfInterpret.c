#include "stdio.h"
#include "stdlib.h"

typedef struct {

  int numCells;
  int openedLoops;
  
  int values[4000];

  int* cells;
  int execute;
  char* positions[4000];


} machine;

machine turing;

void initMachine(int n){
  turing.numCells = n;

  //this method doesn't work well because it makes it necessary to
  //     keep track of the starting position of the cells. An array
  //     does this automatically
  //turing.cells = (int*) calloc(n+1, sizeof(int));

  turing.cells = turing.values;
  turing.openedLoops = 0;
  turing.execute = 1;
}

void moveRight(){
  
    turing.cells++;
}

void moveLeft(){
    turing.cells--;
}

void printValue(){
    printf("%c",*(turing.cells));
}

void add(){
    *(turing.cells)+=1;
}

void subtract(){
    *(turing.cells)-=1;
}

void input(){
  char c;
  c = getchar();
  *(turing.cells) = c;
}

void savePosition(char* ptr, int position){
  turing.positions[position] = ptr;
}
char* retrievePosition(int position){
    return turing.positions[position];}

void printTape(){
  int ii;
  printf("\n");
  for(ii = 0; ii<turing.numCells; ii++){
    printf("%d ", turing.values[ii]);
  }
}

void argInput(char* c){
   
  while((int)*c != 0){
    if(turing.execute == 1){
      if(*c == 43){
	add();
      }
      if(*c == 46){
	printValue();
      }
      if(*c == 44){
	input();
      }
      if(*c == 45)
	subtract();
      if(*c == 60)
	moveLeft();
      if(*c == 62)
	moveRight();
      if(*c == 35)
	printTape();
    }
    if(*c == 91){      
	if(*turing.cells == 0)
	  turing.execute = 0;
      turing.openedLoops +=1;
      //save the current value of the pointer c, plus one in turing 
      // do this in an array indexed by num of opened loops
      // this will allow the use of the [ and ] characters for looping
      savePosition(c+1, turing.openedLoops);
    }
    if(*c == 93){
      if(turing.openedLoops == 1 && *turing.cells == 0){
	
	turing.execute = 1;
      } else if(*turing.cells != 0) {
	//go to the saved value of the c pointer
	c = retrievePosition(turing.openedLoops) - 1;
	turing.openedLoops +=1;
      }
      
      turing.openedLoops -=1;
      //printf("turing.openedLoops = %d", turing.openedLoops);
    }
    
    c++;
  }

}



void getInput(){
  char buffer[4000];
  char *c = buffer;
  int ii;

  fgets(buffer, 4000, stdin);
  //for( ii = 0; ii<10000; ii++){
  while((int)*c != 0){
    if(turing.execute == 1){
      if(*c == 43){
	add();
      }
      if(*c == 44){
	input();
      }
      if(*c == 46){
	printValue();
      }
      if(*c == 45)
	subtract();
      if(*c == 60)
	moveLeft();
      if(*c == 62)
	moveRight();
      if(*c == 35)
	printTape();
    }
    if(*c == 91){      
	if(*turing.cells == 0)
	  turing.execute = 0;
      turing.openedLoops +=1;
      //save the current value of the pointer c, plus one in turing 
      // do this in an array indexed by num of opened loops
      savePosition(c+1, turing.openedLoops);
    }
    if(*c == 93){
      if(turing.openedLoops == 1 && *turing.cells == 0){
	
	turing.execute = 1;
      } else if(*turing.cells != 0) {
	//go to the saved value of the c pointer
	c = retrievePosition(turing.openedLoops) - 1;
	turing.openedLoops +=1;
      }
      
      turing.openedLoops -=1;
      //printf("turing.openedLoops = %d", turing.openedLoops);
    }
    
    c++;
  }
}

int main(int argc, char ** argv){
  initMachine(5);

  //printValue();
  
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


