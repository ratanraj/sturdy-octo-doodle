import pygame
from pygame.locals import *

class Game():
    def __init__(self) -> None:
        pygame.init()
        self.fpsClock = pygame.time.Clock()
        self.screen = pygame.display.set_mode((1024, 768))
        pygame.display.set_caption('Tower Defense')
        self.images = dict()

    def load_images(self):
        self.images['splash'] = pygame.image.load('splash.png')

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

            

    def main(self):
        pygame.init()
        self.load_images()

        self.splash_screen()
        self.level_selector()

        running = True
        while running:
            self.screen.fill(pygame.Color(255, 0, 0))

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

            pygame.display.update()
            self.fpsClock.tick(30)


if __name__ == '__main__':
    game = Game()
    game.main()
