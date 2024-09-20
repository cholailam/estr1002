#include <stdio.h>
#include <stdlib.h>

int main(){
    
    float red, green, blue, min, hue, sat, value;

    scanf("%f %f %f", &red, &green, &blue);
    

    // Normalise the RGB value
    red = red / 255;
    green = green / 255;
    blue = blue / 255;



    // Determine max (value) and min
    if ( (red >= green) && (red >= blue) ){
        
        value = red;
        if (green >= blue)
            min = blue;
        else min = green;     

    } else if ( (green >= red) && (green >= blue) ){
        
        value = green;
        if (red >= blue)
            min = blue;
        else min = red;     

    } else {

        value = blue;
        if (green >= red)
            min = red;
        else min = green;

    }


    // calculate saturation
    if (value <= 1e-6)
        sat = 0;
    else sat = (value - min)/ value;


    // calculate hue
    if (sat <= 1e-6)
        hue = 0;
    else{

        if ( abs(value - red) <= 1e-6 )
            hue = (green - blue) / (value - min);
        else if ( abs(value - green) <= 1e-6 )
            hue = (blue - red) / (value - min) + 2;
        else
            hue = (red - green) / (value - min) + 4;

    }


    hue = hue * 60;
    if (hue < 0)
        hue += 360;
    hue = hue / 360;

    printf("%.3f\n", hue);
    printf("%.3f\n", sat);
    printf("%.3f\n", value);


    return 0;
}
