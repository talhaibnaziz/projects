#!/usr/bin/python
from __future__ import absolute_import, division, print_function, unicode_literals

""" Landscape from ElevationMap with model tanks and buildings. Demonstrates using
a function to draw the various parts of the tank and the ElevationMap.pitch_roll()
method to make models conform (aproximately) to the surface of an ElevationMap.
The tank gun is raised as the mouse view point to looking up. This shows how to
combine various rotations about different axes without the objects falling apart!
This demo also uses a tkinter tkwindow but creates it as method of Display. Compare
with the system used in demos/MarsStation.py
Also look out for:
2D shader usage. Drawing onto an ImageSprite canvas placed in front of the camera
imediately after reset() This is used to generate a splash screed during file
loading and to draw a telescopic site view and a navigation map
"""
import math, random, time, traceback

import demo
import pi3d

LOGGER = pi3d.Log(__name__, level='INFO')

# Create a Tkinter window
winw, winh, bord = 1200, 600, 0     #64MB GPU memory setting
# winw,winh,bord = 1920,1200,0   #128MB GPU memory setting

DISPLAY = pi3d.Display.create(tk=True, window_title='Tiger Tank demo in Pi3D',
                        w=winw, h=winh - bord, far=3000.0,
                        background=(0.4, 0.8, 0.8, 1), frames_per_second=16)

#inputs = InputEvents()
#inputs.get_mouse_movement()

pi3d.Light(lightpos=(-1, -1, 1), lightcol =(0.8, 0.8, 0.8), lightamb=(0.30, 0.30, 0.32))

win = DISPLAY.tkwin

shader = pi3d.Shader('uv_bump')
flatsh = pi3d.Shader('uv_flat')
shade2d = pi3d.Shader('2d_flat')

#========================================
# create splash screen and draw it
splash = pi3d.ImageSprite("textures/tiger_splash.jpg", shade2d, w=10, h=10, z=0.2)
splash.draw()
DISPLAY.swap_buffers()

# create environment cube
ectex = pi3d.loadECfiles('textures/ecubes/Miramar', 'miramar_256',
                                    suffix='png')
myecube = pi3d.EnvironmentCube(size=1800.0, maptype='FACES')
myecube.set_draw_details(flatsh, ectex)

# Create elevation map
mapwidth = 2000.0
mapdepth = 2000.0
mapheight = 100.0
mountimg1 = pi3d.Texture('textures/mountains3_512.jpg')
bumpimg = pi3d.Texture('textures/grasstile_n.jpg')
tigerbmp = pi3d.Texture('models/Tiger/tiger_bump.jpg')
topbmp = pi3d.Texture('models/Tiger/top_bump.jpg')

mymap = pi3d.ElevationMap(mapfile='textures/mountainsHgt2.png',
                     width=mapwidth, depth=mapdepth,
                     height=mapheight, divx=64, divy=64)

mymap.set_draw_details(shader, [mountimg1, bumpimg], 128.0, 0.0)

FOG = (0.5, 0.5, 0.5, 0.8)

mymap.set_fog(FOG, 1000.0)

#Load tank
tank_body = pi3d.Model(file_string='models/Tiger/body.obj', sx=0.1, sy=0.1, sz=0.1)
tank_body.set_shader(shader)
tank_body.set_normal_shine(tigerbmp)

tank_gun = pi3d.Model(file_string='models/Tiger/gun.obj')
tank_gun.set_shader(shader)

tank_turret = pi3d.Model(file_string='models/Tiger/turret.obj')
tank_turret.set_shader(shader)
tank_turret.set_normal_shine(topbmp)
### because these children will inherit matrix operation applied to
#   their parent they don't need to be scaled
tank_body.add_child(tank_turret)
tank_turret.add_child(tank_gun)

#Load church
x, z = 20, -320
y = mymap.calcHeight(x,z)

church = pi3d.Model(file_string='models/AllSaints/AllSaints.obj',
          sx=0.1, sy=0.1, sz=0.1, x=x, y=y, z=z)
church.set_shader(shader)

#Load cottages
x, z = 250,-40
y = mymap.calcHeight(x,z)

