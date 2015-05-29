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

# Screenshots

![](https://github.com/alexesDev/node_editor/blob/master/preview.png)
