#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h> // atoi() function
using namespace std;

// Date format is true if date is of format 23-Jan-14
bool date_format = true;
const int max_no_conditions = 20; // CHANGE THIS IF NECESSARY!
#define no_of_months 12
#define no_of_days_in_year 365
#define no_of_days_in_month 30

int month(char input[])
{
	if (!strcmp(input,"Jan"))
		return 1;
	else if (!strcmp(input,"Feb"))
		return 2;
	else if (!strcmp(input,"Mar"))
		return 3;
	else if (!strcmp(input,"Apr"))
		return 4;
	else if (!strcmp(input,"May"))
		return 5;
	else if (!strcmp(input,"Jun"))
		return 6;
	else if (!strcmp(input,"Jul"))
		return 7;
	else if (!strcmp(input,"Aug"))
		return 8;
	else if (!strcmp(input,"Sep"))
		return 9;
	else if (!strcmp(input,"Oct"))
		return 10;
	else if (!strcmp(input,"Nov"))
		return 11;
	else if (!strcmp(input,"Dec"))
		return 12;
	else
	{
		cout << "Invalid month as per reqd format.\n";
		exit(1);
	}
}

struct date
{
	int dd, mm, yy;
	void convert_to_date(string date_val)
	{
		if(date_format)
		{
			char *token = strtok(&date_val[0], "-");
			dd = atoi(token);
			
			token = strtok(NULL, "-");
			mm = month(token);

			token = strtok(NULL, "-");
			// Change below line if year is not 21st century
			char year[4];
			strcpy(year,"20");
			strcat(year, token);
			yy = atoi(year);
		}
	}
};

// If val1 is same as, or after val2, returns true otherwise false. If equal is false, same dates return false.
bool compare_dates(date val1, date val2, bool equal = true)
{
	if(val1.yy > val2.yy)
		return true;
	else if(val1.yy < val2.yy)
		return false;

	if(val1.mm > val2.mm)
		return true;
	else if(val1.mm < val2.mm)
		return false;

	if(val1.dd > val2.dd)
		return true;
	else if(val1.dd < val2.dd)
		return false;

	else
		if(equal)
			return true;
		else
			return false;
}

bool is_leapyear(int year)
{
	if(!(year % 100))
		if(!(year % 400))
			return 1;
		else
			return 0;
	if(!(year % 4))
		return 1;
	else
		return 0;
}

// No of leap years inbetween two years, both years exclusive
int no_of_leap_years_inbetween(date val1, date val2)
{
	if(compare_dates(val1, val2))
		return 0;
	if(val2.yy - val1.yy < 2)
		return 0;

	int no_of_leap_years;
	no_of_leap_years = (val2.yy - val1.yy - 2)/4;
	if(is_leapyear(val1.yy + 1) || is_leapyear(val2.yy - 1))
		no_of_leap_years++;
	return no_of_leap_years;
}

static int day_increment[no_of_months] = {1, -2, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1};

// No of days from first day to end of year, current day inclusive
int no_of_days_from_start(date val)
{
	int no_of_days = 0, i;
	for(i = 0; i < val.mm - 1; i++)
		no_of_days += day_increment[i];
	no_of_days += no_of_days_in_month * (val.mm - 1);
	no_of_days += val.dd;

	if(is_leapyear(val.yy) && val.mm > 2)
		no_of_days++;

	return no_of_days;
}

// No of days to last day to end of year, current day inclusive
int no_of_days_to_end(date val)
{
	int no_of_days = 0, i;
	for(i = val.mm; i < no_of_months - 1; i++)
		no_of_days += day_increment[i];
	no_of_days += no_of_days_in_month * (no_of_months - val.mm);
	no_of_days += no_of_days_in_month + day_increment[val.mm - 1] - val.dd;
	if(is_leapyear(val.yy) && val.mm <= 2)
		no_of_days++;

	return no_of_days;
}

bool is_dates_equal(date val1, date val2)
{
	int count = 0;
	if(val1.dd == val2.dd)
		count++;
	if(val1.mm == val2.mm)
		count++;
	if(val1.yy == val2.yy)
		count++;

	if(count == 3)
		return true;
	return false;
}

// Difference of two dates, both inclusive
int difference_of_dates(date val1, date val2)
{
	if(compare_dates(val1, val2, false))
		return -1;

	int difference;

	if(val2.yy > val1.yy)
		difference = no_of_days_from_start(val2) + no_of_days_to_end(val1) + (val2.yy - val1.yy - 1) * no_of_days_in_year + no_of_leap_years_inbetween(val1, val2);
	else
		difference = no_of_days_from_start(val2) - no_of_days_from_start(val1) + 1;
	return difference;
}

// Assign val2 to val1
void date_assignment(date &val1, date &val2)
{
	val1.dd = val2.dd;
	val1.mm = val2.mm;
	val1.yy = val2.yy;
}

// Bubble sort on date array
void sort_date(date dateline[], int size)
{
	int i, count = 1;
	date temp;
	while(count)
	{
		count = 0;
		for(i = 0; i < size - 1; i++)
		{
			if(compare_dates(dateline[i], dateline[i+1], false))
			{
				count++;

				date_assignment(temp, dateline[i]);
				date_assignment(dateline[i], dateline[i+1]);
				date_assignment(dateline[i+1], temp);
			}
		}
	}
}

int remove_extras(date dateline[], int size)
{
	int i;
	date temp[size];
	for(i = 0; i < size; i++)
		date_assignment(temp[i], dateline[i]);

	int count = 0;
	for(i = 0; i < size - 1; i++)
	{
		if(is_dates_equal(temp[i], temp[i+1]))
			continue;
		else
			date_assignment(dateline[count++], temp[i]);
	}
	date_assignment(dateline[count++], temp[i]);

	return count;
}

