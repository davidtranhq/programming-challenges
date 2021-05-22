import math
import matplotlib.pyplot as plot

def angle(x0, y0, x1, y1):
    return math.atan2(y1 - y0, x1 - x0) * (180/math.pi)

def get_angles(x0, y0, pts):
    angles = {}
    for x1, y1 in pts:
        ang = angle(x0, y0, x1, y1)
        if ang not in angles:
            angles[ang] = (x1, y1)
        else:
            recorded = angles[ang]
            angles[ang] = min((x1, y1), recorded, key=lambda pt: distance(x0, y0, *pt))
    return angles

def filter_pts(x, y, pts, dist):
    return [pt for pt in pts if distance(x, y, pt[0], pt[1]) <= dist]

def include_reflections(pts):
    return [(xr, yr) for x, y in pts for xr, yr in ((x, y), (-x, y), (-x, -y), (x, -y))]

def distance(x0, y0, x1, y1):
    return ((x1-x0)**2 + (y1-y0)**2) ** 0.5

def between(p0, p1, p2):
    '''Returns True if p2 is aligned in between p0 and p1.'''
    return (distance(p0[0], p0[1], p2[0], p2[1]) 
        + distance(p2[0], p2[1], p1[0], p1[1]) 
        == distance(p0[0], p0[1], p1[0], p1[1]))

def solution(dimensions, your_pos, guard_pos, dist):
    ypx, ypy = your_pos[0], your_pos[1]
    gpx, gpy = guard_pos[0], guard_pos[1]
    # max number of lattice image copies that fit within dist
    x_imgs = (dist // dimensions[0]) + 1
    y_imgs = (dist // dimensions[1]) + 1
    # find points of the first quadrant
    your_pts = []
    guard_pts = []
    for y_img in range(y_imgs):
        y_off = y_img * dimensions[1]
        your_y = y_off + (ypy if not y_img % 2 else dimensions[1] - ypy)
        guard_y = y_off + (gpy if not y_img % 2 else dimensions[1] - gpy)
        for x_img in range(x_imgs):
            x_off = x_img * dimensions[0]
            your_x = x_off + (ypx if not x_img % 2 else dimensions[0] - ypx)
            guard_x = x_off + (gpx if not x_img % 2 else dimensions[0] - gpx)
            your_pts.append( (your_x, your_y) )
            guard_pts.append( (guard_x, guard_y) )
    # include 2nd, 3rd, 4th quadrant pts from reflection of 1st quadrant pts
    your_pts = include_reflections(your_pts)
    guard_pts = include_reflections(guard_pts)
    # remove pts farther than the bullet distance away from the player
    your_pts = filter_pts(ypx, ypy, your_pts, dist)
    guard_pts = filter_pts(ypx, ypy, guard_pts, dist)
    # map of (angle: pt) where pt is the closest point for a given angle
    your_angles = get_angles(ypx, ypy, your_pts[1:])
    guard_angles = get_angles(ypx, ypy, guard_pts)
    shots = 0
    shot_list = []
    for ang, pt in guard_angles.items():
        if ang not in your_angles or distance(ypx, ypy, *pt) < distance(ypx, ypy, *your_angles[ang]):
            shots += 1
            shot_list.append(pt)
    fig = plot.figure()    
    ax = fig.add_subplot(1,1,1)
    ax.set_axisbelow(True)
    ax.yaxis.grid(color='gray', linestyle='dashed')
    ax.xaxis.grid(color='gray', linestyle='dashed')
    plot.scatter(*zip(*your_pts), color='blue')
    plot.scatter(*zip(*guard_pts), color='red')
    #plot.scatter(*zip(*shot_list), color='red')
    plot.show()
    return shots

 
a = solution([3,2], [1,1], [2,1], 4)
#print(a)
#b = solution([300,275], [150,150], [185,100], 500)
#print(b)
#c = solution([2,5],[1,2],[1,4],11)
#print(c)
#d = solution([10,10],[4,4],[3,3],5000)
#print(d)
#e = solution([23,10],[6,4],[3,2],23)
#print(e)
#f = solution([3,2],[0,0],[2,1],4)
