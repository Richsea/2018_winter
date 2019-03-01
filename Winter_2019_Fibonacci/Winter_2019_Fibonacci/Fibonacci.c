
int doRecursiveFib(int count)
{
	if (count < 2)
	{
		return count;
	}

	int fibResult1 = 0;
	int fibResult2 = 0;
	// 피보나치 어떻게 나눠야 하지?
	
	fibResult1 = doRecursiveFib(count - 1);
	fibResult2 = doRecursiveFib(count - 2);

	return fibResult1 + fibResult2;
}

int doArrayFib(int count)
{
	int arr[20];
	
	if (count > 20)
	{
		return -1;
	}

	int location = 2;

	if (count == 0)
	{
		return 0;
	}
	if (count == 1)
	{
		return 1;
	}

	arr[0] = 0;
	arr[1] = 1;

	while (location <= count)
	{
		arr[location] = arr[location - 1] + arr[location - 2];
		location++;
	}

	return arr[location-1];
}

int squareRecurssive(int count)
{

}