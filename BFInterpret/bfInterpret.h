typedef struct {
  //what are the purposes of these variables? comments would be nice

  //why was 4000 chosen as a size for the arrays? It seems arbitrary
  int numCells;
  int openedLoops;
  int values[4000];
  int* cells;
  int execute;
  char* positions[4000];
} machine;

//This creates a global instance. It would be better to create a local
// instance in main, and pass a machine* to functions that currently
// use this global machine.
machine turing;

void initMachine(int n){
  turing.numCells = n;
  turing.cells = turing.values;
  turing.openedLoops = 0;
  turing.execute = 1;
}

//simulate > in BF
void moveRight(){
    turing.cells++;
}

//simulate < in BF
void moveLeft(){
    turing.cells--;
}

//simulate . in BF
void printValue(){
    printf("%c",*(turing.cells));
}

//simulate + in BF
void add(){
    *(turing.cells)+=1;
}

//simulate - in BF
void subtract(){
    *(turing.cells)-=1;
}

//simulate , in BF
void input(){
  char c;
  c = getchar();
  *(turing.cells) = c;
}

//simulate [ in BF
void savePosition(char* ptr, int position){
  turing.positions[position] = ptr;
}

//simulate ] in BF
char* retrievePosition(int position){
    return turing.positions[position];}

//Convenience function that prints the values of all the machine's cells
void printTape(){
  int ii;
  printf("\n");
  for(ii = 0; ii<turing.numCells; ii++){
    printf("%d ", turing.values[ii]);
  }
}

//process input from a command line argument
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

//safely get input interactively
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
