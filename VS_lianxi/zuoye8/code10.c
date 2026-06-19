#include<stdio.h>
#include<string.h>
void main()
{ char *p1, *p2, str[20]="xyz";
  p1="abcd";
  p2="ABCD";
  strcpy(str+1, strcat(p1+1, p2+1));
  printf("%s", str);
}