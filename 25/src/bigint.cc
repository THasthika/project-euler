#include "bigint.h"

using namespace std;

void BigInt::init()
{
	first_ptr_ = new ushort[EXPAND_SIZE];
	last_ptr_ = &first_ptr_[EXPAND_SIZE - 1];
	curr_ptr_ = first_ptr_;
	new_ptr_ = first_ptr_;
	*new_ptr_ = 0;
	new_ptr_++;
}

void BigInt::setArray(ushort *arr, int count)
{
	int size = EXPAND_SIZE;
	while(count > size)
	{
		size += EXPAND_SIZE;
	}
	first_ptr_ = new ushort[size];
	last_ptr_ = &first_ptr_[size - 1];
	curr_ptr_ = first_ptr_;
	copy(arr, count, first_ptr_);
	new_ptr_ = first_ptr_ + count;
}

BigInt& BigInt::operator+(BigInt &other)
{
	BigInt *max;
	BigInt *min;
	BigInt *ret = new BigInt();
	if(this->length() > other.length())
	{
		max = this;
		min = &other;
	}
	else
	{
		max = &other;
		min = this;
	}
	int size = EXPAND_SIZE;
	while(max->length() > size)
		size += EXPAND_SIZE;
	ret->first_ptr_ = new ushort[size];
	ret->last_ptr_ = &(ret->first_ptr_)[size - 1];
	ret->new_ptr_ = ret->first_ptr_;
	ret->curr_ptr_ = ret->first_ptr_;
	max->curr_ptr_ = max->first_ptr_;
	min->curr_ptr_ = min->first_ptr_;
	ushort sum = 0;
	ushort carry = 0;
	while(min->curr_ptr_ < min->new_ptr_)
	{
		sum = *(max->curr_ptr_) + *(min->curr_ptr_) + carry;
		carry = 0;
		if(sum > 9)
		{
			carry = sum / 10;
			sum %= 10;
		}
		*ret->new_ptr_ = sum;
		(ret->new_ptr_)++;
		(max->curr_ptr_)++;
		(min->curr_ptr_)++;
	}

	min->curr_ptr_ = min->first_ptr_;

	while(max->curr_ptr_ < max->new_ptr_)
	{
		sum = *(max->curr_ptr_) + carry;
		carry = 0;
		if(sum > 9)
		{
			carry = sum / 10;
			sum %= 10;
		}
		*ret->new_ptr_ = sum;
		(ret->new_ptr_)++;
		(max->curr_ptr_)++;
	}
	if(carry > 0)
	{
		if(ret->new_ptr_ - 1 == ret->last_ptr_)
		{
			size = (ret->last_ptr_ - ret->first_ptr_ + 1) + EXPAND_SIZE;
			int new_loc = ret->new_ptr_ - ret->first_ptr_;
			ret->first_ptr_ = expand(ret->first_ptr_, size);
			ret->last_ptr_ = &(ret->first_ptr_)[size - 1];
			ret->new_ptr_ = ret->first_ptr_ + new_loc;
			ret->curr_ptr_ = ret->first_ptr_;
		}
		*ret->new_ptr_ = carry;
		(ret->new_ptr_)++;
	}

	max->curr_ptr_ = max->first_ptr_;
	ret->curr_ptr_ = ret->first_ptr_;
	return *ret;
}