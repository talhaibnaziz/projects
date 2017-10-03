#!/usr/bin/python
from __future__ import absolute_import, division, print_function, unicode_literals

""" The basic ForestWalk but with shadows cast onto the ElevationMap using
the ShadowCaster class.
Also demonstrates passing an array of objects to the MergeShape.merge()
method which is much faster for adding large numbers of objects
"""

import math, random

import demo
import pi3d

# Setup display and initialise pi3d
DISPLAY = pi3d.Display.create()
DISPLAY.set_background(0.4,0.8,0.8,1)      # r,g,b,alpha
# yellowish directional light blueish ambient light
#TODO doesn't cope with z direction properly
mylight = pi3d.Light(lightpos=(-2.0, -1.0, 0.0), lightcol=(1.0, 1.0, 0.8), lightamb=(0.25, 0.2, 0.3))
CAMERA = pi3d.Camera.instance()

#========================================
# load shader
shader = pi3d.Shader("shadow_uv_bump")
shinesh = pi3d.Shader("uv_reflect")
flatsh = pi3d.Shader("uv_flat")

tree2img = pi3d.Texture("textures/tree2.png")
tree1img = pi3d.Texture("textures/tree1.png")
hb2img = pi3d.Texture("textures/hornbeam2.png")
bumpimg = pi3d.Texture("textures/grasstile_n.jpg")
reflimg = pi3d.Texture("textures/stars.jpg")
rockimg = pi3d.Texture("textures/rock1.jpg")

FOG = ((0.3, 0.3, 0.4, 0.8), 650.0)
TFOG = ((0.2, 0.24, 0.22, 1.0), 350.0)

#myecube = pi3d.EnvironmentCube(900.0,"HALFCROSS")
ectex=pi3d.loadECfiles("textures/ecubes","sbox")
myecube = pi3d.EnvironmentCube(size=900.0, maptype="FACES", name="cube")
myecube.set_draw_details(flatsh, ectex)

# Create elevation map
mapwidth = 1000.0
mapdepth = 1000.0
mapheight = 45.0 # can't cope with much elevation
mountimg1 = pi3d.Texture("textures/mountains3_512.jpg")
mymap = pi3d.ElevationMap("textures/mountainsHgt.jpg", name="map",
                     width=mapwidth, depth=mapdepth, height=mapheight,
                     divx=32, divy=32) #testislands.jpg
mymap.set_draw_details(shader, [mountimg1, bumpimg, bumpimg], 128.0, 0.0)
mymap.set_fog(*FOG)

#Create tree models
treeplane = pi3d.Plane(w=4.0, h=5.0)

treemodel1 = pi3d.MergeShape(name="baretree")
treemodel1.merge([[treeplane, 0,0,0, 0,0,0, 1,1,1],
                [treeplane, 0,0,0, 0,90,0, 1,1,1]])

treemodel2 = pi3d.MergeShape(name="bushytree")
treemodel2.merge([[treeplane, 0,0,0, 0,0,0, 1,1,1],
                [treeplane, 0,0,0, 0,60,0, 1,1,1],
                [treeplane, 0,0,0, 0,120,0, 1,1,1]])

#Scatter them on map using Merge shape's cluster function
mytrees1 = pi3d.MergeShape(name="trees1")
mytrees1.cluster(treemodel1.buf[0], mymap, 50.0, 200.0, 50.0, 500.0, 50, "", 5.0, 20.0)
mytrees1.set_draw_details(flatsh, [tree2img], 0.0, 0.0)
mytrees1.set_fog(*TFOG)

mytrees2 = pi3d.MergeShape(name="trees2")
mytrees2.cluster(treemodel2.buf[0], mymap, 0.0, 0.0, 200.0, 300.0, 5,"",3.0,7.0)
mytrees2.set_draw_details(flatsh, [tree1img], 0.0, 0.0)
mytrees2.set_fog(*TFOG)

mytrees3 = pi3d.MergeShape(name="trees3")
mytrees3.cluster(treemodel2, mymap,0.0, 0.0, 600.0, 100.0, 5,"", 4.0, 20.0)
mytrees3.set_draw_details(flatsh, [hb2img], 0.0, 0.0)
mytrees3.set_fog(*TFOG)

#is it a bird? is it a plane?
myplane = pi3d.Plane(h=80.0, w=80.0)
myplane.set_draw_details(shinesh, [rockimg, bumpimg, reflimg], 2.0, 0.6)
xrot, yrot, zrot = 90.0, 0.0, 0.0 #degrees
dxrot, dyrot, dzrot = 0.01, 0.22, 0.061
radius = 100.0
angle = 0.0
rotn = 0.012 #radians
elev = 80.0

#screenshot number
scshots = 1

#avatar camera
rot = 0.0
tilt = 0.0
avhgt = 7.0
xm = 0.0
zm = 0.0
ym = mymap.calcHeight(xm, zm) + avhgt

myshadows = pi3d.ShadowCaster(position=[xm, ym, zm], light=mylight)

# Fetch key presses
mykeys = pi3d.Keyboard()
mymouse = pi3d.Mouse(restrict = False)
mymouse.start()

omx, omy = mymouse.position()

# main loop
while DISPLAY.loop_running():
  CAMERA.reset()
  CAMERA.rotate(tilt, rot, 0)
  CAMERA.position((xm, ym, zm))

  xrot += dxrot
  yrot += dyrot
  zrot += dzrot
  angle += rotn
  myplane.position(radius * math.cos(angle) - radius, elev, radius * math.sin(angle))
  myplane.rotateToX(xrot)
  myplane.rotateToY(yrot)
  myplane.rotateToZ(zrot)

  # put the shadows onto the shadowcaster texture
  myshadows.start_cast([xm, ym, zm])
  myshadows.cast_shadow(mytrees1)
  myshadows.cast_shadow(mytrees2)
  myshadows.cast_shadow(mytrees3)
  myshadows.cast_shadow(myplane)
  myshadows.cast_shadow(mymap)
  myshadows.end_cast()

  myplane.draw()
  mymap.draw(shader, [mountimg1, bumpimg, myshadows], 128.0, 0.0, light_camera=myshadows.LIGHT_CAM)
  myecube.draw()
  mytrees2.draw()
  mytrees3.draw()
  mytrees1.draw()

  mx, my = mymouse.position()

  rot -= (mx-omx)*0.2
  tilt += (my-omy)*0.2
  omx=mx
  omy=my

  #Press ESCAPE to terminate
  k = mykeys.read()
  if k >-1:
    if k==119:  #key W
      xm -= math.sin(math.radians(rot))
      zm += math.cos(math.radians(rot))
      ym = mymap.calcHeight(xm, zm) + avhgt
    elif k==115:  #kry S
      xm += math.sin(math.radians(rot))
      zm -= math.cos(math.radians(rot))
      ym = mymap.calcHeight(xm, zm) + avhgt
    elif k==39:   #key '
      tilt -= 2.0
    elif k==47:   #key /
      tilt += 2.0
    elif k==97:   #key A
      rot -= 2
    elif k==100:  #key D
      rot += 2
    elif k==112:  #key P
      pi3d.screenshot("forestWalk"+str(scshots)+".jpg")
      scshots += 1
    elif k==10:   #key RETURN
      mc = 0
    elif k==27:  #Escape key
      mykeys.close()
      mymouse.stop()
      DISPLAY.stop()
      break
    else:
      print(k)

  CAMERA.was_moved = False
quit()
