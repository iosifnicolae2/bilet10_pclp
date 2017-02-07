#include <iostream>
#include <math.h>


int strlen(char *c){
int i = 0;
while(*c!=0){
    c++;i++;
}
return i;
}


void int_to_a(long j,char *&c){
    c = new char[10];
    int p =0;

    /*
     * i = 1234567
     * c = 654321 ar trebui sa fie 123456
     */
//
//    long ogl = 0;
//    while(i!=0){
//        ogl=ogl*10+i%10;
//        i/=10;
//    }
//    // am facut oglinditul, adica din 123456 ogl=654321
//
//    while(ogl!=0){
//        char nr =  ogl %10+'0';//am scris + '0' ca sa imi ia codul asci lui 0 si sa adauge cifra mea.. si apoi cand va fi afisat ca si char va afisa caracterul respectivului numar
//        ogl/=10;
//        c[p++]=nr;
//    }

    if(j<0){
        while(j!=0){
            c[9-p++] = -j%10+'0';
            j/=10;
        }
        c[9-p]='-';
        c= c+9-p;

    }else{
        while(j!=0){
            c[9-p++] = j%10+'0';
            j/=10;
        }
        c= c+9-p+1;
    }




}

void a_to_int(long int *a,char *c){
    int nr = strlen(c);
    for(int i=0;i<nr;i++){
        if(c[i]<'0'||c[i]>'9'){
            //am identificat un caracter si nu o cifra..
            *a=0;
            return;
        }

        *a= (*a)*10+(c[i]-'0');

    }

}


int main() {

//    char *c = new char[20];
//    printf("Start: ");
//    //scanf("%s",c);
//    fgets(c,20,stdin);
//    printf("Ati introdus: %s cu lungimea de %d caractere",c,strlen(c));



    long nr;
    char *c;
    scanf("%ld",&nr);
    int_to_a(nr,c);
    printf("%s",c);
    long *b;
    b = new long;
    a_to_int(b,c);
    printf("\nb = %ld",*b);

    return 0;
}