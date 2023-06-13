#include <string>
#include "task.h"
#include <vector>

class ToDo{
public:
	ToDo();
	ToDo(const std::vector<Task>& t);
	void addTask(const Task& t);
	void deleteTask(int index);
	void updateTask(int index, const std::string& d);
	void updateTask(int index, bool c);
	void updateTask(int index, const Date& date);
	void updateTask(int index, const std::string& d, bool c, const Date& date);
	void displayTasks();
	int getCountOfCompletedTasks() const;
	int getCountOfNotCompletedTasks() const;
private:
	std::vector<Task> tasks;
};