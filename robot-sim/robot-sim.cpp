#include <iostream>
#include <vector>
using namespace std;

#define AREA_EMPTY 0
#define AREA_ROBOT 1
#define AREA_WALL 2
#define OK_FINE 0
#define ROBOT_CRASH 1
#define WALL_CRASH 2

// #define DEBUG
int sol_flag = 0;
class genProbSolver {
    public:
        genProbSolver() = default;
        genProbSolver(string s) : name(s) {}
        string &get_probname() {return name;}
        void process_input(istream &);
        void process_solution();
        void process_output(ostream &);
        void echo_input(ostream &);
    private:
        string name;
};
char check_next_dir(char dir, char lr); 
void print_output(int sol_flag);   
void print_board();
unsigned A, B, N, M;
struct robot {
    int x, y; char dir;
    robot(int ax, int ay, char adir) :
        x(ax), y(ay), dir(adir) {}
};
struct instruction {
    int robot_number;
    char inst_type;
    int repetition;
    instruction(int ar_n, char ai_t, int rep) :
        robot_number(ar_n), inst_type(ai_t), repetition(rep) {}
};
vector<robot> robots;
vector<instruction> instructions;
vector<vector<int>> matrix;
char pbuf[128] = {0};

int main() { 
    genProbSolver gensolver("robot simulation");
    gensolver.process_input(std::cin);
//     gensolver.echo_input(std::cout); 
    gensolver.process_solution();
    print_output(sol_flag);
    return 0;
}

int X_robot, Y_robot;
void genProbSolver::process_solution() {
    int i;
    for(const auto &p : instructions) {
#ifdef DEBUG
    cout << "로봇 번호:" << p.robot_number << endl;
    cout << "명령어 타입:" << p.inst_type << endl;
    cout << "반복 횟수:" << p.repetition << endl;
#endif
        // fecth robot number and subtract by 1 
        // to access correct vector position
        const int rnum = p.robot_number - 1;
        // fetch current robot's direction
        const char curr_dir = robots[rnum].dir;
        if(p.inst_type == 'F') {
            int next_x = robots[rnum].x;
            int next_y = robots[rnum].y;
            int ix, iy;
            for (i = 0; i < p.repetition; i++) {
                if(curr_dir == 'N') next_y++; 
                if(curr_dir == 'W') next_x--; 
                if(curr_dir == 'E') next_x++; 
                if(curr_dir == 'S') next_y--; 
                // check if next pos is crashing
                // with other robots or with  robots
                ix = next_x; iy = B - next_y + 1;
                if(matrix[iy][ix] == AREA_ROBOT) {
                    X_robot = p.robot_number;
                    int cntY = 1;
                    for(const auto &q : robots) {
                        if(q.x == next_x && q.y == next_y) break; 
                        ++cntY;
                    }
                    Y_robot = cntY; 
                    sol_flag = ROBOT_CRASH;
                    break;
                } else if(matrix[iy][ix] == AREA_WALL) {
//                     cout << "X_robot : " << p.robot_number << endl;
                    X_robot = p.robot_number;
                    sol_flag = WALL_CRASH;
                    break;
                } else {
                    const int ox = robots[rnum].x;
                    const int oy = B - robots[rnum].y + 1;
                    matrix[oy][ox] = AREA_EMPTY;
                    matrix[iy][ix] = AREA_ROBOT;
                    robots[rnum].x = next_x;
                    robots[rnum].y = next_y;
                } 
            }    
        } else { // in the case of L or R
            // just update robot's next direction
            char next_dir = curr_dir;
            for (i = 0; i < p.repetition; i++) {
               next_dir = check_next_dir(next_dir, p.inst_type);
#ifdef DEBUG
               cout << "현재 방향:" << curr_dir << endl; 
//                cout << "L/R:" << p.inst_type << endl;
               cout << "다음 방향:" << next_dir << endl;
#endif
            }
            robots[rnum].dir = next_dir;
        }
#ifdef DEBUG
         print_board();
#endif
//
        if(sol_flag != OK_FINE) break;
    }
}
void print_output(int sol_flag) {
    if(sol_flag == 0) {
        cout << "OK"; 
    } else if(sol_flag == 1) {
        cout << "Robot " << X_robot 
            << " crashes into robot " << Y_robot;
    } else if(sol_flag == 2) {
        cout << "Robot " << X_robot
            << " crashes into the wall";
    } else {
        cout << "WTF is that" << endl;
    }
}
void print_board() {
    for (const auto &p : matrix) {
        for(const auto &q : p) {
            cout << q << " ";
        }
        cout << endl;
    }
    cout << endl;
}
char check_next_dir(char dir, char lr) {
    if(dir == 'N' && lr == 'L') return 'W';
    if(dir == 'N' && lr == 'R') return 'E';
    if(dir == 'W' && lr == 'L') return 'S';
    if(dir == 'W' && lr == 'R') return 'N';
    if(dir == 'E' && lr == 'L') return 'N';
    if(dir == 'E' && lr == 'R') return 'S';
    if(dir == 'S' && lr == 'L') return 'E';
    if(dir == 'S' && lr == 'R') return 'W';
}
void genProbSolver::process_input(istream &pin) {
    int i;
    int tmp_x, tmp_y;
    char tmp_dir;
    pin >> A >> B >> N >> M;
    matrix.resize(B+2);
    for (i = 0; i < B+2; i++) {
        matrix[i].resize(A+2);
    }
    for (i = 0; i < N; i++) {
        pin >> tmp_x >> tmp_y >> tmp_dir;
        robots.push_back(robot(tmp_x, tmp_y, tmp_dir));
    }
    for (i = 0; i < M; i++) {
        pin >> tmp_x >> tmp_dir >> tmp_y;
        instructions.push_back(instruction(tmp_x, tmp_dir, tmp_y));
    }
    // board line should be wall
    // board initialization
    for (i = 0; i < B+2; i++) {
        matrix[i][0] = matrix[i][A+1] = AREA_WALL;
    }
    for (i = 0; i < A+2; i++) {
        matrix[0][i] = matrix[B+1][i] = AREA_WALL;
    }
    for (const auto &p : robots) {
        matrix[B - p.y + 1][p.x] = AREA_ROBOT;
    }
}
void genProbSolver::echo_input(ostream &pout) {
    sprintf(pbuf, "%d %d\n%d %d\n", A, B, N, M);
    pout << pbuf;
    for (const auto &p : robots) {
        sprintf(pbuf, "%d %d %c", p.x, p.y, p.dir);
        pout << pbuf << endl;
    }
    for (const auto &p : instructions) {
        sprintf(pbuf, "%d %c %d", p.robot_number, p.inst_type, p.repetition);
        pout << pbuf << endl;
    }
    for (const auto &p : matrix) {
        for(const auto &q : p) {
            cout << q << " ";
        }
        cout << endl;
    } 
}

