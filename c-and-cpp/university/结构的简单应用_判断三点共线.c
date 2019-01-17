/*�ṹ�ļ�Ӧ��_�ж����㹲��
   Author��Tianyong-Tsow������ӿ��
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//����һ���ռ�����
typedef struct Point
{
	double x_coordinate;	// X����
	double y_coordinate;
	double z_coordinate;
}Point;

double slopeXY(Point P1,Point P2)
{//��XY�����ϵ�б��
		return (P2.y_coordinate-P1.y_coordinate)/(P2.x_coordinate-P1.x_coordinate);
}
int iscolinearXY(Point P1,Point P2,Point P3)
{//�ж�������XYƽ���Ƿ���
	int flag=0;
	if ( slopeXY(P1,P2) == slopeXY(P2,P3) )
		flag=1;
	return flag;
}


int main()
{
	Point P1,P2,P3;
	printf("������P1�����꣺");
	scanf("%f%f%f",&(P1.x_coordinate),&(P1.y_coordinate),&(P1.z_coordinate));
	printf("������P2�����꣺");
	scanf("%f%f%f",&(P2.x_coordinate),&(P2.y_coordinate),&(P2.z_coordinate));
	printf("������P3�����꣺");
	scanf("%f%f%f",&(P3.x_coordinate),&(P3.y_coordinate),&(P3.z_coordinate));

	if( iscolinearXY(P1,P2,P3) )
		printf("P1,P2,P3������XYƽ�湲�ߣ�\n");
	else
		printf("P1,P2,P3������XYƽ�治���ߣ�\n");

	return 0;
}