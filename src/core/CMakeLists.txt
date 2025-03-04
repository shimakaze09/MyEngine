GET_TARGET_NAME(IMGUI "${PROJECT_SOURCE_DIR}/src/_deps/imgui")
GET_TARGET_NAME(IMGUI_IMPL "${PROJECT_SOURCE_DIR}/src/_deps/imgui_impl")

ADD_TARGET(
        MODE STATIC
        SOURCE
        "${PROJECT_SOURCE_DIR}/include/MyEngine"
        LIB
        glfw
        ${imgui}
        My::MyRTR_core
        LIB_PRIVATE
        ${imgui_impl}
        INC
        include
)