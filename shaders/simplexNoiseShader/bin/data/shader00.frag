void main (void){
	gl_FragColor = vec4(1.0, gl_TexCoord[0].s / 1280.0, gl_TexCoord[0].t / 720.0, 1.0);
}