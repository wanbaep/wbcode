class Graph {
    private int V;
    private ArrayList<Integer>[] graph;

    public Graph(int V) {
        this.V = V;
        graph = new ArrayList[V + 1];
        for(int i = 0; i <= V; i++) {
            graph[i] = new ArrayList<>();
        }
    }

    public void addEdge(int src, int des) {
        graph[src].add(des);
        graph[des].add(src);
    }

    public List<Integer> BFS(int start) {
        List<Integer> bfs = new ArrayList<>();
        boolean[] visit = new boolean [V + 1];
        Queue<Integer> queue = new LinkedList<>();

        //시작정점을 큐에 넣어줌
        queue.add(start);
        //시작정점을 방문했다는 정보 저장
        visit[start] = true;

        //큐에 정점이 없어질 때까지 반복
        while(!queue.isEmpty()){
            //큐에서 정점을 poll해서 이동함
            int v = queue.poll();
            bfs.add(v);
            //이동한 정점에서 연결된 정점들을 큐에 넣어주고 visit배열에 체크
            for(int i : graph[v]){
                if(!visit[i]){
                    queue.add(i);
                    visit[i] = true;
                }
            }
        }
        return bfs;
    }

    public List<Integer> DFS(int start){
        boolean[] visited = new boolean[V + 1];
        List<Integer> dfs = new ArrayList<>();

        Stack<Integer> stack = new Stack<>();
        stack.push(start);
        while (!stack.isEmpty()){
            int v = stack.pop();
            if (!visited[v]){
                dfs.add(v);
                visited[v] = true;
                for(int i : graph[v]) {
                    if(!visited[i]) {
                        stack.push(i);
                    }
                }
            }
        }
        return dfs;
    }
}
