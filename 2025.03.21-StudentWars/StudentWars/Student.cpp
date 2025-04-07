#include "Student.h"
#include <iostream>

using namespace std;

Student::Student():
	hp(100), dmg(5), luck(10), agr(0), brain(false)
{
}

Student::Student(int hp = 100, int dmg = 5, int agr = 0, int luck = 10, bool brain  = false) :
		hp(hp), dmg(dmg), luck(luck), agr(agr), brain(brain)
	{
	}	

Student::Student(const Student& st) :
		hp(st.hp), dmg(st.dmg), luck(st.luck), agr(st.agr), brain(st.brain)
	{
	}

Student::~Student()
	{
	}
void Student::print() {
	std::cout <<char(3)<< hp << " " <<char(24)<< dmg << " " <<char(15)<< agr << " " <<char(5)<< luck << " " <<char(14)<< brain << "\n";
}

bool Student::isDead() {
		return !(hp > 0);
	}

	int Student::attack() {
		int k = 1;
		if (hp < 20) {
			k = k + (0.1 + 0.1 * !(brain)) * agr;
		}
		if (rand() % 100 < luck) {
			k = k * 1.1;
		}
		return dmg * k;


	}

	void Student::defence(int dmg) {
		if (rand() % 100 < luck) {
			if (brain && dmg > hp) {
				dmg = 0;
			}
			else {
				dmg /= 2;
			}
		}
		hp -= dmg;
	}

	Student battle(Student st1, Student st2) {
		Student params1(st1);
		Student params2(st2);
		while (!st1.isDead() && !st2.isDead()) {
			if (st1.agr >= st2.agr) {
				st2.defence(st1.attack());
				st1.defence(st2.attack());
			}
			else {
				st1.defence(st2.attack());
				st2.defence(st1.attack());
			}
		}
		
		if (!st1.isDead()) {
			return params1;
		}
		return params2;
	}



