#include <stdio.h>

int main () {
    double price, percent;
    int amount;
    scanf("%lf %lf %d", &price, &percent, &amount);
    double discount = (price - price * percent / 100) * amount, free = (amount - amount / 3) * price;
    if (discount <= free) {
        printf("Discount %.lf%%\n", percent);
        printf("%.2lf", discount);
    }
    else {
        printf("Buy 2 Get 1\n");
        printf("%.2lf", free);
    }
}