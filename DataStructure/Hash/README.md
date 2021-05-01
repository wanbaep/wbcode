# Hash

## Linked List Hash (Closed Address, Chaining)
- Collision 이 발생하는 경우 Linked List를 사용해서 Collision을 해결한다.
> Coolistion 이 빈번하게 발생해서 Linked List 가 길어지는 경우 선형 탐색 시간이 증가하게 된다. 이러한 경우 이진 탐색 트리를 사용해서 탐색에 소요되는 시간을 줄일 수 있다.

## Open Address Hash
- Collision 이 발생하는 경우 현재 위치에서 step size 만큼 이동한 memory address에 write 한다. Linear Probing(선형 탐사) 를 사용 하는 경우 (1, 2 칸... 만큼 이동) Clustering 현상이 발생 할 가능성이 높다. 따라서, step size 의 값도 별도의 hash 함수로 구하는 방법 (이중 해싱)을 사용한다.

## Rehash (재해싱)
- Open Address 방법을 사용해서 Hash Table 을 구성하는 경우, 여유 공간이 줄어들게 되면 Collision 이 갈수록 빈번하게 발생된다. 따라서, rehash 를 통해서 Hash Table 크기를 늘리고 이에 맞춰서 모든 데이터를 해싱한다.