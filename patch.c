#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

if (argc<2){
fprintf(stdout,"Not enough arguments\n");
return -1;
}

unsigned char opcode = 0x00;
unsigned int offset = 0x000;
char str[255] = "patched";

for(int i = 1; argc > i; i++){
	printf("\nWORK on %s argv\n", argv[i] );
	if( (!strcmp(argv[i], "-c")) || (!strcmp(argv[i], "--code")) ) 
		sscanf(argv[++i], "%x", &opcode );
	else
	if( (!strcmp(argv[i], "-f")) || (!strcmp(argv[i], "--file")) )
		sscanf(argv[++i], "%255s", str);
	else
	if( (!strcmp(argv[i], "-p")) || (!strcmp(argv[i], "--position")) || (!strcmp(argv[i], "--set")) ) 
		sscanf(argv[++i], "%x", &offset);
	else
	printf("\nWrong argument: %s\n", argv[i]);
}

FILE *f = fopen(str, "r+b");
fseek(f, offset, SEEK_SET);
fwrite(&opcode, sizeof(opcode), 1, f);
fclose(f);

return 0;
}
