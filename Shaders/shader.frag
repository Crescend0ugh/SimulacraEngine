#version 450

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragPosition;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragNormals;



layout(location = 0) out vec4 outColor;

vec3 lightColor = vec3(1.0,1.0,1.0);
vec3 objectColor = vec3(1, 0.5, 0.5);
vec3 ambient = vec3(0.01,0.01,0.01);

void main() {

    vec3 light_position = vec3(-2,1,2)*2;
    vec3 lightDirection = normalize(light_position-fragPosition);
    vec3 norms = normalize(fragNormals);
    float diff = max(dot(norms, lightDirection), 0.0);
    vec3 diffuse = diff * lightColor;
    vec3 result = (ambient + diffuse) * objectColor;
    outColor = vec4(result, 1.0);
}