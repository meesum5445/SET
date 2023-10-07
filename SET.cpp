#include"bscs22048_Sets.h"
#include<iostream>
#include<fstream>
#include<stdexcept>
using namespace std;
bool Set::isPresent(int T)const
{
	for (int i = 0; i < size; i++)
	{
		if (Vs[i] == T)
			return true;
	}
	return false;
}
int Set::numofequals(const Set & B)const
{
    int num=0;
    for(int i=0;i<B.size;i++)
    {
        if(this->isPresent(B.Vs[i]))
        {
            num++;
        }
    }
    return num;
}
Set::Set()
{
	this->size = 0;
	this->Vs = nullptr;
}
Set::Set(int size)
{
    this->size=size;
	this->Vs = (size!=0)?new int[size]{}:nullptr;
}
void Set::copy(const Set &orset)
{
    this->size = orset.size;
	this->Vs = (orset.size!=0)?new int[this->size] {}:nullptr;	
	for (int i = 0; i < this->size; i++)
	{
		this->Vs[i]=orset.Vs[i];
	}
}
Set::Set(const Set &orset)
{
	this->copy(orset);
}
Set::Set(ifstream& reader)
{
	this->Load(reader);
}
void Set::Load(ifstream& reader)
{
	reader >> this->size;
	this->Vs = new int[size]{};
	for (int i = 0; i < this->size; i++)
	{
		reader >> this->Vs[i];
	}
}
void Set::print_set()const
{
	cout << "{ ";
	for (int i = 0; i < this->size; i++)
	{
		cout << this->Vs[i]<<',';
	}
	cout << "\b}";
}
void Set::store (ofstream & wtr)const
{
    wtr<<this->size<<"\t";
	for (int i = 0; i < this->size; i++)
	{
		wtr<<this->Vs[i]<<" ";
	}
}
Set Set::Intersection (const Set & B) const
{
    Set temp(this->numofequals(B));
    if(temp.size==0)
        return temp;
    int count=0;
    for(int i=0;i<B.size;i++)
    {
        if(this->isPresent(B.Vs[i]))
        {
            temp.Vs[count]=B.Vs[i];
            count++;
        }
    }
    return temp;
}
Set Set::Union(const Set & B) const
{
    Set temp(this->size+B.size-this->numofequals(B));
    int count=0;
    for(int i=0;i<this->size;i++)
    {
        temp.Vs[count]=this->Vs[i];
        count++;
    }
    for(int i=0;i<B.size;i++)
    {
        if(!temp.isPresent(B.Vs[i]))
        {
            temp.Vs[count]=B.Vs[i];
            count++;
        }
    }
    return temp;
}
Set Set::Complement (const Set & U) const
{
    Set temp(U.size-U.numofequals(*this));
    int count=0;
    for(int i=0;i<U.size;i++)
    {
        if(!this->isPresent(U.Vs[i]))
        {
            temp.Vs[count]=U.Vs[i];
            count++;
        }
    }
    return temp;
}
Set Set::Subtraction (const Set & B) const
{
    return B.Complement(*this);
}
bool Set::IsEqual (const Set & B) const
{
    if(this->size!=B.size)
        return false;
    for(int i=0;i<B.size;i++)
    {
        if(!this->isPresent(B.Vs[i]))
            return false;
    }
    return true;
}
bool Set::Disjoint (const Set & B) const
{
    return this->Intersection(B).size==0;
}
bool Set::IsSuperset (const Set & B) const
{
    for(int i=0;i<B.size;i++)
    {
        if(!this->isPresent(B.Vs[i]))
            return false;
    }
    return true;
}
bool Set::IsSubset (const Set & B) const
{
    return B.IsSuperset(*this);
}
bool Set::IsProperSubSet (const Set & B) const
{
    return this->IsSubset(B) && !this->IsEqual(B);
}
Set::~Set()
{
    delete []this->Vs;
}