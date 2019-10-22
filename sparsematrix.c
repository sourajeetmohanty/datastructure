#include<stdio.h>
#include<stdlib.h>
int mat[10][10];
int r,c;
int cnt;
void Alter_Mat();
void main()
{
    int i,j;
    cnt =0;
    printf("\n Read Matrix:");
    printf("\n No of rows:");
    scanf("%d",&r);
    printf("\n No of columns:");
    scanf("%d",&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==0)
            {
                cnt++;
            }
        }
        printf("\n");
    }
    if(cnt>(r*c)/2)
    {
        printf("\n Sparce matrix.");
        Alter_Mat();
    }
    else
        printf("\n Not a sparce matrix ");
}
void Alter_Mat()
{
    int n=r*c-cnt;
    int alt_mat[n+1][3];
    int i=1;
    int j,k;
    alt_mat[0][0]=r;
    alt_mat[0][1]=c;
    alt_mat[0][2]=n;
    for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                if(mat[j][k]!=0)
                   {
                      alt_mat[i][0]=j;
                      alt_mat[i][1]=k;
                      alt_mat[i][2]=mat[j][k];
                      i++;
                   }
            }
        }

    printf("\n Display Alter_Mat:\n");
    for(j=0;j<=n;j++)
    {
        for(k=0;k<3;k++)
        {
            printf("%d\t",alt_mat[j][k]);
        }
        printf("\n");
    }
}
