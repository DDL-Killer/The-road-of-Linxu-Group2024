#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator); 
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Warning！\n");
            }
            break;
        case '%':
            if ((int)num2 != 0) {
                result = (int)num1 % (int)num2;
                printf("Result: %.0lf\n", result);
            } else {
                printf("Wrong！\n");
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}