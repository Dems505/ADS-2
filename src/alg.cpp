int countPairs1(int* arr, int len, int value)
{
	if ((len == 0) || (len == 1) || (arr[len - 1] < value / 2))
		return 0;
	int k = 0;
	for (int i = 0; i <= len; i++)
		for (int j = i + 1; j <= len; j++)
			if (arr[i] + arr[j] == value)
				k++;

	return k;
}

int countPairs2(int* arr, int len, int value)
{
	if ((len == 0) || (len == 1) || (arr[len - 1] < value / 2))
		return 0;
	int k = 0;
	while (arr[len - 1] > value)
		len--;
	int j;
	int i = 0;
	while (arr[i] <= value / 2)
	{
		j = len - 1;
		while ((arr[i] + arr[j] >= value) && (j > i))
		{
			if (arr[i] + arr[j] == value)
				k++;
			j--;
		}
		i++;
	}

	return k;
}


int countPairs3(int* arr, int len, int value)
{
	if ((len == 0) || (len == 1) || (arr[len - 1] < value / 2))
		return 0;
	int k = 0;
	for (int i = 0; i < len - 1; i++)
	{
		int left = i, right = len;

		while (left < right - 1)
		{
			int mid = (left + right) / 2;
			if (arr[i] + arr[mid] == value)
			{
				k++;
				int j = mid + 1;
				while ((arr[i] + arr[j] == value) && (j < right))
				{
					k++;
					j++;
				}
				j = mid - 1;
				while ((arr[i] + arr[j] == value) && (j > left))
				{
					k++;
					j--;
				}
				break;
			}
			if (arr[i] + arr[mid] > value)
				right = mid;
			else
				left = mid;
		}

	}
	return k;
}