cottages = pi3d.Model(file_string='models/Cottages/cottages_low.obj',
          sx=0.1, sy=0.1, sz=0.1, x=x, y=y, z=z, ry=-5)
cottages.set_shader(shader)

#cross-hairs in gun sight
targtex = pi3d.Texture("textures/target.png", blend=True)
target = pi3d.ImageSprite(targtex, shade2d, w=10, h=10, z=0.4)
target.set_2d_size(targtex.ix, targtex.iy, (DISPLAY.width - targtex.ix)/2,
                  (DISPLAY.height - targtex.iy)/2)

#telescopic gun sight
sniptex = pi3d.Texture("textures/snipermode.png", blend=True)
sniper = pi3d.ImageSprite(sniptex, shade2d, w=10, h=10, z=0.3)
scx = DISPLAY.width/sniptex.ix
scy = DISPLAY.height/sniptex.iy
if scy > scx:
  scx = scy # enlarge to fill screen but use same scale for both directions
scw, sch = sniptex.ix * scx, sniptex.iy * scx
sniper.set_2d_size(scw, sch, (DISPLAY.width - scw)/2,(DISPLAY.height - sch)/2)

#corner map and dots
smmap = pi3d.ImageSprite(mountimg1, shade2d, w=10, h=10, z=0.2)
smmap.set_2d_size(w=200, h=200, x=DISPLAY.width - 200, y=DISPLAY.height - 200)
dot1 = pi3d.ImageSprite("textures/red_ball.png", shade2d, w=10, h=10, z=0.1)
dot1.set_2d_size(w=10, h=10) # 10x10 pixels
dot2 = pi3d.ImageSprite("textures/blu_ball.png", shade2d, w=10, h=10, z=0.05)
dot2.set_2d_size(w=10, h=10)

#player tank vars
tankrot = 180.0
turret = 0.0
tankroll = 0.0     #side-to-side roll of tank on ground
tankpitch = 0.0    #too and fro pitch of tank on ground
enemyroll = 0.0
enemypitch = 0.0

#key presses
mymouse = pi3d.Mouse(restrict = False)
mymouse.start()
omx, omy = mymouse.position()

#position vars
mouserot = 0.0
tilt = 0.0
avhgt = 0.85
xm, oxm = 0.0, -1.0
zm, ozm = -200.0, -1.0
ym = mymap.calcHeight(xm, zm) + avhgt

#enemy tank vars
etx = 120
etz = -120
etr = 0.0

ltm = 0.0 #last pitch roll check
smode = False #sniper mode

def drawTiger(x, y, z, rot, roll, pitch, turret, gunangle):
  tank_body.position(x, y, z)
  tank_body.rotateToX(pitch)
  tank_body.rotateToY(rot-90)
  tank_body.rotateToZ(roll)
  tank_turret.rotateToY(turret - rot)
  tank_gun.rotateToZ(gunangle)
  tank_body.draw() # children drawn too.


# Update display before we begin (user might have moved window)
win.update()
DISPLAY.resize(win.winx, win.winy, win.width, win.height - bord)

is_running = True
CAMERA = pi3d.Camera.instance()

