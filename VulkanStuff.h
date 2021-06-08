#include <string.h>
#include "GPU_grabber.h"

VkDebugUtilsMessengerEXT debugMessenger;
VkInstance instance;

const int needLayerNumber = 1;
const char* ValidLayers[needLayerNumber] = {
  "VK_LAYER_KHRONOS_validation"
};

const int enableValidationLayers = 0;

int VkLayerSupport()
{
  unsigned int layerNumber;
  vkEnumerateInstanceLayerProperties(&layerNumber, NULL);

  VkLayerProperties availableLayers[layerNumber];
  vkEnumerateInstanceLayerProperties(&layerNumber, availableLayers);

  for (int i = 0; i < needLayerNumber; i++)
  {
    const char* layerName = ValidLayers[i];
    int layerFound = 1;

    for (int x = 0; x < layerNumber; x++)
    {
      const VkLayerProperties& layerProps = availableLayers[x];

      if (strcmp(layerName, layerProps.layerName) == 0)
      {
        layerFound = 0;
        break;
      }
    }

    if (layerFound == 1)
    {
      return 1;
    }
  }
  return 0;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
VkDebugUtilsMessageTypeFlagsEXT messageType,
const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)
{

  if (messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
  {
    fprintf(stderr, "Validation Layer: %s\n", pCallbackData->pMessage);
  }

  return VK_FALSE;
}

void fillDebugMessengerInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
  createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
  createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
  createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
  createInfo.pfnUserCallback = debugCallback;
}

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
  const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger)
{
  auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");

  if (func != NULL)
  {
    return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
  }
  else
  {
    return VK_ERROR_EXTENSION_NOT_PRESENT;
  }
}

void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
  auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
  if (func != NULL) {
        func(instance, debugMessenger, pAllocator);
    }
}

void setupDebugMessenger()
{
  if (enableValidationLayers != 0) return;

  VkDebugUtilsMessengerCreateInfoEXT createInfo;
  fillDebugMessengerInfo(createInfo);

  if (CreateDebugUtilsMessengerEXT(instance, &createInfo, NULL, &debugMessenger) != VK_SUCCESS) {
      printf("Nope, no debug messanger for you\n");
  }
}

int VkStuff()
{
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "KaoticEngine";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "N/A";
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  int vLayers = VkLayerSupport();
  if (enableValidationLayers == 0 && !vLayers == 0) printf("Requested validation layers not found. You probably misspelled something.\n");
  else printf("Requested validation layers verified. Proceeding with debug setup.\n");

  if (enableValidationLayers == 0)
  {
    createInfo.enabledLayerCount = needLayerNumber;
    createInfo.ppEnabledLayerNames = ValidLayers;

    VkDebugUtilsMessengerCreateInfoEXT validInfo;
    fillDebugMessengerInfo(validInfo);
    createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &validInfo;
  }
  else
  {
    createInfo.enabledLayerCount = 0;
  }

  if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS || grabPhysicalDevice(instance) != 0)
  {
    printf("Failure to create Vulkan instance. Terminating program.\n");
    return 1;
  }
  return 0;
}

void VkDie()
{
  if (enableValidationLayers == 0)
  {
    DestroyDebugUtilsMessengerEXT(instance, debugMessenger, NULL);
  }
  vkDestroyInstance(instance, NULL);
}
