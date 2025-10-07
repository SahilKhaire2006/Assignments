#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int row_sak;
    int col_sak;
    int val_sak;
}Element_sak;

int main()
{
    int **matrix_sak=NULL;
    int rows_sak,cols_sak;
    int count_sak=0;

    printf("enter rows:");
    scanf("%d",&rows_sak);
    printf("enter cols:");
    scanf("%d",&cols_sak);

    matrix_sak=(int **)malloc(sizeof(int *)*rows_sak);

    if(matrix_sak==NULL)
    {
        printf("memory is not allocated!!!");
        exit(-1);
    }
    for(int i_sak=0;i_sak<rows_sak;i_sak++)
    {
        matrix_sak[i_sak]=(int *)malloc(sizeof(int)*cols_sak);
    }

    printf("enter array elements:-\n");
    for(int i_sak=0;i_sak<rows_sak;i_sak++)
    {
        for(int j_sak=0;j_sak<cols_sak;j_sak++)
        {
            scanf("%d",&matrix_sak[i_sak][j_sak]);
            if(matrix_sak[i_sak][j_sak]!=0)
            {
                count_sak++;
            }
        }
    }

    //--------------matrix print------------------

    printf("\nSimple Matrix:-\n");
    for(int i_sak=0;i_sak<rows_sak;i_sak++)
    {
        for(int j_sak=0;j_sak<cols_sak;j_sak++)
        {
            printf("%d ",matrix_sak[i_sak][j_sak]);
        }
        printf("\n");
    }

    //-----------------sparse matrix-------------------

    Element_sak *sparse_sak=(Element_sak *)malloc(sizeof(Element_sak)*(count_sak+1));

    if(sparse_sak==NULL)
    {
        printf("Memory is not allocated!!!");
        exit(-2);
    }

    sparse_sak[0].row_sak=rows_sak;
    sparse_sak[0].col_sak=cols_sak;
    sparse_sak[0].val_sak=count_sak;

    int k_sak=1;
    for(int i_sak=0;i_sak<rows_sak;i_sak++)
    {
        for(int j_sak=0;j_sak<cols_sak;j_sak++)
        {
            if(matrix_sak[i_sak][j_sak]!=0)
            {
                sparse_sak[k_sak].row_sak=i_sak;
                sparse_sak[k_sak].col_sak=j_sak;
                sparse_sak[k_sak].val_sak=matrix_sak[i_sak][j_sak];
                k_sak++;
            }
        }
    }

    printf("\nSparse Matrix:-\n");
    printf("\n--------------------------");
    printf("\n|Row\t|Col\t|Value\t|\n");
    printf("----------------------------\n");
    for(int i_sak=0;i_sak<=count_sak;i_sak++)
    {
        printf("|%d\t|%d\t|%d\t|\n",sparse_sak[i_sak].row_sak,sparse_sak[i_sak].col_sak,sparse_sak[i_sak].val_sak);
    }

    for(int i_sak=0;i_sak<rows_sak;i_sak++)
    {
        free(matrix_sak[i_sak]);
    }


    Element_sak *f_transpose_sak=(Element_sak *)malloc(sizeof(Element_sak)*(count_sak+1));

    if(f_transpose_sak==NULL)
    {
        printf("Memory is not allocated!!!!");
        exit(-4);
    }

    f_transpose_sak[0].row_sak=sparse_sak[0].col_sak;
    f_transpose_sak[0].col_sak=sparse_sak[0].row_sak;
    f_transpose_sak[0].val_sak=sparse_sak[0].val_sak;

    int *rowterms_sak=(int *)calloc(sparse_sak[0].col_sak,sizeof(int));
    int *startpos_sak=(int *)malloc(sizeof(int)*sparse_sak[0].col_sak);

    for(int i_sak=1;i_sak<=count_sak;i_sak++)
    {
        rowterms_sak[sparse_sak[i_sak].col_sak]++;
    }

    startpos_sak[0]=1;
    for(int i_sak=1;i_sak<sparse_sak[0].col_sak;i_sak++)
    {
        startpos_sak[i_sak]=startpos_sak[i_sak-1]+rowterms_sak[i_sak-1];
    }

    for(int i_sak=1;i_sak<=count_sak;i_sak++)
    {
        int col_sak=sparse_sak[i_sak].col_sak;
        int pos_sak=startpos_sak[col_sak];

        f_transpose_sak[pos_sak].row_sak=sparse_sak[i_sak].col_sak;
        f_transpose_sak[pos_sak].col_sak=sparse_sak[i_sak].row_sak;
        f_transpose_sak[pos_sak].val_sak=sparse_sak[i_sak].val_sak;

        startpos_sak[col_sak]++;
    }

    printf("\nFast Transpose  Matrix:-\n");
    printf("\n--------------------------");
    printf("\n|Row\t|Col\t|Value\t|\n");
    printf("----------------------------\n");
    for(int i_sak=0;i_sak<=count_sak;i_sak++)
    {
        printf("|%d\t|%d\t|%d\t|\n",f_transpose_sak[i_sak].row_sak,f_transpose_sak[i_sak].col_sak,f_transpose_sak[i_sak].val_sak);
    }
    free(matrix_sak);
    free(sparse_sak);
    free(f_transpose_sak);
    return 0;
}
