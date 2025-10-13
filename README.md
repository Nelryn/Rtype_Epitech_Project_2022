# R-Type
The goal of this project is to implement a multithreaded server and a graphical client for a game called **R-type** using an engine of our own design.
To do that we MUST develop a Game engine with which we will be able to create a networked video game.

Made by : Emilie Baunifais, Leena Saibi, Ludovic Hou, Ludovic Peltier, Sandati Yahaya

# Server
- [x] The server is asynchrone
- [x] The server allow multiple player in one game
- [ ] The server MUST be multithreaded
- [x] The server MUST NOT block or wait for clients messages, as the game MUST run frame after frame on the server
- [x] In any case the server MUST have authority on what happens in the end
- [ ] If a client crashes for any reason, the server MUST continue to work and MUST notify other clients in the same game that a client crashed.

# Client
- [x] The client output is in SFML
- [x] The client already contains the necessities to launch the game
- [x] The client MUST display a slow horizontal scrolling background representing space with stars, planets... You MUST use timers
- [x] Players MUST be able to move using the arrow keys
- [ ] The four players in a game MUST be distinctly identifiable (via color, sprite, etc.)

# Requirements
- [x] The project is build using CMake and dependencies must be installed using CMakeFetch
- [ ] The project is cross platform
- [ ] The project can be packaged/delivered/installed standalone, without requiring building from sources, and with correct versioning
- [ ] You MUST provide a mean to build tarballs or installers for the game
- [ ] There MUST be Bydos slaves in your game

# Protocol
- [x] The clients and server communicate using binary protocol.
- [x] The server uses UDP communication.
- [x] The protocol is documented using an RFC.
- [x] The RFC is formatted as a real RFC.
- [x] Malformed messages or packets MUST NOT lead the client or server to crash

# Libraries
- [x] The rendering is done with the SFML.
- [x] The server is using Boost::Asio.

# Supported platforms
Using CMake as a cross-platform build system, it handles dependencies using CMakeFetch.
  * Linux : it generates a binary to launch the project AND a Makefile allowing to build the project
  * Windows : it generates a Visual Studio solution .sln

# Dependencies
  * Boost : Libraries that work well with C++ Standard Library. Documentation: https://www.boost.org/doc/libs/1_80_0/

# Graphic Library
**SFML**, a simple, fast, cross-platform and object-oriented multimedia API.
  * Access the SFML github : https://github.com/SFML/SFML
  * Access the official documentation : https://www.sfml-dev.org/documentation/2.5.1/

# The game
## Game Engine
### What is a Game Engine
The Game Engine is the core foundation of any video game.

We chose to make our own game engine for this project.
