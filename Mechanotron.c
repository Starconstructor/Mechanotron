#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "VulkanStuff.h"

int main()
{
  surface = 0;
  if (VkStuff() != 0)
  {
    printf("oh noes! Shutdown initiated!\n");
    return 1;
  }
  printf("Vulkan setup complete. Activating window.\n");

  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Vulkan", glfwGetPrimaryMonitor(), NULL);
  VkResult err = glfwCreateWindowSurface(instance, window, NULL, &surface);

  if (err != 0)
  {
    printf("Failure to create window surface. Code: %i. Terminating...\n", err);
    return 1;
  }

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, 1);
    }
  }

  VkDie();
}
