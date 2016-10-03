#include <stdio.h>
#include <math.h>
#include <cs50.h>

int GetRoundMoney (void);
 
int main(void) {
    int money = GetRoundMoney();
    
    int count = 0;   
    
    while (money > 0) {
        if (money >= 25) {
            money = money - 25;
            count++;
        }
        else if (money >= 10) {
            money = money - 10;
            count++;
        }
        else if (money >= 5) {
            money = money - 5;
            count++;
        }
        else if (money >= 1) {
            money--;
            count++;
        }
        else if (money == 0)
            break;
    }
    printf("%i\n", count);
}

int GetRoundMoney(void) {
    int m;
    float foo;
    printf("O,Hai! ");
    do {
        printf("How much change is owed?\n");
        foo = GetFloat();
        m = (int) round((foo) * 100);
    }
    while (m <= 0);
    return m;
}