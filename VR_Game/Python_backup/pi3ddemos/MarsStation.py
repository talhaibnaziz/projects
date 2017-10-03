#!/usr/bin/python
from __future__ import absolute_import, division, print_function, unicode_literals

""" Uses a Tkinter window with elevation map, and more complicated models
loaded from panda3d egg files. The models demostrate various things:
1. loading the shader for them to be drawn with 2. loading the normal map
file and reflection map file, although this is done for the whole model it can
be used to set them differently for each Buffer, i.e. different parts of the
Model. 3. level of detail drawing using Utility.draw_level_of_detail() This allows different
versions of the model to be shown as the viewpoint gets nearer, in this case
the distant one has the doors and windows closed, the near one open
"""
import math, random, time

import demo
import pi3d

rads = 0.017453292512  # degrees to radians

#Create a Tkinter window
# TODO: the display will do this for you automatically now
winw,winh,bord = 1200,600,0 #64MB GPU memory setting
#winw,winh,bord = 1920,1080,0 #128MB GPU memory setting

DISPLAY = pi3d.Display.create(tk=True, window_title='Mars Station demo in Pi3D',
                        w=winw, h=winh - bord, far=2200.0,
                        background=(0.4, 0.8, 0.8, 1), frames_per_second=20)

#inputs = InputEvents()

win = DISPLAY.tkwin

shader = pi3d.Shader("uv_reflect")
bumpsh = pi3d.Shader("uv_bump")
flatsh = pi3d.Shader("uv_flat")
shade2d = pi3d.Shader('2d_flat')

#========================================
# create splash screen and draw it
splash = pi3d.ImageSprite("textures/pi3d_splash.jpg", shade2d, w=10, h=10, z=0.2)
splash.draw()
DISPLAY.swap_buffers()
#############################
ectex = pi3d.loadECfiles("textures/ecubes/RedPlanet", "redplanet_256", "png", True)
myecube = pi3d.EnvironmentCube(size=1800.0, maptype="FACES")
myecube.set_draw_details(flatsh,ectex)

# Create elevation map
mapwidth=2000.0
mapdepth=2000.0
mapheight=100.0
redplanet = pi3d.Texture("textures/mars_colour.png")
bumpimg = pi3d.Texture("textures/mudnormal.jpg")
mymap = pi3d.ElevationMap(mapfile='textures/mars_height.png',
                     width=mapwidth, depth=mapdepth, height=mapheight,
                     divx=64, divy=64)
mymap.set_draw_details(bumpsh,[redplanet, bumpimg],128.0, 0.0)
mymap.set_fog((0.3, 0.15, 0.1, 0.0), 1000.0)

#Load Corridors sections

sttnbmp = pi3d.Texture("textures/floor_nm.jpg")
sttnshn = pi3d.Texture("textures/stars.jpg")
x,z = 0,0
y = mymap.calcHeight(x, z)
#corridor with windows
cor_win = pi3d.Model(file_string="models/MarsStation/corridor_win_lowpoly.egg",
                x=x, y=y, z=z, sx=0.1, sy=0.1, sz=0.1)
cor_win.set_shader(shader)
#normal corridor
corridor = pi3d.Model(file_string="models/MarsStation/corridor_lowpoly.egg",
                 x=x, y=y, z=z, sx=0.1, sy=0.1, sz=0.1)
corridor.set_shader(shader)
#corridor crossing
cor_cross = pi3d.Model(file_string="models/MarsStation/cross_room.egg",
                 x=x, y=y, z=z, sx=0.1, sy=0.1, sz=0.1)
cor_cross.set_shader(shader)
cor_cross.set_normal_shine(sttnbmp, 32.0, sttnshn, 0.1)
#corridor crossing with doors
cor_cross_doors = pi3d.Model(file_string="models/MarsStation/cross_room_doors.egg",
                        x=x, y=y, z=z, sx=0.1, sy=0.1, sz=0.1)
cor_cross_doors.set_shader(shader)
cor_cross_doors.set_normal_shine(sttnbmp, 32.0, sttnshn, 0.1)
#corridor with 90 degree bend
cor_bend = pi3d.Model(file_string="models/MarsStation/bend_lowpoly.egg",
                 x=x, y=y, z=z, sx=0.1, sy=0.1, sz=0.1)
cor_bend.set_shader(shader)
cor_bend.set_normal_shine(sttnbmp, 32.0)
cor_bend.rotateToY(180)

#position vars
mouserot=0.0
tilt=0.0
avhgt = 5.3
xm=0.0
zm=0.0
ym= (mymap.calcHeight(xm,zm) + avhgt)
spc = 39.32
mody = ym + 3.0
opendist = 80

