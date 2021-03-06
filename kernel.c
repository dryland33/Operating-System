#define BUFLEN 512
#define FI_LEN 13312
void readFile(char*, char*);
void runProgram(char*, int);
void error(int);
void clearBuffer(char*, int);
void handleInterrupt21 (int, int, int, int);
int div(int, int);
int mod(int, int);

void main()
{
    char line[BUFLEN];
    char file[FI_LEN];
    char* p = &line;
    int number, color_1=2, color_2=12;
    int running=1;

    clearBuffer(line, BUFLEN);
    /*clear screen*/
    handleInterrupt21(12, color_1, color_2, 0);
    handleInterrupt21(0, "Based on a project by M. Black. \r\n\0", 0, 0);
    handleInterrupt21(0,"Author: Rylan Wassem                 /) \r\n\0", 0, 0);
    handleInterrupt21(0,"                                    \'  \\ \r\n\0", 0, 0);
    handleInterrupt21(0,"                                   /    \\ \r\n\0", 0, 0);
    handleInterrupt21(0,"                                 /\'    o \\ \r\n\0", 0, 0);
    handleInterrupt21(0,"                               /\'         \\ \r\n\0", 0, 0);
    handleInterrupt21(0,"                          _.-\'      /`-.   ) \r\n\0", 0, 0);
    handleInterrupt21(0,"               __.-\'\"\"\"\"\"\'         /    `-\' \r\n\0", 0, 0);
    handleInterrupt21(0,"             /\'                   (  _._ \r\n\0", 0, 0);
    handleInterrupt21(0,"            /       __      (       ___ \\ \r\n\0", 0, 0);
    handleInterrupt21(0,"          /\'          \\      \\.____/   \\_) \r\n\0", 0, 0);
    handleInterrupt21(0,"         /             \\   \\  | \r\n\0", 0, 0);
    handleInterrupt21(0,"        /   __          |   \\_) \r\n\0", 0, 0);
    handleInterrupt21(0,"       |   /  \\_        |  _/ \r\n\0", 0, 0);
    handleInterrupt21(0,"       |  /     )      / /\\\' \r\n\0", 0, 0);
    handleInterrupt21(0,"      .\' |    _/      /_/ \r\n\0", 0, 0);
    handleInterrupt21(0,"      |  |  /\'     __/\' \r\n\0", 0, 0);
    handleInterrupt21(0,"      |  |  \\    /\' \r\n\0", 0, 0);
    handleInterrupt21(0,"      |  |   \\   \\ \r\n\0", 0, 0);
    handleInterrupt21(0,"     /  /     \\   \\ \r\n\0", 0, 0);
    handleInterrupt21(0," __/\' _/        \\  `----. \r\n\0", 0, 0);
    handleInterrupt21(0,"(___/\'           `------\' \r\n\0", 0, 0); 
    handleInterrupt21(0,"Press              Enter \r\n\0", 0, 0); 
    /*read string*/
    handleInterrupt21(1, line, 0, 0);
    handleInterrupt21(0," _    _            _  __        _  ____    _____ \r\n\0", 0, 0);
    handleInterrupt21(0,"| |  | |          | |/ /       | |/ __ \\ / ____| \r\n\0", 0, 0);
    handleInterrupt21(0,"| |__| | __ _  ___| ' / ___  __| | |  | || (___ \r\n\0", 0, 0);
    handleInterrupt21(0,"|  __  |/ _` |/ __|  < / _ \\/ _` | |  | |\\__ _ \\ \r\n\0", 0, 0);
    handleInterrupt21(0,"| |  | | (_| | (__| . \\  __/ (_| | |__| |____) |\r\n\0", 0, 0); 
    handleInterrupt21(0,"|_|  |_|\\__,_|\\___|_|\\_\\___|\\__,_|\\____/|_____/\r\n\0", 0, 0);
    handleInterrupt21(0,"Type qX + Enter + Enter to QUIT.\r\n\0", 0, 0);
    handleInterrupt21(0,"Type rX + Enter + Enter to REBOOT.\r\n\0", 0, 0);
    handleInterrupt21(0,"\r\n\0", 0, 0);
    
    makeInterrupt21();
    runProgram("test2", 2);
    /*runProgram("fib", 2);*/    

    while(running){
        /*
        handleInterrupt21(0,"Enter a file name: \r\n\0", 0, 0);
        clearBuffer(line, BUFLEN);
        handleInterrupt21(1, line, 0, 0);
        readFile(line, file);
        handleInterrupt21(0, file, 0, 0);
        clearBuffer(file, FI_LEN);
        
        handleInterrupt21(0,"Enter a program name: \r\n\0", 0, 0);
        clearBuffer(line, BUFLEN);
        handleInterrupt21(1, line, 0, 0);
        handleInterrupt21(4, line, 2, 0);
		*/
        handleInterrupt21(0,"Say something: \r\n\0", 0, 0);
        clearBuffer(line, BUFLEN);
        
        /*read string*/
        handleInterrupt21(1, line, 0, 0);
        handleInterrupt21(0,"\r\nYou said: \r\n\0", 0, 0);
        handleInterrupt21(0, line, 0, 0);
        
        handleInterrupt21(0,"Enter a number: \r\n\0", 0, 0);

        /*read int*/
        handleInterrupt21(14, &number, 0, 0); 
        handleInterrupt21(0,"\r\nYour number is: \r\n\0", 0, 0);

        /*write int*/
        handleInterrupt21(13, number, 0, 0);
        handleInterrupt21(0,"\r\n\0", 0, 0);  

        if (line[0]=='r' && line[1]=='X'){
            handleInterrupt21(0,"Restarting: \r\n\0", 0, 0);
            running = 0; 
        }
        if (line[0]=='q' && line[1]=='X'){
            handleInterrupt21(0,"Shutting Down: \r\n\0", 0, 0);
            interrupt(0x15,0x5307,0x0001,0x0003,0); 
        }
        /*ACID TEST:*/
        /*number = 1;
        while(number!= 0){
            handleInterrupt21(13, number, 0, 0);
            handleInterrupt21(0,"\r\n\0", 0, 0);
            number++;
            color_1 = mod(color_1, 7) + 1;
            color_2 = mod(color_2, 15) + 1;
            handleInterrupt21(12, color_1, color_2, 0);
        }*/
    }  
}

