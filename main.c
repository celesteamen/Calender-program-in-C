/**
 * Name: Celeste Amengual
 * PID: 6115500
 * Assignment: 2
 * Class: COP 4338 Section U02
 */

#include <stdio.h>
#include <stdbool.h>
#include <expat.h>

int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool leapYr(int myYear);
void printMonth(int month, int year, int monthDays[]);
void dateDifference(int day1, int day2, int month1, int month2, int year1, int year2, int monthDays1[],
                    int monthDays2[]);
int main()
{
    int userCommand;

    int month, year;

    int day1,month1,year1;
    int day2,month2,year2;

    printf("Enter '1' if you want to print a certain month of a given year\n");
    printf("OR\n");
    printf("Enter '2' if you want to count the number of days between two different dates\n");

    scanf("%d", &userCommand);

    if(userCommand == 1)
    {

        printf("Enter Month and Year as (M/YYYY) Example ----> 3/2020\n");
        scanf("%d/%d", &month, &year);

        if( (month > 12) || (month < 1))
        {
            printf("Invalid Month Input");
            exit(0);
        }

        if(year < 0)
        {
            printf("Invalid Year Input");
            exit(0);
        }


        if(leapYr(year) == true)
        {
            monthDays[1] = 29;
            printMonth(month, year, monthDays);
        }
        else
        {
            printMonth(month, year, monthDays);
        }

    }
    if(userCommand == 2)
    {

        printf("Enter First Date as (M/D/YYYY) Example ----> 1/9/2020: \n");
        scanf("%d/%d/%d", &month1, &day1, &year1);

        if( (month1 > 12) || (month1 < 1))
        {
            printf("Invalid Month Input");
            exit(0);
        }
        if(year1 < 0)
        {
            printf("Invalid Year Input");
            exit(0);
        }

        printf("Enter Second Date as (M/D/YYYY) Example ----> 1/9/2020: \n");
        scanf("%d/%d/%d", &month2, &day2, &year2);

        if( (month2 > 12) || (month2 < 1))
        {
            printf("Invalid Month Input");
            exit(0);
        }
        if(year2 < 0)
        {
            printf("Invalid Year Input");
            exit(0);
        }

        dateDifference(day1,day2,month1,month2,year1,year2,monthDays,monthDays);
    }
    if(userCommand != 1 && userCommand !=2)
    {
        printf("Invalid Input");
    }

    return 0;
}

bool leapYr(int myYear)
{
    bool leapYr;
    if(myYear % 4 == 0 && myYear % 100 != 0 || myYear % 400 == 0)
    {
        leapYr= true;
    }

    else
    {
        leapYr = false;
    }

    return leapYr;
}

void dateDifference(int day1, int day2, int month1, int month2, int year1, int year2, int monthDays1[],
                    int monthDays2[])
{
    int daysInYear1;
    int daysInYear2;
    int i;
    int j;
    int k;
    int remainingDaysMonth2;
    int startingYear;
    int daysWithinYears;
    int daysWithinMonths;
    int totalDays;



    if(year1-year2 == 0)
    {

        if(leapYr(year1) == true)
        {
            monthDays1[1] = 29;
            monthDays2[1] = 29;
        }

        daysWithinMonths = 0;

        if(month1 > month2)
        {
            for(i = month1 - 1; i > month2; i--)
            {
                daysWithinMonths = daysWithinMonths + monthDays1[i-1];
            }

            totalDays = (monthDays2[month2-1] - day2) + day1 + daysWithinMonths;

            printf("\nThe difference between date1 and date 2 is: -%d days", totalDays);
        }
        if(month1 < month2)
        {
            for(i = month2 - 1; i > month1; i--)
            {
                daysWithinMonths = daysWithinMonths + monthDays1[i-1];
            }

            totalDays = (monthDays1[month1-1] - day1) + day2 + daysWithinMonths;

            printf("\nThe difference between date 1 and date 2 is: %d days", totalDays);
        }

        if(month1 == month2)
        {
            if(day2 > day1)
            {
                printf("The difference between date 1 and date 2 is: %d days", day2-day1);
            }
            else
            {
                printf("The difference between date 1 and date 2 is: -%d days", day1-day2);
            }
        }
    }

    if( (year1-year2) == 1 || (year1-year2) == -1 )
    {
        if(leapYr(year1) == true )
        {
            monthDays1[1] = 29;
        }
        if(leapYr(year2) == true)
        {
            monthDays2[1] = 29;
        }

        daysInYear1 = 0;
        for(i = 1; i < month1; i++)
        {
            daysInYear1 = daysInYear1 + monthDays1[i-1];
        }
        daysInYear1 = daysInYear1 + day1;

        daysInYear2 = 0;

        for(j = (month2 + 1) ; j <= 12; j++)
        {
            daysInYear2 = daysInYear2 + monthDays2[j-1];
        }
        remainingDaysMonth2 = monthDays2[month2-1] - day2;
        daysInYear2 = daysInYear2 + remainingDaysMonth2;

       if(year1 > year2)
       {
           printf("\nThe difference between date1 and date 2 is: -%d days", daysInYear1+daysInYear2);
       }
       else
       {
           printf("\nThe difference between date1 and date 2 is: %d days", daysInYear1+daysInYear2);
       }
    }

    daysWithinYears = 0;
    if( (year1 - year2) > 1 || (year1 - year2) < -1 )
    {
        if(year1 > year2)
        {
            for (startingYear = year2 + 1; startingYear < year1; startingYear++) {
                if (leapYr(startingYear) == true)
                {

                    daysWithinYears = daysWithinYears + 366;
                }
                else
                {

                    daysWithinYears = daysWithinYears + 365;
                }
            }
        }
        if(year1 < year2)
        {
            for (startingYear = year1 + 1; startingYear < year2; startingYear++) {
                if (leapYr(startingYear) == true)
                {
                    daysWithinYears = daysWithinYears + 366;
                }
                else
                    {
                    daysWithinYears = daysWithinYears + 365;
                }
            }
        }

        if(leapYr(year1) == true )
        {
            monthDays1[1] = 29;
        }
        if(leapYr(year2) == true)
        {
            monthDays2[1] = 29;
        }

        daysInYear1 = 0;
        for(k = 1; k < month1; k++)
        {
            daysInYear1 = daysInYear1 + monthDays1[k-1];
        }
        daysInYear1 = daysInYear1 + day1;

        daysInYear2 = 0;

        for(k = month2 + 1; k <= 12; k++)
        {
            daysInYear2 = daysInYear2 + monthDays2[k-1];
        }
        remainingDaysMonth2 = monthDays2[month2-1] - day2;
        daysInYear2 = daysInYear2 + remainingDaysMonth2;

        if(year1 < year2)
        {
            printf("\nThe difference between date1 and date 2 is: %d days", daysInYear1+daysInYear2+daysWithinYears);
        }
        else
        {
            printf("\nThe difference between date1 and date 2 is: -%d days", daysInYear1+daysInYear2+daysWithinYears);
        }

    }
}

