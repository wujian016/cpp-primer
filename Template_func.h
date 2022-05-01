#pragma once

template <typename T, size_t N>
const T* my_begin(const T(&a)[N]) {
	return &a[0];
}
template <typename T, size_t N>
const T* my_end(const T(&a)[N]) {
	return &a[0] + N;
}

template<typename T, size_t N>
void print2(const T(&a)[N]) {
	for (auto iter = my_begin(a); iter != my_end(a); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

template<typename T, size_t N>
constexpr int arr_size(const T(&a)[N])
{
	return N;
}

template<typename T, size_t N>
void print_arr(const T(&a)[N])
{
	for (int i = 0; i < arr_size(a); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}