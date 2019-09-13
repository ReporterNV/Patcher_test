#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Короче. Застрял на переводе char -> pointer. Рещи со scanf проблему. Вроде вполня реальное решение. А дальше по тупая работа(описать работу с каждым ключиком). Удачи:) Я играть в over. 
int conv_in_hex(char* a){
printf("%s", a);
int result = 0;
short max = strlen (a);

if((a[0] != '0')||(a[1] != 'x')){
puts("Incorrect hex data");
}

for (int i = 2; i < max; i++){ 
printf("\n%d\n", atoi(&a[i]));
result = atoi(&a[i])%(10*i-1);
printf("\n res conv = %d \n", result);
}
return result;
}


int main(int argc, char *argv[]){
/*
if (argc<2){
fprintf(stdout,"Not enough arguments\n");
return -1;
}*/
printf("ARGV: %d \n", argc);

for(int i=0;argc>i;i++){
	printf("%s\n", argv[i] );
}

unsigned char opcode = 0x0a;//значение на  которое нужно заменить
unsigned int offset = 0x1144;//смещение

for(int i = 1; argc > i; i++){
	printf("\nWORK on %s argv\n", argv[i] );
	if(!memcmp(argv[i], "-c", 2)){
		puts("1");
		sscanf(argv[++i], "%p", &opcode );
		printf("%d");
		puts("2");

	//	opcode = (unsigned char)conv_in_hex(argv[++i]);//значение на  которое нужно заменить
	}

}
printf("%c", opcode);
/*
FILE *f = fopen("pathed","r+b");
fseek(f, offset, SEEK_SET);
fwrite(&opcode, sizeof(opcode), 1, f);
fclose(f);
*/
return 0;
}