#key presses
mymouse = pi3d.Mouse(restrict = False)
mymouse.start()
omx, omy = mymouse.position()

# Update display before we begin (user might have moved window)
win.update()
DISPLAY.resize(win.winx, win.winy, win.width, win.height - bord)

CAMERA = pi3d.Camera.instance()
#inputs.get_mouse_movement()

try:
  while DISPLAY.loop_running():
    CAMERA.reset()

    #tilt can be used as a means to prevent the view from going under the landscape!
    if tilt < -1: sf = 6 - 5.5/abs(tilt)
    else: sf = 0.5
    xoff, yoff, zoff = sf*math.sin(mouserot*rads), abs(1.25*sf*math.sin(tilt*rads)) + 3.0, -sf*math.cos(mouserot*rads)
    CAMERA.rotate(tilt, mouserot, 0)
    CAMERA.position((xm + xoff, ym + yoff +5, zm + zoff))

    pi3d.Utility.draw_level_of_detail([xm, ym, zm], [0, mody, 0], [[opendist,cor_cross],[1000,cor_cross_doors]])
    #90 degree units
    corridor.rotateToY(90)
    cor_win.rotateToY(90)
    cor_win.position(0, mody, spc*1.5)
    cor_win.draw()
    corridor.position(0, mody, spc*2.5)
    corridor.draw()
    cor_win.position(0, mody, spc*3.5)
    cor_win.draw()
    cor_win.position(0, mody, spc*6.5)
    cor_win.draw()
    #0 degree units
    corridor.rotateToY(0)
    cor_win.rotateToY(0)
    pi3d.Utility.draw_level_of_detail([xm, ym, zm], [0, mody, spc*5],[[opendist,cor_cross],[1000,cor_cross_doors]])
    pi3d.Utility.draw_level_of_detail([xm, ym, zm],[0, mody, spc*8], [[opendist,cor_cross],[1000,cor_cross_doors]])
    cor_win.position(-spc*1.5, mody, spc*5)
    cor_win.draw()
    cor_bend.position(-spc*2.5, mody, spc*5)
    cor_bend.draw()
    pi3d.Utility.draw_level_of_detail([xm, ym, zm],[-spc*2.6, mody, spc*6.6],[[opendist,cor_cross],[1000,cor_cross_doors]])
    cor_win.position(spc*1.5, mody, spc*5)
    cor_win.draw()
    corridor.position(spc*2.5, mody, spc*5)
    corridor.draw()
    pi3d.Utility.draw_level_of_detail([xm, ym, zm],[spc*4, mody, spc*5],[[opendist,cor_cross],[1000,cor_cross_doors]])

    myecube.position(xm, ym, zm)
    myecube.draw()#Draw environment cube

    mymap.draw()  #Draw the landscape after as transparent fog

    mx, my = mymouse.position()
    mouserot -= (mx-omx)*0.2
    tilt += (my-omy)*0.2
    omx=mx
    omy=my
    try:
      win.update()
    except Exception as e:
      print("bye,bye2", e)
      DISPLAY.destroy()
      try:
        win.destroy()
      except:
        pass
      mymouse.stop()
      exit()
    if win.ev == "resized":
      print("resized")
      DISPLAY.resize(win.winx, win.winy, win.width, win.height-bord)
      CAMERA.reset((DISPLAY.near, DISPLAY.far, DISPLAY.fov,
                  DISPLAY.width / float(DISPLAY.height)))
      win.resized = False
    if win.ev == "key":
      if win.key == "w":
        xm-=math.sin(mouserot*rads)*10
        zm+=math.cos(mouserot*rads)*10
      if win.key == "s":
        xm+=math.sin(mouserot*rads)*2
        zm-=math.cos(mouserot*rads)*2
      if win.key == "a":
        mouserot -= 2
      if win.key == "d":
        mouserot += 2
      if win.key == "p":
        pi3d.screenshot("MarsStation.jpg")
      if win.key == "Escape":
        try:
          print("bye,bye1")
          DISPLAY.destroy()
          try:
            win.destroy()
          except:
            pass
          mymouse.stop()
          exit()
        except:
          pass
    if win.ev=="drag" or win.ev=="click" or win.ev=="wheel":
      xm-=math.sin(mouserot*rads)*2
      zm+=math.cos(mouserot*rads)*2
    else:
      win.ev=""  #clear the event so it doesn't repeat

except Exception as e:
  print("bye,bye3", e)
  DISPLAY.destroy()
  try:
    win.destroy()
  except:
    pass
  mymouse.stop()
  exit()

