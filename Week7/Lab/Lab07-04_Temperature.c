#include <stdio.h>
#include <ctype.h>

double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
void printFahrenheit(double fahrenheit);
void printCelsius(double celsius);

int main() {
    char convert;
    double unit = 0.0;
    scanf("%lf %c", &unit, &convert);
    if (convert == 'f' || convert == 'F') {
        printCelsius(fahrenheitToCelsius(unit));
    } else if (convert == 'c' || convert == 'C') {
        printFahrenheit(celsiusToFahrenheit(unit));
    }
    return 0;

}

double fahrenheitToCelsius(double fahrenheit) {
    double celcius = 0.0;
    celcius = (-32 + fahrenheit) * (100.0/180.0);
    return celcius;
}

double celsiusToFahrenheit(double celsius) {
    double fahrenheit = 0.0;
    fahrenheit = 32 + celsius * (180.0/100.0);
    return fahrenheit;
}

void printFahrenheit(double fahrenheit) {
    printf("%.2f f\n", fahrenheit);

}

void printCelsius(double celsius) {
    printf("%.2f c\n", celsius);

}