#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdlib.h>
////#include<math.h>
#include <stdio.h>

int main()
{
	printf("%d", sizeof(char*));
	return 0;
}

//int main()
//{
//	char bor[3][3];
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			bor[i][j] = ' ';
//			printf("%c", bor[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	double n;
//	scanf("%lf", &n);
//}

//int main()
//{
//	float exc;
//	float tic;
//	float per;
//	scanf("%d%d", &exc, &tic);
//	per = ((exc - tic) / tic * 100);
//	if (per < 10)
//		printf("OK");
//	else if (per < 50)
//		printf("Exceed %.0f%%. Ticket 200", per);
//	else
//		printf("Exceed %.0f%%. License Revoked", per);
//	return 0;
//}

//int main()
//{
//	int arr[3];
//	int i;
//	int j;
//	int tmp = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 2; i++)
//	{
//		for(j=0;j<2-i;j++)
//		if (arr[j] > arr[j + 1])
//		{
//			tmp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = tmp;
//		}
//	}
//	for (i = 0; i < 2; i++)
//	{
//		printf("%d->", arr[i]);
//	}
//	printf("%d", arr[2]);
//	return 0;
//
//}


//
//int main()
//{
//	int arr[5];
//	int i;
//	int count = 0;
//	printf("[1] apple\n");
//	printf("[2] pear\n");
//	printf("[3] orange\n");
//	printf("[4] grape\n");
//	printf("[0] exit\n");
//	
//	for (i = 0; i <= 4; i++)
//	{
//		scanf("%d", &arr[i]);
//		count++;
//		if (arr[i] == 0)
//		{
//			break;
//		}
//		
//	}
//	for (i = 0; i <= 4; i++)
//	{
//		if (arr[i] == 0)
//		{
//			break;
//		}
//		if (i != (count-1) )
//		{
//			
//			if (arr[i]>0 && arr[i]<=4)
//			{
//				switch (arr[i])
//				{
//				case(1):printf("price = 3.00\n"); break;
//				case(2):printf("price = 2.50\n"); break;
//				case(3):printf("price = 4.10\n"); break;
//				case(4):printf("price = 10.20\n"); break;
//				}
//			}
//			else
//				printf("price = 0.00\n");
//		}
//		else
//		{
//			if (arr[i] > 0 && arr[i] <= 4)
//			{
//				switch (arr[i])
//				{
//				case(1):printf("price = 3.00"); break;
//				case(2):printf("price = 2.50"); break;
//				case(3):printf("price = 4.10"); break;
//				case(4):printf("price = 10.20"); break;
//				}
//			}
//			else
//				printf("price = 0.00");
//
//		}
//	}
//	return 0;
//
//}

//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n >= 90)
//		printf("A");
//	else if (n >= 80)
//		printf("B");
//	else if (n >= 70)
//		printf("C");
//	else if (n >= 60)
//		printf("D");
//	else
//		printf("E");
//	return 0;
//
//	
//}

