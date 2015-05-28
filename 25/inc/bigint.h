#include <iostream>

#define EXPAND_SIZE 10

using namespace std;

class BigInt
{
private:
	ushort *first_ptr_;
	ushort *last_ptr_;
	ushort *curr_ptr_;
	ushort *new_ptr_;

protected:
	void init();
	void setArray(ushort *arr, int count);

	static ushort* intToShortArray(int num, int *count)
	{
		ushort *out;
		if(num == 0)
		{
			out = new ushort[1];
			*count = 1;
			out[0] = 0;
			return out;	
		}
		*count = 0;
		int size = EXPAND_SIZE;
		out = new ushort[size];
		while(num > 0)
		{
			if((*count) >= size)
			{
				size += EXPAND_SIZE;
				out = expand(out, size);
			}
			out[*count] = num % 10;
			num /= 10;
			(*count)++;
		}
		return out;
	}

	static void copy(ushort *src, int size, ushort *dest)
	{
		ushort *cur = dest;
		while((cur - dest) < size)
		{
			*(cur++) = *(src++);
		}
	}

	static ushort* expand(ushort *arr, int size)
	{
		return (ushort*) realloc(arr, sizeof(ushort)*size);
	}

	static void swap(ushort *a, ushort *b)
	{
		ushort tmp = *a;
		*a = *b;
		*b = tmp;
	}

	static void reverse(ushort *arr, int size)
	{
		int j;
		for(int i = 0; i < size / 2; i++)
		{
			j = (size-1) - i;
			swap(&arr[i], &arr[j]);
		}
	}


public:
	BigInt()
	{
		init();
	}

	BigInt(const int &num)
	{
		int count;
		ushort *arr = intToShortArray(num, &count);
		setArray(arr, count);
	}

	int length()
	{
		return new_ptr_ - first_ptr_;
	}
	BigInt& operator+(BigInt &other);

	friend ostream& operator<<(ostream &os, BigInt &bigInt)
	{
		int size = bigInt.length();
		ushort *tmp = new ushort[size];
		ushort *first = tmp;
		copy(bigInt.first_ptr_, size, tmp);
		reverse(tmp, size);
		size--;
		while(size >= 0)
		{
			os << *(first++);
			size--;
		}
		return os;
	}
};