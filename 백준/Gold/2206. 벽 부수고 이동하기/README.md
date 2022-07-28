# [Gold IV] 벽 부수고 이동하기 - 2206 

[문제 링크](https://www.acmicpc.net/problem/2206) 

### 성능 요약

메모리: 12548 KB, 시간: 128 ms

### 분류

너비 우선 탐색(bfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)


### 복기 내용

bfs 탐색 시 flag를 사용해야 하는 경우 3차원 배열을 사용할 수 있다.

flag가 0일 때 W[][][0]에 flag가 1일 때 W[][][1]에 저장하며 최종 목적지에 도달할 경우 W[n][m][f]를 출력

bfs로 탐색시 최단 경로를 찾기 용이하다.
