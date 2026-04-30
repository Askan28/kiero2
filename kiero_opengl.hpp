#pragma once
#ifndef KIERO_OPENGL_HPP
#define KIERO_OPENGL_HPP

#include <string>
#include <unordered_map>

namespace kiero {

enum {
  Implementation_OpenGL = KIERO_IMPL_FREE_SLOT,
};

struct OpenGLOutput {
  // function name -> function pointer
  std::unordered_map<std::string, void*> methods;
};

} // namespace kiero

#undef KIERO_IMPL_CURR_SLOT
#define KIERO_IMPL_CURR_SLOT kiero::Implementation_OpenGL

#endif // KIERO_OPENGL_HPP
