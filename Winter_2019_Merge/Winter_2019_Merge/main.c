#include "MergeSort.h"
#include "FileIO.h"

int main()
{
	int* data;
	node* result;

	result = readFile();
	result = listMergeSort(result, 0, getSize(result)-1);
	writeFile(result);

	//data = doMergeSort(0, getSize()-1);
}