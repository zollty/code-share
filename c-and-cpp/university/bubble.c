#include "stdio.h"

void Swap(int *left, int *right)
        {
            int temp;

            temp = *left;
            *left = *right;
            *right =temp;
        }

void ImproveBubble2(int *myArray, int Length)
        {
            int m = Length - 1;
            int k, j;

            while( m > 0 )
            {
                for( k=j=0; j<m; j++)
                {
                    if( myArray[j] > myArray[j+1])
                    {
                        Swap(&myArray[j], &myArray[j+1]);
                        k = j; //记录每次交换的位置
                    }
                }
                m = k;        //记录最后一个交换的位置
            }
        }

void print(int s[], int l)
{
	int i;
	for(i=0; i<l; i++)
		printf("%d ", s[i]);
	printf("\n");
}

void main()
{
	int s[8]={6,2,4,7,1,3,8,5};
	print(s,8);
	ImproveBubble2(s, 8);
	print(s,8);
}