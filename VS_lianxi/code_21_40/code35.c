#include<stdio.h>
#include<math.h>
struct point
{
    float x;
    float y;
};
float GetDis(struct point,struct point);
float GetDis(struct point p1,struct point p2)
{
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

void main()
{
    struct point pt0={0.0,0.0};
    struct point pt1,pt3,pt2;
    printf("请输入第一个点的坐标:");
    scanf("%f%f",&pt1.x,&pt1.y);
    printf("请输入第二个点的坐标:");
    scanf("%f%f",&pt2.x,&pt2.y);
    pt3=pt1;
    printf("第一个点的坐标是:(%.1f,%.1f),",pt1.x,pt1.y);
    printf("原点到第一个点的距离是:%f\n",GetDis(pt0,pt1));
    printf("第一个点的坐标是:(%.1f,%.1f),",pt2.x,pt2.y);
    printf("原点到第二个点的距离是:%f\n",GetDis(pt0,pt2));
    printf("第一个点的坐标是:(%.1f,%.1f),",pt3.x,pt3.y);
    printf("原点到第三个点的距离是:%f\n",GetDis(pt0,pt3));
}