// Checks if condition i overlaps with dates j, j+1 in dateline
bool condition_dateline_period_overlap(date start_condition[], date end_condition[], int i, date dateline[], int j)
{
	if(is_dates_equal(dateline[j], end_condition[i]) || is_dates_equal(dateline[j+1], start_condition[i]))
		return false;
	else if(is_dates_equal(dateline[j+1], end_condition[i]) || is_dates_equal(dateline[j], start_condition[i]))
		return true;
	else if(compare_dates(dateline[j], start_condition[i], false) && compare_dates(end_condition[i], dateline[j+1], false))
		return true;
	return false;
}

class loan
{
	private:
		int no_of_conditions;
		double amount, rate[max_no_conditions], max_rate;
		int total_time;
		date start_date, end_date;
		date start_condition[max_no_conditions], end_condition[max_no_conditions];
		double charges[max_no_conditions];
		double total_charges;

		date dateline[2 * max_no_conditions + 2];

		int i,j;
		int no_of_periods, duration_of_period;
		double rate_period[2 * max_no_conditions - 1];
	public:
		loan(double amount_val, int total_time_val, string start_date_val, int no_of_conditions_val, string start_condition_val[], string end_condition_val[], double rate_val[], double max_rate_val)
		{
			amount = amount_val;
			total_time = total_time_val;

			start_date.convert_to_date(start_date_val);

			date_assignment(end_date, start_date);
			end_date.yy = start_date.yy + total_time;

			if(no_of_conditions_val <= max_no_conditions)
				no_of_conditions = no_of_conditions_val;
			else
			{
				cout << "Adjust max_no_conditions accordingly before running.\n";
				exit(1);
			}
			for(i = 0; i < no_of_conditions; i++)
			{
				start_condition[i].convert_to_date(start_condition_val[i]);
				end_condition[i].convert_to_date(end_condition_val[i]);
				rate[i] = rate_val[i];
			}

			max_rate = max_rate_val;
			total_charges = 0;

			for(i = 0; i < max_no_conditions; i++)
				charges[i] = 0;
		}
		void date_line()
		{
			date_assignment(dateline[0], start_date);
			for(i = 0; i < no_of_conditions; i++)
			{
				date_assignment(dateline[1 + 2 * i], start_condition[i]);
				date_assignment(dateline[1 + 2 * i + 1], end_condition[i]);
			}
			date_assignment(dateline[2 * no_of_conditions + 1], end_date);

			sort_date(dateline, 2 * no_of_conditions + 2);
			no_of_periods = remove_extras(dateline, 2 * no_of_conditions + 2) - 1;
		}
		void compute_charges()
		{
			date_line();
			for(j = 0; j < no_of_periods; j++)
			{
				rate_period[j] = 0;
				duration_of_period = difference_of_dates(dateline[j], dateline[j+1]);
				for(i = 0; i < no_of_conditions; i++)
				{
					if(condition_dateline_period_overlap(start_condition, end_condition, i, dateline, j))
					{
						rate_period[j] += rate[i];
						charges[i] += (rate[i] * amount * duration_of_period / 100 / no_of_days_in_year);
					}
				}
				if(rate_period[j] > max_rate)
				{
					for(i = 0; i < no_of_conditions; i++)
					{
						if(condition_dateline_period_overlap(start_condition, end_condition, i, dateline, j))
						{
							charges[i] -= (rate[i] * amount * duration_of_period / 100 / no_of_days_in_year);
							charges[i] += (rate[i] / rate_period[j]) * (max_rate * amount * duration_of_period / 100 / no_of_days_in_year);
						}
					}
					
				}
			}

			// Total charges
			for(i = 0; i < no_of_conditions; i++)
				total_charges += charges[i];			
		}
		void print_charges()
		{
			for(i = 0; i < no_of_conditions; i++)
				printf("Charges for condition %d: %lf\n", i, charges[i]);
			printf("Total charges: %lf\n", total_charges);			
		}
		void print_charges_to_file(string filename, bool append = true)
		{
			ofstream myfile;
			if(append)
				myfile.open(&filename[0], ios_base::app);
			else
				myfile.open(&filename[0]);

			for(i = 0; i < no_of_conditions; i++)
				myfile << charges[i] << endl;
			myfile << total_charges << endl << endl;
			myfile.close();
		}
};

void loan_charges(string filename)
{
	ifstream myfile(&filename[0]);

	string start_date;
	int no_of_test_cases, no_of_conditions;
	double amount;
	int total_time;
	double max_rate;
	int k,m;

	string output_file = "output.txt";
	bool append;
	if(myfile.is_open())
	{
		myfile >> no_of_test_cases;
		for(k = 0; k < no_of_test_cases; k++)
		{
			myfile >> amount;
			myfile >> total_time;
			myfile >> start_date;
			myfile >> no_of_conditions;
			string start_condition[no_of_conditions], end_condition[no_of_conditions];
			double rate[no_of_conditions];
			for(m = 0; m < no_of_conditions; m++)
			{
				myfile >> start_condition[m];
				myfile >> end_condition[m];
				myfile >> rate[m];
			}
			myfile >> max_rate;

			loan instance(amount, total_time, start_date, no_of_conditions, start_condition, end_condition, rate, max_rate);

			//int charges[m];
			bool total = true;
			instance.compute_charges();
			//instance.print_charges();
			if(!k)
				append = false;
			else
				append = true;
			instance.print_charges_to_file(output_file, append);
		}
	}
	else
		printf("Unable to open file!!\n");
}

int main()
{
	string filename = "input.txt";
	loan_charges(filename);
}
