//
// Created by Admin on 21/02/2025.
//

#pragma once

#include "SceneMngr.h"
#include "_deps/imgui/imgui.h"

#define MY_MYGL_GLAD 1
#include <MyGL/MyGL>

struct GLFWwindow;

#include <functional>

namespace My {
class DeferredRenderer;

class Engine {
 public:
  static Engine& Instance() {
    static Engine instance;
    return instance;
  }

  bool Init(const std::string& title);
  void Loop(std::function<void()> func);
  void CleanUp();

 private:
  Engine() = default;

  DeferredRenderer* rtr;
  GLFWwindow* window{nullptr};
};
}  // namespace My
