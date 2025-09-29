#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int roll_sak;
    char name_sak[50];
    float marks_sak;
} Student_sak;

void bubbleSort_sak(Student_sak arr_sak[], int n_sak)
{
    for (int i_sak = 0; i_sak < n_sak - 1; i_sak++)
    {
        printf("\nPass %d:\n", i_sak + 1);
        for (int j_sak = 0; j_sak < n_sak - 1 - i_sak; j_sak++)
        {
            if (arr_sak[j_sak].marks_sak < arr_sak[j_sak + 1].marks_sak)
            {
                Student_sak temp_sak = arr_sak[j_sak];
                arr_sak[j_sak] = arr_sak[j_sak + 1];
                arr_sak[j_sak + 1] = temp_sak;
            }
        }

        for (int k_sak = 0; k_sak < n_sak; k_sak++)
        {
            printf("Name: %-10s | Marks: %.1f\n",
                   arr_sak[k_sak].name_sak, arr_sak[k_sak].marks_sak);
        }
    }

    for (int i_sak = 0; i_sak < n_sak; i_sak++)
    {
        arr_sak[i_sak].roll_sak = i_sak + 1;
    }
}

int main()
{
    int n_sak;
    Student_sak *s1_sak = NULL;

    printf("Enter number of students: ");
    scanf("%d", &n_sak);

    s1_sak = (Student_sak *)malloc(n_sak * sizeof(Student_sak));
    if (s1_sak == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    const char *name_list_sak[] = {"sahil", "apurv", "aryan", "atharva","prathmesh", "swikrut", "sujal", "aditya","krishna", "kunal", "aman", "rohit"};
    int name_count_sak = sizeof(name_list_sak) / sizeof(name_list_sak[0]);

    for (int i_sak = 0; i_sak < n_sak; i_sak++)
    {
        strcpy(s1_sak[i_sak].name_sak, name_list_sak[rand() % name_count_sak]);
        s1_sak[i_sak].marks_sak = (float)(rand() % 101);
    }

    printf("\nOriginal Data:\n");
    for (int i_sak = 0; i_sak < n_sak; i_sak++)
    {
        printf("Name: %-10s | Marks: %.1f\n",s1_sak[i_sak].name_sak, s1_sak[i_sak].marks_sak);
    }

    bubbleSort_sak(s1_sak, n_sak);

    printf("\nFinal Sorted List with Roll Numbers:\n");
    for (int i_sak = 0; i_sak < n_sak; i_sak++)
    {
        printf("Roll No: %d | Name: %-10s | Marks: %.1f\n",s1_sak[i_sak].roll_sak, s1_sak[i_sak].name_sak, s1_sak[i_sak].marks_sak);
    }

    free(s1_sak);
    return 0;
}
