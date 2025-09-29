#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   

typedef struct
{
    char name_sak[50];
    float height_sak;
    float weight_sak;
    float avg_sak;
} Employee_sak;

int selectionSort_sak(Employee_sak emp_sak[], int n_sak)
{
    int swap_count_sak = 0;
    for (int i_sak = 0; i_sak < n_sak - 1; i_sak++)
    {
        int min_idx_sak = i_sak;
        for (int j_sak = i_sak + 1; j_sak < n_sak; j_sak++)
        {
            if (emp_sak[j_sak].avg_sak < emp_sak[min_idx_sak].avg_sak)
                min_idx_sak = j_sak;
        }
        if (min_idx_sak != i_sak)
        {
            Employee_sak temp_sak = emp_sak[i_sak];
            emp_sak[i_sak] = emp_sak[min_idx_sak];
            emp_sak[min_idx_sak] = temp_sak;
            swap_count_sak++;
        }
    }
    return swap_count_sak;
}

void merge_sak(Employee_sak emp_sak[], int left_sak, int mid_sak, int right_sak)
{
    int n1_sak = mid_sak - left_sak + 1;
    int n2_sak = right_sak - mid_sak;

    Employee_sak *L_sak = (Employee_sak *)malloc(n1_sak * sizeof(Employee_sak));
    Employee_sak *R_sak = (Employee_sak *)malloc(n2_sak * sizeof(Employee_sak));

    for (int i_sak = 0; i_sak < n1_sak; i_sak++)
        L_sak[i_sak] = emp_sak[left_sak + i_sak];
    for (int j_sak = 0; j_sak < n2_sak; j_sak++)
        R_sak[j_sak] = emp_sak[mid_sak + 1 + j_sak];

    int i_sak = 0, j_sak = 0, k_sak = left_sak;
    while (i_sak < n1_sak && j_sak < n2_sak)
    {
        if (L_sak[i_sak].avg_sak <= R_sak[j_sak].avg_sak)
            emp_sak[k_sak++] = L_sak[i_sak++];
        else
            emp_sak[k_sak++] = R_sak[j_sak++];
    }

    while (i_sak < n1_sak)
        emp_sak[k_sak++] = L_sak[i_sak++];
    while (j_sak < n2_sak)
        emp_sak[k_sak++] = R_sak[j_sak++];

    free(L_sak);
    free(R_sak);
}

void mergeSort_sak(Employee_sak emp_sak[], int left_sak, int right_sak)
{
    if (left_sak < right_sak)
    {
        int mid_sak = left_sak + (right_sak - left_sak) / 2;
        mergeSort_sak(emp_sak, left_sak, mid_sak);
        mergeSort_sak(emp_sak, mid_sak + 1, right_sak);
        merge_sak(emp_sak, left_sak, mid_sak, right_sak);
    }
}

int main()
{
    int n_sak;
    printf("Enter number of employees: ");
    scanf("%d", &n_sak);

    Employee_sak *emp_sak = (Employee_sak *)malloc(n_sak * sizeof(Employee_sak));
    if (emp_sak == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    const char *name_list_sak[] = {"Sahil", "Atharva", "Prathmesh", "Swikrut", "Apurv", "Sujal", "Kunal", "Aman", "Rohit", "Amit", "Rahul"};
    int name_count_sak = sizeof(name_list_sak) / sizeof(name_list_sak[0]);

    for (int i_sak = 0; i_sak < n_sak; i_sak++)
    {
        strcpy(emp_sak[i_sak].name_sak, name_list_sak[rand() % name_count_sak]);
        emp_sak[i_sak].height_sak = (float)(150 + rand() % 51);
        emp_sak[i_sak].weight_sak = (float)(50 + rand() % 51);
        emp_sak[i_sak].avg_sak = (emp_sak[i_sak].height_sak + emp_sak[i_sak].weight_sak) / 2;
    }

    printf("\nOriginal Employee Data:\n");
    for (int i_sak = 0; i_sak < n_sak; i_sak++)
        printf("Name: %-10s | Height: %.1f | Weight: %.1f | Avg: %.2f\n",
               emp_sak[i_sak].name_sak, emp_sak[i_sak].height_sak, emp_sak[i_sak].weight_sak, emp_sak[i_sak].avg_sak);

    Employee_sak *emp_sel_sak = (Employee_sak *)malloc(n_sak * sizeof(Employee_sak));
    memcpy(emp_sel_sak, emp_sak, n_sak * sizeof(Employee_sak));

    clock_t start_sel = clock();
    int sel_swaps_sak = selectionSort_sak(emp_sel_sak, n_sak);
    clock_t end_sel = clock();
    double time_sel = (double)(end_sel - start_sel) / CLOCKS_PER_SEC;

    printf("\nFinal List (Selection Sort):\n");
    for (int i_sak = 0; i_sak < n_sak; i_sak++)
        printf("Name: %-10s | Avg: %.2f\n", emp_sel_sak[i_sak].name_sak, emp_sel_sak[i_sak].avg_sak);
    printf("\nTotal swaps in Selection Sort: %d\n", sel_swaps_sak);
    printf("Time taken by Selection Sort: %.6f seconds\n", time_sel);

    Employee_sak *emp_merge_sak = (Employee_sak *)malloc(n_sak * sizeof(Employee_sak));
    memcpy(emp_merge_sak, emp_sak, n_sak * sizeof(Employee_sak));

    clock_t start_merge = clock();
    mergeSort_sak(emp_merge_sak, 0, n_sak - 1);
    clock_t end_merge = clock();
    double time_merge = (double)(end_merge - start_merge) / CLOCKS_PER_SEC;

    printf("\nFinal List (Merge Sort):\n");
    for (int i_sak = 0; i_sak < n_sak; i_sak++)
        printf("Name: %-10s | Avg: %.2f\n", emp_merge_sak[i_sak].name_sak, emp_merge_sak[i_sak].avg_sak);
    printf("Time taken by Merge Sort: %.6f seconds\n", time_merge);

    printf("\nAnalysis:\n");
    printf("Selection Sort -> O(n^2), Time: %.6f sec, Swaps: %d\n", time_sel, sel_swaps_sak);
    printf("Merge Sort -> O(n log n), Time: %.6f sec\n", time_merge);

    free(emp_sak);
    free(emp_sel_sak);
    free(emp_merge_sak);

    return 0;
}
