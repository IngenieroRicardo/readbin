#include <stdio.h>
#include <ctype.h>

void printbin(int numero){
    int bit;
    for(bit = 128; bit > 0; bit >>= 1){
        if((numero & bit) == bit){
            printf("1");    
        }
        else{
            printf("0");    
        }
    }
}

int main(int argc, char* argv[]){
    int contador;
    char puntero[(1024*10)];
    int bytes;
    int bytesmaximo;
    int pesolectura;
    int pesoescritura;
    FILE *archivodebytes;
    bytes = 1;
    bytesmaximo = (1024*10);
    if(argc<=1){
        return 0; 
    }
    archivodebytes = fopen(argv[1],"ab+");
    pesolectura = fread(puntero, bytes, bytesmaximo, archivodebytes);
    printf("\nINICIA EL ANALISIS...\n\n");
    for(contador = 0; contador < (pesolectura / sizeof(unsigned char)); contador++){
            printf(" Bin[%d]=", contador); 
            printbin((int)((unsigned char)puntero[contador])); //BIN
            printf("  Hex[%d]=0X%02x ", contador, (int)((unsigned char)puntero[contador])); //HEX
            printf(" ASCII[%d]=%d ", contador, (int)puntero[contador]); // ASCII

            if((int)puntero[contador]<=-100){
                printf("   Char[%d]=", contador); 
            } else if((int)puntero[contador]<=-10){
                printf("    Char[%d]=", contador); 

            } else if((int)puntero[contador]<0){
                printf("     Char[%d]=", contador);

            } else if((int)puntero[contador]>=100){
                printf("    Char[%d]=", contador); 
            } else if((int)puntero[contador]>=10) {
                printf("     Char[%d]=", contador); 
            } else{
                printf("      Char[%d]=", contador); 
            }
            printf("%c",(char)puntero[contador]); //CHAR
            printf("\n");
    }
    
    printf("\n\nSTRING: \n\n");
    for(contador = 0; contador < (pesolectura / sizeof(unsigned char)); contador++){

        if ( ((int)puntero[contador]) != 0 ){
            if (isalpha((char)puntero[contador]) != 0){
                printf("%c",(char)puntero[contador]);
            }
            else if (isdigit((char)puntero[contador]) != 0){
                printf("%c",(char)puntero[contador]);
            } else {
                printf(" ");
            }
        } 

    }
    fclose(archivodebytes);

    printf("\n\nFIN DEL ANALISIS...\n\n");
    return 0; 
}
