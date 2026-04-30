#pragma once
#ifndef KIERO_VULKAN_HPP
#define KIERO_VULKAN_HPP

#include <unordered_map>
#include <string>

namespace kiero {

enum {
  Implementation_Vulkan = KIERO_IMPL_FREE_SLOT,
};

struct VulkanOutput {
  // function name -> function pointer
  std::unordered_map<std::string, void*> methods;
};

} // namespace kiero

#undef KIERO_IMPL_CURR_SLOT
#define KIERO_IMPL_CURR_SLOT kiero::Implementation_Vulkan

#endif // KIERO_VULKAN_HPP
