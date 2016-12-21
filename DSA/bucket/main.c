#include <stdio.h>
#include<time.h>
/* Function for bucket sort */
void Bucket_Sort(int array[], int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        (count[array[i]])++;

    for (i = 0, j = 0; i < n; i++)
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}
/* End of Bucket_Sort() */

/* The main() begins */
int main()
{
    int array[100000], i;
    int num=malloc(sizeof(num));
    time_t start,end;
    double tc;
    printf("Enter the size of array : ");
    scanf("%d", &num);
    for(i=num;i>0;i--)
        {
            array[i]=i+1;
        }
    /*printf("Enter the %d elements to be sorted:\n",num);
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]);
    printf("\nThe array of elements before sorting : \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);
    printf("\nThe array of elements after sorting : \n");*/
    start=clock();
    Bucket_Sort(array, num);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency is %lf\n",tc);
    for (i = 0; i < 20; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
