//
// Created by Admin on 21/02/2025.
//

#pragma once

#include <MyScene/core/core>

namespace My {
class SceneMngr {
 public:
  static SceneMngr& Instance() noexcept {
    static SceneMngr instance;
    return instance;
  }

  Read<SceneMngr, std::set<Scene*>> scenes;

  // rendering
  Read<SceneMngr, Scene*> actived_scene{nullptr};
  Read<SceneMngr, SObj*> main_camera_sobj{nullptr};

  void Insert(Scene* scene);
  void Erase(Scene* scene);
  void Active(Scene* scene, SObj* main_camera_sobj);
};
}  // namespace My
