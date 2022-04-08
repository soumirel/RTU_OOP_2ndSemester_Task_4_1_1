#pragma once

#include  "Cl_base.h"

class Cl_application : public Cl_base {
public:
	//Конструктор
	Cl_application(Cl_base* parentPtr = nullptr);

	//Построение дерева объектов (ввод)
	void buildTree();

	//"Запуск приложения"
	int execApp();

};
