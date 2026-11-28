/*
    작성자 : 최원준
    최초 작성일 : 2026.11.16.
    최종 작성일 : 2026.11.27.
    개발 환경 : Visual Studio Code 1.147
    컴파일러 : GCC 16.2.0 (MinGW-w64 / WinLibs UCRT 64-bit)
    문법 표준 : C11
    소스 인코딩 : UTF-8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* ---------- 상수 정의 ---------- */
#define MAX_PEOPLE 8                /* 최대 참가자 수 */
#define DAYS_PER_WEEK 7             /* 요일 수 (요일 이름 배열과 일치) */
#define START_HOUR 9                /* 시작 시간 */
#define END_HOUR 21                 /* 끝 시간 */
#define TIME_SLOTS_PER_DAY (END_HOUR - START_HOUR) /* 하루에 관리할 1시간 단위 시간대 수 */
#define NAME_LEN 64                 /* 이름 버퍼 크기 (안내 문구는 63바이트 기준) */
#define INPUT_LEN 128               /* 한 줄 입력 버퍼 크기 (입력 형식은 128 기준) */
#define PREFERENCE_SCALE 10         /* 선호도 저장 단위 (소수 입력은 10 기준) */
#define MAX_CANDIDATES (DAYS_PER_WEEK * TIME_SLOTS_PER_DAY) /* 1시간 약속의 최대 후보 수 */
#define MAX_RECOMMENDATIONS 3       /* 화면에 표시할 최대 추천 수 */

/* ---------- 구조체 정의 ---------- */
/* 참가자 한 명의 정보 */
typedef struct {
    int id;                                                  /* 참가자 고유 번호 */
    int is_registered;                                       /* 등록 여부 (1: 등록, 0: 미등록) */
    int available[DAYS_PER_WEEK][TIME_SLOTS_PER_DAY];        /* 요일·시간대별 참석 가능 여부 */
    int preference[DAYS_PER_WEEK][TIME_SLOTS_PER_DAY];       /* 시간대별 선호도 (0.1점 단위) */
    char name[NAME_LEN];                                     /* 참가자 이름 */
} participant;

/* 사용자가 선택한 약속 검색 조건 */
typedef struct {
    int duration;            /* 약속 소요 시간 */
    int min_attendees;       /* 검색에 필요한 최소 참석 인원 */
} meeting_conditions;

/* 검색된 약속 후보 한 건의 정보 */
typedef struct {
    int day;                         /* 요일 인덱스 */
    int start_hour;                  /* 약속 시작 시각 */
    int end_hour;                    /* 약속 종료 시각 */
    int attendee_count;              /* 참석 가능한 인원 */
    char attending[MAX_PEOPLE];      /* participants 배열의 같은 인덱스에 해당하는 참석 여부 */
    float attendance_rate;           /* 전체 참가자 중 참석 비율 */
    double average_preference;       /* 참석 가능한 참가자의 평균 선호도 */
} result;

/* ---------- 전역 변수 정의 ---------- */
const char *const days[DAYS_PER_WEEK] = {"월", "화", "수", "목", "금", "토", "일"};
int results_valid = 0; /* 현재 참가자와 시간표에 맞는 검색 결과인지 표시 */
result results[MAX_CANDIDATES]; /* 검색한 약속 시간 후보 */
int result_count = 0; /* 저장된 후보 수 */
int results_active_count = 0; /* 검색 당시 등록된 참가자 수 */

/* ---------- 함수 선언 ---------- */
/* 메뉴와 주요 기능 */
int print_menu(void);
void register_participant(participant participants[], int *used_slot_count, int *deleted_participant_count);
void list_participants(participant participants[], int used_slot_count, int deleted_participant_count);
void find_participant(participant participants[], int used_slot_count);
void delete_participant(participant participants[], int used_slot_count, int *deleted_participant_count);
void input_schedule(participant participants[], int count, int is_update);
void update_schedule(participant participants[], int count);
void print_schedule(participant participants[], int count);
void search_times(participant participants[], int count, int active_count);
void print_recommendations(void);
void print_result_details(participant participants[], int count);

