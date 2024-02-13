/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** main.c
*/

#include "include/hashtable.h"

char *generate_random_string(int length)
{
    char *randomString = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; ++i) {
        randomString[i] = rand() % 94 + 33;
    }
    randomString[length] = '\0';
    return randomString;
}

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 1);

    printf("%d\n", hash("Hey", 5));
    printf("%d\n", ht_insert(ht, NULL, NULL));
    printf("%d\n", ht_insert(ht, "aartekl=oa", "Hery"));
    printf("%d\n", ht_insert(ht, "b", "Hery"));
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
