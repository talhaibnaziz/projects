#!/usr/bin/python
from __future__ import absolute_import, division, print_function, unicode_literals

""" Demonstrates first person movment using the mouse but constrained, physics
of bouncing off an elevation map using normal vectors. Also writing using the
Font class. 

This demo also used the Defoucs class to blur things in the distance, but this
has been commented out. The monster is not blurred as it is at a constant
distance and could have been blurred in the actual png image file using gimp
or shuchlike. The Display.frames_per_second has been throttled to 20 as
there is a big change in speed depending on camera movement which effects
game play.
"""

import math, random

import demo
import pi3d

#helpful messages
print("############################################################")
print("Mouse to move left and right and up and down")
print("############################################################")
print()

# Setup display and initialise pi3d
DISPLAY = pi3d.Display.create(x=100, y=50, frames_per_second=20)
DISPLAY.set_background(0.4,0.8,0.8,1) # r,g,b,alpha
camera = pi3d.Camera((0, 0, 0), (0, 0, -1), (1, 1000, 30.0, DISPLAY.width/DISPLAY.height))
light = pi3d.Light((10, -20, -10))
# load shader
shader = pi3d.Shader("uv_light")
flatsh = pi3d.Shader("uv_flat")
#defocus = pi3d.Defocus() #<<<<<<<<<<<<<<<
#========================================

# Setting 2nd param to True renders 'True' Blending
# (this can be changed later to 'False' with 'rockimg2.blend = False')
groundimg = pi3d.Texture("textures/stripwood.jpg")
monstimg = pi3d.Texture("textures/pong3.png")
ballimg = pi3d.Texture("textures/pong2.jpg")

# environment cube
ectex = pi3d.Texture("textures/ecubes/skybox_stormydays.jpg")
myecube = pi3d.EnvironmentCube(camera, light, 900.0,"CROSS")
myecube.set_draw_details(flatsh, [ectex])

#ball
maxdsz = 0.3
radius = 1.0
radius0 = 1.0
ball = pi3d.Triangle(corners=((-0.01, 0.0), (0.0, 0.01), (0.01, 0.0)))
ball_shape = pi3d.Sphere(radius=radius)
ball.add_child(ball_shape) # to get realistic 'rolling'
# Shape.set_draw_details is a wrapper for calling the method on each item in buf
# as is done explicitly here for no reason than to show that it can be done!
ball_shape.set_draw_details(shader,[ballimg])

#monster
monster = pi3d.Plane(camera, light, 5.0, 5.0, "monster", 0,0,0, 0,0,0)
monster.set_draw_details(flatsh, [monstimg])

# Create elevation map
mapwidth=50.0
mapdepth=50.0
maphalf=22.0
mapheight=40.0

mymap = pi3d.ElevationMap("textures/pong.jpg", camera=camera, light=light,
                     width=mapwidth, depth=mapdepth, height=mapheight,
                     divx=64, divy=64, ntiles=4, name="sub")
mymap.set_draw_details(shader, [groundimg])

#avatar camera
avhgt = 2.0
xm = 0.0
zm = 0.0
ym = 0.0
lastX0 = 0.0
lastZ0 = 0.0
camera.position((xm, 2 + ym, -maphalf - 2.5))

#scores
arialFont = pi3d.Font("fonts/NotoSerif-Regular.ttf", (221,0,170,255))
arialFont.blend = True
score = [0,0]
score0 = pi3d.String(font=arialFont, string=str(score[0]), y=12, sx=0.05, sy=0.05)
score0.set_shader(flatsh)
score1 = pi3d.String(font=arialFont, string=str(score[1]), y=12, sx=0.05, sy=0.05)
score1.set_shader(flatsh)

#sphere loc and speed
sx, sy, sz = 0, 5, 0
dsx, dsy, dsz = 0.2, 0.0, -0.1
gravity = 0.02
#monster loc and speed
rx, ry, rz = 0, 0, -maphalf
drx, dry, drz = 0, 0, 0
max_speed = 0.2

# Fetch key presses
mykeys = pi3d.Keyboard()
mymouse = pi3d.Mouse(restrict=False)
mymouse.start()

omx, omy = mymouse.position()

