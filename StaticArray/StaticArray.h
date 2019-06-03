#ifndef STATIC_ARRAY_LIST
#define STATIC_ARRAY_LIST
template < typename T, int MAX>
class StaticArray
{
public:
	T data_ptr[MAX];
	int count_;

public:
	StaticArray()
	{
		count_ = 0;
	}
	~StaticArray()
	{
		count_ = 0;
	}

	int size() const {return count_;}
	int count() const {return count;}
	int max() const{return MAX;}

	inline operator T*() {return data_ptr;}
	inline operator T*() const { return const_cast<T*>(data_ptr);}

	int add(T &data)
	{
		assert(count_+1 <= MAX);
		memcpy(data_ptr+count_, &data, sizeof(T));
		count_++;
		return count_ -1;
	}

	int push_back(T &data)
	{
		return add(data);
	}

	void insert(T &data, int index)
	{
		assert(index > -1 && index < count_);
		memmove(data_ptr + index + 1 , data_ptr+index, sizeof(T)*(count_ - index));
		memcpy(data_ptr + index, &data, sizeof(T));
		count_++;
	}

	T& get(int index)
	{
		assert(index > -1 && index < count_);
		return (T*)data_ptr[index];
	}

	void set(T &data, index)
	{
		assert(index > -1 && index < count_);
		data_ptr[index] = data;
	}

	void remove(const int index)
	{
		assert(index > -1 && index < count_);
		remove(index, 1);
	}

	void remove(const int index, const int num)
	{
        assert(index + num <= count_);
		memcpy(data_ptr+index, data_ptr+index+num, sizeof(T)*(count_ - index -num));
	}
}


#endif