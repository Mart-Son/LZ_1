#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
	int *A=NULL, S=0, Min, Max, min_i=0, max_i=0; //Массив, его размер, значения макс. и мин. элементов и соответствующие им индексы.
	int **M=NULL, M_i, M_j, i=0, j=0, Sum; //Матрица, кол-во столбцов и строк, счётчики и переменная под сумму элементов.
	int Choice; //Выбор способа суммирования элементов матрицы (по столбцам / по строкам)
	srand(time(NULL)); //Инициализатор датчика случайных чисел
	setlocale(LC_ALL, "Rus");
	printf("Введите размер массива: ");
	scanf_s("%d", &S);
	while (S <= 0)
	{
		printf("Размер массива задан некорректно! Введите целое положительное число: ");
		scanf_s("%d", &S);
	}
	printf("Введите количество столбцов матрицы: ");
	scanf_s("%d", &M_i);
	while (M_i <= 0)
	{
		printf("Количество столбцов матрицы задано некорректно! Введите целое положительное число: ");
		scanf_s("%d", &M_i);
	}
	printf("Введите количество строк матрицы: ");
	scanf_s("%d", &M_j);
	while (M_j <= 0)
	{
		printf("Количество строк матрицы задано некорректно! Введите целое положительное число: ");
		scanf_s("%d", &M_j);
	}
	A = (int*)malloc(S * sizeof(int)); //Выделение памяти под массив
	M=(int**)malloc(M_j*sizeof(int)); //Выделение памяти под указатели на строки матрицы
	printf("\nМассив A: ");
	for (i = 0; i < S; i++)
	{
		*(A + i)=rand()%200-100; //Заполнение массива случайными числами
		printf("%5d", *(A+i));
	}
	Min = *A; Max = *A;
	for (i = 0; i < S; i++)
	{
		if (*(A + i) < Min)
		{
			Min = *(A + i);
			min_i = i;
		}
		if (*(A + i) > Max)
		{
			Max = *(A + i);
			max_i = i;
		}
	}
	printf("\nМакс. элемент - Мин. элемент = M[%d] - M[%d] = %d - %d = %d\n", max_i, min_i, Max, Min, Max-Min);
	printf("Матрица M:\n");
	for (j = 0; j < M_j; j++)
	{
		*(M+j)=(int*)malloc(M_i*sizeof(int));
		for (i = 0; i < M_i; i++)
		{
			*(*(M+j)+i) = rand() % 200 - 100;
			printf("%5d", *(*(M+j)+i));
		}
		printf("\n");
	}
	printf("Выберите способ суммирования элементов матрицы:\n1-По строкам\n2-По столбцам\n");
	scanf("%d", &Choice);
	while((Choice!=1)&&(Choice!=2))
	{
		printf("Некорректно введённое число! Введите 1 или 2.\n");
		scanf("%d", &Choice);
	}
	switch(Choice)
	{
	case(1):
		{
			for(j=0;j<M_j;j++)
				{
					for(i=0, Sum=0;i<M_i;i++)
						Sum+=*(*(M+j)+i);
					printf("Сумма по %d-ой строке=%d\n", j+1, Sum);
				}
			break;
		}
	case(2):
		{
			for(i=0;i<M_i;i++)
			{
				for(j=0, Sum=0;j<M_j;j++)
					Sum+=*(*(M+j)+i);
				printf("Сумма по %d-му столбцу=%d\n", i+1, Sum);
			}
			break;
		}
	default:
		break;
	}
	free(M);
	free(A);
}