/**
 * In this function,I used the "Tomohiko Sakamoto's Algorithm" to find the index
 * of the day of first day of the week that the first day of the month falls on.
 */

int dayNumber(int day, int month, int year)
{
    int dayIndex;
    int i;

    static int a[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;


    dayIndex = (year + year / 4 - year / 100 +year / 400 + a[month - 1] + day) % 7;
    return dayIndex;

}


void printMonth(int month, int year, int monthDays[])
{
    int days;
    int dayIndex;
    int i;

    if(month == 1)
    {
        printf("\n\n---------------%s %d------------------\n","January", year);
        dayIndex = dayNumber(1, 1, year);
        days = monthDays[0];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 2)
    {
        printf("\n\n---------------%s %d------------------\n","February", year);
        dayIndex = dayNumber(1, 2, year);
        days = monthDays[1];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 3)
    {
        printf("\n\n---------------%s %d------------------\n","March", year);
        dayIndex = dayNumber(1, 3, year);
        days = monthDays[2];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 4)
    {
        printf("\n\n---------------%s %d------------------\n","April", year);
        dayIndex = dayNumber(1, 4, year);
        days = monthDays[3];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 5)
    {
        printf("\n\n---------------%s %d------------------\n","May", year);
        dayIndex = dayNumber(1, 5, year);
        days = monthDays[4];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }

    }

    if(month == 6)
    {
        printf("\n\n---------------%s %d------------------\n","June", year);
        dayIndex = dayNumber(1, 6, year);
        days = monthDays[5];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 7)
    {
        printf("\n\n---------------%s %d------------------\n","July", year);
        dayIndex = dayNumber(1, 7, year);
        days = monthDays[6];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 8)
    {
        printf("\n\n---------------%s %d------------------\n","August", year);
        dayIndex = dayNumber(1, 8, year);
        days = monthDays[7];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 9)
    {
        printf("\n\n---------------%s %d------------------\n","September",year);
        dayIndex = dayNumber(1, 9, year);
        days = monthDays[8];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 10)
    {
        printf("\n\n---------------%s %d------------------\n","October",year);
        dayIndex = dayNumber(1, 10, year);
        days = monthDays[9];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 11)
    {
        printf("\n\n---------------%s %d------------------\n","November", year);
        dayIndex = dayNumber(1, 11, year);
        days = monthDays[10];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }

    if(month == 12)
    {
        printf("\n\n---------------%s %d------------------\n","December",year);
        dayIndex = dayNumber(1, 12, year);
        days = monthDays[11];

        printf("   Su   Mo   Tu   We   Th   Fr   Sa \n");

        for (i = 0; i < dayIndex; i++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++i > 6)
            {
                i = 0;
                printf("\n");
            }
        }
    }
}








