#include <array>

using namespace std;

constexpr int board_size = 5;

class Maze2D
{
public:
    void RotateRight()
    {
        array<array<int, board_size>, board_size> copy(maze);
        for (int r = 0; r < board_size; r++)
        {
            for (int c = 0; c < board_size; c++)
                maze[c][board_size - 1 - r] = copy[r][c];
            ;
        }
    }

    /*
    []연산자 오버로딩
    */
    array<int, board_size> &operator[](int idx)
    {
        return maze[idx];
    }

private:
    array<array<int, board_size>, board_size> maze;
};

class Maze3D
{
public:
    Maze3D()
    {
        for (auto &maze_2d : maze)
            maze_2d = new Maze2D;
        sort(maze.begin(), maze.end());
    }

    bool SetNextPermutation()
    {
        return next_permutation(maze.begin(), maze.end());
    }

    ~Maze3D()
    {
        for (auto &maze_2d : maze)
            delete maze_2d;
    }

    /*
    []연산자 오버로딩
    */
    Maze2D &operator[](int idx)
    {
        return *maze[idx];
    }

private:
    array<Maze2D *, board_size> maze;
};

/*
사용 예시
*/
int main()
{
    Maze3D maze_3d;

    /*
    maze_3d[0]은 가장 위층(0층)의 2D 미로판을 가져옵니다.
    → Maze3D 클래스가 operator[]를 오버로딩했기 때문에 배열처럼 사용할 수 있습니다.
    → 즉, maze_3d
    */
    Maze2D maze_2d_top = maze_3d[0];

    /*
    2D 미로판 순서를 다음 순열로 재배치 합니다. (false 반환시 모든 순열을 다 탐색했음을 의미)
    */
    bool is_permutation_end = maze_3d.SetNextPermutation();

    /*
    2D 미로판을 오른쪽으로 90도 회전합니다.
    */
    maze_2d_top.RotateRight();

    /*
    3차원 좌표 (z, y, x)에 접근하는 코드입니다.
    maze_3d[z][y][x]는 이렇게 해석됩니다:

    1. maze_3d[z] → z층에 해당하는 Maze2D 객체 반환(Maze3D의 operator[]을 호출한 것)
    2. maze_3d[z][y] → y행에 해당하는 1D array 반환(Maze2D의 operator[]을 호출한 것)
    3. maze_3d[z][y][x] → x열에 있는 값을 참조(Maze2D의 operator[]가 반환한 array에 접근)

    즉, operator[]를 연쇄적으로 호출하여 3차원처럼 접근하는 구조입니다.
    */
    int z = 3, y = 2, x = 1;
    maze_3d[z][y][x] = 0;
}