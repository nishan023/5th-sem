#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

// Comparator function to sort jobs based on profit in descending order
int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;  // Sort by profit
}

// Function to find the maximum profit job sequence
void jobSequencing(Job jobs[], int n) {
    // Sort jobs based on profit
    qsort(jobs, n, sizeof(Job), compare);

    int result[n];  // To store the job sequence
    int slot[n];    // To keep track of free slots

    // Initialize all slots as empty
    for (int i = 0; i < n; i++) {
        slot[i] = -1;
    }

    // Loop through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;  // Assign this job to this slot
                break;
            }
        }
    }

    // Print the job sequence and profit
    printf("Job Sequence:\n");
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i] != -1) {
            printf("Job %d (Profit: %d)\n", jobs[slot[i]].id, jobs[slot[i]].profit);
            totalProfit += jobs[slot[i]].profit;
        }
    }
    
    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("\n\t****NISHAN DHAKAL****\n      **** Job Sequencing with Deadline ****\n\n");

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];

    // Input jobs: job id, deadline, and profit
    for (int i = 0; i < n; i++) {
        printf("Enter job %d (ID, Deadline, Profit): ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
