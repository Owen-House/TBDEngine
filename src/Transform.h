//
// Created by owenh on 10/17/2024.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "Component.h"

using namespace glm;

class Transform : Component {
public:
    vec3 position();
    vec3 rotation();
    vec3 size();

    Transform(const vec3 v_position = vec3(0.0, 0.0, 0.0), const vec3 v_size = vec3(0.0, 0.0, 0.0)
            , const vec3 v_rotation = vec3(0.0, 0.0, 0.0))
    {
        position() = v_position;
        rotation() = v_rotation;
        size() = v_size;
    }
};



#endif //TRANSFORM_H
