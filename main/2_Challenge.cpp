
#include <iostream>

enum ESortType : int
{
	Ascending = 1,
	Descending = 2,
};

void Bubble(int* PtrArr, int ArrCnt, int SortType);

int main()
{
	int Arr[5] = { 3,2,7,6,1 };
	int ArrCnt = sizeof(Arr) / sizeof(int);

	int Type;
	std::cout << "Sort Type (1 : Asc, 2 : Desc) : ";
	std::cin >> Type;

	std::cout << "Origin : \n";
	for (int i = 0; i < ArrCnt; i++)
	{
		std::cout << "[" << Arr[i] << "]";
	}
	std::cout << "\n";

	switch (Type)
	{
	case ESortType::Ascending:
		Bubble(Arr, ArrCnt, 1);
		break;
	case ESortType::Descending:
		Bubble(Arr, ArrCnt, 2);
		break;
	default:
		break;
	}

	std::cout << "Sorting : \n";
	for (int i = 0; i < ArrCnt; i++)
	{
		std::cout << "[" << Arr[i] << "]";
	}

	std::cout << std::endl;

	return 0;
}

void Swap(int& a, int& b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void Bubble(int* PtrArr, int ArrCnt, int SortType)
{
	for (size_t i = 0; i < ArrCnt; i++)
	{
		for (size_t k = 0; k < ArrCnt - 1 - i; k++)
		{
			bool bSwap = false;
			if (ESortType::Ascending == SortType)
				bSwap = PtrArr[k] > PtrArr[k + 1];
			else
				bSwap = PtrArr[k] < PtrArr[k + 1];

			if (bSwap) Swap(PtrArr[k], PtrArr[k + 1]);
		}
	}
}