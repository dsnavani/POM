#include<stdio.h>
#include "forecast_functions.h"

int status()
{
	printf("\ntype 0 to exit\n");
	printf("type any other number to use another method :");
	int ck;
	scanf("%d",&ck);
	if(ck) return 1;
	else return 0;
}
void main()
{
	// N MONTHS DATA
	int num; 
	printf("Number of months :");
	scanf("%d",&num);
	
	// ARRAY TO STORE DATA
	float data[num];
	float forecast;
	for(int i = 0; i < num; i++) 
	{
		printf("%dth month data : ",i+1);
		scanf("%f",&data[i]);
	}
	printf("FORECAST METHODS :\n");
	printf(" Select 1 for simple average method\n");
	printf(" Select 2 for moving average method\n");
	printf(" Select 3 for weighted moving average method\n");
	printf(" Select 4 for exponential smoothing method\n");
	printf(" Select 5 for double exponential smoothing method\n");
	char select;
	int flag = 1;
	while(flag)
	{
		select = getchar();
		printf("select : ");
		scanf("%c",&select);
		switch(select)
		{
			case '1' :
				simple_average(data,num);
				flag = status();
				break;
			
			case '2' :
				moving_average(data,num);
				flag = status();
				break;
			
			case '3' :
				weighted_moving_average(data,num);
				flag = status();
				break;
			
			case '4' :
				exponential_smoothing(data,num);
				flag = status();
				break;
			
			case '5' :
				double_exponential_smoothing(data,num);
				flag = status();
				break;
			
			default:
				printf("\nNo methods selected! Enter appropriate number.");
				break;
		}
	}
	system("Timeout -1");
}
