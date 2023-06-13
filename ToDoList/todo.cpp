#include "todo.h"
#include <stdexcept>
#include <ctime>
#include <iostream>
#include <fstream>

ToDo::ToDo() = default;

ToDo::ToDo(const std::vector<Task>& t) : tasks{t} {}

void ToDo::addTask(const Task& t) {
	tasks.push_back(t);
}

void ToDo::deleteTask(int index) {
	if(index < 0 || index >= tasks.size()) {
		throw std::out_of_range{"Index out of range!"};
	}
	tasks.erase(tasks.begin() + index);
}

void ToDo::updateTask(int index, const std::string& d) {
	if(index < 0 || index >= tasks.size()) {
		throw std::out_of_range{"Index out of range!"};
	}
	tasks[index].setDescription(d);
}

void ToDo::updateTask(int index, bool c) {
	if(index < 0 || index >= tasks.size()) {
		throw std::out_of_range{"Index out of range!"};
	}
	tasks[index].setCompleted(c);
}

void ToDo::updateTask(int index, const Date& date) {
	if(index < 0 || index >= tasks.size()) {
		throw std::out_of_range{"Index out of range!"};
	}
	tasks[index].setDeadline(date);
}

void ToDo::updateTask(int index, const std::string& d, bool c, const Date& date) {
	if(index < 0 || index >= tasks.size()) {
		throw std::out_of_range{"Index out of range!"};
	}
	tasks[index].setDescription(d);
	tasks[index].setCompleted(c);
	tasks[index].setDeadline(date);
}

void ToDo::displayTasks() {
	std::ofstream file("toDoList.txt");
    Date date;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date.setYear(1900 + ltm->tm_year);
    date.setMonth(1 + ltm->tm_mon);
    date.setDay(ltm->tm_mday);
    std::cout << "Displaying tasks:" << std::endl;
    std::string result;
    for (int i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i]; 
        if (task.getCompleted()) {
            result = " Completed.";
        } 
        else if (task.getDeadline().getYear() == date.getYear() &&
                   task.getDeadline().getMonth() == date.getMonth() &&
                   date.getDay() == task.getDeadline().getDay()) {
            result = " Deadline today.";
        } 
        else if (task.getDeadline().getDay() < date.getDay()) {
            result = " Deadline has passed. Task not completed.";
        } 
        else {
            result = " Deadline in the future.";
        }
        file << i + 1 << ":\t" << task.getDescription() << "\t" << result << std::endl;
        std::cout << i + 1 << ":\t" << task.getDescription() << "\t" << result << std::endl;
    }
    file.close();
}

int ToDo::getCountOfCompletedTasks() const {
	int count = 0;
	for(int i = 0; i < tasks.size(); ++i) {
		if(tasks[i].getCompleted()) {
			count++;
		}
	}
	return count;
}

int ToDo::getCountOfNotCompletedTasks() const {
	int count = 0;
	for(int i = 0; i < tasks.size(); ++i) {
		if(!tasks[i].getCompleted()) {
			count++;
		}
	}
	return count;
}