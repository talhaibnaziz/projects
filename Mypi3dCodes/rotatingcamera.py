'''Moving pi3d camera with mouse'''

import pi3d
from numpy import sin, cos, radians

class RotatingCamera:
	def __init__(self, CAMRAD, mouse):
		self.CAMERA = pi3d.Camera()
		#radius of camera position:
		self.CAMRAD = CAMRAD
		self.mouserot = 0.0 #rotation of camera
		self.tilt = 15.0 #tilt of camera
		self.frame = 0
		#"old" mouse position:
		self.omx, self.omy = mouse.position()
		
	def update(self, mouse):
		#"new" mouse position:
		self.mx, self.my = mouse.position()
		self.mouserot -= (self.mx - self.omx)*0.2
		self.tilt -= (self.my - self.omy) * 0.1
		self.omx = self.mx # the current mouse position becomes
		self.omy = self.my # the "old" mouse position
		self.CAMERA.reset() #you have to reset the camera first
		self.CAMERA.rotate(-self.tilt, self.mouserot, 0)
		self.CAMERA.position((self.CAMRAD * sin(radians(self.mouserot))*cos(radians(self.tilt)),
							self.CAMRAD * sin(radians(self.tilt)),
							-self.CAMRAD * cos(radians(self.mouserot)) * cos(radians(self.tilt))))
