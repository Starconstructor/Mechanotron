VkPhysicalDevice physicalDevice;
VkDevice device;
VkQueue graphicsQueue;

int deviceGud(VkPhysicalDevice device)
{
  VkPhysicalDeviceProperties deviceProps;
  vkGetPhysicalDeviceProperties(device, &deviceProps);

  VkPhysicalDeviceFeatures deviceFeatures;
  vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

  if (deviceProps.deviceType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
  {
    printf("This software runs best on discrete GPUs. Are you sure running it is a good idea?\n");
  }
  else
  {
    printf("Discrete GPU detected. Proceeding with device verification.\n");
  }

  return 0;
}

uint32_t getQueueFamilies(VkPhysicalDevice device)
{
  uint32_t quFamCount = 0;
  vkGetPhysicalDeviceQueueFamilyProperties(device, &quFamCount, NULL);
  VkQueueFamilyProperties quFams[quFamCount];

  uint32_t arbnumber[quFamCount];
  vkGetPhysicalDeviceQueueFamilyProperties(device, &quFamCount, quFams);
  for (int i = 0; i < quFamCount; i++)
  {
    arbnumber[i] = i;
  }
  return *arbnumber;
}

int grabPhysicalDevice(VkInstance instance)
{
  physicalDevice = VK_NULL_HANDLE;

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
    VkPhysicalDevice device = devices[x];
    if (deviceGud(device) == 0)
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

int makLogicalDevice(VkInstance instance, int layerNum, const char* ValidLayers[1], int enableValidLayers)
{
  graphicsQueue = 0;
  uint32_t famdices = getQueueFamilies(physicalDevice);

  VkDeviceQueueCreateInfo quCreateInfo = {0};
  quCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  quCreateInfo.queueFamilyIndex = famdices;
  quCreateInfo.queueCount = 1;

  float quPriority = 1.0f;
  quCreateInfo.pQueuePriorities = &quPriority;

  VkPhysicalDeviceFeatures deviceFeats = {0};

  VkDeviceCreateInfo createInfo = {0};
  createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

  createInfo.pQueueCreateInfos = &quCreateInfo;
  createInfo.queueCreateInfoCount = 1;

  createInfo.pEnabledFeatures = &deviceFeats;

  createInfo.enabledExtensionCount = 0;
  createInfo.pNext = 0;

  if (enableValidLayers == 0)
  {
    createInfo.enabledLayerCount = (uint32_t)layerNum;
    createInfo.ppEnabledLayerNames = ValidLayers;
  } else {
    createInfo.enabledLayerCount = 0;
  }
  if (vkCreateDevice(physicalDevice, &createInfo, NULL, &device) != VK_SUCCESS)
  {
    printf("Failed to create logical device. Prepare for doom!\n");
    return 1;
  }
  vkGetDeviceQueue(device, famdices, 0, &graphicsQueue);

  printf("Logical device initialized.\n");
  return 0;
}
