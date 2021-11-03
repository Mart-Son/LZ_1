#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
	{
		char Name[20];
		char Fam[20];
		char Facult[20];
		int Zach_Num;
	}*Base;

void Search(int Area, Base Str, int S)
{
	int i, Z, k=0;
	char Buf[20];
	switch(Area)
	{
	case(1):
		{
			printf("������ �� �������: "); scanf("%s", &Buf);
			for(i=0;i<S;i++)
				if (!strcmp(Str[i].Fam, Buf))
					{
						printf("%d| ������� %s %s ��������� �� ���������� %s, ����� �������� ������: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	case(2):
		{
			printf("������ �� �����: "); scanf("%s", &Buf);
			for(i=0;i<S;i++)
				if (!strcmp(Str[i].Name, Buf))
					{
						printf("%d| ������� %s %s ��������� �� ���������� %s, ����� �������� ������: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	case(3):
		{
			printf("������ �� ����������: "); scanf("%s", &Buf);
			for(i=0;i<S;i++)
				if (!strcmp(Str[i].Facult, Buf))
					{
						printf("%d| ������� %s %s ��������� �� ���������� %s, ����� �������� ������: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	case(4):
		{
			printf("������ �� ������ �������� ������: "); scanf("%d", &Z);
			for(i=0;i<S;i++)
				if (Str[i].Zach_Num==Z)
					{
						printf("%d| ������� %s %s ��������� �� ���������� %s, ����� �������� ������: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	}
	if(k==0)
		printf("������ �� ������� �� ��������� �������...\n\n");
}

int main()
{
	int i=0, Size=0, Choice, Area;
	Base stud=NULL;
	setlocale(LC_ALL, "Rus");
	printf("������� ��������� ������ ���� �������� � ���� ������?\n");
	scanf("%d", &Size);
	while(Size<=0)
	{
		printf("����� ������� �����������! ������� ����� ������������� �����: ");
		scanf("%d", &Size);
	}
	stud=malloc(Size*sizeof(struct Student));
	if(stud==NULL)
	{
		printf("������ ��������� ������!\n");
		return -1;
	}

	for(i=0;i<Size;i++)
	{
		printf("\n������� ������ � %d-�� ��������...\n", i+1);
		printf("�������: "); scanf("%s", &(stud[i].Fam));
		printf("���: "); scanf("%s", &(stud[i].Name));
		printf("�� ����� ���������� ������� ���������: "); scanf("%s", &(stud[i].Facult));
		printf("����� �������� ������: "); scanf("%d", &(stud[i].Zach_Num));
	}
	printf("\n\n");
	for(i=0;i<Size;i++)
	{
		printf("%d| ������� %s %s ��������� �� ���������� %s, ����� �������� ������: %d\n", i+1, stud[i].Fam, stud[i].Name, stud[i].Facult, stud[i].Zach_Num);
	}
	printf("\n������� �� �� ����� ���������� � ���������� ��������? (0-���, 1-��)\n");
	scanf("%d", &Choice);
	while((Choice!=0) && (Choice!=1))
	{
		printf("����� ����� �����������! ������� ����� 0 ��� 1:\n");
		scanf("%d", &Choice);
	}
	switch(Choice)
	{
		case(0):
		{
				printf("���������� ������ ���������...\n");
				break;
		}
		case(1):
		{
			printf("�� ������ �������� �� ������ ����� ��������?");
			printf("\n1-�������, 2-���, 3-���������, 4-����� �������� ������\n");
			scanf("%d", &Area);
			while((Area!=1)&&(Area!=2)&&(Area!=3)&&(Area!=4))
			{
				printf("����� ����� �����������! ������� ����� �� 1 �� 4:\n");
				scanf("%d", &Area);
			}
			Search(Area, stud, Size);
			break;
		}
	}
	
	free(stud);
	return 0;
}