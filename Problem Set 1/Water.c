// Program that calculates your water consumption.

#include <cs50.h>
#include <stdio.h>

//Functions

float glass2GPD(float x);
float shwr2GPW(float mpw);
float hands2GPD(float xpd);
float bthrm2GPD(float x1pd);

float d2m1(float b);
float w2m(float gpw);
float d2m(float gpd);



int main(void)
{

// Intro

    printf("\nIn this program we will assess your water consumption.\n\n");



// Q&A

    // Drinking
    float drk = get_float("\nHow many glasses of water do you drink a day ?\n: ");

    // Hygiene
    float shwr = get_float("\n\nHow much time (in minutes) do you spend showering in a week ?\n:");
    float hands = get_float("\n\nHow many times a day do you wash your hands ?\n: ");
    float bthrm = get_float("\n\nHow many times a day do you use the restroom ?\n: ");



// Results

    printf("\n\n\nProcessing Information . . .       Calculating . . .       Done.\n\n\n\nYour water consumption results are in :\n\n");

    // Total Per Day/Week & Month for Each Activity
    printf("Drinking: %.2f Gallons/month\n", d2m1(glass2GPD(drk)));
    printf("Showering: %.2f Gallons/month\n", w2m(shwr2GPW(shwr)));
    printf("Washing Your Hands: %.2f Gallons/month\n", d2m1(hands2GPD(hands)));
    printf("Bathroom: %.2f Gallons/month\n\n", d2m(bthrm2GPD(bthrm)));

    // Total Per Week for All Activities
    printf("Total Per Week: %.2f Gallons\n", glass2GPD(drk)*7 + shwr2GPW(shwr) + hands2GPD(hands)*7 + bthrm2GPD(bthrm)*7);

    // Total Per Month for All Activities
    printf("Total Per Month: %.2f Gallons\n", d2m1(glass2GPD(drk)) + w2m(shwr2GPW(shwr)) + d2m1(hands2GPD(hands)) + d2m(bthrm2GPD(bthrm)));

    // Total Per Year for All Activities
    printf("Total Per Year: %.2f Gallons\n\n", d2m1(glass2GPD(drk))*12 + w2m(shwr2GPW(shwr))*12 + d2m1(hands2GPD(hands))*12 + d2m(bthrm2GPD(bthrm))*12);

}

// Functions


//1- Glass --> Gallon
float glass2GPD(float x)
{
    return x*0.066043;
}

//2- Shower(min/week) --> GallonPerWeek
float shwr2GPW(float mpw)
{
    return mpw*2.1;
}

//3- Washing hands (times/day) --> GallonsPerDay
float hands2GPD(float xpd)
{
    return xpd*0.07;
}

//4- Bathroom (times/day) --> GallonsPerDay
float bthrm2GPD(float x1pd)
{
    return x1pd*5;
}

//5- GallonPerWeek --> GallonsPerMonth
float w2m(float gpw)
{
    return gpw*4.36;
}

//6- GallonPerDay --> GallonsPerMonth
float d2m(float gpd)
{
    return gpd*30.52;
}

//7- GallonPerDay --> GallonsPerMonth (floats)
float d2m1(float b)
{
    return b*30.52;
}
