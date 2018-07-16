#include <stdio.h>

main(){
    float fahr,celcius;
    int lower,upper,step;

    lower = 0;
    upper= 300;
    step = 20;

    fahr = lower;
    
    /*Fahrenheit to celcius converter*/
    printf("FAHRENHEIT CELCIUS\n");
    while (fahr<=upper){
        celcius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f         %6.1f\n",fahr,celcius);
        fahr = fahr + step;
    }
    printf("\n");
    
    /*Celcius to fahrenheit converter*/
    celcius = lower;
    printf("CELCIUS FAHRENHEIT\n");
    while (celcius<=upper){
        fahr = celcius*(9.0/5.0)+32.0;
        printf("%3.0f         %6.1f\n",celcius,fahr);
        celcius = celcius + step;
    }
}