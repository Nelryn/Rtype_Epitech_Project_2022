# 🚀 R-Type — Epitech Project (2022)

> **“A Game Engine That Roars!”**
> A multiplayer shoot’em up built from scratch using **C++**, **SFML**, and a **custom-made game engine**.

---

## 🧩 Overview

**R-Type** is a **cross-platform multiplayer shooter** developed in a team of 5 third-year students.
The goal is to build both a **multithreaded server** and a **graphical client** powered by a **custom-designed game engine** — without relying on existing engines.

This project blends:

* 🎮 **Real-time multiplayer gameplay**
* ⚙️ **Network programming (UDP, binary protocol)**
* 🧱 **Game engine design (ECS, rendering, physics)**
* 🧠 **Multithreading and asynchronous architecture**

---

## 🛠️ Project Objectives

* Implement a **multithreaded asynchronous server**
* Create a **graphical client** using **SFML**
* Design a **modular C++ game engine**
* Implement a **binary network protocol over UDP**
* Ensure **cross-platform compatibility** with **CMake**

---

## ⚙️ Compilation & Installation

### 🧰 Requirements

* **C++17 or higher**
* **CMake ≥ 3.17**
* **Boost (Boost::Asio)**
* **SFML 2.5.1**
* **CMakeFetchContent** for dependency management

### 🐧 Linux

```bash
mkdir build && cd build
cmake ..
make
```

### 🪟 Windows

```bash
mkdir build && cd build
cmake -G "Visual Studio 17 2022" ..
```

### 🔗 Supported Platforms

| OS          | Build Output                              |
| ----------- | ----------------------------------------- |
| **Linux**   | Generates a Makefile and project binary   |
| **Windows** | Generates a Visual Studio `.sln` solution |

---

## 🧠 Architecture Overview

The R-Type project is divided into **three main components**:

| Component                    | Description                                                           |
| ---------------------------- | --------------------------------------------------------------------- |
| **Server (`r-type_server`)** | Manages players, physics, and global game state                       |
| **Client (`r-type_client`)** | Handles rendering, user input, and display                            |
| **Engine (`engine/`)**       | Core logic including ECS, rendering, networking, and audio subsystems |

---

## 🌐 Networking

### Protocol

* **Binary protocol** using **UDP**
* Documented in a **custom RFC** formatted like an actual Internet Standard
* Resistant to malformed messages (no crashes)
* Client and server fully asynchronous

### Server

* ✅ Asynchronous, frame-based processing
* ✅ Supports multiple players in a single game
* ✅ Authority over final game state
* ❌ Multithreading planned (work in progress)
* ✅ Handles client disconnection gracefully (future improvement)

### Client

* ✅ Uses **SFML** for rendering
* ✅ Fully functional launcher
* ✅ Horizontal scrolling background with parallax space effect
* ✅ Player movement via arrow keys
* ❌ Distinct player identification (planned feature)

---

## 🧱 Game Engine

### What is a Game Engine?

A **game engine** is the foundational software that provides the systems and tools required to build video games — including rendering, physics, audio, and input handling.

For this project, we developed our **own custom game engine** in C++.
It provides modular components for graphics, audio, entities, and networking — enabling us to create the R-Type game efficiently.

### Engine Subsystems

| Subsystem                         | Description                                                |
| --------------------------------- | ---------------------------------------------------------- |
| **Rendering (SFML)**              | Draws sprites, animations, and backgrounds                 |
| **Audio**                         | Manages sound effects and background music                 |
| **Physics**                       | Handles movement and collisions                            |
| **Networking**                    | Encapsulates UDP packet handling and binary protocol logic |
| **ECS (Entity-Component-System)** | Decouples entity logic from behavior and data              |
| **Timer & Loop Management**       | Ensures consistent frame rate and updates                  |
| **Resource Management**           | Loads and caches textures and sounds                       |

---

## 🧩 Game Design

### Core Features

* Multiplayer **R-Type inspired** shoot’em up gameplay
* Players navigate a **horizontal scrolling space background**
* The server dictates the **game state**, ensuring authoritative synchronization
* Real-time **missile firing**, **enemy spawning**, and **explosions**

### Planned Features

* Distinct player appearances (colors, models)
* Enemy **Bydos slaves** (AI-controlled enemies)
* Cross-platform packaging and versioning
* Graceful client crash handling

---

## 📚 Libraries & Dependencies

| Library               | Purpose                                  |
| --------------------- | ---------------------------------------- |
| **Boost::Asio**       | Networking, UDP communication, async I/O |
| **SFML 2.5.1**        | Rendering, window, input, and audio      |
| **CMakeFetchContent** | Dependency management                    |
| **CMake**             | Cross-platform build system              |

### Documentation

* [Boost Documentation](https://www.boost.org/doc/libs/1_80_0/)
* [SFML Documentation](https://www.sfml-dev.org/documentation/2.5.1/)
* [SFML GitHub](https://github.com/SFML/SFML)

---

## 📂 Project Structure

```
Rtype_Epitech_Project_2022/
├── Client/                 # Client-side code (SFML rendering, input)
│   ├── src/
│   ├── include/
├── Configuration/          # Configuration files in .json
├── server/                 # Server-side code (game logic, UDP communication)
│   ├── src/
│   ├── include/
│
│
├── assets/                 # Resources
├── GameEngine/             # Custom game engine
├── Player/                 # Player component
├── Map/
├── poc/                    # PoC folder
├── CMakeLists.txt          # Build configuration
└── README.md               # This file
```

---

## 🕹️ Example Usage

### 🖥️ Start Server

```bash
./r-type_server <port>
```

### 💻 Start Client

```bash
./r-type_client <ip> <port>
```

**Example:**

```bash
./r-type_server 4242
./r-type_client 127.0.0.1 4242
```
