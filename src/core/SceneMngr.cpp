//
// Created by Admin on 21/02/2025.
//

#include <MyEngine/SceneMngr.h>

using namespace My;

void SceneMngr::Insert(Scene* scene) {
	scenes->insert(scene);
}

void SceneMngr::Erase(Scene* scene) {
	scenes->erase(scene);
}

void SceneMngr::Active(Scene* scene, SObj* main_camera_sobj) {
	scenes->insert(scene);
	actived_scene = scene;
	this->main_camera_sobj = main_camera_sobj;
}
