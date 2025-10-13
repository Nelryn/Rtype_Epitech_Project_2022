#include "Core.hpp"
#include "Collidable.hpp"
#include "Move.hpp"
#include "AState.hpp"
#include "StateManager.hpp"
#include "CoreError.hpp"
#include "Movable.hpp"

namespace sfge
{
    Core::Core()
    {
        int width = 0;
        int heidth = 0;
        this->m_resource_manager = new ResourcesManager();
        loadTexture("Configuration/config_texture.json");
        this->factory = new Factory;
        this->factory->addComponent<Move>("Move");
        this->factory->addComponent<Collidable>("Collidable");
        this->factory->addComponent<Movable>("Movable");



        this->factory->createBuilder("Wall");
        this->factory->addBuilderComponent({"Collidable"});
        this->factory->pushBuilder();

        std::string filename = "Configuration/config_window.json";
        ParseConfig *parseConfig = new ParseConfig(filename);
        boost::property_tree::ptree pt = parseConfig->getAllData();
        loadMap("Configuration/config_map.json");
        // std::cout << "Window: " << m_window->getWindow().getSize().x << std::endl;
        try {
            width = pt.get<int>("width");
            heidth = pt.get<int>("height");
            std::string title = pt.get<std::string>("name");
            int fps = pt.get<int>("framelimit");
            m_window = new Window(width, heidth, title);
            m_window->setFramerateLimit(pt.get<int>("framelimit"));
            m_state = StateManager::getInstance();
            readEntity("Configuration/config_entity.json");
            if (pt.get<std::string>("online").compare("True") == 0) {
                _online = true;
                _port = pt.get<int>("port");
                _ip = pt.get<std::string>("ip");
                std::cout << _ip << ": " << _port << std::endl;
            }
        } catch (CoreError &error) {
            std::cerr << error.what() << std::endl;
        }
        ParseConfig *parseQuadtree = new ParseConfig("Configuration/config_quadtree.json");
        boost::property_tree::ptree qt = parseQuadtree->getAllData();
        try {
            float marge = qt.get<float>("marge");
            int level = qt.get<int>("level");
            int maxLevel = qt.get<int>("maxLevel");
            _quadtree = new Quadtree(0, 0, width, heidth, level, maxLevel, marge);
        } catch (boost::property_tree::ptree_error &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }

    Core::~Core()
    {
        delete factory;
        delete m_state;
        delete m_window;
        delete m_resource_manager;
    }

    Core *Core::getInstance()
    {
        if (m_instance == nullptr) {
            //std::cout << "Core created" << std::endl;
            m_instance = new Core();
        }
        return m_instance;
    }

    void Core::run()
    {
        if (_online == true) {
            _clientUdp = std::make_unique<ClientUdpAsync>(_ip, _port);
        }

        while (m_window->isOpen())
        {
            _quadtree->AddObject(this->m_state->entityManager->getEntities());
            std::vector<unsigned int> ent = _quadtree->detectCollision();
            for (auto &it : this->m_state->entityManager->getEntities()) {
                std::shared_ptr<Collidable> col;
                for (auto &it2 : ent) {
                    if (it->getId() == it2) {
                        col = it->getComponent<Collidable>();
                        if (col != nullptr) {
                            col->setCollide(true);
                        }
                    }
                }
            }
            m_window->pollEvent();
            if (_online == true) {
                __packet__ = _clientUdp->pollEvent();
                if (__packet__.magic[0] == 'E' &&  __packet__.magic[1] == 'L' && __packet__.magic[2] == 'F' && int(__packet__.idCommand) == 1) {
                    std::cout << "ADD " << std::endl;
                    this->createEntity("Ally");
                }
            }

            
            m_state->getState().update();
            m_window->clearWindow();
            m_state->getState().draw(m_window->getWindow());
            m_window->displayWindow();
            for (auto &it : this->m_state->entityManager->getEntities()) {
                std::shared_ptr<Collidable> col;
                col = it->getComponent<Collidable>();
                if (col != nullptr) {
                    col->setCollide(false);
                }
            }
            _quadtree->clearQuadtree();
        }
    }

    Core *Core::m_instance = nullptr;

    void Core::readEntity(std::string const &filePath)
    {
        ParseConfig parser(filePath);
        boost::property_tree::ptree pt = parser.getAllData();
        std::vector<std::pair<const std::string, boost::property_tree::ptree>> _dataEntity;

        for (auto &it : pt) {
            _dataEntity.push_back(it);
        }
        for (auto &it : _dataEntity) {
            try {
                std::string path = it.second.get<std::string>("sprite");
                int x = it.second.get<int>("x");
                int y = it.second.get<int>("y");
                int width = it.second.get<int>("width");
                int height = it.second.get<int>("height");
                // int tx = it.second.get<int>("testx");
                // int ty = it.second.get<int>("testy");
                std::vector<int> scale;
                for (auto &ite : it.second.get_child("scale")) {
                    scale.push_back(std::stoi(ite.second.data()));
                }
                std::vector<std::string> component;
                for (auto &itera : it.second.get_child("component")) {
                    ////std::cout << itera.second.data() << std::endl;
                    component.push_back(itera.second.data());
                }
                // create the entity
                this->factory->createBuilder(it.first);
                // set this entity position
                this->factory->setBuilderPosition(x, y);
                // set the sprite of this entity
                this->factory->setBuilderSprite(this->m_resource_manager->getTexture(path), path);
                // set the rectangle to animate this entity
                this->factory->setBuilderSize(width, height);
                // add component to our entity
                this->factory->addBuilderComponent(component);
                // push our new entity in the entity lists
                // this->factory->setBuilderIsPlayable(tx, ty);
                this->factory->pushBuilder();
            } catch (CoreError error) {
                std::cerr << error.what() << std::endl;
            }
        }
    }

    void Core::createEntity(std::string const &name)
    {
        Entity *ent = this->factory->createEntity(name);
        if (ent == nullptr)
            return;
        this->m_state->AddEntity(ent);
    }

    void Core::loadTexture(std::string const &filePath)
    {
        ParseConfig parser(filePath);
        boost::property_tree::ptree pt = parser.getAllData();

        for (auto &it : pt) {
            //std::cout << "load " << it.first.data() << std::endl;
            this->m_resource_manager->loadTexture(it.first, it.second.data());
        }
    }

    void Core::loadMap(std::string const &filepath)
    {
        ParseConfig parser(filepath);
        boost::property_tree::ptree pt = parser.getAllData();
        std::vector<std::pair<const std::string, boost::property_tree::ptree>> _dataEntity;
        std::string texture;
        std::string file;
        std::vector<float> speed;
        std::vector<float> scale;

        for (auto &it : pt) {
            _dataEntity.push_back(it);
        }
        for (auto &it : _dataEntity) {
            file = it.second.get<std::string>("file");
            texture = it.second.get<std::string>("texture");
            for (auto &ite : it.second.get_child("speed")) {
                speed.push_back(std::stof(ite.second.data()));
            }
            for (auto &ite : it.second.get_child("scale")) {
                scale.push_back(std::stof(ite.second.data()));
            }
        }
        std::cout << "load map" << filepath << std::endl;
        for (auto &it : pt) {
            Map *map = new Map(file, texture, sf::Vector2f(speed.at(0), speed.at(1)), sf::Vector2f(scale.at(0), scale.at(1)));
            map->loadMap(file, this);
            map->setSprite(texture, this);
            this->m_map[it.first.data()] = map;
        }
    }

    void Core::setMap(std::string const &name)
    {
        this->m_state->getState().setMap(this->m_map[name]);
    }
}       // namespace sfge
