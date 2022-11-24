import java.lang.*;
import java.util.*;
//2 2 0 0 1 1 0 0 0
public class Lab2 {
    static int score = 0;

    static void ran_move(int r[], int c) {
        if (r[4] == 0) {
            r[4] = c;
            score = 10;

        } else if (r[0] == 0) {

            r[0] = c;
            score = 5;
        } else if (r[2] == 0) {

            r[2] = c;
            score = 5;

        } else if (r[6] == 0) {

            r[6] = c;
            score = 5;

        } else if (r[8] == 0) {

            r[8] = c;
            score = 5;

        } else if (r[1] == 0) {

            r[1] = c;
            score = 1;

        } else if (r[3] == 0) {

            r[3] = c;
            score = 1;

        } else if (r[5] == 0) {

            r[5] = c;
            score = 1;

        } else if (r[7] == 0) {

            r[7] = c;
            score = 1;

        }
        System.out.println("This is random move with score: " + score + "\n");
        printArr(r);
    }

    static void printArr(int arr[]) {
        for (int a = 0; a < 3; a++) {
            System.out.print(arr[a] + " ");
        }
        System.out.println();
        for (int a = 3; a < 6; a++) {
            System.out.print(arr[a] + " ");
        }
        System.out.println();
        for (int a = 6; a < 9; a++) {
            System.out.print(arr[a] + " ");
        }
        System.out.println();
    }

    static void print_mat(int matrix[][]) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {

                System.out.print(matrix[i][j] + " ");

            }
            System.out.println();
        }

    }

    static boolean winning(int a[], int i) {
        if ((a[0] == a[1] && a[1] == a[2] && a[0] == i) || (a[3] == a[4] && a[4] == a[5] && a[3] == i)
                || (a[6] == a[7] && a[7] == a[8] && a[6] == i) || (a[0] == a[3] && a[3] == a[6] && a[0] == i)
                || (a[1] == a[4] && a[4] == a[7] && a[1] == i) || (a[2] == a[5] && a[5] == a[8] && a[2] == i)
                || (a[0] == a[4] && a[4] == a[8] && a[0] == i) || (a[2] == a[4] && a[4] == a[6] && a[2] == i))
            return true;
        return false;
    }

    public static void main(String[] args) {
        // blank = 0
        // 'X'=1-> human
        // 'O'=2-> computer

//        int arr[] = new int[9];
        System.out.println("Enter input for tic tac toe\n");
        Scanner sc = new Scanner(System.in);
//        for (int l = 0; l < 9; l++) {
//            arr[l] = sc.nextInt();
//        }

//        int arr[]={0, 1, 0, 1, 1, 0, 2, 2, 1};  // invalid input
        int arr[]={2, 1, 2, 1, 2, 0, 0, 0, 0};  // Blocking move x
//        int arr[]={2, 1, 2, 0, 1, 0, 0, 0, 0};  //Blocking o
//        int arr[]={2, 0, 2, 0, 1, 1, 0, 0, 0};  // Winning Move X
//        int arr[]={0, 0, 2, 0, 1, 0, 0, 0, 0};  // Random move

        System.out.println("Given State");
        printArr(arr);
        System.out.println();

        System.out.println("In this game o will play first");
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < 9; i++) {
            if (arr[i] == 0)
                count0++;
            if (arr[i] == 1)
                count1++;
            if (arr[i] == 2)
                count2++;
        }

        if (count2 - count1 == 0) {
            System.out.println("Its o chance to play ");
            int[][] matrix = new int[count0][9];
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {
                    matrix[i][j] = arr[j];
                }
            }

            System.out.println();
            System.out.println("After Copying the array in " + count0 + "x9 matrix");

            print_mat(matrix);

            int j = 0;
            for (int i = 0; i < 9; i++) {
                if (arr[i] == 0) {
                    matrix[j][i] = 2;
                    j++;
                }

            }
            System.out.println();
            System.out.println("After playing a chance in every possible blocks");
            print_mat(matrix);

            System.out.println();
            for (int i = 0; i < count0; i++) {
                if (winning(matrix[i], 2)) {
                    score = 100;
                    System.out.println("o has winning move");
                    printArr(matrix[i]);
                    System.out.println("Score for winning is : " + score);
                    System.exit(0);
                }
            }

            int[][] matrix_2 = new int[count0][9];
            for (int i = 0; i < matrix_2.length; i++) {
                for (int k = 0; k < matrix_2[0].length; k++) {
                    matrix_2[i][k] = arr[k];
                }
            }

            j = 0;
            for (int i = 0; i < 9; i++) {
                if (arr[i] == 0) {
                    matrix_2[j][i] = 1;
                    j++;
                }

            }
            for (int i = 0; i < count0; i++) {
                if (winning(matrix_2[i], 1)) {
                    score = 50;
                    System.out.println("o has blocking move");
                    printArr(matrix[i]);
                    System.out.println("Score for blocking is: " + score);
                    System.exit(0);
                }
            }

            ran_move(arr, 2);

        }

        else if (count2 - count1 == 1) {
            System.out.println("Its X chance to play ");
            int[][] matrix = new int[count0][9];
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {
                    matrix[i][j] = arr[j];
                }
            }
            System.out.println();
            System.out.println("After Copying the array in " + count0 + "x9 matrix");
            print_mat(matrix);
            int j = 0;
            for (int i = 0; i < 9; i++) {
                if (arr[i] == 0) {
                    matrix[j][i] = 1;
                    j++;
                }

            }
            System.out.println();
            System.out.println("After playing a chance in every possible blocks");
            print_mat(matrix);

            System.out.println();
            System.out.println();
            for (int i = 0; i < count0; i++) {
                if (winning(matrix[i], 1)) {
                    score = 100;
                    System.out.println("x has winning move");
                    printArr(matrix[i]);
                    System.out.println("Score for winning is: " + score);
                    System.exit(0);
                }
            }

            int[][] matrix_2 = new int[count0][9];
            for (int i = 0; i < matrix_2.length; i++) {
                for (int k = 0; k < matrix_2[0].length; k++) {
                    matrix_2[i][k] = arr[k];
                }
            }

            j = 0;
            for (int i = 0; i < 9; i++) {
                if (arr[i] == 0) {
                    matrix_2[j][i] = 2;
                    j++;
                }

            }
            for (int i = 0; i < count0; i++) {
                if (winning(matrix_2[i], 2)) {
                    score = 50;
                    System.out.println("x has blocking move");
                    printArr(matrix[i]);
                    System.out.println("Score for blocking is: " + score);
                    System.exit(0);
                }
            }
            ran_move(arr, 1);
        }

        else {
            System.out.println("Invalid input");
        }

    }
}