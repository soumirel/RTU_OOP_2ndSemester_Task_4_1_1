#include "Cl_base.h"

// Создание объекта-прородителя
Cl_base* Cl_base::root = new Cl_base();

//Конструктор
Cl_base::Cl_base(string objectName, Cl_base* parentPtr)
{
	this->objectName = objectName;
	//Если это не головной объект
	if (parentPtr)
	{
		setParent(parentPtr);
		parentPtr->childrenList.push_back(this);
	}
	else
	{
		//Привязываем объект как головной (дочерний объект прородителя)
		setParent(root);
		root->childrenList.push_back(this);
	}
}

//Сетер имени
void Cl_base::setName(string objectName)
{
	this->objectName = objectName;
}

//Сетер родителя
void Cl_base::setParent(Cl_base* parentPtr)
{
	this->parentPtr = parentPtr;
}

//Гетер родителя (указатель)
Cl_base* Cl_base::getParent() {
	return parentPtr;
}

//Гетер имени
string Cl_base::getName() {
	return objectName;
}

//Получить указатель на объект по имени
Cl_base* Cl_base::getObjectPtr(string objectName)
{
	/* Получаем указатель с помощью рекурсии - проходим по всем дочерним объектам
	*  Выход из рекурсии происходит когда закончились все дочерние объекты
	*  т.е длинна массива доч.объектов = 0. Выходное значение из рекурсии -
	*  указатель на объект, который был последним в вызове рекурсии. */
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		if (childrenList[i]->getObjectPtr(objectName)->getName() == objectName)
		{
			return childrenList[i]->getObjectPtr(objectName);
		}
	}

	return this;
}

//Вывод дерева объектов
void Cl_base::printTree() {
	//Дерево печатается рекурсией. Условие выхода - отсутсвие доч.объектов

	//Условие выхода из рекурсии
	if (childrenList.size() == 0)
	{
		return;
	}

	//Вывод объекта-подчинителя
	cout << endl << this->getName();

	//Вывод подчинённых объектов
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		cout << "  " << childrenList[i]->getName();
	}

	//Вход в рекурсию для каждого дочернего объекта
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		childrenList[i]->printTree();
	}
}
