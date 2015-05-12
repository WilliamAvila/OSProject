#define SIZE 11
#define COLUMN_SIZE 158
#define LINE_SIZE 17
#define START_OFFSET 0XB000
#define ADDRESS 0x8000

void clear_screen();
void printString(char *);
void readString(char *);
void main(){
	
	 char* x ;
	 char* y;
     char* arr = "Hello World";
     int a = 0x8000; 
     int i;
     int j;
     int columns=0x8000;
     int color =0x0;
	 char line[80];
     clear_screen();

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


			for(j=0;j<80;j++){
				x[i] = readChar();
				if(x[i]==0xd){
					String(line);
					break;
				}
			line[i] = x[i];
			printChar(x[i]);

		}

		//printString("Hello World \0");

}


void printString(char * arr){
	int x =0;
	while(arr[x]!='\0'){
		printChar(arr[x]);
		x++;
	}


}

void readString(char arr[]){
	int i;
	printChar('\n');
	for(i =0;i<80;i++)					
		printChar(arr[i]);
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