/* 입력과 검색·추천을 위한 보조 함수 */
int read_input_line(char input[INPUT_LEN]);
int read_name(char name[NAME_LEN]);
int read_int(int min, int max, int *value);
int read_preference(int *preference);
int is_available(const int availability[], int time_slot, int duration);
double calculate_preference(int preference_total, int duration, int attendee_count);
void sort_results(void);
void invalidate_results(void);

/* ---------- 메인 함수 ---------- */
int main(void) {
    participant participants[MAX_PEOPLE] = {0};
    int used_slot_count = 0; /* 한 번이라도 사용한 배열 칸 수 */
    int deleted_participant_count = 0; /* 사용한 칸 중 현재 비어 있는 칸 수 */

    while (1) {
        int menu = print_menu();
        switch (menu) {

        case 1: /* 참가자 등록 */
            register_participant(participants, &used_slot_count, &deleted_participant_count);
            break;

        case 2: /* 참가자 목록 조회 */
            list_participants(participants, used_slot_count, deleted_participant_count);
            break;

        case 3: /* 참가자 검색 */
            find_participant(participants, used_slot_count);
            break;

        case 4: /* 참가자 삭제 */
            delete_participant(participants, used_slot_count, &deleted_participant_count);
            break;

        case 5: /* 가능 시간 및 선호도 입력 */
            if (used_slot_count - deleted_participant_count == 0) {
                printf("[Error] 등록된 참가자가 없습니다.\n");
                break;
            }
            input_schedule(participants, used_slot_count, 0);
            break;

        case 6:  /* 시간표 조회 및 수정 */
            {    
                int choice;

                if (used_slot_count - deleted_participant_count == 0) {
                    printf("[Error] 등록된 참가자가 없습니다.\n");
                    break;
                }

                printf("1. 조회  2. 수정 > ");
                if (!read_int(1, 2, &choice)) {
                    printf("[Error] 1 또는 2를 입력하세요.\n");
                    break;
                }

                if (choice == 1) {
                    print_schedule(participants, used_slot_count);
                } else {
                    update_schedule(participants, used_slot_count);
                }

                break;
            }

        case 7: /* 공통 가능 시간 검색 */
            search_times(participants, used_slot_count, used_slot_count - deleted_participant_count);
            break;

        case 8: /* 최적 약속 시간 추천 */
            print_recommendations();
            break;

        case 9: /* 추천 결과 상세 조회 */
            print_result_details(participants, used_slot_count);
            break;

        case 0: /* 프로그램 종료 */
            printf("프로그램을 종료합니다.\n");
            return 0;

        default: /* 예외 처리 */
            printf("올바른 메뉴 번호를 입력하세요.\n");
            break;
        }
    }
}

/* ---------- 메뉴와 주요 기능 ---------- */
int print_menu(void) {
    int choice;

    printf("====== 약속ZIP ======\n");
    printf("1. 참가자 등록\n");
    printf("2. 참가자 목록 조회\n");
    printf("3. 참가자 검색\n");
    printf("4. 참가자 삭제\n");
    printf("5. 가능 시간 및 선호도 입력\n");
    printf("6. 시간표 조회 및 수정\n");
    printf("7. 공통 가능 시간 검색\n");
    printf("8. 최적 약속 시간 추천\n");
    printf("9. 추천 결과 상세 조회\n");
    printf("0. 종료\n");
    printf("선택 > ");
    if (!read_int(0, 9, &choice)) {
        /* 입력 종료 또는 오류 시 종료 메뉴로 이동 */
        if (feof(stdin) || ferror(stdin)) {
            return 0;
        }
        /* 잘못된 메뉴 번호는 main의 default에서 처리 */
        return -1;
    }

    return choice;
}

