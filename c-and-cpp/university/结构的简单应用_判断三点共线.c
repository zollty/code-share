/*结构的简单应用_判断三点共线
   Author：Tianyong-Tsow（邹天涌）
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//定义一个空间坐标
typedef struct Point
{
	double x_coordinate;	// X坐标
	double y_coordinate;
	double z_coordinate;
}Point;

double slopeXY(Point P1,Point P2)
{//求XY方向上的斜率
		return (P2.y_coordinate-P1.y_coordinate)/(P2.x_coordinate-P1.x_coordinate);
}
int iscolinearXY(Point P1,Point P2,Point P3)
{//判断三点在XY平面是否共线
	int flag=0;
	if ( slopeXY(P1,P2) == slopeXY(P2,P3) )
		flag=1;
	return flag;
}


int main()
{
	Point P1,P2,P3;
	printf("请输入P1的坐标：");
	scanf("%f%f%f",&(P1.x_coordinate),&(P1.y_coordinate),&(P1.z_coordinate));
	printf("请输入P2的坐标：");
	scanf("%f%f%f",&(P2.x_coordinate),&(P2.y_coordinate),&(P2.z_coordinate));
	printf("请输入P3的坐标：");
	scanf("%f%f%f",&(P3.x_coordinate),&(P3.y_coordinate),&(P3.z_coordinate));

	if( iscolinearXY(P1,P2,P3) )
		printf("P1,P2,P3三点在XY平面共线！\n");
	else
		printf("P1,P2,P3三点在XY平面不共线！\n");

	return 0;
}