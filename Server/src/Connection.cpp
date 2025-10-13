#include "Connection.hpp"


Connection::Connection(unsigned char  __idCli, boost::asio::ip::udp::endpoint &endpoint) : idCli(__idCli), _endpoint(endpoint)
{

}

Connection::~Connection()
{

}




//quand tu connecte pour la première fois le client udp le serveur tonne un id au client et le serveur le renvoie au client pour qu'il puisse le stocker dans une map avec l'endpoint du client. Ensuite le serveur peut envoyer des messages au client en utilisant l'id du client comme clé dans la map.