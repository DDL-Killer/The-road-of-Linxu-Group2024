#include<stdio.h>
#define Yangji 2.05
#define Tiancai 1.15
#define Carrot 1.09

void addPound(int *p) {
    int huancun;
    printf("Please input pound:");
    if (scanf("%d", &huancun) != 1 || huancun < 0) {
        printf("Invalid input, please input a positive number.\n");
        while (getchar() != '\n'); // 清空输入缓冲区
        return;
    }
    *p += huancun;
}

int main() {
    int pY = 0, pT = 0, pC = 0, sump = 0, panduan = 1;
    char type;
    double allcost, sumf, Yf, yunfee, Tf, Cf, youhui = 0.95;

    printf("Yangji: 2.05p/$     Tiancai: 1.15p/$     Carrot: 1.09p/$\n");
    printf("Choose your type:\na = Yangji\nb = Tiancai\nc = Carrot\nq = quit\n");

    while (panduan) {
        scanf(" %c", &type);  // 空格跳过空白字符
        switch (type) {
        case 'a':
            addPound(&pY);
            break;
        case 'b':
            addPound(&pT);
            break;
        case 'c':
            addPound(&pC);
            break;
        case 'q':
            panduan = 0;
            break;
        default:
            printf("Please input right type\n");
            break;
        }
    }

    sump = pC + pT + pY;
    Cf = (double)pC * Carrot;
    Tf = (double)pT * Tiancai;
    Yf = (double)pY * Yangji;
    sumf = Tf + Cf + Yf;

    if (sumf > 100) {
        sumf *= youhui;
    }

    if (sump <= 5) {
        yunfee = 6.5;
    } else if (sump <= 20) {
        yunfee = 14;
    } else {
        yunfee = 14 + (sump - 20) * 0.5;
    }

    allcost = sumf + yunfee;

    printf("Yangji: 2.05p/$     Tiancai: 1.15p/$     Carrot: 1.09p/$\n");
    printf("You have bought %d pound Yangji, cost %.2lf\n", pY, Yf);
    printf("You have bought %d pound Tiancai, cost %.2lf\n", pT, Tf);
    printf("You have bought %d pound Carrot, cost %.2lf\n", pC, Cf);
    printf("Total pounds of vegetable: %d, total cost: %.2lf\n", sump, sumf);
    printf("Shipping cost: %.2lf, total amount to pay: %.2lf\n", yunfee, allcost);
}
