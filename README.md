# File System Representation and Search Using BFS and DFS

A C program that represents a file system as a graph using an adjacency matrix. Each file or directory is a node, and each connection is an edge. It searches for a file using BFS and DFS and shows the traversal order.

Program file: filesystem_search.c

## Test 1: file found

Input:
```
8
root docs pics src report.txt photo.jpg main.c notes.txt
7
root docs
root pics
root src
docs report.txt
pics photo.jpg
src main.c
src notes.txt
root
main.c
```

Output:
```
BFS traversal: root docs pics src report.txt photo.jpg main.c
BFS result: main.c FOUND

DFS traversal: root docs report.txt pics photo.jpg src main.c
DFS result: main.c FOUND
```

## Test 2: file not found

Input: same as Test 1, but the last line is `video.mp4`

Output:
```
BFS traversal: root docs pics src report.txt photo.jpg main.c notes.txt
BFS result: video.mp4 NOT FOUND

DFS traversal: root docs report.txt pics photo.jpg src main.c notes.txt
DFS result: video.mp4 NOT FOUND
```