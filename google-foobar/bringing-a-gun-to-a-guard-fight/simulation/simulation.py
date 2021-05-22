from graphics import *

dimensions = (3, 2)

win = GraphWin('My Circle', 600, 400)
c = Circle(Point(200,200), 100)
c.draw(win)
win.getMouse()
win.close()