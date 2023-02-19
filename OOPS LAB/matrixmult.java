import java.util.*;

public class matrixmult {
    public static void main(String[] args) {
        int row1, row2, col1, col2,currsum=0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows in the first matrix : ");
        row1 = sc.nextInt();
        System.out.println("Enter the number of columns in the first matrix : ");
        col1 = sc.nextInt();
        System.out.println("Enter the number of rows in the second matrix : ");
        row2 = sc.nextInt();
        System.out.println("Enter the number of columns in the second matrix : ");
        col2 = sc.nextInt();
        if (col1 != row2) {
            System.out.println("Matrix Multiplication is not possible.");
            return;
        } else {
            int A[][] = new int[row1][col1];
            int B[][] = new int[row2][col2];
            int C[][] = new int[row1][col2];

            System.out.println("Input the values of the first Matrix : ");
            for (int i = 0; i < row1; i++) {
                for (int j = 0; j < col1; j++) {
                    System.out.println("Enter the element of the matrix at ("+i+","+j+") position : ");
                    A[i][j]=sc.nextInt();
                }
            }
            
            System.out.println("Input the values of the second Matrix : ");
            for (int i = 0; i < row2; i++) {
                for (int j = 0; j < col2; j++) {
                    System.out.println("Enter the element of the matrix at ("+i+","+j+") position : ");
                    B[i][j]=sc.nextInt();
                }
            }

            for(int i = 0; i<row1; i++){
                for(int j = 0;j<col2;j++){
                    C[i][j]=0;
                    for(int k =0;k<col1;k++){
                        C[i][j]+=A[i][k]*B[k][j];
                    }
                }
            }
        }
    }
}