void clearBuffer(char* c, int bufLen){           /*getting the garbage out of my array*/
    int i=0;
    for(i; i<bufLen; i++){
        c[i]='\0';
    }
}

void printString(char* c)
{
    int i=0;
    while(c[i] != '\0'){
        int x=c[i];
        interrupt(0x10,0xe00+x,0,0,0);           /*ASCII value gets passed to interrupt 16*/ 
        ++i;
    }         
return;
}

void readString(char* c){                        
    int char_count = 0;                          /*length of string*/
    int is_reading = 1;                          /*true while Enter isn't pressed*/
    c[0]='\r';
    c[1]='\n';
    c[2]='\0';
    
    while(is_reading){
        int input = interrupt(0x16,0,0,0,0);     /*call to keyboard reading routine*/

        switch(input){                           /*what was read from the keyboard?*/

        case 0xd :                               /*user pressed Enter key*/ 
            c[char_count] = '\r';                /*carriage return*/
            c[char_count+1] = '\n';              /*line feed*/             
            c[char_count+2] = '\0';              /*set end of string equal to null*/
            is_reading = 0;                      /*terminate the loop*/
            break;
            
        case 0x8 :                               /*user pressed Backspace key*/
        if(char_count>0){
            char_count--;                        /*shorten the string*/
            interrupt(0x10,0xe08,0,0,0);         /*pass Backspace signal to console*/
            interrupt(0x10,0xe20,0,0,0);         /*overwrite the character on the screen*/
            interrupt(0x10,0xe08,0,0,0);         /*pass Backspace signal to console again*/
            break;   
        }  
        default:                                 /*Here be dragons: printString(input);*/
            c[char_count] = input;               /*add a character to the string*/
            interrupt(0x10,0xe00+input,0,0,0);   /*pass char to console writing routine*/
            char_count++;                        /*increment the string length*/
        }
    }
return;
}

void readSector(int* storage, int sector){

int trackNo, relSecNo, headNo, CX, DX; 
       
/*
AH = 2 (this number tells the BIOS to read a sector as opposed to 3 for write)
AL = number of sectors to read (use 1)
AX = AH * 256 + AL = 513 in this case

BX = address where the data should be stored to (pass your char* array here)

CH = track number(trackNo)
CL = relative sector number(relSecNo)
CX = CH * 256 + CL = trackNo * 256 + relSecNo

DH = head number(headNo)
DL = device number (for the floppy disk, use 0)
DX = DH * 256 + DL = headNo * 256

relSecNo = (absSecNo MOD 18) + 1
headNo = (absSecNo DIV 18) MOD 2
trackNo = (absSecNo DIV 36)
*/
    relSecNo = mod(sector, 18) + 1;
    headNo = div(sector, 18);
    headNo = mod(headNo, 2);
    trackNo = div(sector, 36);
    CX = trackNo * 256;
    CX += relSecNo;
    DX = headNo * 256;

    interrupt(19, 513, storage, CX, DX);
}

