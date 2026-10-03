#include "raylib.h"
#include "node.h"

int main(void) {
  InitWindow(800, 450, "raylib example - basic window");

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
      Node node;
      Vector2 a = {.x = 150, .y = 100};
      node.position = a;
      DrawCircle(node.pos.x, node.pos.y, 0.1f, RED);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
