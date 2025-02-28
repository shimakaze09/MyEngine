//
// Created by Admin on 21/02/2025.
//

#include <MyEngine/SceneMngr.h>

#include <MyScene/core/Scene.h>

using namespace My;

bool SceneMngr::Insert(Scene* scene) {
  if (updatetingScenes->find(scene) != updatetingScenes->end() ||
      toStopScenes->find(scene) != toStopScenes->end())
    return false;

  toStartScenes->insert(scene);
  return true;
}

bool SceneMngr::Erase(Scene* scene) {
  if (updatetingScenes->find(scene) == updatetingScenes->end())
    return false;

  toStopScenes->insert(scene);
  return true;
}

bool SceneMngr::Active(Scene* scene, SObj* main_camera_sobj) {
  if (toStopScenes->find(scene) != toStopScenes->end())
    return false;
  if (updatetingScenes->find(scene) == updatetingScenes->end() &&
      toStartScenes->find(scene) == toStartScenes->end())
    Insert(scene);
  actived_scene = scene;
  this->main_camera_sobj = main_camera_sobj;
  return true;
}

void SceneMngr::Update() {
  for (auto scene : toStartScenes)
    updatetingScenes->insert(scene);
  toStartScenes->clear();

  for (auto scene : toStopScenes) {
    updatetingScenes->erase(scene);
    if (actived_scene == scene) {
      actived_scene = nullptr;
      main_camera_sobj = nullptr;
    }
  }
  toStopScenes->clear();
}