void writeSector(int* storage, int sector){

int trackNo, relSecNo, headNo, CX, DX; 
       
    relSecNo = mod(sector, 18) + 1;
    headNo = div(sector, 18);
    headNo = mod(headNo, 2);
    trackNo = div(sector, 36);
    CX = trackNo * 256;
    CX += relSecNo;
    DX = headNo * 256;

    interrupt(19, 769, storage, CX, DX);
}

void readFile(char* req_name, char* contents/*, int size*/){

char buffer[512];
int i = 0; 
int offset = 0; 
int sector_number = 6; 
int req_length = 0; 
int match = 1; /*assumes true until a difference is found*/
    
    while (req_name[req_length] != '\r') { /*TODO come up with a better string format*/
        if (req_length < 6)
            ++req_length;
    }
    /*patterns the requested file string after a directory entry*/ 
    for (i=req_length; i<6; ++i) {
        req_name[i] = '\0';
    }
    
    /*calls readSector() and reads in the directory*/
    handleInterrupt21(2, buffer, 2, 0);
    
    /*while() compares the first letter in each directory entry with the first letter in the request*/
    while ((req_name[0] != buffer[offset]) && (offset < 512)) {
        offset += 32;
        if(offset == 512) match = 0;
        for (i=0; i < 6; ++i) {
            /*char by char comparison*/
            if (req_name[i] != buffer[offset + i]) 
                match = 0;
        }
    }

    if (match){ /*gets the data associated with the matching file name*/
        while ((buffer[offset + sector_number]) && (sector_number < 32)) {
            handleInterrupt21(2, contents, buffer[offset + sector_number], 0);
            ++sector_number;
            contents += 512;
            return;
	}
    }/*if all else fails*/
    error(0);             
}

void runProgram(char* program, int mem_seg){
    int i=0;
    char prog[FI_LEN];
/*
Call readFile() to load the file into a buffer.
*/
    readFile(program, prog);
/*
Multiply segment by 0x1000 (4096) to derive the base location of the indicated segment.
*/
    mem_seg *= 4096;

/*
In a loop, use putInMemory() to transfer the loaded file from the buffer into 
the memory based at the computed segment location, starting from offset.
  
    void putInMemory (int segment, int address, char character)
*/
    for(i; i<FI_LEN; ++i){
        putInMemory(mem_seg, i, prog[i]);
    }
/*
Call launchProgram() which takes the base segment address as a parameter.
*/
    launchProgram(mem_seg);
}

void stop(){
    while(1);
}

void clearScreen(int bx, int cx){
    int i = 0;
    int colors; 

    colors = (0x1000 * (bx-1) + 0x100 * (cx-1));

/*Issue 24 carriage return/newline combinations.*/
    for(i; i<24; i++){
	interrupt(0x10,0xe0d,0,0,0);
	interrupt(0x10,0xe0c,0,0,0);
    }

/*Call BIOS function 16/2 which repositions the cursor 
in the upper left-hand corner (coordinates (0,0)) 
after the existing text has been cleared away.*/ 
    interrupt(0xF,0x200,0,0,0);


/*If both bx and cx are bigger than zero we execute:*/
    if (bx && cx){
    interrupt(16, 1563, colors, 0, 6323);        
    }
/*which calls BIOS function 16/6 to scroll the window with these parameters:
AH = 6, indicates function 6
AL = 0, means scroll whole screen or window
BH is set to the attribute byte for blank lines
CH and CL are the row and column for the upper left-hand corner of the window (0,0)
DH and DL are the row and column for the lower right-hand corner, (24,79)
*/
    interrupt(0x10,0xe08,0,0,0);         /*pass Backspace signal to console*/
    return;
}

int mod(int a, int b){

   int x = a;
   while (x >= b) x = x - b;
   return x;
}

int div(int a, int b){

   int q = 0;
   while (q * b <= a) q++;
   return (q - 1);
}

void writeInt(int x){

   char number[6], *d;
   int q = x, r;

   if (x < 1){
      d = number; *d = 0x30; d++; *d = 0x0; d--;
   }
   else{
      d = number + 5;
      *d = 0x0; d--;
      while (q > 0){
         r = mod(q,10); q = div(q,10);
         *d = r + 48; d--; 
      }
      d++;
   }
   printString(d);
}

