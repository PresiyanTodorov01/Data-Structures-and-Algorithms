#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int times = 0;
	cin >> times;
	vector<pair< string,int>> dates;

	string inputHour;
	string inputDate;

	string currentDate="";

	for (int i = 0; i < times; i++)
	{
		cin >> inputHour;
		cin >> inputDate;
		for (int j = 6; j < 10; j++)
		{
			currentDate += inputDate[j];
		}
		for (int j = 3; j < 5; j++)
		{
			currentDate += inputDate[j];
		}
		for (int j = 0; j < 2; j++)
		{
			currentDate += inputDate[j];
		}
		for (int j = 0; j < inputHour.size(); j++)
		{
			currentDate += inputHour[j];
		}
		dates.push_back(pair<string,int>(currentDate,i + 1));
		currentDate = "";
	}
	std::sort(dates.begin(),
		dates.end());

    for(int i = 0; i < times; i++){
        cout << dates[i].second << endl;
    }
}
