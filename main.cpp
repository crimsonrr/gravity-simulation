#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

    class Particle {
        public: 
            glm::vec3 position;
            glm::vec3 velocity;
            glm::vec3 acceleration;
            float mass;
            std::string name;

            void printState(float deltaTime, int frame) {
                   std::cout << "Frame: " << frame << std::endl;
                    std::cout << "dt: " << deltaTime << std::endl;
                    std::cout << "Velocity: " << glm::to_string(velocity) << std::endl;
                    std::cout << name << "(position): " << glm::to_string(position) << std::endl;
                    std::cout << "----------------------------\n";
                    // std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS (more realistic, but difficult to read)
                    std::this_thread::sleep_for(std::chrono::milliseconds(300)); 
            }

            void update(float deltaTime) {
                velocity += acceleration * deltaTime;
                position += velocity * deltaTime;
            }
        };

    int main() {
        std::vector<Particle> particles;

        Particle p1, p2, p3, p4;

        p1.name = "Alpha";
        p1.position = glm::vec3(0.0f, 0.0f, 0.0f);
        p1.velocity = glm::vec3(0.0f, 1.0f, 0.f);
        p1.acceleration = glm::vec3(0.0f, -9.8f, 0.0f);

        p2.name = "Beta";
        p2.position = glm::vec3(2.0f, 0.0f, 0.0f);
        p2.velocity = glm::vec3(1.0f, 2.0f, 0.f);
        p2.acceleration = glm::vec3(0.0f, -9.8f, 0.0f);

        p3.name = "Gamma";
        p3.position = glm::vec3(-1.0f, 2.0f, 0.0f);
        p3.velocity = glm::vec3(0.5f, 0.0f, 0.f);
        p3.acceleration = glm::vec3(0.0f, -9.8f, 0.0f);

        p4.name = "Delta";
        p4.position = glm::vec3(5.0f, -3.0f, 0.0f);
        p4.velocity = glm::vec3(2.0f, 0.5f, 0.f);
        p4.acceleration = glm::vec3(0.0f, -9.8f, 0.0f);



        particles.push_back(p1);
        particles.push_back(p2);
        particles.push_back(p3);
        particles.push_back(p4);

        int frame = 0;
        auto previousTime = std::chrono::high_resolution_clock::now(); // measures how much time has passed since the last frame

        bool firstFrame = true;
        
        while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<float> elapsed = currentTime - previousTime;
        float deltaTime = elapsed.count();

    /** allow previousTime to update to get the actual elapsedTime */
        if (firstFrame) {
            deltaTime = 0.0f;
            firstFrame = false;
        }

        previousTime = currentTime;

        for (auto& p : particles) {
           p.update(deltaTime);
           p.printState(deltaTime, frame);

    }
    frame++;
           std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }

    }
    