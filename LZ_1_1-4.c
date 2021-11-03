#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
	int *A=NULL, S=0, Min, Max, min_i=0, max_i=0; //������, ��� ������, �������� ����. � ���. ��������� � ��������������� �� �������.
	int **M=NULL, M_i, M_j, i=0, j=0, Sum; //�������, ���-�� �������� � �����, �������� � ���������� ��� ����� ���������.
	int Choice; //����� ������� ������������ ��������� ������� (�� �������� / �� �������)
	srand(time(NULL)); //������������� ������� ��������� �����
	setlocale(LC_ALL, "Rus");
	printf("������� ������ �������: ");
	scanf_s("%d", &S);
	while (S <= 0)
	{
		printf("������ ������� ����� �����������! ������� ����� ������������� �����: ");
		scanf_s("%d", &S);
	}
	printf("������� ���������� �������� �������: ");
	scanf_s("%d", &M_i);
	while (M_i <= 0)
	{
		printf("���������� �������� ������� ������ �����������! ������� ����� ������������� �����: ");
		scanf_s("%d", &M_i);
	}
	printf("������� ���������� ����� �������: ");
	scanf_s("%d", &M_j);
	while (M_j <= 0)
	{
		printf("���������� ����� ������� ������ �����������! ������� ����� ������������� �����: ");
		scanf_s("%d", &M_j);
	}
	A = (int*)malloc(S * sizeof(int)); //��������� ������ ��� ������
	M=(int**)malloc(M_j*sizeof(int)); //��������� ������ ��� ��������� �� ������ �������
	printf("\n������ A: ");
	for (i = 0; i < S; i++)
	{
		*(A + i)=rand()%200-100; //���������� ������� ���������� �������
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
	printf("\n����. ������� - ���. ������� = M[%d] - M[%d] = %d - %d = %d\n", max_i, min_i, Max, Min, Max-Min);
	printf("������� M:\n");
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
	printf("�������� ������ ������������ ��������� �������:\n1-�� �������\n2-�� ��������\n");
	scanf("%d", &Choice);
	while((Choice!=1)&&(Choice!=2))
	{
		printf("����������� �������� �����! ������� 1 ��� 2.\n");
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
					printf("����� �� %d-�� ������=%d\n", j+1, Sum);
				}
			break;
		}
	case(2):
		{
			for(i=0;i<M_i;i++)
			{
				for(j=0, Sum=0;j<M_j;j++)
					Sum+=*(*(M+j)+i);
				printf("����� �� %d-�� �������=%d\n", i+1, Sum);
			}
			break;
		}
	default:
		break;
	}
	free(M);
	free(A);
}