/* ASCII values of decimal digits 0-9 range from 0x30-0x39 */
void readInt(int* number){

    int char_count = 0;                          /*length of string of key signals*/
    int is_reading = 1;                          /*true while Enter isn't pressed*/
    int temp_num[5];                             /*int overflows around 0x7FF7 so this will do*/ 
    int pow10;
    int i = 0;
    int j = 0;
    *(number) = 0;

    while(is_reading){
        int input = interrupt(0x16,0,0,0,0);     /*call to keyboard reading routine*/

        switch(input){                           /*what was read from the keyboard?*/

        case 0xd :                               /*user pressed Enter key*/
	    for(i; i<char_count; i++){           
		pow10=1;                         /*each digit gets multiplied by a power of ten*/
		for(j=(i+1); j<char_count; j++){ /*the rightmost digit will be multiplied*/
		    pow10 *= 10;                 /*by 10^char_count and so on*/  
		} 
		temp_num[i] *= pow10;            /*now temp_num[i] holds the correct value*/
		*(number) += temp_num[i];        /*our running total*/
	    }                                    /*set arg value equal to the total*/ 
            is_reading = 0;                      /*terminate the loop*/
            break;
            
        case 0x8 :                               /*user pressed Backspace key*/
        if(char_count>0){                        /*ensure positive char_count*/   
            char_count--;                        /*shorten the string*/
            interrupt(0x10,0xe08,0,0,0);         /*pass Backspace signal to console*/
            interrupt(0x10,0xe20,0,0,0);         /*overwrite the character on the screen*/
            interrupt(0x10,0xe08,0,0,0);         /*pass Backspace signal to console again*/
            break;   
        }  
        default:                                 
            temp_num[char_count] = input - 0x30; /*add the character minus ASCII offset to value*/
            interrupt(0x10,0xe00+input,0,0,0);   /*pass the character to console writing routine*/
            char_count++;                        /*increment the "string" length*/
        }
    }/*end while*/   
    return;
}

void error(int er_num){
char er_mess[32];

    switch(er_num){
        case 0 :
        /*calls printString()*/
        handleInterrupt21(0, "FILE NOT FOUND!!! \r\n\0", 0, 0);
        break;
    }
}

/*
void printString(char*);
void readString(char*);
void readSector(int*, int);
void readFile(char*, char*, int);
void runProgram(char*, int);
void stop();
void clearScreen(int, int);
void writeInt(int);
void readInt(int*);
void error(int);

╔════════════════════╦═════╦══════════════════╦═══════════════╦═══════╗
║      Function      ║ AX= ║       BX=        ║      CX=      ║  DX=  ║
╠════════════════════╬═════╬══════════════════╬═══════════════╬═══════╣
║ printString(bx)    ║   0 ║ &string          ║ 0             ║ 0     ║
║ readString(bx)     ║   1 ║ &string          ║ 0             ║ 0     ║
║ readSector(bx,cx)  ║   2 ║ &storage         ║ sector number ║ 0     ║
║ readFile(bx,cx,dx) ║   3 ║ &file name       ║ &contents     ║ count ║
║ runProgram(bx,cx)  ║   4 ║ &file name       ║ mem seg       ║ 0     ║
║ stop()             ║   5 ║ 0                ║ 0             ║ 0     ║
║ clearScreen(bx,cx) ║  12 ║ BG(1–8)          ║ FG(1-16)      ║ 0     ║
║ writeInt(bx)       ║  13 ║ integer to print ║ 0             ║ 0     ║
║ readInt(bx)        ║  14 ║ &integer         ║ 0             ║ 0     ║
║ error(bx)          ║  15 ║ error number     ║ 0             ║ 0     ║
╚════════════════════╩═════╩══════════════════╩═══════════════╩═══════╝
*/
void handleInterrupt21 (int AX, int BX, int CX, int DX){
    switch (AX){

    case 0 : 
        printString(BX);
        break;

    case 1 :
        readString(BX);
        break;

    case 2 :
        readSector(BX, CX);
        break;

    case 3 :
        readFile(BX, CX, DX);
        break;

    case 4 :
        runProgram(BX, CX);
        break;

    case 5 :
        stop();
        break;
		
    case 6:
		writeSector(BX, CX);
		break;
		
	case 7: 
		deleteFile(BX);
		break;
	
	case 8: 
		writeFile(BX, CX, DX);
		break;
	
	/*Reboot*/	
	case 11:
		interrupt(25,0,0,0,0);
		
    case 12 : 
        clearScreen(BX, CX);
        break;

    case 13 :
        writeInt(BX);
        break;
 
    case 14 :
        readInt(BX);
        break;

    case 15 :
        error(BX);
        break; 
    }
}
