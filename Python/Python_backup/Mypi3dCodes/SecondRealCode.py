import pi3d
from rotatingcamera import RotatingCamera
from random import random, randint

#create display
DISPLAY = pi3d.Display.create()


#create a mouse object
mymouse = pi3d.Mouse(restrict = False)
mymouse.start()

#crate camera
CAM = RotatingCamera(5, mymouse)

#create keyboard object
mykeys = pi3d.Keyboard()

#create cubes
cube_list = [] #list for cubes

for i in range(10):
	cube = pi3d.Cuboid(x = i)
	cube.set_material((random(), random(), random()))
	cube_list.append(cube)


#display loop:
while DISPLAY.loop_running():
	#listen for keystrokes
	k = mykeys.read()
	if k == 27: #if ESC key is pressed
		mykeys.close()
		DISPLAY.destroy() #sounds so dramatic
		break
	CAM.update(mymouse)
	for cube in cube_list:
		cube.draw()
