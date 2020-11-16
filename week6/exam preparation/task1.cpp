#include<iostream>
#include<string>

//Даден е едносвързан цикличен списък, на който елементите му са стрингове. Да се реализира функция unite(Node list)*, 
//която получава като параметър указател към елемент на цикличен едносвързан списък от стрингове и обединява всички 
//двойки последователни елементи на списъка, за които последния символ на единия елемент съвпада с първия символ на 
//непосредствено следващия му елемент, в общ елемент чиито низ е съставен от слепването на стринговете на двата елемента 
//разделени с тире. Функцията да изкарва списъка на стандартния изход, започвайки от лексикографвски най-малкия низ.

template<typename T>
struct slnode
{
	T data;
	slnode* next;

	slnode(T elem, slnode<T>* next) : data(elem), next(next) {}
};

template<typename T>
void Print(slnode<T>* list)
{
	slnode<T>* iter = list;
	do
	{
		std::cout << iter->data << std::endl;
		iter = iter->next;
	} while (iter != list);
}

bool shouldUnite(const std::string& str1, const std::string& str2)
{
	if (str1 == "" || str2 == "")
		return false;
	return str1[str1.size() - 1] == str2[0];
}

void absorb(slnode<std::string>* node1, slnode<std::string>* node2)
{
	node1->data += '-' + node2->data;
	node1->next = node2->next;
	delete node2;
}

void unite(slnode<std::string>* list)
{
	if (list == nullptr)
		return;

	slnode<std::string>* temp = list;
	slnode<std::string>* lexMin = list;

	bool end = false;
	while (!end)
	{
		if (strcmp(temp->data.c_str(), lexMin->data.c_str()) < 0)
			lexMin = temp;

		if (temp->next == list)
			end = true;
		if (temp != temp->next && shouldUnite(temp->data, temp->next->data))
			absorb(temp, temp->next);
		else
			temp = temp->next;
	}

	Print(lexMin);
}

template<typename T>
void print(slnode<T>* list)
{
	while (list)
	{
		std::cout << list->data << " ";
		list = list->next;
	}
}

int main()
{
	slnode<std::string>* f1 = new slnode<std::string>("street", nullptr);
	slnode<std::string>* f2 = new slnode<std::string>("taxi", nullptr);
	slnode<std::string>* f3 = new slnode < std::string>("inc", nullptr);
	slnode<std::string>* f4 = new slnode < std::string>("dog", nullptr);
	slnode<std::string>* f5 = new slnode < std::string>("smile", nullptr);
	slnode<std::string>* f6 = new slnode < std::string>("eat", nullptr);
	slnode<std::string>* f7 = new slnode < std::string>("tall", nullptr);
	slnode<std::string>* f8 = new slnode < std::string>("pas", nullptr);
	f1->next = f2;
	f2->next = f3;
	f3->next = f4;
	f4->next = f5;
	f5->next = f6;
	f6->next = f7;
	f7->next = f8;
	f8->next = f1;

	unite(f1);
	return system("pause");
}
