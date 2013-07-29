
#version 120
#extension GL_EXT_geometry_shader4 : enable

varying vec3 normal;

//--------------------------------------------------------------
vec3 quaternionRotation(vec3 original, float angle, vec3 axis) {
    normalize(axis);
    float hcos = cos(angle / 2);
    float hsin = sin(angle / 2);
    float q10 = hcos;
    float q11 = axis.x * hsin;
    float q12 = axis.y * hsin;
    float q13 = axis.z * hsin;
    
    float q20 = hcos;
    float q21 = -axis.x * hsin;
    float q22 = -axis.y * hsin;
    float q23 = -axis.z * hsin;

    float qo0 = 0;
    float qo1 = original.x;
    float qo2 = original.y;
    float qo3 = original.z;
    
    float qt0 = q10 * qo0 - q11 * qo1 - q12 * qo2 - q13 * qo3;
    float qt1 = q10 * qo1 + q11 * qo0 + q12 * qo3 - q13 * qo2;
    float qt2 = q10 * qo2 - q11 * qo3 + q12 * qo0 + q13 * qo1;
    float qt3 = q10 * qo3 + q11 * qo2 - q12 * qo1 + q13 * qo0;
    
    float qe0 = qt0 * q20 - qt1 * q21 - qt2 * q22 - qt3 * q23;
    float qe1 = qt0 * q21 + qt1 * q20 + qt2 * q23 - qt3 * q22;
    float qe2 = qt0 * q22 - qt1 * q23 + qt2 * q20 + qt3 * q21;
    float qe3 = qt0 * q23 + qt1 * q22 - qt2 * q21 + qt3 * q20;
    
    return vec3(qe1, qe2, qe3);
}
//--------------------------------------------------------------

void main() {
	float PI = 3.14159265359;
	float TWO_PI =  PI * 2;
	float radius = 6;
	vec3 p0 = gl_PositionIn[0].xyz;
	
	int hslices = 6; 
	int vslices = 12; 
	vec3 d, n;
	for (int i = 0; i < hslices; i ++) {
		float vTheta = PI / hslices * i - PI / 2;
		float cosV = cos(vTheta);
		float sinV = sin(vTheta);
		float vTheta2 = PI / hslices * (i + 1) - PI / 2;
		float cosV2 = cos(vTheta2);
		float sinV2 = sin(vTheta2);
		
		for (int j = 0; j <= vslices; j ++) {
			float cosH = cos(TWO_PI / vslices * j);
			float sinH = sin(TWO_PI / vslices * j);
			
			d = vec3(cosH * cosV, sinH * cosV, sinV);
			gl_Position = gl_ModelViewProjectionMatrix * vec4(p0 + d * radius, 1.0);
			normal = normalize(d);
			EmitVertex();
			
			cosH = cos(TWO_PI / vslices * j);
			sinH = sin(TWO_PI / vslices * j);
			
			d = vec3(cosH * cosV2, sinH * cosV2, sinV2);
			gl_Position = gl_ModelViewProjectionMatrix * vec4(p0 + d * radius, 1.0);
			normal = normalize(d);
			EmitVertex();
			
		}
	}
}
