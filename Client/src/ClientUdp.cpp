/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** Client Udp
*/

#include "ClientUdp.hpp"

namespace sfge {

ClientUdp::ClientUdp(boost::asio::io_context &ioc, std::string addr) : 
    _socket(ioc), _endpoint(boost::asio::ip::make_address(addr.c_str()), 4545)
{
    _socket.open(udp::v4());
}

//serveur qui tourne
//deux clients qui se connectent 
//bougent syncroniser
//tire des missiles

//un debut de moteur de jeu pour faciliter
//ecs simplifier tout autre type de jeu
//bout de la game engine
//partie réseau
//+ readme + wiki
//doxygène
//diagrame de classe complet; liaison
//entité deplacer avec input-entité ssprite-elle estanime-liste anim- app.run
//app.add player

//bareme
//cmake
//gestionnaire paquet sous linux compliqué 
//pas de lib dans un systeme
//cmake fetch (pour recup lib)
//cmake compile en trois ligne
//Pas de soluc au prblm//supp le probleme
//cpack  simplier recup lib compilation+generer fichier distribution 
//abstract graphic 
//reseau fonctionnel

//player tire
//ennemie
//background
//sprite animé client et un background en parallax
//follow up rtype semaine pro 16h

ClientUdp::~ClientUdp()
{
}

void ClientUdp::sendMsg(std::string msg)
{
    boost::shared_ptr<std::string> message(new std::string(msg));
    _socket.send_to(boost::asio::buffer(*message), _endpoint);
    //////std::cout"Sent: " << msg << " to " << _endpoint << std::endl;
}

void ClientUdp::receiveMsg()
{
    _recvBuffer.assign(0);
    _socket.receive_from(boost::asio::buffer(_recvBuffer), _endpoint);
    ////std::cout_endpoint << " : " << _recvBuffer.c_array() << std::endl;
}

void ClientUdp::start()
{
    while (1) {
        this->receiveMsg();
        //this->sendMsg(msg);
    }
}

}