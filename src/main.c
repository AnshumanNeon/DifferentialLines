#include "node.h"
#include "raymath.h"

int main(void) {
  // constants
  const int width = 800;
  const int height = 450;
  const int grid_x = 10;
  const int grid_y = 10;
  const int grid_cells_x = width/grid_x;
  const int grid_cells_y = height/grid_y;
  const float force_constant = 4.0f;

  // grid initialize
  Node grid[grid_cells_x][grid_cells_y][25]; // each particle has to be 2 units apart so there can be at most 25 nodes in a grid cell
  int grid_length[grid_cells_x][grid_cells_y] = {}; // number of nodes in each grid cell (needed to remove or add elements)

  // raylib initialize
  InitWindow(width, height, "Differential Lines");

  float deltaTime = 0;

  bool update_flag = false;
  while(!WindowShouldClose()) {
    deltaTime = GetFrameTime();
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

      if(IsKeyPressed(KEY_SPACE)) update_flag = !update_flag;

      for(int i = 0; i < grid_cells_x; i++) {
	for(int j = 0; j < grid_cells_y; j++) {
	  for(int n = 0; n < grid_length[i][j]; n++) {
	    DrawCircleV(grid[i][j][n].pos, 5, RED);

	    if(update_flag) {
	      TraceLog(LOG_INFO, "hell");
	      Vector2 additive_forces = Vector2Zero();
	      for(int x = 0; x < grid_length[i][j]; x++) {
		if(x == n) continue;

		additive_forces = Vector2Add(Vector2Scale(Vector2Normalize(Vector2Subtract(grid[i][j][n].pos, grid[i][j][x].pos)), force_constant), additive_forces);
	      }

	      grid[i][j][n].pos = Vector2Add(Vector2Scale(additive_forces, deltaTime*deltaTime), grid[i][j][n].pos);

	      if((int)(grid[i][j][n].pos.x / grid_x) != i || (int)(grid[i][j][n].pos.y / grid_y) != j) {
		int _i = grid[i][j][n].pos.x / grid_x;
		int _j = grid[i][j][n].pos.y / grid_y;

		grid[_i][_j][grid_length[_i][_j]] = grid[i][j][n];

		for(int x = n+1; x < grid_length[i][j]; x++){
		  grid[i][j][x-1] = grid[i][j][x];
		}
		
		grid_length[i][j]--;
	      }
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
