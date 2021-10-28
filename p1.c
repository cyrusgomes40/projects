#include <stdio.h>

int main (){
const int iCups = 2000;
const int iCandy_bars = 1000;
const int iBags_of_Pop = 2500;
const int iBottled_water = 750;

int Cups;
int Candy_bars;
int Bags_of_Pop;
int Bottled_water;

printf("Enter the number of cups, candy, popcorn, and water remaining: \n");
scanf ("%d %d %d %d", &Cups, &Candy_bars, &Bags_of_Pop, &Bottled_water);

int NCups =iCups - Cups;
int NCandy_bars = iCandy_bars - Candy_bars;
int NBags_of_Pop = iBags_of_Pop - Bags_of_Pop;
int NBottled_water = iBottled_water - Bottled_water;

printf("Need: %d cups, %d candy bars, %d bags of popcorn, and %d bottles of water\n", NCups, NCandy_bars, NBags_of_Pop, NBottled_water);

double Cost_Cups = 0.05 * NCups;
double Cost_Candy_bars = 0.3 * NCandy_bars;
double Cost_Bags_of_Pop = 0.2 * NBags_of_Pop;
double Cost_Bottled_water = 0.5 * NBottled_water;
double Total_cost = Cost_Cups + Cost_Candy_bars + Cost_Bags_of_Pop + Cost_Bottled_water;
int Total_dollars = (int)(Total_cost);
int Total_cents = ((int)((Total_cost+.001)*100)) % 100;


printf("Cost: %d dollars and %d cents\n", Total_dollars, Total_cents);

double avg_Cups = NCups/7.0;
double avg_Candy_bars = NCandy_bars/7.0;
double avg_Bags_of_Pop = NBags_of_Pop/7.0;
double avg_Bottled_water = NBottled_water/7.0;

printf("Average sold: %.2lf cups, %.2lf candy bars, %.2lf bags of popcorn, and %.2lf bottles of water per day\n", avg_Cups, avg_Candy_bars, avg_Bags_of_Pop, avg_Bottled_water);

return 0;
}