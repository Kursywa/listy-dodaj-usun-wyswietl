#include<stdio.h>
#include<iostream>

using namespace std;
class Element {
public:
	string name;
	Element *next;
};

class ListManager {
	Element *head;
	
public:
	void pushBack(string name);
	void popBack();
	void showAll();
};



int main() {
	ListManager* manager = new ListManager();
	manager->pushBack("1");
	manager->pushBack("2");
	manager->popBack();
	manager->showAll();

	return 0;
}

//metody
void ListManager::pushBack(string name) {
	Element *N = new Element();
	N->name = "";
	N->next = NULL;

	Element* P = head;
	if (P == NULL) {
		P = N;
	}
	else {
		Element* P = head;
		while (P->next != NULL) {
			P = P->next;
		}
	}
	P->next = N;
}

void ListManager::showAll() {
	Element* P = head;
	while (P != NULL) {
		cout << P->name << endl;
		P = P->next;
	}
}

void ListManager::popBack() {
	Element* P = head;
	if (P == NULL) {}
	else if (P->next == NULL) {
		delete P;
		head = NULL;
	}
	else {
		while (P->next->next != NULL) {
			P++;
			if (P->next->next == NULL) {
				delete P->next;
				P->next = NULL;
			}
		}
	}
}