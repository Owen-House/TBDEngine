#pragma once
#include "component.h"
#include "glm\glm.hpp"

class Light: public Component {
public:
    glm::vec3 color;
    float intensity;
    Light(const glm::vec3 color = {1.0f, 1.0f, 1.0f} , float intensity = 1.0f)
        : color(color), intensity(intensity)
    {
        type = LIGHT;
    }
};
