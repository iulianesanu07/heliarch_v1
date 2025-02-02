#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


static unsigned int CompileShader(unsigned int type, const std::string& source) {
  unsigned int id = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE) {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char* message = (char*)alloca(length * sizeof(char));
    glGetShaderInfoLog(id, length, &length, message);
    std::cout << "Failed to compile " << 
      (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
    std::cout << message << std::endl;
    glDeleteShader(id);
    return 0;
  }

  return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}

int main() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW!" << std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);


  GLFWwindow *window = glfwCreateWindow(800, 600, "Heliarch", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create window!" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW!" << std::endl;
    return -1;
  }

  std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

  unsigned int vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  float positions[6] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f
  };

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  // index, size, type, normalized, stride, pointer
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

  std::string vertexShader = 
    "#version 410 core\n"
    "\n"
    "layout(location = 0) in vec2 position;\n"
    "\n"
    "void main()\n"
    "{\n"
    "  gl_Position = vec4(position, 0.0, 1.0);\n"
    "}\n";

  std::string fragmentShader = 
    "#version 410 core\n"
    "\n"
    "layout(location = 0) out vec4 color;\n"
    "\n"
    "void main()\n"
    "{\n"
    "  color = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

  unsigned int shader = CreateShader(vertexShader, fragmentShader);
  glUseProgram(shader);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(shader);

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
