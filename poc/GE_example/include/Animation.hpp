/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Animation
*/

#pragma once

#include <vector>

struct FrameData 
{
    int id; // Texture id (retrieved from our texture allocator).
    int x; // x position of sprite in the texture.
    int y; // y position of sprite in the texture.
    int width; // Width of sprite.
    int height; // Height of sprite.
    float displayTimeSeconds; // How long to display the frame.
};

enum class FacingDirection
{
    None,
    Left,
    Right
};

class Animation {
    public:
        Animation(FacingDirection direction);
        ~Animation();
        void AddFrame(int textureID, int x, int y,
        int width, int height, float frameTime);
        const FrameData* GetCurrentFrame() const;
        bool UpdateFrame(float deltaTime);
        void Reset();
        void SetDirection(FacingDirection dir);
        FacingDirection GetDirection() const;
    protected:
    private:
        void IncrementFrame();
        // Stores all frames for our animation.
        std::vector<FrameData> frames;
        // Current frame.
        int currentFrameIndex;
        // We use this to decide when to transition to the next frame.
        float currentFrameTime;
        FacingDirection direction;
};