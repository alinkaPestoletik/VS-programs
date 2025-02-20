/*
 * author Alina Pestova DSAI-5
 * I used the implementation of sort algorithm from the first lab
 * I used the idea of the implementation of dynamic programming from tutorial 5
 */

import java.util.Scanner;

public class JobScheduling {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        
        int[] startTime = new int[N];
        int[] finishTime = new int[N];
        int[] profit = new int[N];
        
        for (int i = 0; i < N; i++) {
            startTime[i] = scanner.nextInt();
        }
 
        for (int i = 0; i < N; i++) {
            finishTime[i] = scanner.nextInt();
        }
 
        for (int i = 0; i < N; i++) {
            profit[i] = scanner.nextInt();
        }
        
        Job[] jobs = new Job[N];
        for (int i = 0; i < N; i++) {
            jobs[i] = new Job(startTime[i], finishTime[i], profit[i]);
        }
 
        AlinkaSelectionSort(jobs);
        
        int[] maxProfit = new int[N];
        maxProfit[0] = jobs[0].profit; 

        for (int i = 1; i < N; i++) {
            int getProfit = jobs[i].profit;
            int nonOverlapping = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (jobs[j].finish <= jobs[i].start) {
                    nonOverlapping = j;
                    break;
                }
            }

            if (nonOverlapping != -1) {
                getProfit += maxProfit[nonOverlapping];
            }

            maxProfit[i] = Math.max(getProfit, maxProfit[i - 1]);
        }
        
        System.out.println(maxProfit[N - 1]);
        
        scanner.close();
    }

    private static void AlinkaSelectionSort(Job[] jobs) {
        int n = jobs.length;
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (jobs[j].finish < jobs[min].finish) {
                    min = j;
                }
            }
            Job temp = jobs[i];
            jobs[i] = jobs[min];
            jobs[min] = temp;
        }
    }
}

class Job {
    int start;
    int finish;
    int profit;

    Job(int start, int finish, int profit) {
        this.start = start;
        this.finish = finish;
        this.profit = profit;
    }
}


