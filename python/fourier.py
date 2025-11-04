import pygame
import math

pygame.init()
WIDTH, HEIGHT = 1000, 1000
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

center = (WIDTH // 2, HEIGHT // 2)
radius = 150
angle = 0.0
speed = 0.02  # radians per frame

# frames in one rotation (may be non-integer)
rotation_frames = (2 * math.pi) / speed

# exact (float) alpha to subtract each frame so sum over rotation_frames == 255
fade_per_frame = 255.0 / rotation_frames

# We'll distribute fractional parts using an accumulator so we subtract integers each frame
frac_acc = 0.0

trail_surface = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)  # keep alpha channel

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # compute point
    x = center[0] + radius * math.cos(angle)
    y = center[1] + radius * math.sin(angle)
    angle += speed

    # accumulate fractional alpha, convert to integer to subtract this frame
    frac_acc += fade_per_frame
    to_sub = int(frac_acc)          # how much to subtract this frame (integer)
    frac_acc -= to_sub              # keep the fractional remainder

    # clamp to_sub to valid alpha range
    if to_sub > 0:
        if to_sub > 255:
            to_sub = 255

        fade_surface = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
        # fill black but with alpha = to_sub; BLEND_RGBA_SUB will subtract src.a from dest.a
        fade_surface.fill((0, 0, 0, to_sub))
        trail_surface.blit(fade_surface, (0, 0), special_flags=pygame.BLEND_RGBA_SUB)

    # draw trail dot (opaque)
    pygame.draw.circle(trail_surface, (0, 100, 255, 255), (int(x), int(y)), 2)

    # render
    screen.fill((0, 0, 0))
    screen.blit(trail_surface, (0, 0))
    pygame.draw.circle(screen, (255, 0, 0), (int(x), int(y)), 8)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()

