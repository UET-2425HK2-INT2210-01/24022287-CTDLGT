class Queue
    array Q[capacity]
    front ← 0
    rear ← -1
    size ← 0

function enqueue(x)
    if size = capacity then error "Queue Full"
    rear ← (rear + 1) mod capacity
    Q[rear] ← x
    size ← size + 1

function dequeue()
    if size = 0 then error "Queue Empty"
    x ← Q[front]
    front ← (front + 1) mod capacity
    size ← size - 1
    return x

function peek()
    if size = 0 then error "Queue Empty"
    return Q[front]

function isEmpty()
    return size = 0
