#pragma once
template<class T>
class MyArray
{
public:
	MyArray(int mCapacity)
	{//有参构造
		this->mCapacity=mCapacity;
		this->mSize=0;
	}
	MyArray(const MyArray &m)
	{//拷贝构造
		this->mCapacity=m.mCapacity;
		this->mSize=m.mSize;
		this->p=new T[this->mCapacity];
		int i=0;
		for(i=0;i<m.mSize;i++)
		{
			*(this->p+i)=*(m.p+i);
		}
	}
	//重载[]
private:
	int mCapacity;
	int mSize;
	T *p;
};