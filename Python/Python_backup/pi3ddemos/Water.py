#!/usr/bin/python
from __future__ import absolute_import, division, print_function, unicode_literals

""" Animated normal map to give rippling reflection as off the surface of water
there is a fog applied to the water surface with an alpha of zero so that it fades
in the distance

There is also an offset applied applied to the uv texture mapping for the water.
Although there is no texture (it uses mat_reflect shader) the offset is
carried through to the normal map texture. It is not used to offset the
reflection image.

The text here uses the Pngfont class which is generally not as good as the
normal Font but can be used where Pillow isn't installed such as with
python_for_android.

This demo also shows the effect of set_material() in combination with a
uv mapped texture.

The normal map for shapebump is generated from a standard image using
the normal_map argument

3D perlin noise creation application in
textures/water/noise_normal.py
"""
import math, random, time, glob

import demo
import pi3d

print("=====================================================")
print("press escape to escape")
print("move this terminal window to top of screen to see FPS")
print("=====================================================")

# Setup display and initialise pi3d
DISPLAY = pi3d.Display.create(x=200, y=150, frames_per_second=25.0)
DISPLAY.set_background(0.4, 0.6, 0.8, 0.5)      # r,g,b,alpha

#setup textures, light position and initial model position
pi3d.Light((5, -5, 8))
#create shaders
shader = pi3d.Shader("uv_reflect")
matsh = pi3d.Shader("mat_reflect")
flatsh = pi3d.Shader("uv_flat")

#Create textures
shapeimg = pi3d.Texture("textures/straw1.jpg")
shapebump = pi3d.Texture("textures/straw1.jpg", normal_map=-6.0)
waterbump = []
iFiles = glob.glob("textures/water/n_norm???.png")
iFiles.sort() # order is vital to animation!
for f in iFiles:
  waterbump.append(pi3d.Texture(f))
num_n = len(waterbump)
shapeshine = pi3d.Texture("textures/stars.jpg")

#Create shape
myshape = pi3d.MergeShape()
num = (2, 2)
asphere = pi3d.Sphere(sides=32)
for i in range(num[0]):
  for j in range(num[1]):
    myshape.add(asphere, -num[0]*0.9 + 1.8*i, -num[1]*0.9 +1.8*j, 0.0)

myshape.position(0.0, 0.0, 5)
myshape.set_draw_details(shader, [shapeimg, shapebump, shapeshine], 1.0, 0.1)

mywater = pi3d.LodSprite(w=250.0, h=250.0, n=6)
mywater.set_draw_details(matsh, [waterbump[0], shapeshine], 14.0, 0.6)
mywater.set_material((0.1, 0.25, 0.3))
mywater.set_fog((0.4, 0.6, 0.8, 0.0),100)
mywater.rotateToX(85.0)
mywater.position(10.0, -2.0, 0.0)

font = pi3d.Pngfont("fonts/GillSansMT.png", (221,0,170,255))
mystring = pi3d.String(font=font, string="Now the Raspberry Pi really does rock")
mystring.translate(0.0, 0.0, 1)
mystring.set_shader(flatsh)

tick = 0
av_fps = 0
i_n=0
spf = 0.1 # seconds per frame, i.e. water image change
next_time = time.time() + spf
dx = 0.02
offset = 0.0 # uv offset
do = -0.001 # uv increment

# Fetch key presses.
mykeys = pi3d.Keyboard()
fr = 0
# Display scene and rotate shape
while DISPLAY.loop_running():

  myshape.draw()
  myshape.rotateIncY(0.247)
  myshape.rotateIncZ(0.1613)
  myshape.translateX(dx)
  if myshape.x() > 5: dx = -0.05
  elif myshape.x() < -5: dx = 0.05

  mywater.draw()
  offset = (offset + do) % 1.0 # move texture offset in v direction
  mywater.set_offset((0.0, offset))

  mystring.draw()
  mystring.rotateIncZ(0.05)

  if time.time() > next_time:
    i_n = (i_n + 1) % num_n
    mywater.buf[0].textures[0] = waterbump[i_n]
    next_time = time.time() + spf
    av_fps = av_fps*0.9 + tick/spf*0.1 # exp smooth moving average
    print(av_fps,"FPS")
    tick = 0

  tick += 1

  fr += 1
  myshape.set_material((math.sin(fr*0.102) * 0.25 + 0.5, 
                        math.sin(fr*0.073) * 0.25 + 0.5, 
                        math.sin(fr*0.067) * 0.25 + 0.5))

  k = mykeys.read()
  if k==112:
    pi3d.screenshot("water1.jpg")
  elif k==27:
    mykeys.close()
    DISPLAY.destroy()
    break

quit()