try:
  while DISPLAY.loop_running():
    mx, my = mymouse.position()
    mouserot -= (mx-omx)*0.2
    tilt += (my-omy)*0.2
    omx=mx
    omy=my

    CAMERA.reset()
    dot1.set_2d_location(DISPLAY.width - 105.0 + 200.0*xm/mapwidth,
                        DISPLAY.height - 105.0 - 200.0*zm/mapdepth)
    dot2.set_2d_location(DISPLAY.width - 105.0 + 200.0*etx/mapwidth,
                        DISPLAY.height - 105.0 - 200.0*etz/mapdepth)
    dot1.draw()
    dot2.draw()
    smmap.draw()
    # tilt can be used to prevent the view from going under the landscape!
    sf = 60 - 55.0 / abs(tilt) if tilt < -1 else 5.0
    xoff = sf * math.sin(math.radians(mouserot))
    yoff = abs(1.25 * sf * math.sin(math.radians(tilt))) + 3.0
    zoff = -sf * math.cos(math.radians(mouserot))

    if tilt > -5 and smode == False: # zoom in
      CAMERA.reset(lens=(1, 3000, 12.5, DISPLAY.width / DISPLAY.height))
      smode = True
    elif tilt <= -5 and smode == True: # zoom out
      CAMERA.reset(lens=(1, 3000, 45, DISPLAY.width / DISPLAY.height))
      smode = False

    #adjust CAMERA position in and out so we can see our tank
    CAMERA.rotate(tilt, mouserot, 0)
    CAMERA.position((xm + xoff, ym + yoff + 5, zm + zoff))
    oxm, ozm = xm, zm

    #draw player tank with smoothing on pitch and roll to lessen jerkiness
    drawTiger(xm, ym, zm, tankrot, tankroll, tankpitch, 180 - turret, ((tilt+20)*-1.0 if tilt > -20.0 else 0.0))

    mymap.draw()           # Draw the landscape

    #Draw enemy tank
    etdx = -math.sin(math.radians(etr))
    etdz = -math.cos(math.radians(etr))
    etx += etdx
    etz += etdz
    #ety = mymap.calcHeight(etx, etz) + avhgt # see below
    etr += 0.5
    pitch, roll = mymap.pitch_roll(etx, etz)
    ety = mymap.ht_y + avhgt # calcHeight is now called as part of pitch_roll
    enemypitch = enemypitch * 0.9 + pitch * 0.1
    enemyroll = enemyroll * 0.9 + roll * 0.1
    drawTiger(etx, ety, etz, etr, enemyroll, enemypitch, etr, 0)

    #Draw buildings
    church.draw()
    cottages.draw()

    myecube.position(xm, ym, zm)
    myecube.draw()  #Draw environment cube

    if smode:
      """ because some of the overlays have blend=True they must be done AFTER
      other objects have been rendered.
      """
      target.draw()
      sniper.draw()

    # turns player tankt turret towards center of screen which will have a crosshairs
    if turret + 2.0 < mouserot:
      turret += 2.0
    if turret - 2.0 > mouserot:
      turret -= 2.0

    try:
      win.update()
    except Exception as e:
      LOGGER.info("bye,bye2 %s", e)
      DISPLAY.destroy()
      try:
        win.destroy()
      except:
        pass
      mymouse.stop()
      exit()
    if win.ev == "resized":
      LOGGER.info("resized")
      DISPLAY.resize(win.winx, win.winy, win.width, win.height-bord)
      CAMERA.reset((DISPLAY.near, DISPLAY.far, DISPLAY.fov,
                  DISPLAY.width / float(DISPLAY.height)))
      win.resized = False
    if win.ev == "key":
      mv = False
      if win.key == "w":
        xm -= math.sin(math.radians(tankrot)) * 2
        zm -= math.cos(math.radians(tankrot)) * 2
        mv = True
      elif win.key == "s":
        xm += math.sin(math.radians(tankrot)) * 2
        zm += math.cos(math.radians(tankrot)) * 2
        mv = True
      elif win.key == "a":
        tankrot -= 2
      elif win.key == "d":
        tankrot += 2
      elif win.key == "p":
        pi3d.screenshot("TigerTank.jpg")
      elif win.key == "Escape":
        try:
          LOGGER.info("bye,bye1")
          DISPLAY.destroy()
          try:
            win.destroy()
          except:
            pass
          mymouse.stop()
          exit()
        except:
          pass
      if mv: # moved so recalc pitch_roll
        pitch, roll = mymap.pitch_roll(xm, zm)
        tankpitch = tankpitch * 0.9 + pitch * 0.1
        tankroll = tankroll * 0.9 + roll * 0.1
        ym = mymap.ht_y + avhgt # calcHeight done by pitch_roll
    if win.ev=="drag" or win.ev=="click" or win.ev=="wheel":
      xm -= math.sin(math.radians(tankrot)) * 2
      zm -= math.cos(math.radians(tankrot)) * 2
      ym = (mymap.calcHeight(xm, zm) + avhgt)
    else:
      win.ev=""  #clear the event so it doesn't repeat

except Exception as e:
  LOGGER.info("bye,bye3 %s", e)
  DISPLAY.destroy()
  try:
    win.destroy()
  except:
    pass
  mymouse.stop()
  exit()
