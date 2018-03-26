#include <stdio.h>
#include <string.h>

#define MAX 125
#define R_NUM 6

unsigned int result[MAX];
unsigned int R[R_NUM];
unsigned int temp[MAX];
// unsigned 

int main (void)
{
	int i, j, c, dot, exp;
	int out_start = -1;
	int out_end = -1;
	char input[MAX];
	while(scanf("%s %d", input, &exp) == 2)
	{
		memset(result, 0, sizeof(result));
		memset(temp, 0, sizeof(temp));
		memset(R, 0, sizeof(R));
		// 输入R，记录小数位数，并且转换为int值倒序存在R数组中
		for(i = 0,j = 0; i < R_NUM; i++)
		{
			if(input[R_NUM-1-i] == '.')
			{
				dot = i;
				continue;
			}
			R[j++] = input[R_NUM-1-i] - '0'; //用j可以去掉小数点占的位
			// printf("%d",R[i] );
		}
		
		for(i = 0; i < R_NUM; i++)
		{
			temp[i] = R[i];
			// printf("%d", temp[i]);
		}
		// printf("\n");
		// 大数乘法
		for(c = 0; c < exp-1; c++)
		{
			for(i = 0; i < MAX; i++)
			{
				for(j = 0; j < R_NUM; j++)
				{
					result[i+j] += temp[i] * R[j];
				}

			}
			for(i = 0; i < MAX-1; i++)
			{
				result[i+1] += result[i] / 10;
				result[i] = result[i] % 10;
			}

			// for(i = 0; i < MAX; i++)
			// {
			// 	printf("%d",result[i] );
			// }

			memcpy(temp, result, sizeof(result));
			memset(result, 0, sizeof(result));
		}
		memcpy(result, temp, sizeof(result));
		// for(i = 0; i < MAX; i++)
		// {
		// 	printf("%d",result[i] );
		// }
		// 结果的小数位数
		dot *= exp;

		for(i = MAX-1; i > dot - 1; i--)
		{
			if(result[i] != 0)
			{
				out_start = i;
				break;
			}
		}
		for(i = 0; i < dot-1; i++)
		{
			if(result[i] != 0)
			{
				out_end = i;
				break;
			}
		}
		// printf("\n");
		if(out_start != -1)
		{
			for(i = out_start; i > dot-1; i--)
			{
				printf("%d",result[i] );
			}
		}
		if(out_end != -1)
		{
			printf(".");
			for(i = dot-1; i > out_end-1; i--)
			{
				printf("%d", result[i] );
			}
		}
		printf("\n");
	}

	return 0;
}