/* 사용자 등록 */
void register_participant(participant participants[], int *used_slot_count, int *deleted_participant_count) {
    char name[NAME_LEN];
    static int next_id = 1;
    int slot = -1;
    participant empty = {0};

    if (*used_slot_count - *deleted_participant_count >= MAX_PEOPLE) {
        printf("[Error] 최대 인원 초과\n");
        return;
    }

    printf("등록할 참가자 이름 > ");
    if (!read_name(name)) {
        printf("[Error] 이름은 공백 없이 63바이트 이하로 입력하세요.\n");
        return;
    }

    for (int i = 0; i < *used_slot_count; i++) {
        if (participants[i].is_registered == 1 && strcmp(participants[i].name, name) == 0) {
            printf("[Error] 이미 등록된 이름입니다.\n");
            return;
        }
    }

    /* 삭제된 칸 우선 재사용 */
    for (int i = 0; i < *used_slot_count; i++) {
        if (participants[i].is_registered == 0) {
            slot = i;
            break;
        }
    }

    if (slot == -1) {
        /* 빈 칸이 없을 때 배열 범위 확장 */
        slot = *used_slot_count;
        (*used_slot_count)++;
    } else {
        (*deleted_participant_count)--;
    }
    participants[slot] = empty;

    strcpy(participants[slot].name, name);
    participants[slot].id = next_id;
    next_id++;
    participants[slot].is_registered = 1;
    invalidate_results();

    printf("%s님을 등록했습니다.\n", name);
}

