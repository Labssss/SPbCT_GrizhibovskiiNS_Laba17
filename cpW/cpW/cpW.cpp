// cpW.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <windows.h>
#include <stdio.h>
#define BUF_SIZE 256
#pragma warning(disable : 4996)

int main(int argc, LPTSTR argv[])
{
	HANDLE hIn, hOut;
	DWORD nIn, nOut;
	CHAR Buffer[BUF_SIZE];
	if (argc != 3)
	{
		printf("Использование: CpW file1 File2\n");
		return 1;
	}
	hIn = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hIn == INVALID_HANDLE_VALUE)
	{
		printf("Нельзя открыть входной файл.Ошибка: % х\n", GetLastError());
		return 2;
	}
	hOut = CreateFile(argv[2], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("Нельзя открыть выходной файл.Ошибка: % х\n", GetLastError());
		return 3;
	}
	while (ReadFile(hIn, Buffer, BUF_SIZE, &nIn, NULL) && nIn > 0)
	{
		WriteFile(hOut, Buffer, nIn, &nOut, NULL);
		if (nIn != nOut)
		{
			printf("Неисправимая ошибка записи : % x\n", GetLastError());
			return 4;
		}
	}
	CloseHandle(hIn);
	CloseHandle(hOut);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
