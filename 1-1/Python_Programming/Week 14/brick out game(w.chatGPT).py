import pygame
import sys
import random

pygame.init()

# ======================
# 화면 설정
# ======================
WIDTH = 800
HEIGHT = 600

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("벽돌깨기")

# ======================
# 색상
# ======================
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 60, 60)
BLUE = (50, 120, 255)
GOLD = (255, 215, 0)

# ======================
# 폰트
# ======================
font = pygame.font.SysFont(None, 40)

# ======================
# 블록 생성
# ======================
BLOCK_ROWS = 5
BLOCK_COLS = 8
BLOCK_WIDTH = 90
BLOCK_HEIGHT = 30
BLOCK_GAP = 5

blocks = []

start_x = (
    WIDTH -
    (BLOCK_COLS * BLOCK_WIDTH +
     (BLOCK_COLS - 1) * BLOCK_GAP)
) // 2

start_y = 50

for row in range(BLOCK_ROWS):
    for col in range(BLOCK_COLS):

        x = start_x + col * (BLOCK_WIDTH + BLOCK_GAP)
        y = start_y + row * (BLOCK_HEIGHT + BLOCK_GAP)

        rect = pygame.Rect(
            x,
            y,
            BLOCK_WIDTH,
            BLOCK_HEIGHT
        )

        blocks.append({
            "rect": rect,
            "bonus": False
        })

# ======================
# 랜덤 보너스 벽돌 4개
# ======================
for block in random.sample(blocks, 4):
    block["bonus"] = True

# ======================
# 공 설정
# ======================
ball_radius = 10

ball_x = WIDTH // 2
ball_y = HEIGHT // 2

ball_dx = 4
ball_dy = -4

# ======================
# 패들 설정
# ======================
paddle_width = 120
paddle_height = 15

paddle = pygame.Rect(
    WIDTH // 2 - paddle_width // 2,
    HEIGHT - 60,
    paddle_width,
    paddle_height
)

paddle_speed = 8

# ======================
# 게임 정보
# ======================
score = 0
lives = 3

# ======================
# 종료 화면
# ======================
def show_end_message(message):

    screen.fill(BLACK)

    text = font.render(message, True, WHITE)

    rect = text.get_rect(
        center=(WIDTH // 2, HEIGHT // 2)
    )

    screen.blit(text, rect)

    pygame.display.flip()

    pygame.time.wait(3000)

    pygame.quit()
    sys.exit()

# ======================
# 메인 루프
# ======================
clock = pygame.time.Clock()

while True:

    # 이벤트 처리
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # ======================
    # 패들 이동
    # ======================
    keys = pygame.key.get_pressed()

    if keys[pygame.K_LEFT]:
        paddle.x -= paddle_speed

    if keys[pygame.K_RIGHT]:
        paddle.x += paddle_speed

    if paddle.left < 0:
        paddle.left = 0

    if paddle.right > WIDTH:
        paddle.right = WIDTH

    # ======================
    # 공 이동
    # ======================
    ball_x += ball_dx
    ball_y += ball_dy

    # 좌우 벽
    if ball_x - ball_radius <= 0:
        ball_x = ball_radius
        ball_dx *= -1

    if ball_x + ball_radius >= WIDTH:
        ball_x = WIDTH - ball_radius
        ball_dx *= -1

    # 위 벽
    if ball_y - ball_radius <= 0:
        ball_y = ball_radius
        ball_dy *= -1

    # ======================
    # 공 Rect
    # ======================
    ball_rect = pygame.Rect(
        ball_x - ball_radius,
        ball_y - ball_radius,
        ball_radius * 2,
        ball_radius * 2
    )

    # ======================
    # 패들 충돌
    # ======================
    if ball_rect.colliderect(paddle) and ball_dy > 0:

        ball_y = paddle.top - ball_radius

        # 패들 위치에 따른 반사각
        hit_pos = (
            ball_x - paddle.centerx
        ) / (paddle_width / 2)

        ball_dx = hit_pos * 6

        if ball_dx > 8:
            ball_dx = 8

        if ball_dx < -8:
            ball_dx = -8

        ball_dy = -abs(ball_dy)

    # ======================
    # 벽돌 충돌
    # ======================
    hit_block = None

    for block in blocks:

        if ball_rect.colliderect(block["rect"]):
            hit_block = block
            break

    if hit_block:

        if hit_block["bonus"]:
            score += 20
        else:
            score += 10

        blocks.remove(hit_block)

        ball_dy *= -1

        # 승리
        if len(blocks) == 0:
            show_end_message("YOU WIN!")

    # ======================
    # 공 놓침
    # ======================
    if ball_y - ball_radius > HEIGHT:

        lives -= 1

        if lives <= 0:
            show_end_message("GAME OVER")

        # 공 리셋
        ball_x = WIDTH // 2
        ball_y = HEIGHT // 2

        ball_dx = random.choice([-4, 4])
        ball_dy = -4

        paddle.centerx = WIDTH // 2

    # ======================
    # 화면 그리기
    # ======================
    screen.fill(BLACK)

    # 벽돌
    for block in blocks:

        color = GOLD if block["bonus"] else BLUE

        pygame.draw.rect(
            screen,
            color,
            block["rect"]
        )

        pygame.draw.rect(
            screen,
            WHITE,
            block["rect"],
            1
        )

    # 공
    pygame.draw.circle(
        screen,
        RED,
        (int(ball_x), int(ball_y)),
        ball_radius
    )

    # 패들
    pygame.draw.rect(
        screen,
        WHITE,
        paddle
    )

    # ======================
    # UI
    # ======================
    remaining_bricks = len(blocks)

    score_text = font.render(
        f"Score: {score}",
        True,
        WHITE
    )

    lives_text = font.render(
        f"Lives: {lives}",
        True,
        WHITE
    )

    bricks_text = font.render(
        f"Bricks: {remaining_bricks}",
        True,
        WHITE
    )

    # 좌상단
    screen.blit(score_text, (10, 10))

    # 중상단
    screen.blit(
        lives_text,
        lives_text.get_rect(
            center=(WIDTH // 2, 25)
        )
    )

    # 우상단
    screen.blit(
        bricks_text,
        bricks_text.get_rect(
            topright=(WIDTH - 10, 10)
        )
    )

    pygame.display.flip()
    clock.tick(60)