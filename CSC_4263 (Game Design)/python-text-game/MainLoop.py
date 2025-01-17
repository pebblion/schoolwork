import keyboard
import os
import time

level = 1
screen = [[".", ".", ".", ".", "."], 
          ["X", ".", ".", ".", "."],
          [".", ".", ".", ".", "."],
          [".", ".", ".", ".", "."],
          [".", ".", ".", ".", ".",]]

Xcoords = [[1,0]]

loop = True
px = 2
py = 4
lx = 0
ly = 0
newline = 0
Xcounter = 2
loops = 0

print("You are O, Collect the X")
print("Move with WASD")
time.sleep(2)

while loop:
    time.sleep(0.2)
    os.system('cls')
    screen[ly][lx] = "."
    screen[py][px] = "O"

    for array in screen:
        for pixel in array:
            newline = newline + 1
            if (newline % 5) == 0:
                print(pixel + "\n", end = '')
            else:
                print(pixel, end = '')

        #input
        if keyboard.is_pressed("a") and px > 0:
            lx = px
            ly = py
            px = px - 1
            break
        elif keyboard.is_pressed("d") and px < 4:
            lx = px
            ly = py
            px = px + 1
            break
        elif keyboard.is_pressed("w") and py > 0:
            lx = px
            ly = py
            py = py - 1
            break
        elif keyboard.is_pressed("s") and py < 4:
            lx = px
            ly = py
            py = py + 1
            break

        #win
        if py == Xcoords[0][0] and px == Xcoords[0][1]:
            Xcounter = Xcounter - 1
     
        if Xcounter == 0: 
            loop = False

print("You Win!")
