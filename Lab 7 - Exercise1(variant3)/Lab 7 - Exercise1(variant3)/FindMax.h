#pragma once

template <class T, class Less = std::less<T>>
bool FindMax(std::vector<T> const& arr,
	T & maxValue,
	Less const& less = Less())
{
	if (arr.empty())
	{
		return false;
	}
	maxValue = arr[0];
	for (T const& element : arr)
	{
		if (less(maxValue, element))
		{
			maxValue = element;
		}
	}
	return true;
}