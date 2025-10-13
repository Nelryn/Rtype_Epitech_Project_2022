#pragma once

#include "Window.hpp"
#include "ParseConfig.hpp"
#include "boost/property_tree/ptree.hpp"
#include "ResourcesManager.hpp"
#include "Factory.hpp"
#include "Map.hpp"
#include "Quadtree.hpp"
#include "ClientUdpAsync.hpp"
#include "ClientTcpAsync.hpp"

namespace sfge
{
    class StateManager;
    class Core
    {
        public:
            ~Core();
            static Core *getInstance();
            void run();
            void readEntity(std::string const &filePath);
            void createEntity(std::string const &name);
            ResourcesManager *m_resource_manager;
            Factory *factory;
            StateManager *m_state;
            void setMap(std::string const &filePath);
            void loadMap(std::string const &filePath);


            std::unique_ptr<ClientUdpAsync> _clientUdp;

            bool _online = false;
            unsigned int idPlayer;
            packet_t __packet__;

        private:
            void loadTexture(std::string const &filePath);
            Core();
            static Core *m_instance;
            IWindow *m_window;
            Map *m_current_map;
            std::unordered_map<std::string, Map *> m_map;
            Quadtree *_quadtree;
            int _port;
            std::string _ip;
    };
}       // namespace sfge