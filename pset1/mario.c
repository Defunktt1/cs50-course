#include <cs50.h>
#include <stdio.h>

int GetHeight ();

int main (void) {
    int height = GetHeight();
    
    for (int i = 0; i < height; i++) {
        for (int j = 2; j <= height - i; j++)
            printf (" ");
        for (int j = 1; j <= i + 2; j++)
            printf ("#");
        printf ("\n");        
    }
}

int GetHeight (void) {
    int h;
    do {
    printf ("height: ");
    h = GetInt();
    if (h == 0) 
        break;
    }
    while (h <= 0 || h > 23);
    return h;
}