#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool alph (char i);
void makeInitials (char* ct);


int main (void) {
    string name = GetString();
    makeInitials(name);
    return 0;
}

//булевская переменная для вызова её при проверке на правильность ввода
bool alph (char i) {
    if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
        return true;
    else 
        return false;
}

void makeInitials (char* name) {
    bool lookingForWord = true, alph (char c);
    for (int i = 0; name[i] != '\0'; i++) {
        if (alph (name[i])) //если i-тое значение буква 
                if (lookingForWord) { //если true, то значит это начало слова
                    lookingForWord = false;
                    if (name[i] >= 'a' && name[i] <= 'z') //если слово написано с маленькой
                        printf ("%c", name[i]-32);//то переводим и записываем инициал в верхнем регистре
                    else
                        printf ("%c", (name[i]));//иначе сразу пишем в верхнем
                }
        else lookingForWord = true;
    }
    printf ("\n");
}

