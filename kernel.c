#define SIZE 11
#define COLUMN_SIZE 158
#define LINE_SIZE 17
#define START_OFFSET 0XB000
#define ADDRESS 0x8000

void clear_screen();
void printString(char *);
void readString(char *);
void CleanSpace(int);
void main(){
	
	 char line[80];
	 char* x ;
	 char* y;
     char* arr = "Hello World";
     int a = 0x8000; 
     int i;
     int j;
     int columns=0x8000;
     int color =0x0;
	 char buffer[512];
    // clear_screen();

     /*for(j =0;j<16;j++){
           for( i =0;i<SIZE;i++){
         	putInMemory(START_OFFSET, a, arr[i]);
	        putInMemory(START_OFFSET, a+1, color);
                a+=0x2;
	
           }
	        a-=SIZE*2;
	        color+=1;
	        a+=160;
		    }*/
		initVideo();
		
		setCursor(1,1,0);
		printString("                          Welcome to the my OS");
		

		setCursor(getCursorRow(),getCursorColumn()+1,0);
		readChar();
		setCursor(0,0,0);
		
		initVideo();
		setBackground(0x43);
		makeInterrupt21();
		loadProgram();

		/*printString("Enter a line: \0");
		readString(line);
		printString(line);*/

		/*CleanSpace(1000);
		readString(x);

		printString("Hello World \0");*/

}

void printString(char * arr){
	int x =0;
	while(arr[x]!='\0'){
			printChar(arr[x]);
		x++;
	}


}

void CleanSpace(int i){
	int j;
	
	printChar('\n');
	for(j=0;j<i;j++)
		printChar(0x8);

}



void readString(char *x){
		int j =0;

		while(j<81){
				x[j] = readChar();
				if(x[j]==0x8 && j > 0){
					printChar(0x8);
					printChar(0x0);
					printChar(0x8);		
					j-=1;
					
				}else if(x[j] == 0xd){
					printChar('\n');
					printChar(0x8);
					x[j] ='\0';
					break;
				}
				else if(j<80 && x[j] != 0x8 && x[j] != 0xd){
					printChar(x[j]);
					j++;
				}
				

		}
	
		CleanSpace(j-1);
}

void clear_screen(){
int i;
int j;
  int x = 0x8000;
	for(j =0;j<LINE_SIZE;j++){
             for( i =0;i<COLUMN_SIZE;i++){
	      putInMemory(START_OFFSET, x, 0);
	      x+=1;

	     }
		x-=COLUMN_SIZE;
		x+=160;
	}



}