/* 사용자 목록 */
void list_participants(participant participants[], int used_slot_count, int deleted_participant_count) {
    int active_count = used_slot_count - deleted_participant_count;
    int last_id = 0;

    printf("====== 참가자 목록 (%d명) ======\n", active_count);
    if (active_count == 0) {
        printf("등록된 참가자가 없습니다.\n");
        return;
    }

    /* 배열 순서와 ID 순서가 다를 수 있음 */
    for (int number = 1; number <= active_count; number++) {
        int selected = -1;

        for (int i = 0; i < used_slot_count; i++) {
            if (participants[i].is_registered == 1 && participants[i].id > last_id) {
                if (selected == -1 || participants[i].id < participants[selected].id) {
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            break;
        }

        printf("%d. %s\n", number, participants[selected].name);
        last_id = participants[selected].id;
    }
}

/* 사용자 이름 검색 */
void find_participant(participant participants[], int used_slot_count) {
    char name[NAME_LEN];

    printf("검색할 이름 > ");
    if (!read_name(name)) {
        printf("[Error] 이름은 공백 없이 63바이트 이하로 입력하세요.\n");
        return;
    }

    for (int i = 0; i < used_slot_count; i++) {
        if (participants[i].is_registered == 1 && strcmp(participants[i].name, name) == 0) {
            printf("\n===== 참가자 검색 결과 =====\n");
            printf("참가자 ID : %04d\n", participants[i].id);
            printf("참가자 이름 : %s\n", participants[i].name);
            printf("등록 상태   : 등록됨\n");
            printf("===========================\n");
            return;
        }
    }

    printf("[Error] '%s'님은 등록되지 않았습니다.\n", name);
}

/* 사용자 삭제 */
void delete_participant(participant participants[], int used_slot_count, int *deleted_participant_count) {
    char name[NAME_LEN];
    char input[INPUT_LEN];

    printf("삭제할 이름 > ");
    if (!read_name(name)) {
        printf("[Error] 이름은 공백 없이 63바이트 이하로 입력하세요.\n");
        return;
    }

    for (int i = 0; i < used_slot_count; i++) {
        if (participants[i].is_registered == 1 && strcmp(participants[i].name, name) == 0) {
            printf("정말로 삭제하시겠습니까? (Y/N) > ");
            
            if (!read_input_line(input) || input[1] != '\0') {
                printf("[Error] Y 또는 N을 입력하세요.\n");
                return;
            }

            int is_agree = toupper((unsigned char)input[0]);
            
            if (is_agree == 'Y') {
                int deleted_id = participants[i].id;
                participant empty = {0};
                participants[i] = empty;
                participants[i].id = deleted_id;
                strcpy(participants[i].name, "<삭제된 사용자>");
                (*deleted_participant_count)++;
                invalidate_results();
                printf("삭제를 완료하였습니다.\n");
            } else if (is_agree == 'N') {
                printf("사용자 삭제를 취소합니다.\n");
            } else {
                printf("[Error] Y 또는 N을 입력하세요.\n");
            }

            return;
        }
    }

    printf("[Error] 등록되지 않은 참가자입니다.\n");
}

/* 시간표 입력 */
void input_schedule(participant participants[], int count, int is_update) {
    char name[NAME_LEN];
    int day, time_slot, available;
    int preference = 0;

    printf("참가자 이름 > ");
    if (!read_name(name)) {
        printf("[Error] 이름은 공백 없이 63바이트 이하로 입력하세요.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (participants[i].is_registered == 1 && strcmp(participants[i].name, name) == 0) {
            printf("요일 (1: 월 ~ 7: 일) > ");
            if (!read_int(1, DAYS_PER_WEEK, &day)) {
                printf("[Error] 1~7 사이의 요일을 입력하세요.\n");
                return;
            }

            printf("시작 시간 (%d~%d시) > ", START_HOUR, END_HOUR - 1);
            if (!read_int(START_HOUR, END_HOUR - 1, &time_slot)) {
                printf("[Error] %d~%d 사이의 시간을 입력하세요.\n", START_HOUR, END_HOUR - 1);
                return;
            }

            printf("참석 가능 여부 (1: 가능, 0: 불가능) > ");
            if (!read_int(0, 1, &available)) {
                printf("[Error] 0 또는 1을 입력하세요.\n");
                return;
            }

            if (available == 1) {
                printf("선호도 (1.0~5.0) > ");
                if (!read_preference(&preference)) {
                    printf("[Error] 1.0~5.0 사이의 선호도를 0.1점 단위로 입력하세요.\n");
                    return;
                }
            }

            /* 요일·시각을 배열 인덱스로 변환 */
            participants[i].available[day - 1][time_slot - START_HOUR] = available;
            participants[i].preference[day - 1][time_slot - START_HOUR] = preference;

            invalidate_results();

            if (is_update == 1) {
                printf("%s요일 %02d:00~%02d:00 시간표를 수정했습니다.\n", days[day - 1], time_slot, time_slot + 1);
            } else {
                printf("%s요일 %02d:00~%02d:00 시간표를 저장했습니다.\n", days[day - 1], time_slot, time_slot + 1);
            }

            return;
        }
    }

    printf("[Error] '%s'님은 등록되지 않았습니다.\n", name);
}

/* 시간표 수정 */
void update_schedule(participant participants[], int count) {
    printf("수정할 시간표를 입력하세요.\n");
    input_schedule(participants, count, 1);
}

/* 시간표 조회 */
void print_schedule(participant participants[], int count) {
    char name[NAME_LEN];

    printf("참가자 이름 > ");
    if (!read_name(name)) {
        printf("[Error] 이름은 공백 없이 63바이트 이하로 입력하세요.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (participants[i].is_registered == 1 && strcmp(participants[i].name, name) == 0) {
            printf("======== %s 님의 시간표 ========\n", participants[i].name);
            printf("[참고] 설정하지 않은 시간은 불가능으로 표시됩니다.\n");

            for (int day = 0; day < DAYS_PER_WEEK; day++) {
                printf("\n[%s요일]\n", days[day]);

                for (int time_slot = 0; time_slot < TIME_SLOTS_PER_DAY; time_slot++) {
                    printf("%02d:00~%02d:00  ", START_HOUR + time_slot, START_HOUR + time_slot + 1);

                    if (participants[i].available[day][time_slot] == 1) {
                        printf("가능 (%.1f점)\n", (double)participants[i].preference[day][time_slot] / PREFERENCE_SCALE);
                    } else {
                        printf("불가능\n");
                    }
                }
            }

            return;
        }
    }

    printf("[Error] '%s'님은 등록되지 않았습니다.\n", name);
}

/* 최소 참석 인원을 만족하는 시간 검색 */
void search_times(participant participants[], int count, int active_count) {
    meeting_conditions conditions;

    if (active_count == 0) {
        printf("[Error] 등록된 참가자가 없습니다. 참가자를 먼저 등록하세요.\n");
        return;
    }

    printf("약속 소요 시간 (1~%d시간) > ", TIME_SLOTS_PER_DAY);
    if (!read_int(1, TIME_SLOTS_PER_DAY, &conditions.duration)) {
        printf("[Error] 1~%d 사이의 시간을 입력하세요.\n", TIME_SLOTS_PER_DAY);
        return;
    }

    printf("최소 참석 인원 (1~%d명) > ", active_count);
    if (!read_int(1, active_count, &conditions.min_attendees)) {
        printf("[Error] 1~%d 사이의 인원을 입력하세요.\n", active_count);
        return;
    }

    printf("=== 검색 결과 ===\n");

    result_count = 0;
    results_active_count = active_count;
    results_valid = 1; /* 새 검색 결과 유효 표시 */

    for (int day = 0; day < DAYS_PER_WEEK; day++) {
        /* 종료 시간을 넘지 않는 시작 시간만 검사 */
        for (int time_slot = 0; time_slot <= TIME_SLOTS_PER_DAY - conditions.duration; time_slot++) {
            result candidate = {0};
            int preference_total = 0;

            for (int i = 0; i < count; i++) {
                candidate.attending[i] = 'N';
                if (participants[i].is_registered == 1 && is_available(participants[i].available[day], time_slot, conditions.duration)) {
                    candidate.attendee_count++;
                    candidate.attending[i] = 'Y';

                    for (int hour = 0; hour < conditions.duration; hour++) {
                        preference_total += participants[i].preference[day][time_slot + hour];
                    }
                }
            }

            if (candidate.attendee_count >= conditions.min_attendees) {
                /* 최대 후보 수 안에서 결과 저장 */
                candidate.day = day;
                candidate.start_hour = START_HOUR + time_slot;
                candidate.end_hour = candidate.start_hour + conditions.duration;
                candidate.attendance_rate = 100.0f * candidate.attendee_count / active_count;
                candidate.average_preference = calculate_preference(preference_total, conditions.duration, candidate.attendee_count);
                results[result_count] = candidate;
                result_count++;

                printf("%s요일 %02d:00~%02d:00  참석 가능: %d명\n", days[day], candidate.start_hour, candidate.end_hour, candidate.attendee_count);
            }
        }
    }

    if (result_count == 0) {
        printf("조건에 맞는 시간이 없습니다.\n");
    }

    sort_results(); /* 추천 순서로 정렬 */
}

/* 저장된 검색 결과 중 설정한 개수만큼 표시 */
void print_recommendations(void) {
    if (!results_valid) {
        printf("먼저 공통 가능 시간을 검색하세요.\n");
        return;
    }

    if (result_count == 0) {
        printf("추천할 시간이 없습니다.\n");
        return;
    }

    printf("=== 추천 결과 ===\n");

    for (int i = 0; i < result_count && i < MAX_RECOMMENDATIONS; i++) {
        printf("%d위  %s요일 %02d:00~%02d:00  참석: %d명  평균 선호도: %.2f\n", i + 1, days[results[i].day], results[i].start_hour, results[i].end_hour, results[i].attendee_count, results[i].average_preference);
    }
}

/* 선택한 추천 시간의 점수와 참석자 명단을 표시 */
void print_result_details(participant participants[], int count) {
    int rank;

    if (!results_valid || result_count == 0) {
        printf("조회할 추천 결과가 없습니다. 공통 가능 시간을 다시 검색하세요.\n");
        return;
    }

    printf("상세 조회할 순위 > ");

    int max_rank = result_count;

    if (max_rank > MAX_RECOMMENDATIONS) {
        max_rank = MAX_RECOMMENDATIONS;
    }

    if (!read_int(1, max_rank, &rank)) {
        printf("[Error] 표시된 추천 순위를 입력하세요.\n");
        return;
    }

    result selected = results[rank - 1];

    printf("=== %d위 상세 정보 ===\n", rank);
    printf("시간: %s요일 %02d:00~%02d:00\n", days[selected.day], selected.start_hour, selected.end_hour);
    printf("참석: %d명 / %d명 (%.1f%%)\n", selected.attendee_count, results_active_count, selected.attendance_rate);
    printf("평균 선호도: %.2f\n", selected.average_preference);

    /* 참석 가능 여부 순으로 출력 */
    for (int available = 1; available >= 0; available--) {
        int printed = 0;

        if (available == 1) {
            printf("참석 가능: ");
        } else {
            printf("참석 불가능: ");
        }

        for (int i = 0; i < count; i++) {
            if (participants[i].is_registered == 1 && selected.attending[i] == (available == 1 ? 'Y' : 'N')) {
                if (printed == 1) {
                    printf(", ");
                }

                printf("%s", participants[i].name);
                printed = 1;
            }
        }

        if (printed == 0) {
            printf("없음");
        }

        printf("\n");
    }
}

/* ---------- 입력과 검색·추천을 위한 보조 함수 ---------- */
/* 한 줄에서 공백으로 구분된 입력 항목 하나만 읽는다. */
int read_input_line(char input[INPUT_LEN]) {
    char line[INPUT_LEN];
    char extra;

    if (fgets(line, INPUT_LEN, stdin) == NULL) {
        return 0;
    }

    if (strchr(line, '\n') == NULL && !feof(stdin)) {
        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* 긴 줄의 나머지 제거 */
        }

        return 0;
    }

/* 두 번째 항목 입력 여부 확인 */
    return sscanf(line, "%127s %c", input, &extra) == 1;
}

/* 공백 없는 이름과 저장 크기 확인 */
int read_name(char name[NAME_LEN]) {
    char input[INPUT_LEN];

    if (!read_input_line(input) || strlen(input) >= NAME_LEN) {
        return 0;
    }

    strcpy(name, input);

    return 1;
}

/* 한 줄 정수와 범위 확인 */
int read_int(int min, int max, int *value) {
    char input[INPUT_LEN];
    char *end;

    if (!read_input_line(input)) {
        return 0;
    }

    long number = strtol(input, &end, 10);
    /* 변환 범위 초과 시 메뉴·시간 범위 검사에서 제외 */
    if (*end != '\0' || number < min || number > max) {
        return 0;
    }

    *value = (int)number;

    return 1;
}

/* 4.5처럼 입력한 점수를 정수 45로 변환 */
int read_preference(int *preference) {
    char input[INPUT_LEN];
    char *end;

    if (!read_input_line(input)) {
        return 0;
    }

    long whole = strtol(input, &end, 10);
    if (whole < 1 || whole > 5) {
        return 0;
    }

    int score = (int)whole * PREFERENCE_SCALE;
    if (*end != '\0') {
        if (*end != '.' || strlen(end) != 2 || !isdigit((unsigned char)end[1])) {
            return 0;
        }
        score += end[1] - '0';
    }

    if (score > 5 * PREFERENCE_SCALE) {
        return 0;
    }

    *preference = score;

    return 1;
}

/* 약속 시간 전체의 참석 가능 여부 확인 */
int is_available(const int availability[], int time_slot, int duration) {
    /* 약속 시간대 모두 확인 */
    for (int i = 0; i < duration; i++) {
        if (availability[time_slot + i] != 1) {
            return 0;
        }
    }

    return 1;
}

/* 참석자 선호도 평균 계산 */
double calculate_preference(int preference_total, int duration, int attendee_count) {
    return (double)preference_total / (PREFERENCE_SCALE * duration * attendee_count);
}

/* 참석 인원·선호도 순으로 정렬 */
void sort_results(void) {
    for (int last = result_count - 1; last > 0; last--) {
        for (int i = 0; i < last; i++) {
            /* 동점이면 검색한 요일·시간 순서 유지 */
            if (results[i].attendee_count < results[i + 1].attendee_count || (results[i].attendee_count == results[i + 1].attendee_count && results[i].average_preference < results[i + 1].average_preference)) {
                result temp = results[i];
                results[i] = results[i + 1];
                results[i + 1] = temp;
            }
        }
    }
}

/* 참가자·시간표 변경 시 이전 결과 무효화 */
void invalidate_results(void) {
    results_valid = 0;
}