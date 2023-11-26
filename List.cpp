#pragma once
#include <iostream>
using namespace std;
class List
{
public:
	int* arr;
	int size;

	List(){
		
		arr==nullptr;
		size=0;
		arr = new int[size];
	}
	void insert(int val){
		int *newList = new int[size+1];
		for(int i=0; i<size; ++i){
			newList[i] = arr[i];
		}
		newList[size] = val;
		++size;
		arr = newList;
	}
	void remove(int val){

		int *newList = new int[size-1];
		for(int i=0,j=0; i<size; ++i){
			if(arr[i] == val)
				continue;
			else
				newList[j++] = arr[i];
		}
		--size;
		arr = newList;
	}
	bool isDuplicate(int val){

		for(int i=0; i<size; ++i){
			if(arr[i] == val)
				return true;
		}
		return false;
	}
};

