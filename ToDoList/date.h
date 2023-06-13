class Date{
public:
	Date();
	Date(int d, int m, int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
private:
	int day;
	int month;
	int year;
};