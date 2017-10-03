#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import absolute_import, division, print_function, unicode_literals

""" Depth of field blurring also demos MergeShape radial copying
To blur something against its background both object are drawn to an offscreen
texture. They are then drawn to the screen with a depth blur effect.

The Font class is also demonstrated. This generates a texture from
a true-type font file on the RPi system or added from an external resource
(standard fonts are available on raspbian in /usr/share/fonts/truetype)

This demo also shows the use of an additional orthographic camera for
rendering the string in 2D. If you change the Display size you will see
that the text stays the same size, also the text will be rendered on top
of the 3d view. x and y locations for the text represent pixel offsets
from the centre of the screen
"""
import math, random, time

import demo
import sys
if sys.version_info[0] == 3:
  unichr = chr

import pi3d

LOGGER = pi3d.Log(__name__, level='INFO', format='%(message)s')
# or you can log to file, or use default format
#LOGGER = pi3d.Log(__name__, level='DEBUG', file='dump.txt')
#LOGGER = pi3d.Log(__name__, level='ERROR')
''' to display all the pi3d module logging activity you must leave the
name argument blank (it will default to None) this will set the logger
to the root logger i.e.
'''
#LOGGER = pi3d.Log(level='DEBUG')
# these can be changed subsequently using LOGGER.set_logs()
MESSAGE = """\
blurring
with
distance!
---------
justified
multiline
unicode æ ö ¼
Strings """ + unichr(255) + ' ' + unichr(256) + ' ' + unichr(257)

# character 255 should appear, character 256 should not.

# Setup display and initialise pi3d
DISPLAY = pi3d.Display.create(x=10, y=10, w=900, h=600, frames_per_second=25)
DISPLAY.set_background(0.4, 0.6, 0.8, 1.0)      # r,g,b,alpha

persp_cam = pi3d.Camera.instance() # default instance camera perspecive view
ortho_cam = pi3d.Camera(is_3d=False) # 2d orthographic view camera

#setup textures, light position and initial model position
pi3d.Light((0, 5, 0))
#create shaders
shader = pi3d.Shader("uv_reflect")
flatsh = pi3d.Shader("uv_flat")
defocus = pi3d.Defocus()

#Create textures
shapeimg = pi3d.Texture("textures/straw1.jpg")
shapebump = pi3d.Texture("textures/floor_nm.jpg")
shapeshine = pi3d.Texture("textures/pong3.png")

#Create shape
myshape = pi3d.MergeShape(camera=persp_cam) #specify perspective view
asphere = pi3d.Sphere(sides=16, slices=16)
myshape.radialCopy(asphere, step=72)
myshape.position(0.0, 0.0, 5.0)
myshape.set_draw_details(shader, [shapeimg, shapebump, shapeshine], 8.0, 0.1)

mysprite = pi3d.Sprite(w=10.0, h=10.0, camera=persp_cam)
mysprite.position(0.0, 0.0, 15.0)
mysprite.set_draw_details(flatsh, [shapebump])

tick=0
next_time = time.time()+2.0

#load ttf font and set the font colour to 'raspberry'
arialFont = pi3d.Font("fonts/NotoSerif-Regular.ttf",  (221,0,170,255),
                    add_codepoints=[256])
arialFont.blend = True #much better anitaliased look but must String.draw() after everything else      
mystring = pi3d.String(font=arialFont, string=MESSAGE,
                  camera=ortho_cam, z=1.0, is_3d=False, justify="r") # orthographic view
mystring.set_shader(flatsh)

# Fetch key presses.
mykeys = pi3d.Keyboard()

# Display scene and rotate shape
while DISPLAY.loop_running():

  defocus.start_blur()
  # 1. drawing objects now renders to an offscreen texture ####################
  mysprite.draw()
  myshape.draw()
  defocus.end_blur()
  # 2. drawing now back to screen. The texture can now be used by defocus.blur()

  # 3. redraw these two objects applying a distance blur effect ###############
  defocus.blur(myshape, 4, 9, 5) # 4 is focal distance, >= 9 distance will get
  defocus.blur(mysprite, 4, 9, 5) # 5 x blurring, nearer than focus also blurs

  myshape.rotateIncY(1.247)
  myshape.rotateIncX(0.1613)

  mystring.draw()
  mystring.rotateIncZ(0.05)

  if time.time() > next_time:
    LOGGER.info("FPS: %4.1f", (tick / 2.0))
    tick=0
    next_time = time.time() + 2.0
  tick+=1

  k = mykeys.read()
  if k==112:
    pi3d.screenshot("blur1.jpg")
  elif k==27:
    mykeys.close()
    defocus.delete_buffers()
    DISPLAY.destroy()
    break

