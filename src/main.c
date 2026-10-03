#include "raylib.h"
#include "node.h"

int main(void) {
  // constants
  const int width = 800;
  const int height = 450;
  const int grid_x = 10;
  const int grid_y = 10;
  const int grid_cells_x = width/grid_x;
  const int grid_cells_y = height/grid_y;

  // raylib initialize
  InitWindow(width, height, "raylib example - basic window");

  while(!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(WHITE);
    EndDrawing();
  }

  // destroy
  CloseWindow();

  return 0;
}
