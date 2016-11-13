#include <cs50.h>
#include <stdio.h>

void water (int munites);

int main (void) {
    int minutes;
    do {
        printf ("minutes: ");
        minutes = GetInt();
    }
    while (minutes <= 0);
    
    water (minutes);
}

void water (int minutes) {
    int bottles = minutes * (12);
    printf ("bottles: %i\n", bottles);
}