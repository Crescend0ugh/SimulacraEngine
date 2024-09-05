#version 450

layout(binding = 0) uniform UniformBufferObject
{
    mat4 model;
    mat4 view;
    mat4 projection;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormals;
layout(location = 3) in vec2 inTexCoord;
layout(location = 2) in vec3 inColor;

layout(location = 0) out vec3 fragPosition;
layout(location = 1) out vec2 fragTexCoord;
layout(location = 2) out vec3 fragNormals;

float map(float value, float min1, float max1, float min2, float max2) {
    return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

void main() {
    vec4 positionWorld =  ubo.model * vec4(inPosition, 1.0);
    gl_Position = ubo.projection * ubo.view * positionWorld;
    fragPosition = vec3(positionWorld);
    fragTexCoord = inTexCoord;
    fragNormals = inNormals;
}