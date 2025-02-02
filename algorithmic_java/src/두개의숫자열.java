import java.util.Scanner;
import java.io.FileInputStream;

public class 두개의숫자열 {
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            int N, M;
            N = sc.nextInt();
            M = sc.nextInt();
            int[] A = new int[N];
            int[] B = new int[M];

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextInt();
            }

            for (int i = 0; i < M; i++) {
                B[i] = sc.nextInt();
            }

            int[] long_arr;
            int[] short_arr;
            if(N<M)
            {
                long_arr = B;
                short_arr = A;
            }
            else
            {
                long_arr = A;
                short_arr = B;
            }
            
            int l_len = long_arr.length;
            int s_len = short_arr.length;

            int answer = 0;
            for (int l = 0; l < s_len; l++)
                answer += long_arr[l] * short_arr[l];
            
            for (int i = 1; i < l_len - s_len + 1; i++)
            {
                int sum = 0;
                for (int l = 0; l < s_len; l++)
                    sum += long_arr[i + l] * short_arr[l];
                if(sum > answer)
                    answer = sum;
            }

            System.out.println(String.format("#%s %s", test_case, answer));
        }

        sc.close();
        return;
    }
}

