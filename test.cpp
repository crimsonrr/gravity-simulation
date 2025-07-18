
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>  
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <thread>
#include <chrono>

int main() {
    glm::vec3 position = glm::vec3(0.0f, 100.0f, 0.0f);  // start 100m high
    glm::vec3 velocity = glm::vec3(0.0f);
    glm::vec3 gravity = glm::vec3(0.0f, -9.81f, 0.0f);
    float deltaTime = 0.1f;  // seconds per simulation step

    for (int step = 0; step < 100; ++step) {
        // Euler integration
        velocity += gravity * deltaTime;
        position += velocity * deltaTime;

        std::cout << "Step " << step << ": "
                  << "y = " << position.y
                  << ", vy = " << velocity.y
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
