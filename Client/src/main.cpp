/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** main
*/

#include <iostream>
#include "bg.hpp"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "ClientUdpAsync.hpp"
#include "ClientTcpAsync.hpp"
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include <unordered_map>
#include "PlayState.hpp"
#include "Core.hpp"
#include "StateManager.hpp"

// typedef struct create_ent {
//     unsigned char type;
//     unsigned char id[2];
//     float x;
//     float y;
// } create_ent_t;

// typedef struct move_ent {
//     unsigned char id[2];
//     int x;
//     int y;
// } move_ent_t;

// void create_entity(ClientUdpAsync &client, std::unordered_map<std::string, sfge::Player *> &ent, int type)
// {
//     static char id[3] = {'a', 'a', 0};

//     if (id[1] ==  'z') {
//         id[0]++;
//         id[1] = 'a';
//     }
//     ////std::coutid[1] << " ht" << std::endl;

//     create_ent_t entty;

//     switch (type)
//     {
//     case 1:
//         entty.type = 1;
//         std::memcpy(&entty.id, &id, sizeof(char) * 2);
//         entty.x = 0;
//         entty.y = 0;

//         ent[id] = new sfge::Player;
//         ent[id]->ismoveable = true;
//         std::memcpy(&ent[id]->id, &id, 2);
//         packet_t pck;
//         pck.id = 'b';
//         std::memcpy(&pck.data, &entty, sizeof(create_ent_t));

//         client.sendPacket(pck);
//         break;
//     case 2:
//         ent[id] = new sfge::Player;
//         ent[id]->ismoveable = false;
//         entty.type = 1;
//         std::memcpy(&ent[id]->id, &id, 2);
//         packet_t pck2;
//         pck2.id = 'b';
//         std::memcpy(&pck2.data, &entty, sizeof(create_ent_t));
//         client.sendPacket(pck2);

//         //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//         packet pck3;
//         pck3.id = 'd';
//         std::memcpy(&pck3.data, id, 2);
//         pck.data[2] = 0;
//         client.sendPacket(pck3);
//         break;
//     default:
//         break;
//     }
//     id[1]++;
// }

// void create_entity_local(std::unordered_map<std::string, sfge::Player *> &ent, int type)
// {
//     static char id[3] = {'a', 'a', 0};

//     if (id[1] ==  'z') {
//         id[0]++;
//         id[1] = 'a';
//     }

//     switch (type) {
//     case 1:
//         ent[id] = new sfge::Player;
//         ent[id]->ismoveable = true;
//         std::memcpy(&ent[id]->id, &id, 2);
//         break;
//     case 2:
//         ent[id] = new sfge::Player;
//         ent[id]->ismoveable = false;
//         std::memcpy(&ent[id]->id, &id, 2);
//     default:
//         break;
//     }
//     id[1]++;
// }

// void move(std::unordered_map<std::string, sfge::Player *> &ent, packet_t pack)
// {
//     move_ent_t *move = (move_ent_t *)pack.data;
//     char id[3] = {move->id[0], move->id[1], '\0'};
//     ent[id]->move(move->x, move->y);
//     //std::cout << "la" << id << std::endl;
// }

// void setmovable(std::unordered_map<std::string, sfge::Player *> &ent, char id[2])
// {
//     //std::cout << "je crash ici" << std::endl;
//     char id2[3] = {id[0], id[1], '\0'};
//     //std::cout << id2 << std::endl;
//     ent[id2]->ismoveable = true;
//     //std::cout << "non ici" << std::endl;
// }

// int main(int ac, char **av)
// {
//     sf::RenderWindow win(sf::VideoMode(800, 600), "r-type");
//     std::unordered_map<std::string, sfge::Player *> ent;
//     sf::Clock clock;

//     if (ac < 4) {
//         //////std::cout"usage:" << std::endl;
//         //////std::cout"\t\t ./r-type_client <port> <addresse> <mode [host | client]>" << std::endl;
//         exit(84);
//     }
//     ClientUdpAsync client(av[1], 4242);
//     std::string mode(av[3]);
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));

//     win.setFramerateLimit(60);
//     if (mode == "client") {
//         packet_t newpack2;
//         newpack2.id = 'a';
//         client.sendPacket(newpack2);
//     } else if (mode == "host") {
//         packet_t newpack2;
//         newpack2.id = 255;
//         client.sendPacket(newpack2);
//     }

//     char ids[3] = {'E', 'E', 0};
//     sfge::Parallax bg;

//     if (mode == "host") {
//         create_entity(client, ent, 1);
//         create_entity(client, ent, 2);
//     } else {
//         create_entity(client, ent, 2);
//         create_entity(client, ent, 2);
//     }

//     while (win.isOpen()) {
//         sf::Event event;

//         while (win.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 win.close();
//             }
//             for (auto &en : ent) {
//                 sfge::Player *entity = en.second;
//                 entity->update(event, client);
//             }
//         }

//         packet_t packet = client.pollEvent();
//         if (mode == "host")
//         {
//             if (packet.id == 'a') {
//                 packet_t pck3;
//                 pck3.id = 'd';
//                 pck3.data[0] = 'a';
//                 pck3.data[1] = 'b';
//                 pck3.data[2] = 0;

//                 pck3.data[2] = 0;
//                 client.sendPacket(pck3);
//             }
//             if (packet.id == 'c') {
//                 move(ent, packet);
//             }
//         } else {
//             switch (packet.id) {
//             case 'b':
//                 ////std::cout"create entity" << std::endl;
//                 //create_entity_local(ent, 2);
//                 break;
//             case 'c':
//                 move(ent, packet);
//                 break;
//             case 'd':
//                 std::memcpy(&ids, &packet.data, 2);
//                 ////std::cout"je suis " << ids << std::endl;
//                 setmovable(ent, ids);
//                 break;
//             default:
//                 // packet_t newpack3;
//                 // newpack3.id = 'a';
//                 // client.sendPacket(newpack3);
//                 break;
//             }
//         }
//         sf::Time time;
//         float tempo = 0.05;
//         float seconds;

//         time = clock.getElapsedTime();
//         seconds = time.asMicroseconds() / 1000000.0;
//         if (seconds > tempo) {
//             bg.animateParallax();
//             clock.restart();
//         }
//         win.clear();
//         bg.draw(win);
//         for (auto &en : ent) {
//             sfge::Player * entity = en.second;
//             entity->draw(win);
//         }
//         win.display();
//     }
//     return 0;
// }

#include <iostream>

int main(void)
{
    sfge::Core *core = sfge::Core::getInstance();
    sfge::Playstate playState;

    sfge::StateManager *state = sfge::StateManager::getInstance();
    state->changeState(playState);
    
    core->setMap("Map");
    core->m_state->_stateStack.top()->_map->addEntityToEntityManager();
    core->run();
    return (0);
}
