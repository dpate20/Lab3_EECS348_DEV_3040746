/*
 * Author: Dev Patel
 * ID: 3040746
 * Date: 02/17/2022
 * Program Description: This will take in a sales report file and present it in the desired format
 *
 */

#include <stdio.h>
#define months 12
#define move_period6

void sales_re(double sales[]);
double min_val(double sales[]);
double max_val(double sales[]);
double avg_val(double sales[]);
void sales_rep_print(double sales[]);
void sales_summary_rep(double sales[]);
void moving_avg_rep(double sales[]);
void sort_sales_rep(double sales[]);

int main()
{
    double sales[months];

    sales_re(sales);

    sales_rep_print(sales);

    sales_summary_rep(sales);

    moving_avg_rep(sales);

    sort_sales_rep(sales);

    return 0;
}

void sales_re(double sales[])
{
    FILE *f;
    int i = 0;

    f = fopen("sales.txt", "r");
    if (f == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(f, "%lf", &sales[i]) == 1) {
        i++;
    }

    fclose(f);
}

double max_val(double sales[])
{
    double max = sales[0];
    int i;

    for (i = 1; i < months; i++) {
        if (sales[i] > max) {
            max = sales[i];
        }
    }

    return max;
}

double min_val(double sales[])
{
    double min = sales[0];
    int i;

    for (i = 1; i < months; i++) {
        if (sales[i] < min) {
            min = sales[i];
        }
    }

    return min;
}

double avg_val(double sales[])
{
    double sum = 0;
    int i;

    for (i = 0; i < months; i++) {
        sum += sales[i];
    }

    return sum / months;
}

void sales_rep_print(double sales[])
{
    int i;

    printf("Monthly sales report for 2022:\n\n");
    printf("Month\t\tSales\n");

    for (i = 0; i < months; i++) {
        printf("%d\t", i+1);
        printf("$%.2f\n", sales[i]);
    }

    printf("\n");
}

void sales_summary_rep(double sales[])
{
    double min, max, avg;

    min = min_val(sales);
    max = max_val(sales);
    avg = avg_val(sales);

    printf("Sales summary:\n\n");
    printf("Minimum sales: $%.2f (%d)\n", min, sale_month(sales, min)+1);
    printf("Maximum sales: $%.2f (%d)\n", max, sale_month(sales, max)+1);
    printf("Average sales: $%.2f\n\n", avg);
}

void moving_avg_rep(double sales[])
{
    int i, j;
    double sum;

    printf("Six-Month Moving Average Report:\n\n");
    printf("Month\t\tSix-Month Moving Average\n");

    for (i = moving_per_avg-1; i < months; i++) {
        sum = 0;

        for (j = i; j > i- moving_per_avg; j--) {
            sum += sales[j];
