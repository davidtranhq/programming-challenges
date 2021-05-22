import math

def angle(x0, y0, x1, y1):
    return math.atan2(y1 - y0, x1 - x0) * (180/math.pi)

def get_angles(x0, y0, pts):
    '''Returns a map of {angle, pt} where pt is the closest point to (x0,y0) for a given angle'''
    angles = {}
    for x1, y1 in pts:
        ang = angle(x0, y0, x1, y1)
        if ang not in angles:
            angles[ang] = (x1, y1)
        else:
            # replace an already recorded point if the new point is closer
            recorded = angles[ang]
            angles[ang] = min((x1, y1), recorded, key=lambda x: distance(x0, y0, *x))
    return angles

def filter_pts(x, y, pts, dist):
    '''Removes points from pts that are farther than dist away from (x,y)'''
    return [pt for pt in pts if distance(x, y, pt[0], pt[1]) <= dist]

def include_reflections(pts):
    '''Returns a list of reflected points in quadrants 1-4 from a list of 1st quadrant points'''
    return [(xr, yr) for x, y in pts for xr, yr in ((x, y), (-x, y), (-x, -y), (x, -y))]

def distance(x0, y0, x1, y1):
    '''Returns the distance between 2 points (x0, y0) and (x1, y1)'''
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
    x_imgs = (dist // dimensions[0]) + 2
    y_imgs = (dist // dimensions[1]) + 2
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
    # get map of (angle: pt) where pt is the closest point for a given angle
    your_angles = get_angles(ypx, ypy, your_pts[1:])
    guard_angles = get_angles(ypx, ypy, guard_pts)
    # count how many guards can be shot
    shots = 0
    for ang, pt in guard_angles.iteritems():
        # a guard can only be shot if it's not aligned with a player reflection OR
        # it is closer than an aligned player reflection
        if ang not in your_angles or distance(ypx, ypy, *pt) < distance(ypx, ypy, *your_angles[ang]):
            shots += 1
    return shots