#include <iostream>
#include "todo.h"

int main() {
	ToDo list;
	Date date1(11, 6, 2023);
	Task task1("Do lessons.", date1);
	Task task2("Do task1.", date1);
	Task task3("Do task2.", date1);
	task1.setCompleted(false);
	task2.setCompleted(true);
	task2.setCompleted(true);
	list.addTask(task1);
	list.addTask(task2);
	list.addTask(task3);
	list.displayTasks();
	std:: cout << "Count of completed tasks: " << list.getCountOfCompletedTasks() << std::endl;
	std:: cout << "Count of not completed tasks: " << list.getCountOfNotCompletedTasks() << std::endl;
	list.updateTask(0, true);
	list.displayTasks();
	Date date2(14, 5, 2024);
	list.updateTask(0, "Do homework.", false, date2);
	list.updateTask(1, false);
	list.updateTask(2, true);
	list.displayTasks();

	return 0;
}