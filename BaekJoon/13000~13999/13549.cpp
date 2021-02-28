#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
 
const int MAX = 100000 + 1;
bool visited[MAX];
 
int minSecond(int N, int K)
{
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
 
        //��� �ð��� �������� �켱���� ť(ª������ �켱���� ũ��)
        q.push(make_pair(0, N));
        visited[N] = true;
 
        while (!q.empty())
        {
                 int curSec = q.top().first;
                 int curLoc = q.top().second;
                 q.pop();
 
                 if (curLoc == K) //������ ���� �� break
                         return curSec;
 
                 //�� ���� ����� ��
                 //�̹� �湮�� ������ ť�� ���� �ʴ´�
                 if (curLoc * 2 < MAX && !visited[curLoc * 2])
                 {
                         q.push(make_pair(curSec, curLoc * 2)); //�����̵��ϴµ� �ɸ��� �ð� 0��
                         visited[curLoc * 2] = true;
                 }
                 if (curLoc + 1 < MAX && !visited[curLoc + 1])
                 {
                         q.push(make_pair(curSec + 1, curLoc + 1));
                         visited[curLoc + 1] = true;
                 }
                 if (curLoc - 1 >= 0 && !visited[curLoc - 1])
                 {
                         q.push(make_pair(curSec + 1, curLoc - 1));
                         visited[curLoc - 1] = true;
                 }
        }
}
 
int main(void)
{
        int N, K;
        cin >> N >> K;
 
        cout << minSecond(N, K) << "\n";
 
        return 0;
}