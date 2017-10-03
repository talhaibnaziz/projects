import pi3d

DISPLAY = pi3d.Display.create()
DISPLAY.set_background(0.0, 0.0, 0.0, 0.1) #sets background black

shader = pi3d.Shader('uv_light')
earthimg = pi3d.Texture('textures/world_map.jpg')

ball = pi3d.Sphere(z = 5.0)
#chsnge the color of the ball:
#ball.set_material((1.8,0.0,0.0))

#listen for keystrokes
mykeys = pi3d.Keyboard()

#start the display loop:
while DISPLAY.loop_running():
	#store keystrokes:
	k = mykeys.read()
	if k == 27: #if ESC key is pressed
		mykeys.close()
		DISPLAY.destroy() #close the display
		break
	ball.draw(shader, [earthimg])
