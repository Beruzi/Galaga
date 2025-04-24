# Galaga
A remake of the retro arcade game, Galaga



Galaga/
├── CMakeLists.txt
├── README.md

├── assets/                         # All game art, sound, etc.
│   ├── sprites/
│   └── audio/

├── include/                        # Public headers
│   ├── core/
│   │   ├── Engine.hpp              # Main game loop + orchestration
│   │   ├── GameState.hpp           # Tracks score, lives, level, flags
│   │   ├── Timer.hpp               # Optional for frame timing
│   │   └── Config.hpp              # Constants: screen size, speeds, etc.
│   │
│   ├── entities/
│   │   ├── Entity.hpp              # Abstract base class
│   │   ├── Player.hpp
│   │   ├── Enemy.hpp
│   │   ├── Bullet.hpp
│   │   └── PowerUp.hpp
│   │
│   ├── systems/
│   │   ├── InputSystem.hpp         # Processes SDL events
│   │   ├── CollisionSystem.hpp     # Handles entity collision resolution
│   │   ├── RenderSystem.hpp        # Handles OpenGL or SDL rendering
│   │   └── AISystem.hpp            # Optional: controls enemy AI logic
│   │
│   ├── managers/
│   │   ├── EntityManager.hpp       # Manages all game entities
│   │   ├── TextureManager.hpp      # Caches loaded textures
│   │   └── SoundManager.hpp        # Optional: audio cache
│   │
│   └── utils/
│       └── Math.hpp                # Vectors, rects, AABB checks

├── src/                            # Source files (.cpp)
│   ├── main.cpp                    # Entry point
│   ├── core/
│   ├── entities/
│   ├── systems/
│   ├── managers/
│   └── utils/

├── build/                          # CMake output (gitignore this)

└── tests/                          # Optional: unit tests
    ├── test_collision.cpp
    └── test_entity.cpp
