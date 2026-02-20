#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char cartao[12];
    int verificador1, verificador2, ii;

    srand(1); // Semente fixa para correção automática

    int auxbanco = rand()%3;

    if(auxbanco == 0) {
        cartao[0]='5'; cartao[1]='1'; cartao[2]='4'; cartao[3]='7';
    } else if(auxbanco == 1) {
        cartao[0]='8'; cartao[1]='9'; cartao[2]='1'; cartao[3]='4';
    } else {
        cartao[0]='6'; cartao[1]='8'; cartao[2]='6'; cartao[3]='5';
    }

    for(ii=4; ii<=11; ii++)
        cartao[ii] = (rand()%10) + 48;

    // === cálculo do verificador1 ===
    verificador1=0;
    for(ii=0;ii<=3;ii++)
        verificador1 += (5-ii)*(cartao[ii]-48);

    for(ii=4;ii<=11;ii++)
        verificador1 += (13-ii)*(cartao[ii]-48);

    verificador1 %= 11;
    if(verificador1<2) verificador1=0;
    else verificador1=11-verificador1;

    // === cálculo do verificador2 ===
    verificador2=0;
    for(ii=0;ii<=4;ii++)
        verificador2 += (6-ii)*(cartao[ii]-48);

    for(ii=5;ii<=11;ii++)
        verificador2 += (14-ii)*(cartao[ii]-48);

    verificador2 += 2*verificador1;
    verificador2 %= 11;

    if(verificador2<2) verificador2=0;
    else verificador2=11-verificador2;

    printf("%c%c%c%c-%c%c%c%c-%c%c%c%c-%d%d\n",
           cartao[0],cartao[1],cartao[2],cartao[3],
           cartao[4],cartao[5],cartao[6],cartao[7],
           cartao[8],cartao[9],cartao[10],cartao[11],
           verificador1, verificador2);

    return 0;
}
