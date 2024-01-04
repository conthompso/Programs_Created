#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import cv2
import numpy as np

point_matrix = np.zeros((2,2), np.int32)

red = 0
green = 255
blue = 0
counter = 0
select = 0


def mousePoints(event, x, y, flags, params):
    global entries
    global counter
    global red
    global green
    global blue
    global rec_red
    global rec_green
    global rec_blue
    global colors
    global select
    
    
    if event == cv2.EVENT_LBUTTONDOWN:
        point_matrix[counter] = x,y
        counter = counter + 1
        
    if event == cv2.EVENT_RBUTTONDOWN:
        check_x = x
        check_y = y
        global i
        global entries
        
        for i in range(0, len(entries), 7):
            if entries[i] <= check_x <= entries[i+2] or entries[i] >= check_x >= entries[i+2]:
                if entries[i+1] <= check_y <= entries[i+3] or entries[i+1] >= check_y >= entries[i+3]:
                    del1 = entries[i]
                    del2 = entries[i+1]
                    del3 = entries[i+2]
                    del4 = entries[i+3]
                    del5 = entries[i+4]
                    del6 = entries[i+5]
                    del7 = entries[i+6]
                    
                    result1 = np.where(entries == del1)
                    for i in range(7):
                        entries = np.delete(entries, result1)
        
    if event == cv2.EVENT_MOUSEWHEEL:
        if flags > 0:
            select = select + 1
            if select > 2:
                select = 0
            if select == 0:
                red = 0
                green = 255
                blue = 0
            if select == 1:
                red = 0
                green = 0
                blue = 255
            if select == 2:
                red = 255
                green = 0
                blue = 0
            
        if flags < 0:
            select = select - 1
            if select < 0:
                select = 2
            if select == 0:
                red = 0
                green = 255
                blue = 0
            if select == 1:
                red = 0
                green = 0
                blue = 255
            if select == 2:
                red = 255
                green = 0
                blue = 0
                
    if event == cv2.EVENT_MBUTTONDOWN:
        temp = np.any(dst)
        if temp == True:
            dst.fill(0)
            zoomout()
        else:
            zoomin(x,y)

def mouseone(event, x, y, flags, param):
    return 0

def zoomout():
    dst.fill(0)
    counter = 0
    
def zoomin(x,y):
    cv2.setMouseCallback('frame', mouseone)
    counter = 0
    global x1
    global x2
    global y1
    global y2
    global dst
    
    x1 = x - 0.25*shapeX
    if x1 < 0:
        x1 = abs(x1)
        x2 = x + 0.25*shapeX
        x2 = x2 + x1
        x1 = 0
    else:
        x2 = x + 0.25*shapeX
    if x2 > shapeX:
        x2 = x2 - shapeX
        x1 = x1 - x2
        x2 = shapeX
    y1 = y - 0.25*shapeY
    if y1 < 0:
        y1 = abs(y1)
        y2 = y + 0.25*shapeY
        y2 = y2 + y1
        y1 = 0
    else:
        y2 = y + 0.25*shapeY
    if y2 > shapeY:
        y2 = y2 - shapeY
        y1 = y1 - y2
        y2 = shapeY

    pts1 = np.float32([[x1, y1], [x2, y1], [x1, y2], [x2, y2]])
    pts2 = np.float32([[0,0], [shapeX, 0], [0, shapeY], [shapeX, shapeY]])
    M = cv2.getPerspectiveTransform(pts1, pts2)
    dst = cv2.warpPerspective(frame, M, (shapeX, shapeY))

entries = np.array([0,0,0,0,255,255,255])
f = open("previousScaffolding.txt", 'r')
for x in f:
    add_entry = x
    if add_entry == '\n':
        print("nothing")
        break
    add_entry = add_entry.split()
    for i in range(len(add_entry)):
        add_entry[i] = int(add_entry[i])
if len(entries) > 7:
    for i in range(7):
        entries = np.delete(entries[0])
entries = np.append(entries, add_entry, axis = None)
f.close()

frame = cv2.imread('snip.png')
cv2.imshow('frame', frame)
cv2.namedWindow('frame', cv2.WINDOW_NORMAL)
clone = frame.copy()


dst = np.array([])
global shapeX
shapeX = frame.shape[1]
global shapeY
shapeY = frame.shape[0]




