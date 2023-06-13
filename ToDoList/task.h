#include <string>
#include "date.h"

class Task{
public:
	Task();
	Task(const std::string& d, const Date& dead);
	void setDescription(const std::string& d);
	std::string getDescription() const;
	void setCompleted(bool c);
	bool getCompleted() const;
	void setDeadline(const Date& date);
	const Date& getDeadline() const;
private:
	std::string description;
	bool completed;
	Date deadline;
};