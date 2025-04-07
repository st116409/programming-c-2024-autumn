#pragma once
#include <string>

using namespace std;


class Student
{
private:
	
	int hp;
	int dmg;
	int agr;
	int luck;
	bool brain;
public:
	Student();
	Student(int hp, int dmg, int agr, int luck, bool brain);
	Student(const Student& st);
	
	~Student();

	bool isDead();
	void print();
	int attack();
	
	void defence(int dmg);

	friend Student battle(Student st1, Student st2);


};

