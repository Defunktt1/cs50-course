#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

void caesar (string p, int k);

int const BEFORELOWERA = 96; //символ в ASCII, который находится перед маленькой а
int const BEFOREUPPERA = 64; //перед большой А

int main (int argc, char* argv[]) {
    if (argc != 2) { //если не был введен ключ, то получаем error
        printf ("ERROR!!!\n");
        return 1;
    }
    
    int k = atoi(argv[1]); //переводим чаровский массив argv[1] в int
    printf ("plaintext: ");
    string p = GetString();
    printf ("ciphertext: ");
    caesar(p, k);
    return 0;
}

void caesar (string p, int k) {
    for (int i = 0; p[i] != '\0'; i++) {
        if ((isalpha(p[i])) && (islower(p[i]))) { //проходим по маленьким буквам
            int temp = (p[i] + k); 
                while (temp > 'z') //цикл для перехода ключа в начало алфавита до тех пор, пока он не будет больше z в ASCII таблице
                    temp = temp - 'z' + BEFORELOWERA;
                printf ("%c", temp);
        }
        else if ((isalpha(p[i])) && (isupper(p[i]))) { //проходим по большим буквам
            int temp = (p[i] + k); 
                while (temp > 'Z') //тоже самое, но для верхнего регистра
                    temp = temp - 'Z' + BEFOREUPPERA;
                printf ("%c", temp);
        }
        else 
            printf ("%c", p[i]); //выводим все остальные символы
    }
    printf ("\n");
}