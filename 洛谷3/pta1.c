#include<stdio.h>
int main(){
    int day;
double factor, initial;

scanf("%lf %lf %d", &initial, &factor, &day);
printf("%.1f#%.3f#%d", initial, factor, day);
}