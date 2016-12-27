#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
    _Bool line = 0;
    Queue line1;
    Queue line2;
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaways = 0;
    double min_per_cust;
    long line1_customers = 0;
    long line1_served = 0;
    long line1_sum = 0;
    int line1_wait_time = 0;
    long line1_wait = 0;

    long line2_customers = 0;
    long line2_served = 0;
    long line2_sum = 0;
    int line2_wait_time = 0;
    long line2_wait = 0;

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int)time(0));
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (!QueueIsFull(&line1) && line1_customers <= line2_customers)
            {
                line1_customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line1);
                line = 0;
            }
            else if (!QueueIsFull(&line2))
            {
                line2_customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line2);
                line = 1;
            }
            else turnaways++;
        }
        if (line == 0 && line1_wait_time <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp, &line1);
            line1_wait_time = temp.processtime;
            line1_wait += cycle - temp.arrive;
            line1_served++;
        }

        if (line == 1 && line2_wait_time <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp, &line2);
            line2_wait_time = temp.processtime;
            line2_wait += cycle - temp.arrive;
            line2_served++;
        }

        if (line1_wait_time > 0)
            line1_wait_time--;
        line1_sum += QueueItemCount(&line1);

        if (line2_wait_time > 0)
            line2_wait_time--;
        line2_sum += QueueItemCount(&line2);
    }

    if (line1_customers > 0)
    {
        puts("Line1:");
        printf("customers accepted: %ld\n", line1_customers);
        printf("  customers served: %ld\n", line1_served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double)line1_sum / cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double)line1_wait / line1_served);
    }
    else
        puts("No customers!");
    if (line2_customers > 0)
    {
        puts("Line2:");
        printf("customers accepted: %ld\n", line2_customers);
        printf("  customers served: %ld\n", line2_served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double)line2_sum / cyclelimit);
        printf(" average wait time: %.2f  minutes\n",
               (double)line2_wait / line2_served);
    }
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}

bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}