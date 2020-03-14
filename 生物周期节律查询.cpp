#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<iostream>

using namespace std;
int  get_days(const char* from, const char* to); time_t convert(int year,int month,int day);
int tl,qx,zl;
char birth[200];char now[200];int i,j,byear,tyear,count=0;

int main()
	
{ printf("体力节律的周期为23天,情绪节律的周期为28天,智力节律的周期为33天\n\n\n");
	printf("开始计算你的生物节律周期\n\n"); 
    printf("首先计算你输入的两个年份间闰年的数目\n使用的日期必须为公历\n");
	printf("输入你的出生year(不包含月份和日期):");
	scanf("%d",&byear);
    printf("输入查询的year(不包含月份和日期):");
    scanf("%d",&tyear);
    
    for(i=byear;i<=tyear;i++)
    {
		if((i%4==0 && i%100!=0) || i%400==0)
		{  count++;} }
      printf("闰年的数目count=%d\n",count);

      printf("请输入你的出生年月日，格式为year-mouth-day\n");
	  scanf("%s",birth);
      const char* from=("%s",birth);
	  printf("请输入你想查询生物节律的年月日\n");
      scanf("%s",now);
      const char* to=("%s",now);
 int days=get_days(from,to)+count;
     printf("From:%s\nTo:%s\n",from,to);
     printf("总天数为%d\n\n\n",days);

	 tl=days%23;
	 qx=days%28;
	 zl=days%33;
	 printf("体力周期=%d\n",tl);
	 printf("情绪周期=%d\n",qx);
	 printf("智力周期=%d\n",zl);
	 if(tl==0)
	{
		printf("你的体力恰好处于周期日\n");
	}
	if(tl<12)
	{	
		printf("你的体力处于高潮期的第%d天\n",tl);
	}
	if(tl==12)
	{	
		printf("你的体力刚好处于临界期\n");
	}
	if(tl>12)
	{	
		printf("你的体力处于低潮期的第%d天\n",tl);
	}
	if(qx==0)
	{	
		printf("你的情绪恰好是周期日\n");
	}
	if(qx<14)
	{	
		printf("你的情绪正处于高潮期的第%d天\n",qx);
	}
	if(qx==14)
	{	
		printf("你的情绪恰好是临界日\n");
	}
	if(qx>14)
	{	
		printf("你的情绪处于低潮期的第%d天\n",qx);
	}
	if(zl==0)
	{	
		printf("你的智力刚好是周期日\n");
	}
	if(zl<17)
	{	
		printf("你的智力处于高潮期的第%d天\n",zl);
	}
	if(zl==17)
	{	
		printf("你的智力正处于临界日\n");
	}
	if(zl>17)
	{	
		printf("你的智力处于低潮期的第%d天\n\n\n",zl);}
//-----------------------------制作人体生物节律周期表供对照查询------------------------


	 printf(" \t     周期日\t高潮期\t临界期\t低潮期\n\n");
	 printf("体力周期\t0\t0~12\t 12\t12~23\n\n");
	 printf("情绪周期\t0\t0~14\t 14\t14~28\n\n");
	 printf("智力周期\t0\t0~17\t 17\t17~33\n\n\n\n");
system("pause");
return 0;

}

time_t convert(int year,int month,int day)

{
tm info={0};
info.tm_year=year-1900;
info.tm_mon=month-1;
info.tm_mday=day;
return mktime(&info);
}

int  get_days(const char* from, const char* to)
{
int year,month,day;int leap;

sscanf(from,"%d-%d-%d",&year,&month,&day);

int fromSecond=(int)convert(year,month,day);

sscanf(to,"%d-%d-%d",&year,&month,&day);

int toSecond=(int)convert(year,month,day);

return (toSecond-fromSecond)/24/3600;

}
