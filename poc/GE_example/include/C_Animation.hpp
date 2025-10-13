/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** C_Animation
*/

#pragma once

#include "Component.hpp"
#include "Animation.hpp"
#include <memory>

class C_Sprite;

enum class AnimationState
{
    None,
    Idle,
    Walk
};

class C_Animation : public Component {
    public:
        C_Animation(Object* owner);
        ~C_Animation();
        void Awake() override;
        void Update(float deltaTime) override;
        // Add animation to object. We need its state as well
        // so that we can switch to it.
        void AddAnimation(AnimationState state,
        std::shared_ptr<Animation> animation);
        // Set current animation states.
        void SetAnimationState(AnimationState state);
        // Returns current animation state.
        const AnimationState& GetAnimationState() const;
        void SetAnimationDirection(FacingDirection dir);
    protected:
    private:
        std::shared_ptr<C_Sprite> sprite; // 1
        std::map<AnimationState, std::shared_ptr<Animation>> animations;
        // We store a reference to the current animation so we
        // can quickly update and draw it.
        std::pair<AnimationState,
        std::shared_ptr<Animation>> currentAnimation;
};
