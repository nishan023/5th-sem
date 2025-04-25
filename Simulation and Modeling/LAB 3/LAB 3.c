#include <stdio.h>

// Function to compute probability using Markov Chain
double compute_no_rain_probability(int days)
{
    // Transition probabilities
    double P_rain_tomorrow_if_rain_today = 0.4;
    double P_no_rain_tomorrow_if_rain_today = 0.6;
    double P_rain_tomorrow_if_no_rain_today = 0.2;
    double P_no_rain_tomorrow_if_no_rain_today = 0.8;

    // Initial state: User inputs today's weather
    int today_rain;
    printf("Enter today's weather (1 for rain, 0 for no rain): ");
    scanf("%d", &today_rain);

    double P_no_rain_next_day;
    double P_no_rain_after_next_day;

    if (today_rain)
    {
        P_no_rain_next_day = P_no_rain_tomorrow_if_rain_today;
    }
    else
    {
        P_no_rain_next_day = P_no_rain_tomorrow_if_no_rain_today;
    }

    P_no_rain_after_next_day = (P_no_rain_next_day * P_no_rain_tomorrow_if_rain_today) +
                               ((1 - P_no_rain_next_day) * P_no_rain_tomorrow_if_no_rain_today);

    return P_no_rain_after_next_day;
}

int main()
{
    printf("\t****NISHAN DHAKAL****\n\n  ");
    int days = 2;
    double result = compute_no_rain_probability(days);

    printf("\nProbability of NO rain the day after tomorrow: %.2f%%\n", result * 100);

    return 0;
}
