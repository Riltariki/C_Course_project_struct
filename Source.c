#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

typedef struct persone {
	char lastname[20];
	float weight;
	int age;
	float first;
	float second;
	float points;
};

struct persone athlet_changes();
struct persone input_club();
struct persone athlet_random();
void athlet_statistic();
int getMarksSum();
void Sort();

void main() {

	struct persone mas[64];
	char fname[20];
	char reading[20];
	char txt[5] = ".txt";
	FILE* file;
	int count, n, choice, end, sort;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	n = 0;
	end = 0;
	sort = 0;

	printf("������� ���������� ������ > ");
	scanf_s("%d", &n);
	for (int k = 0; k < n; k++) {
		mas[k] = input_club(mas[k], k);
	}
	while (1)
	{
		char name[20];
		int selection, selection_2, count = 0;

		if (sort == 1) {
			Sort(mas, n);
		};

		printf("�������:\n");
		printf("1) ������.\n2) ��������� ������� ���������� ����������.\n3) �������� �������.\n4) ����������.\n5) ��������� ������� �� �����.\n6) ��������� ������� � ����.\n7) �������� ���������� ������.\n8) �����.\n\n");
		printf("�������� ���������� ������� > ");
		scanf_s("%d", &choice);
		printf("\n");
		system("cls");
		switch (choice)
		{
		case 1:
			printf("�������� ����� ������� ��� ������ � > ");
			scanf_s("%d", &selection);
			printf("\n");
			system("cls");
			while (1) {
				printf("������� ���������� �������:\n\n");
				printf("1) ������������� ��������� ������.\n2) ���������� �������������� ������.\n3) ������������� ������� ������.\n4) �����.\n\n");
				printf("�������� ����� > ");
				scanf_s("%d", &selection_2);
				printf("\n");
				printf("----------------------------------------------------\n\n");
				switch (selection_2)
				{
				case 1:
					mas[(selection - 1)] = athlet_changes(mas[(selection - 1)]);
					system("cls");
					athlet_statistic(mas[(selection - 1)]);
					break;
				case 2:
					athlet_statistic(mas[(selection - 1)]);
					break;
				case 3:
					printf("������� ������� ������ > ");
					scanf("%s", name);
					scanf("%s", mas[(selection - 1)].lastname);
					athlet_statistic(mas[(selection - 1)]);
					system("cls");
					break;
				case 4:
					system("cls");
					break;
				default:
					printf("����������� ������� �������.");
					break;
				} if (selection_2 == 4) {
					break;
				}
			}
			break;
		case 2:
			printf("��� �������� ������� ����������!\n\n");
			printf("�� �������,��� ������ ����������?\n");
			printf("1) ��\n2) ���\n");
			printf("������� > ");
			scanf("%d", &selection);
			switch (selection) {
			case 1:
				for (int k = 0; k < n; k++) {
					mas[k] = athlet_random(mas[k], k);
				}
				break;
			case 2:
				break;
			default:
				break;
			} system("cls");
			break;
		case 3:

			printf("\n");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			printf("|%7s|%17s|%17s|%17s|%17s|%17s|%17s|\n", "�����", "�������", "���", "�������", "�����", "������", "����� �����");
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			for (int i = 0; i < n; i++) {
				printf("|%7d|", (i + 1));
				printf("|%16s|", mas[i].lastname);
				printf("|%16.1f|", mas[i].weight);
				printf("|%16d|", mas[i].age);
				printf("|%16.1f|", mas[i].first);
				printf("|%16.1f|", mas[i].second);
				printf("|%16.1f|", mas[i].points);
				printf("\n");
			}
			printf("---------------------------------------------------------------------------------------------------------------------\n");
			printf("\n\n");
			printf("��������� ���������?\n1) ��\n2) ���\n");
			printf("������� > ");
			scanf_s("%d", &end);
			printf("\n\n");
			system("cls");
			break;
		case 4:
			printf("�������� ���������� ������� �� �����?\n1) ��\n2) ���\n");
			printf("������� > ");
			scanf("%d", &selection);
			switch (selection) {
			case 1:
				sort = 1;
				break;
			case 2:
				sort = 0;
				break;
			default:
				printf("����������� ������� �������.");
				printf("\n\n");
				printf("��������� ���������?\n1) ��\n2) ���\n");
				printf("������� > ");
				scanf_s("%d", &end);
				printf("\n\n");
				system("cls");
				break;
			}
			system("cls");
			break;
		case 5:
			printf("������� �������� ����� > ");
			scanf("%s", fname);
			strcat(fname, txt);
			file = fopen(fname, "r");
			while (fscanf(file, "%s%f%d%f%f%f", mas[count].lastname, &(mas[count].weight), &(mas[count].age), &(mas[count].first), &(mas[count].second), &(mas[count].points)) != EOF) {
				printf("%s %.2f %d %.2f %.2f %.2f\n", mas[count].lastname, (mas[count].weight), (mas[count].age), (mas[count].first), (mas[count].second), (mas[count].points));
				count++;
			} 
			n = count;
			fclose(file);
			break;
		case 6:
			printf("������� �������� ����� > ");
			scanf("%s", fname);
			strcat(fname, txt);
			file = fopen(fname, "w");
			for (int i = 0; i < n; i++) {
				fprintf(file, "%s %.2f %d %.2f %.2f %.2f\n", mas[i].lastname, mas[i].weight, mas[i].age, mas[i].first, mas[i].second, mas[i].points);
			}
			fclose(file);
			break;
		case 7:
			printf("������� ���������� ������ > ");
			scanf_s("%d", &n);
			break;
		case 8:
			printf("\n\n");
			printf("��������� ���������?\n1) ��\n2) ���\n");
			printf("������� > ");
			scanf_s("%d", &end);
			printf("\n\n");
			system("cls");
			break;
		default:
			printf("����������� ������� �������.");
			printf("\n\n");
			printf("��������� ���������?\n1) ��\n2) ���\n");
			printf("������� > ");
			scanf_s("%d", &end);
			printf("\n\n");
			system("cls");
			break;

		}
		if (end == 1) {
			break;
		}
	}

	return 0;
}

