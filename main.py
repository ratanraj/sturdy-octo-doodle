import pygame
from pygame.locals import *
from levels import levels

# TODO: Fix the line drawing algorithm
def bresenham(x1,y1,x2, y2):
    m_new = 2 * (y2 - y1)
    slope_error_new = m_new - (x2 - x1)
    y=y1
    for x in range(x1,x2+1, -1 if x1>x2 else 1):
        #print("(",x ,",",y ,")\n")
        yield (x,y)
        slope_error_new =slope_error_new + m_new
        if (slope_error_new >= 0):
            y=y+1
            slope_error_new =slope_error_new - 2 * (x2 - x1)



def extrapolate_walk_path(walk_path):
    for i in range(0, len(walk_path)-1, 1):
        x1,y1,x2,y2 = walk_path[i][0], walk_path[i][1], walk_path[i+1][0], walk_path[i+1][1]
        for p in bresenham(x1, y1, x2, y2):
            yield p


class Boogy:
    def __init__(self, walk_path) -> None:
        self.path = extrapolate_walk_path(walk_path=walk_path)

    def plot(self, screen):
        screen.blit(self.sprite, next(self.path))


class Monster1(Boogy):
    def __init__(self, walk_path) -> None:
        self.sprite = pygame.image.load('monster_small.png')
        super().__init__(walk_path)


class Game:
    def __init__(self) -> None:
        pygame.init()
        self.fpsClock = pygame.time.Clock()
        self.screen = pygame.display.set_mode((1024, 768))
        pygame.display.set_caption('Tower Defense')
        self.images = dict()

    def load_images(self):
        self.images['splash'] = pygame.image.load('splash.png')
        self.images['level1'] = pygame.image.load('levels/level1.png')

    def splash_screen(self):
        running = True
        while running:
            self.screen.blit(self.images['splash'], (0, 0))
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == KEYDOWN:
                    running = False
            pygame.display.update()
            self.fpsClock.tick(12)

    def level_selector(self):
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type ==MOUSEBUTTONUP:
                    mouse_x, mouse_y = event.pos

            pygame.display.update()
            self.fpsClock.tick(12)

    def load_level(self, n):
        for i in levels:
            if i['id'] == n:
                return i

    def main(self):
        pygame.init()
        self.load_images()

        self.splash_screen()
        #selected_level = self.level_selector()
        selected_level = 1

        level = self.load_level(selected_level)

        print(f'Level: {level}')

        running = True
        m1 = Monster1(level['path'])
        while running:
            self.screen.fill(pygame.Color(255, 0, 0))
            self.screen.blit(self.images[level['map']], (0, 0))
            m1.plot(self.screen)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

            pygame.display.update()
            self.fpsClock.tick(30)


if __name__ == '__main__':
    game = Game()
    game.main()
