#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#define BG1     "./assets/Parallax/background_1.png"
#define BG2     "./assets/Parallax/background_2.png"
#define BG3     "./assets/Parallax/background_3.png"
#define BG4     "./assets/Parallax/background_4.png"

namespace sfge {
    class Parallax {
        public:
            /**
             * @brief  Constructor Parallax class
             */
            Parallax();
            /**
             * @brief  Destructor Parallax class
             */
            ~Parallax();

            /**
             * @brief  Draw the parallax
             * @note   Draw every sprite in the vector<sprite>
             * @param  &w: Rendered window
             * @retval None
             */
            void draw(sf::RenderWindow &w);

            /**
             * @brief  anime the parallax
             * @note   use the vector<int> vel & vecot<sprite> to move the texture
             * @retval None
             */
            void animateParallax();

        private:
            std::vector<int> _vel;
            std::vector<std::shared_ptr<sf::Texture>> _txtureTab;
            std::vector<std::shared_ptr<sf::Sprite>> _spriteTab;
    };
}