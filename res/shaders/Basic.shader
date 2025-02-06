#shader vertex
#version 410 core

layout(location = 0) in vec2 position;

void main()
{
  gl_Position = vec4(position, 0.0, 1.0);
}

#shader fragment 
#version 410 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
  color = u_Color;
}
