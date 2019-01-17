



//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
__inline
static void swap(int* v1, int* v2) {
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}


void InsertSort(int *a, int r)//注意r=n-1
{
	int i, j;
	int temp;
	for(i=1; i<=r; i++)
	{
		temp=a[i];
		j=i-1;
		while( a[j]>temp )
		{
			a[j+1]=a[j];
			if( j != 0 )//检查越界
			{
				j--;
			}
			else
			{//理论上j--后j=-1，但是不能再执行while(a[j]>temp)，所以break
				j=-1;
				break;
			}
		}
		a[j+1]=temp;
	}
}



static int Partition(int *a, int h, int r)//注意r=n-1
{
	int key;
	int i;
	int j;
	i=h;
	j=r;
	key=a[h];//用区间的第1个记录作为基准


	//cout<<i<<endl;

	while( i < j )//每执行一次while左右指针各移动一轮
	{
		while( a[j]>=key && i<j )//指针j从右往左移动
		{
			j--;
		}
		if( i<j )	// 虽然外循环也有 i < j，但是前面j--可能使得i=j，这样就不能再执行a[i++]了. 
			         
		{
			a[i]=a[j];
			i++;
		}

		while( a[i]<=key && i<j )//指针i从左往右移动
		{
			i++;
		}
		if( i<j )
		{
			a[j]=a[i];
			j--;
		}
	}	//左右指针各移动一轮后，又重新开始下一轮移动

	a[i]=key;

	return i;
}

static int quickSortRecurse (int * numbers, int left, int right)
{
	int pivot;
	pivot = numbers[left];

    goto QStart;
    while (1)
	{
        do{
            right--;
            if (left >= right) goto QEnd;
            QStart:;
        }while (numbers[right] > pivot);
        
		numbers[left] = numbers[right];

        do{ 
            left++;
            if (left >= right)
			{
                left = right;
                goto QEnd;
            }
        }while (numbers[ left] < pivot);
        
		numbers[right] = numbers[left];
    }
    QEnd:;
    numbers[left] = pivot;

	return left;
}


static int medianOf3 (int * numbers, int i, int j) {
int tmp;

    if (numbers[0] <= numbers[i]) {
        if (numbers[j] <= numbers[0]) return numbers[0]; /* j 0 i */
        if (numbers[i] <= numbers[j]) j = i;             /* 0 i j */
                                                         /* 0 j i */
    } else {
        if (numbers[0] <= numbers[j]) return numbers[0]; /* i 0 j */
        if (numbers[j] <= numbers[i]) j = i;             /* j i 0 */
                                                         /* i j 0 */
    }
    tmp = numbers[j];
    numbers[j] = numbers[0];
    numbers[0] = tmp;
    return tmp;
}

///////////////////////////////////////////////////////////////////
void Zollty(int *a, int h, int r)//注意r=n-1
{
	int k;
	int key;
	int j;
	int p;
	int newl,newr;
	int i;
	int t;

	if(r-h<16) //用insertsort
		//insertsort(a, h, r);
		return;

	/////////////////-START-//////////////////
	//将与key相等的提到前面去
	k=j=h;
	//key三者取中
	key=medianOf3 (a + h, (r-h) >> 1, r-h);

	while( ++j<=r )
	{
		if( a[j]==key )
		{
			swap(&a[j],&a[++k]);  //k代表最后一个key的位置，随后的任务是对k到r的序列进行partition（以a[k]为key）
		}
	}
	/////////////////-END-///////////////////

	///////划分k到r的序列///////////
	p=quickSortRecurse(a, k, r); 
	//p=Partition(a, k, r);

	//////////////////-START-//////////////////
	//将与key相等的提到中间去
	i=h;
	j=p-k;
	t=k-h;
	if( j<=t ){

		while( p>k )
		{
			swap(&a[i++],&a[k++]);
		}
		newl=i-1;
		newr=p+1;

	}else{

		j=p;
		while( k>i )
		{
			swap(&a[i++],&a[--j]);
		}
		newl=j-1;
		newr=p+1;
	}
	//////////////////-END-//////////////////

	Zollty(a,h,newl);
	Zollty(a,newr,r);
}
///////////////////////////////////////////////////////////////////


void sort(int a[], int right) {
	int left;
	left=0;
	Zollty(a, left, right);
	InsertSort(a, right);
}


/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////--TEST--////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

__inline
static void sort2 (int * numbers) {
int tmp;

    if (numbers[0] <= numbers[1]) return;
    tmp = numbers[0];
    numbers[0] = numbers[1];
    numbers[1] = tmp;
}

