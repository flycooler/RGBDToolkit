#version 110

	void main(void){
		vec4 v = vec4(gl_Vertex);		
		v.z = sin(5.0*v.x )*0.25;
		
		gl_Position = ftransform() * v;
		//gl_Position = gl_ModelViewProjectionMatrix * v;
		gl_TexCoord[0] = gl_MultiTexCoord0;
	} 

/*
void main(void){
	gl_Position = ftransform();
	gl_TexCoord[0] = gl_MultiTexCoord0;
}
*/