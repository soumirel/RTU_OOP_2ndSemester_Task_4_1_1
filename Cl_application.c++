#include "Cl_application.h"
#include "Cl_branch.h"

Cl_application::Cl_application(Cl_base* parentPtr)
{
	//Использование сетеров обусловленно закрытостью полей
	Cl_base::root->setParent(parentPtr);
	Cl_base::root->setName("root");
}

void Cl_application::buildTree()
{
	string parentName, childName;

	cin >> parentName;

	// Головной объект
	Cl_base* head = new Cl_base(parentName);
	while (true) {

		cin >> parentName >> childName;
		//Условие окончания ввода
		if (parentName == childName)
		{
			return;
		}

		// Создание дочернего объекта
		Cl_base* child = new Cl_branch(childName, root->getObjectPtr(parentName));
	}
}

int Cl_application::execApp()
{
	//Вывод имени головного объекта
	cout << root->childrenList[0]->getName();
	// Вывод построенного дерева
	root->childrenList[0]->printTree();
	return 0;
}