__inline
static void sort3 (int * numbers) {
int tmp;

    if (numbers[0] <= numbers[1]) {
        if (numbers[1] <= numbers[2]) return;
        if (numbers[2] <= numbers[0]) {
            tmp = numbers[0];
            numbers[0] = numbers[2];
            numbers[2] = numbers[1];
            numbers[1] = tmp;
            return;
        }
        tmp = numbers[1];
    } else {
        tmp = numbers[0];
        if (numbers[0] <= numbers[2]) {
            numbers[0] = numbers[1];
            numbers[1] = tmp;
            return;
        }
        if (numbers[2] <= numbers[1]) {
            numbers[0] = numbers[2];
            numbers[2] = tmp;
            return;
        }
        numbers[0] = numbers[1];
    }
    numbers[1] = numbers[2];
    numbers[2] = tmp;
}

__inline
static void sort4 (int * num) {
int tmp;
  if (num[0] < num[1]) {
    if (num[1] < num[2]) {
      if (num[1] < num[3]) {
        if (num[2] >= num[3]) {
          tmp = num[2];
          num[2] = num[3];
          num[3] = tmp;
        }
      } else {
        tmp = num[1];
        if (num[0] < num[3]) {
          num[1] = num[3];
        } else {
          num[1] = num[0];
          num[0] = num[3];
        }
        num[3] = num[2];
        num[2] = tmp;
      }
    } else {
      if (num[0] < num[2]) {
        if (num[2] < num[3]) {
          if (num[1] < num[3]) {
            tmp = num[1];
          } else {
            tmp = num[3];
            num[3] = num[1];
          }
          num[1] = num[2];
          num[2] = tmp;
        } else {
          if (num[0] < num[3]) {
            tmp = num[3];
          } else {
            tmp = num[0];
            num[0] = num[3];
          }
          num[3] = num[1];
          num[1] = tmp;
        }
      } else {
        if (num[0] < num[3]) {
          tmp = num[0];
          num[0] = num[2];
          if (num[1] < num[3]) {
            num[2] = num[1];
          } else {
            num[2] = num[3];
            num[3] = num[1];
          }
          num[1] = tmp;
        } else {
          if (num[2] < num[3]) {
            tmp = num[0];
            num[0] = num[2];
            num[2] = tmp;
            tmp = num[1];
            num[1] = num[3];
          } else {
            tmp = num[1];
            num[1] = num[2];
            num[2] = num[0];
            num[0] = num[3];
          }
          num[3] = tmp;
        }
      }
    }
  } else {
    tmp = num[0];
    if (tmp < num[2]) {
      if (tmp < num[3]) {
        num[0] = num[1];
        num[1] = tmp;
        if (num[2] >= num[3]) {
          tmp = num[2];
          num[2] = num[3];
          num[3] = tmp;
        }
      } else {
        if (num[1] < num[3]) {
          num[0] = num[1];
          num[1] = num[3];
        } else {
          num[0] = num[3];
        }
        num[3] = num[2];
        num[2] = tmp;
      }
    } else {
      if (num[1] < num[2]) {
        if (num[2] < num[3]) {
          num[0] = num[1];
          num[1] = num[2];
          if (tmp < num[3]) {
            num[2] = tmp;
          } else {
            num[2] = num[3];
            num[3] = tmp;
          }
        } else {
          if (num[1] < num[3]) {
            num[0] = num[1];
            num[1] = num[3];
          } else {
            num[0] = num[3];
          }
          num[3] = tmp;
        }
      } else {
        if (num[1] < num[3]) {
          num[0] = num[2];
          if (tmp < num[3]) {
            num[2] = tmp;
          } else {
            num[2] = num[3];
            num[3] = tmp;
          }
        } else {
          if (num[2] < num[3]) {
            num[0] = num[2];
            num[2] = num[1];
            num[1] = num[3];
            num[3] = tmp;
          } else {
            num[0] = num[3];
            num[3] = tmp;
            tmp = num[1];
            num[1] = num[2];
            num[2] = tmp;
          }
        }
      }
    }
  }
}

/*
 *  Heap Sort
 */

/* Assure the heap property for entries from top to last */
static void siftDown (int numbers[], int top, int last) {
int tmp = numbers[top];
int maxIdx = top;

    while (last >= (maxIdx += maxIdx)) {

        /* This is where the comparison occurrs and where a sufficiently
           good compiler can use a computed conditional result rather
           than using control logic. */
        if (maxIdx != last && numbers[maxIdx] < numbers[maxIdx + 1]) maxIdx++;

        if (tmp >= numbers[maxIdx]) break;
        numbers[top] = numbers[maxIdx];
        top = maxIdx;
    }
    numbers[top] = tmp;
}

/* Peel off the top siftDown operation since its parameters are trivial to
   fill in directly (and this saves us some moves.) */
static void siftDown0 (int numbers[], int last) {
int tmp;

    if (numbers[0] < numbers[1]) {
        tmp = numbers[1];
        numbers[1] = numbers[0];
        siftDown (numbers, 1, last);
    } else {
        tmp = numbers[0];
    }
    numbers[0] = numbers[last];
    numbers[last] = tmp;
}

