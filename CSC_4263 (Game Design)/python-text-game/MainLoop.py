import keyboard
import os
import time

level = 1
screen = [["Y", ".", ".", "X", "."], 
          ["X", "Y", "Y", ".", "."],
          [".", ".", "X", ".", "X"],
          [".", "X", ".", "Y", "."],
          [".", ".", ".", ".", ".",]]

Xcoords = [[1,0], [2,2], [3,1], [0,3], [2,4]]
Qcoords = [[0,0], [1,1], [1,2], [3,3]]
loop = True
px = 2
py = 4
lx = 0
ly = 0
newline = 0
Xcounter = 5
loops = 0

print(r"""                                                                                                 
                                                                                      ,----..    
                                                                                     /   /   \   
        ,---,                                                                       /   .     :  
       /_ ./|   ,---.           ,--,                       __  ,-.                 .   /   ;.  \ 
 ,---, |  ' :  '   ,'\        ,'_ /|                     ,' ,'/ /|                .   ;   /  ` ; 
/___/ \.  : | /   /   |  .--. |  | :            ,--.--.  '  | |' | ,---.          ;   |  ; \ ; | 
 .  \  \ ,' '.   ; ,. :,'_ /| :  . |           /       \ |  |   ,'/     \         |   :  | ; | ' 
  \  ;  `  ,''   | |: :|  ' | |  . .          .--.  .-. |'  :  / /    /  |        .   |  ' ' ' : 
   \  \    ' '   | .; :|  | ' |  | |           \__\/: . .|  | ' .    ' / |        '   ;  \; /  | 
    '  \   | |   :    |:  | : ;  ; |           ," .--.; |;  : | '   ;   /|         \   \  ',  /  
     \  ;  ;  \   \  / '  :  `--'   \         /  /  ,.  ||  , ; '   |  / |          ;   :    /   
      :  \  \  `----'  :  ,      .-./        ;  :   .'   \---'  |   :    |           \   \ .'    
       \  ' ;           `--`----'            |  ,     .-./       \   \  /             `---`      
        `--`                                  `--`---'            `----'                         
                                                                                                 """)

print("Collect X")
print("Avoid Y")
print("Move with WASD")
time.sleep(3)

while loop:
    time.sleep(0.2)
    os.system('cls')
    screen[py][px] = "O"
    for array in screen:
        for pixel in array:
            newline = newline + 1
            if (newline % 5) == 0:
                print(pixel + "\n", end = '')
            else:
                print(pixel + "  ", end = '')

        #input
        if keyboard.is_pressed("a") and px > 0:
            lx = px
            ly = py
            px = px - 1
            screen[ly][lx] = "."
            break
        elif keyboard.is_pressed("d") and px < 4:
            lx = px
            ly = py
            px = px + 1
            screen[ly][lx] = "."
            break
        elif keyboard.is_pressed("w") and py > 0:
            lx = px
            ly = py
            py = py - 1
            screen[ly][lx] = "."
            break
        elif keyboard.is_pressed("s") and py < 4:
            lx = px
            ly = py
            py = py + 1
            screen[ly][lx] = "."
            break

        #win
        for coords in Xcoords:
            if py == coords[0] and px == coords[1]:
                Xcounter = Xcounter - 1
                Xcoords.remove([py, px])
        #lose
        for coords in Qcoords:
            if py == coords[0] and px == coords[1]:
                loop = False
                
        if Xcounter == 0: 
            loop = False

if Xcounter == 0:
    print(r"""
                                                                                           
                 ,----..                                                          ,--. 
                /   /   \                                   .---.   ,---,       ,--.'| 
        ,---,  /   .     :          ,--,                   /. ./|,`--.' |   ,--,:  : | 
       /_ ./| .   /   ;.  \       ,'_ /|               .--'.  ' ;|   :  :,`--.'`|  ' : 
 ,---, |  ' :.   ;   /  ` ;  .--. |  | :              /__./ \ : |:   |  '|   :  :  | | 
/___/ \.  : |;   |  ; \ ; |,'_ /| :  . |          .--'.  '   \' .|   :  |:   |   \ | : 
 .  \  \ ,' '|   :  | ; | '|  ' | |  . .         /___/ \ |    ' ''   '  ;|   : '  '; | 
  \  ;  `  ,'.   |  ' ' ' :|  | ' |  | |         ;   \  \;      :|   |  |'   ' ;.    ; 
   \  \    ' '   ;  \; /  |:  | | :  ' ;          \   ;  `      |'   :  ;|   | | \   | 
    '  \   |  \   \  ',  / |  ; ' |  | '           .   \    .\  ;|   |  ''   : |  ; .' 
     \  ;  ;   ;   :    /  :  | : ;  ; |            \   \   ' \ |'   :  ||   | '`--'   
      :  \  \   \   \ .'   '  :  `--'   \            :   '  |--" ;   |.' '   : |       
       \  ' ;    `---`     :  ,      .-./             \   \ ;    '---'   ;   |.'       
        `--`                `--`----'                  '---"             '---'         
                                                                                          """)             
else:
    print(""" 
    
░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓███████▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓███████▓▒░  
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
 ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓██████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ 
   ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░
   ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
   ░▒▓█▓▒░    ░▒▓██████▓▒░ ░▒▓██████▓▒░       ░▒▓███████▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓███████▓▒░  
                                                                                             
                                                                                             """)                                                

