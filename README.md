# cub3D

cub3D is a 3D graphical project inspired by the popular game **Wolfenstein 3D**. It is developed in **C** and leverages raycasting techniques to create a pseudo-3D game environment. This project is part of the **42 School curriculum** and aims to demonstrate mastery of graphics programming, mathematical algorithms, and performance optimization.



<img width="1508" alt="cub3D_preview" src="https://github.com/user-attachments/assets/04107508-e348-4b8b-8743-e395ef571f15" />

## Features

- **Raycasting Engine**: Simulates a 3D perspective using 2D maps.
- **Customizable Maps**: Load and play custom-designed map files.
- **Interactive Gameplay**: Real-time player movement and interaction with the environment.
- **Textured Walls**: Adds realism to the game world with texture mapping.
- **Cross-Platform Compatibility**: Runs on Linux and macOS.

---

## Setup and Compilation

### Prerequisites

Before compiling the project, ensure you have the following dependencies installed:

- **gcc (GNU Compiler Collection)**
- **make**
- **MinilibX** (X11 library for graphics rendering)
- **OpenGL** and **GLUT** (if applicable for your platform)

### Compilation

Clone the repository and compile the project:

```bash
git clone https://github.com/jocuni-p/cub3D.git
cd cub3D
make
```

This will generate the `cub3D` executable in the root directory.
```bash
./cub3D maps/valid/choose_a_map
```

---

## Controls

| Key           | Action                    |
| ------------- | ------------------------- |
| `W` / `Up`    | Move forward              |
| `S` / `Down`  | Move backward             |
| `A`           | Strafe left               |
| `D`           | Strafe right              |
| `Left Arrow`  | Rotate view left          |
| `Right Arrow` | Rotate view right         |
| `ESC`         | Exit the game             |

---

## Project Structure

```plaintext
cub3D/
├── src/          # Source code files
├── include/      # Header files
├── maps/         # Sample map files
├── textures/     # Textures used in the game
├── Makefile      # Build script
└── README.md     # Project documentation
```

---

## Dependencies

The project uses the **MinilibX** library for rendering graphics. Ensure you have the required libraries installed for your operating system:

### macOS
```bash
brew install mlx
```

### Linux
```bash
sudo apt-get install libx11-dev libxext-dev
```

---

## Contributing

Contributions are welcome! If you want to contribute to the project, follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

---

## Acknowledgments

This project is part of the **42 School curriculum**. Special thanks to the 42 Network community for their guidance and resources.

---

### License

This project is licensed under the [MIT License](./LICENSE).
```

Let me know if you'd like to adjust or expand on any part of this `README.md`!
