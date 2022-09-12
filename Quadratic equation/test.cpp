#include "test.hpp"

void test() {
    double a = NAN, b = NAN, c = NAN, x_1 = NAN, x_2 = NAN;
    NUM_ROOTS num_roots = ZERO;

    for (int i = 0; i < 29; i++) {
        FILE *ret = freopen("data.txt", "r", stdin);
        assert(ret);

        input(&a, &b, &c);
        fclose(ret);

        ret = freopen("answer.txt", "w", stdout);
        assert(ret);

        num_roots = solve(a, b, c, &x_1, &x_2);
        output(x_1, x_2, num_roots);
        fclose(ret);

        char ans_p[MAX_LEN_OF_OUT_STR] = {};
        char ans_t[MAX_LEN_OF_OUT_STR] = {};

        FILE *answer_p = fopen("answer.txt", "r");
        assert(answer_p);

        int input = fscanf(answer_p, "%s", ans_p);
        assert(input = 1);

        fclose(answer_p);

        FILE *answer_t = fopen("answers.txt", "r");
        assert(answer_t);

        input = fscanf(answer_t, "%s", ans_t);
        assert(input = 1);

        fclose(answer_t);

        freopen("/dev/tty", "a", stdout);
        
        int res = strcmp(ans_p, ans_t);
        if (res == 0)
            printf("Passed\n");
        else
            printf("Not passed\n");
    }
}