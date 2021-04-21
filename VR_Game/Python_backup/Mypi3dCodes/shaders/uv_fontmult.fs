precision mediump float;

uniform sampler2D tex0;
uniform vec3 unib[4];

varying float dist;
varying mat2 rotn;
varying vec2 corner;
varying float subsize;
varying float alpha;

void main(void) {
  if (distance(gl_PointCoord, vec2(0.5)) > 0.5) discard; //circular points
  vec2 p_centre = vec2(0.5, 0.5);
  vec2 rot_coord = rotn * (gl_PointCoord - p_centre) + p_centre;
  vec4 texc = texture2D(tex0, (rot_coord * subsize + corner));
  if (texc.a < unib[0][2]) discard; // ------ to allow rendering behind the transparent parts of this object
  gl_FragColor = texc;
  gl_FragColor.a = alpha;
}
