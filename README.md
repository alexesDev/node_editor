# Idea

I'm trying to create a universal node editor with micro service architecture.
For example, the generation of noise texture to the game engine:

```
Game engine <- Noise generator service <- Editor <-> Save service
```

1. Launched editor
2. Launched "Save service" that loaded a scheme to editor
3. Launched Noise generator and Game engine
4. Edit loaded nodes in the editor
5. Noise generator generated a texture
6. Game engine shown the image

# Compilation

```
mkdir -p build && cd build
cmake ..
make -j5
./node_editor
```

## Minimal dependencies

- CMake >= 3.1.3
- Qt >= 5.4.1
- ZeroMQ >= 4.0.5
- boost >= 1.57

# Screenshots

![](https://github.com/alexesDev/node_editor/blob/master/preview.png)

# License

Project is licensed under MIT/Expat license, see [COPYING](COPYING) file for details.
