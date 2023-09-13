#ifndef CATEGORY_H
#define CATEGORY_H
#include "common.h"

class Category {
	string name;
	int level; 
	int top;
	int mid;
public:
	Category(string name = "",int level = 0,int top = 0,int mid = 0) { this->name = name; this->level = level; this->top = top; this->mid = mid; }
	string getName() { return name; }	//카테고리명 받아오기	
	int getLevel() { return level; }
	int getTop() { return top; }
	int getMid() { return mid; }
	void Mod(string name,int level) { this->name = name; this->level = level; }
};


#endif
