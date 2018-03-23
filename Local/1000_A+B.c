#include <stdio.h>

int main (void)
{
	// int a[65534],b[65534], sum[65534], ch;
	// int i = 1;
	// scanf("%d %d", &a[0], &b[0]);
	// sum[0] = a[0] + b[0];
	// while((ch = getchar()) != EOF)
	// {
	// 	scanf("%d %d", &a[i], &b[i]);
	// 	sum[i] = a[i] + b[i];
	// 	i++;
	// }
	// for (int j = 0; j < i; j++)
	// {
	// 	printf("%d\n",sum[j] );
	// }

	int a,b, ch;
	while(scanf("%d %d", &a, &b) != EOF)
	{
		
		printf("%d\n",a + b );

		// if((ch = getchar()) == EOF){
		// 	break;
		// }
	}
	
	return 0;
}