//int main()
//{
//	int n;
//	int i;
//	int count = 0;
//	scanf("%d", &n);
//	
//
//	if (n > 2100 || n <= 2000)
//	{
//		printf("Invalid year!");
//	}
//	else
//	{
//		
//		for (i = 2001; i <= n; i++)
//		{
//			if (i % 4 == 0 && i % 100 != 0)
//			{
//				printf("%d\n", i);
//				count++;
//			}
//		}
//		if (count == 0)
//		printf("None");
//	}
//
//
//	return 0;
//
//}
//int main()
//{
//	char a[10];
//	int letter = 0;
//	int blank = 0;
//	int digit = 0;
//	int other = 0;
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%c", &a[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (a[i] >= 48 && a[i] <= 57)
//			digit++;
//		else if (a[i] >=65 && a[i] <= 90)
//			letter++;
//		else if (a[i] >= 97 && a[i] <= 122)
//			letter++;
//		else if (a[i] == '\n' || a[i] == ' ')
//			blank++;
//		else
//			other++;
//
//	}
//	printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
//}
//int main()
//{
//	int n=0;
//	int a[20];
//	int i;
//	float ans = 0;
//	int count = 0;
//	scanf("%d", &n);
//	if (n == 0)
//	{
//		ans = 0;
//	}
//	else
//	{
//		for (i = 0; i < n; i++)
//		{
//			scanf("%d", &a[i]);
//		}
//		for (i = 0; i < n; i++)
//		{
//			ans = ans + a[i];
//			if (a[i] >= 60)
//				count++;
//		}
//		ans = ans / n;
//	}
//	printf("average = %.1f\n", ans);
//	printf("count = %d", count);
//}
//
//int main()
//{
//	int n;
//	
//	scanf("%d", &n);
//	if (n > 0)
//		printf("sign(%d) = 1", n);
//	else if (n < 0)
//		printf("sign(%d) = -1", n);
//	else
//		printf("sign(%d) = 0", n);
//	return 0;
//
//}
//int main()
//{
//	int n;
//	int i;
//	int s;
//	int j;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		s = 1;
//		for (j = 1; j <= i; j++)
//		{
//			
//			s = s * j;
//		}
//		sum = sum + s;
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int m;
//	float sum = 0;
//	float i;
//	
//	scanf("%d", &m);
//	for (i = 1; i <=  m; i++)
//	{
//		if((int)i%2== 0)
//		sum = sum - i/(2*i-1);
//		else
//		sum = sum + i / (2 * i - 1);
//
//
//	}
//	printf("%.3f", sum);
//	return 0;
//}
// 
// 
// 
// 
// ////////////////////////////////////////////////////////////////////////////////
// BASIC ,PTA2
//int sum = 0;
//void p_pinyin(int x)
//{
//	
//	if (x > 9)
//		p_pinyin(x / 10);
//	if (x != sum)
//	{
//		switch (x % 10)
//		{
//		case (1):printf("yi "); break;
//		case (2):printf("er "); break;
//		case (3):printf("san "); break;
//		case (4):printf("si "); break;
//		case (5):printf("wu "); break;
//		case (6):printf("liu "); break;
//		case (7):printf("qi "); break;
//		case (8):printf("ba "); break;
//		case (9):printf("jiu "); break;
//		case (0):printf("ling "); break;
//		}
//	}
//	else
//	{
//		switch (x % 10)
//		{
//		case (1):printf("yi"); break;
//		case (2):printf("er"); break;
//		case (3):printf("san"); break;
//		case (4):printf("si"); break;
//		case (5):printf("wu"); break;
//		case (6):printf("liu"); break;
//		case (7):printf("qi"); break;
//		case (8):printf("ba"); break;
//		case (9):printf("jiu"); break;
//		case (0):printf("ling"); break;
//		}
//	}
//
//}
//int main()
//{
//	int i;
//	int j;
//	char n[100];
//	
//	scanf("%s", &n);
//	for (i = 0; n[i]!='\0'; i++)
//	{
//		sum = sum + (n[i]-48);
//	}
//	/*printf("%d", sum);*/
//	p_pinyin(sum);
//
//	return 0;
//
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//int main()
//{
//	int n;
//	int i;
//	scanf("%d", &n);
//	for (i = 0; n !=1; i++)
//	{
//		if (n % 2 == 0)
//			n = n / 2;
//		else
//			n = ((3 * n + 1) / 2);
//
//	}
//	printf("%d", i);
//	return 0;
//}
//int is_prime(int n)
//{
//	int j;
//	int s=0;
//	for (j = 2; j < n; j++)
//	{
//		if (n % j == 0)
//			s++;
//	}
//	if (s == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//}
//int main()
//{
//	float e;
//	float c;
//	scanf("%f", &e);
//	if (e < 0)
//		printf("Invalid Value!");
//	else if (e > 50)
//	{
//		e = e - 50;
//		c =  50 * 0.53 + e * 0.58;
//		printf("cost = %.2f", c);
//	}
//	else
//	{
//		c = e * 0.53;
//		printf("cost = %.2f", c);
//
//	}
//	return 0;
//}

//int main()
//{
//	int a1;
//	int a2;
//	int a3;
//	int a4;
//	int sum;
//	float avg;
//	scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
//	sum = a1 + a2 + a3 + a4;
//	avg = (float)sum / 4;
//	printf("Sum = %d; Average = %.1f", sum, avg);
//	return 0;
//
//}
//int main()
//{
//	int x = 0;
//	int p = 0;
//	int i;
//	scanf("%d", &x);
//	system("cls");
//	for (i = 0; i <= x; i++)
//	{
//		p = pow(x, i);
//		printf("pow(%d,%d) = %d", x, i, p);
//		if (i != x)
//		{
//			printf("\n");
//		}
//
//	}
//	return 0;
//}



//int main()
//{
//    int n;
//    double i;
//    double sum=0;
//    scanf("%d", &n);
//
//    for (i = 1; i <= n; i+=3)
//    {
//        if ((int)i % 2 == 1)
//            sum = sum + 1 / i;
//        else
//            sum = sum - 1 / i;
//    }
//    printf("sum = %.6lf", sum);
//    return 0;
//
//}




//int main()
//{
//    int i = 0;
//    int j = 0;
//    for (i = 1; i <= 4; i++)
//    {
//        for (j = 1; j <= 7; j++)
//        {
//            if ((i + j) % 2 == 0 && j >= i && i + j <= 9)
//                printf("*");
//            else
//                printf(" ");
//        }
//        if (i == 4)
//            break;
//        printf("\n");
//    }
//    return 0;
//}
//3.4.1
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ans = 1;
//	scanf("%d", &n);
//	for (i = n; i != 1; i--)
//	{
//		ans = ans * i;
//	}
//	printf("%d", ans);
//	return 0;
//}

////3.4.2
//int main()
//{
//	int i=0;
//	int j = 0;
//	int ans=1;
//	int anss = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		for (j=1,ans=1; j<=i;j++)
//		{
//			ans = ans * j;
//		}
//		
//		anss = anss + ans;
//
//	}
//	printf("%d", anss);
//	return 0;
//}

//3.4.3


//int main()
//{
//	int a = 1;
//	while ( a < 100)
//	{
//		printf("%d ", a);
//		a++;
//		a++;
//		
//		
//	}
//	return 0;
//}




//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (0 == a % 2)
//		printf("这是一个偶数");
//	else
//		printf("这是一个奇数");
//	return 0;
//}

//int main()
//{
//	int a1;
//	int a2;
//	int num;
//	scanf("%d%d", &a1, &a2);
//	num = a1 + a2;
//	printf("%d", num);
//
//	
//	return 0;
//}
//enum sex
//{
//	male,
//	female,
//	secret
//};
//int main()
//{
//	printf("%d\n", male);
//	printf("%d\n", female);
//	printf("%d\n", secret);
//	return 0;
//
//}