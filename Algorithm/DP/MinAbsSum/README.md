# MinAbsSum

이 문제는 Dynamic Programming 문제이다.
두 집합 차이가 최소가 되는 Sum(A) - Sum(B) 를 찾는 문제이다.
결국 풀지 못하여 다른 사람의 해설을 참조했다.

즉, 전체 집합 T = {a, b, c, d, e} 라고 할때 A = {a, b}, B = {c, d, e} 가 Min Abs Sum 이라고 한다면, (a + b) - (c + d + e) 와 같은 수식이 결국 해이다.
이 식을 다시 작성 하면 (a + b + c + d + e} - 2 * (c + d + e) 와 동일하다.

한가지 어려웠던 부분은 집합 T 의 원소들로 가능한 sub sum의 경우의 수를 구하는 부분 이었는데, 사실 지금도 완벽하게 이해는 하지 못했다.
각 숫자의 갯수를 세고, 각 숫자 별로 사용 가능한 숫자를 줄여 가면서, 만들 수 있는 sub sum 에 양수로 표시 함으로써 이를 O(N * sum)에 계산 하도록 한 것으로 이해했다.
- [참조 사이트](https://bgrooot.github.io/codility-minabssum/)