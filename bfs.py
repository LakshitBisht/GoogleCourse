def bfs(graph,st):
    visited=[]
    queue=[]
    queue.append(st)
    while(queue!=[]):
        val=queue.pop(0)
        if val not in visited:
            visited.append(val)
            queue=queue+graph[val]
    return visited

if __name__ == '__main__':
    graph={
        0:[1,2],
        1:[0,2,3],
        2:[0,1,4],
        3:[1,4],
        4:[2,3]
    }
    print(f"Blind Search(BFS) Traversal : {bfs(graph,0)}")