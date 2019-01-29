#include "InsertionSort.h"
#include "FileIO.h"

int main()
{
	int* printData;
	int i = 0;
	printData = doInsertionSort(readFile());
	
	writeFile(printData);

	return 0;
}