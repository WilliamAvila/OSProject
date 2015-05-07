#define SIZE 11
#define COLUMN_SIZE 158
#define LINE_SIZE 25
#define START_OFFSET 0XB000
#define ADDRESS 0x8000


void clear_screen();
void main(){

     char* arr = "Hello World";
     int a = 0x8000; 
     int i;
     int j;
     int columns=0x8000;
     int color =0x0;

   clear_screen();

       for(j =0;j<16;j++){
           for( i =0;i<SIZE;i++){
         	putInMemory(START_OFFSET, a, arr[i]);
	        putInMemory(START_OFFSET, a+1, color);
                a+=0x2;
	
           }
	        a-=SIZE*2;
	        color+=1;
	        a+=160;
        }
            

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

