def dfs(graph,st):
    visited=[]
    stack=[]
    stack.append(st)
    while(stack!=[]):
        val=stack.pop()
        if val not in visited:
            visited.append(val)
            stack=stack+graph[val]
    return visited

def dfs_Recursion(graph,val,visited):
    if len(visited)==len(graph):
        return
    if val not in visited:
        visited.append(val)
        for point in graph[val]:
            dfs_Recursion(graph,point,visited)

if __name__ == '__main__':
    graph={
        0:[1,2,3],
        1:[0,2],
        2:[0,1,4],
        3:[0],
        4:[2]
    }
    print(f"Blind Search(DFS) Traversal : {dfs(graph,0)}")
    visited=[]
    dfs_Recursion(graph,0,visited)
    print(f"Blind Search(DFS) Traversal using Recursion : {visited}")