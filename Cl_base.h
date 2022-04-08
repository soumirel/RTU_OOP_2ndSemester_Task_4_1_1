#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cl_base {
private:
	// Имя объекта
	string objectName = "";
	// Указатель на родителя объекта
	Cl_base* parentPtr;

public:
	//Объект root - "родитель" всех объектов
	static Cl_base* root;
	//Вектор указателей дочерних объектов
	vector<Cl_base*> childrenList;

	//Конструкторы
	Cl_base() { parentPtr = nullptr; };
	Cl_base(string objectName, Cl_base* parentPtr = nullptr);

	//Сетеры
	void setName(string objectName);
	void setParent(Cl_base* parentPtr);

	//Гетеры
	Cl_base* getParent();
	string getName();

	//Получение указателя на объект через его имя
	Cl_base* getObjectPtr(string name);

	//Вывод дерева объектов
	void printTree();
};