void heapSort (int numbers[], int qty) {
int i;

    if (qty <= 4) {
        if (qty == 4) sort4 (numbers);
        else if (qty == 3) sort3 (numbers);
        else if (qty == 2) sort2 (numbers);
        return;
    }

    i = qty / 2;
    /* Enforce the heap property for each position in the tree */
    for (  qty--; i >  0; i--) siftDown  (numbers, i, qty);
    for (i = qty; i >= 4; i--) siftDown0 (numbers, i);
    sort4 (numbers);
}

#include <stdio.h>
#include <time.h>

#define NUM_ITEMS 6000
int numbers[NUM_ITEMS];

/* #define CORRECTNESS 1 */

int test (int seed, void (* sortfn)(int numbers[], int qty)) {
#ifdef CORRECTNESS
    int t0, t1, t2, t3, t4, t5, t6, t7;
#endif
    int i, c, n;

    srand (seed);

    for (c=0; c < 10000; c++) {
#ifdef CORRECTNESS
        t0 = t1 = t2 = t3 = t4 = t5 = t6 = t7 = 0;
#endif

        n = 16 + (rand () % (NUM_ITEMS - 16));

        /* fill array with random integers */
        for (i = 0; i < n; i++) {
            /* if (0 != (i & 15)) numbers[i] = (i + 1) % n;
            else */
			//if(i%7!=0) numbers[i]=100000; else
            numbers[i] = rand ();
#ifdef CORRECTNESS
            t0 += numbers[i];
            t1 ^= numbers[i];
            t2 += numbers[i] * numbers[i];
            t3 ^= numbers[i] * numbers[i];
#endif
        }

        /* perform heap sort on array */
        sortfn (numbers, n);

#ifdef CORRECTNESS
        for (i = 0; i < n; i++) {
            if (i > 0 && numbers[i] < numbers[i-1]) {
                printf ("Error!  Not properly sorted! n = %d (%d > %d)\n", n, numbers[i-1], numbers[i]);
                return -1;
            }
            t4 += numbers[i];
            t5 ^= numbers[i];
            t6 += numbers[i] * numbers[i];
            t7 ^= numbers[i] * numbers[i];
        }

        if (t0 != t4 || t1 != t5 || t2 != t6 || t3 != t7) {
            printf ("The numbers are corrupted!\n");
            return -1;
        }
#endif
    }
    return 0;
}


#include <limits.h>

/* Return with the minimum time for 5 runs */
double timetest (int seed, void (* sortfn)(int numbers[], int qty)) {
clock_t t0, t1;
long d = LONG_MAX;
int i;

    /* Wait for clock() roll over before starting */
    t0 = clock ();
    while (t0 == (t1 = clock ())) ;

    for (i=0; i < 4; i++) {
        t0 = t1;
        test (seed, sortfn);
        t1 = clock ();
        if (t1 - t0 < d) d = t1 - t0;
    }

    return d * (1.0 / CLOCKS_PER_SEC);
}


#define DATASIZE 250000

//定义sleep函数
void sleep( clock_t wait )
{
  clock_t goal;
  goal = wait + clock();//clock获取当前时间
  while( goal > clock() )//clock自动变化，会增加到比goal还大
  ;
}


int main () {
	const char * file_name = "out.dat";
	FILE * fp;//这个FILE类型的定义必须放在其他变量定义的前面

	clock_t start, finish;//定义clock_t类型的变量
	double duration;
	
int a[13]={77,90,60,50,80,44,66,55,20,49,49,10,44};//此算法可以对仅有一、两个元素的数组排序

	int array[DATASIZE];
	int array_size = DATASIZE;
	int i;

int seed = 0; /* time (NULL) ^ getpid (); */
double r0, r1;

/////////////////////////////////////////////////
//Test 1
	fp = fopen(file_name, "rb");
	fread(&array, sizeof(int), DATASIZE, fp);

	//sleep的用法
	printf( "Delay for three seconds\n" );
	sleep( (clock_t)3 * CLOCKS_PER_SEC );
	printf("Done!\n");

	//计算程序的运行时间
	start = clock();//计时开始

	sort(array, array_size-1);

	finish = clock();//计时结束
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "This quickSort algorithm run %f seconds\n", duration );

	printf( "After sorting: " );
	for(i = 1; i < DATASIZE; i*=2 )
	{
		printf( "%d ", array[i] );
	}
	printf( "\n" );
////////////////////////////////////////////////
//Test 2
	sort(a, 12);
	printf( "After sorting: " );
	for(i = 0; i < 13; i++ )
	{
		printf( "%d ", a[i] );
	}
	printf( "\n" );

/////////////////////////////////////////////////
//Test 3
    /* Warm up the cache */
    {
        for (i = 0; i < NUM_ITEMS; i++) numbers[i] = i;
        heapSort (numbers, NUM_ITEMS);
    }

    r1 = timetest (seed, sort);
    r0 = timetest (seed, heapSort);

    printf ("  heapsort: %.3f\n", r0);
    printf (" quicksort: %.3f\n", r1);

    return 0;
}













