import java.util.*;

public class Matrix {


    static void inMat(int[][] mat,int rows, int cols) {
        Scanner sc = new Scanner(System.in);
        int ele;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("Enter the element : ");
                ele = sc.nextInt();
                mat[i][j]=ele;
            }
        }
        System.out.println("Matrix has been recorded successfully.\n");
    }

    static void printMat(int[][] mat, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(mat[i][j] + "\t");
            }
            System.out.println("");
        }
        System.out.println("");
    }

    static void multMats(int[][] a,int row1, int col1,int[][] b, int row2, int col2,int[][] c) {
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col2; j++) {
                for (int k = 0; k < row2; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    static void addMats(int[][] a,int row1, int col1,int[][] b, int row2, int col2,int[][] c) {
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++){
                c[i][j]=a[i][j] + b[i][j];
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        //Entering the elements of the first matrix
        System.out.println("Enter the number of rows of first matrix : ");
        int row1 = sc.nextInt();
        System.out.println("Enter the number of columns of first matrix : ");
        int col1 = sc.nextInt();
        int[][] a = new int[row1][col1];
        inMat(a, row1, col1); //putting it into the first nested array
        printMat(a, row1, col1); //printing the first nested array

        //Entering the elements of the second matrix
        System.out.println("Enter the number of rows of second matrix : ");
        int row2 = sc.nextInt();
        System.out.println("Enter the number of rows of second matrix : ");
        int col2 = sc.nextInt();
        int[][] b = new int[row2][col2];
        inMat(b, row2, col2); //putting it into the second nested array
        printMat(b, row2, col2); //printing the second nested array
        sc.close();
        
        int[][] c = new int[row1][col2];

        //using a check to see if matrix multiplication is possible.
        if(col1==row2){
            multMats(a,row1, col1,b, row2, col2,c);//multiplying both the matrices
        
            System.out.println("The resultant matrix is : ");
            printMat(c, row1, col2);//printing the resultant array
        }
        else{
            System.out.println("Multiplication of these matrices is not possible.");
        }

        if(row1==row2 && col1==col2){
            addMats(a,row1, col1,b, row2, col2,c);
            System.out.println("After Matrix Addition : ");
            printMat(c, row2, col2);
        }
        else{
            System.out.println("These matrices cannot be added.");
        }

}
}
