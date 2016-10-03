#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void vigenere (string p, int * k, int length);
int check (char argv[], int argc, int length);
int * getKey (int length, char argv[]);

int const BEFORELOWERA = 96; //символ в ASCII, который находится перед маленькой а
int const BEFOREUPPERA = 64; //перед большой А

int main (int argc, char* argv[]) {
    
    if (argc != 2) { //проверяем количество аргументов
        printf("YOU SCREWED UP!\n");
        return 1;
    }
    int length = strlen(argv[1]); //узнаем длину ключевого слова
    
    for (int i = 0; i < length; ) { //если в ключевом слове есть что-то кроме букв - ошибка
        if (isalpha(argv[1][i]))
            i++;
        else {
            printf("YOU SCREWED UP!\n");
            return 1;
        }
    }
        
    
    
    int * k = getKey (length, argv[1]);
    
    printf ("plaintext: ");
    string p = GetString();
    printf ("ciphertext: ");
    vigenere(p, k, length);
    free (k); //освобождаем память
    return 0;
}

//Используем метод Vigenere
void vigenere (string p, int * k, int length) {
    for (int i = 0, j = 0; p[i] != '\0'; i++) {
        if ((isalpha(p[i])) && (islower(p[i]))) { //если значение маленькая буква
            int temp = (p[i] + k[j]); 
                while (temp > 'z') 
                    temp = temp - 'z' + BEFORELOWERA;
                printf ("%c", temp);
                j++;
        }
          else if ((isalpha(p[i])) && (isupper(p[i]))) { //если значение большая буква
            int temp = (p[i] + k[j]); 
                while (temp > 'Z') 
                    temp = temp - 'Z' + BEFOREUPPERA;
                printf ("%c", temp);
                j++;
        }
        else //для всех остальных значений как знаки, цифры и т.п.
            printf ("%c", p[i]);
        if (j == length) //переводит ключевое слово на первый элемент
            j = 0;
    }
    printf ("\n");
}



//переводим стринговый массив argv[1] в int, с учетом регистра значения;
int * getKey (int length, char argv[]) {
    int * k = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        if (isupper(argv[i]))
            k[i] = argv[i] - 'A';
        else if (islower(argv[i]))
            k[i] = argv[i] - 'a';
    }
    
    return k;
}