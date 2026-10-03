#include "node.h"

int main(void) {
  // constants
  const int width = 800;
  const int height = 450;
  const int grid_x = 10;
  const int grid_y = 10;
  const int grid_cells_x = width/grid_x;
  const int grid_cells_y = height/grid_y;

  // grid initialize
  Node grid[grid_cells_x][grid_cells_y][25]; // each particle has to be 2 units apart so there can be at most 25 nodes in a grid cell
  int grid_length[grid_cells_x][grid_cells_y]; // number of nodes in each grid cell (needed to remove or add elements)

  // raylib initialize
  InitWindow(width, height, "raylib example - basic window");

  bool display_flag = false;
  while(!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(WHITE);

      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	Vector2 mouse_pos = GetMousePosition();
	int i = mouse_pos.x / grid_x;
	int j = mouse_pos.y / grid_y;

	int l = grid_length[i][j];
	Node n;
	n.pos = mouse_pos;
	
	grid[i][j][l] = n;
	grid_length[i][j]++;
      }

      if(IsKeyPressed(KEY_ENTER)) display_flag = !display_flag;

      if(display_flag) {
	for(int i = 0; i < grid_cells_x; i++) {
	  for(int j = 0; j < grid_cells_y; j++) {
	    for(int n = 0; n < grid_length[i][j]; n++) {
	      DrawCircleV(grid[i][j][n].pos, 5, RED);
	    }
	  }
	}
      }
      
    EndDrawing();
  }

  // destroy
  CloseWindow();

  return 0;
}