while DISPLAY.loop_running():

  # mouse movement checking here to get bat movment values
  mx, my = mymouse.position()
  dx = (mx-omx)*0.04
  omx=mx
  if ((xm >= (-1*maphalf) and dx < 0) or (xm <= maphalf and dx > 0)):  xm += dx


  dy = (my-omy)*0.02
  omy = my
  if ((ym >= (0) and dy < 0) or (ym <= mapheight and dy > 0)):  ym += dy
  if not (dy == 0.0 and dx == 0.0):
    camera.reset()
    camera.position((xm, 2 + ym, -maphalf - 2.5))

  #monster movement
  drx = sx - rx
  if abs(drx) > max_speed: drx = drx/abs(drx) * max_speed
  dry = sy - ry
  if abs(dry) > max_speed: dry = dry/abs(dry) * max_speed
  rx += drx
  ry += dry

  monster.position(rx, ry, maphalf)

  dsy -= gravity
  sx += dsx
  sy += dsy
  sz += dsz
  # now uses the clashTest method from elevationMap

  clash = mymap.clashTest(sx, sy, sz, radius)
  # bouncing physics
  if clash[0]:
    # returns the components of normal vector if clash
    nx, ny, nz =  clash[1], clash[2], clash[3]
    # move it away a bit to stop it getting trapped inside if it has tunelled
    jDist = clash[4] + 0.2
    sx, sy, sz = sx + jDist*nx, sy + jDist*ny, sz + jDist*nz
    # use R = I - 2(N.I)N
    rfact = 2.05*(nx*dsx + ny*dsy + nz*dsz) #small extra boost by using value > 2 to top up energy in defiance of 1st LOT
    dsx, dsy, dsz = dsx - rfact*nx, dsy - rfact*ny, dsz - rfact*nz
    # stop the speed increasing too much
    if dsz > 0.4: dsz = 0.4
    if dsx > 0.3: dsx = 0.2
    if dsz > maxdsz: dsz = maxdsz
  if sy < mymap.y() - 0.4:
    sy = mymap.y() + 0.4 + radius
    dsy = abs(dsy)

  # bounce off edges and give a random boost
  if sx > maphalf:
    dsx = -1 * abs(dsx) * (1 + random.random())
    dsz += 0.1*random.random()-0.05
  if sx < -maphalf: dsx = abs(dsx)
  if sz < -maphalf: #player end
    #check if bat in position
    if (sx - xm)**2 + (sy - ym)**2 < 10:
      dsz = abs(dsz) * (1 + random.random())
      dsx += dx
      dsy += dy
    else:
      sx, sy, sz = 0, mapheight/3, 0
      dsx, dsy, dsz = 0.3*random.random()-0.15, 0, 0.1
      score[1] += 1
      score1 = pi3d.String(font=arialFont, string=str(score[1]), y=12, z=5, sx=0.05, sy=0.05)
      score1.set_shader(flatsh)
  elif sz > maphalf: #monster end
    if (sx-rx)**2 + (sy-ry)**2 < 10:
      dsz = -1 * abs(dsz)
    else:
      score[0] += 1
      score0 = pi3d.String(font=arialFont, string=str(score[0]), y=12, z=-5, sx=0.05, sy=0.05)
      score0.set_shader(flatsh)
      radius = 0.1 + (radius - 0.1)*0.75 # ball gets smaller each time you score
      s_fact = radius / radius0
      ball_shape.scale(s_fact, s_fact, s_fact)
      maxdsz += 0.01 # max speed in z direction increases too
      sx, sy, sz = 0, mapheight/3, 0
      dsx, dsy, dsz = 0.3*random.random()-0.15, 0, -0.1

  ball.position(sx, sy, sz)
  ball.rotateToY(math.degrees(math.atan2(dsx, dsz)))
  ball_shape.rotateIncX((dsz ** 2 + dsx ** 2) ** 0.5 / radius * 50.0)

  #defocus.start_blur() #<<<<<<<<<<<<<<<
  ball.draw()
  mymap.draw()
  myecube.draw()
  #defocus.end_blur() #<<<<<<<<<<<<<<<

  #defocus.blur(ball, 4, 15, 2) #<<<<<<<<<<<<<<<
  #defocus.blur(mymap, 4, 15, 2) #<<<<<<<<<<<<<<<
  #defocus.blur(myecube, 4, 15, 2) #<<<<<<<<<<<<<<<

  monster.draw()

  # write up the score
  score0.draw()
  score1.draw()

  camera.was_moved = False

  #Press ESCAPE to terminate
  k = mykeys.read()

  if k==27: #Escape key
    #defocus.delete_buffers() #<<<<<<<<<<<<<<<
    DISPLAY.destroy()
    mykeys.close()
    mymouse.stop()
    break
  elif k==112:  #key P
    pi3d.screenshot("pong.jpg")

# attempt to tidy up!
quit()
