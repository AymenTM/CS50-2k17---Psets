// Program that calculates the minimum number of coins required to give a user change.

#include <cs50.h>
#include <stdio.h>

int main(void)
{

// 1° Declare Variables ------------------------------------------------------- 1

    float changeQ, changeD, changeN, changeP, change;
    int coins, Q, D, N, P;

    coins = 0;
    Q = 0;
    D = 0;
    N = 0;
    P = 0;



// 2° Prompt User & Check Non-Negative ---------------------------------------- 2

    do
    {
        change = get_float("\nChange owed ?\n: ");
    }
    while (change < 0);



// 3° Algorithm --------------------------------------------------------------- 3

    for (changeQ = change; changeQ >= 0.25; changeQ -= 0.25)
    {
        coins++;
        Q++;
    }

    for (changeD = changeQ; changeD >= 0.10; changeD -= 0.10)
    {
        coins++;
        D++;
    }

    for (changeN = changeD; changeN >= 0.05; changeN -= 0.05)
    {
        coins++;
        N++;
    }

    for (changeP = changeN; changeP >= 0.01; changeP -= 0.01)
    {
        coins++;
        P++;
    }



// 4° Print Min. Coins -------------------------------------------------------- 4

    printf("\n\nMinimum Amount of Coin(s): %i\n\nTo be precise: \n\n   %i Quarter(s)\n   %i Dime(s)\n   %i Nickel(s)\n   %i Pennie(s)\n\n", coins, Q, D, N, P);

}
