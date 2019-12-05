#include <bits/stdc++.h>
using namespace std;

int calendar[5000][15][33];
int curYear, curMonth, curDay;
inline bool isLeapYear(int year)
{
    return (year%400==0) || (year%4==0 && year%100!=0);
}

int getTotalDays(int year, int month)
{
    bool flag = false;
    int days = 0;
    if(isLeapYear(year))	flag = true;
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 2:
        if(flag)	days = 29;
        else		days = 28;
        break;
    default:
        days = 30;
        break;
    }
    return days;
}

void showMonth(int year, int month)
{
	cout << "\t\t";
    cout << "Sun";
    cout << "\t";
    cout << "Mon";
    cout << "\t";
    cout << "Tue\t";
    cout << "Wed\t";
    cout << "Thu\t";
    cout << "Fri\t";
    cout << "Sat\t";
    cout << endl;
    int week = 1;
    cout << "\t\t";
    while(calendar[year][month][1] != week)
    {
        cout << setfill(' ') << setw(3);
        cout << "\t";
        week++;
    }
    if(week > 7) week = 1;
    for(int i = 1; i <= getTotalDays(year, month); ++i)
    {
        cout << setw(3) << i << "\t";
        week++;
        if(week > 7)
        {
            week = 1;
            cout << endl;
        	cout << "\t\t";
        }
    }
    cout <<endl;
}

void viewWeekday(int y, int m, int d) {
    int x = calendar[y][m][d];
    switch(x) {
        case 1:
            cout <<  "Sunday\n";
            break;
        case 2:
            cout <<  "Monday\n";
            break;
        case 3:
            cout <<  "Tuesday\n";
            break;
        case 4:
            cout <<  "Wednesday\n";
            break;
        case 5:
            cout <<  "Thursday\n";
            break;
        case 6:
            cout <<  "Friday\n";
            break;
        case 7:
            cout <<  "Saturday\n";
            break;
    }
    cout << endl;
}

int getMonthFromInput(string s) {
	int m;
	for(int i = 0; i < s.length(); ++i)	s[i] = tolower(s[i]);	
	if(s.length() == 1)
		m = s[0] - '0';
	else if(s.compare("10") == 0)			m = 10;
    else if(s.compare("11") == 0)			m = 11;
	else if(s.compare("12") == 0)			m = 12;
	else if(s.compare("january") == 0 )		m = 1;
	else if(s.compare("february") == 0 )		m = 2;
	else if(s.compare("march") == 0 )		m = 3;
	else if(s.compare("april") == 0 )		m = 4;
	else if(s.compare("may") == 0 )			m = 5;
	else if(s.compare("june") == 0 )			m = 6;
	else if(s.compare("july") == 0 )			m = 7;
	else if(s.compare("august") == 0 )		m = 8;
	else if(s.compare("september") == 0 )	m = 9;
	else if(s.compare("october") == 0 )		m = 10;
	else if(s.compare("november") == 0 )		m = 11;
	else if(s.compare("december") == 0 )		m = 12;
	else								m = 100;
	return m;
}

int main()
{
    int week;
    string s;
    calendar[1970][1][1] = 5;
    week = 6;
    for(int i = 1970; i <= 4000; ++i)
    {
        for(int j = 1; j <= 12; ++j)
        {
            for(int k = 1; k <= getTotalDays(i,j); ++k)
            {
                if(i == 1970 && j == 1 && k == 1)	continue;
                calendar[i][j][k] = week++;
                if(week > 7)	week = 1;
            }
        }
    }
    printf("done\n");
    cout << "\033[2J\033[1;1H";
    while(1)
    {
        char ch;
        while(1) {
	        cout << "Current Year : ";
	        cin >> curYear;
        	if(curYear >= 1970 && curYear <= 4000) break;
        	else
        		cout << "Calendar is limited from Year 1970 to 4000\n";
        }
        while(1) {
	        cout << "Current Month : ";
	        cin >> s;
	        curMonth = getMonthFromInput(s);
       		if(curMonth > 0 && curMonth <= 12)	break;
       		else
       			cout << "In case you don't know,there is actually 12 months in a year. :) \n";
       	}
       	while(1) {
	        cout << "Current Day : ";
	        scanf("%d",&curDay);
        	if(curDay > 0 && curDay <= getTotalDays(curYear, curMonth))	break;
        	else
        		cout << "There's " << getTotalDays(curYear, curMonth) << " days in this month.\n";
        }
        getchar();
        cout << "Press enter to confirm. 'x' to edit current date/month/year\n";
        scanf("%c", &ch);
        if(ch == '\n')
            break;
        else
        {
            //	cout << "\033[2J\033[1;1H";
            continue;
        }
    }
    cout << "\033[2J\033[1;1H";
    showMonth(curYear,curMonth);
    while(1)
    {
        int choice;
        cout << "\n\n1. Jump to date.\n";
        cout << "2. Jump to month\n";
        cout << "3. Go to Current Date\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1) {
            cout << "\033[2J\033[1;1H";
            int y,m,d;
            cout << "Jump to date...\n\n";
            while(1) {
	        cout << "Enter Year : ";
	        scanf("%d",&y);
        	if(y >= 1970 && y <= 4000) break;
        	else
	        	cout << "Calendar is limited from Year 1970 to 4000\n";
	        }
	        while(1) {
		        cout << "Enter Month : ";
		        cin >> s;
		        m = getMonthFromInput(s);
	       		if(m > 0 && m <= 12)	break;
	       		else
	       			cout << "In case you don't know,there is actually 12 months in a year. :) \n";
	       	}
	       	while(1) {
		        cout << "Enter Day : ";
		        scanf("%d",&d);
	        	if(d > 0 && d <= getTotalDays(y, m))	break;
	        	else
	        		cout << "There's " << getTotalDays(y, m) << " days in this month.\n";
	        }
	            viewWeekday(y,m,d);
	            continue;
        }
        if(choice == 2) {
            int y,m;
            cout << "\033[2J\033[1;1H";
            cout << "Jump to month...\n\n";
            while(1) {
	        cout << "Enter Year : ";
	        scanf("%d",&y);
        	if(y >= 1970 && y <= 4000) break;
        	else
	        	cout << "Calendar is limited from Year 1970 to 4000\n";
	        }
	        while(1) {
		        cout << "Enter Month : ";
		        cin >> s;
		        m = getMonthFromInput(s);
	       		if(m > 0 && m <= 12)	break;
	       		else
	       			cout << "In case you don't know,there is actually 12 months in a year. :) \n";
	       	}
            cout << "\033[2J\033[1;1H";
            showMonth(y,m);
            continue;
        }
        if(choice == 3) {
            cout << "\033[2J\033[1;1H";
            showMonth(curYear, curMonth);
            continue;
        }
        else
            break;
    }
//	cout << "\033[2J\033[1;1H";
    getchar();
    return 0;
}
