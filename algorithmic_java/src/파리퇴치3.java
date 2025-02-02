import java.util.Scanner;
import java.io.FileInputStream;

public class 파리퇴치3 {
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            int N, M;
            N = sc.nextInt();
            M = sc.nextInt();
            int[][] input = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int l = 0; l < N; l++) {
                    input[i][l] = sc.nextInt();
                }
            }

            int answer = 0;

            for (int i = 0; i < N; i++) {
                for (int l = 0; l < N; l++) {
                    int catched_fly = 0;
                    for (int n = -M + 1; n < M; n++) {
                        if (-1 < i + n && i + n < N)
                            catched_fly += input[i + n][l];
                        if (-1 < l + n && l + n < N)
                            catched_fly += input[i][l + n];
                    }
                    catched_fly -= input[i][l];
                    if (catched_fly > answer)
                        answer = catched_fly;
                    catched_fly = 0;
                    for (int n = -M + 1; n < M; n++) {
                        if (-1 < i + n && i + n < N && -1 < l + n && l + n < N)
                            catched_fly += input[i + n][l + n];
                        if (-1 < i - n && i - n < N && -1 < l + n && l + n < N)
                            catched_fly += input[i - n][l + n];
                    }
                    catched_fly -= input[i][l];
                    if (catched_fly > answer)
                        answer = catched_fly;
                }
            }

            System.out.println(String.format("#%s %s", test_case, answer));
        }

        sc.close();
        return;
    }
}
