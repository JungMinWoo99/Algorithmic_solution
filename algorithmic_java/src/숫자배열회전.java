import java.util.Scanner;
import java.io.FileInputStream;

public class 숫자배열회전{

    public static int[][] rotate90(int[][] input)
    {
        int N = input.length;
        int[][] ret = new int[N][N];

        double half = (N-1)/2.0;
        for (int i = 0; i < N; i++)
        {
            for(int l = 0; l < N; l++)
            {
                double x = (double)l - half;
                double y = (double)i - half;
                double rotated_x = y + half;
                double rotated_y = -x + half;
                ret[i][l] = input[(int)rotated_y][(int)rotated_x];
            }
        }

        return ret;
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            System.out.printf("#%d\n",test_case);
            int N;
            N = sc.nextInt();
            int[][] input = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int l = 0; l < N; l++) {
                    input[i][l] = sc.nextInt();
                }
            }
            
            int [][][] answer = new int[3][N][N];
            answer[0] = rotate90(input);
            answer[1]  = rotate90(answer[0]);
            answer[2]  = rotate90(answer[1]);
            for (int i = 0; i < N; i++) {
                for(int k = 0 ;k<3;k++)
                {
                    for (int l = 0; l < N; l++) {
                        System.out.printf("%d",answer[k][i][l]);
                    }
                    System.out.printf(" ");
                }
                System.out.println();
            }
        }

        sc.close();
        return;
    }
}
