//Question link: https://www.spoj.com/problems/NAKANJ/

#include <iostream>
#include <queue>

using namespace std;

bool movimentoValido(pair<int,int> &posicaoAtual, pair<int,int> &movimento){
    if((posicaoAtual.first+movimento.first) < 0){
        return false;
    }else if((posicaoAtual.first+movimento.first) > 7){
        return false;
    }else if((posicaoAtual.second+movimento.second) < 0){
        return false;
    }else if((posicaoAtual.second+movimento.second) > 7){
        return false;
    }else{
        return true;
    }
}

void bfs(int tabuleiro[8][8], pair<int,int> &start, pair<int,int> &destination){
    pair<int,int> v, movimentosPossiveis[8] = {make_pair(2,1),make_pair(2,-1),make_pair(-2,1),make_pair(-2,-1),make_pair(1,2),make_pair(-1,2),make_pair(1,-2),make_pair(-1,-2)}; //Movimentos que mum cavalo pode fazer dentro de um tabuleiro, a partir de uma dada posição
    queue<pair<int,int> > q;
    int ans = 0;

    q.push(start);
    q.push(make_pair(-1, -1));

    while(q.empty() != true){
        init:
        v = q.front(); //Posição atual
        q.pop();
        if(v == destination){ //Chegamos na posição desejada do tabuleiro
            break;
        }else if((v.first == -1) && (v.second == -1)){
            ans++;
            q.push(v);
            goto init;
        }
        for(int i = 0; i < 8; i++){
            if(movimentoValido(v, movimentosPossiveis[i])){ //Checar se após um dos movimentos possíveis que um cavalo pode fazer no tabuleiro a posição dele ainda estará dentro do tabuleiro
                if(tabuleiro[v.first+movimentosPossiveis[i].first][v.second+movimentosPossiveis[i].second] == -1){ //Verificar se aquela posição do tabuleiro ainda não foi visitada
                    q.push(make_pair((v.first+movimentosPossiveis[i].first),(v.second+movimentosPossiveis[i].second)));
                    tabuleiro[v.first+movimentosPossiveis[i].first][v.second+movimentosPossiveis[i].second] = 0;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main(){

    int t;
    pair<int,int> s, d;
    int tabuleiro[8][8]; //Tabuleiro de xadrez 8x8
    char start[3], destination[3];

    scanf("%d", &t);

    while(t--){
        scanf(" %s %s", start, destination);
        
        s = make_pair((start[0]-'a'), (start[1]-'1')); //Posição inicial do cavalo no tabuleiro
        d = make_pair((destination[0]-'a'), (destination[1]-'1')); //Posição final que o cavalo deve chegar no tabuleiro

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                tabuleiro[i][j] = -1; //Posição do tabuleiro ainda não foi visitada
            }
        }

        bfs(tabuleiro, s, d);
    }

    return 0;
}