/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

void readSales(double sales[], const char *filename){
    FILE *file= fopen(filename, "r");
    if (file == NULL){
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < MONTHS; i++){
        if (fscanf(file, "%lf", &sales[i]) !=1){
            printf("Error reading sales data.\n");
            exit(1);
        }
    }
    fclose(file);
}

void generateSalesReport(double sales[], const char *months[]){
    printf("Monthly sales report for 2022: \n");
    printf("Month\tSales\n");
    for (int i=0; i< MONTHS; i++){
        printf("%-10s\t%.2lf\n", months[i], sales[i]);
    }
    printf("\n");
}

void generateSalesSummary(double sales[], const char *months[]){
    double min = sales[0];
    double max = sales[0];
    double total = sales[0];
    for (int i=1; i<MONTHS; i++){
        if (sales[i] < min){
            min = sales[i];
        }
        if (sales[i]>max){
            max = sales[i];
        }
        total += sales[i];
    }
    double average = total/ MONTHS;
    printf("Sales summary: \n");
    printf("Minimum sales: $%.2lf\n", min);
    printf("Maximum Sales: $%.2lf\n", max);
    printf("Average sales: $%.2lf\n\n", average);
}

void generateMovingAverages(double sales[], const char *months[]){
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++) {
        double sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j];
        }
        double average = sum / 6;
        printf("%s - %s $%.2lf\n", months[i], months[i + 5], average);
    }
    printf("\n");
}

void sortSales(double sales[], const char *months[]) {
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sales[i] < sales[j]) {
                double temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
                const char *tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }
}

void generateDescendingSalesReport(double sales[], const char *months[]) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t%.2lf\n", months[i], sales[i]);
    }
}

int main(){
    const char *months[MONTHS]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double sales[MONTHS];
    readSales(sales, "sales.txt");
    generateSalesReport(sales, months);
    generateSalesSummary(sales,months);
    generateMovingAverages(sales, months);
    sortSales(sales, months);
    generateDescendingSalesReport(sales, months);
    return 0;
}
