#include <stdio.h>

char *human_readable_time (unsigned seconds, char *time_string)
{
    int hrs = seconds / 3600;
    int mins = (seconds - hrs * 3600) / 60;
    int sec = seconds % 60;
    sprintf(time_string, "%s%d:%s%d:%s%d\0", 
        hrs / 10 == 0 ? "0" : "", hrs, 
        mins / 10 == 0 ? "0" : "", mins, 
        sec / 10 == 0 ? "0" : "", sec);

	return time_string; // return it
}

int main(int argc, char* argv[]) {
    char* res = malloc(sizeof(char) * 9);
    human_readable_time(0, res); // "00:00:00");
	human_readable_time(59, res); // "00:00:59");
	human_readable_time(60, res); // "00:01:00");
	human_readable_time(90, res); // "00:01:30");
	human_readable_time(3599, res); // "00:59:59");
	human_readable_time(3600, res); // "01:00:00");
	human_readable_time(45296, res); // "12:34:56");
	human_readable_time(86399, res); // "23:59:59");
	human_readable_time(86400, res); // "24:00:00");
	human_readable_time(359999, res); // "99:59:59");
}