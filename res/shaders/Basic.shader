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

void main()
{
  color = vec4(0.0745f, 0.3922f, 0.5843f, 1.0);
}
