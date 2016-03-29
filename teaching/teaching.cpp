#include <iostream> 
#include <vector> 
#include <array>
#include <list>
#include <algorithm> 
#include <iterator>
#include <numeric>
#define REQSZ 5
//#define DEBUG
using namespace std;
enum S_FLAG {
    WORD_NONE, WORD_ONLY_FIXES, 
    WORD_ENOUGH, WORD_CNT
};
S_FLAG sflg;
int N, K, sol_flag, teaching_char, sol;
list<string> words;
vector<char> required = {'a', 'c', 'i', 'n', 't'};
string letter_bunch("");

inline void eliminate_dups(string &s) {
    sort(s.begin(), s.end());
    const auto p = unique(s.begin(), s.end());
    s.resize(distance(s.begin(), p));        
}
inline void eliminate_fixes(string &s) {
    s.erase(0, 4);
    s.erase(s.size()-4, s.size()+1);
}
inline void eliminate_required(string &s) {
    for(const auto &p : required) {
        auto q = remove(s.begin(), s.end(), p);    
        s.resize(distance(s.begin(), q));
    }
}
inline void preprocess(string &s) {
    eliminate_fixes(s);
    eliminate_dups(s);
    eliminate_required(s);
}
class genProbSolver {
    public:
        genProbSolver(string s) : name(s) {}
        void process_input(istream &);
        void process_solution();
        void process_output(ostream &);
        void echo_input();
    private:
        string name;
};
inline string find_letter_bunch(list<string> &ls) {
    string tmp("");
    tmp = accumulate(ls.begin(), ls.end(), string(""));
    eliminate_dups(tmp);
    return tmp;
}
void dprint(string &s) {
    std::cout << s;
}

void genProbSolver::process_input(istream &pin) {
    auto bi = back_inserter(words);
    string tmp("");
    pin >> N >> K;
    try {
        if(K < REQSZ) {
            throw WORD_NONE;
        } else {
            for (int i = 0; i < N; i++) {
                pin >> tmp;
                preprocess(tmp);
                *bi = tmp;
            } 
            if(K == REQSZ) {
                throw WORD_ONLY_FIXES;
            }
            letter_bunch = find_letter_bunch(words);
            teaching_char = letter_bunch.size();
#ifdef DEBUG
     std::cout << "N : " << N << "\tK : " << K << std::endl;
     std::cout << letter_bunch;
     std::cout << "중에 " << K -5 << "만큼 뽑아서 "<< std::endl;
     std::cout << "{";
     for(const auto &p : words) {
         if(p == "") {
             std::cout << "NULL, "; continue;
         }
         std::cout << p << ", ";

     }
     std::cout << "}" << std::endl;
     std::cout << "위 단어들을 만들 수 있는 최대 갯수를 구한다." << std::endl;
#endif
            //std::cout << teaching_char << std::endl;
            if(K >= REQSZ + teaching_char) {
                throw WORD_ENOUGH;
            }
        }
    } catch (S_FLAG flag) {
        switch (flag) {
            case WORD_NONE:
                std::cout << 0;
                break;
            case WORD_ONLY_FIXES: 
                {
                    int null_cnt = count_if(words.begin(), words.end(),
                            [](string s){return s.empty();});
                    std::cout << null_cnt;
                }
                break;
            case WORD_ENOUGH:
                std::cout << words.size();
                break;
            default:
                std::cout << "WTF" << std::endl;
                break;
        }    
        //std::cout << "error" << std::endl;
        exit(1);
    }
}
void genProbSolver::echo_input() {
    std::cout << "Echoing input" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << words.size() << std::endl;
    for(const auto &p : words)
        std::cout << p << std::endl;
    std::cout << "==============" << std::endl;
}
void genProbSolver::process_solution() {
    

    const int c_r = K - REQSZ;
    const int c_n = letter_bunch.size();
    vector<bool> selection(c_n);
    fill(selection.begin() + c_n - c_r, selection.end(), true);
    auto find_max_completion = 
        [](const list<string> &ws, const int n, const int r,
                const string &bunch, vector<bool> &sel){
            string tmp("");
            int max_match = 0, occur= 0;
            do {
                for (int i = 0; i < n; i++) {
                    if(sel[i]) {
                        tmp.push_back(bunch[i]);
                    }        

                }
#ifdef DEBUG
                std::cout << "current combination : "; 
                std::cout << tmp << std::endl;
#endif
                //includes()
                for(const auto &p :words) {
#ifdef DEBUG
                    std::cout << "compare words : ";
                    std::cout << p << std::endl;
#endif
                    if(0/*tmp.size() < p.size()*/) {
                        if(includes(tmp.begin(), tmp.end(), 
                                    p.begin(), p.end())) {
                            occur++;
                        }
                    } else if (tmp.size() >= p.size()) {
                        if(includes(tmp.begin(), tmp.end(), 
                                    p.begin(), p.end())) {
                            occur++;
                        } 
                    } 
                }                    
#ifdef DEBUG
    std::cout << "occur : "; 
    std::cout << occur << std::endl;
#endif
                if(max_match < occur) max_match = occur;
                occur = 0;
                tmp.clear();
            } while (next_permutation(sel.begin(), sel.end()));
            return max_match;
        };
    const int max_match 
        = find_max_completion(words, c_n, c_r, letter_bunch, selection);
    sol = max_match;
}
void genProbSolver::process_output(ostream &pout) {
    pout << sol;
}
int main(int argc, const char *argv[]) {
    // Includes 테스트
    /*array<int,5> arr1 = {1,2,3,4,5};
    array<int,5> arr2 = {1,2,3,4,5};
    array<int,3> arr3 = {1,2,6};
    array<int,2> arr4 = {1,3};*/
    /*if(includes(arr1.begin(), arr1.end(), arr4.begin(), arr4.end()))
        std::cout << "yo1" << std::endl;
    else std::cout << "wtf" << std::endl;*/
    genProbSolver probsolver("teaching");
    probsolver.process_input(std::cin);
    //probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}

