#include <stdio.h>
#include <stdbool.h>

#define PAYRATE 12
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main()
{
    //ask for the amount worked, initialize variables
    int amountWorked;
    double grossPay = 0;
    double taxes = 0;
    double netPay = 0;
    printf("The payrate is %i$ an hour, how many hours have you worked? \n", (int)PAYRATE);
    scanf("%i", &amountWorked);

    //calculate overtime, excess of 40 hours
    if (amountWorked > OVERTIME)
    {
        grossPay += (amountWorked - OVERTIME) * PAYRATE * 1.5;
        amountWorked = 40;
    }

    //calculate basic work time
    grossPay += amountWorked * PAYRATE;
    double computeGrossPay = grossPay;

    //calculating taxes and net pay
    if (computeGrossPay > 450.0)
    {
        taxes += (computeGrossPay - 450) * TAXRATE_REST;
        computeGrossPay = 450.0;
    }

    if (computeGrossPay > 300.0)
    {
        taxes += (computeGrossPay - 300) * TAXRATE_150;
        computeGrossPay = 300.0;
    }

    taxes += computeGrossPay * TAXRATE_300;

    netPay = grossPay - taxes;

    //displaying output
    printf("Your gross pay is %.2f \n", grossPay);
    printf("Your amount of taxes are %.2f \n", taxes);
    printf("Your net pay is %.2f \n\n", netPay);

    printf("Press enter to continue...\n");

    return 0;
}