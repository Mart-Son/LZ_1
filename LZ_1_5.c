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
			printf("Искать по фамилии: "); scanf("%s", &Buf);
			for(i=0;i<S;i++)
				if (!strcmp(Str[i].Fam, Buf))
					{
						printf("%d| Студент %s %s обучается на факультете %s, номер зачётной книжки: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	case(2):
		{
			printf("Искать по имени: "); scanf("%s", &Buf);
			for(i=0;i<S;i++)
				if (!strcmp(Str[i].Name, Buf))
					{
						printf("%d| Студент %s %s обучается на факультете %s, номер зачётной книжки: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	case(3):
		{
			printf("Искать по факультету: "); scanf("%s", &Buf);
			for(i=0;i<S;i++)
				if (!strcmp(Str[i].Facult, Buf))
					{
						printf("%d| Студент %s %s обучается на факультете %s, номер зачётной книжки: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	case(4):
		{
			printf("Искать по номеру зачётной книжки: "); scanf("%d", &Z);
			for(i=0;i<S;i++)
				if (Str[i].Zach_Num==Z)
					{
						printf("%d| Студент %s %s обучается на факультете %s, номер зачётной книжки: %d\n", i+1, Str[i].Fam, Str[i].Name, Str[i].Facult, Str[i].Zach_Num);
						k++;
					}
			break;
		}
	}
	if(k==0)
		printf("Ничего не найдено по введённому запросу...\n\n");
}

int main()
{
	int i=0, Size=0, Choice, Area;
	Base stud=NULL;
	setlocale(LC_ALL, "Rus");
	printf("Сколько студентов должно быть записано в базу данных?\n");
	scanf("%d", &Size);
	while(Size<=0)
	{
		printf("Число введено некорректно! Введите целое положительное число: ");
		scanf("%d", &Size);
	}
	stud=malloc(Size*sizeof(struct Student));
	if(stud==NULL)
	{
		printf("Ошибка выделения памяти!\n");
		return -1;
	}

	for(i=0;i<Size;i++)
	{
		printf("\nВведите данные о %d-ом студенте...\n", i+1);
		printf("Фамилия: "); scanf("%s", &(stud[i].Fam));
		printf("Имя: "); scanf("%s", &(stud[i].Name));
		printf("На каком факультете студент обучается: "); scanf("%s", &(stud[i].Facult));
		printf("Номер зачётной книжки: "); scanf("%d", &(stud[i].Zach_Num));
	}
	printf("\n\n");
	for(i=0;i<Size;i++)
	{
		printf("%d| Студент %s %s обучается на факультете %s, номер зачётной книжки: %d\n", i+1, stud[i].Fam, stud[i].Name, stud[i].Facult, stud[i].Zach_Num);
	}
	printf("\nЖелаете ли Вы найти информацию о конкретном студенте? (0-Нет, 1-Да)\n");
	scanf("%d", &Choice);
	while((Choice!=0) && (Choice!=1))
	{
		printf("Ответ введён некорректно! Введите цифру 0 или 1:\n");
		scanf("%d", &Choice);
	}
	switch(Choice)
	{
		case(0):
		{
				printf("Завершение работы программы...\n");
				break;
		}
		case(1):
		{
			printf("По какому критерию Вы хотите найти студента?");
			printf("\n1-Фамилия, 2-Имя, 3-Факультет, 4-Номер зачётной книжки\n");
			scanf("%d", &Area);
			while((Area!=1)&&(Area!=2)&&(Area!=3)&&(Area!=4))
			{
				printf("Ответ введён некорректно! Введите цифру от 1 до 4:\n");
				scanf("%d", &Area);
			}
			Search(Area, stud, Size);
			break;
		}
	}
	
	free(stud);
	return 0;
}