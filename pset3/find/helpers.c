/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Бинарный поиск
 */
bool search(int value, int values[], int n)
{
    int lower = 0;
    int upper = n - 1;
    
    while (lower <= upper) {
        int middle = (upper + lower) / 2;
        if (value == values[middle]) {
            return true;
        }
        else if (value < values[middle]) {
            upper = middle - 1;
        }
        else if (value > values[middle]) {
            lower = middle + 1;
        }
    }
    return false;
}

/**
 * Сортировка выбором
 */
void sort(int values[], int n)
{
       for (int i = 0; i < n - 1; i++) {
        int swaps = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (values[j] > values[j + 1]) {
                int temp = values[j + 1];
                values[j + 1] = values[j];
                values[j] = temp; 
                swaps++;
            }
        }
        if (!swaps) 
            break;
    }
    return;
}