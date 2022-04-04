#include "Cl_base.h"

// �������� �������-�����������
Cl_base* Cl_base::root = new Cl_base();

//�����������
Cl_base::Cl_base(string objectName, Cl_base* parentPtr)
{
	this->objectName = objectName;
	//���� ��� �� �������� ������
	if (parentPtr)
	{
		setParent(parentPtr);
		parentPtr->childrenList.push_back(this);
	}
	else
	{
		//����������� ������ ��� �������� (�������� ������ �����������)
		setParent(root);
		root->childrenList.push_back(this);
	}
}

//����� �����
void Cl_base::setName(string objectName)
{
	this->objectName = objectName;
}

//����� ��������
void Cl_base::setParent(Cl_base* parentPtr)
{
	this->parentPtr = parentPtr;
}

//����� �������� (���������)
Cl_base* Cl_base::getParent() {
	return parentPtr;
}

//����� �����
string Cl_base::getName() {
	return objectName;
}

//�������� ��������� �� ������ �� �����
Cl_base* Cl_base::getObjectPtr(string objectName)
{
	/* �������� ��������� � ������� �������� - �������� �� ���� �������� ��������
	*  ����� �� �������� ���������� ����� ����������� ��� �������� �������
	*  �.� ������ ������� ���.�������� = 0. �������� �������� �� �������� -
	*  ��������� �� ������, ������� ��� ��������� � ������ ��������. */
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		Cl_base* tmp = childrenList[i]->getObjectPtr(objectName);
		if (tmp->getName() == objectName)
		{
			return tmp;
		}
	}

	return this;
}

//����� ������ ��������
void Cl_base::printTree() {
	//������ ���������� ���������. ������� ������ - ��������� ���.��������

	//������� ������ �� ��������
	if (childrenList.size() == 0)
	{
		return;
	}

	//����� �������-�����������
	cout << endl << this->getName();

	//����� ����������� ��������
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		cout << "  " << childrenList[i]->getName();
	}

	//���� � �������� ��� ������� ��������� �������
	for (size_t i = 0; i < childrenList.size(); i++)
	{
		childrenList[i]->printTree();
	}
}
