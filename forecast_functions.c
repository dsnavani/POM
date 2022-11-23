#include<stdio.h>
#include<stdlib.h>


// SIMPLE AVERAGE METHOD
float simple_average(float arr[],int num)
{
	printf("\nSIMPLE AVERAGE METHOD:\n");
	float sum = 0;
	for(int i = 0; i < num; i++) 
	{
		sum += arr[i];
	}
	float forecast = sum/num;
	printf("\nForecast for the month %d based on SIMPLE AVERAGE METHOD : %.3f \n", num+1, forecast);
	return forecast;
}

// MOVING AVERAGE METHOD
float moving_average(float arr[],int num)
{
	printf("\nMOVING AVERAGE METHOD:\n");
	float sum = 0;
	int n;
	printf("\nGive number of months moving average : ");
	scanf("%d",&n);
	while(n > num)
	{
		printf("\nNot having enough data!\n Give number of months moving average : ");
		scanf("%d",&n);
	}
	static float* forecast ;
	forecast = (float*)calloc(num - n + 1, sizeof(int));
	for(int i = n-1; i < num; i++)
	{
		sum = 0;
		for(int j = i - (n - 1); j <= i; j++)
		{
			sum += arr[j];
		}
		forecast[i-(n-1)] = sum/n;
	}
	printf("\nForecast for the month %d based on MOVING AVERAGE METHOD : %f \n", num+1, forecast[num-n]);
	
	return forecast[num-n];
}

// WEIGHTED MOVING AVERAGE METHOD
float weighted_moving_average(float arr[],int num)
{
	printf("\nWEIGHTED MOVING AVERAGE METHOD\n");
	float sum = 0;
	int n; // MOVING AVERAGE NUMBER
	printf("\nGive number of months for weighted moving average : ");
	scanf("%d",&n);
	while(n > num)
	{
		printf("\nNot having enough data!\n Give number of months moving average : ");
		scanf("%d",&n);
	}
	float weight[n]; // WEIGHT VALUES
	float weight_check = 0;  // TEMPORARY VARIABLE TO CHECK WEIGHT
	for(int i = 0;i < n; i++) 
	{
		printf("weight %d : ",i+1);
		scanf("%f",&weight[i]);
	}
	for(int i = 0;i < n; i++) weight_check += weight[i];
	while(weight_check != 1)
	{
		weight_check = 0;
		printf("Enter correct weights \n");
		for(int i = 0;i < n; i++) 
		{
			printf("weight %d : ",i+1);
			scanf("%f",&weight[i]);
		}
		for(int i = 0;i < n; i++) weight_check += weight[i];
	}
	static float* forecast ;
	forecast = (float*)calloc(num - n + 1, sizeof(int));
	for(int i = n-1; i < num; i++)
	{
		sum = 0;
		int k = 0;
		for(int j = i - (n - 1); j <= i; j++)
		{
			sum += arr[j] * weight[k++];
		}
		forecast[i-(n-1)] = sum;
	}
	printf("\nForecast for the month %d based on WEIGHTED MOVING AVERAGE METHOD : %f \n", num+1, forecast[num - n]);
	return forecast[num-n];
}

// EXPONENTIAL SMOOTHING METHOD
float exponential_smoothing(float arr[],int num)
{
	printf("\nEXPONENTIAL SMOOTHING \n");
	printf("\nGive old forecast for 1st month : ");
	static float *forecast; // FORECASTING
	forecast = (float*)calloc(num + 1, sizeof(int));
	scanf("%f",&forecast[0]);
	printf("Give the trend value : ");
	float t;  // TREND
	scanf("%f",&t);
	for(int i = 1; i <= num; i++)
	{
		forecast[i] = forecast[i-1] + t*(arr[i-1] - forecast[i-1]);
	}
	printf("\nForecast for the month %d based on EXPONENTIAL SMOOTHING METHOD : %f \n", num+1, forecast[num]);
	return forecast[num];
}

// DOUBLE EXPONENTIAL SMOOTHING METHOD
float double_exponential_smoothing(float arr[],int num)
{
	printf("\nDOUBLE EXPONENTIAL SMOOTHING \n");
	printf("\nalpha value : ");
	float a; // ALPHA VALUE
	scanf("%f",&a);
	printf("beta value : ");
	float b; // BETA VALUE
	scanf("%f",&b);
	
	printf("old forecast for 1st month : ");
	static float *forecast; // FORECASTING
	forecast = (float*)calloc(num + 1, sizeof(int));
	scanf("%f",&forecast[0]);
	
	printf("trend for 1st month : ");
	float trend[num+1]; // TREND
	scanf("%f",&trend[0]);
	float smooth_avg[num+1];  // SMOOTHED AVERAGE
	smooth_avg[0] = forecast[0];

	
	for(int i = 1; i <= num; i++)
	{
		smooth_avg[i] = a*arr[i-1] + (1-a)*(smooth_avg[i-1] + trend[i-1]);
		trend[i] = b*(smooth_avg[i] - smooth_avg[i-1]) + (1 - b)*trend[i-1];
		forecast[i] = smooth_avg[i] + trend[i];
	}
	printf("\nForecast for the month %d based on DOUBLE EXPONENTIAL SMOOTHING METHOD : %f \n", num+1, forecast[num]);
	return forecast[num];
}