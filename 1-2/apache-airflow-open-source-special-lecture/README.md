# PR부터 Merge까지: Apache Airflow 오픈소스에 기여하기

2026년 11월 5일 동아대학교에서 진행된 오픈소스 실전 특강의 학습 내용과 기여 결과를 기록합니다. 강연 자료의 목표는 한국어 UI 번역 한 항목을 수정하고 검증한 뒤 Pull Request(PR)를 제출하는 것이었으며, 병합은 이후 커뮤니티 검토를 거쳐 진행되는 과정으로 설명되었습니다.

## 특강 정보

| 항목 | 내용 |
| :-- | :-- |
| 프로그램 | 2026년 오픈소스 & 개발자 실전 특강 |
| 일시 | 2026년 11월 5일(목) 10:00~12:00 |
| 장소 | 동아대학교 승학캠퍼스 공대5호관 S06-0607호 |
| 주제 | Apache Airflow 한국어 UI 번역 기여와 PR 제출·검토 과정 |
| 강연 | 추영욱 (Apache Airflow 커미터) |

## Apache Airflow와 이번 실습

Apache Airflow는 워크플로를 작성하고, 실행 일정을 관리하며, 실행 상태를 확인하는 플랫폼입니다. 이번 특강에서는 Airflow 자체 기능을 새로 만드는 대신 웹 UI의 한국어 번역을 통해 오픈소스 기여 과정을 연습했습니다.

**i18n(국제화)**은 프로그램이 여러 언어와 지역에 대응할 수 있도록 만드는 작업입니다. Airflow UI에서는 영어가 기준 언어이며, 각 언어의 JSON 파일에 같은 항목의 번역을 저장합니다. 번역할 때는 영어 원문의 의미와 기존 한국어 용어를 함께 확인합니다.

### 1. 작업 환경 준비

강연 자료에서는 GitHub 계정, 코드 편집기, Git, uv와 Docker를 준비하고 다음 명령으로 환경을 확인하도록 안내했습니다.

```bash
git --version
uv --version
docker info
```

`docker info`는 Docker 서버가 실행 중인지 확인하는 용도입니다. 강연의 UI 실행 실습에는 Docker 기반 Breeze 환경을 사용합니다. 번역 파일 편집과 GitHub PR 제출 자체에는 Docker가 필요하지 않습니다.

### 2. Fork, Clone, 브랜치 생성

