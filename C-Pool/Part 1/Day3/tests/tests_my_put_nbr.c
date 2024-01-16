/*
** EPITECH PROJECT, 2023
** test_my_put_nbr.c
** File description:
** Testing the my_put_nbr. file
*/

int main()
{
    my_put_nbr(2147483647);
    my_put_nbr(-2147483648);
    my_put_nbr(-65);
    my_put_nbr(42);
    my_put_nbr(0); 
    return 0;
}
