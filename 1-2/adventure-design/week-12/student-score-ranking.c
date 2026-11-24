#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 2

struct student {
    char nameS[40];
    int kor, eng;
    long sum;
    float avg;
    int rank;
};

typedef struct student dongSW;
typedef int Busan;

int main() {
    int a4;
    a4 = 4.5;

    Busan oo, xx;
    oo = 4.5;
    xx = 4;

    dongSW kk = {"홍길동", 100, 100, 200, 100};
    dongSW x, *y, z[SIZE];
    y = &x;

    strcpy(x.nameS, "홍길동");
    x.kor = 100;
    x.eng = 100;
    x.sum = 200;
    x.avg = 100;

    printf("%s %d\n\n", x.nameS, x.kor);
    printf("%d %d\n\n", (*y).kor, y -> kor);

    dongSW st[SIZE];
    int i = 0, j = 0;
    
    srand(time(NULL));
    printf("순위 이름 국어 영어 총점 평균\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < 6; j++) {
            st[i].nameS[j] = rand() % 26 + 65;
        }

        st[i].nameS[6] = '\0';
        st[i].kor = rand() % 101;
        st[i].eng = rand() % 101;
        st[i].sum = st[i].kor + st[i].eng;
        
        if (st[i].sum == 0) {
            st[i].avg = 0.0;
        } else {
            st[i].avg = st[i].sum / 2.0;
        }
        
    }

    for (i = 0; i < SIZE; i++) {
        st[i].rank = 1;
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (st[j].sum > st[i].sum) {
                st[i].rank++;
            }
        }
    }

    struct student temp;
    /* 총점 오름차순 순차 정렬 */
    for (i = 0; i < SIZE; i++) {
        for (j = i+1; j < SIZE; j++) {
            if (st[i].sum > st[j].sum) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        printf("%3d %s %3d %3d %3ld %5.2f\n", st[i].rank, st[i].nameS, st[i].kor, st[i].eng, st[i].sum, st[i].avg);
    }

    putchar('\n');

    /* 총점 내림차순 버블 정렬 */
    for (i = 0; i < SIZE-1; i++) {
        for (j = 0; j < SIZE-i-1; j++) {
            if (st[j].sum < st[j+1].sum) {
                temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        printf("%3d %s %3d %3d %3ld %5.2f\n", st[i].rank, st[i].nameS, st[i].kor, st[i].eng, st[i].sum, st[i].avg);
    }

    putchar('\n');

    /* 이름 오름차순 순차 정렬 */
    for (i = 0; i < SIZE; i++) {
        for (j = i+1; j < SIZE; j++) {
            if (strcmp(st[i].nameS, st[j].nameS) > 0) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        printf("%3d %s %3d %3d %3ld %5.2f\n", st[i].rank, st[i].nameS, st[i].kor, st[i].eng, st[i].sum, st[i].avg);
    }

    putchar('\n');

    /* 이름 내림차순 버블 정렬 */
    for (i = 0; i < SIZE-1; i++) {
        for (j = 0; j < SIZE-i-1; j++) {
            if (strcmp(st[j].nameS, st[j+1].nameS) < 0) {
                temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        printf("%3d %s %3d %3d %3ld %5.2f\n", st[i].rank, st[i].nameS, st[i].kor, st[i].eng, st[i].sum, st[i].avg);
    }

    return 0;
}
