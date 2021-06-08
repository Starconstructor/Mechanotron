int deviceGud()
{
  return 0;
}

int grabPhysicalDevice(VkInstance instance)
{
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

  unsigned int devCount = 0;
  vkEnumeratePhysicalDevices(instance, &devCount, NULL);

  if (devCount == 0)
  {
    printf("Your GPU is too weak for this epic Vulkan shit\n");
    return 1;
  }

  VkPhysicalDevice devices[devCount];
  vkEnumeratePhysicalDevices(instance, &devCount, devices);

  for (int x = 0; x < devCount; x++)
  {
    VkPhysicalDevice* device = devices[x];
    if (deviceGud() == 0)
    {
      physicalDevice = device;
      break;
    }
  }

  if (physicalDevice == VK_NULL_HANDLE)
  {
    printf("Bro where is ur GPU I can't find it\n");
    return 1;
  }

  return 0;
}
