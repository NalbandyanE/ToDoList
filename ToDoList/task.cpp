#include "task.h"

Task::Task() : description{" "}, completed{false}, deadline{Date()} {}

Task::Task(const std::string& d, const Date& dead) : description{d}, completed{false}, deadline{dead} {}

void Task::setDescription(const std::string& d) {
	description = d;
}

std::string Task::getDescription() const {
	return description;
}

void Task::setCompleted(bool c) {
	completed = c;
}

bool Task::getCompleted() const {
	return completed;
}

void Task::setDeadline(const Date& date) {
	deadline = date;
}

const Date& Task::getDeadline() const {
	return deadline;
}