while True:
    
    temp = np.any(dst)
    if temp == True:
        cv2.imshow('frame', dst)
        cv2.setMouseCallback("frame", mousePoints)
        for x in range (0,2):
            cv2.circle(dst,(point_matrix[x][0], point_matrix[x][1]), 2, (red, green, blue), cv2.FILLED)
            if counter == 2:
                starting_x = point_matrix[0][0]
                starting_y = point_matrix[0][1]
                ending_x = point_matrix[1][0]
                ending_y = point_matrix[1][1]
                                
                reccolor = np.array([red, green, blue])
                reccolor = (int (reccolor[0]), int (reccolor[1]), int (reccolor[2]))
                
                points = np.array([[starting_x, starting_y], [ending_x, starting_y], [ending_x, ending_y], [starting_x, ending_y]])
                cv2.fillPoly(dst, pts = [points], color = tuple (reccolor))
                cv2.rectangle(dst, (starting_x, starting_y), (ending_x, ending_y), tuple (reccolor), 3)
                cv2.imshow("frame" , dst)
                cv2.setMouseCallback("frame", mousePoints)
                
                counter = 0                    
                
                x1Loc = x1 + (starting_x/shapeX)*(x2 - x1)
                y1Loc = y1 + (starting_y/shapeY)*(y2 - y1)
                x2Loc = x1 + (ending_x/shapeX)*(x2 - x1)
                y2Loc = y1 + (ending_y/shapeY)*(y2 - y1)
                
                newLoc = np.array([x1Loc, y1Loc, x2Loc, y2Loc, red, green, blue])
                newLoc = (int(newLoc[0]), int (newLoc[1]), int(newLoc[2]), int(newLoc[3]), int(newLoc[4]), int(newLoc[5]), int(newLoc[6]))
                
                add_entry = np.array(newLoc)
                entries = np.append(entries, add_entry, axis = None)
        cv2.imshow('frame', dst)
        cv2.setMouseCallback("frame", mousePoints)
                
        


    else:
        for x in range (0,2):
            cv2.circle(frame,(point_matrix[x][0], point_matrix[x][1]), 2, (red, green, blue), cv2.FILLED)

            if counter == 2:
                starting_x = point_matrix[0][0]
                starting_y = point_matrix[0][1]
                ending_x = point_matrix[1][0]
                ending_y = point_matrix[1][1]
                

                lst1 = [starting_x, starting_y, ending_x, ending_y, red, green, blue]
                add_entry = np.array(lst1)
                entries = np.append(entries, add_entry, axis = None)
                counter = 0

        for i in range (0, len(entries), 7):
            starting_x = entries[i + 0]
            starting_y = entries[i + 1]
            ending_x = entries[i + 2]
            ending_y = entries[i + 3]
            rec_red = entries[i + 4]
            rec_green = entries[i + 5]
            rec_blue = entries[i + 6]
            reccolor = np.array([rec_red, rec_green, rec_blue])
            reccolor = (int (reccolor[0]), int (reccolor[1]), int (reccolor[2]))

            points = np.array([[starting_x, starting_y], [ending_x, starting_y], [ending_x, ending_y], [starting_x, ending_y]])
            cv2.fillPoly(frame, pts = [points], color = tuple (reccolor))
            cv2.rectangle(frame, (starting_x, starting_y), (ending_x, ending_y), tuple (reccolor), 3)
            cv2.imshow("frame" , frame)
            cv2.setMouseCallback("frame", mousePoints)
            
        cv2.imshow('frame', frame)
        cv2.setMouseCallback("frame", mousePoints)
    

   
    

   
    cv2.waitKey(1)
    k = cv2.waitKey(1)
    if k == ord("c"):
        entries = np.array([0,0,0,0,255,255,255])
#     if k == ord("u"):
#         for i in range(7):
#             x = len(entries-1)
#             if x == 7:
#                 break
#             else:
#                 entries = np.delete(entries, x)
    if k == ord("r"):
        frame = clone.copy()
    if k == 27:
        cv2.destroyAllWindows()
        break
    if k == ord("p"):
        zoomout()
        filename = 'scaffoldingImage.jpg'
        cv2.imwrite(filename, frame)
        with open('previousScaffolding.txt', 'w') as f:
            for i in range(len(entries)):
                vectorEntries = str(entries[i])
                f.write(vectorEntries)
                f.write(" ")
            f.close()
        cv2.destroyAllWindows()

