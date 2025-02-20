/*
 * author Alina Pestova DSAI-5
 */

import java.util.Scanner;

public class MinimumCostPath {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[][] cost = new int[n][m];
        int[][] minCost = new int[n][m];
        int[][] path = new int[n][m]; 

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                cost[i][j] = scanner.nextInt();
            }
        }

        minCost[0][0] = cost[0][0];

        for (int j = 1; j < m; j++) {
            minCost[0][j] = minCost[0][j - 1] + cost[0][j];
            path[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            minCost[i][0] = minCost[i - 1][0] + cost[i][0];
            path[i][0] = 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (minCost[i - 1][j] < minCost[i][j - 1]) {
                    minCost[i][j] = minCost[i - 1][j] + cost[i][j];
                    path[i][j] = 0;
                } else {
                    minCost[i][j] = minCost[i][j - 1] + cost[i][j];
                    path[i][j] = 1;
                }
            }
        }

        System.out.println(minCost[n - 1][m - 1]);

        String pathCosts = "";
        int i = n - 1;
        int j = m - 1;

        while (i > 0 || j > 0) {
            pathCosts = String.format("%d ", cost[i][j]) + pathCosts; 
            switch (path[i][j]) {
                case 0:
                    i--;
                    break;
                case 1:
                    j--;
                    break;
            }
        }
        pathCosts = String.format("%d ", cost[0][0]) + pathCosts; 
        System.out.println(pathCosts.trim());

        scanner.close();
    }
}