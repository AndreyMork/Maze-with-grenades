#include <iostream> 
#include <iomanip>


using namespace std;


#define N 21
#define M 31
#define K 3 + 1
class Maze {
private:
	int mazeTemplate[N][M] = {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1,
		-1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1,
		-1, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1,
		-1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1,
		-1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -2, 0, 0, -1,
		-1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1,
		-1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1,
		-1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1,
		-1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1,
		-1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1,
		-1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
	};
	int maze[K][N][M];

	int start_x = 1, start_y = 1;
	int** i;
	int* j;

	struct Step 
	{
		int x;
		int y;
		int k;
		int s;
		Step* next;
	};
	Step* first = new Step { start_x, start_y, 0, 0, NULL };
	Step* last = first;

	void push(int x, int y, int k, int s) 
	{
		if (first == NULL) 
		{
			first = new Step{ x, y, k, s, NULL };
			last = first;
		}
		else
		{
			if (last->k > k)
			{
				int temp = last->x;
				last->x = x;
				x = temp;

				temp = last->y;
				last->y = y;
				y = temp;

				temp = last->k;
				last->k = k;
				k = temp;

				temp = last->s;
				last->s = s;
				s = temp;
			}
			Step* node = new Step{ x, y, k, s, NULL };
			last->next = node;
			last = node;
		}
			
	}
	Step pop() 
	{
		Step node = *first;
		first = node.next;
		return node;
	}

public:
	void backTrace(int k, int x, int y, int s)
	{
		while (s != 1)
		{
			if (maze[0][y][x] == -1)
			{
				maze[0][y][x] = -4;
				k--;
			}
			else
			{
				maze[0][y][x] = -3;
			}
			s--;


			if (maze[k][y - 1][x] == s)
			{
				y--;
			}

			else if (maze[k][y][x + 1] == s)
			{
				x++;
			}

			else if (maze[k][y + 1][x] == s)
			{
				y++;
			}

			else if (maze[k][y][x - 1] == s)
			{
				x--;
			}
		}
		
		if (maze[0][y][x] == -1)
		{
			maze[0][y][x] = -4;
			k--;
		}
		else
		{
			maze[0][y][x] = -3;
		}
		s--;
		printMaze();
	}
	void makeMaze()
	{
		for (int k = 0; k < K; k++)
		{
			for (int n = 0; n < N; n++)
			{
				for (int m = 0; m < M; m++)
				{
					maze[k][n][m] = mazeTemplate[n][m];
				}
			}
		}
	}
	void markMaze()
	{
		Step st;
		while (first != NULL) {
			st = pop();

 			if (maze[st.k][st.y - 1][st.x] == -2 || maze[st.k][st.y][st.x + 1] == -2 ||
				maze[st.k][st.y + 1][st.x] == -2 || maze[st.k][st.y][st.x - 1] == -2) 
			{
				backTrace(st.k, st.x, st.y, st.s);
				break;
			}
			else if (st.k == 0)
			{
				if ((st.y - 1 > 0) && (st.x != start_x || st.y - 1 != start_y)) {
					if (maze[st.k][st.y - 1][st.x] == 0)
					{
						maze[st.k][st.y - 1][st.x] = st.s + 1;
						push(st.x, st.y - 1, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y - 1][st.x] == -1 && maze[st.k + 1][st.y - 1][st.x] == -1)
					{
						maze[st.k + 1][st.y - 1][st.x] = st.s + 1;
						push(st.x, st.y - 1, st.k + 1, st.s + 1);
					}
				}

				if ((st.x + 1 < M - 1) && (st.x + 1 != start_x || st.y != start_y)) {
					if (maze[st.k][st.y][st.x + 1] == 0)
					{
						maze[st.k][st.y][st.x + 1] = st.s + 1;
						push(st.x + 1, st.y, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y][st.x + 1] == -1 && maze[st.k + 1][st.y][st.x + 1] == -1)
					{
						maze[st.k + 1][st.y][st.x + 1] = st.s + 1;
						push(st.x + 1, st.y, st.k + 1, st.s + 1);
					}
				}

				if ((st.y + 1 < N - 1) && (st.x != start_x || st.y + 1 != start_y)) {
					if (maze[st.k][st.y + 1][st.x] == 0)
					{
						maze[st.k][st.y + 1][st.x] = st.s + 1;
						push(st.x, st.y + 1, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y + 1][st.x] == -1 && maze[st.k + 1][st.y + 1][st.x] == -1)
					{
						maze[st.k + 1][st.y + 1][st.x] = st.s + 1;
						push(st.x, st.y + 1, st.k + 1, st.s + 1);
					}
				}

				if ((st.x - 1 > 0) && (st.x - 1 != start_x || st.y != start_y)) {
					if (maze[st.k][st.y][st.x - 1] == 0)
					{
						maze[st.k][st.y][st.x - 1] = st.s + 1;
						push(st.x - 1, st.y, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y][st.x - 1] == -1 && maze[st.k + 1][st.y][st.x - 1] == -1)
					{
						maze[st.k + 1][st.y][st.x - 1] = st.s + 1;
						push(st.x - 1, st.y, st.k + 1, st.s + 1);
					}
				}
			}
			else if (st.k == K - 1)
			{
				if (maze[st.k][st.y - 1][st.x] == 0)
				{
					maze[st.k][st.y - 1][st.x] = st.s + 1;
					push(st.x, st.y - 1, st.k, st.s + 1);
				}

				if (maze[st.k][st.y][st.x + 1] == 0)
				{
					maze[st.k][st.y][st.x + 1] = st.s + 1;
					push(st.x + 1, st.y, st.k, st.s + 1);
				}

				if (maze[st.k][st.y + 1][st.x] == 0)
				{
					maze[st.k][st.y + 1][st.x] = st.s + 1;
					push(st.x, st.y + 1, st.k, st.s + 1);
				}

				if (maze[st.k][st.y][st.x - 1] == 0)
				{
					maze[st.k][st.y][st.x - 1] = st.s + 1;
					push(st.x - 1, st.y, st.k, st.s + 1);
				}
			}		
			else
			{
				if (st.y - 1 > 0) {
					if (maze[st.k][st.y - 1][st.x] == 0)
					{
						maze[st.k][st.y - 1][st.x] = st.s + 1;
						push(st.x, st.y - 1, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y - 1][st.x] == -1 && maze[st.k + 1][st.y - 1][st.x] == -1)
					{
						maze[st.k + 1][st.y - 1][st.x] = st.s + 1;
						push(st.x, st.y - 1, st.k + 1, st.s + 1);
					}
				}
				
				if (st.x + 1 < M - 1) {
					if (maze[st.k][st.y][st.x + 1] == 0)
					{
						maze[st.k][st.y][st.x + 1] = st.s + 1;
						push(st.x + 1, st.y, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y][st.x + 1] == -1 && maze[st.k + 1][st.y][st.x + 1] == -1)
					{
						maze[st.k + 1][st.y][st.x + 1] = st.s + 1;
						push(st.x + 1, st.y, st.k + 1, st.s + 1);
					}
				}

				if (st.y + 1 < N - 1) {
					if (maze[st.k][st.y + 1][st.x] == 0)
					{
						maze[st.k][st.y + 1][st.x] = st.s + 1;
						push(st.x, st.y + 1, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y + 1][st.x] == -1 && maze[st.k + 1][st.y + 1][st.x] == -1)
					{
						maze[st.k + 1][st.y + 1][st.x] = st.s + 1;
						push(st.x, st.y + 1, st.k + 1, st.s + 1);
					}
				}

				if (st.x - 1 > 0) {
					if (maze[st.k][st.y][st.x - 1] == 0)
					{
						maze[st.k][st.y][st.x - 1] = st.s + 1;
						push(st.x - 1, st.y, st.k, st.s + 1);
					}
					else if (maze[st.k][st.y][st.x - 1] == -1 && maze[st.k + 1][st.y][st.x - 1] == -1)
					{
						maze[st.k + 1][st.y][st.x - 1] = st.s + 1;
						push(st.x - 1, st.y, st.k + 1, st.s + 1);
					}
				}
			}

		}
	}
	void printMaze()
	{
		for (int k = 0; k < 1; k++)
		{
			for (int i = 0; i < N; i++) 
			{
				for (int j = 0; j < M; j++) 
				{
					if (maze[k][i][j] == -1) 
					{
						cout << "###";
					}
					else if (maze[k][i][j] == -2) 
					{
						cout << " @ ";
					}
					else if (maze[k][i][j] == -3) 
					{
						cout << " * ";
					}
					else if (maze[k][i][j] == -4)
					{
						cout << "{*}";
					}
					else if (i == start_x && j == start_y && k == 0) 
					{
						cout << " & ";
					}
					else if (maze[k][i][j] == 0) 
					{
						cout << "...";
					}
					else 
					{
						cout << "...";
					}

				}
				cout << endl;
			}
			cout << endl;
		}
	}
};


int main() {
	Maze maze;
	maze.makeMaze();
	maze.markMaze();

	cin.get();
	return 0;
}
