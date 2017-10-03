#!/usr/bin/python
from __future__ import absolute_import, division, print_function, unicode_literals

""" Uses a Tkinter window with elevation map, and a robot character in the
foreground that swaps to a more objective view as the mouse moves back and forth
The landscape can be navigated with the w and s keys to move forward and back.
The robot demostrates the same texture as the buildings but with higher shiny
value
"""

import demo
import pi3d

# Setup display and initialise pi3d
DISPLAY = pi3d.Display.create(x=50, y=50, w=-100, h=-100,
                         background=(0.4, 0.8, 0.8, 1))
shader = pi3d.Shader("uv_reflect")
bumpsh = pi3d.Shader("uv_bump")
flatsh = pi3d.Shader("uv_flat")
#############################

# Load textures
reflcn = pi3d.Texture("textures/stars.jpg")

#load environment cube
ectex = pi3d.loadECfiles("textures/ecubes","sbox_interstellar")
myecube = pi3d.EnvironmentCube(size=900.0, maptype="FACES")
myecube.set_draw_details(flatsh, ectex)

# Create elevation map
mapwidth=1000.0
mapdepth=1000.0
mapheight=60.0
mountimg1 = pi3d.Texture("textures/mars_colour.png")
bumpimg = pi3d.Texture("textures/mudnormal.jpg")
mymap = pi3d.ElevationMap(mapfile="textures/mars_height.png",
                     width=mapwidth, depth=mapdepth, height=mapheight,
                     divx=128, divy=128)
mymap.set_draw_details(bumpsh,[mountimg1, bumpimg],128.0, 0.0)
mymap.set_fog((0.3,0.15,0.1,0.7), 700.0)


#create robot
metalimg = pi3d.Texture("textures/metalhull.jpg")
robot_head= pi3d.Sphere(radius=1.0)
robot_body = pi3d.Cylinder(radius=1.0, height=2.0, sides=12)
robot_leg = pi3d.Cuboid(w=0.35, h=2.0)

robot = pi3d.MergeShape()
robot.add(robot_head.buf[0], 0.0, 1.6)
robot.add(robot_body.buf[0], 0.0, 0.5)
robot.add(robot_leg.buf[0], -1.04, 0, 0)
robot.add(robot_leg.buf[0], 1.05, 0, 0)
robot.set_draw_details(shader, [metalimg, metalimg, reflcn], 0.0, 0.5)

#create space station
ssphere = pi3d.Sphere(radius=10, slices=16, sides=16)
scorrid = pi3d.Cylinder(radius=4, height=22)

station = pi3d.MergeShape(y=mymap.calcHeight(0, 0), rx=4, ry=4, rz=4)
station.add(ssphere.buf[0], -20, 0, 20)
station.add(ssphere.buf[0], 20, 0, 20)
station.add(ssphere.buf[0], 20, 0, -20)
station.add(ssphere.buf[0], -20, 0, -20)
station.add(scorrid.buf[0], -20, 0, 0, 90, 0, 0)
station.add(scorrid.buf[0], 0, 0, -20, 0, 0, 90)
station.add(scorrid.buf[0], 0, 0, 20, 0, 0, 90)
station.set_draw_details(bumpsh, [metalimg, metalimg], 0.0)
station.set_fog((0.3,0.15,0.1,0.7), 700.0)

#avatar camera
rot = 0.0
tilt = -10.0
avhgt = 2.0
xm = 0.0
zm = 0.0
ym = (mymap.calcHeight(xm,zm)+avhgt)

# Fetch key presses
mykeys = pi3d.Keyboard()
mymouse = pi3d.Mouse(restrict=False)
mymouse.start()

#omx, omy = mymouse.position()

# Display scene and rotate cuboid
CAMERA = pi3d.Camera.instance()
while DISPLAY.loop_running():

  sf = 15.0 - 12.5 / abs(tilt) if tilt < -1.0 else 2.5
  CAMERA.relocate(rot, tilt, [xm, ym + 1.0, zm], [-sf, -sf, -sf])

  #draw robot
  robot.position(xm, ym, zm)
  robot.rotateToY(-rot)
  robot.draw()

  station.draw()
  mymap.draw() #Draw the landscape
  myecube.draw() #Draw environment cube
  myecube.position(xm, ym, zm)

  mx, my = mymouse.position()

  #if mx>DISPLAY.left and mx<DISPLAY.right and my>DISPLAY.top and my<DISPLAY.bottom:
  rot = -mx * 0.2
  tilt = my * 0.1 -10.0
  if tilt > 5.0:
    tilt = 5.0

  #Press ESCAPE to terminate
  k = mykeys.read()
  if k >-1:
    cam_vec = CAMERA.get_direction()
    if k==119:    #key W
      xm += cam_vec[0]
      zm += cam_vec[2]
    elif k==115:  #kry S
      xm -= cam_vec[0]
      zm -= cam_vec[2]
    elif k==97:   #key A
      xm -= cam_vec[2] * 0.25
      zm += cam_vec[0] * 0.25
    elif k==100:  #key D
      xm += cam_vec[2] * 0.25
      zm -= cam_vec[0] * 0.25
    elif k==112:  #key P
        pi3d.screenshot("walkaboutRobot.jpg")
    elif k==27:    #Escape key
      mykeys.close()
      mymouse.stop()
      DISPLAY.destroy()
      break
    else:
        print(k)
    ym = mymap.calcHeight(xm, zm) + avhgt
