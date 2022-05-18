from pygame import MOUSEBUTTONUP
import pygame


def button(screen, coords=(), text="Button",event=None, onclick=None):
    pygame.draw.rect(screen, pygame.Color(255, 255, 255), coords)
    if event.type == MOUSEBUTTONUP:
        mousex, mousey = event.pos
        if mousex>coords[0] and mousex<(coords[0]+coords[2]) and \
            mousey>coords[1] and mousey<(coords[1]+coords[3]):
            onclick()
