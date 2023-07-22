#pragma once

#include "model.h"

#include <memory>

struct Transform2DComponent {
    glm::vec2 translation{};
    glm::vec2 scale{1.0f, 1.0f};
    float rotation;

    glm::mat2 mat2() {
        const float s = glm::sin(rotation);
        const float c = glm::cos(rotation);
        glm::mat2 rotMatrix{{c, s}, {-s, c}};
        glm::mat2 scaleMat{{scale.x, 0.0f}, {0.0f, scale.y}};
        return rotMatrix * scaleMat;
    };
};

class GameObject {
  public:
    using id_t = unsigned int;

    std::shared_ptr<Model> model{};
    glm::vec3 color{};
    Transform2DComponent transform2D{};

    static GameObject createGameObject() {
        static id_t currentId = 0;
        return GameObject{currentId++};
    }

    id_t getId() {
        return id;
    }

  private:
    GameObject(id_t objId) : id(objId) {}

    id_t id;
};