struct persone athlet_changes(struct persone x) {

	printf("������� ������� ������ > ");
	scanf("%s", x.lastname);
	printf("������� ��� ������ > ");
	scanf_s("%f", &x.weight);
	printf("������� ������� ������ > ");
	scanf_s("%d", &x.age);
	printf("������� ������ ������ > ");
	scanf_s("%f", &x.first);
	printf("������� ����� ������ > ");
	scanf_s("%f", &x.second);
	printf("\n");
	float A = 0.751945030;
	float b = 175.508;
	x.points = (x.first + x.second) * pow(10, A * pow(log10(x.weight / b), 2));
	return x;
}

struct persone input_club(struct persone x, int n) {

	char pustota[20] = " - ";
	strcpy(x.lastname, pustota);
	x.age = 0;
	x.weight = 0;
	x.first = 0;
	x.second = 0;
	float A = 0.751945030;
	float b = 175.508;
	x.points = 0;
	return x;
}

struct persone athlet_random() {
	struct persone x;

	char athlet[20] = "�����";
	strcpy(x.lastname, athlet);
	x.weight = 50 + rand() % 90;
	x.age = 15 + rand() % 40;
	x.first = 140 + rand() % 300;
	x.second = 140 + rand() % 300;
	float A = 0.751945030;
	float b = 175.508;
	x.points = (x.first + x.second) * pow(10, A * pow(log10(x.weight / b), 2));
	return x;
}


void athlet_statistic(struct persone x) {
	printf("\n");
	printf("������ �� ������:\n");
	printf("\n");
	printf("������� > %s\n��� > %.1f\n������� > %d\n������ > %.1f\n����� > %.1f\n����� ����� > %.1f\n\n", x.lastname, x.weight, x.age, x.first, x.second, x.points);
}

int getMarksSum(struct persone x)
{
	return x.points;

}

void Sort(struct persone x[], int N) {
	{
		struct persone tmp;

		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (getMarksSum(x[j]) < getMarksSum(x[j + 1]))
				{
					tmp = x[j];
					x[j] = x[j + 1];
					x[j + 1] = tmp;
				}
			}
		}

		return x;
	}
}