GitHub에서 [apache/airflow](https://github.com/apache/airflow)를 자신의 계정으로 **Fork**한 뒤, Fork한 저장소를 컴퓨터에 **Clone**합니다. 아래 `<GitHub-사용자명>`은 본인의 계정으로 바꾸며 꺾쇠괄호는 입력하지 않습니다.

```bash
git clone https://github.com/<GitHub-사용자명>/airflow.git
cd airflow
git checkout -b i18n/workshop
git branch --show-current
```

Fork는 자신의 GitHub에 작업용 저장소를 만드는 과정이고, Clone은 그 저장소를 로컬로 내려받는 과정입니다. `i18n/workshop` 브랜치는 이번 변경을 위한 별도 작업 공간입니다. 이후 명령은 별도 설명이 없으면 Clone한 `airflow` 폴더에서 실행합니다.

### 3. 번역할 항목 찾기

Airflow UI의 언어 파일은 다음 경로에 있습니다.

| 경로 | 내용 |
| :-- | :-- |
| `airflow-core/src/airflow/ui/public/i18n/locales/en` | 영어 기준 문구 |
| `airflow-core/src/airflow/ui/public/i18n/locales/ko` | 한국어 번역 |

편집기에서 한국어 폴더를 검색해 `TODO: translate:`로 표시된 항목을 찾거나, 아래의 Breeze 검사로 누락 항목을 확인합니다. 항목이 이미 다른 PR에서 작업 중인지 확인하고 중복 기여를 피합니다. 기존 TODO가 없다고 해서 새 항목을 반드시 생성해야 하는 것은 아닙니다.

번역할 때는 영어 파일에서 같은 키를 찾아 의미를 확인하고 한국어 값을 수정합니다. 키 이름, JSON 문법, 변수와 태그는 보존합니다. 예를 들어 아래는 형식을 설명하기 위한 예시입니다.

```json
{
  "cancel": "취소"
}
```

`{{name}}`, `%s`, `$t(...)` 같은 자리표시자나 참조가 있다면 원문의 형태를 유지해야 합니다. 직역하기보다 화면 문맥에 맞는 자연스러운 표현을 사용하고, 기존 번역과 용어를 맞춥니다.

### 4. Breeze로 번역 완성도 확인

강연 자료에서는 저장소 루트에서 Breeze를 설치하고 도움말을 확인했습니다.

```bash
uv tool install -e ./dev/breeze
breeze -h
```

한국어 번역을 검사하려면 다음 명령을 사용합니다.

```bash
breeze ui check-translation-completeness --language ko
```

이 명령은 영어 기준 파일과 비교해 누락된 키, 불필요한 키, 미번역 TODO 표시와 번역 범위를 보여 줍니다. 출력에서 파일과 키를 확인해 작업할 항목을 고르고, 수정 후 다시 검사합니다. [Breeze UI 작업 안내](https://github.com/apache/airflow/blob/main/dev/breeze/doc/10_ui_tasks.rst)

강연에서 소개한 다음 명령은 **파일을 변경하는 선택 실습**입니다. 첫 PR에서는 필요한 범위를 확인한 뒤 사용합니다.

```bash
# 누락된 항목을 TODO 표시와 함께 추가
breeze ui check-translation-completeness --language ko --add-missing

# 기준 언어에 필요하지 않은 항목을 제거
breeze ui check-translation-completeness --language ko --remove-unused
```

자동 추가된 TODO는 완성된 번역이 아닙니다. 일괄 변경 후에는 담당 항목만 남았는지 확인하고, 번역하지 않은 항목을 PR에 포함하지 않도록 주의합니다.

### 5. UI와 변경 내역 확인

강연에서는 Breeze 환경에서 Airflow를 실행해 번역이 실제 화면에 어떻게 표시되는지도 살펴봤습니다.

```bash
breeze --backend postgres start-airflow --dev-mode
```

UI 확인은 화면의 맥락과 문구 길이를 살펴보는 데 도움이 됩니다. 실행하지 못했다면 PR에 UI를 확인했다고 적지 않습니다.

커밋 전에는 의도한 파일과 항목만 수정됐는지 확인합니다.

```bash
git status
git diff --stat
git diff
breeze ui check-translation-completeness --language ko
```

### 6. 커밋, Push, PR

검토한 번역 파일을 스테이징하고 변경에 맞는 메시지로 커밋합니다. 아래 경로와 메시지는 예시이며 실제 수정한 파일과 내용으로 바꿉니다.

```bash
git add airflow-core/src/airflow/ui/public/i18n/locales/ko/common.json
git commit -m "i18n(ko): translate UI labels"
git push -u origin i18n/workshop
```

GitHub의 Fork 저장소에서 **Compare & pull request**를 열고, 대상은 `apache/airflow:main`, 변경 브랜치는 자신의 Fork의 `i18n/workshop`으로 설정합니다. **Files changed**에서 관련 없는 변경이 없는지 확인하고, PR 설명에 번역한 내용과 실제로 수행한 검증을 적습니다.

PR 제목은 예를 들어 `i18n(ko): translate task action labels`처럼 실제 변경 범위에 맞춰 작성합니다. UI 전후 화면을 확인했다면 비교 자료를 첨부할 수 있습니다. 제출 후에는 리뷰 의견에 따라 수정하고 검토를 기다립니다. 한국어 번역의 언어적 검토와 기술적 검토를 거쳐 커미터가 병합을 결정합니다.

## 기여 결과

실습과 연결된 [Apache Airflow PR #76506](https://github.com/apache/airflow/pull/76506)은 `browse.json`, `common.json`, `components.json`, `dags.json`의 한국어 UI 번역을 추가했습니다. PR 작성자는 `lWonJunl`이며, 2026년 11월 7일 병합되었습니다. [병합 후 댓글](https://github.com/apache/airflow/pull/76506#issuecomment-6703130050)에는 기여에 대한 감사와 Airflow 커뮤니티 환영 인사가 남았습니다.

PR 리뷰에서는 미번역 `TODO` 항목을 변경 범위에서 제외해 완료된 번역만 남기도록 요청했습니다. 이는 번역 내용뿐 아니라 PR에 포함된 변경의 범위와 형식도 검토 대상이라는 점을 보여 줍니다.

## 참고 자료

- [Apache Airflow PR #76506](https://github.com/apache/airflow/pull/76506)
- [Airflow 기여 안내](https://github.com/apache/airflow/blob/main/contributing-docs/README.rst)
- [Airflow UI 국제화 안내](https://github.com/apache/airflow/blob/main/airflow-core/src/airflow/ui/public/i18n/README.md)
- [Breeze UI 작업 안내](https://github.com/apache/airflow/blob/main/dev/breeze/doc/10_ui_tasks.rst)

## 이동

- [1학년 2학기](../README.md)
- [저장소 대표 README](../../README.md)
