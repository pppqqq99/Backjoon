# [Gold IV] DSLR - 9019 

[문제 링크](https://www.acmicpc.net/problem/9019) 

### 성능 요약

메모리: 2300 KB, 시간: 4092 ms

### 분류

너비 우선 탐색(bfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)


### 복기 내용

string 클래스 사용
참고(https://blockdmask.tistory.com/338)

string 클래스의 메소드들이 유용하긴 하나 수행시간이 길다고 함.
해당 문제를 풀 때 중복 연산을 제거하여 수행하였지만 시간 초과가 떠서 찾아본 결과 연산이 많은 경우에 string 클래스의 메소드가 빈번하게 사용되면 시간 초과가 발생하기도 한다는 사실을 알게 되었음.



