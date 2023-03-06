//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

int a[7];
int comp(const int*, const int*);
int compn(const int*, const int*);
using namespace std;

int main(int argc, char** argv)
{
	setlocale(0, "");
	fstream f;
	//открываем файл в режиме чтения
	f.open("D:\Other\AppsC\SortFile\File.txt", ios::in);
	//если открытие файла прошло корректно, то
	if (f)
	{
		for (int i = 0; i < 7; i++)
		{
			f >> a[i];
			//cout << a[i] << ' ';
		}
		f.close();
	}
	else cout << " Файл не существует" << endl;
	if (argc == 1)
	{
		printf("This program reads a file of numbers and outputs them sorted.\n");
		return 1;
	}
	if (argc == 2 && !strcmp(argv[1], "-h"))
	{
		printf("Option Description:\n");
		printf("-h Outputs a short description of the options.\n");
		printf("-a Sorts in ascending order.\n");
		printf("-d Sorts in descending order.\n");
		return 1;
	}
	if (argc == 2)
	{
		if (!strcmp(argv[1], "-a"))
		{
			printf("Sorts in ascending order.\n");
			qsort(a, 8, sizeof(int), (int(*) (const void*, const void*)) comp);
			printf("Sorted array: ");
			for (int i = 0; i < 7; i++)
			{
				printf(a[i]);
			}
			return 1;
		}
		if (!strcmp(argv[1], "-d"))
		{
			printf("Sorts in descending order.\n");
			qsort(a, 8, sizeof(int), (int(*) (const void*, const void*)) compn);
			printf("Sorted array: ");
			for (int i = 0; i < 7; i++)
			{
				printf(a[i]);
			}
			return 1;
		}
	}
}
int comp(const int* i, const int* j)
{
	return *i - *j;
}
int compn(const int* i, const int* j)
{
	return *j - *i;
}