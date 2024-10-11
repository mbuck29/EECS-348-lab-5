#include <stdio.h>
#include <string.h>

void monthly_report(float *monthly_sales, char months[][10]){
    printf("Monthly Sales Report for 2024\n");
    printf("\n");
    printf("Month      Sales\n");
    for(int i = 0; i < 12; i++){
        printf("%-10s %.2f \n", months[i], monthly_sales[i]);
    }
    
}
void sales_summary(float *monthly_sales, char months[][10]){
    printf("\n");
    printf("Sales summary report: \n");
    printf("\n");
    float min_val = monthly_sales[0];
    char min_month[10];
    strcpy(min_month, months[0]);
    float max_val = monthly_sales[0];
    char max_month[10];
    strcpy(max_month, months[0]);
    float year_avg;
    float sum = 0;
    
    for(int i = 0; i < 12; i++){
        if(monthly_sales[i] < min_val){
            min_val = monthly_sales[i];
            strcpy(min_month, months[i]);
            printf("hello");
        }
        if(monthly_sales[i] > max_val){
            max_val = monthly_sales[i];
            strcpy(max_month, months[i]);
        }
        sum += monthly_sales[i];
    }
    year_avg = sum / 12;
    
    printf("Minimum sales:  %7.2f  (%s)\n", min_val, min_month);
    printf("Maximum sales:  %7.2f  (%s)\n", max_val, max_month);
    printf("Average sales:  %7.2f\n", year_avg);
}

void six_month_avg(float *monthly_sales, char months[][10]){
    printf("\n");
    printf("Six-Month moving average report: \n");
    printf("\n");
    
    for(int i = 0; i < 6; i++){
        float total = 0;
        for (int j = 0; j < 6; j ++){
            total += monthly_sales[i+j];
        }
        
        int indent = 22 - (strlen(months[i+5]) + strlen(months[i] + 1));
        printf("%s-%s %*.2f\n", months[i], months[i+5], indent, (total/6));
    }
}

void report_high_to_low(float *monthly_sales, char months[][10]){
    printf("\n");
    printf("Sales report (highest to lowest): \n");
    printf("\n");
    
    float temp_sales[12];
    for(int i = 0; i < 12; i++){
        temp_sales[i] = monthly_sales[i];
    }
    float sorted_sales[12];
    char sorted_months[12][10];
    float current_max;
    int current_max_index;
    
    for(int i = 0; i < 12; i++){
        current_max = 0;
        current_max_index = 0;
        for(int j = 0; j < 12; j++){
            if(temp_sales[j] > current_max){
                current_max = temp_sales[j];
                current_max_index = j;
            }
        }
        sorted_sales[i] = current_max;
        strcpy(sorted_months[i], months[current_max_index]);
        temp_sales[current_max_index] = 0;
    }
    printf("Month      Sales\n");
    for(int i = 0; i < 12; i++){
        printf("%-10s $%.2f \n", sorted_months[i], sorted_sales[i]);
    }
    
}

int main(){
    
    char months[12][10] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    float monthly_sales[12]; 
    float value;
    FILE *file_ptr;
    file_ptr = fopen("input.txt", "r");
    
    int i = 0;
    while(fscanf(file_ptr, "%f", &value) == 1){
        monthly_sales[i] = value;
        i++;
    } 
    fclose(file_ptr);
    
    monthly_report(monthly_sales, months);
    sales_summary(monthly_sales, months);
    six_month_avg(monthly_sales, months);
    report_high_to_low(monthly_sales, months);
    return 0;
}